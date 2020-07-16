//
// Created by Ere on 6/20/20.
//

#include "file_not_found_error.h"

FileNotFoundError::FileNotFoundError(const std::string &string) : runtime_error(string) {}

