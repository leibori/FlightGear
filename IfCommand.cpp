//
// Created by edan on 12/21/18.
//

#include "IfCommand.h"

void IfCommand::execute() {
    if (condition->calculate()) {
        for (auto& command : commands) {
            command->execute();
        }
    }
}

void IfCommand::addCommand(Command* command) {
    commands.push_back(command);
}