#include "addtaskui.h"
#include "ui_addtaskui.h"
#include "QMessageBox"
#include "task.h"
#include <cstdlib>
#include <QComboBox>

addtaskui::addtaskui(User* user, TaskPlanner* plannerptr, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addtaskui)
    , user(user)
    , planner(plannerptr)
    , priorityCombo(nullptr)
{
    ui->setupUi(this);

    // Hide the original priority text edit and replace with combo box
    ui->txtPriority->setVisible(false);

    // Create a combo box for priority selection with better UX
    priorityCombo = new QComboBox(this);
    priorityCombo->setObjectName("priorityCombo");
    priorityCombo->setGeometry(ui->txtPriority->geometry()); // Same position and size
    priorityCombo->addItem("Low");
    priorityCombo->addItem("Medium");
    priorityCombo->addItem("High");

    // Style the combo box for better visibility
    QString comboStyle = "QComboBox {"
                         "background-color: rgb(255, 255, 255);"
                         "color: rgb(0, 0, 0);"  // Black text for visibility
                         "font: 11pt \"Segoe UI\";"
                         "border: 2px solid #3498db;"
                         "border-radius: 20px;"
                         "padding: 5px 15px;"
                         "}"
                         "QComboBox:hover {"
                         "border: 2px solid #2980b9;"
                         "}"
                         "QComboBox::drop-down {"
                         "subcontrol-origin: padding;"
                         "subcontrol-position: top right;"
                         "width: 25px;"
                         "border-left-width: 1px;"
                         "border-left-color: #3498db;"
                         "border-left-style: solid;"
                         "border-top-right-radius: 20px;"
                         "border-bottom-right-radius: 20px;"
                         "}"
                         "QComboBox QAbstractItemView {"
                         "background-color: white;"
                         "color: black;"  // Black text in dropdown
                         "border: 2px solid #3498db;"
                         "border-radius: 10px;"
                         "selection-background-color: #3498db;"
                         "selection-color: white;"  // White text when selected
                         "outline: none;"
                         "}";

    priorityCombo->setStyleSheet(comboStyle);

    // Set consistent style for all input fields with dark text
    QString inputStyle = "background-color: rgb(255, 255, 255);"
                         "color: rgb(0, 0, 0);"  // Black text
                         "font: 11pt \"Segoe UI\";"
                         "border: 2px solid #3498db;"
                         "border-radius: 20px;"
                         "padding: 5px 15px;";

    ui->txtTitle->setStyleSheet(inputStyle);
    ui->txtdis->setStyleSheet(inputStyle);
    ui->txtdue->setStyleSheet(inputStyle);

    // Set placeholder text for better user guidance
    ui->txtTitle->setPlaceholderText("Enter task title");
    ui->txtdis->setPlaceholderText("Enter task description");
    ui->txtdue->setPlaceholderText("Enter due date (e.g., 1/8/2025)");
}

addtaskui::~addtaskui()
{
    delete ui;
    delete priorityCombo;
}

void addtaskui::on_btncancel_clicked()
{
    this->hide();
    parentWidget()->show();
}

void addtaskui::on_btnAdd_clicked()
{
    QString title = ui->txtTitle->toPlainText();
    QString desc = ui->txtdis->toPlainText();
    QString due = ui->txtdue->toPlainText();
    QString prio = priorityCombo->currentText();

    // Validate required fields
    if (title.isEmpty() || due.isEmpty()) {
        QMessageBox::warning(this, "Missing fields", "Title and Due Date are required.");
        return;
    }

    // Get unique task ID from planner (uses shared counter but recycles IDs properly)
    int tid = planner->allocateTaskID();

    // Create new task with allocated ID
    Task* t = new Task(tid,
                       title.toStdString(),
                       desc.toStdString(),
                       due.toStdString(),
                       prio.toStdString());

    // Add task to user's sorted task list
    user->tasks.addSorted(t);

    // Persist changes to file
    planner->saveToFile("data.txt");

    QMessageBox::information(this,"Success","Task Added");
    emit taskAdded(); // Signal to refresh task display in dashboard
    this->hide();
    parentWidget()->show();
}
