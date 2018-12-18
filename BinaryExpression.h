//
// Created by edan on 12/15/18.
//

#ifndef PROJ1_BINARYEXPRESSION_H
#define PROJ1_BINARYEXPRESSION_H

#include "Expression.h"

using namespace std;
class BinaryExpression : public Expression {
public:

    BinaryExpression(Expression *left, Expression *right);

    Expression *getLeft() const;

    Expression *getRight() const;

protected:
    Expression* left;
    Expression* right;

};

#endif //PROJ1_BINARYEXPRESSION_H
