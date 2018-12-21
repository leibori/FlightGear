#ifndef PROJECT_BREAKSDEFINEVAR_H
#define PROJECT_BREAKSDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class BreaksDefineVar : DefineVarCommand {
    double breaks;
    SymbolTable symbolTable;
public:
    BreaksDefineVar(double value, SymbolTable symbolTable1) {
        breaks = value;
        symbolTable = symbolTable1;
    }
    void setBreaks(double newValue) { breaks = newValue; }
    void getValue() { return breaks; }
    int execute();
};

#endif //PROJECT_BREAKSDEFINEVAR_H
