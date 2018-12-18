//
// Created by ori on 12/14/18.
//
#include "ExpressionGenerator.h"
#include "Number.h"
#include "Add.h"
#include "Sub.h"
#include "Div.h"
#include "Mul.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
#include <sstream>
#include <deque>

using namespace std;

/*
 * function name: isOperator
 * The function check if the string it get is operator
 * */
bool ExpressionGenerator::isOperator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
}

/*
 * function name: priority
 * The function put priority to operators by logical order
 */
int ExpressionGenerator::priority(const string &s) {
    int prio;
    if (s == "*" || s == "/") {
        prio = 3;
        return prio;
    } else if (s == "+" || s == "-") {
        prio = 2;
        return prio;
    } else if (s == "(" || s == ")") {
        prio = 1;
        return prio;
    } else {
        prio = 0;
        return prio;
    }
}


vector<string> ExpressionGenerator::splitIt(string str, string token) {
    vector<string> result;
    while (str.size()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)result.push_back(str);
        } else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
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

    //operator: +, -, *, /, ()
    //operands: 1234567890
    for (int i = 0; i < parts.size(); i++) {
        if (!isOperator(parts[i]) && priority(parts[i]) < 1) {
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
            while (!s.empty() && priority(s.top()) >= priority(parts[i])) {
                outQueue.push_front(s.top());
                s.pop();
            }
            s.push(parts[i]);
        }
    }
    //pop any remaining operators from the stack and insert to outputlist
    while (!s.empty()) {
        //outputList.push_back(s.top());
        outQueue.push_front(s.top());
        s.pop();
    }
    return outQueue;
}

Expression *ExpressionGenerator::GenerateExp(vector<string> orig) {
    deque<string> postFix = shuntingYardAlgoritem(orig);
    string fromQu;
    Expression *numExp;
    stack<Expression *> ouput;
    while (!postFix.empty()) {
        string temp = postFix.back();
        if (!isOperator(temp)) {
            numExp = new Number(stoi(temp));
            ouput.push(numExp);
            postFix.pop_back();
        } else {
            Expression *right = ouput.top();
            ouput.pop();
            Expression *left = ouput.top();
            ouput.pop();
            if (temp == "+") {
                numExp = new Add(left, right);
                ouput.push(numExp);
            } else if (temp == "-") {
                numExp = new Sub(left, right);
                ouput.push(numExp);
            } else if (temp == "*") {
                numExp = new Mul(left, right);
                ouput.push(numExp);
            } else {
                numExp = new Div(left, right);
                ouput.push(numExp);
            }
            postFix.pop_back();
        }
        ;
    }
    return ouput.top();
}

