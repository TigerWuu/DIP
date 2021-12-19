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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_filter_currentTextChanged(const QString &arg1);

    void on_pushButton_apply_clicked();

    void on_pushButton_restore_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_doubleSpinBox_yL_valueChanged(double arg1);

    void on_doubleSpinBox_yH_valueChanged(double arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_motion_blurred_clicked();

    void on_pushButton_idft_clicked();


    void on_pushButton_difference_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat image;
    cv::Mat image2;
    cv::Mat image3;
    cv::Mat idft;

    QString filter;
    QString pass;

    float yH;
    float yL;

    cv::Mat Filter(cv::Mat shifted_mag, QString filter_type);
    cv::Mat Shift(cv::Mat mag);
};
#endif // MAINWINDOW_H
