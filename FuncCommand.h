#ifndef PROJECT_FUNCCOMMAND_H
#define PROJECT_FUNCCOMMAND_H

#include <vector>

#include "Command.h"

using namespace std;

class FuncCommand : public Command {
    vector<Command*> commands;
public:
    FuncCommand() {}
    void addCommand(Command* command);
    void execute();
};

#endif //PROJECT_FUNCCOMMAND_H
