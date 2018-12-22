#ifndef PROJECT_AIRSPEEDDEFINEVAR_H
#define PROJECT_AIRSPEEDDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class AirspeedDefineVar : public DefineVarCommand {
    double airspeed;
    SymbolTable* symbolTable;
public:
    AirspeedDefineVar(double value, SymbolTable* symbolTable1) {
        airspeed = value;
        symbolTable = symbolTable1;
    }
    void setAirspeed(double newValue) { airspeed = newValue; }
    double getValue() { return airspeed; }
    void execute();
};

#endif //PROJECT_AIRSPEEDDEFINEVAR_H
