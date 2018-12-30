//
// Created by ori on 12/16/18.
//

#ifndef PROJ1_ADD_H
#define PROJ1_ADD_H
using namespace std;
#include "BinaryExpression.h"
class Add : public BinaryExpression{
public:

    Add(Expression *left, Expression *right);

    double calculate() override;

};

#endif //PROJ1_ADD_H
