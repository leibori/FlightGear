//
// Created by edan on 12/21/18.
//

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