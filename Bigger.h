//
// Created by edan on 12/17/18.
//

#ifndef PROJ1_BOOLEANOPERATOR_H
#define PROJ1_BOOLEANOPERATOR_H
using namespace std;

#include <string>
#include "BinaryExpression.h"
class Bigger : public BinaryExpression{
public:

    Bigger(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJ1_BOOLEANOPERATOR_H
