#include <QSqlError>
#include "log.h"
#include "ui_log.h"

Log::Log(QWidget *parent, QString nm) :
    QDialog(parent), fullname(nm),
    ui(new Ui::Log)
{
    ui->setupUi(this);
    openDB();

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * query  = new QSqlQuery(fitlog_db);

    query->prepare("select FoodName from Food");
    query->exec();
    model->setQuery(*query);
    ui->comboBox_foodlist->setModel(model);
     qDebug() << (model->rowCount());
     closeDB();

     openDB();
      QSqlQueryModel * modelcd = new QSqlQueryModel();
      QSqlQuery * querycd  = new QSqlQuery(fitlog_db);
     querycd->prepare("SELECT CardioName FROM Cardio");
     querycd->exec();
     modelcd->setQuery(*querycd);
     ui->comboBox_cardiolst->setModel(modelcd);
      closeDB();

      openDB();
      QSqlQueryModel * modelwt = new QSqlQueryModel();
      QSqlQuery * querywt  = new QSqlQuery(fitlog_db);
     querywt->prepare("SELECT WTName FROM WT");
     querywt->exec();
     modelwt->setQuery(*querywt);
     ui->comboBox_weightlist->setModel(modelwt);
      closeDB();

}

Log::~Log()
{
    delete ui;
}

void Log::on_pushButton_savefood_clicked()
{
    openDB();

    QString foodname = ui->comboBox_foodlist->currentText();
    QString unit = ui->label_unit->text();
    double cal= ui->label_cal->text().toInt();
    int quantity = ui->spinBox->text().toInt() ;
    QString date = QDate::currentDate().toString(Qt::ISODate);
   Food new_food(foodname, unit, cal, quantity);
   double total_cal = new_food.calculate_calories();
    QSqlQuery query;
    query.prepare("INSERT INTO FoodLogbook(Fullname, Date, FoodName, FoodAmount, TotalCal) VALUES(?,?,?,?,?)");
    query.addBindValue(fullname);
    query.addBindValue(date);
    query.addBindValue(foodname);
    query.addBindValue(quantity);
    query.addBindValue(total_cal);
    query.exec();
    closeDB();
   this->hide();
   Dashboard dashb(this, fullname);
   dashb.setModal(true);
   dashb.exec();

}

void Log::on_comboBox_foodlist_currentIndexChanged(const QString &arg1)
{

    qDebug() << arg1 << endl;
    QString foodname = arg1;
    openDB();
    QSqlQuery query;
    query.prepare("select * from Food where Foodname = '"+foodname+"' ");

    if (query.exec()) {
        while(query.next()) {
            ui->label_unit->setText(query.value(1).toString());
            ui->label_cal->setText(query.value(2).toString());
        }
    }

    closeDB();
}

void Log::on_pushButton_cancelfood_clicked()
{
    this->hide();
    Dashboard das(this, fullname);
    das.setModal(true);
    das.exec();
}

void Log::on_pushButton_cancelweight_clicked()
{
    this->hide();
    Dashboard das(this, fullname);
    das.setModal(true);
    das.exec();
}

void Log::on_pushButton_cancelcardio_clicked()
{
    this->hide();
    Dashboard das(this, fullname);
    das.setModal(true);
    das.exec();
}

void Log::on_comboBox_cardiolst_currentTextChanged(const QString &arg1)
{

}

void Log::on_comboBox_cardiolst_currentIndexChanged(const QString &arg1)
{
    qDebug() << arg1 << endl;
    QString cardioname = arg1;
    openDB();
    QSqlQuery query;
    query.prepare("select * from Cardio where CardioName = '"+cardioname+"' ");

    if (query.exec()) {
        while(query.next()) {
            ui->label_cardiocal->setText(query.value(1).toString());
        }
    }
    closeDB();
}

void Log::on_pushButton_savecardio_clicked()
{
    openDB();

    QString cardioname = ui->comboBox_cardiolst->currentText();
    double calpermin= ui->label_cardiocal->text().toDouble();
//    qDebug() << "calpermin form label  = " << calpermin << endl;
    QString intensity= ui->comboBox_inten->currentText();

    int minute = ui->spinBox_cardiodur->text().toInt();
    QString date = QDate::currentDate().toString(Qt::ISODate);

    Cardio card(cardioname, calpermin, intensity, minute);
    double total_cal_used = card.calculate_calories();

    QSqlQuery query;
    query.prepare("INSERT INTO CardioLogbook(Fullname, Date, CardioName, TotalTime, CalUsed, Intensity) VALUES(?,?,?,?,?,?)");
    query.addBindValue(fullname);
    query.addBindValue(date);
    query.addBindValue(cardioname);
    query.addBindValue(minute);
    query.addBindValue(total_cal_used);
    query.addBindValue(intensity);

    query.exec();

    closeDB();
   this->hide();
   Dashboard dashb(this, fullname);
   dashb.setModal(true);
   dashb.exec();

}

void Log::on_comboBox_weightlist_currentIndexChanged(const QString &arg1)
{
    QString wtname = arg1;
    openDB();
    QSqlQuery query;
    query.prepare("select * from WT where WTName = '"+wtname+"' ");

    if (query.exec()) {
        while(query.next()) {
            ui->label_calperrep->setText(query.value(1).toString());
        }
    }
    closeDB();
}

void Log::on_pushButton_saveweight_clicked()
{
    QString wtname = ui->comboBox_weightlist->currentText();
    int rep = ui->spinBox_rep->text().toInt();
    int set = ui->spinBox_sets->text().toInt();
    double calperrep = ui->label_calperrep->text().toDouble();

    qDebug() << "rep = " << rep << "set = " << set << "calperrep = " << calperrep << endl;

    WeightTraining wt(wtname, rep, set, calperrep);
    double total_cal_used  = wt.calculate_calories();
    qDebug() << "total cal used = " << wt.calculate_calories() << endl;
    QString date = QDate::currentDate().toString(Qt::ISODate);

     openDB();
    QSqlQuery query;
    query.prepare("INSERT INTO WTLogbook(Fullname, Date, WTName, Repitition, Sets, TotalCalUsed) VALUES(?,?,?,?,?,?)");
    query.addBindValue(fullname);
    query.addBindValue(date);
    query.addBindValue(wtname);
    query.addBindValue(rep);
    query.addBindValue(set);
    query.addBindValue(total_cal_used);
    qDebug() << query.executedQuery();
    qDebug() << query.lastError();
    query.exec();
    closeDB();
   this->hide();
   Dashboard dashb(this, fullname);
   dashb.setModal(true);
   dashb.exec();
}
