#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    if (symbolTable->getValuesTable().find(name) != symbolTable->getValuesTable().end()) {
        symbolTable->getValuesTable().find(name)->second = value;
    } else {
        symbolTable->getValuesTable().insert(make_pair(name, value));
    }
    if (symbolTable->getCommandTable().find(name) != symbolTable->getCommandTable().end()) {
        symbolTable->getCommandTable().find(name)->second = this;
    } else {
        symbolTable->getCommandTable().insert(make_pair(name, this));
    }
}