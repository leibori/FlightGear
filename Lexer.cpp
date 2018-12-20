//
// Created by edan on 12/18/18.
//

#include "Lexer.h"
#include <vector>
#include <string>
#include "Lexer.h"

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
            //isNextVar = false;
            //isNextnumber = false;
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
            while (j < cutIt.size() && isdigit(cutIt[j])) {
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
