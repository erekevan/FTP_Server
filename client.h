//
// Created by Ere on 6/14/20.
//

#ifndef FTP_SERVER_CLIENT_H
#define FTP_SERVER_CLIENT_H

// we need a constructor that takes in an address and port to connect to

#include <string>

class Client {
    int socket_fd_;

public:
    Client(const std::string &address, unsigned short int port);
    void RequestFile(const std::string &file_name);
    void Transfer(const std::string &source, const std::string &destination);
};


#endif //FTP_SERVER_CLIENT_H
