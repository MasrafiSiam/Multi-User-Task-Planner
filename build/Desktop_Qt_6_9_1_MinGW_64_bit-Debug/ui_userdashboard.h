/********************************************************************************
** Form generated from reading UI file 'userdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDASHBOARD_H
#define UI_USERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userdashboard
{
public:
    QPushButton *btnadd;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btnLogOut;

    void setupUi(QDialog *userdashboard)
    {
        if (userdashboard->objectName().isEmpty())
            userdashboard->setObjectName("userdashboard");
        userdashboard->setEnabled(true);
        userdashboard->resize(1200, 800);
        userdashboard->setMinimumSize(QSize(1200, 800));
        userdashboard->setMaximumSize(QSize(1200, 800));
        userdashboard->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d16ba5,   /* pinkish purple */\n"
"        stop:1 #2575fc    /* vivid blue */\n"
"    );\n"
"}\n"
""));
        btnadd = new QPushButton(userdashboard);
        btnadd->setObjectName("btnadd");
        btnadd->setGeometry(QRect(1060, 30, 121, 41));
        btnadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        scrollArea = new QScrollArea(userdashboard);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 1021, 781));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QString::fromUtf8("border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;\n"
"background-color: rgb(255, 255, 255);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 991, 751));
        scrollArea->setWidget(scrollAreaWidgetContents);
        btnLogOut = new QPushButton(userdashboard);
        btnLogOut->setObjectName("btnLogOut");
        btnLogOut->setGeometry(QRect(1070, 750, 121, 41));
        btnLogOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(userdashboard);

        QMetaObject::connectSlotsByName(userdashboard);
    } // setupUi

    void retranslateUi(QDialog *userdashboard)
    {
        userdashboard->setWindowTitle(QCoreApplication::translate("userdashboard", "Dialog", nullptr));
        btnadd->setText(QCoreApplication::translate("userdashboard", "ADD", nullptr));
        btnLogOut->setText(QCoreApplication::translate("userdashboard", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userdashboard: public Ui_userdashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDASHBOARD_H
