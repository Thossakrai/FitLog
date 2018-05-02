#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <QString>

class Workout{
public:
    Workout(QString, int);
    ~Workout();
    virtual int calculate_calories();
    void setTotalCalUsed(int tcu) {total_calories_used = tcu;}
    void setName(QString name) {this->name = name;}
    int getTotalCalUsed() {return total_calories_used;}
    QString getName() {return name;}
private:
    QString name;
    int total_calories_used;
};

#endif // WORKOUT_H
