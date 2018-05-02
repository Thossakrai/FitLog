#ifndef FOOD_H
#define FOOD_H

#include "QString"

class Food {
public :
    Food();
    ~Food();
    int calculate_calories();
private:
    QString name;
    QString unit;
    int calories_per_unit;
    int total_calories_gain;
};
#endif // FOOD_H
