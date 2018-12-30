#include "LoopCommand.h"

void LoopCommand::execute() {
    while (condition->calculate()) {
        for (auto& command : commands) {
            command->execute();
        }
    }
}

void LoopCommand::addCommand(Command* command) {
    commands.push_back(command);
}

LoopCommand::~LoopCommand() {
    for (vector<Command*>::iterator it = commands.begin(); it!= commands.end();it++){
        delete *it;
    }
}
