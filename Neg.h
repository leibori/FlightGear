//
// Created by ori on 12/20/18.
//

#ifndef PROJ1_NEG_H
#define PROJ1_NEG_H
using namespace std;

#include <string>
#include "UnaryExpression.h"
class Neg : public UnaryExpression{
public:


    Neg(Expression *alone);

    double calculate() override;

};
#endif //PROJ1_NEG_H
