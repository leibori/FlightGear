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
    vector<string>splitIt(string str, string token);
    vector<string> lexerAlgorithem();


private:
    bool isOperatorChar(string c, int i);
    bool isLexSign(char c);
    bool istwoChars(string c, int i);

};
#endif //PROJ1_LEXER_H
