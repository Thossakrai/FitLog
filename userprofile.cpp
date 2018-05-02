#include "userprofile.h"
#include "ui_userprofile.h"

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
