#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H

#include <QDialog>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "taskplanner.h"
#include "user.h"
#include "addtaskui.h"
#include "taskwidget.h"

namespace Ui {
class userdashboard;
}

class userdashboard : public QDialog
{
    Q_OBJECT

public:
    explicit userdashboard(User* user, TaskPlanner* planner, QWidget *parent = nullptr);
    ~userdashboard();

    void loadTask();
    void searchTaskById(int taskId);
    void searchTaskByTitle(const QString& title);
    void deleteTaskById(int taskId);
    void editTaskById(int taskId);
    void updateTaskStatus(int taskId, const QString& newStatus);
    void sortTasks(const QString& sortBy);

    // New method to get next available task ID for display
    int getNextAvailableTaskID() const;

signals:
    void loggedOut();

private slots:
    void on_btnadd_clicked();
    void on_btnLogOut_clicked();
    void on_btnsearch_clicked();
    void on_btndelete_clicked();
    void on_btnedit_clicked();
    void on_btnStatus_clicked();
    void on_btnSort_clicked();

private:
    Ui::userdashboard *ui;
    User* user;
    TaskPlanner* planner;
    addtaskui* addtask;
    QVBoxLayout *tasksLayout;

    QLineEdit* txtSearch;
    QPushButton* btnsearch;
    QLineEdit* txtDelete;
    QPushButton* btndelete;
    QLineEdit* txtEdit;
    QPushButton* btnedit;
    QLineEdit* txtStatus;
    QPushButton* btnStatus;
    QComboBox* cmbSort;
    QPushButton* btnSort;
    QPushButton* btnadd;
    QPushButton* btnLogOut;
    QComboBox* cmbSearchType;
    QComboBox* cmbStatusType;
};

#endif // USERDASHBOARD_H
