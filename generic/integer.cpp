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
 * Integer value by default - un-supported type
 *
 * @param T
 * @return 0
 */
template <typename T> int Integer(T) {
    return 0;
}

/**
 * Integer value of std::string
 *
 * @param target
 * @return int
 */
template<> int Integer(std::string target) {
    return string_to_int((char*) target.c_str());
}
template int Integer<std::string>(std::string target);

/**
 * Integer value of char pointer
 *
 * @param target
 * @return int
 */
template<> int Integer(char *target) {
    return string_to_int(target);
}
template int Integer<char*>(char *target);

/**
 * Integer value of integer
 *
 * @param target
 * @return int
 */
template<> int Integer(int target) {
    return target;
}
template int Integer<int>(int target);

// /**
//  * Integer value of long
//  * Can not cast long to int
//  *
//  * @param target
//  * @return 0
//  */
// template<> int Integer(long target) {
//     return 0;
// }
// template int Integer<long>(long target);

// /**
//  * Integer value of float
//  *
//  * @param target
//  * @return int
//  */
// template<> int Integer(float target) {
//     return (int) floor(target);
// }
// template int Integer<float>(float target);

// /**
//  * Integer value of double
//  *
//  * @param target
//  * @return int
//  */
// template<> int Integer(double target) {
//     return (int) floor(target);
// }
// template int Integer<double>(double target);