//
// Created by Ere on 6/14/20.
//

#ifndef FTP_SERVER_IO_H
#define FTP_SERVER_IO_H


#include <string>

class IO {
protected:
    const static size_t BUFFER_SIZE_;
    static void Write_(int file_descriptor, const char* data, size_t size);
    static char* Read_(int file_descriptor, size_t size);

};




#endif //FTP_SERVER_IO_H
