#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_select->setDisabled(true);
    ui->pushButton_done->setDisabled(true);
    ui->pushButton_cancel->setDisabled(true);
    ui->pushButton_convert->setDisabled(true);
    ui->pushButton_clear->setDisabled(true);
    ui->pushButton_restore->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::graphshow(QImage img, QGraphicsView *graph){
    myscene *scene = new myscene();
    scene->addPixmap(QPixmap::fromImage(img).scaled(graph->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    graph->setScene(scene);
    graph->show();
}

void MainWindow::graphresize(QGraphicsView* graph){
    if (graph->scene()!=NULL)
        graph->fitInView(graph->scene()->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    graphresize(ui->graphicsView);
    graphresize(ui->graphicsView_2);
    graphresize(ui->graphicsView_3);
    graphresize(ui->graphicsView_4);
    graphresize(ui->graphicsView_5);
    graphresize(ui->graphicsView_6);
    graphresize(ui->graphicsView_7);
    graphresize(ui->graphicsView_8);
    QWidget::resizeEvent(event);
}


void MainWindow::on_pushButton_openImg_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB );  // 4 for original CV_BGR2RGB

        QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

        graphshow(img, ui->graphicsView);

    }
    image_org = image.clone();

    ui->pushButton_select->setEnabled(true);
    ui->pushButton_convert->setEnabled(true);

}



void MainWindow::on_pushButton_select_clicked()
{
    //ui->graphicsView->scene()->clear();

    myscene *scene = new myscene();

    QPen pen;
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(1);

    int x = ui->graphicsView->size().width();
    int y = float(image.rows)/image.cols*x;

    circle_topleft = new QGraphicsCircleItem(5, 0, 0);
    circle_topright = new QGraphicsCircleItem(5, x, 0);
    circle_bottomleft = new QGraphicsCircleItem(5, 0, y);
    circle_bottomright = new QGraphicsCircleItem(5, x, y);

    circle_topleft->setFlag(QGraphicsItem::ItemIsMovable);
    circle_topright->setFlag(QGraphicsItem::ItemIsMovable);
    circle_bottomleft->setFlag(QGraphicsItem::ItemIsMovable);
    circle_bottomright->setFlag(QGraphicsItem::ItemIsMovable);

    QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    scene->addPixmap(QPixmap::fromImage(img).scaled(ui->graphicsView->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    scene->addItem(circle_topleft);
    scene->addItem(circle_topright);
    scene->addItem(circle_bottomleft);
    scene->addItem(circle_bottomright);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    ui->pushButton_openImg->setDisabled(true);
    ui->pushButton_convert->setDisabled(true);
    ui->pushButton_clear->setDisabled(true);

    ui->pushButton_done->setEnabled(true);
    ui->pushButton_cancel->setEnabled(true);
    ui->pushButton_restore->setEnabled(true);
}

void MainWindow::on_pushButton_done_clicked()
{
    // ui->graphicsView->scene()->clear(); //the circle object will also be cleared
    int x = ui->graphicsView->size().width();
    int y = float(image.rows)/image.cols*x;

    cv::Point2f a(circle_topleft->new_x,circle_topleft->new_y);
    cv::Point2f b(circle_topright->new_x,circle_topright->new_y);
    cv::Point2f c(circle_bottomleft->new_x,circle_bottomleft->new_y);
    cv::Point2f d(circle_bottomright->new_x,circle_bottomright->new_y);
    cv::Point2f a1(0,0);
    cv::Point2f b1(x,0);
    cv::Point2f c1(0,y);
    cv::Point2f d1(x,y);
    cv::Point2f src[] = {a,b,c,d};
    cv::Point2f dst[] = {a1,b1,c1,d1};

    cv::Mat warpimage = IP::GeoTrans::trapezoidal(image, src, dst);


    image = warpimage.clone();

    QImage img_new = QImage((const unsigned char*) (warpimage.data), warpimage.cols, warpimage.rows, QImage::Format_RGB888);
    graphshow(img_new, ui->graphicsView);

    ui->pushButton_openImg->setEnabled(true);
    ui->pushButton_convert->setEnabled(true);

    ui->pushButton_done->setDisabled(true);
    ui->pushButton_cancel->setDisabled(true);
}

void MainWindow::on_pushButton_cancel_clicked()
{
    //ui->graphicsView->scene()->clear();
    QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    graphshow(img, ui->graphicsView);

    ui->pushButton_openImg->setEnabled(true);
    ui->pushButton_convert->setEnabled(true);

    ui->pushButton_done->setDisabled(true);
    ui->pushButton_cancel->setDisabled(true);
}

void MainWindow::on_pushButton_restore_clicked()
{
    image = image_org.clone();
    QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    graphshow(img, ui->graphicsView);
}

void MainWindow::on_pushButton_convert_clicked()
{
    ui->textBrowser_solmizations->clear();
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);
    cv::Mat blurredimage = IP::Spa::Gaussian(gray, 3, 5);
    cv::Mat binaryimage = IP::Binary(blurredimage, 200);
    IP::OMR omr(binaryimage);
    cv::Mat HorizontalProjection_image = omr.HorizontalProjection();
    cv::Mat lineremoved_image = omr.LineRemoved();
    cv::Mat staffline_image = omr.StaffLineRecognition();

    int* line = omr.LineLocation(staffline_image);

    cv::Mat template_image = cv::imread(".\\template\\template_note2.jpg");
    cv::Mat templatematching_image = omr.TemplateMatching(lineremoved_image, template_image);
    cv::Mat binary_templatematching_image = IP::Binary(templatematching_image, 245);

    int** notepoint = omr.NotePoint(binary_templatematching_image);
    cv::Mat notepointimage = omr.DrawNotePoint(image);

    for (int j = 0; j < omr.line_nums / 5; j++) {
        char* sol = omr.Semantics(line[5*j], line[5*j+1], line[5*j + 2], line[5*j + 3], line[5*j + 4]);

        for (int i = 0; i < omr.sol_nums; i++) {
            //qDebug() << QChar(sol[i]);
            QString solmization= QChar(sol[i]);
            ui->textBrowser_solmizations->insertPlainText(solmization);
        }
        ui->textBrowser_solmizations->append("");
        delete [] sol;
    }


    delete[] line;
    for (int i = 0; i < 2; i++) {
        delete[] notepoint[i];
    }
    delete[] notepoint;

    QImage img3 = QImage((const unsigned char*) (HorizontalProjection_image.data), HorizontalProjection_image.cols, HorizontalProjection_image.rows, QImage::Format_Grayscale8);
    QImage img4 = QImage((const unsigned char*) (lineremoved_image.data), lineremoved_image.cols, lineremoved_image.rows, QImage::Format_Grayscale8);
    QImage img5 = QImage((const unsigned char*) (staffline_image.data), staffline_image.cols, staffline_image.rows, QImage::Format_Grayscale8);
    QImage img6 = QImage((const unsigned char*) (templatematching_image.data), templatematching_image.cols, templatematching_image.rows, QImage::Format_Grayscale8);
    QImage img7 = QImage((const unsigned char*) (binary_templatematching_image.data), binary_templatematching_image.cols, binary_templatematching_image.rows, QImage::Format_Grayscale8);
    QImage img8 = QImage((const unsigned char*) (notepointimage.data), notepointimage.cols, notepointimage.rows, QImage::Format_RGB888);

    graphshow(img8, ui->graphicsView_2);
    graphshow(img3, ui->graphicsView_3);
    graphshow(img4, ui->graphicsView_4);
    graphshow(img5, ui->graphicsView_5);
    graphshow(img6, ui->graphicsView_6);
    graphshow(img7, ui->graphicsView_7);
    graphshow(img8, ui->graphicsView_8);

    ui->pushButton_clear->setEnabled(true);

}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->graphicsView_2->scene()->clear();
    ui->graphicsView_3->scene()->clear();
    ui->graphicsView_4->scene()->clear();
    ui->graphicsView_5->scene()->clear();
    ui->graphicsView_6->scene()->clear();
    ui->graphicsView_7->scene()->clear();
    ui->graphicsView_8->scene()->clear();
    ui->textBrowser_solmizations->clear();

    ui->pushButton_clear->setDisabled(true);
}



