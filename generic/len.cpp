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

/**
 * Length by default - un-supported type
 *
 * @param T
 * @param t
 * @return 0
 */
template <typename T> int len(T) {
    return 0;
}

/**
 * Length of std::string
 *
 * @param target
 * @return int
 */
template<> int len(std::string target) {
    return target.length();
}
template int len<std::string>(std::string target);

/**
 * Length pointer char
 *
 * @param target
 * @return int
 */
template<> int len(char *target) {
    return length_pointer_char(target);
}
template int len<char*>(char *target);

/**
 * Length short number
 *
 * @param target
 * @return int
 */
template<> int len(short target) {
    return length_pointer_char(string_from_short(target));
}
template int len<short>(short target);

/**
 * Length int number
 *
 * @param target
 * @return int
 */
template<> int len(int target) {
    return length_pointer_char(string_from_int(target));
}
template int len<int>(int target);

/**
 * Length long number
 *
 * @param target
 * @return int
 */
template<> int len(long target) {
    return length_pointer_char(string_from_long(target));
}
template int len<long>(long target);

/**
 * Length float number
 *
 * @param target
 * @return int
 */
template<> int len(float target) {
    return length_pointer_char(string_from_float(target));
}
template int len<float>(float target);

/**
 * Length double number
 *
 * @param target
 * @return int
 */
template<> int len(double target) {
    return length_pointer_char(string_from_double(target));
}
template int len<double>(double target);

