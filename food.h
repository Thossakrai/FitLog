#ifndef FOOD_H
#define FOOD_H

#include "QString"

class Food {
public :
    Food(QString, QString, double, int);
    ~Food();
    int calculate_calories();
private:
    QString name;
    QString unit;
    double calories_per_unit;
    int amount;
    int total_calories_gain;
};
#endif // FOOD_H
