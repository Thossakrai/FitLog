#include "weight_training.h"
#include "workout.h"
#include <QDebug>

WeightTraining::WeightTraining(QString wtname, int rep, int set, double calperrep): Workout(wtname, 0) {
   this->repetition = rep;
    this->set = set;
    this->calories_used_per_set = calperrep;
}


double WeightTraining::calculate_calories()
{
    double result = 0;
    result = repetition * set * calories_used_per_set;
    Workout::setTotalCalUsed(result);
    return result;
}
