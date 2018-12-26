//
// Created by ori on 12/25/18.
//

#ifndef PROJ1_PRINTCOMMAND_H
#define PROJ1_PRINTCOMMAND_H

#include <string>

#include "Expression.h"
#include "Command.h"


using namespace std;

class PrintCommand : public Command {
    string toPrint;
public:
    explicit PrintCommand(Expression *ePrint) { this->toPrint = to_string(ePrint->calculate()); }

    explicit PrintCommand(string sPrint) { this->toPrint = sPrint; }


    void execute();
};

#endif //PROJ1_PRINTCOMMAND_H

