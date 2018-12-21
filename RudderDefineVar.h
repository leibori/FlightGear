#ifndef PROJECT_RUDDERDEFINEVAR_H
#define PROJECT_RUDDERDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class RudderDefineVar : DefineVarCommand {
    double rudder;
    SymbolTable symbolTable;
public:
    RudderDefineVar(double value, SymbolTable symbolTable1) {
        rudder = value;
        symbolTable = symbolTable1;
    }
    void setRudder(double newValue) { rudder = newValue; }
    void getValue() { return rudder; }
    int execute();
};

#endif //PROJECT_RUDDERDEFINEVAR_H
