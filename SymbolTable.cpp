#include "SymbolTable.h"

mutex recorder;

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
    if (bindTable.find(key) != bindTable.end()) {
        bindTable.find(key)->second = value;
    } else {
        bindTable.insert(make_pair(key, value));
    }
    if (valuesTable.find(key) != valuesTable.end()) {
        valuesTable.find(key)->second = bindValuesTable.find(value)->second;
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