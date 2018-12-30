//
// Created by ori on 12/20/18.
//

#include "UnaryExpression.h"
using namespace std;

UnaryExpression::UnaryExpression(Expression *alone) : alone(alone) {}

Expression *UnaryExpression::getAlone() const {
    return alone;
}

UnaryExpression::~UnaryExpression() {
delete alone;
}
