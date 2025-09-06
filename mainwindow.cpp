#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set password field to show asterisks for security
    ui->txtpassword->setEchoMode(QLineEdit::Password);

    // Set placeholder text for better user experience
    ui->txtusername->setPlaceholderText("Enter your username");
    ui->txtpassword->setPlaceholderText("Enter your password");

    // Apply consistent styling to input fields
    QString style = "background-color: rgb(255, 255, 255);"
                    "font: 18pt \"Segoe UI\";"
                    "border: none;"
                    "border-radius: 20px;"
                    "padding: 5px 15px;"
                    "color: rgb(0, 0, 0);";

    ui->txtusername->setStyleSheet(style);
    ui->txtpassword->setStyleSheet(style);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Clear login fields when returning from dashboard to prepare for new login
void MainWindow::refreshLoginFields()
{
    ui->txtusername->clear();    // Clear username field
    ui->txtpassword->clear();    // Clear password field
    currentUser = nullptr;       // Reset current user pointer
}

void MainWindow::on_BSignup_clicked()
{
    signup = new signupform(&planner, this);
    signup->show();
    this->hide();
}

void MainWindow::on_BtnUsers_clicked()
{
    currentUser = planner.GetUserHead();

    int counter = 0;
    QString userlist;

    // Iterate through user linked list with safety counter to prevent infinite loops
    while(currentUser && counter < 1000)
    {
        userlist += "ID: " + QString::number(currentUser->userID) +
                    " | Username: " + QString::fromStdString(currentUser->username) + "\n";
        currentUser = currentUser->next;
        counter++;
    }

    // Safety check for infinite loops in linked list traversal
    if(counter >= 1000)
    {
        QMessageBox::critical(this, "Error", "Infinite Loop Detected");
        return;
    }

    if(userlist.isEmpty())
    {
        userlist = "No users registered yet";
    }

    QMessageBox::information(this, "Registered users", userlist);
}

void MainWindow::on_Blogin_clicked()
{
    QString uname = ui->txtusername->toPlainText();
    QString pass = ui->txtpassword->text();

    // Validate that both fields are filled
    if(uname.isEmpty() || pass.isEmpty())
    {
        QMessageBox::information(this, "Error", "Please enter both Username & Password");
        return;
    }

    // Attempt authentication through TaskPlanner
    currentUser = planner.loginUser(uname.toStdString(), pass.toStdString());

    if(currentUser)
    {
        // Create and show user dashboard on successful login
        udashboard = new userdashboard(currentUser, &planner, this);

        // Connect dashboard destruction to refresh function to clear fields on return
        connect(udashboard, &userdashboard::destroyed, this, &MainWindow::refreshLoginFields);

        udashboard->show();
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "Error", "Login Failed");
    }
}
