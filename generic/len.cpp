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
#include "../common.h"
#include "../string.h"
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

/**
 * Length pointer char
 *
 * @param target
 * @return int
 */
int len(char *target) {
    return length_pointer_char(target);
}

/**
 * Length of std::string
 *
 * @param target
 * @return int
 */
int len(std::string target) {
    return target.length();
}

/**
 * Length pointer pointer char
 *
 * @param target
 * @return int
 */
int len(char **target) {
    return length_pointer_pointer_char(target);
}

/**
 * Length short number
 *
 * @param target
 * @return int
 */
int len(short target) {
    return length_pointer_char(string_from_short(target));
}

/**
 * Length int number
 *
 * @param target
 * @return int
 */
int len(int target) {
    return length_pointer_char(string_from_int(target));
}

/**
 * Length long number
 *
 * @param target
 * @return int
 */
int len(long target) {
    return length_pointer_char(string_from_long(target));
}

/**
 * Length float number
 *
 * @param target
 * @return int
 */
int len(float target) {
    return length_pointer_char(string_from_float(target));
}

/**
 * Length double number
 *
 * @param target
 * @return int
 */
int len(double target) {
    return length_pointer_char(string_from_double(target));
}

/**
 * Length of vector pointer char
 *
 * @param target
 * @return int
 */
int len(std::vector<char*> target) {
    return (int) target.size();
}

/**
 * Length of vector std::string
 *
 * @param target
 * @return int
 */
int len(std::vector<std::string> target) {
    return (int) target.size();
}

/**
 * Length of map char pointer
 *
 * @param target
 * @return int
 */
int len(std::map<char*, char*> target) {
    return (int) target.size();
}

/**
 * Length of map
 *
 * @param target
 * @return int
 */
int len(std::map<std::string, std::string> target) {
    return (int) target.size();
}

