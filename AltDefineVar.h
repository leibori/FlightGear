#ifndef PROJECT_ALTDEFINEVAR_H
#define PROJECT_ALTDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class AltDefineVar : DefineVarCommand {
    double alt;
    SymbolTable symbolTable;
public:
    AltDefineVar(double value, SymbolTable symbolTable1) {
        alt = value;
        symbolTable = symbolTable1;
    }
    void setAlt(double newValue) { alt = newValue; }
    void getValue() { return alt; }
    int execute();
};

#endif //PROJECT_ALTDEFINEVAR_H
