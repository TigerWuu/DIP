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
    QLabel *label2;
    QPushButton *pushButton_apply;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label3;
    QLabel *label4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *tab_2;
    QPushButton *pushButton_openImg2;
    QLabel *label_colorbar;
    QLabel *label6;
    QPushButton *pushButton_pseudo_color;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label5;
    QLabel *label_2;
    QPushButton *pushButton_openImg3;
    QLabel *label7;
    QLabel *label8;
    QPushButton *pushButton_kmeans;
    QSpinBox *spinBox_k;
    QLabel *label_10;
    QSpinBox *spinBox_iter;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1135, 701);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 70, 1091, 611));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_openImg1 = new QPushButton(tab);
        pushButton_openImg1->setObjectName(QString::fromUtf8("pushButton_openImg1"));
        pushButton_openImg1->setGeometry(QRect(200, 30, 161, 71));
        label2 = new QLabel(tab);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(30, 320, 320, 240));
        label2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label2->setAlignment(Qt::AlignCenter);
        pushButton_apply = new QPushButton(tab);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(230, 220, 131, 51));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 30, 320, 240));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(260, 130, 80, 22));
        label3 = new QLabel(tab);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(370, 320, 320, 240));
        label3->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label3->setAlignment(Qt::AlignCenter);
        label4 = new QLabel(tab);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(710, 320, 320, 240));
        label4->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 290, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Emoji"));
        font.setPointSize(11);
        label_5->setFont(font);
        label_5->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 290, 61, 21));
        label_6->setFont(font);
        label_6->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_6->setTextFormat(Qt::AutoText);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(830, 290, 61, 21));
        label_7->setFont(font);
        label_7->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_openImg2 = new QPushButton(tab_2);
        pushButton_openImg2->setObjectName(QString::fromUtf8("pushButton_openImg2"));
        pushButton_openImg2->setGeometry(QRect(60, 30, 161, 71));
        label_colorbar = new QLabel(tab_2);
        label_colorbar->setObjectName(QString::fromUtf8("label_colorbar"));
        label_colorbar->setGeometry(QRect(910, 30, 20, 240));
        label_colorbar->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label_colorbar->setAlignment(Qt::AlignCenter);
        label6 = new QLabel(tab_2);
        label6->setObjectName(QString::fromUtf8("label6"));
        label6->setGeometry(QRect(570, 30, 320, 240));
        label6->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label6->setAlignment(Qt::AlignCenter);
        pushButton_pseudo_color = new QPushButton(tab_2);
        pushButton_pseudo_color->setObjectName(QString::fromUtf8("pushButton_pseudo_color"));
        pushButton_pseudo_color->setGeometry(QRect(90, 180, 131, 51));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(930, 30, 51, 21));
        label_3->setFont(font);
        label_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(930, 250, 51, 21));
        label_4->setFont(font);
        label_4->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);
        doubleSpinBox = new QDoubleSpinBox(tab_2);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(110, 140, 62, 22));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMinimum(1.047000000000000);
        doubleSpinBox->setSingleStep(1.047000000000000);
        doubleSpinBox->setValue(1.047000000000000);
        label5 = new QLabel(tab_2);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(230, 30, 320, 240));
        label5->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label5->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 110, 131, 31));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_openImg3 = new QPushButton(tab_2);
        pushButton_openImg3->setObjectName(QString::fromUtf8("pushButton_openImg3"));
        pushButton_openImg3->setGeometry(QRect(60, 330, 161, 71));
        label7 = new QLabel(tab_2);
        label7->setObjectName(QString::fromUtf8("label7"));
        label7->setGeometry(QRect(230, 310, 320, 240));
        label7->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label7->setAlignment(Qt::AlignCenter);
        label8 = new QLabel(tab_2);
        label8->setObjectName(QString::fromUtf8("label8"));
        label8->setGeometry(QRect(570, 310, 320, 240));
        label8->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215); border-color: rgb(8, 8, 8);"));
        label8->setAlignment(Qt::AlignCenter);
        pushButton_kmeans = new QPushButton(tab_2);
        pushButton_kmeans->setObjectName(QString::fromUtf8("pushButton_kmeans"));
        pushButton_kmeans->setGeometry(QRect(90, 500, 131, 51));
        spinBox_k = new QSpinBox(tab_2);
        spinBox_k->setObjectName(QString::fromUtf8("spinBox_k"));
        spinBox_k->setGeometry(QRect(160, 450, 42, 22));
        spinBox_k->setMinimum(1);
        spinBox_k->setValue(2);
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(160, 420, 41, 20));
        label_10->setAlignment(Qt::AlignCenter);
        spinBox_iter = new QSpinBox(tab_2);
        spinBox_iter->setObjectName(QString::fromUtf8("spinBox_iter"));
        spinBox_iter->setGeometry(QRect(100, 450, 42, 22));
        spinBox_iter->setMinimum(10);
        spinBox_iter->setMaximum(100);
        spinBox_iter->setSingleStep(10);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 420, 71, 21));
        label_11->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_2, QString());
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(820, -10, 141, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Heiti Std"));
        font1.setPointSize(26);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(950, 50, 161, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Palace Script MT"));
        font2.setPointSize(26);
        font2.setItalic(true);
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1135, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_openImg1->setText(QCoreApplication::translate("MainWindow", "OpemImg", nullptr));
        label2->setText(QString());
        pushButton_apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Original image", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "RGB", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "CMY", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "HSI", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "L*a*b", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "YUV", nullptr));

        label3->setText(QString());
        label4->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Plane1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Plane2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Plane3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Part1", nullptr));
        pushButton_openImg2->setText(QCoreApplication::translate("MainWindow", "OpemImg", nullptr));
        label_colorbar->setText(QString());
        label6->setText(QCoreApplication::translate("MainWindow", "Pseudo Color image", nullptr));
        pushButton_pseudo_color->setText(QCoreApplication::translate("MainWindow", "Pseudo Color", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label5->setText(QCoreApplication::translate("MainWindow", "Original image", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Color Table adjustion", nullptr));
        pushButton_openImg3->setText(QCoreApplication::translate("MainWindow", "OpemImg", nullptr));
        label7->setText(QCoreApplication::translate("MainWindow", "Original image", nullptr));
        label8->setText(QCoreApplication::translate("MainWindow", "Kmeans image", nullptr));
        pushButton_kmeans->setText(QCoreApplication::translate("MainWindow", "Kmeans", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Max_iter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Part2 & Part3", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "HW5", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TA so handsome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
