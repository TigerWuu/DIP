#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include "myscene.h"
#include "qgraphicscircleitem.h"
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

protected:
    void resizeEvent(QResizeEvent *event);



private slots:
    void on_pushButton_openImg_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_convert_clicked();


    void on_pushButton_done_clicked();



    void on_pushButton_cancel_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_restore_clicked();

private:
    Ui::MainWindow *ui;

    void graphshow(QImage img, QGraphicsView *graph);

    void graphresize(QGraphicsView* grv);

    cv::Mat image;
    cv::Mat image_org;

    QGraphicsCircleItem* circle_topleft;
    QGraphicsCircleItem* circle_topright;
    QGraphicsCircleItem* circle_bottomleft;
    QGraphicsCircleItem* circle_bottomright;


};
#endif // MAINWINDOW_H
