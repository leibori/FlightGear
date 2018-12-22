#ifndef PROJECT_BREAKSDEFINEVAR_H
#define PROJECT_BREAKSDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class BreaksDefineVar : public DefineVarCommand {
    double breaks;
    SymbolTable* symbolTable;
public:
    BreaksDefineVar(double value, SymbolTable* symbolTable1) {
        breaks = value;
        symbolTable = symbolTable1;
    }
    void setBreaks(double newValue) { breaks = newValue; }
    double getValue() { return breaks; }
    void execute();
};

#endif //PROJECT_BREAKSDEFINEVAR_H
