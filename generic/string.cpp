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
#include "../string.h"
}
#include <string>
#include <vector>
#include "../native.hpp"

/**
 * Convert char to pointer char
 *
 * @param string
 * @return pointer char
 */
char *String(char target) {
    return string_copy(&target);
}

/**
 * Convert constant pointer char to pointer char
 *
 * @param string
 * @return pointer char
 */
char *String(char const *target) {
    return (char*) target;
}

/**
 * Convert std::string to pointer char
 *
 * @param string
 * @return pointer char
 */
char *String(std::string target) {
    char *result = string_copy((char*) target.c_str());
    return result;
}

/**
 * String  int number
 *
 * @param int_number
 * @return Pointer char
 */
char *String(int target) {
    char *result = string_from_int(target);
    return result;
}

/**
 *  String double number
 *
 * @param double_number
 * @return Pointer char
 */
char *String(double target) {
    char *result = string_from_double(target);
    return result;
}

/**
 * String of vector int
 *
 * @param vectorInt
 * @return Pointer char
 */
char *String(std::vector<int> target) {
    std::string str;
    str.append("[");
    std::vector<int>::iterator it;

    for (it = target.begin(); it != target.end() - 1; ++it) {
        str.append(string_from_int(*it));
        str.append(", ");
    }
    str.append(string_from_int(*it));
    str.append("]");

    char *result = string_copy((char *) str.c_str());
    return result;
}

/**
 * String of vector double
 *
 * @param target
 * @return pointer char
 */
char *String(std::vector<double> target) {
    std::string str;
    str.append("[");
    std::vector<double>::iterator it;

    for (it = target.begin(); it != target.end() - 1; ++it) {
        str.append(string_from_double(*it));
        str.append(", ");
    }
    str.append(string_from_double(*it));
    str.append("]");

    char *result = string_copy((char *) str.c_str());
    return result;
}

