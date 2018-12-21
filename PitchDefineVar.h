#ifndef PROJECT_PITCHDEFINEVAR_H
#define PROJECT_PITCHDEFINEVAR_H

#include <map>
#include <string>

#include "DefineVarCommand.h"
#include "SymbolTable.h"

using namespace std;

class PitchDefineVar : DefineVarCommand {
    double pitch;
    SymbolTable symbolTable;
public:
    PitchDefineVar(double value, SymbolTable symbolTable1) {
        pitch = value;
        symbolTable = symbolTable1;
    }
    void setPitch(double newValue) { pitch = newValue; }
    void getValue() { return pitch; }
    int execute();
};

#endif //PROJECT_PITCHDEFINEVAR_H
