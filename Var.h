//
// Created by edan on 12/26/18.
//

#ifndef PROJ1_VAR_H
#define PROJ1_VAR_H

#include "Expression.h"
#include "SymbolTable.h"

using namespace std;

class Var: public Expression{
    string nameVar;
    SymbolTable* sym;
public:

    Var(const string &nameVar, SymbolTable *sym);


    double calculate() override;

};
#endif //PROJ1_VAR_H
