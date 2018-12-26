#ifndef PROJECT_FUNCTIONSBUNDLE_H
#define PROJECT_FUNCTIONSBUNDLE_H

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
#include "PrintCommand.h"
#include "SleepCommand.h"

using namespace std;

class FunctionBundles {
public:
    Expression* createExpression(SymbolTable* symbolTable, vector<string> parts, int start, int end);
    Command* findAndCreateTypeOfDefineVarCommand(SymbolTable* symbolTable, vector<string> parts);
    Command* createIfCommand(SymbolTable* symbolTable, vector<string> parts, ifstream& in);
    Command* createLoopCommand(SymbolTable* symbolTable, vector<string> parts, ifstream& in);
    Command* createPrintCommand(SymbolTable* symbolTable, vector<string> parts);
    Command* createSleepCommand(SymbolTable* symbolTable, vector<string> parts);
    void parser(string fileName, SymbolTable* symbolTable);
};


#endif //PROJECT_FUNCTIONSBUNDLE_H
