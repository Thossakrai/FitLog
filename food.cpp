#include "food.h"

Food::Food(QString name, QString unit, double cal, int amount) : name(name), unit(unit), calories_per_unit(cal), amount(amount) {}
Food::~Food() { }

int Food::calculate_calories() {
    int sum = 0;
    sum = calories_per_unit * amount;
    total_calories_gain = sum;
    return sum;
}
