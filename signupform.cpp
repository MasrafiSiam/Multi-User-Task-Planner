#include "signupform.h"
#include "ui_signupform.h"
#include "QMessageBox"

signupform::signupform(TaskPlanner* planner, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signupform)
    , planner(planner)
{
    ui->setupUi(this);

    // Set placeholder text for all fields
    ui->txtUsername->setPlaceholderText("Choose a username");
    ui->Txtpass->setPlaceholderText("Create a password");
    ui->txtconfirmpass->setPlaceholderText("Confirm your password");

    // Apply the exact styling you specified
    QString style = "background-color: rgb(255, 255, 255);"
                    "font: 18pt \"Segoe UI\";"
                    "border: none;"
                    "border-radius: 20px;"
                    "padding: 5px 15px;"
                    "color: rgb(0, 0, 0);";

    ui->txtUsername->setStyleSheet(style);
    ui->Txtpass->setStyleSheet(style);
    ui->txtconfirmpass->setStyleSheet(style);
}

signupform::~signupform()
{
    delete ui;
}

void signupform::on_btnCancel_clicked()
{
    this->hide();
    parentWidget()->show();
}

void signupform::on_btnregister_clicked()
{
    QString uname = ui->txtUsername->toPlainText();
    QString pass = ui->Txtpass->toPlainText();
    QString pass2 = ui->txtconfirmpass->toPlainText();

    if(uname.isEmpty() || pass.isEmpty() || pass2.isEmpty())
    {
        QMessageBox::information(this, "Error", "Please Enter both Username and Password");
        return;
    }

    if(pass==pass2)
    {
        bool success = planner->registerUser(uname.toStdString(),pass.toStdString());

        if(success)
        {
            QMessageBox::information(this,"Success","Account Created");
            parentWidget()->show();
            this->close();
        }
        else
        {
            QMessageBox::information(this,"Error","Username already Exists");
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "Password didn't match");
    }
}
