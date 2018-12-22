//
// Created by ori on 12/14/18.
//

#ifndef PROJ1_SHUNTINGYARD_H
#define PROJ1_SHUNTINGYARD_H

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <map>
#include "Expression.h"
#include "Command.h"

using namespace std;

class ExpressionGenerator {
public:
    Expression* generateExp(vector<string> orig, map<string,Command*> commandMap);
private:
    int priority(const string &s);
    bool isOperator(const string &s);
    deque<string> shuntingYardAlgoritem(vector<string> orig);
    bool isCommandName(const string &s);
    bool isNumber(const string &s);
    Expression* CommmandExpressGener( string str ,map<string,Command*> commandMap);
    bool isCommandVar(const string &s);



};

#endif //PROJ1_SHUNTINGYARD_H
