#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QDebug>

#define e 2.71828182846
#define pi 3.14159265358

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox_yH->setVisible(false);
    ui->doubleSpinBox_yL->setVisible(false);
    ui->label_yH->setVisible(false);
    ui->label_yL->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY );  // 4 for original CV_BGR2RGB
        // resize to fit the label
        int y = ui->label->geometry().height();
        int x = ui->label->geometry().width();
        cv::resize(image, image,cv::Size(x,y));

        QImage img = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_Grayscale8);

        // Set the background color of label
        ui->label->setStyleSheet("QLabel { background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8); }");
        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    cv::Mat pad;
    cv::Mat image_dft;
    cv::Mat image_idft;
    cv::Mat mag;
    cv::Mat phase;
    cv::Mat idft;

    cv::Mat planes[] = {cv::Mat_<float>(image), cv::Mat::zeros(image.size(), CV_32FC1)};
    cv::merge(planes,2, image_dft);

    cv::dft(image_dft, image_dft, cv::DFT_COMPLEX_OUTPUT);

    cv::split(image_dft, planes);
    cv::cartToPolar(planes[0],planes[1], mag, phase);
    mag += cv::Scalar::all(1);   // add one to avoid th minus log value
    phase += cv::Scalar::all(1);
    cv::log(mag,mag);
    cv::log(phase,phase);

    // switch q1 and q3, q2 and q4
    mag = Shift(mag);

    // normalize to 0 to 255
    cv::normalize(mag, mag, 0, 255, cv::NORM_MINMAX);
    cv::normalize(phase, phase, 0, 255, cv::NORM_MINMAX);


    // convert the float datatype to uchar datatype for showing correctly in QT
    mag = cv::Mat_<uchar>(mag);
    phase = cv::Mat_<uchar>(phase);

    QImage mag_img = QImage((const unsigned char*) (mag.data), mag.cols, mag.rows, QImage::Format_Grayscale8);
    QImage phase_img = QImage((const unsigned char*) (phase.data), phase.cols, phase.rows, QImage::Format_Grayscale8);

    // Display on label
    ui->label2->setPixmap(QPixmap::fromImage(mag_img));
    ui->label3->setPixmap(QPixmap::fromImage(phase_img));

}

void MainWindow::on_pushButton_idft_clicked()
{
    cv::Mat pad;
    cv::Mat image_dft;
    cv::Mat image_idft;

    cv::Mat planes[] = {cv::Mat_<float>(image), cv::Mat::zeros(image.size(), CV_32FC1)};
    cv::merge(planes,2, image_dft);

    cv::dft(image_dft, image_dft, cv::DFT_COMPLEX_OUTPUT);
    cv::dft(image_dft, image_idft, cv::DFT_INVERSE);

    cv::split(image_idft, planes);
    idft = planes[0];

    cv::normalize(idft, idft, 0, 255, cv::NORM_MINMAX);
    idft = cv::Mat_<uchar>(idft);

    QImage idft_img = QImage((const unsigned char*) (idft.data), idft.cols, idft.rows, QImage::Format_Grayscale8);
    ui->label4->setPixmap(QPixmap::fromImage(idft_img));

}

void MainWindow::on_pushButton_difference_clicked()
{
    int x = image.cols;
    int y = image.rows;

    cv::Mat image_difference(cv::Size(x,y),CV_8UC1);
    for (int i=0;i<y ;i++ ) {
        for (int j=0;j<x ;j++ ) {
            image_difference.at<uchar>(i,j) = image.at<uchar>(i,j) - idft.at<uchar>(i,j);
        }
    }
    cv::resize(image_difference,image_difference,cv::Size(ui->label7->width(),ui->label7->height()));
    QImage diffence_img = QImage((const unsigned char*) (image_difference.data), image_difference.cols, image_difference.rows, QImage::Format_Grayscale8);
    ui->label7->setPixmap(QPixmap::fromImage(diffence_img));

}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image2 = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image2, image2, cv::COLOR_BGR2GRAY );  // 4 for original CV_BGR2RGB
        // resize to fit the label
        int y = ui->label5->geometry().height();
        int x = ui->label5->geometry().width();
        cv::resize(image2, image2,cv::Size(x,y));

        QImage img = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows, QImage::Format_Grayscale8);

        // Display on label
        ui->label5->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_comboBox_filter_currentTextChanged(const QString &arg1)
{
    filter = arg1;
    if(filter == "Homomorphic"){
        ui->doubleSpinBox_yH->setVisible(true);
        ui->doubleSpinBox_yL->setVisible(true);
        ui->label_yH->setVisible(true);
        ui->label_yL->setVisible(true);
        ui->comboBox->setVisible(false);
    }
    else{
        ui->doubleSpinBox_yH->setVisible(false);
        ui->doubleSpinBox_yL->setVisible(false);
        ui->label_yH->setVisible(false);
        ui->label_yL->setVisible(false);
        ui->comboBox->setVisible(true);
    }

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    pass = arg1;
}

void MainWindow::on_doubleSpinBox_yL_valueChanged(double arg1)
{
    yL = arg1;
}


void MainWindow::on_doubleSpinBox_yH_valueChanged(double arg1)
{
    yH = arg1;
}

void MainWindow::on_pushButton_apply_clicked()
{
    cv::Mat image_dft;
    cv::Mat image_idft;
    cv::Mat idft;
    // cv::Mat planes[2];

    cv::Mat planes[] = {cv::Mat_<float>(image2), cv::Mat::zeros(image2.size(), CV_32FC1)};

//    if (filter == "Homomorphic"){
//        cv::Mat temp = cv::Mat(cv::Size(image2.cols,image2.rows),CV_32FC1);

//        for (int i=0;i<image2.rows;i++){
//            for (int j=0;j<image2.cols ;j++ ) {
//                temp.at<float>(i,j) = log(image2.at<uchar>(i,j)+1);
//            }
//        }
//        planes[0] = cv::Mat_<float>(temp) ;
//        planes[1] = cv::Mat::zeros(temp.size(), CV_32FC1);
//    }
//    else{
//        planes[0] = cv::Mat_<float>(image2);
//        planes[1] = cv::Mat::zeros(image2.size(), CV_32FC1);
//    }

    cv::merge(planes,2, image_dft);

    cv::dft(image_dft, image_dft, cv::DFT_COMPLEX_OUTPUT);
    cv::split(image_dft, planes);
    planes[0] = Shift(planes[0]);
    planes[1] = Shift(planes[1]);
    planes[0] = Filter(planes[0],filter);
    planes[1] = Filter(planes[1],filter);
    planes[0] = Shift(planes[0]);
    planes[1] = Shift(planes[1]);
    cv::merge(planes,2, image_dft);
    cv::dft(image_dft, image_idft, cv::DFT_INVERSE);
    cv::split(image_idft, planes);
    idft = planes[0];

    cv::normalize(idft, idft, 0, 1, cv::NORM_MINMAX);

//    if (filter == "Homomorphic"){
//        for (int i=0;i<idft.rows;i++){
//            for (int j=0;j<idft.cols ;j++ ) {
//                // qDebug()<<idft.at<float>(i,j);
//                idft.at<float>(i,j) = pow(e,(idft.at<float>(i,j)));

//            }
//        }
//    }
    cv::normalize(idft, idft, 0, 255, cv::NORM_MINMAX);
    idft = cv::Mat_<uchar>(idft);
    QImage idft_img = QImage((const unsigned char*) (idft.data), idft.cols, idft.rows, QImage::Format_Grayscale8);
    ui->label5->setPixmap(QPixmap::fromImage(idft_img));
}

cv::Mat MainWindow::Filter(cv::Mat shifted_mag, QString filter_type){
    int x = shifted_mag.cols;
    int y = shifted_mag.rows;
    float D0 = ui->doubleSpinBox_cutoff_frequency->value();
    float D = 0;


    cv::Mat filter_mask(cv::Size(x,y),CV_32FC1);

    if (filter_type=="Ideal"){
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                D = pow(pow((i-y/2),2)+pow((j-x/2),2),0.5);
                if (D<=D0){
                    if (pass=="Low pass"){
                        filter_mask.at<float>(i,j) = 1;
                    }
                    else{
                        filter_mask.at<float>(i,j) = 0;
                    }
                }
                else{
                    if (pass=="Low pass"){
                        filter_mask.at<float>(i,j) = 0;
                    }
                    else{
                        filter_mask.at<float>(i,j) = 1;
                    }
                }
                shifted_mag.at<float>(i,j) *= filter_mask.at<float>(i,j);
            }
        }
    }
    else if(filter_type=="Butterworth"){
        int n = 1;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                D = pow(pow((i-y/2),2)+pow((j-x/2),2),0.5);
                if (pass=="Low pass"){
                    filter_mask.at<float>(i,j) = 1/(1+pow((D/D0),(2*n)));
                }
                else{
                    filter_mask.at<float>(i,j) = 1/(1+pow((D0/D),(2*n)));
                }
                shifted_mag.at<float>(i,j) *= filter_mask.at<float>(i,j);
            }
        }
    }
    else if(filter_type=="Gaussian"){
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                D = pow(pow((i-y/2),2)+pow((j-x/2),2),0.5);
                if (pass=="Low pass"){
                    filter_mask.at<float>(i,j) = pow(e,(-pow(D,2)/(2*pow(D0,2))));
                }
                else{
                    filter_mask.at<float>(i,j) = 1 - pow(e,(-pow(D,2)/(2*pow(D0,2))));
                }
                shifted_mag.at<float>(i,j) *= filter_mask.at<float>(i,j);
            }
        }
    }
    else if(filter_type=="Homomorphic"){
        yH = ui->doubleSpinBox_yH->value();
        yL = ui->doubleSpinBox_yL->value();
        int c = 5;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                D = pow(pow((i-y/2),2)+pow((j-x/2),2),0.5);
                filter_mask.at<float>(i,j) = (yH-yL)*(1-pow(e,(-c*pow(D,2)/(pow(D0,2)))))+yL;
                shifted_mag.at<float>(i,j) *= filter_mask.at<float>(i,j);
            }
        }
    }

    return shifted_mag;
}

cv::Mat MainWindow::Shift(cv::Mat mag){
    mag = mag(cv::Rect(0, 0, mag.cols & -2, mag.rows & -2));
    // rearrange the quadrants of Fourier image so the origin is at image center(shift)
    int cx = mag.cols/2;
    int cy = mag.rows/2;
    cv::Mat q0(mag, cv::Rect(0, 0, cx, cy)); // Top-Left - Create a ROI per quadrant
    cv::Mat q1(mag, cv::Rect(cx, 0, cx, cy)); // Top-Right
    cv::Mat q2(mag, cv::Rect(0, cy, cx, cy)); // Bottom-Left
    cv::Mat q3(mag, cv::Rect(cx, cy, cx, cy)); // Bottom-Right
    cv::Mat tmp; // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp); // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);
    return mag;
}

void MainWindow::on_pushButton_restore_clicked()
{
    QImage img = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows, QImage::Format_Grayscale8);
    // Display on label
    ui->label5->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image3 = cv::imread(fileName.toStdString().data());
        cv::cvtColor(image3, image3, cv::COLOR_BGR2GRAY );  // 4 for original CV_BGR2RGB
        // resize to fit the label
        int y = ui->label5->geometry().height();
        int x = ui->label5->geometry().width();
        cv::resize(image3, image3,cv::Size(x,y));

        QImage img = QImage((const unsigned char*) (image3.data), image3.cols, image3.rows, QImage::Format_Grayscale8);

        // Display on label
        ui->label6->setPixmap(QPixmap::fromImage(img));
    }
}


void MainWindow::on_pushButton_motion_blurred_clicked()
{
    float T = 1;
    float a = 0.1;
    float b = 0.1;
    cv::Mat motion(cv::Size(image3.cols,image3.rows),CV_32FC1);



}






