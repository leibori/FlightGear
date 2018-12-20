#ifndef PROJECT_RUDDERDEFINEVAR_H
#define PROJECT_RUDDERDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class RudderDefineVar : Command {
    double rudder;
    SymbolTable symbolTable;
public:
    RudderDefineVar(double value, SymbolTable symbolTable1) {
        rudder = value;
        symbolTable = symbolTable1;
    }
    void setRudder(double newValue) { rudder = newValue; }
    int execute();
};

#endif //PROJECT_RUDDERDEFINEVAR_H
