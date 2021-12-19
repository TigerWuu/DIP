/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *part2_1;
    QLabel *label;
    QPushButton *A;
    QPushButton *B;
    QPushButton *compare;
    QLabel *label2;
    QPushButton *histogram;
    QLabel *label3;
    QSlider *threshold;
    QLabel *binarythreshold;
    QSlider *resize_slider;
    QPushButton *part2_5;
    QLabel *label4;
    QLabel *label_scale;
    QLabel *resize_scale;
    QSlider *brightness_slider;
    QLabel *brightness;
    QSpinBox *spinBox_r1;
    QSpinBox *spinBox_s1;
    QSpinBox *spinBox_s2;
    QSpinBox *spinBox_r2;
    QLabel *label_brightness;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_contrast;
    QPushButton *PushButton_reset;
    QLabel *label5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *histogram_equalization;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1315, 1010);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        part2_1 = new QPushButton(centralwidget);
        part2_1->setObjectName(QString::fromUtf8("part2_1"));
        part2_1->setGeometry(QRect(10, 140, 131, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 110, 320, 240));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        label->setAlignment(Qt::AlignCenter);
        A = new QPushButton(centralwidget);
        A->setObjectName(QString::fromUtf8("A"));
        A->setEnabled(false);
        A->setGeometry(QRect(90, 210, 31, 31));
        B = new QPushButton(centralwidget);
        B->setObjectName(QString::fromUtf8("B"));
        B->setEnabled(false);
        B->setGeometry(QRect(130, 210, 31, 31));
        compare = new QPushButton(centralwidget);
        compare->setObjectName(QString::fromUtf8("compare"));
        compare->setEnabled(false);
        compare->setGeometry(QRect(80, 250, 93, 28));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(580, 110, 320, 240));
        label2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        label2->setAlignment(Qt::AlignCenter);
        histogram = new QPushButton(centralwidget);
        histogram->setObjectName(QString::fromUtf8("histogram"));
        histogram->setEnabled(false);
        histogram->setGeometry(QRect(80, 330, 93, 28));
        label3 = new QLabel(centralwidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(920, 110, 320, 240));
        label3->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        label3->setAlignment(Qt::AlignCenter);
        threshold = new QSlider(centralwidget);
        threshold->setObjectName(QString::fromUtf8("threshold"));
        threshold->setEnabled(false);
        threshold->setGeometry(QRect(60, 370, 160, 22));
        threshold->setMaximum(255);
        threshold->setOrientation(Qt::Horizontal);
        binarythreshold = new QLabel(centralwidget);
        binarythreshold->setObjectName(QString::fromUtf8("binarythreshold"));
        binarythreshold->setEnabled(false);
        binarythreshold->setGeometry(QRect(60, 400, 111, 31));
        binarythreshold->setTextFormat(Qt::PlainText);
        binarythreshold->setAlignment(Qt::AlignCenter);
        resize_slider = new QSlider(centralwidget);
        resize_slider->setObjectName(QString::fromUtf8("resize_slider"));
        resize_slider->setEnabled(false);
        resize_slider->setGeometry(QRect(60, 520, 160, 22));
        resize_slider->setMinimum(5);
        resize_slider->setMaximum(20);
        resize_slider->setSingleStep(1);
        resize_slider->setSliderPosition(10);
        resize_slider->setOrientation(Qt::Horizontal);
        part2_5 = new QPushButton(centralwidget);
        part2_5->setObjectName(QString::fromUtf8("part2_5"));
        part2_5->setGeometry(QRect(10, 450, 131, 51));
        label4 = new QLabel(centralwidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(380, 440, 320, 240));
        label4->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);\n"
"border-color: rgb(8, 8, 8);"));
        label4->setAlignment(Qt::AlignCenter);
        label_scale = new QLabel(centralwidget);
        label_scale->setObjectName(QString::fromUtf8("label_scale"));
        label_scale->setEnabled(false);
        label_scale->setGeometry(QRect(160, 550, 31, 31));
        label_scale->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_scale->setAlignment(Qt::AlignCenter);
        resize_scale = new QLabel(centralwidget);
        resize_scale->setObjectName(QString::fromUtf8("resize_scale"));
        resize_scale->setEnabled(false);
        resize_scale->setGeometry(QRect(50, 550, 111, 31));
        resize_scale->setTextFormat(Qt::PlainText);
        resize_scale->setAlignment(Qt::AlignCenter);
        brightness_slider = new QSlider(centralwidget);
        brightness_slider->setObjectName(QString::fromUtf8("brightness_slider"));
        brightness_slider->setGeometry(QRect(60, 600, 160, 22));
        brightness_slider->setMinimum(-200);
        brightness_slider->setMaximum(200);
        brightness_slider->setOrientation(Qt::Horizontal);
        brightness = new QLabel(centralwidget);
        brightness->setObjectName(QString::fromUtf8("brightness"));
        brightness->setEnabled(false);
        brightness->setGeometry(QRect(50, 630, 111, 31));
        brightness->setTextFormat(Qt::PlainText);
        brightness->setAlignment(Qt::AlignCenter);
        spinBox_r1 = new QSpinBox(centralwidget);
        spinBox_r1->setObjectName(QString::fromUtf8("spinBox_r1"));
        spinBox_r1->setEnabled(false);
        spinBox_r1->setGeometry(QRect(60, 700, 42, 22));
        spinBox_r1->setMaximum(255);
        spinBox_r1->setSingleStep(10);
        spinBox_r1->setValue(64);
        spinBox_s1 = new QSpinBox(centralwidget);
        spinBox_s1->setObjectName(QString::fromUtf8("spinBox_s1"));
        spinBox_s1->setEnabled(false);
        spinBox_s1->setGeometry(QRect(110, 700, 42, 22));
        spinBox_s1->setMaximum(255);
        spinBox_s1->setSingleStep(10);
        spinBox_s1->setValue(32);
        spinBox_s2 = new QSpinBox(centralwidget);
        spinBox_s2->setObjectName(QString::fromUtf8("spinBox_s2"));
        spinBox_s2->setEnabled(false);
        spinBox_s2->setGeometry(QRect(210, 700, 42, 22));
        spinBox_s2->setMaximum(255);
        spinBox_s2->setSingleStep(10);
        spinBox_s2->setValue(224);
        spinBox_r2 = new QSpinBox(centralwidget);
        spinBox_r2->setObjectName(QString::fromUtf8("spinBox_r2"));
        spinBox_r2->setEnabled(false);
        spinBox_r2->setGeometry(QRect(160, 700, 42, 22));
        spinBox_r2->setMaximum(255);
        spinBox_r2->setSingleStep(10);
        spinBox_r2->setValue(192);
        label_brightness = new QLabel(centralwidget);
        label_brightness->setObjectName(QString::fromUtf8("label_brightness"));
        label_brightness->setEnabled(false);
        label_brightness->setGeometry(QRect(160, 630, 31, 31));
        label_brightness->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_brightness->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 730, 31, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 730, 31, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 730, 31, 16));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 730, 31, 16));
        label_5->setAlignment(Qt::AlignCenter);
        pushButton_contrast = new QPushButton(centralwidget);
        pushButton_contrast->setObjectName(QString::fromUtf8("pushButton_contrast"));
        pushButton_contrast->setEnabled(false);
        pushButton_contrast->setGeometry(QRect(60, 750, 93, 28));
        PushButton_reset = new QPushButton(centralwidget);
        PushButton_reset->setObjectName(QString::fromUtf8("PushButton_reset"));
        PushButton_reset->setEnabled(false);
        PushButton_reset->setGeometry(QRect(160, 750, 93, 28));
        label5 = new QLabel(centralwidget);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(1040, 690, 255, 255));
        label5->setStyleSheet(QString::fromUtf8(""));
        label5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(970, 0, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Palace Script MT"));
        font.setPointSize(26);
        font.setItalic(true);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 10, 141, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font1.setPointSize(26);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        histogram_equalization = new QPushButton(centralwidget);
        histogram_equalization->setObjectName(QString::fromUtf8("histogram_equalization"));
        histogram_equalization->setEnabled(false);
        histogram_equalization->setGeometry(QRect(80, 290, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1315, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        part2_1->setText(QCoreApplication::translate("MainWindow", "OpenIMG", nullptr));
        label->setText(QString());
        A->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        B->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        compare->setText(QCoreApplication::translate("MainWindow", "A-B", nullptr));
        label2->setText(QString());
        histogram->setText(QCoreApplication::translate("MainWindow", "Histogram", nullptr));
        label3->setText(QString());
        binarythreshold->setText(QCoreApplication::translate("MainWindow", "Binary threshold", nullptr));
        part2_5->setText(QCoreApplication::translate("MainWindow", "OpenIMG", nullptr));
        label4->setText(QString());
        label_scale->setText(QString());
        resize_scale->setText(QCoreApplication::translate("MainWindow", "resize_scale", nullptr));
        brightness->setText(QCoreApplication::translate("MainWindow", "brightness", nullptr));
        label_brightness->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "r1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "s1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "r2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "s2", nullptr));
        pushButton_contrast->setText(QCoreApplication::translate("MainWindow", "contrast", nullptr));
        PushButton_reset->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        label5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "TA so handsome", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "HW2", nullptr));
        histogram_equalization->setText(QCoreApplication::translate("MainWindow", "Equalization", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
