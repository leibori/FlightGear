#ifndef PROJECT_ELEVATORDEFINEVAR_H
#define PROJECT_ELEVATORDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class ElevatorDefineVar : Command {
    double elevator;
    SymbolTable symbolTable;
public:
    ElevatorDefineVar(double value, SymbolTable symbolTable1) {
        elevator = value;
        symbolTable = symbolTable1;
    }
    void setElevator(double newValue) { elevator = newValue; }
    int execute();
};

#endif //PROJECT_ELEVATORDEFINEVAR_H
