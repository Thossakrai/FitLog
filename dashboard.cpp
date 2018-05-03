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

   query->prepare("SELECT TotalCal FROM FoodLogbook where Fullname = '"+name+"'");
   double sum = 0;
   if(query->exec()) {
        while(query->next())
        {
            sum += query->value(0).toDouble();
        }
   }
   qDebug() << "sum = " << sum << endl;
   ui->lcdNumber_intake->display(sum);

   double BMR = 0;
   double Goal = 0;
   query->prepare("SELECT BMR, Goal_calories FROM User where Name = '"+fllnm+"'");
   if(query->exec()) {
       while (query->next()) {
           BMR = query->value(0).toDouble();
           Goal = query->value(1).toDouble();
       }
   }

   qDebug() << "BMR = " << BMR << "Goal = " << Goal << endl;
   int progress = (sum / Goal * 100.0);
   if (progress >= 100) progress = 100;
   ui->progressBar->setValue(progress);

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

void Dashboard::on_button_refresh_clicked()
{
    this->hide();
    Dashboard Dash(this, name);
    Dash.setModal(true);
    Dash.exec();
}
