#ifndef WEIGHT_TRAINING_H
#define WEIGHT_TRAINING_H

#include <iostream>
#include "workout.h"

class WeightTraining : public Workout
{
public:
    WeightTraining(QString wtname, int rep, int set, double calperrep);
    ~WeightTraining() {}
    double calculate_calories();

private :
    int calories_used_per_set;
    int repetition;
    int set;
};
#endif // WEIGHT_TRAINING_H
