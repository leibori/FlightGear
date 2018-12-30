#ifndef PROJECT_DATAREADERARGUMENTS_H
#define PROJECT_DATAREADERARGUMENTS_H

#include "SymbolTable.h"

class DataReaderArguments {
private:
    int port;
    int frequency;
    SymbolTable* symbolTable;
public:

    DataReaderArguments(int port1, int frequency1, SymbolTable* symbolTable1) {
        port = port1;
        frequency = frequency1;
        symbolTable = symbolTable1;
    }

    int getPort() const { return port; }

    int getFrequency() const { return frequency; }

    SymbolTable *getSymbolTable() const { return symbolTable; }
};

#endif //PROJECT_DATAREADERARGUMENTS_H
