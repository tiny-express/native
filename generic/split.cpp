/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

extern "C" {
#include "../general.h"
#include "../string.h"
}
#include <iostream>
#include <vector>

/**
 * Split  by default - un-supported type
 *
 * @param T
 * @param t
 * @return empty array
 */
template <typename T> std::vector<T> split(T target, char *delimiter) {
    std::vector<T> empty_vector;
    return empty_vector;
}

/**
 * Split std::string
 *
 * @param target
 * @return std::string array
 */
template<> std::vector<std::string> split(std::string target, char *delimiter) {
    std::vector<std::string> empty_vector;
    return empty_vector;
}
template std::vector<std::string> split<std::string>(std::string target, char *delimiter);

/**
 * Split pointer char
 *
 * @param target
 * @return char pointer array
 */
template<> std::vector<char*> split(char *target, char *delimiter) {
    std::vector<char*> empty_vector;
    return empty_vector;
}
template std::vector<char*> split<char*>(char *target, char *delimiter);