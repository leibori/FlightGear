//
// Created by edan on 12/20/18.
//

#ifndef PROJ1_UNARYEXPRESSION_H
#define PROJ1_UNARYEXPRESSION_H
#include "Expression.h"

using namespace std;
class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression *alone);

    Expression *getAlone() const;

    virtual ~UnaryExpression();

public:




protected:
    Expression* alone;

};
#endif //PROJ1_UNARYEXPRESSION_H
