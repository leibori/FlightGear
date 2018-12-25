//
// Created by edan on 12/21/18.
//

#ifndef PROJ1_LOOPCOMMAND_H
#define PROJ1_LOOPCOMMAND_H
#include <vector>

#include "Command.h"
#include "SymbolTable.h"
#include "Expression.h"

using namespace std;

class LoopCommand : public Command {
    Expression* condition;

    vector<Command*> commands;
public:
    LoopCommand(Expression* newCondition) { condition = newCondition; }
    void addCommand(Command* command);
    void execute();
};

#endif //PROJ1_LOOPCOMMAND_H
