//
// Created by edan on 12/18/18.
//

#include "Lexer.h"
#include <vector>
#include <string>
#include "Lexer.h"
#define IP_NUM cutIt[j] == '.'

Lexer::Lexer(const string &toCut) : toCut(toCut) {}

vector<string> Lexer::lexerAlgorithem() {
    string cutIt = this->toCut;
    vector<string> afterCut;
    // bool isNextVar = false;
    //  bool isNextnumber = false;
    string s = "";
    int i = 0;
    int j = 0;
    while (i < cutIt.size()) {
        if (isLexSign(cutIt[i])) {
            i++;
            continue;
        } else if (isOperatorChar(cutIt[i])) {
            s = "";
            s.push_back(cutIt[i]);
            afterCut.push_back(s);
            i++;
        } else if (isdigit(cutIt[i])) {
            j = i + 1;
            s = "";
            s.push_back(cutIt[i]);
            while (j < cutIt.size() && (isdigit(cutIt[j])|| IP_NUM)) {
                s.push_back(cutIt[j]);
                j++;
            }
            afterCut.push_back(s);
            i = j;
        } else {
            j = i + 1;
            s = "";
            s.push_back(cutIt[i]);
            while ((j < cutIt.size()) && ((!isOperatorChar(cutIt[j])) && (!isLexSign(cutIt[j])))) {
                s.push_back(cutIt[j]);
                j++;
            }
            afterCut.push_back(s);
            i = j;
        }
    }
    return afterCut;
}

bool Lexer::isOperatorChar(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=');
}

bool Lexer::isLexSign(char c) {
    return (c == ' ' || c == '\n' || c == ',' || c == '\t');

}
vector<string> Lexer::splitIt(string str, string token) {
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