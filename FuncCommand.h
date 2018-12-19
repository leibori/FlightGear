#ifndef PROJECT_FUNCCOMMAND_H
#define PROJECT_FUNCCOMMAND_H

#include <list>

#include "Command.h"

using namespace std;

class FuncCommand : Command {
    list<Command> commands;
public:
    FuncCommand(list<Command> newCommands) {
        commands = newCommands;
    }
    int execute();
};

#endif //PROJECT_FUNCCOMMAND_H
