//
// Created by Ere on 6/16/20.
//

#ifndef FTP_SERVER_FILE_H
#define FTP_SERVER_FILE_H
#include "string"
#include "io.h"

class File {
    const std::string path_;
public:
    explicit File(std::string path);
    bool Exists();
    std::string Read();
    void Write(const std::string &payload);
};


#endif //FTP_SERVER_FILE_H
