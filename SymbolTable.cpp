#include "SymbolTable.h"

mutex recorder;

SymbolTable::SymbolTable() {
    bindTable.insert(pair<string,string>("/instrumentation/airspeed-indicator/indicated-speed-kt", ""));
    bindTable.insert(pair<string,string>("/instrumentation/altimeter/indicated-altitude-ft",""));
    bindTable.insert(pair<string,string>("/instrumentation/altimeter/pressure-alt-ft",""));
    bindTable.insert(pair<string,string>("/instrumentation/attitude-indicator/indicated-pitch-deg",""));
    bindTable.insert(pair<string,string>("/instrumentation/attitude-indicator/indicated-roll-deg",""));
    bindTable.insert(pair<string,string>("/instrumentation/attitude-indicator/internal-pitch-deg",""));
    bindTable.insert(pair<string,string>("/instrumentation/attitude-indicator/internal-roll-deg",""));
    bindTable.insert(pair<string,string>("/instrumentation/encoder/indicated-altitude-ft",""));
    bindTable.insert(pair<string,string>("/instrumentation/encoder/pressure-alt-ft",""));
    bindTable.insert(pair<string,string>("/instrumentation/gps/indicated-altitude-ft",""));
    bindTable.insert(pair<string,string>("/instrumentation/gps/indicated-ground-speed-kt",""));
    bindTable.insert(pair<string,string>("/instrumentation/gps/indicated-vertical-speed",""));
    bindTable.insert(pair<string,string>("/instrumentation/heading-indicator/indicated-heading-deg",""));
    bindTable.insert(pair<string,string>("/instrumentation/magnetic-compass/indicated-heading-deg",""));
    bindTable.insert(pair<string,string>("/instrumentation/slip-skid-ball/indicated-slip-skid",""));
    bindTable.insert(pair<string,string>("/instrumentation/turn-indicator/indicated-turn-rate",""));
    bindTable.insert(pair<string,string>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", ""));
    bindTable.insert(pair<string,string>("/controls/flight/aileron",""));
    bindTable.insert(pair<string,string>("/controls/flight/elevator",""));
    bindTable.insert(pair<string,string>("/controls/flight/rudder",""));
    bindTable.insert(pair<string,string>("/controls/flight/flaps",""));
    bindTable.insert(pair<string,string>("/controls/engines/engine/throttle",""));
    bindTable.insert(pair<string,string>("/engines/engine/rpm",""));
    bindValuesTable.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
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

void SymbolTable::updateValuesTable(string key, double value) {
    recorder.lock();
    if (valuesTable.find(key) != valuesTable.end()) {
        valuesTable.find(key)->second = value;
    } else {
        valuesTable.insert(make_pair(key, value));
    }
    if (bindTable.find(key) != bindTable.end()) {
        bindValuesTable.find(bindTable.find(key)->second)->second = value;
    }
    recorder.unlock();
}

void SymbolTable::updateBindTable(string key, string value) {
    recorder.lock();
    for (map<string,string>::const_iterator it = bindTable.begin(); it != bindTable.end(); ++it) {
        if (it->second == value) {
            bindTable[it->first] = "";
            break;
        }
    }
    if (bindTable.find(key) != bindTable.end()) {
        bindTable.find(key)->second = value;
    } else {
        bindTable.insert(make_pair(key, value));
    }
    if (valuesTable.find(value) != valuesTable.end()) {
        valuesTable.find(value)->second = bindValuesTable.find(key)->second;
    }
    recorder.unlock();
}

void SymbolTable::updateBindValuesTable(string key, double value) {
    recorder.lock();
    if (bindValuesTable.find(key) != bindValuesTable.end()) {
        bindValuesTable.find(key)->second = value;
    } else {
        bindValuesTable.insert(make_pair(key, value));
    }
    recorder.unlock();
}