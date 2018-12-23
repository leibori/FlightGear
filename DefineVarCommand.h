#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include "string"
#include "SymbolTable.h"

class DefineVarCommand : public Command {
    string name;
    double value;
    SymbolTable* symbolTable;
public:
    DefineVarCommand(const string &name, double value, SymbolTable *symbolTable) {
        this->name = name;
        this->value = value;
        this->symbolTable = symbolTable;
    }
    double getValue() { return value; }
    void setValue(double value) { this->value = value; }
    void execute();
};

#endif //PROJECT_DEFINEVARCOMMAND_H
