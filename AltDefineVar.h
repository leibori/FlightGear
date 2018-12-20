#ifndef PROJECT_ALTDEFINEVAR_H
#define PROJECT_ALTDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class AltDefineVar : Command {
    double alt;
    SymbolTable symbolTable;
public:
    AltDefineVar(double value, SymbolTable symbolTable1) {
        alt = value;
        symbolTable = symbolTable1;
    }
    void setAlt(double newValue) { alt = newValue; }
    int execute();
};

#endif //PROJECT_ALTDEFINEVAR_H
