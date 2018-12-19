#ifndef PROJECT_BREAKSDEFINEVAR_H
#define PROJECT_BREAKSDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class BreaksDefineVar : Command {
    double breaks;
    map<string, double>* valuesMap;
public:
    BreaksDefineVar(double value, map<string, double>* map) {
        breaks = value;
        valuesMap = map;
    }
    void setBreaks(double newValue) { breaks = newValue; }
    int execute();
};

#endif //PROJECT_BREAKSDEFINEVAR_H
