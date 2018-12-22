#include "BreaksDefineVar.h"

void BreaksDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("breaks");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("breaks");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("breaks");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = breaks;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}