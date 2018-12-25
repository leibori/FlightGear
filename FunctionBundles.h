//
// Created by edan on 12/21/18.
//

#ifndef PROJ1_FUNCTIONSBUNDLE_H
#define PROJ1_FUNCTIONSBUNDLE_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "SymbolTable.h"
#include "Lexer.h"
#include "Expression.h"
#include "ExpressionGenerator.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "DefineVarCommand.h"

using namespace std;

class FunctionBundles {
public:
    Expression* createExpression(map<string,Command*> commandTable, vector<string> parts, int start, int end);
    string findAndCreateTypeOfDefineVarCommand(SymbolTable* symbolTable, vector<string> parts);
    Command* createIfCommand(SymbolTable* symbolTable, vector<string> parts, ifstream& in);
    Command* createLoopCommand(SymbolTable* symbolTable, vector<string> parts, ifstream& in);
    void parser(string fileName, SymbolTable* symbolTable);
};
#endif //PROJ1_FUNCTIONSBUNDLE_H