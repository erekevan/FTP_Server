//
// Created by Ere on 6/16/20.
//

#include "network_io.h"

std::string NetworkIO::Read(int file_descriptor) {
    char *size = Read_(file_descriptor, sizeof(size_t));
    size_t expected_size = reinterpret_cast<size_t*>(size)[0];
    char *read_result = Read_(file_descriptor, expected_size);
    std::string result(read_result, expected_size);
    delete[] size;
    delete[] read_result;
    return result;
}

void NetworkIO::Write(int file_descriptor, const std::string &payload) {
    size_t size = payload.size();
    Write_(file_descriptor, (const char*) &size, sizeof(payload.size()));
    Write_(file_descriptor, payload.data(), payload.size());
}
