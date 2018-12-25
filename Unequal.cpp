//
// Created by ori on 12/24/18.
//

#include "Unequal.h"
Unequal::Unequal(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Unequal::calculate() {
    return left->calculate() != right->calculate();
}