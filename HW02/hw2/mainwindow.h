#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QFileDialog>

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
    void on_part2_1_clicked();

    void on_A_clicked();

    void on_B_clicked();

    void on_compare_clicked();

    void on_histogram_clicked();

    void on_threshold_valueChanged(int value);

    void on_part2_5_clicked();

    void on_resize_slider_valueChanged(int value);

    void on_brightness_slider_valueChanged(int value);

    void on_pushButton_contrast_clicked();

    void on_PushButton_reset_clicked();

    void on_histogram_equalization_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat image;
    cv::Mat grayA;
    cv::Mat grayB;
    cv::Mat hisgray;

    cv::Mat image2;
    cv::Mat resize_image;

    int A_state = 0;
    int B_state = 0;
    int val1 = 0;
    int val2 = 0;

};
#endif // MAINWINDOW_H
