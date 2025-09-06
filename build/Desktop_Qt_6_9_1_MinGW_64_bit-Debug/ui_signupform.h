/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signupform
{
public:
    QPlainTextEdit *txtUsername;
    QPlainTextEdit *Txtpass;
    QPlainTextEdit *txtconfirmpass;
    QPushButton *btnregister;
    QPushButton *btnCancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *signupform)
    {
        if (signupform->objectName().isEmpty())
            signupform->setObjectName("signupform");
        signupform->resize(1200, 800);
        signupform->setMinimumSize(QSize(1200, 800));
        signupform->setMaximumSize(QSize(1200, 800));
        signupform->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #d16ba5,   /* pinkish purple */\n"
"        stop:1 #2575fc    /* vivid blue */\n"
"    );\n"
"}\n"
""));
        txtUsername = new QPlainTextEdit(signupform);
        txtUsername->setObjectName("txtUsername");
        txtUsername->setGeometry(QRect(190, 160, 761, 71));
        txtUsername->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        Txtpass = new QPlainTextEdit(signupform);
        Txtpass->setObjectName("Txtpass");
        Txtpass->setGeometry(QRect(190, 310, 761, 71));
        Txtpass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        txtconfirmpass = new QPlainTextEdit(signupform);
        txtconfirmpass->setObjectName("txtconfirmpass");
        txtconfirmpass->setGeometry(QRect(190, 470, 761, 71));
        txtconfirmpass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Segoe UI\";\n"
"\n"
"    border: none;                /* remove native border */\n"
"    border-radius: 20px;         /* makes edges round */\n"
"    padding: 5px 15px;   \n"
"color: rgb(0, 0, 0);"));
        btnregister = new QPushButton(signupform);
        btnregister->setObjectName("btnregister");
        btnregister->setGeometry(QRect(750, 630, 121, 51));
        btnregister->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnCancel = new QPushButton(signupform);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(280, 630, 121, 51));
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(signupform);
        label->setObjectName("label");
        label->setGeometry(QRect(490, 100, 141, 41));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_2 = new QLabel(signupform);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 260, 141, 41));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));
        label_3 = new QLabel(signupform);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 420, 251, 41));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: 18pt \"Segoe UI\";"));

        retranslateUi(signupform);

        QMetaObject::connectSlotsByName(signupform);
    } // setupUi

    void retranslateUi(QDialog *signupform)
    {
        signupform->setWindowTitle(QCoreApplication::translate("signupform", "Dialog", nullptr));
        btnregister->setText(QCoreApplication::translate("signupform", "register", nullptr));
        btnCancel->setText(QCoreApplication::translate("signupform", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("signupform", "Username ", nullptr));
        label_2->setText(QCoreApplication::translate("signupform", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("signupform", "Re-write Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signupform: public Ui_signupform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
