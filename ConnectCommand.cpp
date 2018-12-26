#include "ConnectCommand.h"

void ConnectCommand::execute() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) { /* If failed throw. */
        throw "ERROR opening socket";
    }

    /* Get address */
    server = gethostbyname(ip);
}