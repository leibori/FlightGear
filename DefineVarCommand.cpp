#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    if (expression != nullptr) {
        symbolTable->updateValuesTable(name, expression->calculate());
    } else if (symbolTable->getBindValuesTable().find(bindPath) != symbolTable->getBindValuesTable().end()) {
        symbolTable->updateBindTable(name, bindPath);
    }
}