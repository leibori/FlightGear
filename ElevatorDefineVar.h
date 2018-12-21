#ifndef PROJECT_ELEVATORDEFINEVAR_H
#define PROJECT_ELEVATORDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class ElevatorDefineVar : DefineVarCommand {
    double elevator;
    SymbolTable symbolTable;
public:
    ElevatorDefineVar(double value, SymbolTable symbolTable1) {
        elevator = value;
        symbolTable = symbolTable1;
    }
    void setElevator(double newValue) { elevator = newValue; }
    void getValue() { return elevator; }
    int execute();
};

#endif //PROJECT_ELEVATORDEFINEVAR_H
