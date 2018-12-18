//
// Created by edan on 12/16/18.
//

#include "Mul.h"

Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Mul::calculate() {
    return left->calculate() * right->calculate();
}