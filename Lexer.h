//
// Created by edan on 12/18/18.
//

#ifndef PROJ1_LEXER_H
#define PROJ1_LEXER_H

#include <string>
#include <vector>

using namespace std;

class Lexer{
    string toCut;
public:
    Lexer(const string &toCut);

    vector<string> lexerAlgorithem();


private:
    bool isOperatorChar(char c);
    bool isLexSign(char c);
};
#endif //PROJ1_LEXER_H
