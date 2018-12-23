#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <map>
#include <string>

#include "Command.h"

using namespace std;

class SymbolTable {
    map<string,Command*> commandTable;
    map<string,double> valuesTable;
    map<string,double> pathValuesTable;
public:
    SymbolTable() {}

    map<string, Command *> &getCommandTable() { return commandTable; }

    map<string, double> &getValuesTable() { return valuesTable; }
};

#endif //PROJECT_SYMBOLTABLE_H
