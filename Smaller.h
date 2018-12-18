//
// Created by edan on 12/17/18.
//

#ifndef PROJ1_SMALLER_H
#define PROJ1_SMALLER_H
using namespace std;

#include <string>
#include "BinaryExpression.h"
class Smaller : public BinaryExpression{
public:

    Smaller(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJ1_SMALLER_H
