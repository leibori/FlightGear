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
#include "AileronDefineVar.h"
#include "AirspeedDefineVar.h"
#include "AltDefineVar.h"
#include "BreaksDefineVar.h"
#include "ElevatorDefineVar.h"
#include "HeadingDefineVar.h"
#include "PitchDefineVar.h"
#include "RollDefineVar.h"
#include "RudderDefineVar.h"
#include "ThrottleDefineVar.h"

using namespace std;

class FunctionBundles {
public:
    string replaceStringWithValue(map<string,double> newValues, string str);
    Expression* createExpression(map<string,Command*> commandTable, map<string,double> newValues, vector<string>
            parts, int start, int end);
    void inputToSymbolMap(SymbolTable* symbolTable, map<string,double> newValues, string str, Expression* expression);
    string findAndCreateTypeOfDefineVarCommand(SymbolTable* symbolTable, map<string,double> newVariables, vector<string>
            parts);
    Command* createIfCommand(SymbolTable* symbolTable, map<string,double> newVariables, vector<string> parts,
            stack<Command*> commands, ifstream& in);
    Command* createLoopCommand(SymbolTable* symbolTable, map<string,double> newVariables, vector<string> parts,
            stack<Command*> commands, ifstream& in);
    void parser(string fileName, SymbolTable* symbolTable);
};


#endif //PROJECT_FUNCTIONSBUNDLE_H
