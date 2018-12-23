#include "ConnectCommand.h"

#define MAX_CLIENT 5

void ConnectCommand::execute() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_aton(ip);
    address.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, MAX_CLIENT);
}