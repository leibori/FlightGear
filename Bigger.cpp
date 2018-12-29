//
// Created by ori on 12/17/18.
//

#include "Bigger.h"

Bigger::Bigger(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Bigger::calculate() {
        return left->calculate() > right->calculate();
}