//
// Created by ori on 12/29/18.
//

#include "BigEqual.h"

BigEqual::BigEqual(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double BigEqual::calculate() {
    return left->calculate() >= right->calculate();
}