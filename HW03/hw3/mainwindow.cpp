#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <math.h>

#define e 2.71828182846


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


void MainWindow::on_pushButton_OpenImg_clicked()
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
        // Qt image
        // QImage* img = new QImage(fileName);
        QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

        // Set the background color of label
        ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
    ui->comboBox_mask_type->setEnabled(true);
    ui->comboBox_mask_size->setEnabled(true);
    ui->comboBox_mask_coefficient->setEnabled(true);
}

void MainWindow::determine(){
    if (ui->comboBox_mask_type->currentText()!="Type" && ui->comboBox_mask_size->currentText()!="Size" && ui->comboBox_mask_coefficient->currentText()!="Coefficient"){
        ui->pushButton_apply->setEnabled(true);
    }
    else{
        ui->pushButton_apply->setEnabled(false);
    }
}
void MainWindow::on_comboBox_mask_type_currentTextChanged(const QString &arg1)
{
    mask_type = arg1;
    determine();
}
void MainWindow::on_comboBox_mask_size_currentTextChanged(const QString &arg1)
{
    mask_size = arg1;
    determine();
}
void MainWindow::on_comboBox_mask_coefficient_currentTextChanged(const QString &arg1)
{
    mask_coefficient = arg1;
    determine();
}

//cv::Mat fillter(QString mask, cv::Mat img)

void MainWindow::on_pushButton_apply_clicked()
{
    int x = image.cols;
    int y = image.rows;
    float sum_r = 0;
    float sum_g = 0;
    float sum_b = 0;
    int scale = mask_coefficient.toInt();

    int size = 0;

    if (mask_size == "3*3"){
        size = 3;
    }
    else if(mask_size == "5*5"){
        size = 5;
    }
    else if(mask_size == "7*7"){
        size = 7;
    }

    cv::Mat image_result = cv::Mat(cv::Size(x,y),CV_8UC3);
    cv::Mat image_padding = cv::Mat(cv::Size(x+size-1,y+size-1),CV_8UC3);
    cv::Mat mask;

    // create a padding image //
    int edge = (size-1)/2;
    for(int i=edge; i<image_padding.rows-edge;i++){
        for(int j=edge; j<image_padding.cols-edge;j++){
            image_padding.at<cv::Vec3b>(i,j)[0] = image.at<cv::Vec3b>(i-edge,j-edge)[0];
            image_padding.at<cv::Vec3b>(i,j)[1] = image.at<cv::Vec3b>(i-edge,j-edge)[1];
            image_padding.at<cv::Vec3b>(i,j)[2] = image.at<cv::Vec3b>(i-edge,j-edge)[2];
        }
    }

    if (mask_type == "Mean"){
        mask = cv::Mat::ones(cv::Size(size,size),CV_8UC1);
        int weight=(size*size);
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                sum_r = 0;
                sum_g = 0;
                sum_b = 0;
                for (int a=0;a<size ;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        sum_r += mask.at<uchar>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[0];
                        sum_g += mask.at<uchar>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[1];
                        sum_b += mask.at<uchar>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[2];
                    }
                }
                image_result.at<cv::Vec3b>(i,j)[0] = 1.0/weight*sum_r*scale;
                image_result.at<cv::Vec3b>(i,j)[1] = 1.0/weight*sum_g*scale;
                image_result.at<cv::Vec3b>(i,j)[2] = 1.0/weight*sum_b*scale;
            }
        }
    }
    else if(mask_type == "Median"){
        int **order = new int*[3];
        for (int i=0;i<3 ;i++ ) {
            order[i] = new int[size*size]{0};
        }
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                for (int a=0;a<size;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        for (int channel=0;channel<3;channel++) {
                            order[channel][a*3+b] = image_padding.at<cv::Vec3b>(a+i,b+j)[channel];
                        }
                    }
                }
                int temp = 0;
                int t = 0;
                for (int k=0;k<3 ;k++ ) {
                    t = 0;
                    while (t<size*size){
                        for(int l=0;l<size*size-1;l++){
                            if(order[k][l]>order[k][l+1]){
                                temp = order[k][l];
                                order[k][l] = order[k][l+1];
                                order[k][l+1] = temp;
                            }
                        }
                        t++;
                    }
                    image_result.at<cv::Vec3b>(i,j)[k] = scale*order[k][(size*size-1)/2];
                }
            }
        }
        for (int i=0;i<3 ;i++ ) {
            delete [] order[i];
        }
        delete [] order;
    }
    else if(mask_type == "Max"){
        int **order = new int*[3];
        for (int i=0;i<3 ;i++ ) {
            order[i] = new int[size*size]{0};
        }
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                for (int a=0;a<size;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        for (int channel=0;channel<3;channel++) {
                            order[channel][a*3+b] = image_padding.at<cv::Vec3b>(a+i,b+j)[channel];
                        }
                    }
                }
                // sort //
                int temp = 0;
                int t = 0;
                for (int k=0;k<3 ;k++ ) {
                    t = 0;
                    while (t<size*size){
                        for(int l=0;l<size*size-1;l++){
                            if(order[k][l]>order[k][l+1]){
                                temp = order[k][l];
                                order[k][l] = order[k][l+1];
                                order[k][l+1] = temp;
                            }
                        }
                        t++;
                    }
                    image_result.at<cv::Vec3b>(i,j)[k] = scale*order[k][size*size-1];
                }
            }
        }
        for (int i=0;i<3 ;i++ ) {
            delete [] order[i];
        }
        delete [] order;
    }
    else if(mask_type == "Min"){
        int **order = new int*[3];
        for (int i=0;i<3 ;i++ ) {
            order[i] = new int[size*size]{0};
        }
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                for (int a=0;a<size;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        for (int channel=0;channel<3;channel++) {
                            order[channel][a*3+b] = image_padding.at<cv::Vec3b>(a+i,b+j)[channel];
                        }
                    }
                }
                int temp = 0;
                int t = 0;
                for (int k=0;k<3 ;k++ ) {
                    t = 0;
                    while (t<size*size){
                        for(int l=0;l<size*size-1;l++){
                            if(order[k][l]>order[k][l+1]){
                                temp = order[k][l];
                                order[k][l] = order[k][l+1];
                                order[k][l+1] = temp;
                            }
                        }
                        t++;
                    }
                    image_result.at<cv::Vec3b>(i,j)[k] = scale*order[k][0];
                }
            }
        }
        for (int i=0;i<3 ;i++ ) {
            delete [] order[i];
        }
        delete [] order;
    }
    else if(mask_type == "Gaussian"){
        int K=1;
        int sigma=15;
        int weight=0;
        mask = cv::Mat(cv::Size(size,size),CV_32FC1);
        for (int s=0;s<mask.rows ;s++) {
            for(int t=0;t<mask.cols ;t++ ) {
//                mask.at<float>(s,t) = K*pow(e,-((pow(s,2)+pow(t,2))/(2*pow(sigma,2))));
                mask.at<float>(s,t) = K*pow(e,-((s*s+t*t)/(2*sigma*sigma)));
                weight += mask.at<float>(s,t);
            }
        }
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                sum_r = 0;
                sum_g = 0;
                sum_b = 0;
                for (int a=0;a<size ;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        sum_r += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[0];
                        sum_g += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[1];
                        sum_b += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[2];
                    }
                }
                image_result.at<cv::Vec3b>(i,j)[0] = 1.0/weight*sum_r*scale;
                image_result.at<cv::Vec3b>(i,j)[1] = 1.0/weight*sum_g*scale;
                image_result.at<cv::Vec3b>(i,j)[2] = 1.0/weight*sum_b*scale;
            }
        }
    }
    else if(mask_type == "LoG"){
        int K=1;
        int sigma=15;
        int weight=0;
        mask = cv::Mat(cv::Size(size,size),CV_32FC1);
        cv::Mat laplacian_mask = (cv::Mat_<int>(3, 3) << 0, 1, 0, 1, -4, 1, 0, 1, 0);
        for (int s=0;s<mask.rows ;s++) {
            for(int t=0;t<mask.cols ;t++ ) {
//                mask.at<float>(s,t) = K*pow(e,-((s^2+t^2)/(2*sigma^2)));
                mask.at<float>(s,t) = K*pow(e,-((s*s+t*t)/(2*sigma*sigma)));
                weight += mask.at<float>(s,t);
            }
        }
        // Gaussian filter //
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                sum_r = 0;
                sum_g = 0;
                sum_b = 0;
                for (int a=0;a<size ;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        sum_r += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[0];
                        sum_g += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[1];
                        sum_b += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[2];
                    }
                }
                image_result.at<cv::Vec3b>(i,j)[0] = 1.0/weight*sum_r;
                image_result.at<cv::Vec3b>(i,j)[1] = 1.0/weight*sum_g;
                image_result.at<cv::Vec3b>(i,j)[2] = 1.0/weight*sum_b;
            }
        }
        // create a padding image //
        cv::Mat image_padding_laplacian = cv::Mat(cv::Size(x+3-1,y+3-1),CV_8UC3);
        int edge = (3-1)/2;
        for(int i=edge; i<image_padding_laplacian.rows-edge;i++){
            for(int j=edge; j<image_padding_laplacian.cols-edge;j++){
                image_padding_laplacian.at<cv::Vec3b>(i,j)[0] = image_result.at<cv::Vec3b>(i-edge,j-edge)[0];
                image_padding_laplacian.at<cv::Vec3b>(i,j)[1] = image_result.at<cv::Vec3b>(i-edge,j-edge)[1];
                image_padding_laplacian.at<cv::Vec3b>(i,j)[2] = image_result.at<cv::Vec3b>(i-edge,j-edge)[2];
            }
        }
        // Laplacian filter //
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                sum_r = 0;
                sum_g = 0;
                sum_b = 0;
                for (int a=0;a<laplacian_mask.rows ;a++ ) {
                    for (int b=0;b<laplacian_mask.cols ;b++ ) {
                        sum_r += laplacian_mask.at<int>(a,b)*image_padding_laplacian.at<cv::Vec3b>(a+i,b+j)[0];
                        sum_g += laplacian_mask.at<int>(a,b)*image_padding_laplacian.at<cv::Vec3b>(a+i,b+j)[1];
                        sum_b += laplacian_mask.at<int>(a,b)*image_padding_laplacian.at<cv::Vec3b>(a+i,b+j)[2];
                    }
                }
                image_result.at<cv::Vec3b>(i,j)[0] = sum_r*scale;
                image_result.at<cv::Vec3b>(i,j)[1] = sum_g*scale;
                image_result.at<cv::Vec3b>(i,j)[2] = sum_b*scale;
            }
        }
    }
//    else if(mask_type == "LoG"){
//        float sigma=15.0;

//        mask = cv::Mat(cv::Size(size,size),CV_32FC1);
//        for (int s=0;s<mask.rows ;s++) {
//            for(int t=0;t<mask.cols ;t++ ) {
//                mask.at<float>(s,t) = (pow(s,2)+pow(t,2)-2*pow(sigma,2))/pow(sigma,4)*pow(e,-((pow(s,2)+pow(t,2))/(2*pow(sigma,2))));
//                mask.at<float>(s,t) = (s*s+t*t-2*sigma*sigma)/sigma/sigma/sigma/sigma*pow(e,-((s*s+t*t)/(2*sigma*sigma)));
//            }
//        }
//        // LoG filter //
//        for(int i=0; i<image_result.rows;i++){
//            for(int j=0; j<image_result.cols;j++){
//                sum_r = 0;
//                sum_g = 0;
//                sum_b = 0;
//                for (int a=0;a<size ;a++ ) {
//                    for (int b=0;b<size ;b++ ) {
//                        sum_r += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[0];
//                        sum_g += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[1];
//                        sum_b += mask.at<float>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[2];
//                    }
//                }
//                image_result.at<cv::Vec3b>(i,j)[0] = sum_r;
//                image_result.at<cv::Vec3b>(i,j)[1] = sum_g;
//                image_result.at<cv::Vec3b>(i,j)[2] = sum_b;
//            }
//        }
//    }
    else if(mask_type == "Sobel"){
        ui->comboBox_mask_size->setCurrentText("3*3");
        size = 3;
        cv::Mat Sobel_x = (cv::Mat_<int>(3, 3) << -1, 0, 1,-2, 0, 2, -1, 0, 1);
        cv::Mat Sobel_y = (cv::Mat_<int>(3, 3) << 1, 2, 1,0, 0, 0, -1, -2, -1);

        // Sobel_x filter //
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                sum_r = 0;
                sum_g = 0;
                sum_b = 0;
                for (int a=0;a<size ;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        sum_r += Sobel_x.at<int>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[0];
                        sum_g += Sobel_x.at<int>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[1];
                        sum_b += Sobel_x.at<int>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[2];
                    }
                }
                image_result.at<cv::Vec3b>(i,j)[0] = sum_r;
                image_result.at<cv::Vec3b>(i,j)[1] = sum_g;
                image_result.at<cv::Vec3b>(i,j)[2] = sum_b;
            }
        }
        // Sobel_y filter //
        for(int i=0; i<image_result.rows;i++){
            for(int j=0; j<image_result.cols;j++){
                sum_r = 0;
                sum_g = 0;
                sum_b = 0;
                for (int a=0;a<size ;a++ ) {
                    for (int b=0;b<size ;b++ ) {
                        sum_r += Sobel_y.at<int>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[0];
                        sum_g += Sobel_y.at<int>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[1];
                        sum_b += Sobel_y.at<int>(a,b)*image_padding.at<cv::Vec3b>(a+i,b+j)[2];
                    }
                }
                image_result.at<cv::Vec3b>(i,j)[0] += sum_r;
                image_result.at<cv::Vec3b>(i,j)[1] += sum_g;
                image_result.at<cv::Vec3b>(i,j)[2] += sum_b;
            }
        }

    }

    QImage img = QImage((const unsigned char*) (image_result.data), image_result.cols, image_result.rows, QImage::Format_RGB888);
    // Set the background color of label
    ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->pushButton_restore->setEnabled(true);
}

//int **sort(int **order){

//}
void MainWindow::on_pushButton_restore_clicked()
{
    QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

    // Set the background color of label
    ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
    // Display on label
    ui->label->setPixmap(QPixmap::fromImage(img));
}

