//
// Created by edan on 12/21/18.
//

#ifndef PROJ1_IFCOMMAND_H
#define PROJ1_IFCOMMAND_H
#include <vector>

#include "Expression.h"
#include "Command.h"


using namespace std;

class IfCommand : public Command {
    Expression* condition;
    vector<Command*> commands;
public:
    IfCommand(Expression* newCondition) { condition = newCondition; }
    void addCommand(Command* command);
    void execute();
};

#endif //PROJ1_IFCOMMAND_H
