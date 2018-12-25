#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    if (expression != nullptr) {
        if (symbolTable->getValuesTable().find(name) != symbolTable->getValuesTable().end()) {
            symbolTable->getValuesTable().find(name)->second = expression->calculate();
        } else {
            symbolTable->getValuesTable().insert(make_pair(name, expression->calculate()));
        }
        if (symbolTable->getBindTable().find(name) != symbolTable->getBindTable().end()) {
            symbolTable->getBindTable().erase(name);
        }
    } else if (symbolTable->getBindValuesTable().find(bindPath) != symbolTable->getBindValuesTable().end()) {
        if (symbolTable->getBindTable().find(name) != symbolTable->getBindTable().end()) {
            symbolTable->getBindTable().find(name)->second = bindPath;
        } else {
            symbolTable->getBindTable().insert(make_pair(name, bindPath));
        }
        if (symbolTable->getValuesTable().find(name) != symbolTable->getValuesTable().end()) {
            symbolTable->getValuesTable().erase(name);
        }
    }
}