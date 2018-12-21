#ifndef PROJECT_ROLLDEFINEVAR_H
#define PROJECT_ROLLDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class RollDefineVar : DefineVarCommand {
    double roll;
    SymbolTable symbolTable;
public:
    RollDefineVar(double value, SymbolTable symbolTable1) {
        roll = value;
        symbolTable = symbolTable1;
    }
    void setRoll(double newValue) { roll = newValue; }
    void getValue() { return roll; }
    int execute();
};

#endif //PROJECT_ROLLDEFINEVAR_H
