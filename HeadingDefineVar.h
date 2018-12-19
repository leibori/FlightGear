#ifndef PROJECT_HEADINGDEFINEVAR_H
#define PROJECT_HEADINGDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class HeadingDefineVar : Command {
    double heading;
    map<string, double>* valuesMap;
public:
    HeadingDefineVar(double value, map<string, double>* map) {
        heading = value;
        valuesMap = map;
    }
    void setHeading(double newValue) { heading = newValue; }
    int execute();
};

#endif //PROJECT_HEADINGDEFINEVAR_H
