#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <map>
#include <string>

#include "Command.h"
#include "FunctionsBundle.cpp"

using namespace std;

class SymbolTable {
    map<string,Command*> commandTable;
    map<string,double> valuesTable;
    map<string,bool> initializeTable;
public:
    SymbolTable() {
        commandTable["openDataServer"] = NULL;
        commandTable["connect"] = NULL;
        commandTable["aileron"] = NULL;
        commandTable["airspeed"] = NULL;
        commandTable["alt"] = NULL;
        commandTable["breaks"] = NULL;
        commandTable["elevator"] = NULL;
        commandTable["heading"] = NULL;
        commandTable["pitch"] = NULL;
        commandTable["roll"] = NULL;
        commandTable["rudder"] = NULL;
        commandTable["throttle"] = NULL;
        valuesTable["aileron"] = 0;
        valuesTable["airspeed"] = 0;
        valuesTable["alt"] = 0;
        valuesTable["breaks"] = 0;
        valuesTable["elevator"] = 0;
        valuesTable["heading"] = 0;
        valuesTable["pitch"] = 0;
        valuesTable["roll"] = 0;
        valuesTable["rudder"] = 0;
        valuesTable["throttle"] = 0;
        initializeTable["aileron"] = false;
        initializeTable["airspeed"] = false;
        initializeTable["alt"] = false;
        initializeTable["breaks"] = false;
        initializeTable["elevator"] = false;
        initializeTable["heading"] = false;
        initializeTable["pitch"] = false;
        initializeTable["roll"] = false;
        initializeTable["rudder"] = false;
        initializeTable["throttle"] = false;
    }

    map<string, Command *> &getCommandTable() { return commandTable; }

    map<string, double> &getValuesTable() { return valuesTable; }

    map<string, bool> &getInitializeTable() { return initializeTable; }
};

#endif //PROJECT_SYMBOLTABLE_H
