#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QFileInfo>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool op = openDB();
    if (op == true) {
        ui->signin_label->setText("Database Connected.");
        ui->signup_label->setText("Database Connected.");
    }
    else {
        ui->signin_label->setText("Database Failed.");
        ui->signup_label->setText("Database Failed.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signin_button_clicked()
{
    QString username_login = ui->username_signin->text();
    QString password_login = ui->password_signin->text();

    qDebug() << username_login << ", " << password_login  <<endl;

    QSqlQuery query;
    query.prepare("select * from User where Username ='"+username_login+"' and Password = '"+password_login+"'");

    if(query.exec()) {
            int count = 0;
            QString fullname;
            while (query.next())
            {   count++;
                 fullname = query.value(2).toString();
                qDebug() << "queried name = " << fullname << endl;
            }
            if (count != 1) ui->signin_label->setText("Username or password may not correct");
            else {

                ui->signin_label->setText("user found!!");
                closeDB();
                this->hide();
                Dashboard dashb(this, fullname);
                dashb.setModal(true);
                dashb.exec();

            }
    }


}


void MainWindow::on_signup_button_clicked()
{
    QString username_signup = ui->username_signup->text();
    QString password_signup = ui->password_signup->text();
    QString password_confirm = ui->password_signup_2->text();
    qDebug() << "un signup = " << username_signup <<endl;

    if (password_signup.isEmpty()) {ui->signup_label->setText("Cannot leave password blank"); return;}
    if (username_signup.isEmpty()) {ui->signup_label->setText("Cannot leave Username blank"); return;}

    if (password_confirm != password_signup) {
        ui->signup_label->setText("Password not match.");
        return;
    }

    else {

    ui->signup_label->setText("Sign up succesful.");

    QSqlQuery query;
    query.prepare("select * from User where Username = '" +username_signup+"'");
    if (query.exec()) {
        int count = 0;
        while (query.next()) {
            count++;
        }
        qDebug() << "count = " << count << endl;

        if (count >= 1) {
            ui->signup_label->setText("Username exits.");
        }
        else  {
            ui->signup_label->setText("Sign up mode");
            closeDB();
            this->hide();
            UserProfile new_user(this, username_signup, password_signup);
            new_user.setModal(true);
            new_user.exec();
        }
    }
    }

}
