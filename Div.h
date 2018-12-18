//
// Created by edan on 12/16/18.
//

#ifndef PROJ1_DIV_H
#define PROJ1_DIV_H
using namespace std;
#include "BinaryExpression.h"
class Div : public BinaryExpression{
public:
    Div(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJ1_DIV_H
