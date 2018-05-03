#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent, QString fllnm) :
    QDialog(parent), name(fllnm),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    bool checkDBstatus = openDB();
    if (checkDBstatus == true) ui->label_status->setText("Database Connected");
    else ui->label_status->setText("Database fail to connect");
    ui->label_fullname->setText(name);
    date = QDate::currentDate().toString(Qt::ISODate);
    ui->label_date->setText(date);

   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * query = new QSqlQuery(fitlog_db);
   query->prepare("SELECT FoodName,FoodAmount, TotalCal FROM FoodLogbook where Fullname = '"+fllnm+"' and Date = '"+date+"' ");
   query->exec();
   modal->setQuery(* query);
   ui->tableView->setModel(modal);

}

Dashboard::~Dashboard()
{
    delete ui;
}


void Dashboard::on_button_log_clicked()
{
     this->hide();
     Log log(this, name);
     log.setModal(true);
     log.exec();
}

void Dashboard::on_button_logout_clicked()
{
    this->hide();
    MainWindow mw;
    mw.show();
}
