//
// Created by Ere on 6/16/20.
//

#ifndef FTP_SERVER_NETWORK_IO_H
#define FTP_SERVER_NETWORK_IO_H

#include "io.h"

class NetworkIO : public IO {
public:
    static std::string Read(int file_descriptor);
    static void Write(int file_descriptor, const std::string &payload);
};


#endif //FTP_SERVER_NETWORK_IO_H
