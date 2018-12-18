#include <iostream>
#include "ExpressionGenerator.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include <vector>
int main() {
    ExpressionGenerator* sh = new  ExpressionGenerator();
    vector<string> vecstri ;
   // vecstri.push_back("(");
   // vecstri.push_back("200");
   // vecstri.push_back( "/");
   // vecstri.push_back( "3");
   // vecstri.push_back(")");
   // vecstri.push_back( "+");
    //vecstri.push_back( "(");
    vecstri.push_back("(");
    vecstri.push_back(  "56");
    vecstri.push_back( "-");
    vecstri.push_back( "70");
    vecstri.push_back( ")");
    vecstri.push_back( "*");
    vecstri.push_back( "7");
    //vecstri.push_back(")");


    Expression* expressionnn = sh->GenerateExp(vecstri);
    double d = expressionnn->calculate();
    return 0;
}