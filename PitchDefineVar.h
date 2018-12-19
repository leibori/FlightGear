#ifndef PROJECT_PITCHDEFINEVAR_H
#define PROJECT_PITCHDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class PitchDefineVar : Command {
    double pitch;
    map<string, double>* valuesMap;
public:
    PitchDefineVar(double value, map<string, double>* map) {
        pitch = value;
        valuesMap = map;
    }
    void setPitch(double newValue) { pitch = newValue; }
    int execute();
};

#endif //PROJECT_PITCHDEFINEVAR_H
