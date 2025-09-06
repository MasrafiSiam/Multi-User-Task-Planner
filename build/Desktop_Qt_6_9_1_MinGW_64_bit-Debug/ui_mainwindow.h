/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *txtusername;
    QPushButton *BSignup;
    QPushButton *Blogin;
    QPushButton *BtnUsers;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtpassword;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 800));
        MainWindow->setMaximumSize(QSize(1200, 800));
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d16ba5,   /* pinkish purple */\n"
"        stop:1 #2575fc    /* vivid blue */\n"
"    );\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        txtusername = new QPlainTextEdit(centralwidget);
        txtusername->setObjectName("txtusername");
        txtusername->setGeometry(QRect(290, 250, 631, 51));
        txtusername->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        BSignup = new QPushButton(centralwidget);
        BSignup->setObjectName("BSignup");
        BSignup->setGeometry(QRect(640, 610, 111, 41));
        BSignup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 14pt \"Segoe UI\";\n"
"\n"
"    background-color: #9b59b6;  /* signup button purple */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 5px 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #8e44ad;  /* darker purple on hover */\n"
"}\n"
""));
        Blogin = new QPushButton(centralwidget);
        Blogin->setObjectName("Blogin");
        Blogin->setGeometry(QRect(540, 450, 121, 51));
        Blogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 14pt \"Segoe UI\";\n"
"\n"
"    background-color: #3498db;  /* button color */\n"
"    color: white;                /* text color */\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;           /* spacing inside button */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;  /* hover color */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1c5980;  /* pressed color */\n"
"}"));
        BtnUsers = new QPushButton(centralwidget);
        BtnUsers->setObjectName("BtnUsers");
        BtnUsers->setGeometry(QRect(490, 730, 221, 41));
        BtnUsers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 14pt \"Segoe UI\";\n"
"\n"
"    background-color: #95a5a6;  /* neutral gray */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 5px 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #7f8c8d;  /* darker gray hover */\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 200, 141, 41));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 320, 131, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 610, 211, 41));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 12pt \"Segoe UI\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(450, 10, 421, 121));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 36pt \"Segoe UI\";"));
        txtpassword = new QLineEdit(centralwidget);
        txtpassword->setObjectName("txtpassword");
        txtpassword->setGeometry(QRect(290, 370, 641, 51));
        txtpassword->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BSignup->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        Blogin->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        BtnUsers->setText(QCoreApplication::translate("MainWindow", "Show all users", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Username ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Don't have an account ?", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Task Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
