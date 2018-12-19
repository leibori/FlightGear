#ifndef PROJECT_ROLLDEFINEVAR_H
#define PROJECT_ROLLDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class RollDefineVar : Command {
    double roll;
    map<string, double>* valuesMap;
public:
    RollDefineVar(double value, map<string, double>* map) {
        roll = value;
        valuesMap = map;
    }
    void setRoll(double newValue) { roll = newValue; }
    int execute();
};

#endif //PROJECT_ROLLDEFINEVAR_H
