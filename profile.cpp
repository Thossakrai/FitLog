#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent, QString us, QString pw) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}
