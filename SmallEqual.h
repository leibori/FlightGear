//
// Created by ori on 12/29/18.
//

#ifndef PROJECT_SMALLEQUAL_H
#define PROJECT_SMALLEQUAL_H
using namespace std;

#include <string>
#include "BinaryExpression.h"
class SmallEqual : public BinaryExpression{
public:

    SmallEqual(Expression *left, Expression *right);

    double calculate() override;

};
#endif //PROJECT_SMALLEQUAL_H
