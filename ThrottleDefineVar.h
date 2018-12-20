#ifndef PROJECT_THROTTLEDEFINEVAR_H
#define PROJECT_THROTTLEDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class ThrottleDefineVar : Command {
    double throttle;
    SymbolTable symbolTable;
public:
    ThrottleDefineVar(double value, SymbolTable symbolTable1) {
        throttle = value;
        symbolTable = symbolTable1;
    }
    void setThrottle(double newValue) { throttle = newValue; }
    int execute();
};

#endif //PROJECT_THROTTLEDEFINEVAR_H
