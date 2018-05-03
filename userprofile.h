#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QDialog>

namespace Ui {
class UserProfile;
}

class UserProfile : public QDialog
{
    Q_OBJECT

public:
    explicit UserProfile(QWidget *parent = 0);
    ~UserProfile();

private:
    Ui::UserProfile *ui;
};

#endif // USERPROFILE_H
