#ifndef PROJECT_THROTTLEDEFINEVAR_H
#define PROJECT_THROTTLEDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class ThrottleDefineVar : Command {
    double throttle;
    map<string, double>* valuesMap;
public:
    ThrottleDefineVar(double value, map<string, double>* map) {
        throttle = value;
        valuesMap = map;
    }
    void setThrottle(double newValue) { throttle = newValue; }
    int execute();
};

#endif //PROJECT_THROTTLEDEFINEVAR_H
