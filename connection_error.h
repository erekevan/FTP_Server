//
// Created by Ere on 6/6/20.
//
#include <stdexcept>
#include <iostream>

#ifndef FTP_SERVER_CONNECTION_ERROR_H
#define FTP_SERVER_CONNECTION_ERROR_H


class ConnectionError : public std::runtime_error {
public:
    explicit ConnectionError(const std::string &string);
};

#endif //FTP_SERVER_CONNECTION_ERROR_H
