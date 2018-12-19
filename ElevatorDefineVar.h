#ifndef PROJECT_ELEVATORDEFINEVAR_H
#define PROJECT_ELEVATORDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class ElevatorDefineVar : Command {
    double elevator;
    map<string, double>* valuesMap;
public:
    ElevatorDefineVar(double value, map<string, double>* map) {
        elevator = value;
        valuesMap = map;
    }
    void setElevator(double newValue) { elevator = newValue; }
    int execute();
};

#endif //PROJECT_ELEVATORDEFINEVAR_H
