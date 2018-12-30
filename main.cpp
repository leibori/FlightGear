#include <iostream>

#include <thread>
#include <chrono>
#include "FunctionsBundle.h"

int main(int argc, char **argv) {
    /*SymbolTable symbolTable;
    ofstream ofstr("test.txt", ios::app);*/
    SymbolTable *sym = new SymbolTable();
    FunctionsBundle *func = new FunctionsBundle();
    if (argc > 1) {
        func->parser(argv[1], sym);
    }
    return 0;
}