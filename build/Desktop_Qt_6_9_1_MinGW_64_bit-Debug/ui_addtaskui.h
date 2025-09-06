/********************************************************************************
** Form generated from reading UI file 'addtaskui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASKUI_H
#define UI_ADDTASKUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addtaskui
{
public:
    QPlainTextEdit *txtTitle;
    QPlainTextEdit *txtdis;
    QPlainTextEdit *txtdue;
    QPlainTextEdit *txtPriority;
    QPushButton *btnAdd;
    QPushButton *btncancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *addtaskui)
    {
        if (addtaskui->objectName().isEmpty())
            addtaskui->setObjectName("addtaskui");
        addtaskui->resize(1200, 800);
        addtaskui->setMinimumSize(QSize(1200, 800));
        addtaskui->setMaximumSize(QSize(1200, 800));
        addtaskui->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d16ba5,   /* pinkish purple */\n"
"        stop:1 #2575fc    /* vivid blue */\n"
"    );\n"
"}\n"
""));
        txtTitle = new QPlainTextEdit(addtaskui);
        txtTitle->setObjectName("txtTitle");
        txtTitle->setGeometry(QRect(260, 80, 661, 61));
        txtTitle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        txtdis = new QPlainTextEdit(addtaskui);
        txtdis->setObjectName("txtdis");
        txtdis->setGeometry(QRect(260, 210, 661, 91));
        txtdis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        txtdue = new QPlainTextEdit(addtaskui);
        txtdue->setObjectName("txtdue");
        txtdue->setGeometry(QRect(260, 390, 661, 61));
        txtdue->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        txtPriority = new QPlainTextEdit(addtaskui);
        txtPriority->setObjectName("txtPriority");
        txtPriority->setGeometry(QRect(260, 530, 661, 61));
        txtPriority->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        btnAdd = new QPushButton(addtaskui);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(730, 640, 111, 61));
        btnAdd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 14pt \"Segoe UI\";\n"
"\n"
"    background-color: #27ae60;  /* green button color */\n"
"    color: white;               /* text color */\n"
"    border: none;               /* remove native border */\n"
"    border-radius: 20px;        /* rounded edges */\n"
"    padding: 5px 15px;          /* spacing inside button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #219150;  /* darker green on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1b7a42;  /* even darker green when pressed */\n"
"}\n"
""));
        btncancel = new QPushButton(addtaskui);
        btncancel->setObjectName("btncancel");
        btncancel->setGeometry(QRect(300, 640, 121, 61));
        btncancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 14pt \"Segoe UI\";\n"
"\n"
"    background-color: #e74c3c;  /* red button color */\n"
"    color: white;               /* text color */\n"
"    border: none;               /* remove native border */\n"
"    border-radius: 20px;        /* makes edges round */\n"
"    padding: 5px 15px;          /* spacing inside button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;  /* darker red on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #96281b;  /* even darker red when pressed */\n"
"}\n"
""));
        label = new QLabel(addtaskui);
        label->setObjectName("label");
        label->setGeometry(QRect(540, 30, 81, 41));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_2 = new QLabel(addtaskui);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 160, 181, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_3 = new QLabel(addtaskui);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 340, 141, 41));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_4 = new QLabel(addtaskui);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(520, 480, 131, 41));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));

        retranslateUi(addtaskui);

        QMetaObject::connectSlotsByName(addtaskui);
    } // setupUi

    void retranslateUi(QDialog *addtaskui)
    {
        addtaskui->setWindowTitle(QCoreApplication::translate("addtaskui", "Dialog", nullptr));
        btnAdd->setText(QCoreApplication::translate("addtaskui", "Add", nullptr));
        btncancel->setText(QCoreApplication::translate("addtaskui", "cancel", nullptr));
        label->setText(QCoreApplication::translate("addtaskui", "TITLE", nullptr));
        label_2->setText(QCoreApplication::translate("addtaskui", "DESCRIPTION", nullptr));
        label_3->setText(QCoreApplication::translate("addtaskui", "DUE DATE", nullptr));
        label_4->setText(QCoreApplication::translate("addtaskui", "PRIORITY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addtaskui: public Ui_addtaskui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASKUI_H
