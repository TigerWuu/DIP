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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox_mask_type;
    QPushButton *pushButton_OpenImg;
    QComboBox *comboBox_mask_size;
    QComboBox *comboBox_mask_coefficient;
    QLabel *label;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_restore;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(978, 708);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox_mask_type = new QComboBox(centralwidget);
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->addItem(QString());
        comboBox_mask_type->setObjectName(QString::fromUtf8("comboBox_mask_type"));
        comboBox_mask_type->setEnabled(false);
        comboBox_mask_type->setGeometry(QRect(89, 230, 91, 31));
        comboBox_mask_type->setEditable(false);
        pushButton_OpenImg = new QPushButton(centralwidget);
        pushButton_OpenImg->setObjectName(QString::fromUtf8("pushButton_OpenImg"));
        pushButton_OpenImg->setGeometry(QRect(20, 150, 161, 61));
        comboBox_mask_size = new QComboBox(centralwidget);
        comboBox_mask_size->addItem(QString());
        comboBox_mask_size->addItem(QString());
        comboBox_mask_size->addItem(QString());
        comboBox_mask_size->addItem(QString());
        comboBox_mask_size->setObjectName(QString::fromUtf8("comboBox_mask_size"));
        comboBox_mask_size->setEnabled(false);
        comboBox_mask_size->setGeometry(QRect(89, 270, 91, 31));
        comboBox_mask_size->setEditable(false);
        comboBox_mask_coefficient = new QComboBox(centralwidget);
        comboBox_mask_coefficient->addItem(QString());
        comboBox_mask_coefficient->addItem(QString());
        comboBox_mask_coefficient->addItem(QString());
        comboBox_mask_coefficient->addItem(QString());
        comboBox_mask_coefficient->setObjectName(QString::fromUtf8("comboBox_mask_coefficient"));
        comboBox_mask_coefficient->setEnabled(false);
        comboBox_mask_coefficient->setGeometry(QRect(89, 310, 91, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 103, 640, 480));
        label->setAlignment(Qt::AlignCenter);
        pushButton_apply = new QPushButton(centralwidget);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setEnabled(false);
        pushButton_apply->setGeometry(QRect(70, 460, 111, 51));
        pushButton_restore = new QPushButton(centralwidget);
        pushButton_restore->setObjectName(QString::fromUtf8("pushButton_restore"));
        pushButton_restore->setEnabled(false);
        pushButton_restore->setGeometry(QRect(70, 520, 111, 51));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 20, 141, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font.setPointSize(26);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 610, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Palace Script MT"));
        font1.setPointSize(26);
        font1.setItalic(true);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(720, 550, 161, 41));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 978, 21));
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
        comboBox_mask_type->setItemText(0, QCoreApplication::translate("MainWindow", "Type", nullptr));
        comboBox_mask_type->setItemText(1, QCoreApplication::translate("MainWindow", "Mean", nullptr));
        comboBox_mask_type->setItemText(2, QCoreApplication::translate("MainWindow", "Median", nullptr));
        comboBox_mask_type->setItemText(3, QCoreApplication::translate("MainWindow", "Max", nullptr));
        comboBox_mask_type->setItemText(4, QCoreApplication::translate("MainWindow", "Min", nullptr));
        comboBox_mask_type->setItemText(5, QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        comboBox_mask_type->setItemText(6, QCoreApplication::translate("MainWindow", "LoG", nullptr));
        comboBox_mask_type->setItemText(7, QCoreApplication::translate("MainWindow", "Sobel", nullptr));

        pushButton_OpenImg->setText(QCoreApplication::translate("MainWindow", "OpenImg", nullptr));
        comboBox_mask_size->setItemText(0, QCoreApplication::translate("MainWindow", "Size", nullptr));
        comboBox_mask_size->setItemText(1, QCoreApplication::translate("MainWindow", "3*3", nullptr));
        comboBox_mask_size->setItemText(2, QCoreApplication::translate("MainWindow", "5*5", nullptr));
        comboBox_mask_size->setItemText(3, QCoreApplication::translate("MainWindow", "7*7", nullptr));

        comboBox_mask_coefficient->setItemText(0, QCoreApplication::translate("MainWindow", "Coefficient", nullptr));
        comboBox_mask_coefficient->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_mask_coefficient->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_mask_coefficient->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Img", nullptr));
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_restore->setText(QCoreApplication::translate("MainWindow", "Restore", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "HW3", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TA so handsome", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TA so handsome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
