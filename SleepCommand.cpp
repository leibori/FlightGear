#include "SleepCommand.h"

void SleepCommand::execute() {
    long int milliseconds = abs((long int) toSleep->calculate());
    this_thread::__sleep_for(chrono::seconds(milliseconds / 1000), chrono::nanoseconds(0));
}