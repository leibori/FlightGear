//
// Created by ori on 12/16/18.
//
#include "Add.h"

Add::Add(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Add::calculate() {
    return left->calculate() + right->calculate();
}
