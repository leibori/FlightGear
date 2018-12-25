//
// Created by ori on 12/24/18.
//

#ifndef PROJ1_UNEQUAL_H
#define PROJ1_UNEQUAL_H
using namespace std;

#include <string>
#include "BinaryExpression.h"
class Unequal : public BinaryExpression{
public:

    Unequal(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJ1_UNEQUAL_H
