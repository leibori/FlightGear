#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include <list>

#include "Command.h"

using namespace std;

class IfCommand : Command {
    bool condition;
    list<Command> commands;
public:
    IfCommand(bool newCondition, list<Command> newCommands) {
        condition = newCondition;
        commands = newCommands;
    }
    int execute();
};

#endif //PROJECT_IFCOMMAND_H
