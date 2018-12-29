//
// Created by ori on 12/29/18.
//

#ifndef PROJECT_BIGEQUAL_H
#define PROJECT_BIGEQUAL_H
using namespace std;

#include <string>
#include "BinaryExpression.h"
class BigEqual : public BinaryExpression{
public:

    BigEqual(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJECT_BIGEQUAL_H
