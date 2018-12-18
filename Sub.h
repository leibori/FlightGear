//
// Created by edan on 12/16/18.
//

#ifndef PROJ1_SUB_H
#define PROJ1_SUB_H
using namespace std;
#include "BinaryExpression.h"
class Sub : public BinaryExpression{
public:

    Sub(Expression *left, Expression *right);

    double calculate() override;

};

#endif //PROJ1_SUB_H
