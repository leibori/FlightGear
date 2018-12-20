//
// Created by ori on 12/14/18.
//

#ifndef PROJ1_SHUNTINGYARD_H
#define PROJ1_SHUNTINGYARD_H

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include "Expression.h"
using namespace std;

class ExpressionGenerator {
public:
    Expression* generateExp(vector<string> orig);
private:
    vector<string>splitIt(string str, string token);
    int priority(const string &s);
    bool isOperator(const string &s);
    deque<string> shuntingYardAlgoritem(vector<string> orig);
};

#endif //PROJ1_SHUNTINGYARD_H
