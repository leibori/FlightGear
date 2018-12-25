#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <algorithm>
#include <vector>
#include <pthread.h>

#include "Command.h"
#include "SymbolTable.h"
#include "Lexer.h"
#include "vector"

using namespace std;

class OpenServerCommand : public Command {
    SymbolTable* symbolTable;
    int port;
    int frequency;
public:
    OpenServerCommand(SymbolTable* symbolTable1, int portNum, int freqency1) {
        this->symbolTable = symbolTable1;
        this->port = portNum;
        this->frequency = freqency1;
    }
    void setPort(int newPort) { port = newPort; }
    void setFrequency(int newFreq) { frequency = newFreq; }
    void execute();
};
void* executeInThread(void*);
void initializeBindValues();
void constantRead(int newsockfd);
void updateBindValues(vector<string> values);


#endif //PROJECT_OPENSERVERCOMMAND_H
