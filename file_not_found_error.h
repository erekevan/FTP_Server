//
// Created by Ere on 6/20/20.
//

#ifndef FTP_SERVER_FILE_NOT_FOUND_ERROR_H
#define FTP_SERVER_FILE_NOT_FOUND_ERROR_H

#include <stdexcept>
#include <iostream>

class FileNotFoundError : public std::runtime_error {
public:
    explicit FileNotFoundError(const std::string &string);
};

#endif //FTP_SERVER_FILE_NOT_FOUND_ERROR_H
