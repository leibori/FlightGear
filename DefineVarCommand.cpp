#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    if (expression != NULL) {
        double value = expression->calculate();
        if (symbolTable->getValuesTable().find(name) != symbolTable->getValuesTable().end()) {
            symbolTable->getValuesTable().find(name)->second = value;
        } else {
            symbolTable->getValuesTable().insert(make_pair(name, value));
        }
    }
}