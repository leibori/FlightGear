#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

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

    virtual ~IfCommand();
};

#endif //PROJECT_IFCOMMAND_H
