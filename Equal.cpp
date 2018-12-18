//
// Created by edan on 12/18/18.
//

#include "Equal.h"
Equal::Equal(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Equal::calculate() {
    return left->calculate() == right->calculate();
}