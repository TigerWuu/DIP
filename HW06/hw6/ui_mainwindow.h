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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_openImg1;
    QPushButton *pushButton_apply;
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QSlider *horizontalSlider_x;
    QLabel *label_x_offset;
    QSlider *horizontalSlider_y;
    QLabel *label_y_offset;
    QLabel *label_x_offset_display;
    QLabel *label_y_offset_display;
    QWidget *tab_4;
    QLabel *label_per_display;
    QSlider *horizontalSlider_mag;
    QLabel *label_mag_display;
    QLabel *label_period;
    QLabel *label_mag;
    QSlider *horizontalSlider_per;
    QWidget *tab_2;
    QWidget *tab_5;
    QPushButton *pushButton_openImg_3;
    QLabel *label6;
    QPushButton *pushButton_apply_3;
    QLabel *label5;
    QLabel *label_mag_2;
    QSlider *horizontalSlider_threshold;
    QLabel *label_threshold_display;
    QSpinBox *spinBox_size;
    QLabel *label_mag_3;
    QLabel *label_mag_4;
    QLabel *label_line_display;
    QSlider *horizontalSlider_line;
    QLabel *label7;
    QLabel *label8;
    QSpinBox *spinBox_sigma;
    QLabel *label_mag_5;
    QLabel *label_mag_6;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1110, 830);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(50, 110, 941, 681));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_openImg1 = new QPushButton(tab);
        pushButton_openImg1->setObjectName(QString::fromUtf8("pushButton_openImg1"));
        pushButton_openImg1->setGeometry(QRect(60, 90, 161, 71));
        pushButton_apply = new QPushButton(tab);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(90, 530, 131, 51));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 0, 320, 320));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label->setAlignment(Qt::AlignCenter);
        label2 = new QLabel(tab);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(590, 0, 320, 320));
        label2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label2->setAlignment(Qt::AlignCenter);
        label3 = new QLabel(tab);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(250, 330, 320, 320));
        label3->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label3->setAlignment(Qt::AlignCenter);
        label4 = new QLabel(tab);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(590, 330, 320, 320));
        label4->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label4->setAlignment(Qt::AlignCenter);
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 190, 221, 291));
        tabWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalSlider_x = new QSlider(tab_3);
        horizontalSlider_x->setObjectName(QString::fromUtf8("horizontalSlider_x"));
        horizontalSlider_x->setGeometry(QRect(20, 50, 160, 22));
        horizontalSlider_x->setValue(50);
        horizontalSlider_x->setOrientation(Qt::Horizontal);
        label_x_offset = new QLabel(tab_3);
        label_x_offset->setObjectName(QString::fromUtf8("label_x_offset"));
        label_x_offset->setEnabled(true);
        label_x_offset->setGeometry(QRect(20, 30, 58, 15));
        horizontalSlider_y = new QSlider(tab_3);
        horizontalSlider_y->setObjectName(QString::fromUtf8("horizontalSlider_y"));
        horizontalSlider_y->setGeometry(QRect(20, 110, 160, 22));
        horizontalSlider_y->setValue(50);
        horizontalSlider_y->setOrientation(Qt::Horizontal);
        label_y_offset = new QLabel(tab_3);
        label_y_offset->setObjectName(QString::fromUtf8("label_y_offset"));
        label_y_offset->setGeometry(QRect(20, 90, 58, 15));
        label_x_offset_display = new QLabel(tab_3);
        label_x_offset_display->setObjectName(QString::fromUtf8("label_x_offset_display"));
        label_x_offset_display->setEnabled(false);
        label_x_offset_display->setGeometry(QRect(70, 30, 21, 21));
        label_x_offset_display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_x_offset_display->setAlignment(Qt::AlignCenter);
        label_y_offset_display = new QLabel(tab_3);
        label_y_offset_display->setObjectName(QString::fromUtf8("label_y_offset_display"));
        label_y_offset_display->setEnabled(false);
        label_y_offset_display->setGeometry(QRect(70, 90, 21, 21));
        label_y_offset_display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_y_offset_display->setAlignment(Qt::AlignCenter);
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_per_display = new QLabel(tab_4);
        label_per_display->setObjectName(QString::fromUtf8("label_per_display"));
        label_per_display->setEnabled(false);
        label_per_display->setGeometry(QRect(70, 90, 21, 21));
        label_per_display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_per_display->setAlignment(Qt::AlignCenter);
        horizontalSlider_mag = new QSlider(tab_4);
        horizontalSlider_mag->setObjectName(QString::fromUtf8("horizontalSlider_mag"));
        horizontalSlider_mag->setGeometry(QRect(20, 50, 160, 22));
        horizontalSlider_mag->setMaximum(50);
        horizontalSlider_mag->setSingleStep(1);
        horizontalSlider_mag->setValue(25);
        horizontalSlider_mag->setOrientation(Qt::Horizontal);
        label_mag_display = new QLabel(tab_4);
        label_mag_display->setObjectName(QString::fromUtf8("label_mag_display"));
        label_mag_display->setEnabled(false);
        label_mag_display->setGeometry(QRect(70, 30, 21, 21));
        label_mag_display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_mag_display->setAlignment(Qt::AlignCenter);
        label_period = new QLabel(tab_4);
        label_period->setObjectName(QString::fromUtf8("label_period"));
        label_period->setGeometry(QRect(20, 90, 41, 16));
        label_mag = new QLabel(tab_4);
        label_mag->setObjectName(QString::fromUtf8("label_mag"));
        label_mag->setEnabled(true);
        label_mag->setGeometry(QRect(20, 30, 41, 16));
        horizontalSlider_per = new QSlider(tab_4);
        horizontalSlider_per->setObjectName(QString::fromUtf8("horizontalSlider_per"));
        horizontalSlider_per->setGeometry(QRect(20, 110, 160, 22));
        horizontalSlider_per->setMaximum(200);
        horizontalSlider_per->setValue(100);
        horizontalSlider_per->setOrientation(Qt::Horizontal);
        tabWidget_2->addTab(tab_4, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        pushButton_openImg_3 = new QPushButton(tab_5);
        pushButton_openImg_3->setObjectName(QString::fromUtf8("pushButton_openImg_3"));
        pushButton_openImg_3->setGeometry(QRect(50, 70, 161, 71));
        label6 = new QLabel(tab_5);
        label6->setObjectName(QString::fromUtf8("label6"));
        label6->setGeometry(QRect(580, 0, 320, 320));
        label6->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label6->setAlignment(Qt::AlignCenter);
        pushButton_apply_3 = new QPushButton(tab_5);
        pushButton_apply_3->setObjectName(QString::fromUtf8("pushButton_apply_3"));
        pushButton_apply_3->setGeometry(QRect(70, 460, 131, 51));
        label5 = new QLabel(tab_5);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(240, 0, 320, 320));
        label5->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label5->setAlignment(Qt::AlignCenter);
        label_mag_2 = new QLabel(tab_5);
        label_mag_2->setObjectName(QString::fromUtf8("label_mag_2"));
        label_mag_2->setEnabled(true);
        label_mag_2->setGeometry(QRect(70, 240, 91, 16));
        horizontalSlider_threshold = new QSlider(tab_5);
        horizontalSlider_threshold->setObjectName(QString::fromUtf8("horizontalSlider_threshold"));
        horizontalSlider_threshold->setGeometry(QRect(60, 260, 160, 22));
        horizontalSlider_threshold->setMaximum(255);
        horizontalSlider_threshold->setSingleStep(1);
        horizontalSlider_threshold->setValue(128);
        horizontalSlider_threshold->setOrientation(Qt::Horizontal);
        label_threshold_display = new QLabel(tab_5);
        label_threshold_display->setObjectName(QString::fromUtf8("label_threshold_display"));
        label_threshold_display->setEnabled(false);
        label_threshold_display->setGeometry(QRect(180, 240, 21, 21));
        label_threshold_display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_threshold_display->setAlignment(Qt::AlignCenter);
        spinBox_size = new QSpinBox(tab_5);
        spinBox_size->setObjectName(QString::fromUtf8("spinBox_size"));
        spinBox_size->setGeometry(QRect(70, 200, 42, 22));
        spinBox_size->setMinimum(1);
        spinBox_size->setMaximum(11);
        spinBox_size->setSingleStep(2);
        spinBox_size->setValue(3);
        label_mag_3 = new QLabel(tab_5);
        label_mag_3->setObjectName(QString::fromUtf8("label_mag_3"));
        label_mag_3->setEnabled(true);
        label_mag_3->setGeometry(QRect(70, 150, 101, 21));
        label_mag_4 = new QLabel(tab_5);
        label_mag_4->setObjectName(QString::fromUtf8("label_mag_4"));
        label_mag_4->setEnabled(true);
        label_mag_4->setGeometry(QRect(70, 300, 91, 16));
        label_line_display = new QLabel(tab_5);
        label_line_display->setObjectName(QString::fromUtf8("label_line_display"));
        label_line_display->setEnabled(false);
        label_line_display->setGeometry(QRect(180, 290, 21, 21));
        label_line_display->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(8, 8, 8);"));
        label_line_display->setAlignment(Qt::AlignCenter);
        horizontalSlider_line = new QSlider(tab_5);
        horizontalSlider_line->setObjectName(QString::fromUtf8("horizontalSlider_line"));
        horizontalSlider_line->setGeometry(QRect(60, 330, 160, 22));
        horizontalSlider_line->setMaximum(100);
        horizontalSlider_line->setSingleStep(1);
        horizontalSlider_line->setValue(0);
        horizontalSlider_line->setOrientation(Qt::Horizontal);
        label7 = new QLabel(tab_5);
        label7->setObjectName(QString::fromUtf8("label7"));
        label7->setGeometry(QRect(240, 330, 320, 320));
        label7->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label7->setAlignment(Qt::AlignCenter);
        label8 = new QLabel(tab_5);
        label8->setObjectName(QString::fromUtf8("label8"));
        label8->setGeometry(QRect(580, 330, 320, 320));
        label8->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label8->setAlignment(Qt::AlignCenter);
        spinBox_sigma = new QSpinBox(tab_5);
        spinBox_sigma->setObjectName(QString::fromUtf8("spinBox_sigma"));
        spinBox_sigma->setGeometry(QRect(120, 200, 42, 22));
        spinBox_sigma->setMinimum(1);
        spinBox_sigma->setMaximum(11);
        spinBox_sigma->setSingleStep(2);
        spinBox_sigma->setValue(3);
        label_mag_5 = new QLabel(tab_5);
        label_mag_5->setObjectName(QString::fromUtf8("label_mag_5"));
        label_mag_5->setEnabled(true);
        label_mag_5->setGeometry(QRect(70, 180, 31, 16));
        label_mag_6 = new QLabel(tab_5);
        label_mag_6->setObjectName(QString::fromUtf8("label_mag_6"));
        label_mag_6->setEnabled(true);
        label_mag_6->setGeometry(QRect(120, 180, 31, 16));
        tabWidget->addTab(tab_5, QString());
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 0, 141, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font.setPointSize(26);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(940, 80, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Palace Script MT"));
        font1.setPointSize(26);
        font1.setItalic(true);
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1110, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_openImg1->setText(QCoreApplication::translate("MainWindow", "OpemImg", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Original image", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Trapezoidal", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Wavy", nullptr));
        label4->setText(QCoreApplication::translate("MainWindow", "Circular", nullptr));
        label_x_offset->setText(QCoreApplication::translate("MainWindow", "x_offset :", nullptr));
        label_y_offset->setText(QCoreApplication::translate("MainWindow", "y_offset :", nullptr));
        label_x_offset_display->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_y_offset_display->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Trapezoidal", nullptr));
        label_per_display->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_mag_display->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        label_period->setText(QCoreApplication::translate("MainWindow", "period : ", nullptr));
        label_mag->setText(QCoreApplication::translate("MainWindow", "mag : ", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Wavy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Part1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Part2", nullptr));
        pushButton_openImg_3->setText(QCoreApplication::translate("MainWindow", "OpemImg", nullptr));
        label6->setText(QCoreApplication::translate("MainWindow", "Hough", nullptr));
        pushButton_apply_3->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label5->setText(QCoreApplication::translate("MainWindow", "Original image", nullptr));
        label_mag_2->setText(QCoreApplication::translate("MainWindow", "Binaary threshold", nullptr));
        label_threshold_display->setText(QCoreApplication::translate("MainWindow", "128", nullptr));
        label_mag_3->setText(QCoreApplication::translate("MainWindow", "Gaussian kernal", nullptr));
        label_mag_4->setText(QCoreApplication::translate("MainWindow", "Line number", nullptr));
        label_line_display->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label7->setText(QCoreApplication::translate("MainWindow", "Edge image", nullptr));
        label8->setText(QCoreApplication::translate("MainWindow", "Binary image", nullptr));
        label_mag_5->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label_mag_6->setText(QCoreApplication::translate("MainWindow", "Sigma", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Part3", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "HW6", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TA so handsome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
