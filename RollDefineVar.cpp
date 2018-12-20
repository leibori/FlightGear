#include "RollDefineVar.h"

int RollDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable.getInitializeTable().find("ailerone");
    std::map<string, double>::iterator it2 = symbolTable.getValuesTable().find("ailerone");
    std::map<string, Command*>::iterator it3 = symbolTable.getCommandTable().find("ailerone");
    if (it1 != symbolTable.getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable.getValuesTable().end()) {
        it2->second = roll;
    }
    if (it3 != symbolTable.getCommandTable().end()) {
        it3->second = this;
    }
}