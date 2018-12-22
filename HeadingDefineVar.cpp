#include "HeadingDefineVar.h"

void HeadingDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("heading");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("heading");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("heading");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = heading;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}