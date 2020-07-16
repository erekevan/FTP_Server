//
// Created by Ere on 6/16/20.
//
#include <fstream>
#include <streambuf>
#include <utility>
#include "file.h"
#include "file_not_found_error.h"

File::File(std::string path) : path_(path) {}

bool File::Exists() {
    std::ifstream f(path_);
    return f.good();
}

std::string File::Read() {
    if (!Exists()) {
        throw FileNotFoundError("Unable to read " + path_ + "!");
    }
    std::ifstream f(path_);
    std::string str;

    f.seekg(0, std::ios::end);
    str.reserve(f.tellg());
    f.seekg(0, std::ios::beg);

    str.assign(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());

    return str;
}

void File::Write(const std::string &payload) {
    std::ofstream ofs(path_, std::ofstream::out);
    ofs << payload;
    ofs.close();
}
