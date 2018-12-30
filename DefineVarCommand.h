#ifndef PROJ1_DEFINEVARCOMMAND_H
#define PROJ1_DEFINEVARCOMMAND_H
#include "Command.h"
#include "string"
#include "SymbolTable.h"
#include "Expression.h"

class DefineVarCommand : public Command {
    string name;
    string bindPath;
    Expression* expression = nullptr;
    SymbolTable* symbolTable;
public:
    DefineVarCommand(const string &name, Expression* expression1, SymbolTable *symbolTable) {
        this->name = name;
        this->expression = expression1;
        this->symbolTable = symbolTable;
    }

    virtual ~DefineVarCommand();

    DefineVarCommand(string bindPath1, const string &name, SymbolTable *symbolTable1) {
        this->name = name;
        this->bindPath = bindPath1;
        this->symbolTable = symbolTable1;
    }
    double getValue() { return symbolTable->getValuesTable().at(name); }
    void setExpression(Expression* expression1) { this->expression = expression1; }
    void setBindPath(string bindPath1) {
        this->bindPath = bindPath1;
        this->expression = nullptr;
    }
    void execute();
};

#endif //PROJ1_DEFINEVARCOMMAND_H
