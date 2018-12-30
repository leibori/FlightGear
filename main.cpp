#include <iostream>

#include <thread>
#include <chrono>
#include "FunctionsBundle.h"

int main(int argc, char **argv) {
    SymbolTable *sym = new SymbolTable();
    FunctionsBundle *func = new FunctionsBundle();
    if (argc > 1) {
        try {
            func->parser(argv[1], sym);
        } catch (string message) {
            cout << message << endl;
            delete func;
            delete sym;
            return 0;
        }
    }
    delete func;
    delete sym;
    return 0;
}