#ifndef CARDIO_H
#define CARDIO_H

#include "workout.h"
#include <QString>
#include <QObject>


class Cardio : public Workout {
public:
    Cardio(QString, int, int,QString, QString, int ,int );
    ~Cardio();
    int calculate_calories();

private:
    int calories_used;
    QString unit;
    QString intensity;
    int multiplier;
    int duration;
};

#endif // CARDIO_H
