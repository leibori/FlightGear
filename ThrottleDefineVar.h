#ifndef PROJECT_THROTTLEDEFINEVAR_H
#define PROJECT_THROTTLEDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class ThrottleDefineVar : DefineVarCommand {
    double throttle;
    SymbolTable symbolTable;
public:
    ThrottleDefineVar(double value, SymbolTable symbolTable1) {
        throttle = value;
        symbolTable = symbolTable1;
    }
    void setThrottle(double newValue) { throttle = newValue; }
    void getValue() { return throttle; }
    int execute();
};

#endif //PROJECT_THROTTLEDEFINEVAR_H
