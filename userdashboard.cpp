#include "userdashboard.h"
#include "ui_userdashboard.h"
#include "taskwidget.h"
#include <QLayoutItem>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QComboBox>
#include <QLabel>
#include <QSpacerItem>
#include <QGroupBox>
#include "mainwindow.h"

userdashboard::userdashboard(User* user, TaskPlanner* planner, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userdashboard)
    , user(user)
    , planner(planner)
    , addtask(nullptr)
{
    ui->setupUi(this);

    // Hide the original UI buttons since we're creating them programmatically
    ui->btnadd->setVisible(false);
    ui->btnLogOut->setVisible(false);

    // Create main layout
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // Left side - Task display area
    QWidget* leftWidget = new QWidget();
    QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);

    // Add welcome label at the top
    QLabel* welcomeLabel = new QLabel(this);
    welcomeLabel->setObjectName("welcomeLabel");
    welcomeLabel->setStyleSheet("QLabel { "
                                "color: white; "
                                "font-size: 22px; "
                                "font-weight: bold; "
                                "background: transparent; "
                                "qproperty-alignment: AlignCenter;"
                                "}");
    welcomeLabel->setText("✨ Welcome back, " + QString::fromStdString(user->username) + "! ✨");
    leftLayout->addWidget(welcomeLabel);

    // Create a new widget for the scroll area content
    QWidget* scrollContent = new QWidget();
    tasksLayout = new QVBoxLayout(scrollContent);
    scrollContent->setLayout(tasksLayout);

    // Set the widget for scroll area with bordered style
    ui->scrollArea->setWidget(scrollContent);
    ui->scrollArea->setWidgetResizable(true);

    // Make scroll area bordered and styled as a separate section
    ui->scrollArea->setStyleSheet("QScrollArea { "
                                  "background-color: rgba(255, 255, 255, 200); "
                                  "border: 3px solid #3498db; "
                                  "border-radius: 15px; "
                                  "}"
                                  "QScrollBar:vertical { "
                                  "border: none; "
                                  "background: #f0f0f0; "
                                  "width: 12px; "
                                  "margin: 0px; "
                                  "}"
                                  "QScrollBar::handle:vertical { "
                                  "background: #3498db; "
                                  "border-radius: 6px; "
                                  "min-height: 20px; "
                                  "}"
                                  "QScrollBar::handle:vertical:hover { "
                                  "background: #2980b9; "
                                  "}"
                                  "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { "
                                  "height: 0px; "
                                  "}");

    scrollContent->setStyleSheet("background: transparent;");
    leftLayout->addWidget(ui->scrollArea);

    // Right side - Control panel
    QWidget* rightWidget = new QWidget();
    rightWidget->setFixedWidth(250); // Fixed width for the control panel
    QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->setAlignment(Qt::AlignTop);
    rightLayout->setSpacing(15);

    // Add Task button
    btnadd = new QPushButton(this);
    btnadd->setObjectName("btnadd");
    btnadd->setStyleSheet("QPushButton { "
                          "background-color: #3498db; "
                          "color: white; "
                          "border: none; "
                          "border-radius: 10px; "
                          "padding: 10px; "
                          "}"
                          "QPushButton:hover {"
                          "background-color: #2980b9;"
                          "}"
                          "QPushButton:pressed {"
                          "background-color: #1c5980;"
                          "}");
    btnadd->setText("ADD TASK");
    rightLayout->addWidget(btnadd);

    // Search group
    QGroupBox* searchGroup = new QGroupBox("Search Task");
    searchGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; }");
    QVBoxLayout* searchLayout = new QVBoxLayout(searchGroup);

    cmbSearchType = new QComboBox(this);
    cmbSearchType->setObjectName("cmbSearchType");
    cmbSearchType->setStyleSheet("QComboBox { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    cmbSearchType->addItem("Search by ID");
    cmbSearchType->addItem("Search by Title");
    searchLayout->addWidget(cmbSearchType);

    txtSearch = new QLineEdit(this);
    txtSearch->setObjectName("txtSearch");
    txtSearch->setStyleSheet("QLineEdit { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    txtSearch->setPlaceholderText("Enter search term");
    searchLayout->addWidget(txtSearch);

    btnsearch = new QPushButton(this);
    btnsearch->setObjectName("btnsearch");
    btnsearch->setStyleSheet("QPushButton { background-color: #3498db; color: white; border: none; border-radius: 10px; padding: 5px; }");
    btnsearch->setText("Search");
    searchLayout->addWidget(btnsearch);

    rightLayout->addWidget(searchGroup);

    // Delete group
    QGroupBox* deleteGroup = new QGroupBox("Delete Task");
    deleteGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; }");
    QVBoxLayout* deleteLayout = new QVBoxLayout(deleteGroup);

    txtDelete = new QLineEdit(this);
    txtDelete->setObjectName("txtDelete");
    txtDelete->setStyleSheet("QLineEdit { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    txtDelete->setPlaceholderText("Enter Task ID");
    deleteLayout->addWidget(txtDelete);

    btndelete = new QPushButton(this);
    btndelete->setObjectName("btndelete");
    btndelete->setStyleSheet("QPushButton { background-color: #e74c3c; color: white; border: none; border-radius: 10px; padding: 5px; }");
    btndelete->setText("Delete");
    deleteLayout->addWidget(btndelete);

    rightLayout->addWidget(deleteGroup);

    // Edit group
    QGroupBox* editGroup = new QGroupBox("Edit Task");
    editGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; }");
    QVBoxLayout* editLayout = new QVBoxLayout(editGroup);

    txtEdit = new QLineEdit(this);
    txtEdit->setObjectName("txtEdit");
    txtEdit->setStyleSheet("QLineEdit { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    txtEdit->setPlaceholderText("Enter Task ID");
    editLayout->addWidget(txtEdit);

    btnedit = new QPushButton(this);
    btnedit->setObjectName("btnedit");
    btnedit->setStyleSheet("QPushButton { background-color: #f39c12; color: white; border: none; border-radius: 10px; padding: 5px; }");
    btnedit->setText("Edit");
    editLayout->addWidget(btnedit);

    rightLayout->addWidget(editGroup);

    // Status group
    QGroupBox* statusGroup = new QGroupBox("Update Status");
    statusGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; }");
    QVBoxLayout* statusLayout = new QVBoxLayout(statusGroup);

    txtStatus = new QLineEdit(this);
    txtStatus->setObjectName("txtStatus");
    txtStatus->setStyleSheet("QLineEdit { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    txtStatus->setPlaceholderText("Enter Task ID");
    statusLayout->addWidget(txtStatus);

    cmbStatusType = new QComboBox(this);
    cmbStatusType->setObjectName("cmbStatusType");
    cmbStatusType->setStyleSheet("QComboBox { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    cmbStatusType->addItem("Pending");
    cmbStatusType->addItem("In Progress");
    cmbStatusType->addItem("Completed");
    statusLayout->addWidget(cmbStatusType);

    btnStatus = new QPushButton(this);
    btnStatus->setObjectName("btnStatus");
    btnStatus->setStyleSheet("QPushButton { background-color: #8e44ad; color: white; border: none; border-radius: 10px; padding: 5px; }");
    btnStatus->setText("Update Status");
    statusLayout->addWidget(btnStatus);

    rightLayout->addWidget(statusGroup);

    // Sort group
    QGroupBox* sortGroup = new QGroupBox("Sort Tasks");
    sortGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; }");
    QVBoxLayout* sortLayout = new QVBoxLayout(sortGroup);

    cmbSort = new QComboBox(this);
    cmbSort->setObjectName("cmbSort");
    cmbSort->setStyleSheet("QComboBox { background-color: white; color: black; border-radius: 10px; padding: 5px; }");
    cmbSort->addItem("Priority");
    cmbSort->addItem("Due Date");
    sortLayout->addWidget(cmbSort);

    btnSort = new QPushButton(this);
    btnSort->setObjectName("btnSort");
    btnSort->setStyleSheet("QPushButton { background-color: #9b59b6; color: white; border: none; border-radius: 10px; padding: 5px; }");
    btnSort->setText("Sort");
    sortLayout->addWidget(btnSort);

    rightLayout->addWidget(sortGroup);

    // Add spacer and Log Out button at the bottom
    rightLayout->addStretch();

    btnLogOut = new QPushButton(this);
    btnLogOut->setObjectName("btnLogOut");
    btnLogOut->setStyleSheet("QPushButton { "
                             "background-color: #e67e22; "
                             "color: white; "
                             "border: none; "
                             "border-radius: 10px; "
                             "padding: 10px; "
                             "}"
                             "QPushButton:hover {"
                             "background-color: #d35400;"
                             "}"
                             "QPushButton:pressed {"
                             "background-color: #a84300;"
                             "}");
    btnLogOut->setText("Log Out");
    rightLayout->addWidget(btnLogOut);

    // Add left and right widgets to main layout
    mainLayout->addWidget(leftWidget, 3); // 3 parts for task area
    mainLayout->addWidget(rightWidget, 1); // 1 part for control panel

    // Connect all buttons
    connect(btnadd, &QPushButton::clicked, this, &userdashboard::on_btnadd_clicked);
    connect(btnLogOut, &QPushButton::clicked, this, &userdashboard::on_btnLogOut_clicked);
    connect(btnsearch, &QPushButton::clicked, this, &userdashboard::on_btnsearch_clicked);
    connect(btndelete, &QPushButton::clicked, this, &userdashboard::on_btndelete_clicked);
    connect(btnedit, &QPushButton::clicked, this, &userdashboard::on_btnedit_clicked);
    connect(btnStatus, &QPushButton::clicked, this, &userdashboard::on_btnStatus_clicked);
    connect(btnSort, &QPushButton::clicked, this, &userdashboard::on_btnSort_clicked);

    loadTask();
}

userdashboard::~userdashboard()
{
    delete ui;
    delete txtSearch;
    delete btnsearch;
    delete txtDelete;
    delete btndelete;
    delete txtEdit;
    delete btnedit;
    delete txtStatus;
    delete btnStatus;
    delete cmbSort;
    delete btnSort;
    delete btnadd;
    delete btnLogOut;
    delete cmbSearchType;
    delete cmbStatusType;
}
void userdashboard::on_btnadd_clicked()
{
    addtask = new addtaskui(user, planner, this);
    connect(addtask, &addtaskui::taskAdded, this, &userdashboard::loadTask);
    addtask->show();
    this->hide();
}

void userdashboard::loadTask()
{
    QWidget* scrollContent = ui->scrollArea->widget();
    if (!scrollContent) return;

    scrollContent->setStyleSheet("background: transparent;");

    QLayoutItem* child;
    while ((child = tasksLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }

    Task* current = user->tasks.getHead();
    while (current) {
        TaskWidget* widget = new TaskWidget(current, scrollContent);
        tasksLayout->addWidget(widget);
        current = current->next;
    }

    tasksLayout->addStretch();
    scrollContent->adjustSize();
}

void userdashboard::searchTaskById(int taskId)
{
    QWidget* scrollContent = ui->scrollArea->widget();
    if (!scrollContent) return;

    scrollContent->setStyleSheet("background: transparent;");

    QLayoutItem* child;
    while ((child = tasksLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }

    Task* foundTask = user->tasks.findTaskByID(taskId);

    if (foundTask) {
        TaskWidget* widget = new TaskWidget(foundTask, scrollContent);
        tasksLayout->addWidget(widget);
        QMessageBox::information(this, "Search Result", "Task found!");
    } else {
        QMessageBox::information(this, "Search Result", "Task not found!");
        loadTask();
    }

    tasksLayout->addStretch();
    scrollContent->adjustSize();
}

void userdashboard::searchTaskByTitle(const QString& title)
{
    QWidget* scrollContent = ui->scrollArea->widget();
    if (!scrollContent) return;

    scrollContent->setStyleSheet("background: transparent;");

    QLayoutItem* child;
    while ((child = tasksLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }

    Task* foundTask = user->tasks.searchByTitle(title.toStdString());

    if (foundTask) {
        TaskWidget* widget = new TaskWidget(foundTask, scrollContent);
        tasksLayout->addWidget(widget);
        QMessageBox::information(this, "Search Result", "Task found!");
    } else {
        QMessageBox::information(this, "Search Result", "Task not found!");
        loadTask();
    }

    tasksLayout->addStretch();
    scrollContent->adjustSize();
}

void userdashboard::deleteTaskById(int taskId)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete",
                                  "Are you sure you want to delete task ID " + QString::number(taskId) + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    bool success = user->tasks.deleteTaskByID(taskId);

    if (success) {
        planner->recycleTaskID(taskId);
        planner->saveToFile("data.txt");
        QMessageBox::information(this, "Success", "Task deleted successfully!");
        loadTask();
    } else {
        QMessageBox::warning(this, "Error", "Task not found or could not be deleted!");
    }
}

void userdashboard::editTaskById(int taskId)
{
    Task* task = user->tasks.findTaskByID(taskId);

    if (!task) {
        QMessageBox::warning(this, "Error", "Task not found!");
        return;
    }

    bool ok;
    QString title = QInputDialog::getText(this, "Edit Task", "New Title:", QLineEdit::Normal, QString::fromStdString(task->title), &ok);
    if (!ok) return;

    QString description = QInputDialog::getText(this, "Edit Task", "New Description:", QLineEdit::Normal, QString::fromStdString(task->description), &ok);
    if (!ok) return;

    QString dueDate = QInputDialog::getText(this, "Edit Task", "New Due Date:", QLineEdit::Normal, QString::fromStdString(task->dueDate), &ok);
    if (!ok) return;

    QString priority = QInputDialog::getText(this, "Edit Task", "New Priority (High/Medium/Low):", QLineEdit::Normal, QString::fromStdString(task->priority), &ok);
    if (!ok) return;

    task->title = title.toStdString();
    task->description = description.toStdString();
    task->dueDate = dueDate.toStdString();
    task->priority = priority.toStdString();

    planner->saveToFile("data.txt");
    QMessageBox::information(this, "Success", "Task updated successfully!");
    loadTask();
}

void userdashboard::updateTaskStatus(int taskId, const QString& newStatus) {
    bool success = user->tasks.updateTaskStatus(taskId, newStatus.toStdString());

    if (success) {
        planner->saveToFile("data.txt");
        QMessageBox::information(this, "Success", "Task status updated to: " + newStatus);
        loadTask();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update task status!");
    }
}

void userdashboard::sortTasks(const QString& sortBy)
{
    if (sortBy == "Priority") {
        user->tasks.sortByPriority();
        QMessageBox::information(this, "Sorted", "Tasks sorted by Priority!");
    } else if (sortBy == "Due Date") {
        user->tasks.sortByDueDate();
        QMessageBox::information(this, "Sorted", "Tasks sorted by Due Date!");
    }

    planner->saveToFile("data.txt");
    loadTask();
}

void userdashboard::on_btnsearch_clicked()
{
    QString searchText = txtSearch->text();
    QString searchType = cmbSearchType->currentText();

    if (searchText.isEmpty()) {
        QMessageBox::information(this, "Search", "Please enter a search term");
        return;
    }

    if (searchType == "Search by ID") {
        bool ok;
        int taskId = searchText.toInt(&ok);

        if (!ok) {
            QMessageBox::information(this, "Search", "Please enter a valid numeric Task ID");
            return;
        }

        searchTaskById(taskId);
    } else {
        searchTaskByTitle(searchText);
    }
}

void userdashboard::on_btndelete_clicked()
{
    QString deleteText = txtDelete->text();

    if (deleteText.isEmpty()) {
        QMessageBox::information(this, "Delete", "Please enter a Task ID to delete");
        return;
    }

    bool ok;
    int taskId = deleteText.toInt(&ok);

    if (!ok) {
        QMessageBox::information(this, "Delete", "Please enter a valid numeric Task ID");
        return;
    }

    deleteTaskById(taskId);
}

void userdashboard::on_btnedit_clicked()
{
    QString editText = txtEdit->text();

    if (editText.isEmpty()) {
        QMessageBox::information(this, "Edit", "Please enter a Task ID to edit");
        return;
    }

    bool ok;
    int taskId = editText.toInt(&ok);

    if (!ok) {
        QMessageBox::information(this, "Edit", "Please enter a valid numeric Task ID");
        return;
    }

    editTaskById(taskId);
}

void userdashboard::on_btnStatus_clicked()
{
    QString statusText = txtStatus->text();
    QString newStatus = cmbStatusType->currentText();

    if (statusText.isEmpty()) {
        QMessageBox::information(this, "Status", "Please enter a Task ID");
        return;
    }

    bool ok;
    int taskId = statusText.toInt(&ok);

    if (!ok) {
        QMessageBox::information(this, "Status", "Please enter a valid numeric Task ID");
        return;
    }

    updateTaskStatus(taskId, newStatus);
}

void userdashboard::on_btnSort_clicked()
{
    QString sortBy = cmbSort->currentText();
    sortTasks(sortBy);
}

void userdashboard::on_btnLogOut_clicked()
{
    emit loggedOut();  // Emit signal before hiding
    this->hide();
    parentWidget()->show();
}
int userdashboard::getNextAvailableTaskID() const {
    // Get the next available task ID from the planner without allocating it
    return planner->getNextAvailableTaskID();
}
