#ifndef PROJECT_RUDDERDEFINEVAR_H
#define PROJECT_RUDDERDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class RudderDefineVar : Command {
    double rudder;
    map<string, double>* valuesMap;
public:
    RudderDefineVar(double value, map<string, double>* map) {
        rudder = value;
        valuesMap = map;
    }
    void setRudder(double newValue) { rudder = newValue; }
    int execute();
};

#endif //PROJECT_RUDDERDEFINEVAR_H
