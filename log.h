#ifndef LOG_H
#define LOG_H

#include <QDialog>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "dashboard.h"
#include "food.h"
#include "cardio.h"
#include <QDate>
#include "weight_training.h"

namespace Ui {
class Log;
}

class Log : public QDialog
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
    explicit Log(QWidget *parent = 0, QString name = "");
    ~Log();

private slots:
    void on_pushButton_savefood_clicked();

    void on_comboBox_foodlist_currentIndexChanged(const QString &arg1);

    void on_pushButton_cancelfood_clicked();

    void on_pushButton_cancelweight_clicked();

    void on_pushButton_cancelcardio_clicked();

    void on_comboBox_cardiolst_currentTextChanged(const QString &arg1);

    void on_comboBox_cardiolst_currentIndexChanged(const QString &arg1);

    void on_pushButton_savecardio_clicked();

    void on_comboBox_weightlist_currentIndexChanged(const QString &arg1);

    void on_pushButton_saveweight_clicked();

private:
    QString fullname;
    Ui::Log *ui;
};

#endif // LOG_H
