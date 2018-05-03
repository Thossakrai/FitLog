#ifndef PERSON_H
#define PERSON_H

#include "QString"
#include <vector>

class Person{
public :
    Person(QString, int, QString, double, double, int, QString);
    ~Person() { }

    QString getName() {return name;}
    QString getGender() {return gender;}
    int getAge() {return age;}
    double getHeight() {return height;}
    double getWeight() {return weight;}
    int getFitness() {return level_of_fitness;}

    double getBMR() {return bmr;}
    void setTDEE(double);
    void setBMR(double);
    double calculate_tdee();
    int calculate_total_gain();
    double calculate_bmr();
    int calculate_diff();
    double calculate_goal(int);
    double calculate_bmi();


private :
    QString name;
    QString gender;
    int age;
    double weight;
    double height;
    int level_of_fitness;
    double bmr;
    double bmi;
    double tdee;
    int physical_movement_calories;
    int digestive_calories;
    int progress;
    double goal_calories;
    QString goal;
};
#endif // PERSON_H
