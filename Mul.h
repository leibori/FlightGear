//
// Created by edan on 12/16/18.
//

#ifndef PROJ1_MUL_H
#define PROJ1_MUL_H
using namespace std;
#include "BinaryExpression.h"
class Mul : public BinaryExpression{
public:

    Mul(Expression *left, Expression *right);

    double calculate() override;

};

#endif //PROJ1_MUL_H
