#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
    QString convert_type = ui->comboBox->currentText();
    cv::Mat convertedimage;

    if (convert_type=="RGB") convertedimage = IP::cvtcolor(image, IP::RGB2RGB);
    else if (convert_type=="CMY") convertedimage = IP::cvtcolor(image, IP::RGB2CMY);
    else if (convert_type=="HSI") convertedimage = IP::cvtcolor(image, IP::RGB2HSI);
    else if (convert_type=="XYZ") convertedimage = IP::cvtcolor(image, IP::RGB2XYZ);
    else if (convert_type=="L*a*b") convertedimage = IP::cvtcolor(image, IP::RGB2Lab);
    else if (convert_type=="YUV") convertedimage = IP::cvtcolor(image, IP::RGB2YUV);

    int x = convertedimage.cols;
    int y = convertedimage.rows;
    cv::Mat * color_plane = new cv::Mat[3];
    color_plane[0] = cv::Mat(cv::Size(x,y),CV_8UC1);
    color_plane[1] = cv::Mat(cv::Size(x,y),CV_8UC1);
    color_plane[2] = cv::Mat(cv::Size(x,y),CV_8UC1);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            for (int channel=0;channel<3 ;channel++ ) {
                color_plane[channel].at<uchar>(i,j) = convertedimage.at<cv::Vec3b>(i,j)[channel];
            }
        }
    }
    int h = ui->label2->geometry().height();
    int w = ui->label2->geometry().width();
    QImage* img = new QImage[3];
    for (int i=0;i<3 ;i++ ) {
        cv::resize(color_plane[i], color_plane[i],cv::Size(w,h));
        img[i] = QImage((const unsigned char*) (color_plane[i].data), color_plane[i].cols, color_plane[i].rows, QImage::Format_Grayscale8);
    }

    // Display on label
    ui->label2->setPixmap(QPixmap::fromImage(img[0]));
    ui->label3->setPixmap(QPixmap::fromImage(img[1]));
    ui->label4->setPixmap(QPixmap::fromImage(img[2]));

    delete [] color_plane;
    delete [] img;
}

void MainWindow::on_pushButton_openImg2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image2 = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image2, image2, cv::COLOR_BGR2GRAY );  // 4 for original CV_BGR2RGB
        // resize to fit the label
        int y = ui->label->geometry().height();
        int x = ui->label->geometry().width();
        cv::resize(image2, image2,cv::Size(x,y));

        QImage img = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows, QImage::Format_Grayscale8);

        // Display on label
        ui->label5->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_pseudo_color_clicked()
{
    float phase_shift = ui->doubleSpinBox->value();

    int h = ui->label_colorbar->geometry().height();
    int w = ui->label_colorbar->geometry().width();

    cv::Mat pseudo_image = IP::pseudocolor(image2, phase_shift);
    cv::Mat color_bar_image = IP::colortable(phase_shift);

    cv::resize(color_bar_image, color_bar_image,cv::Size(w,h));

    QImage img = QImage((const unsigned char*) (pseudo_image.data), pseudo_image.cols, pseudo_image.rows, QImage::Format_BGR888);
    QImage img2 = QImage((const unsigned char*) (color_bar_image.data), color_bar_image.cols, color_bar_image.rows, QImage::Format_BGR888);
    // Display on label
    ui->label6->setPixmap(QPixmap::fromImage(img));
    ui->label_colorbar->setPixmap(QPixmap::fromImage(img2));
}


void MainWindow::on_pushButton_openImg3_clicked()
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
        ui->label7->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_kmeans_clicked()
{
    cv::Mat kmeans_image;
    int k = ui->spinBox_k->value();
    int max_iter = ui->spinBox_iter->value();
    kmeans_image = IP::Kmeans_cluster(image3, k, max_iter);

    QImage img = QImage((const unsigned char*) (kmeans_image.data), kmeans_image.cols, kmeans_image.rows, QImage::Format_RGB888);

    // Display on label
    ui->label8->setPixmap(QPixmap::fromImage(img));
}

