#include <iostream> // Input & output.
#include "server.h" // Link to header file.
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "connection_error.h"
#include "network_io.h"

Server::Server(const unsigned short int port) {
    socket_fd_ = socket(AF_INET, SOCK_STREAM, 0); // File descriptor.
    if (!socket_fd_) {
        throw ConnectionError("Socket File Description Creation Has Failed");
    }
    int yes= 1;
    int opt_result = setsockopt(socket_fd_, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    if (opt_result){
        throw ConnectionError("Failed To Set Socket Options!");
    }
    auto address = std::make_unique<struct sockaddr_in>();
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    address->sin_addr = { INADDR_ANY };
    memset(address->sin_zero, 0, sizeof(address->sin_zero));
    auto bind_result = bind(socket_fd_, (struct sockaddr*) address.get(), sizeof(struct sockaddr_in));
    if (bind_result) {
        throw ConnectionError(std::string("Cannot Bind to ") + inet_ntoa(address->sin_addr) + std::to_string(port) + "!");
    }
    int listen_result = listen(socket_fd_, 128);
    if (listen_result) {
        throw ConnectionError(std::string("Cannot Listen on ") + inet_ntoa(address->sin_addr) + std::to_string(port) + "!");
    }

    std::cout << "Server listening on port " << port << "!" << std::endl;
}

void Server::Listen() {
    socklen_t addie_size = sizeof(address_details_);
    int session_fd = accept(socket_fd_, (struct sockaddr*) address_details_.get(), &addie_size);
    if (session_fd < 0 && errno != EINTR) {
        throw ConnectionError(std::string("Failed to accept new connection at ") + inet_ntoa(address_details_->sin_addr) + ":" + std::to_string( ntohs(address_details_->sin_port )));
    }
    std::cout << "Server has accepted the client connection!" << std::endl;
    std::cout << NetworkIO::Read(session_fd) << std::endl;
}

int main(int argc, char const *argv[]) {
    Server server(8080);
    while (true) {
        server.Listen();
    }
    return 0;
}
