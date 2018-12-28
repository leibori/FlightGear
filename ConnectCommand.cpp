#include "ConnectCommand.h"

void ConnectCommand::execute() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) { /* If failed throw exception. */
        throw "ERROR opening socket";
    }

    /* Get address */
    server = gethostbyname(ip.c_str());

    /* If failed throw exception. */
    if (server == nullptr) {
        throw "ERROR, no such host";
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        throw  "ERROR connecting";
    } else {
        symbolTable->setSimulatorSocket(sockfd);
    }
}

void ConnectCommand::updateSimulator(string path) {
    int readData;

    char* buffer[256];
    bzero(buffer, 256);

    string message = "set " + path + " " + to_string(symbolTable->getBindValuesTable().at(path)) + "\r\n";

    int socketID = symbolTable->getSimulatorSocket();
    if (socketID <= 0) {
        throw "ERROR Trying to send data before connection was made.\n";
    }

    readData = write(socketID, message.c_str(), message.length());

    /* If failed throw exception. */
    if (readData < 0) {
        throw "ERROR writing to socket.\n";
    }

    readData = read(socketID, buffer, 255);

    /* If failed throw exception. */
    if (readData < 0) {
        throw "ERROR reading response from server.\n";
    }
}