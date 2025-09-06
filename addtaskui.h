#ifndef ADDTASKUI_H
#define ADDTASKUI_H

#include <QDialog>
#include <QComboBox>
#include "user.h"
#include "taskplanner.h"

namespace Ui {
class addtaskui;
}

class addtaskui : public QDialog
{
    Q_OBJECT

public:
    explicit addtaskui(User* user, TaskPlanner* plannerptr, QWidget *parent = nullptr);
    ~addtaskui();

signals:
    void taskAdded();

private slots:
    void on_btnAdd_clicked();
    void on_btncancel_clicked();

private:
    Ui::addtaskui *ui;
    User* user;
    TaskPlanner* planner;
    QComboBox* priorityCombo;
};

#endif // ADDTASKUI_H
