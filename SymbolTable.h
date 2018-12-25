//
// Created by edan on 12/21/18.
//

#ifndef PROJ1_SYMBOLTABLE_H
#define PROJ1_SYMBOLTABLE_H

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

#endif //PROJ1_SYMBOLTABLE_H
