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
    void on_pushButton_OpenImg_clicked();

    void on_comboBox_mask_type_currentTextChanged(const QString &arg1);

    void on_comboBox_mask_size_currentTextChanged(const QString &arg1);

    void on_comboBox_mask_coefficient_currentTextChanged(const QString &arg1);

    void on_pushButton_apply_clicked();

    void on_pushButton_restore_clicked();

private:
    Ui::MainWindow *ui;
    void determine();

    cv::Mat image;
    QString mask_type;
    QString mask_size;
    QString mask_coefficient;
};
#endif // MAINWINDOW_H
