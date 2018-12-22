#include "AirspeedDefineVar.h"

void AirspeedDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("airspeed");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("airspeed");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("airspeed");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = airspeed;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}