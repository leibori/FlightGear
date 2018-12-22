#include "ElevatorDefineVar.h"

void ElevatorDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("elevator");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("elevator");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("elevator");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = elevator;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = (Command*) this;
    }
}