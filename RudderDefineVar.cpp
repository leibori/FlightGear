#include "RudderDefineVar.h"

void RudderDefineVar::execute() {
    std::map<string, bool>::iterator it1 = symbolTable->getInitializeTable().find("rudder");
    std::map<string, double>::iterator it2 = symbolTable->getValuesTable().find("rudder");
    std::map<string, Command*>::iterator it3 = symbolTable->getCommandTable().find("rudder");
    if (it1 != symbolTable->getInitializeTable().end()) {
        it1->second = true;
    }
    if (it2 != symbolTable->getValuesTable().end()) {
        it2->second = rudder;
    }
    if (it3 != symbolTable->getCommandTable().end()) {
        it3->second = this;
    }
}