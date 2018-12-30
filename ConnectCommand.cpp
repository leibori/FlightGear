#include "ConnectCommand.h"

void ConnectCommand::execute() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    while (!*isServerOpen) {}

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
        simulatorSocket = sockfd;
    }
}

void ConnectCommand::updateSimulator(string path, double value) {
    int readData;

    char* buffer[256];
    bzero(buffer, 256);

    string message = "set " + path + " " + to_string(value) + "\r\n";

    int socketID = simulatorSocket;
    if (socketID <= 0) {
        throw "ERROR Trying to send data before connection was made.\n";
    }

    /*if (path == "/controls/flight/aileron" || path == "/controls/flight/elevator" || path ==
    "/controls/flight/rudder" || path == "/instrumentation/heading-indicator/offset-deg") {
        cout << path + " : " + to_string(value) << endl;
    }*/

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