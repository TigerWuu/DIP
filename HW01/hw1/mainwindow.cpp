#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <fstream>
#include <QSpinBox>
using namespace std;

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

void MainWindow::on_part1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.64"));

// reade .64 file //
    if (fileName!=NULL){
        ifstream file64;

        char buffer[4225]={};// 65*65 inlude the new line character

        file64.open(fileName.toStdString());
        if (!file64.is_open()) {
            cout << "Failed to open file.\n";
        } else {
            file64.read(buffer, sizeof(buffer));
            file64.close();
        }
// reade .64 file //
// convert a 1D array to a 2D matrix //
        cv::Mat c(cv::Size(64,64),CV_8UC1);
        int hist[32]={0}; // initialization
        int add = 0;
        for (int i = 0; i < c.rows; i++) {
            for (int j = 0; j < c.cols; j++){
                add = 64*i+j+i; // ignore new line character

                if (buffer[add]<'A'){
                    c.at<uchar>(i,j) = (buffer[add]-48)*8;//encode the number < 'A', *8 to map from 0~31 to 0~248
                    hist[buffer[add]-48]+=1;//accumulate
                }
                else{
                    c.at<uchar>(i,j) = (buffer[add]-55)*8;
                    hist[buffer[add]-55]+=1;
                }
            }
        }
// convert a 1D array to a 2D matrix //
// plot histogram //
        const int size = 32; // bin =32
        int scale = 10; //the width of bar in the historgram
        int histheight = 320;// the maximum value of this histogram
        cv::Mat histimage(histheight,size*scale,CV_8UC1); // initialize the histogram

        for(int i=0;i<size;i++){
            int peak = hist[i];
            for(int j=0;j<scale;j++){
                cv::Point p1(i*scale+j,histheight-1);
                cv::Point p2(i*scale+j,histheight-peak);
                cv::line(histimage,
                         p1,
                         p2,
                         64);
            }
        }
// plot histogram //
// show the image in the label //
        cv::Mat image1;// picture
        cv::resize(c,image1,cv::Size(200,200)); // resize a 64*64 image to a 200*200 image
        QImage img = QImage((const unsigned char*) (image1.data),
                            image1.cols, image1.rows, QImage::QImage::Format_Grayscale8);


        ui->label1->setPixmap(QPixmap::fromImage(img));// Display on label
        ui->label1->resize(ui->label1->pixmap()->size());// Resize the label to fit the image

        cv::Mat image2;// histogram
        cv::resize(histimage,image2,cv::Size(200,200));
        QImage img2 = QImage((const unsigned char*) (image2.data),
                            image2.cols, image2.rows, QImage::QImage::Format_Grayscale8);

        ui->label1_2->setPixmap(QPixmap::fromImage(img2));
        ui->label1_2->resize(ui->label1_2->pixmap()->size());
// show the image in the label //

//        cv::imshow("hist" , histimage);
//        cv::imshow("image1" , image1);
    }
}




void MainWindow::on_part2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.64"));

    if (fileName!=NULL){
        ifstream file64;

        char buffer[4225]={};

        file64.open(fileName.toStdString());
        if (!file64.is_open()) {
            cout << "Failed to open file.\n";
        } else {
            file64.read(buffer, sizeof(buffer));
            file64.close();
        }

        c2 = cv::Mat_<uchar>(64,64);
        int hist[32]={0};
        int add = 0;
        for (int i = 0; i < c2.rows; i++) {
            for (int j = 0; j < c2.cols; j++){
                add = 64*i+j+i;
                if (buffer[add]<'A'){
                    c2.at<uchar>(i,j) = (buffer[add]-48)*8;
                    hist[buffer[add]-48]+=1;
                }
                else{
                    c2.at<uchar>(i,j) = (buffer[add]-55)*8;
                    hist[buffer[add]-55]+=1;
                }

            }
        }

        const int size = 32;
        int scale = 10;
        int histheight = 320;
        // plot histogram //
        histimage = cv::Mat_<uchar>(histheight,size*scale);
        for(int i=0;i<size;i++){
            int peak = hist[i];
            for(int j=0;j<scale;j++){
                cv::Point p1(i*scale+j,histheight-1);
                cv::Point p2(i*scale+j,histheight-peak);
                cv::line(histimage,
                         p1,
                         p2,
                         64);
            }
        }
        // plot histogram //
        cv::Mat image;
        cv::resize(c2,image,cv::Size(200,200));


        cv::Mat image1;
        cv::resize(c2,image1,cv::Size(200,200));
        QImage img = QImage((const unsigned char*) (image1.data),
                            image1.cols, image1.rows, QImage::QImage::Format_Grayscale8);


        ui->label2->setPixmap(QPixmap::fromImage(img));// Display on label
        ui->label2->resize(ui->label2->pixmap()->size());// Resize the label to fit the image

        cv::Mat image2;
        cv::resize(histimage,image2,cv::Size(200,200));
        QImage img2 = QImage((const unsigned char*) (image2.data),
                            image2.cols, image2.rows, QImage::QImage::Format_Grayscale8);

        ui->label2_2->setPixmap(QPixmap::fromImage(img2));
        ui->label2_2->resize(ui->label2_2->pixmap()->size());
    }
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int add = arg1*8;// load the value from the spinBox to arg1
    int hist[32]={0};
    cv::Mat c_mod(cv::Size(64,64),CV_8UC1);
    for (int i = 0; i < c_mod.rows; i++) {
        for (int j = 0; j < c_mod.cols; j++){
            if(c2.at<uchar>(i,j)+add < 256){
                c_mod.at<uchar>(i,j) = c2.at<uchar>(i,j)+add;//  add add into original pic
            }
            else{c_mod.at<uchar>(i,j)=255;}
            int his = c_mod.at<uchar>(i,j)/8;
            hist[his]+=1;
        }
    }

    const int size = 32;
    int scale = 10;
    int histheight = 320;

    histimage = cv::Mat_<uchar>(histheight,size*scale);
    for(int i=0;i<size;i++){
        int peak = hist[i];
        for(int j=0;j<scale;j++){
            cv::Point p1(i*scale+j,histheight-1);
            cv::Point p2(i*scale+j,histheight-peak);
            cv::line(histimage,
                     p1,
                     p2,
                     64);
        }
    }

    cv::Mat image1;
    cv::resize(c_mod,image1,cv::Size(200,200));

    QImage img = QImage((const unsigned char*) (image1.data),
                        image1.cols, image1.rows, QImage::QImage::Format_Grayscale8);

    ui->label2->setPixmap(QPixmap::fromImage(img));// Display on label
    ui->label2->resize(ui->label2->pixmap()->size());// Resize the label to fit the image

    cv::Mat image2;
    cv::resize(histimage,image2,cv::Size(200,200));
    QImage img2 = QImage((const unsigned char*) (image2.data),
                        image2.cols, image2.rows, QImage::QImage::Format_Grayscale8);

    ui->label2_2->setPixmap(QPixmap::fromImage(img2));
    ui->label2_2->resize(ui->label2_2->pixmap()->size());

}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    int mul = arg1;// load the value from the spinBox to arg1
    int hist[32]={0};
    cv::Mat c_mod(cv::Size(64,64),CV_8UC1);
    for (int i = 0; i < c_mod.rows; i++) {
        for (int j = 0; j < c_mod.cols; j++){
            if(c2.at<uchar>(i,j)*mul < 256){
                c_mod.at<uchar>(i,j) = c2.at<uchar>(i,j)*mul;//multiply mul into original pic
            }
            else{c_mod.at<uchar>(i,j)=255;}
            int his = c_mod.at<uchar>(i,j)/8;
            hist[his]+=1;
        }
    }

    const int size = 32;
    int scale = 10;
    int histheight = 320;

    histimage = cv::Mat_<uchar>(histheight,size*scale);
    for(int i=0;i<size;i++){
        int peak = hist[i];
        for(int j=0;j<scale;j++){
            cv::Point p1(i*scale+j,histheight-1);
            cv::Point p2(i*scale+j,histheight-peak);
            cv::line(histimage,
                     p1,
                     p2,
                     64);
        }
    }

    cv::Mat image1;
    cv::resize(c_mod,image1,cv::Size(200,200));

    QImage img = QImage((const unsigned char*) (image1.data),
                        image1.cols, image1.rows, QImage::QImage::Format_Grayscale8);


    ui->label2->setPixmap(QPixmap::fromImage(img));// Display on label
    ui->label2->resize(ui->label2->pixmap()->size());// Resize the label to fit the image

    cv::Mat image2;
    cv::resize(histimage,image2,cv::Size(200,200));
    QImage img2 = QImage((const unsigned char*) (image2.data),
                        image2.cols, image2.rows, QImage::QImage::Format_Grayscale8);

    ui->label2_2->setPixmap(QPixmap::fromImage(img2));
    ui->label2_2->resize(ui->label2_2->pixmap()->size());
}


void MainWindow::on_part3_clicked()
{
//open two .64 files//
    QString fileName1 = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.64"));

    QString fileName2 = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.64"));
//open two .64 files//

    if (fileName1!=NULL && fileName2!=NULL){
        ifstream file64;

        char buffer1[4225]={};
        char buffer2[4225]={};

        file64.open(fileName1.toStdString());
        if (!file64.is_open()) {
            cout << "Failed to open file.\n";
        } else {
            file64.read(buffer1, sizeof(buffer1));
            file64.close();
        }

        file64.open(fileName2.toStdString());
        if (!file64.is_open()) {
            cout << "Failed to open file.\n";
        } else {
            file64.read(buffer2, sizeof(buffer2));
            file64.close();
        }


        cv::Mat c3(cv::Size(64,64),CV_8UC1);
        int hist[32]={0};
        int add = 0;
        for (int i = 0; i < c3.rows; i++) {
            for (int j = 0; j < c3.cols; j++){
                add = 64*i+j+i; // ignore the line break
                uchar a;
                uchar b;

                if (buffer1[add]<'A'){
                    a = (buffer1[add]-48)*8;
                }
                else{
                    a = (buffer1[add]-55)*8;
                }

                if (buffer2[add]<'A'){
                    b = (buffer2[add]-48)*8;
                }
                else{
                    b = (buffer2[add]-55)*8;
                }
                c3.at<uchar>(i,j) = (a+b)/2;//average the two image
                qDebug()<<a/8;
                hist[(a+b)/(8*2)]+=1;
            }
        }

        const int size = 32;
        int scale = 10;
        int histheight = 320;

        cv::Mat histimage2(histheight,size*scale,CV_8UC1);

        for(int i=0;i<size;i++){
            int peak = hist[i];
            for(int j=0;j<scale;j++){
                cv::Point p1(i*scale+j,histheight-1);
                cv::Point p2(i*scale+j,histheight-peak);
                cv::line(histimage2,
                         p1,
                         p2,
                         64);
            }
        }

        cv::Mat image1;
        cv::resize(c3,image1,cv::Size(200,200));

        QImage img = QImage((const unsigned char*) (image1.data),
                            image1.cols, image1.rows, QImage::QImage::Format_Grayscale8);


        ui->label3->setPixmap(QPixmap::fromImage(img));// Display on label
        ui->label3->resize(ui->label3->pixmap()->size());// Resize the label to fit the image

        cv::Mat image2;
        cv::resize(histimage2,image2,cv::Size(200,200));
        QImage img2 = QImage((const unsigned char*) (image2.data),
                            image2.cols, image2.rows, QImage::QImage::Format_Grayscale8);

        ui->label3_2->setPixmap(QPixmap::fromImage(img2));
        ui->label3_2->resize(ui->label3_2->pixmap()->size());
    }

}


void MainWindow::on_part4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp *.64"));

    if (fileName!=NULL){
        ifstream file64;

        char buffer[4225]={};

        file64.open(fileName.toStdString());
        if (!file64.is_open()) {
            cout << "Failed to open file.\n";
        } else {
            file64.read(buffer, sizeof(buffer));
            file64.close();
        }

        cv::Mat c(cv::Size(64,64),CV_8UC1);
        cv::Mat c_shift(cv::Size(64,64),CV_8UC1);

        int hist[32]={0};
        int add = 0;
        for (int i = 0; i < c.rows; i++) {
            for (int j = 0; j < c.cols; j++){
                add = 64*i+j+i; // igmore the line break

                if (buffer[add]<'A'){
                    c.at<uchar>(i,j) = (buffer[add]-48)*8;
                }
                else{
                    c.at<uchar>(i,j) = (buffer[add]-55)*8;
                }
                if(j==0){
                    c_shift.at<uchar>(i,j)=c.at<uchar>(i,j);
                }
                else{
                    c_shift.at<uchar>(i,j)=c.at<uchar>(i,j)-c.at<uchar>(i,j-1);// minus the adjacent pixel values
                }

                hist[c_shift.at<uchar>(i,j)/8]+=1;
            }
        }

        const int size = 32;
        int scale = 10;
        int histheight = 320;
        cv::Mat histimage(histheight,size*scale,CV_8UC1);

        for(int i=0;i<size;i++){
            int peak = hist[i];
            for(int j=0;j<scale;j++){
                cv::Point p1(i*scale+j,histheight-1);
                cv::Point p2(i*scale+j,histheight-peak);
                cv::line(histimage,
                         p1,
                         p2,
                         64);
            }
        }
        cv::Mat image1;
        cv::resize(c_shift,image1,cv::Size(200,200));

        QImage img = QImage((const unsigned char*) (image1.data),
                            image1.cols, image1.rows, QImage::QImage::Format_Grayscale8);

        ui->label4->setPixmap(QPixmap::fromImage(img));// Display on label
        ui->label4->resize(ui->label4->pixmap()->size());// Resize the label to fit the image

        cv::Mat image2;
        cv::resize(histimage,image2,cv::Size(200,200));
        QImage img2 = QImage((const unsigned char*) (image2.data),
                            image2.cols, image2.rows, QImage::QImage::Format_Grayscale8);

        ui->label4_2->setPixmap(QPixmap::fromImage(img2));
        ui->label4_2->resize(ui->label4_2->pixmap()->size());
    }
}



