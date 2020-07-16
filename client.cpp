//
// Created by Ere on 6/14/20.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include "client.h"
#include "connection_error.h"
#include <arpa/inet.h>
#include "network_io.h"
#include "file.h"

Client::Client(const std::string &address, unsigned short int port) {
    socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (!socket_fd_){
        throw ConnectionError("Failed to Create a File Descriptor!\n");
    };
    auto socket_address = std::make_unique<struct sockaddr_in>();
    socket_address->sin_family = AF_INET;
    socket_address->sin_port = htons(port);
    int conversion_result = inet_pton(AF_INET, address.c_str(), &socket_address->sin_addr);
    if (conversion_result != 1) {
        throw ConnectionError(conversion_result == 0 ? "Invalid IP address!" : "IPv4 is not supported!");
    }
    memset(socket_address->sin_zero, 0, sizeof(socket_address->sin_zero));
    if (connect(socket_fd_, (struct sockaddr*) socket_address.get(), sizeof(struct sockaddr_in))){
        char buffer[INET_ADDRSTRLEN];
        std::string parsedIP = inet_ntop(AF_INET, &socket_address->sin_addr, buffer, INET_ADDRSTRLEN);
        throw ConnectionError("Unable to connect to " + parsedIP + ":" + std::to_string(ntohs(socket_address->sin_port)));
    }
}

void Client::RequestFile(const std::string &file_name) {
    NetworkIO::Write(socket_fd_, file_name);
}

void Client::Transfer(const std::string &source, const std::string &destination) {
    File source_file(source);
    File destination_file(destination);
    destination_file.Write(source_file.Read());
}

int main(int argc, const char *argv[]) {
    Client client("127.0.0.1", 8080);
    std::cout << "Connection Successful!" << std::endl;
//    client.RequestFile("mew.txt");

    // args[1:-1) is source files.
    // args[-1] is destination file if one source file, or directory.

    for (int i = 1; i < argc - 1; i++) {
       client.Transfer(argv[i], argv[argc - 1]);
    }
    return 0;
}