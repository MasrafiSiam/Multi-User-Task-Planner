#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "signupform.h"
#include "taskplanner.h"
#include "userdashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void refreshLoginFields();
private slots:
    void on_BSignup_clicked();
    void on_BtnUsers_clicked();
    void on_Blogin_clicked();

private:
    Ui::MainWindow *ui;
    signupform* signup;
    userdashboard* udashboard;

    TaskPlanner planner;
    User* currentUser = nullptr;
};
#endif // MAINWINDOW_H
