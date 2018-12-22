#include "PitchDefineVar.h"

void PitchDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("pitch");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("pitch");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("pitch");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = pitch;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}