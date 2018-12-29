//
// Created by edan on 12/29/18.
//

#include "SmallEqual.h"


SmallEqual::SmallEqual(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double SmallEqual::calculate() {
    return left->calculate() <= right->calculate();
}