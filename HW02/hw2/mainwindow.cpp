#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->threshold->setRange(0,255);
//    ui->resize_slider->setRange(5,20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_part2_1_clicked()
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
        // Qt imag
        QImage* img = new QImage(fileName);
        //QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

        // Set the background color of label
        ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
    ui->A->setEnabled(true);
    ui->B->setEnabled(true);

}


void MainWindow::on_A_clicked()
{
    A_state = 1;
    int y = ui->label->geometry().height();
    int x = ui->label->geometry().width();
    int R;
    int G;
    int B;
    grayA = cv::Mat(cv::Size(x,y),CV_8UC1);
//    grayA = cv::Mat_<uchar>(x,y);
    for(int i=0; i<grayA.rows;i++){
        for(int j=0; j<grayA.cols;j++){
            R = image.at<cv::Vec3b>(i,j)[0];
            G = image.at<cv::Vec3b>(i,j)[1];
            B = image.at<cv::Vec3b>(i,j)[2];
            grayA.at<uchar>(i,j) = (R+G+B)/3;
        }
    }
    hisgray = grayA;
    QImage img = QImage((const unsigned char*) (grayA.data), grayA.cols, grayA.rows, QImage::Format_Grayscale8);

    // Set the background color of label
    ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->histogram->setEnabled(true);


    if (A_state==1 && B_state==1){
        ui->compare->setEnabled(true);
    }
    ui->threshold->setEnabled(true);
    ui->label_threshold->setEnabled(true);
    ui->binarythreshold->setEnabled(true);
    ui->histogram_equalization->setEnabled(true);
}


void MainWindow::on_B_clicked()
{
    B_state = 1;
    int y = ui->label->geometry().height();
    int x = ui->label->geometry().width();
    int R;
    int G;
    int B;
    grayB = cv::Mat(cv::Size(x,y),CV_8UC1);
    for(int i=0; i<grayB.rows;i++){
        for(int j=0; j<grayB.cols;j++){
            R = image.at<cv::Vec3b>(i,j)[0];
            G = image.at<cv::Vec3b>(i,j)[1];
            B = image.at<cv::Vec3b>(i,j)[2];
            grayB.at<uchar>(i,j) = 0.299*R+0.587*G+0.114*B;
        }
    }
    hisgray = grayB;
    QImage img = QImage((const unsigned char*) (grayB.data), grayB.cols, grayB.rows, QImage::Format_Grayscale8);

    // Set the background color of label
    ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->histogram->setEnabled(true);
    if (A_state==1 && B_state==1){
        ui->compare->setEnabled(true);
    }
    ui->threshold->setEnabled(true);
    ui->label_threshold->setEnabled(true);
    ui->binarythreshold->setEnabled(true);
    ui->histogram_equalization->setEnabled(true);
}


void MainWindow::on_compare_clicked()
{
    int y = ui->label->geometry().height();
    int x = ui->label->geometry().width();
    int sum = 0;
    cv::Mat compare(cv::Size(x,y),CV_8UC1);
    for(int i=0; i<image.rows;i++){
        for(int j=0; j<image.cols;j++){
            sum = grayA.at<uchar>(i,j)-grayB.at<uchar>(i,j);
//            if(grayA.at<uchar>(i,j)<grayB.at<uchar>(i,j)){
//                sum = 0;
//            }
//            else{
//                sum = grayA.at<uchar>(i,j)-grayB.at<uchar>(i,j);
//            }
            compare.at<uchar>(i,j) = sum;
        }
    }
    hisgray = compare;
    QImage img = QImage((const unsigned char*) (compare.data), compare.cols, compare.rows, QImage::Format_Grayscale8);

    // Set the background color of label
    ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_histogram_clicked()
{
    int y = ui->label2->geometry().height();
    int x = ui->label2->geometry().width();
    int histogram[256]={0};
    int value = 0;
    for(int i=0; i<hisgray.rows;i++){
        for(int j=0; j<hisgray.cols;j++){
            value = hisgray.at<uchar>(i,j);
            histogram[value] += 1;
        }
    }

    int bin = 256;
    int height = 1000;
    int scale = 2;
    cv::Mat histimage = cv::Mat(cv::Size(bin*scale,height),CV_8UC1);
    for (int i=0;i<bin;i++) {
        for (int j=0;j<scale;j++) {
            cv::Point p1(i*scale+j,height);
            cv::Point p2(i*scale+j,height-histogram[i]);
            cv::line(histimage,
                     p1,
                     p2,
                     64);
        }
    }
    cv::resize(histimage,histimage,cv::Size(x,y));
    QImage img = QImage((const unsigned char*) (histimage.data), histimage.cols, histimage.rows, QImage::Format_Grayscale8);
    // Display on label
    ui->label2->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_threshold_valueChanged(int value)
{
    QString v = QString::number(value);
    ui->label_threshold->setText(v);
    int y = ui->label3->geometry().height();
    int x = ui->label3->geometry().width();
    cv::Mat binaryimage(cv::Size(x,y),CV_8UC1);
    int grayvalue = 0;
    for(int i=0;i<hisgray.rows;i++ ) {
        for (int j=0;j<hisgray.cols ;j++ ) {
            grayvalue = hisgray.at<uchar>(i,j);
            if(grayvalue < value){
                binaryimage.at<uchar>(i,j)=0;
            }
            else{
                binaryimage.at<uchar>(i,j)=255;
            }
        }
    }
    QImage img = QImage((const unsigned char*) (binaryimage.data), binaryimage.cols, binaryimage.rows, QImage::Format_Grayscale8);
    // Display on label
    ui->label3->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_part2_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image2 = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image2, image2, cv::COLOR_BGR2GRAY );  // 4 for original CV_BGR2GRAY
        // resize to fit the label
        int y = ui->label4->geometry().height();
        int x = ui->label4->geometry().width();

        cv::resize(image2, image2,cv::Size(x,y));
        // Qt image
        QImage img = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows, QImage::Format_Grayscale8);

        // Set the background color of label
        ui->label4->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
        // Display on label
        ui->label4->setPixmap(QPixmap::fromImage(img));
    }
    ui->resize_slider->setEnabled(true);
    ui->label_scale->setEnabled(true);
    ui->resize_scale->setEnabled(true);

    ui->brightness_slider->setEnabled(true);
    ui->brightness->setEnabled(true);
    ui->label_brightness->setEnabled(true);

    ui->spinBox_r1->setEnabled(true);
    ui->spinBox_s1->setEnabled(true);
    ui->spinBox_r2->setEnabled(true);
    ui->spinBox_s2->setEnabled(true);
    ui->pushButton_contrast->setEnabled(true);
    ui->PushButton_reset->setEnabled(true);
}


void MainWindow::on_resize_slider_valueChanged(int value)
{
    float scale = value/10.0;
    QString v = QString::number(scale);
    ui->label_scale->setText(v);
    int y = image2.rows;
    int x = image2.cols;
    int re_y = y*scale;
    int re_x = x*scale;
    resize_image = cv::Mat(cv::Size(re_x,re_y),CV_8UC1);
    for (int i=0;i<re_y ;i++ ) {
        for (int j=0;j<re_x ;j++ ) {
            resize_image.at<uchar>(i,j)=image2.at<uchar>((int)(i/scale),(int)(j/scale));
        }
    }

    QImage img = QImage((const unsigned char*) (resize_image.data), resize_image.cols, resize_image.rows, QImage::Format_Grayscale8);

    // Set the background color of label
    ui->label4->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label4->setPixmap(QPixmap::fromImage(img));
    ui->label4->resize(ui->label4->pixmap()->size());

}


void MainWindow::on_brightness_slider_valueChanged(int value)
{
    QString v = QString::number(value);
    ui->label_brightness->setText(v);

    int y = resize_image.rows;
    int x = resize_image.cols;
    cv::Mat brightness_image = cv::Mat(cv::Size(x,y),CV_8UC1);
    for (int i=0;i<brightness_image.rows;i++) {
        for (int j=0;j<brightness_image.cols;j++ ) {
            if((resize_image.at<uchar>(i,j)+value)>255){
                brightness_image.at<uchar>(i,j) = 255;
            }
            else if((resize_image.at<uchar>(i,j)+value)<0){
                brightness_image.at<uchar>(i,j) = 0;
            }
            else{
                brightness_image.at<uchar>(i,j)=resize_image.at<uchar>(i,j)+value;
            }
        }
    }
    QImage img = QImage((const unsigned char*) (brightness_image.data), brightness_image.cols, brightness_image.rows, QImage::Format_Grayscale8);

    // Set the background color of label
    ui->label4->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label4->setPixmap(QPixmap::fromImage(img));
    ui->label4->resize(ui->label4->pixmap()->size());

}


void MainWindow::on_pushButton_contrast_clicked()
{
    int r1 = ui->spinBox_r1->value();
    int s1 = ui->spinBox_s1->value();
    int r2 = ui->spinBox_r2->value();
    int s2 = ui->spinBox_s2->value();

    int y = image2.rows;
    int x = image2.cols;

    int temp = 0;
    cv::Mat contrast_image = cv::Mat(cv::Size(x,y),CV_8UC1);
    for (int i=0;i<contrast_image.rows;i++) {
        for (int j=0;j<contrast_image.cols;j++ ) {
            if(image2.at<uchar>(i,j)<=r1){
                temp = (int)(image2.at<uchar>(i,j)*s1/r1);
            }
            else if(image2.at<uchar>(i,j)>r1 && image2.at<uchar>(i,j)<=r2){
                temp = (int)((image2.at<uchar>(i,j)-r1)*(s2-s1)/(r2-r1)+s1);
            }
            else{
                temp = (int)((image2.at<uchar>(i,j)-r2)*(255-s2)/(255-r2)+s2);
            }
            contrast_image.at<uchar>(i,j) = temp;
        }
    }
    QImage img = QImage((const unsigned char*) (contrast_image.data), contrast_image.cols, contrast_image.rows, QImage::Format_Grayscale8);

    // Set the background color of label
    ui->label4->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label4->setPixmap(QPixmap::fromImage(img));
    ui->label4->resize(ui->label4->pixmap()->size());


    cv::Mat curveimage = cv::Mat(cv::Size(255,255),CV_8UC3);
    cv::Point p0(0,255);
    cv::Point p1(r1,255-s1);
    cv::Point p2(r2,255-s2);
    cv::Point p3(255,0);
    cv::Scalar color_line(0,0,255);

    cv::line(curveimage,p0,p1,color_line,3);
    cv::line(curveimage,p1,p2,color_line,3);
    cv::line(curveimage,p2,p3,color_line,3);

    cv::Scalar color(255,0,0);
    cv::circle(curveimage,p1,10,color,cv::FILLED);
    cv::circle(curveimage,p2,10,color,cv::FILLED);

    QImage img2 = QImage((const unsigned char*) (curveimage.data), curveimage.cols, curveimage.rows, QImage::Format_RGB888);

    // Display on label
    ui->label5->setPixmap(QPixmap::fromImage(img2));

}



void MainWindow::on_PushButton_reset_clicked()
{
    ui->spinBox_r1->setValue(64);
    ui->spinBox_s1->setValue(32);
    ui->spinBox_r2->setValue(192);
    ui->spinBox_s2->setValue(224);
}


void MainWindow::on_histogram_equalization_clicked()
{
    int y = ui->label->geometry().height();
    int x = ui->label->geometry().width();
    int histogram[256]={0};
    float pr[256]={0};
    int value = 0;
    float sum = 0;
    cv::Mat equalization_image = cv::Mat(cv::Size(x,y),CV_8UC1);

    for(int i=0; i<hisgray.rows;i++){
        for(int j=0; j<hisgray.cols;j++){
            value = hisgray.at<uchar>(i,j);
            histogram[value] += 1;
            pr[value] += 1.0/(hisgray.rows*hisgray.cols);
        }
    }
    for(int i=0; i<equalization_image.rows;i++){
        for(int j=0; j<equalization_image.cols;j++){
            value = hisgray.at<uchar>(i,j);
            sum = 0;
            for (int k=0;k<value;k++) {
                sum += pr[k];
            }
            equalization_image.at<uchar>(i,j) = sum*255;
        }
    }
    hisgray = equalization_image;
    QImage img = QImage((const unsigned char*) (equalization_image.data), equalization_image.cols, equalization_image.rows, QImage::Format_Grayscale8);
    // Display on label
    ui->label->setPixmap(QPixmap::fromImage(img));

}

