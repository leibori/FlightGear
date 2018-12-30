//
// Created by ori on 12/21/18.
//

#ifndef PROJ1_COMMANDEXPRESSION_H
#define PROJ1_COMMANDEXPRESSION_H
#include "Expression.h"
#include "DefineVarCommand.h"
using namespace std;
class CommandExpression : public Expression {
    DefineVarCommand* dvc;
public:
    CommandExpression(DefineVarCommand *dvc);

    double calculate() override;
};

#endif //PROJ1_COMMANDEXPRESSION_H
