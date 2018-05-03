#include <iostream>
#include "cardio.h"
#include "workout.h"
#include <QString>
#include <QDebug>

using namespace std;

Cardio::Cardio(QString name, double calpermin, QString intensity, int dur) : Workout(name, 0) {
    this->calpermin = calpermin;
    this->intensity = intensity;
    this->duration = dur;
}

Cardio::~Cardio() {}

double Cardio::calculate_calories() {
       double result = 0;
       double multiplier = 1;
       if (intensity == "Light") {
           multiplier = 0.7;
       }
       else if (intensity == "Hard") {
           multiplier = 1.2;
       }
       qDebug() << "multiplier = " << multiplier << endl;
       qDebug() << "dur = " << duration << "calpermin = " << calpermin << endl;
       result = duration * calpermin * multiplier;
       qDebug() << "result = " << result << endl;
       Workout::setTotalCalUsed(result);
       return result;
}
