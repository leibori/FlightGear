#ifndef PROJECT_AIRSPEEDDEFINEVAR_H
#define PROJECT_AIRSPEEDDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class AirspeedDefineVar : DefineVarCommand {
    double airspeed;
    SymbolTable symbolTable;
public:
    AirspeedDefineVar(double value, SymbolTable symbolTable1) {
        aileron = value;
        symbolTable = symbolTable1;
    }
    void setAirspeed(double newValue) { airspeed = newValue; }
    void getValue() { return airspeed; }
    int execute();
};

#endif //PROJECT_AIRSPEEDDEFINEVAR_H
