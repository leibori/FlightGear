#ifndef PROJECT_THROTTLEDEFINEVAR_H
#define PROJECT_THROTTLEDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class ThrottleDefineVar : public DefineVarCommand {
    double throttle;
    SymbolTable* symbolTable;
public:
    ThrottleDefineVar(double value, SymbolTable* symbolTable1) {
        throttle = value;
        symbolTable = symbolTable1;
    }
    void setThrottle(double newValue) { throttle = newValue; }
    double getValue() { return throttle; }
    void execute();
};

#endif //PROJECT_THROTTLEDEFINEVAR_H
