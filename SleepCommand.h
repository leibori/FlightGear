//
// Created by ori on 12/26/18.
//

#ifndef PROJ1_SLEEPCOMMAND_H
#define PROJ1_SLEEPCOMMAND_H

#include <string>

#include "Expression.h"
#include "Command.h"


using namespace std;

class SleepCommand : public Command {
    Expression* toSleep;
public:
    explicit SleepCommand(Expression *ePrint) {
        this->toSleep = toSleep;
    }



    void execute();
};

#endif //PROJ1_SLEEPCOMMAND_H
