#ifndef PROJECT_AILERONDEFINEVAR_H
#define PROJECT_AILERONDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class AileronDefineVar : Command {
    double aileron;
    SymbolTable symbolTable;
public:
    AileronDefineVar(double value, SymbolTable symbolTable1) {
        aileron = value;
        symbolTable = symbolTable1;
    }
    void setAileron(double newValue) { aileron = newValue; }
    int execute();
};


#endif //PROJECT_AILERONDEFINEVAR_H
