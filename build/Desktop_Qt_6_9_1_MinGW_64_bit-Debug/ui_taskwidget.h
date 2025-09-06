/********************************************************************************
** Form generated from reading UI file 'taskwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWIDGET_H
#define UI_TASKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskwidget
{
public:
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QLabel *dueDateLabel;
    QLabel *priorityLabel;
    QLabel *statusLabel;

    void setupUi(QWidget *taskwidget)
    {
        if (taskwidget->objectName().isEmpty())
            taskwidget->setObjectName("taskwidget");
        taskwidget->resize(812, 332);
        titleLabel = new QLabel(taskwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(330, 10, 81, 31));
        descriptionLabel = new QLabel(taskwidget);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setGeometry(QRect(40, 80, 81, 31));
        dueDateLabel = new QLabel(taskwidget);
        dueDateLabel->setObjectName("dueDateLabel");
        dueDateLabel->setGeometry(QRect(40, 140, 81, 31));
        priorityLabel = new QLabel(taskwidget);
        priorityLabel->setObjectName("priorityLabel");
        priorityLabel->setGeometry(QRect(40, 190, 81, 31));
        statusLabel = new QLabel(taskwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(40, 250, 81, 31));

        retranslateUi(taskwidget);

        QMetaObject::connectSlotsByName(taskwidget);
    } // setupUi

    void retranslateUi(QWidget *taskwidget)
    {
        taskwidget->setWindowTitle(QCoreApplication::translate("taskwidget", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("taskwidget", "TextLabel", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("taskwidget", "TextLabel", nullptr));
        dueDateLabel->setText(QCoreApplication::translate("taskwidget", "TextLabel", nullptr));
        priorityLabel->setText(QCoreApplication::translate("taskwidget", "TextLabel", nullptr));
        statusLabel->setText(QCoreApplication::translate("taskwidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskwidget: public Ui_taskwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWIDGET_H
