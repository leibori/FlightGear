//
// Created by ori on 12/14/18.
//
#include "SymbolTable.h"
#include "ExpressionGenerator.h"
#include "BigEqual.h"
#include "SmallEqual.h"
#include "Number.h"
#include "Add.h"
#include "Sub.h"
#include "Div.h"
#include "Mul.h"
#include "Bigger.h"
#include "Smaller.h"
#include "Equal.h"
#include "Unequal.h"
#include "CommandExpression.h"
#include "Neg.h"
#include "Var.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
#include <sstream>
#include <deque>
#include <string>
#include <algorithm>
#include <map>


#define PLUS_IF if (temp == "+")
#define MINUS_IF if (temp == "-")
#define MULTIPLY_IF if (temp == "*")
#define DEVISION_IF if (temp == "/")
#define BIGGER_IF if (temp == ">")
#define SMALLER_IF if (temp == "<")
#define EQUAL_IF if (temp == "==")
#define UNEQUAL_IF if (temp == "!=")
#define BIGEQUAL_IF if (temp == ">=")
#define SMALLEQUAL_IF if (temp == "<=")
#define PLUS_SIGN "+"
#define MINUS_SIGN "-"
#define MULTIPLY_SIGN "*"
#define DEVISION_SIGN "/"
#define BIGGER_SIGN ">"
#define SMALLER_SIGN  "<"
#define EQUAL_SIGN "=="
#define NEGATIVE_SIGN "$"
#define BIGEQUAL ">="
#define SMALLEQUAL "<="


using namespace std;

/*
 * function name: isOperator
 * The function check if the string it get is operator
 * */
bool ExpressionGenerator::isOperator(const string &s) {
    return (s == PLUS_SIGN || s == MINUS_SIGN || s == MULTIPLY_SIGN || s == DEVISION_SIGN
            || s == BIGGER_SIGN || s == SMALLER_SIGN || s == EQUAL_SIGN || s == NEGATIVE_SIGN || s == BIGEQUAL ||
            s == SMALLEQUAL);
}

/*
 * function name: priority
 * The function put priority to operators by logical order
 */
int ExpressionGenerator::priority(const string &s) {
    int prio;
    if (s == NEGATIVE_SIGN) {
        prio = 3;
        return prio;
    } else if (s == MULTIPLY_SIGN || s == DEVISION_SIGN) {
        prio = 2;
        return prio;
    } else if (s == PLUS_SIGN || s == MINUS_SIGN) {
        prio = 1;
        return prio;
    } else {
        prio = 0;
        return prio;
    }
}

/*
 * function name: isCommandName
 * The function check if the string is command
 * */
bool ExpressionGenerator::isCommandName(const string &s) {
    return !(isOperator(s) || isNumber(s) || s == "(" || s == ")" || s == "=");
}

/*
 * function name: isNumber
 * The function check if the string it get is number
 * */
bool ExpressionGenerator::isNumber(const string &s) {
    int i = 0;
    while (i != s.size()) {
        if (isdigit(s[i])) {
            i++;
        } else {
            return false;
        }
    }
    return true;
}

/*
 * function name: shuntingYardAlgoritem
 * The function get infix order defenition and make it postfix
 */
deque<string> ExpressionGenerator::shuntingYardAlgoritem(vector<string> orig) {
    //put all part of expression in here
    vector<string> parts = orig;
    deque<string> outQueue;
    stack<string> s; //main stack

    //operator: +, -, *, /, (), >, <, ==,!=,<=, >=
    //operands: 1234567890
    for (int i = 0; i < parts.size(); i++) {
        //not operator or ( )
        if (!isOperator(parts[i]) && (parts[i] != "(" && parts[i] != ")")) {
            outQueue.push_front(parts[i]);
        }
        if (parts[i] == "(") {
            s.push(parts[i]);
        }
        if (parts[i] == ")") {
            while (!s.empty() && s.top() != "(") {
                outQueue.push_front(s.top());
                s.pop();
            }
            s.pop();
        }
        if (isOperator(parts[i])) {
            if (parts[i] == MINUS_SIGN) {
                if (i == 0) { parts[i] = NEGATIVE_SIGN; }
                if (isOperator(parts[i - 1]) || parts[i - 1] == "(") {
                    parts[i] = NEGATIVE_SIGN;
                }
            }
            while (!s.empty() && priority(s.top()) >= priority(parts[i])) {
                outQueue.push_front(s.top());
                s.pop();
            }
            s.push(parts[i]);
        }
    }
//pop any remaining operators from the stack and insert to outputlist
    while (!s.empty()) {
        outQueue.push_front(s.top());
        s.pop();
    }
    return outQueue;
}

/*
 * function name: generateExp
 * The function make exppression from the vector of string and take value from symbilTable
 **/
Expression *ExpressionGenerator::generateExp(vector<string> orig, SymbolTable *sym) {
    deque<string> postFix = shuntingYardAlgoritem(orig);
    string fromQu;
    Expression *numExp;
    stack<Expression *> ouput;
    while (!postFix.empty()) {
        string temp = postFix.back();
        if (!isOperator(temp)) {
            if (isNumber(temp)) {
                numExp = new Number(stod(temp));
            }
            if (isCommandName(temp)) {
                if (sym->getValuesTable().count(temp)) {
                    numExp = new Var(temp, sym);
                } else {
                    throw "not found";
                }

            }
            ouput.push(numExp);
            postFix.pop_back();
        } else {
            //making expresion by sign
            if (temp == NEGATIVE_SIGN) {
                Expression *alone = ouput.top();
                ouput.pop();
                numExp = new Neg(alone);
                ouput.push(numExp);
            } else {
                Expression *right = ouput.top();
                ouput.pop();
                Expression *left = ouput.top();
                ouput.pop();
                PLUS_IF {
                    numExp = new Add(left, right);
                    ouput.push(numExp);
                } else MINUS_IF {
                    numExp = new Sub(left, right);
                    ouput.push(numExp);
                } else MULTIPLY_IF {
                    numExp = new Mul(left, right);
                    ouput.push(numExp);
                } else DEVISION_IF {
                    numExp = new Div(left, right);
                    ouput.push(numExp);
                } else BIGGER_IF {
                    numExp = new Bigger(left, right);
                    ouput.push(numExp);
                } else SMALLER_IF {
                    numExp = new Smaller(left, right);
                    ouput.push(numExp);
                } else EQUAL_IF {
                    numExp = new Equal(left, right);
                    ouput.push(numExp);
                } else UNEQUAL_IF {
                    numExp = new Unequal(left, right);
                    ouput.push(numExp);
                } else BIGEQUAL_IF {
                    numExp = new BigEqual(left, right);
                    ouput.push(numExp);
                } else SMALLEQUAL_IF {
                    numExp = new SmallEqual(left, right);
                    ouput.push(numExp);
                }
            }
            postFix.pop_back();
        }

    }
//    Expression *finalValue = ouput.top();
//    //delete expresion
//    this->toDelete = finalValue;
//    ouput.pop();
    return ouput.top();
}

//ExpressionGenerator::~ExpressionGenerator() { delete this->toDelete; }

