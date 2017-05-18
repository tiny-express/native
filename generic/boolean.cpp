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

#include "../native.h"

/**
 * Boolean value by default - un-supported type
 *
 * @param T
 * @return 0
 */
template <typename T> bool Boolean(T) {
    return 0;
}

/**
 * Boolean value of std::string
 *
 * @param target
 * @return bool
 */
template<> bool Boolean(std::string target) {
    return string_to_double((char*) target.c_str());
}
template bool Boolean<std::string>(std::string target);

// /**
//  * Boolean value of char pointer
//  *
//  * @param target
//  * @return bool
//  */
// template<> bool Boolean(char *target) {
//     return string_to_boolean(target);
// }
template bool Boolean<char*>(char *target);

/**
 * Boolean value of integer
 *
 * @param target
 * @return bool
 */
template<> bool Boolean(int target) {
    return target;
}
template bool Boolean<int>(int target);

/**
 * Boolean value of long
 *
 * @param target
 * @return 0
 */
template<> bool Boolean(long target) {
    return 0;
}
template bool Boolean<long>(long target);

/**
 * Boolean value of float
 *
 * @param target
 * @return double
 */
template<> bool Boolean(float target) {
    return (int) floor(target);
}
template bool Boolean<float>(float target);

/**
 * Boolean value of double
 *
 * @param target
 * @return bool
 */
template<> bool Boolean(double target) {
    return (bool) floor(target);
}

template bool Boolean<double>(double target);

// /**
//  * Boolean value of boolean
//  *
//  * @param target
//  * @return bool
//  */
// template<> bool Boolean(bool target) {
//     return (bool) floor(target);
// }

// template bool Boolean<boolean>(bool target);
