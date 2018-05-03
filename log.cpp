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
