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

#ifndef NATIVE_COMMON_JOIN_HPP
#define NATIVE_COMMON_JOIN_HPP

#include "../Type.hpp"
#include "../Common.hpp"

/**
 * Join pointer pointer char
 * Concatenating all elements in target array into single string
 *
 * @param target
 * @return char pointer
 */
inline char *joinPointerPointerChar(char **target) {
#ifdef LINUX
    register
#endif
    int totalLength = 0, itemLength = 0;
    char **pointer;
    auto *temporaryResult = (char *) calloc(MAX_STRING_LENGTH, sizeof(char));
    for (pointer = target; *pointer; ++pointer) {
        itemLength = lengthPointerChar(*pointer);
        memcpy(temporaryResult + totalLength, *pointer, (size_t) itemLength);
        totalLength += itemLength;
    }
    // Allocate enough memory for result
    auto *result = (char *) calloc((size_t) totalLength + 1, sizeof(char));
    memcpy(result, temporaryResult, (size_t) totalLength);
    // Free memory for temporary variable
    free(temporaryResult);
    return result;
}

/**
 * Join delimiter pointer pointer char
 * Concatenating all elements in target array into single string with delimiter
 *
 * @param target
 * @return char pointer
 */
inline char *joinDelimiterPointerPointerChar(char **target, const char *delimiter) {
#ifdef LINUX
    register
#endif
    int totalLength = 0, itemLength = 0;
    char **pointer;
    int delimiterLength = lengthPointerChar((char *) delimiter);
    auto *temporaryResult = (char *) calloc(MAX_STRING_LENGTH, sizeof(char));
    for (pointer = target; *pointer; ++pointer) {
        itemLength = lengthPointerChar(*pointer);
        memcpy(temporaryResult + totalLength, *pointer, (size_t) itemLength);
        totalLength += itemLength;
        memcpy(temporaryResult + totalLength, delimiter, (size_t) delimiterLength);
        totalLength += delimiterLength;
    }
    // Allocate enough memory for result
    auto *result = (char *) calloc((size_t) totalLength - delimiterLength + 1, sizeof(char));
    // Copy and remove remainder delimiter
    memcpy(result, temporaryResult, (size_t) totalLength - delimiterLength);
    // Free memory for temporary variable
    free(temporaryResult);
    return result;
}

#endif
