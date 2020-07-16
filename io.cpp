//
// Created by Ere on 6/14/20.
//

#include "io.h"
#include <unistd.h>
#include "connection_error.h"

const size_t IO::BUFFER_SIZE_ = 1024;

void IO::Write_(int file_descriptor, const char* data, size_t size) {
    for (ssize_t bytes_written, i = 0; i < size; data += bytes_written, i += bytes_written) {
        bytes_written = write(file_descriptor, data, std::min(BUFFER_SIZE_, size - i));
        if (bytes_written == -1) {
            throw ConnectionError("Unable to write data! (Error " + std::to_string(errno) + ").");
        }
    }
}

char* IO::Read_(int file_descriptor, size_t size) {
    char *buffer = new char[size];
    for (ssize_t bytes_read, i = 0; i < size; buffer += bytes_read, i += bytes_read) {
        bytes_read = read(file_descriptor, buffer, std::min(BUFFER_SIZE_, size - i));
        if (bytes_read == -1) {
            throw ConnectionError("Unable to write data! (Error " + std::to_string(errno) + ").");
        }
    }
    return buffer - size;
}

