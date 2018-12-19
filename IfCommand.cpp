#include "IfCommand.h"

int IfCommand::execute() {
    if (condition) {
        for (auto& command : commands) {
            command.execute();
        }
    }
}