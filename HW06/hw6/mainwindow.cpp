#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_openImg1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB );  // 4 for original CV_BGR2RGB
        // resize to fit the label
        int y = ui->label->geometry().height();
        int x = ui->label->geometry().width();
        cv::resize(image, image,cv::Size(x,y));

        QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_apply_clicked()
{
    int x = image.cols;
    int y = image.rows;

    cv::Mat warpimage, wavyimage, circularimage;
    // trapezoidal
    int x_offset = ui->horizontalSlider_x->value();
    int y_offset = ui->horizontalSlider_y->value();
    cv::Point2f a(0,0);
    cv::Point2f b(x,0);
    cv::Point2f c(0,y);
    cv::Point2f d(x,y);
    cv::Point2f a1(0,0);
    cv::Point2f b1(x,0);
    cv::Point2f c1(0+x_offset,y-y_offset);
    cv::Point2f d1(x-x_offset,y-y_offset);
    cv::Point2f src[] = {a,b,c,d};
    cv::Point2f dst[] = {a1,b1,c1,d1};

    warpimage = IP::GeoTrans::trapezoidal(image, src, dst);
    // Wavy
    int magnitude = ui->horizontalSlider_mag->value();
    int period = ui->horizontalSlider_per->value();
    wavyimage = IP::GeoTrans::wavy(image, magnitude, period);
    // Circular
    circularimage = IP::GeoTrans::circular(image);


    QImage img = QImage((const unsigned char*) (warpimage.data), warpimage.cols, warpimage.rows, QImage::Format_RGB888);
    QImage img2 = QImage((const unsigned char*) (wavyimage.data), wavyimage.cols, wavyimage.rows, QImage::Format_RGB888);
    QImage img3 = QImage((const unsigned char*) (circularimage.data), circularimage.cols, circularimage.rows, QImage::Format_RGB888);
    // Display on label
    ui->label2->setPixmap(QPixmap::fromImage(img));
    ui->label3->setPixmap(QPixmap::fromImage(img2));
    ui->label4->setPixmap(QPixmap::fromImage(img3));
}


void MainWindow::on_horizontalSlider_x_valueChanged(int value)
{
    QString val = QString::number(value);
    ui->label_x_offset_display->setText(val);
}


void MainWindow::on_horizontalSlider_y_valueChanged(int value)
{
    QString val = QString::number(value);
    ui->label_y_offset_display->setText(val);
}


void MainWindow::on_horizontalSlider_mag_valueChanged(int value)
{
    QString val = QString::number(value);
    ui->label_mag_display->setText(val);
}


void MainWindow::on_horizontalSlider_per_valueChanged(int value)
{
    QString val = QString::number(value);
    ui->label_per_display->setText(val);
}


void MainWindow::on_pushButton_openImg_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image3 = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image3, image3, cv::COLOR_BGR2RGB );  // 4 for original CV_BGR2RGB
        // resize to fit the label
        int y = ui->label->geometry().height();
        int x = ui->label->geometry().width();
        cv::resize(image3, image3,cv::Size(x,y));

        QImage img = QImage((const unsigned char*) (image3.data), image3.cols, image3.rows, QImage::Format_RGB888);

        // Display on label
        ui->label5->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_apply_3_clicked()
{
    cv::Mat houghimage, image3_copy;
    image3_copy = image3.clone();
    int num = ui->horizontalSlider_line->value();
    int sigma = ui->spinBox_sigma->value();
    int size_g = ui->spinBox_size->value();
    int size_s = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    int threshold = ui->horizontalSlider_threshold->value();

    cv::Mat grayimage, blurredimage, edgeimage, binaryimage;
    // RGBtoGRAY
    grayimage = IP::cvtcolor(image3, IP::RGB2GRAY);
    // apply gaussian filter to eliminate noise
    blurredimage = IP::Spa::Gaussian(grayimage, size_g, sigma);
    // finding edge by sobel operator
    edgeimage = IP::Spa::Sobel(blurredimage, size_s, scale, delta, ddepth);

    // binary image
    binaryimage = IP::Binary(edgeimage, threshold);
    // hough image
    houghimage = IP::HoughTransform(image3_copy,binaryimage,num);

    QImage img = QImage((const unsigned char*) (houghimage.data), houghimage.cols, houghimage.rows, QImage::Format_RGB888);
    QImage img2 = QImage((const unsigned char*) (edgeimage.data), edgeimage.cols, edgeimage.rows, QImage::Format_Grayscale8);
    QImage img3 = QImage((const unsigned char*) (binaryimage.data), binaryimage.cols, binaryimage.rows, QImage::Format_Grayscale8);

    // Display on label
    ui->label6->setPixmap(QPixmap::fromImage(img));
    ui->label7->setPixmap(QPixmap::fromImage(img2));
    ui->label8->setPixmap(QPixmap::fromImage(img3));
}


void MainWindow::on_horizontalSlider_threshold_valueChanged(int value)
{
    QString val = QString::number(value);
    ui->label_threshold_display->setText(val);
}


void MainWindow::on_horizontalSlider_line_valueChanged(int value)
{
    QString val = QString::number(value);
    ui->label_line_display->setText(val);
}

