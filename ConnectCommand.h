#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Command.h"

using namespace std;

class ConnectCommand : public Command {
    int port;
    string ip;
public:
    ConnectCommand(string serverIp, int portNum) {
        port = portNum;
        ip = serverIp;
    }
    void setPort(int newPort) { port = newPort; }
    void setIp(string newIp) { ip = newIp; }
    void execute();
    };

#endif //PROJECT_CONNECTCOMMAND_H
