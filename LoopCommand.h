#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H

#include <list>

#include "Command.h"

using namespace std;

class LoopCommand : Command {
    bool condition;
    list<Command> commands;
public:
    LoopCommand(bool newCondition, list<Command> newCommands) {
        condition = newCondition;
        commands = newCommands;
    }
    int execute();
};


#endif //PROJECT_LOOPCOMMAND_H
