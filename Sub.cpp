//
// Created by edan on 12/16/18.
//
#include "Sub.h"

Sub::Sub(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Sub::calculate() {
    return left->calculate() - right->calculate();
}
