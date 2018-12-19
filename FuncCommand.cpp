#include "FuncCommand.h"

int FuncCommand::execute() {
    for (auto& command : commands) {
        command.execute();
    }
}