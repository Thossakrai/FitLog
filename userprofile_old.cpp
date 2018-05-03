//#include "userprofile_old.h"
//#include "ui_userprofile.h"
//#include "person.h"
//#include <QSqlQuery>
//#include <QDialog>


//UserProfile::UserProfile(QWidget *parent, QString us, QString pw) :
//    QDialog(parent), username(us), password(pw),
//    ui(new Ui::UserProfile)
//{
//    ui->setupUi(this);

//}

//UserProfile::~UserProfile()
//{
//    delete ui;
//}




//void UserProfile::on_saveButton_clicked(bool checked)
//{
//    bool checkDBstatus = openDB();
//    if (checkDBstatus == true) ui->label_status->setText("Database Connected");
//    else ui->label_status->setText("Database fail to connect");

//    QString fullname = ui->f1_fullname->text();
//    int age = ui->f2_age->text().toInt();
//    QString gender = ui->f3_gender->currentText();
//    double weight = ui->f4_weight->text().toDouble();
//    double height = ui->f5_height->text().toDouble();
//    int active_level = ui->f6_activity->currentIndex();
//    QString goal = ui->f7_goal->currentText();
//    int goal_idx = ui->f7_goal->currentIndex();

//    if (fullname.isEmpty()) {
//        ui->label_status->setText("Can't leave fullname black");
//    }

//    Person user(fullname, age, gender, weight, height, active_level, goal);

//    qDebug() << "name = " << user.getName() << endl << "age = "  << user.getAge() << endl << "gender = " << user.getGender() << endl
//             << "weight = " << user.getWeight() << endl << "height = " << user.getHeight() << endl << "active level = " << user.getFitness()
//             << "goal = " << goal << endl;

////    qDebug() << "username = " << username << "password = " << password << endl;


//    double bmr = user.calculate_bmr();
//    user.setBMR(bmr);
//    user.calculate_tdee();
//    double goalcal = user.calculate_goal(goal_idx);
//    double bmi = user.calculate_bmi();


//    QSqlQuery query;
//    query.prepare("insert into User (Username, Password, Name, Age, Gender, Weight, Height, Level_of_fitness, BMI, BMR, Goal, Goal_calories) "
//                  "values(?,?,?,?,?,?,?,?,?,?,?,?)");
//    query.addBindValue(username);
//    query.addBindValue(password);
//    query.addBindValue(fullname);
//    query.addBindValue(age);
//    query.addBindValue(gender);
//    query.addBindValue(weight);
//    query.addBindValue(height);
//    query.addBindValue(active_level);
//    query.addBindValue(bmi);
//    query.addBindValue(bmr);
//    query.addBindValue(goal);
//    query.addBindValue(goalcal);

//    query.exec();

//    closeDB();
//    this->hide();
//    Dashboard dashb;
//    dashb.setModal(true);
//    dashb.exec();
//}
