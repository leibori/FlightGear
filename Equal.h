//
// Created by edan on 12/18/18.
//

#ifndef PROJ1_EQUAL_H
#define PROJ1_EQUAL_H
using namespace std;

#include <string>
#include "BinaryExpression.h"
class Equal : public BinaryExpression{
public:

    Equal(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJ1_EQUAL_H
