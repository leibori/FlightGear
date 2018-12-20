#ifndef PROJECT_HEADINGDEFINEVAR_H
#define PROJECT_HEADINGDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class HeadingDefineVar : Command {
    double heading;
    SymbolTable symbolTable;
public:
    HeadingDefineVar(double value, SymbolTable symbolTable1) {
        heading = value;
        symbolTable = symbolTable1;
    }
    void setHeading(double newValue) { heading = newValue; }
    int execute();
};

#endif //PROJECT_HEADINGDEFINEVAR_H
