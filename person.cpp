#include "person.h"
#include <iostream>
#include <QSqlQuery>
#include <QDebug>
#include <QVector>

Person::Person(QString name, int ag, QString gend, double wght, double hght, int fitness, QString gl) :
    name(name), age(ag), gender(gend), weight(wght), height(hght), level_of_fitness(fitness), goal(gl) {}

void Person::setBMR(double val) {
    bmr = val;
}

void Person::setTDEE(double val) {
    tdee = val;
}

double Person::calculate_bmr() {
    int temp;
    if (gender == "Male") {
        temp = 66 + (weight * 13.7) + (5 * height)  - (6.8 * age);
    }
    else if (gender == "Female") {
        temp = 665 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
    }


    qDebug() << "BMR = " << temp << endl;

    return temp;
}

double Person::calculate_tdee() {
    QVector<double> factor = {1.2, 1.375, 1.55, 1.725, 1.9};
    double tdee;
    qDebug() << factor[0] << factor[1] << endl;
    tdee = factor[level_of_fitness] * bmr;

    qDebug() << "TDEE = " << tdee << endl;
    return tdee;
}


double Person::calculate_goal(int idx) {
         double temp;
     if (idx == 0) goal_calories = bmr;
     else if (idx == 1) {
         temp = bmr - 500;
         if (temp < 1000) {
             temp = 1000;
         }
         goal_calories = temp;
     }

    else if (idx == 2) {
        goal_calories = temp + 500;
        qDebug() << "gain weight" << goal_calories << endl;
    }
     return goal_calories;
}

double  Person::calculate_bmi() {
    bmi = weight / ((height / 100) * (height / 100));
    return bmi;
}


