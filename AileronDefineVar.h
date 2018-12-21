#ifndef PROJECT_AILERONDEFINEVAR_H
#define PROJECT_AILERONDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class AileronDefineVar : DefineVarCommand {
    double aileron;
    SymbolTable symbolTable;
public:
    AileronDefineVar(double value, SymbolTable symbolTable1) {
        aileron = value;
        symbolTable = symbolTable1;
    }
    void setAileron(double newValue) { aileron = newValue; }
    void getValue() { return aileron; }
    int execute();
};


#endif //PROJECT_AILERONDEFINEVAR_H
