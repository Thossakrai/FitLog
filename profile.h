#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include "person.h"
#include "dashboard.h"

namespace Ui {
class Profile;
}

class Profile : public QDialog
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
    explicit Profile(QWidget *parent = 0, QString un = "", QString pw = "");
    ~Profile();

private:
    Ui::Profile *ui;
    QString username;
    QString password;
};

#endif // PROFILE_H
