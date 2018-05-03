#ifndef CARDIO_H
#define CARDIO_H

#include "workout.h"
#include <QString>
#include <QObject>


class Cardio : public Workout {
public:
    Cardio(QString name, double calpermin, QString intens ,int duration);
    ~Cardio();
     double calculate_calories();

private:
    int calories_used;
    double calpermin;
    QString intensity;
    int duration;
};

#endif // CARDIO_H
