#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <map>
#include <string>
#include "mutex"

#include "Command.h"

using namespace std;

class SymbolTable {
    map<string,double> valuesTable;
    map<string,string> bindTable;
    map<string,double> bindValuesTable;
    int simulatorSocket = -1;
public:
    SymbolTable();

    map<string, double> &getValuesTable() { return valuesTable; }

    map<string, string> &getBindTable() { return bindTable; }

    map<string, double> &getBindValuesTable() { return bindValuesTable; }

    int getSimulatorSocket() { return  simulatorSocket; }

    void setSimulatorSocket(int socket) { simulatorSocket = socket; }

    void updateValuesTable(string key, double value);

    void updateBindTable(string key, string value);

    void updateBindValuesTable(string key, double value);
};

#endif //PROJECT_SYMBOLTABLE_H
