/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

#ifndef NATIVE_KERNEL_BUILTIN_HPP
#define NATIVE_KERNEL_BUILTIN_HPP

// Definitions and macros
#include "Platform.hpp"
#include "Type.hpp"

// C Compatible Library
#include <cerrno>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <climits>
#include <cstdarg>
#include <cctype>
#include <ctime>

#ifdef LINUX
#include <stdint.h>
#endif

#ifdef DAWIN
#include <stdlib.h>
#include <mach/mach_time.h>
#endif

// C++ Standard Library
#include <thread>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <type_traits>
#include <string>
#include <iostream>

// Builtin functions
#define P_LEN(NAME, TYPE); \
inline long lengthPointer##NAME(TYPE *target) {\
    if (target == nullptr) return 0;\
    return __builtin_strlen(target);\
}

// Length of pointer pointer
#define P_P_LEN(NAME, TYPE); \
inline long lengthPointerPointer##NAME(TYPE **target) {\
    if (target == nullptr) return 0;\
    register TYPE**pointer;\
    for (pointer = target; *pointer; ++pointer);\
    return pointer - target;\
}

P_LEN(Char, char);
P_LEN(Char, const char);
P_P_LEN(Char, char);

/**
 * Is string empty ?
 *
 * @param input
 * @return TRUE or FALSE
 */
inline boolean isEmptyString(const char *input) {
    return lengthPointerChar(input) == 0;
}

/**
 * Allocate new memory with specific size
 *
 * @param size
 * @return void pointer
 */
inline void *allocateMemory(long size) {
#ifdef DARWIN
    return malloc(size);
#else
    return __builtin_malloc(size);
#endif
}

/**
 * Re-allocate memory with new capacity
 *
 * @param currentPointer
 * @param newCapacity
 * @return void*
 */
inline void *allocateMemory(void *currentPointer, size_t newCapacity) {
#ifdef DARWIN
    return realloc(currentPointer, newCapacity);
#else
    return __builtin_realloc(currentPointer, newCapacity);
#endif
}

/**
 * String copy
 *
 * @param target
 * @return char*
 */
inline char *stringCopy(const char *target) {
    return __builtin_strdup(target);
}

#endif //NATIVE_KERNEL_BUILTIN_HPP