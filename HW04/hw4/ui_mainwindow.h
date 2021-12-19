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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QPushButton *pushButton_3;
    QComboBox *comboBox_filter;
    QLabel *label5;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_restore;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox_yH;
    QDoubleSpinBox *doubleSpinBox_yL;
    QLabel *label_yH;
    QLabel *label_yL;
    QPushButton *pushButton_4;
    QLabel *label6;
    QComboBox *comboBox_2;
    QPushButton *pushButton_motion_blurred;
    QPushButton *pushButton_reconstruct;
    QRadioButton *radioButton;
    QDoubleSpinBox *doubleSpinBox_cutoff_frequency;
    QLabel *label_cutoff_frequency;
    QPushButton *pushButton_idft;
    QPushButton *pushButton_difference;
    QLabel *label7;
    QLabel *label_7;
    QLabel *label_6;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1266, 961);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 140, 131, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 60, 240, 240));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 230, 93, 28));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(230, 310, 240, 240));
        label2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label2->setAlignment(Qt::AlignCenter);
        label3 = new QLabel(centralwidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(480, 310, 240, 240));
        label3->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label3->setAlignment(Qt::AlignCenter);
        label4 = new QLabel(centralwidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(480, 60, 240, 240));
        label4->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label4->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 580, 131, 51));
        comboBox_filter = new QComboBox(centralwidget);
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->setObjectName(QString::fromUtf8("comboBox_filter"));
        comboBox_filter->setGeometry(QRect(110, 640, 80, 22));
        label5 = new QLabel(centralwidget);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(230, 580, 320, 320));
        label5->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label5->setAlignment(Qt::AlignCenter);
        pushButton_apply = new QPushButton(centralwidget);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(60, 800, 131, 51));
        pushButton_restore = new QPushButton(centralwidget);
        pushButton_restore->setObjectName(QString::fromUtf8("pushButton_restore"));
        pushButton_restore->setGeometry(QRect(60, 860, 131, 51));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 670, 80, 22));
        doubleSpinBox_yH = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_yH->setObjectName(QString::fromUtf8("doubleSpinBox_yH"));
        doubleSpinBox_yH->setGeometry(QRect(50, 750, 62, 22));
        doubleSpinBox_yH->setDecimals(1);
        doubleSpinBox_yH->setSingleStep(0.200000000000000);
        doubleSpinBox_yH->setValue(3.000000000000000);
        doubleSpinBox_yL = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_yL->setObjectName(QString::fromUtf8("doubleSpinBox_yL"));
        doubleSpinBox_yL->setEnabled(true);
        doubleSpinBox_yL->setGeometry(QRect(120, 750, 62, 22));
        doubleSpinBox_yL->setDecimals(1);
        doubleSpinBox_yL->setSingleStep(0.200000000000000);
        doubleSpinBox_yL->setValue(0.400000000000000);
        label_yH = new QLabel(centralwidget);
        label_yH->setObjectName(QString::fromUtf8("label_yH"));
        label_yH->setGeometry(QRect(50, 780, 58, 15));
        label_yH->setAlignment(Qt::AlignCenter);
        label_yL = new QLabel(centralwidget);
        label_yL->setObjectName(QString::fromUtf8("label_yL"));
        label_yL->setGeometry(QRect(120, 780, 58, 15));
        label_yL->setAlignment(Qt::AlignCenter);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(630, 590, 131, 51));
        label6 = new QLabel(centralwidget);
        label6->setObjectName(QString::fromUtf8("label6"));
        label6->setGeometry(QRect(800, 580, 320, 320));
        label6->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label6->setAlignment(Qt::AlignCenter);
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(650, 790, 80, 22));
        pushButton_motion_blurred = new QPushButton(centralwidget);
        pushButton_motion_blurred->setObjectName(QString::fromUtf8("pushButton_motion_blurred"));
        pushButton_motion_blurred->setGeometry(QRect(630, 650, 131, 51));
        pushButton_reconstruct = new QPushButton(centralwidget);
        pushButton_reconstruct->setObjectName(QString::fromUtf8("pushButton_reconstruct"));
        pushButton_reconstruct->setGeometry(QRect(630, 850, 131, 51));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(630, 820, 131, 19));
        doubleSpinBox_cutoff_frequency = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_cutoff_frequency->setObjectName(QString::fromUtf8("doubleSpinBox_cutoff_frequency"));
        doubleSpinBox_cutoff_frequency->setEnabled(true);
        doubleSpinBox_cutoff_frequency->setGeometry(QRect(120, 700, 62, 22));
        doubleSpinBox_cutoff_frequency->setDecimals(1);
        doubleSpinBox_cutoff_frequency->setMinimum(10.000000000000000);
        doubleSpinBox_cutoff_frequency->setSingleStep(10.000000000000000);
        doubleSpinBox_cutoff_frequency->setValue(10.000000000000000);
        label_cutoff_frequency = new QLabel(centralwidget);
        label_cutoff_frequency->setObjectName(QString::fromUtf8("label_cutoff_frequency"));
        label_cutoff_frequency->setGeometry(QRect(120, 730, 58, 15));
        label_cutoff_frequency->setAlignment(Qt::AlignCenter);
        pushButton_idft = new QPushButton(centralwidget);
        pushButton_idft->setObjectName(QString::fromUtf8("pushButton_idft"));
        pushButton_idft->setGeometry(QRect(90, 270, 93, 28));
        pushButton_difference = new QPushButton(centralwidget);
        pushButton_difference->setObjectName(QString::fromUtf8("pushButton_difference"));
        pushButton_difference->setGeometry(QRect(90, 310, 93, 28));
        label7 = new QLabel(centralwidget);
        label7->setObjectName(QString::fromUtf8("label7"));
        label7->setGeometry(QRect(760, 70, 480, 480));
        label7->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label7->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 0, 141, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font.setPointSize(26);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1090, 10, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Palace Script MT"));
        font1.setPointSize(26);
        font1.setItalic(true);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1266, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "OpenImg", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Img", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "DFT", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "spectrum", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "phase angle", nullptr));
        label4->setText(QCoreApplication::translate("MainWindow", "IDFT", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "OpenImg", nullptr));
        comboBox_filter->setItemText(0, QCoreApplication::translate("MainWindow", "Filter", nullptr));
        comboBox_filter->setItemText(1, QCoreApplication::translate("MainWindow", "Ideal", nullptr));
        comboBox_filter->setItemText(2, QCoreApplication::translate("MainWindow", "Butterworth", nullptr));
        comboBox_filter->setItemText(3, QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        comboBox_filter->setItemText(4, QCoreApplication::translate("MainWindow", "Homomorphic", nullptr));

        label5->setText(QCoreApplication::translate("MainWindow", "Img", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_restore->setText(QCoreApplication::translate("MainWindow", "Restore", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Pass", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "High pass", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Low pass", nullptr));

        label_yH->setText(QCoreApplication::translate("MainWindow", "yH", nullptr));
        label_yL->setText(QCoreApplication::translate("MainWindow", "yL", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "OpenImg", nullptr));
        label6->setText(QCoreApplication::translate("MainWindow", "Img", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Filter", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Inverse", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Wiener", nullptr));

        pushButton_motion_blurred->setText(QCoreApplication::translate("MainWindow", "Motion blurred", nullptr));
        pushButton_reconstruct->setText(QCoreApplication::translate("MainWindow", "Reconstruct", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Gaussain noises", nullptr));
        label_cutoff_frequency->setText(QCoreApplication::translate("MainWindow", "D0", nullptr));
        pushButton_idft->setText(QCoreApplication::translate("MainWindow", "IDFT", nullptr));
        pushButton_difference->setText(QCoreApplication::translate("MainWindow", "Difference", nullptr));
        label7->setText(QCoreApplication::translate("MainWindow", "DFT vs IDFT", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "HW4", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TA so handsome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
