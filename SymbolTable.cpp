#include "SymbolTable.h"

mutex recorder;

void SymbolTable::updateValuesTable(string key, double value) {
    recorder.lock();
    if (valuesTable.find(key) != valuesTable.end()) {
        valuesTable.find(key)->second = value;
    } else {
        valuesTable.insert(make_pair(key, value));
    }
    removeFromBindTable(key);
    recorder.unlock();
}

void SymbolTable::updateBindTable(string key, string value) {
    recorder.lock();
    if (bindTable.find(key) != bindTable.end()) {
        bindTable.find(key)->second = value;
    } else {
        bindTable.insert(make_pair(key, value));
    }
    removeFromValuesTable(key);
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

void SymbolTable::removeFromValuesTable(string key) {
    recorder.lock();
    if (valuesTable.find(key) != valuesTable.end()) {
        valuesTable.erase(key);
    }
    recorder.unlock();
}

void SymbolTable::removeFromBindTable(string key) {
    recorder.lock();
    if (bindTable.find(key) != bindTable.end()) {
        bindTable.erase(key);
    }
    recorder.unlock();
}