#ifndef PROJECT_ALTDEFINEVAR_H
#define PROJECT_ALTDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class AltDefineVar : Command {
    double alt;
    map<string, double>* valuesMap;
public:
    AltDefineVar(double value, map<string, double>* map) {
        alt = value;
        valuesMap = map;
    }
    void setAlt(double newValue) { alt = newValue; }
    int execute();
};

#endif //PROJECT_ALTDEFINEVAR_H
