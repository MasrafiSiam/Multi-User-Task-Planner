#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QDialog>
#include "taskplanner.h"

namespace Ui {
class signupform;
}

class signupform : public QDialog
{
    Q_OBJECT

public:
    explicit signupform(TaskPlanner *planner, QWidget *parent = nullptr);
    ~signupform();

private slots:
    void on_btnCancel_clicked();

    void on_btnregister_clicked();

private:
    Ui::signupform *ui;

    TaskPlanner* planner;
};

#endif // SIGNUPFORM_H
