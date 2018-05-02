#include "userprofile.h"
#include "ui_userprofile.h"
#include "person.h"


UserProfile::UserProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserProfile)
{
    ui->setupUi(this);

}

UserProfile::~UserProfile()
{
    delete ui;
}




void UserProfile::on_saveButton_clicked(bool checked)
{
    bool checkDBstatus = openDB();

    QString fullname = ui->f1_fullname->text();
    QString age = ui->f2_age->text();
    QString gender = ui->f3_Gender->currentText();
    QString weight = ui->f4_weight->text();
    QString height = ui->f5_height->text();
    int active_level = ui->f6_activity->currentIndex();

    if (fullname.isEmpty()) {
        ui->label_status->setText("Can't leave fullname black");
    }

}
