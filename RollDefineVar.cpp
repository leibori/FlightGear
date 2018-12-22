#include "RollDefineVar.h"

void RollDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("roll");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("roll");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("roll");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = roll;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}