#include <iostream>
#include "cardio.h"
#include "workout.h"
#include <QString>

using namespace std;

Cardio::Cardio(QString name, int total_cal_used, int cal_used, QString unit, QString intensity, int multiplier, int dur) : Workout(name, total_cal_used) {
    this->calories_used = cal_used;
    this->unit = unit;
    this->intensity = intensity;
    this->multiplier = multiplier;
    this->duration = dur;
}

int Cardio::calculate_calories() {
       int result = 0;
       
       return result;
}
