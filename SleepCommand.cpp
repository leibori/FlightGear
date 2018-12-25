//
// Created by ori on 12/26/18.
//

#include <chrono>
#include "SleepCommand.h"
#include <unistd.h>
void SleepCommand::execute() {
    usleep(toSleep->calculate());
}