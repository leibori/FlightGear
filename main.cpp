#include <iostream>
#include "FunctionsBundle.h"
#include "Expression.h"
#include "Lexer.h"
#include <vector>
#include <map>
#include "Command.h"
#include "SymbolTable.h"
#include <iostream>
#include <fstream>

int main() {
    ofstream ofstr("test.txt", ios::app);
    SymbolTable *sym = new SymbolTable();
    FunctionsBundle *func = new FunctionsBundle();
    func->parser("test.txt", sym);



    // vecstri.push_back("(");
    // vecstri.push_back("200");
    // vecstri.push_back( "/");
    // vecstri.push_back( "3");
    // vecstri.push_back(")");
    //vecstri.push_back( "0.2");
    // vecstri.push_back( "*");
    // vecstri.push_back(  "0.2");
    //vecstri.push_back( "==");
    // vecstri.push_back("-");
    //  vecstri.push_back( "0.2");
    // vecstri.push_back( "*");
    //vecstri.push_back( "0.4");
    //vecstri.push_back(")");
    return 0;
}