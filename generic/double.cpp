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
#include "../native.h"

/**
 * Double value by default - un-supported type
 *
 * @param T
 * @return 0
 */
template <typename T> double Double(T) {
    return 0;
}

/**
 * Double value of std::string
 *
 * @param target
 * @return double
 */
template<> double Double(std::string target) {
    return string_to_double((char*) target.c_str());
}
template double Double<std::string>(std::string target);

/**
 * Double value of char pointer
 *
 * @param target
 * @return double
 */
template<> double Double(char *target) {
    return string_to_double(target);
}
template double Double<char*>(char *target);

/**
 * Double value of integer
 *
 * @param target
 * @return double
 */
template<> double Double(int target) {
    return target;
}
template double Double<int>(int target);

/**
 * Double value of long
 *
 * @param target
 * @return 0
 */
template<> double Double(long target) {
    return 0;
}
template double Double<long>(long target);

/**
 * Double value of float
 *
 * @param target
 * @return double
 */
template<> double Double(float target) {
    return (int) floor(target);
}
template double Double<float>(float target);

/**
 * Double value of double
 *
 * @param target
 * @return double
 */
template<> double Double(double target) {
    return (double) floor(target);
}

template double Double<double>(double target);
