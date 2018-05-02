#ifndef PERSON_H
#define PERSON_H

#include "QString"

class Person{
public :
    Person();
    ~Person();
    int calculate_tdee();
    int calculate_total_gain();
    int calculate_bmr();
    int calculate_diff();
private :
    QString name;
    QString gender;
    int age;
    double weight;
    double height;
    int level_of_fitness;
    double bmr;
    int physical_movement_calories;
    int digestive_calories;
    int progress;
};
#endif // PERSON_H
