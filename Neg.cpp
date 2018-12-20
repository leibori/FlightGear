//
// Created by ori on 12/20/18.
//

#include "Neg.h"

Neg::Neg(Expression *alone) : UnaryExpression(alone) {}

double Neg::calculate() {
    return -1 * alone->calculate();
}
