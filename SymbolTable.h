#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <map>
#include <string>
#include <vector>
#include <mutex>
//#include "mutex"

#include "ConnectCommand.h"

using namespace std;

class SymbolTable {
    map<string,double> valuesTable;
    map<string,string> bindTable;
    map<string,double> bindValuesTable;
    ConnectCommand *connectCommand = NULL;
public:
    SymbolTable();

    map<string, double> &getValuesTable() { return valuesTable; }

    map<string, string> &getBindTable() { return bindTable; }

    map<string, double> &getBindValuesTable() { return bindValuesTable; }

    void setConnectCommand(ConnectCommand *connectCommand1) { connectCommand = connectCommand1; }

    void updateValuesTable(string key, double value);

    void updateBindTable(string key, string value);

    void updateBindValuesTable(string key, double value);

    void updateMultipleBindValues(vector<string> values);
};

#endif //PROJECT_SYMBOLTABLE_H
