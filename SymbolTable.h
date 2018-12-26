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
public:
    SymbolTable() {
        bindValuesTable["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
        bindValuesTable.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate",0));
        bindValuesTable.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
        bindValuesTable.insert(pair<string,double>("/controls/flight/aileron",0));
        bindValuesTable.insert(pair<string,double>("/controls/flight/elevator",0));
        bindValuesTable.insert(pair<string,double>("/controls/flight/rudder",0));
        bindValuesTable.insert(pair<string,double>("/controls/flight/flaps",0));
        bindValuesTable.insert(pair<string,double>("/controls/engines/engine/throttle",0));
        bindValuesTable.insert(pair<string,double>("/engines/engine/rpm",0));
    }

    map<string, double> &getValuesTable() { return valuesTable; }

    map<string, string> &getBindTable() { return bindTable; }

    map<string, double> &getBindValuesTable() { return bindValuesTable; }

    void updateValuesTable(string key, double value);

    void updateBindTable(string key, string value);

    void updateBindValuesTable(string key, double value);
};

#endif //PROJECT_SYMBOLTABLE_H
