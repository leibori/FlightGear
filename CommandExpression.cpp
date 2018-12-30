//
// Created by ori on 12/21/18.
//

#include "CommandExpression.h"

CommandExpression::CommandExpression(DefineVarCommand *dvc) : dvc(dvc) {}

double CommandExpression::calculate() {
    return dvc->getValue();
}
