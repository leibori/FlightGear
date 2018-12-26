//
// Created by edan on 12/26/18.
//

#include "Var.h"


Var::Var(const string &nameVar, SymbolTable *sym) : nameVar(nameVar), sym(sym) {}


double Var::calculate() {
        sym->getValuesTable().count(nameVar);
        double com = sym->getValuesTable().at(nameVar);
        return com;
}