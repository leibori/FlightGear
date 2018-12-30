#ifndef PROJECT_DATAREADER_H
#define PROJECT_DATAREADER_H

#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <pthread.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <vector>

#include "SymbolTable.h"
#include "DataReaderArguments.h"
#include "Lexer.h"

using namespace std;

class DataReader {
public:
    static void* openServer(void* portNum);
};

#endif //PROJECT_DATAREADER_H
