#ifndef PROJECT_HEADINGDEFINEVAR_H
#define PROJECT_HEADINGDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class HeadingDefineVar : DefineVarCommand {
    double heading;
    SymbolTable symbolTable;
public:
    HeadingDefineVar(double value, SymbolTable symbolTable1) {
        heading = value;
        symbolTable = symbolTable1;
    }
    void setHeading(double newValue) { heading = newValue; }
    void getValue() { return heading; }
    int execute();
};

#endif //PROJECT_HEADINGDEFINEVAR_H