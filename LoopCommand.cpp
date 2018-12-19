#include "LoopCommand.h"

int LoopCommand::execute() {
    while (condition) {
        for (auto& command : commands) {
            command.execute();
        }
    }
}