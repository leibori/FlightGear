#ifndef PROJ1_DEFINEVARCOMMAND_H
#define PROJ1_DEFINEVARCOMMAND_H
#include "Command.h"
#include "string"
#include "SymbolTable.h"
#include "Expression.h"

class DefineVarCommand : public Command {
    string name;
    Expression* expression;
    SymbolTable* symbolTable;
public:
    DefineVarCommand(const string &name, Expression* expression1, SymbolTable *symbolTable) {
        this->name = name;
        this->expression = expression1;
        this->symbolTable = symbolTable;
    }
    double getValue() { return symbolTable->getValuesTable().at(name); }
    void setExpression(Expression* expression1) { this->expression = expression1; }
    void execute();
};

#endif //PROJ1_DEFINEVARCOMMAND_H
