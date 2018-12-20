#ifndef PROJECT_AIRSPEEDDEFINEVAR_H
#define PROJECT_AIRSPEEDDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class AirspeedDefineVar : Command {
    double airspeed;
    SymbolTable symbolTable;
public:
    AirspeedDefineVar(double value, SymbolTable symbolTable1) {
        aileron = value;
        symbolTable = symbolTable1;
    }
    void setAirspeed(double newValue) { airspeed = newValue; }
    int execute();
};

#endif //PROJECT_AIRSPEEDDEFINEVAR_H
