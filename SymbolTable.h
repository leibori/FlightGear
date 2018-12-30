#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <map>
#include <string>
#include <vector>
#include <mutex>

#include "ConnectCommand.h"

using namespace std;

class SymbolTable {
    map<string,double> valuesTable;
    map<string,string> bindTable;
    map<string,double> bindValuesTable;
    ConnectCommand *connectCommand = NULL;
public:
    bool isServerOpen = false;

    SymbolTable();

    map<string, double> &getValuesTable() { return valuesTable; }

    void setConnectCommand(ConnectCommand *connectCommand1) { connectCommand = connectCommand1; }

    void updateValuesTable(string key, double value);

    void updateBindTable(string key, string value);

    virtual ~SymbolTable();

    void updateMultipleBindValues(vector<string> values);
};

#endif //PROJECT_SYMBOLTABLE_H
