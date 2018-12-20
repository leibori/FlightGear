#ifndef PROJECT_PITCHDEFINEVAR_H
#define PROJECT_PITCHDEFINEVAR_H

#include <map>
#include <string>

#include "Command.h"
#include "SymbolTable.cpp"

using namespace std;

class PitchDefineVar : Command {
    double pitch;
    SymbolTable symbolTable;
public:
    PitchDefineVar(double value, SymbolTable symbolTable1) {
        pitch = value;
        symbolTable = symbolTable1;
    }
    void setPitch(double newValue) { pitch = newValue; }
    int execute();
};

#endif //PROJECT_PITCHDEFINEVAR_H
