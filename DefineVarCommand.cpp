#include "DefineVarCommand.h"

void DefineVarCommand::execute() {
    if (expression != nullptr) {
        symbolTable->updateValuesTable(name, expression->calculate());
    } else {
        symbolTable->updateBindTable(bindPath, name);
    }
}

DefineVarCommand::~DefineVarCommand() {
if (expression!= nullptr){
    delete expression;
}
}
