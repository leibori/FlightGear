//
// Created by edan on 12/15/18.
//
#include "BinaryExpression.h"
using namespace std;

BinaryExpression::BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}

Expression *BinaryExpression::getLeft() const {
 return left;
}

Expression *BinaryExpression::getRight() const {
 return right;
}

