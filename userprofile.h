#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include "person.h"
#include "dashboard.h"

using namespace std;

namespace Ui {
class UserProfile;
}

class UserProfile : public QDialog
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
        fitlog_db.setDatabaseName("/Users/60090065/Desktop/fitlog/fitlog.sqlite3");
        qDebug() << "DB user : " << fitlog_db.open()<< endl;
        if (fitlog_db.open() == true) {
            qDebug() << ("user Database Connected.");
            return true;
        }
        else {
            qDebug() << ("Database Failed.");
            return false;
        }
    }

public:
    explicit UserProfile(QWidget *parent = 0, QString un = "", QString pw = "");
    ~UserProfile();

private slots:
    void on_pushButton_save_clicked();

private:
    QString username;
    QString password;
    Ui::UserProfile *ui;
};

#endif // USERPROFILE_H
