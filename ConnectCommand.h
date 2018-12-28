#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "Command.h"
#include "SymbolTable.h"

using namespace std;

class ConnectCommand : public Command {
    SymbolTable* symbolTable;
    int port;
    string ip;
public:
    ConnectCommand(SymbolTable* symbolTable1, string serverIp, int portNum) {
        symbolTable = symbolTable1;
        port = portNum;
        ip = serverIp;
    }
    void setPort(int newPort) { port = newPort; }
    void setIp(string newIp) { ip = newIp; }
    void execute();
    void updateSimulator(string path);
    };

#endif //PROJECT_CONNECTCOMMAND_H
