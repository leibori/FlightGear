#ifndef PROJECT_ROLLDEFINEVAR_H
#define PROJECT_ROLLDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class RollDefineVar : Command {
    double roll;
    SymbolTable symbolTable;
public:
    RollDefineVar(double value, SymbolTable symbolTable1) {
        roll = value;
        symbolTable = symbolTable1;
    }
    void setRoll(double newValue) { roll = newValue; }
    int execute();
};

#endif //PROJECT_ROLLDEFINEVAR_H
