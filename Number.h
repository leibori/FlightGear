//
// Created by edan on 12/15/18.
//

#ifndef PROJ1_NUMBER_H
#define PROJ1_NUMBER_H

#include "Expression.h"

using namespace std;

class Number: public Expression{
    double value;
public:
    Number(double value);

    double getValue() const;

    double calculate() override;

};
#endif //PROJ1_NUMBER_H
