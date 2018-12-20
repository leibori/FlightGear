#ifndef PROJECT_BREAKSDEFINEVAR_H
#define PROJECT_BREAKSDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class BreaksDefineVar : Command {
    double breaks;
    SymbolTable symbolTable;
public:
    BreaksDefineVar(double value, SymbolTable symbolTable1) {
        breaks = value;
        symbolTable = symbolTable1;
    }
    void setBreaks(double newValue) { breaks = newValue; }
    int execute();
};

#endif //PROJECT_BREAKSDEFINEVAR_H
