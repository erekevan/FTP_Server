
#ifndef FTP_SERVER_SERVER_H // Allow Multiple include.
#define FTP_SERVER_SERVER_H

class Server {
    int socket_fd_;
    std::unique_ptr<struct sockaddr_in> address_details_;

public:
    explicit Server(unsigned short int port);
    void Listen();
};

#endif
