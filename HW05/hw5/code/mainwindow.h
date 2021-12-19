#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include "IP.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_openImg1_clicked();

    void on_pushButton_apply_clicked();

    void on_pushButton_openImg2_clicked();

    void on_pushButton_pseudo_color_clicked();

    void on_pushButton_openImg3_clicked();

    void on_pushButton_kmeans_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat image;
    cv::Mat image2;
    cv::Mat image3;
};
#endif // MAINWINDOW_H
