#ifndef PROJECT_AILERONDEFINEVAR_H
#define PROJECT_AILERONDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class AileronDefineVar : Command {
    double aileron;
    map<string, double>* valuesMap;
public:
    AileronDefineVar(double value, map<string, double>* map) {
        aileron = value;
        valuesMap = map;
    }
    void setAileron(double newValue) { aileron = newValue; }
    int execute();
};


#endif //PROJECT_AILERONDEFINEVAR_H
