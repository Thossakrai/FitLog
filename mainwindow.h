#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "userprofile.h"
#include <QDialog>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public :
    QSqlDatabase fitlog_db;
    void closeDB(){
        fitlog_db.close();
        fitlog_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool openDB() {
        QSqlDatabase fitlog_db = QSqlDatabase::addDatabase("QSQLITE");
        fitlog_db.setDatabaseName("/Users/60090065/Documents/cpp_finalproject/fitlog.db");
        qDebug() << "DB connection status : " << fitlog_db.open()<< endl;
        if (fitlog_db.open() == true) {
            qDebug() << ("Database Connected.");
            return true;
        }
        else {
            qDebug() << ("Database Failed.");
            return false;
        }
    }

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_signin_button_clicked();

    void on_signup_button_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
