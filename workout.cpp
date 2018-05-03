#include <iostream>
#include "workout.h"
#include "QString"
#include <QSqlQuery>
#include <QSqlDatabase>

using namespace std;


Workout::Workout(QString name, int total_cal_used) {
   this->name = name;
   this->total_calories_used = total_cal_used;
}


double Workout::calculate_calories() {
}
