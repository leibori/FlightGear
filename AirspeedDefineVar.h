#ifndef PROJECT_AIRSPEEDDEFINEVAR_H
#define PROJECT_AIRSPEEDDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class AirspeedDefineVar : Command {
    double airspeed;
    map<string, double>* valuesMap;
public:
    AirspeedDefineVar(double value, map<string, double>* map) {
        airspeed = value;
        valuesMap = map;
    }
    void setAirspeed(double newValue) { airspeed = newValue; }
    int execute();
};

#endif //PROJECT_AIRSPEEDDEFINEVAR_H
