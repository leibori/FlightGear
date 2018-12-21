#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <sys/socket.h>
#include <netinet/in.h>

#include "Command.h"

class OpenServerCommand : Command {
    int port;
    int frequency;
public:
    OpenServerCommand(int portNum, int timesPerSec) {
        port = portNum;
        frequency = timesPerSec;
    }
    void setPort(int newPort) { port = newPort; }
    void setFrequency(int newFreq) { frequency = newFreq; }
    int execute();
};

#endif //PROJECT_OPENSERVERCOMMAND_H
