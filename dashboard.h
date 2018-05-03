#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QString>
#include "log.h"
#include "mainwindow.h"
#include <QDate>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
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
    explicit Dashboard(QWidget *parent = 0, QString fllnm = "");
    ~Dashboard();

private slots:
    void on_button_log_clicked();

    void on_button_logout_clicked();

    void on_button_refresh_clicked();

private:
    QString name;
    QString date;
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
