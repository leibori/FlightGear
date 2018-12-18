//
// Created by edan on 12/17/18.
//

#include "Smaller.h"
Smaller::Smaller(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Smaller::calculate() {
    return left->calculate() < right->calculate();
}