#include "DataReader.h"

void* DataReader::openServer(void* args) {
    DataReaderArguments* params = (DataReaderArguments*)args;
    int port = params->getPort();
    int frequency = params->getFrequency();
    SymbolTable* symbolTable = params->getSymbolTable();
    delete(params);

    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Check of creation succeeded*/
    if (sockfd < 0) {
        //symbolTable->isServerOpenFailed = true;
        perror("Failed to open connection.");
        exit(1);
    }

    /* Initialize m_socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)port));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //symbolTable->isServerOpenFailed = true;
        perror("Failed to bind server connection.");
        exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        //symbolTable->isServerOpenFailed = true;
        perror("Failed to accept server connection.");
        exit(1);
    }

    while (true) {
        string data;
        char buffer[2];
        ssize_t bytes_read;
        bytes_read = read(newsockfd, buffer, 1);
        while (buffer[0] != *"\n") {
            if (bytes_read < 0) {
                __throw_bad_exception();
//          } else if (bytes_read == 0)   {
//            // TODO connection closed
            }
            data += buffer[0];
            bytes_read = read(newsockfd, buffer, 1);
        }
        Lexer lexer(buffer);
        vector<string> values = lexer.splitIt(data, ",");
        symbolTable->updateMultipleBindValues(values);
        //cout << data;
        this_thread::__sleep_for(chrono::seconds(1 / frequency), chrono::nanoseconds(0));
    }
}
