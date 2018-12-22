#include "AltDefineVar.h"

void AltDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("alt");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("alt");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("alt");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = alt;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}