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
    for (map<string,string>::const_iterator it = bindTable.begin(); it != bindTable.end(); ++it) {
        if (it->second == key) {
            bindValuesTable[it->first] = value;
            if (connectCommand != NULL) {
                connectCommand->updateSimulator(it->first, value);
            }
            break;
        }
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
        if (bindValuesTable.find(key) != bindValuesTable.end()) {
            bindValuesTable.find(key)->second = valuesTable.find(value)->second;
        } else {
            bindValuesTable.insert(make_pair(key, valuesTable.find(value)->second));
        }
        if (connectCommand != NULL) {
            connectCommand->updateSimulator(key, valuesTable.find(value)->second);
        }
    } else {
        if (bindValuesTable.find(key) != bindValuesTable.end()) {
            valuesTable.insert(make_pair(value, bindValuesTable.find(key)->second));
            if (connectCommand != NULL) {
                connectCommand->updateSimulator(key, bindValuesTable.find(key)->second);
            }
        } else {
            valuesTable.insert(make_pair(value, 0));
            bindValuesTable.insert(make_pair(key, 0));
            if (connectCommand != NULL) {
                connectCommand->updateSimulator(key, 0);
            }
        }
    }
    recorder.unlock();
}

void SymbolTable::updateMultipleBindValues(vector<string> values) {
    recorder.lock();
    bindValuesTable.at("/instrumentation/airspeed-indicator/indicated-speed-kt") =  strtod(values[0].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/altimeter/indicated-altitude-ft") =  strtod(values[1].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/altimeter/pressure-alt-ft") = strtod(values[2].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/attitude-indicator/indicated-pitch-deg") = strtod(values[3].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/attitude-indicator/indicated-roll-deg") = strtod(values[4].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/attitude-indicator/internal-pitch-deg") = strtod(values[5].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/attitude-indicator/internal-roll-deg") = strtod(values[6].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/encoder/indicated-altitude-ft") = strtod(values[7].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/encoder/pressure-alt-ft") = strtod(values[8].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/gps/indicated-altitude-ft") = strtod(values[9].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/gps/indicated-ground-speed-kt") = strtod(values[10].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/gps/indicated-vertical-speed") = strtod(values[11].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/heading-indicator/indicated-heading-deg") = strtod(values[12].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/magnetic-compass/indicated-heading-deg") = strtod(values[13].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/slip-skid-ball/indicated-slip-skid") = strtod(values[14].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/turn-indicator/indicated-turn-rate") = strtod(values[15].c_str(), nullptr);
    bindValuesTable.at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm") = strtod(values[16].c_str(), nullptr);
    bindValuesTable.at("/controls/flight/aileron") = strtod(values[17].c_str(), nullptr);
    bindValuesTable.at("/controls/flight/elevator") = strtod(values[18].c_str(), nullptr);
    bindValuesTable.at("/controls/flight/rudder") = strtod(values[19].c_str(), nullptr);
    bindValuesTable.at("/controls/flight/flaps") = strtod(values[20].c_str(), nullptr);
    bindValuesTable.at("/controls/engines/engine/throttle") = strtod(values[21].c_str(), nullptr);
    bindValuesTable.at("/engines/engine/rpm") = strtod(values[22].c_str(), nullptr);
    for (map<string,string>::const_iterator it = bindTable.begin(); it != bindTable.end(); ++it) {
        if (valuesTable.find(it->second) != valuesTable.end()) {
            valuesTable.at(it->second) = bindValuesTable.at(it->first);
        }
    }
    recorder.unlock();
}