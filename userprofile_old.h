#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>

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
    explicit UserProfile(QWidget *parent = 0);
    ~UserProfile();

private slots:
   void on_saveButton_clicked(bool checked);

private:
    Ui::UserProfile *ui;
};

#endif // USERPROFILE_H
