#ifndef PROJ1_SLEEPCOMMAND_H
#define PROJ1_SLEEPCOMMAND_H

#include <string>

#include "Expression.h"
#include "Command.h"
#include <chrono>
#include <unistd.h>
#include <thread>
#include <cmath>

using namespace std;

class SleepCommand : public Command {
    Expression* toSleep;
public:
    explicit SleepCommand(Expression *toSleep1) { this->toSleep = toSleep1; }
    void execute();
};

#endif //PROJ1_SLEEPCOMMAND_H
