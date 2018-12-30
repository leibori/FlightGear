#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H

#include <vector>

#include "Command.h"
#include "Expression.h"

using namespace std;

class LoopCommand : public Command {
    Expression* condition;
    vector<Command*> commands;
public:
    LoopCommand(Expression* newCondition) { condition = newCondition; }
    void addCommand(Command* command);
    void execute();

    virtual ~LoopCommand();
};



#endif //PROJECT_LOOPCOMMAND_H
