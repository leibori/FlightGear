#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "Command.h"

using namespace std;

class ConnectCommand : public Command {
    int port;
    string ip;
    int simulatorSocket;
    bool *isServerOpen;
public:
    ConnectCommand(string serverIp, int portNum, bool *isServer) {
        port = portNum;
        ip = serverIp;
        isServerOpen = isServer;
    }
    void execute();
    void updateSimulator(string path, double value);
    ~ConnectCommand();
};

#endif //PROJECT_CONNECTCOMMAND_H
