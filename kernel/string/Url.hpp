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

#ifndef NATIVE_KERNEL_STRING_URL_HPP
#define NATIVE_KERNEL_STRING_URL_HPP

#include "../Platform.hpp"
#include "../String.hpp"
#include "../Common.hpp"

inline char charFromHex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

inline char charToHex(char code) {
    static char hex[] = "0123456789abcdef";
    return hex[code & 15];
}

inline char *urlEncode(char *target) {
    char *targetIndex = target;
    auto result = (char *) calloc((size_t) lengthPointerChar(target) * 3 + 1, sizeof(char));
    char *resultIndex = result;
    while (*targetIndex) {
        if (isalnum(*targetIndex) || *targetIndex == '-' || *targetIndex == '_' || *targetIndex == '.' ||
            *targetIndex == '~') {
            *resultIndex++ = *targetIndex;
        } else if (*targetIndex == ' ') {
            *resultIndex++ = '+';
        } else {
            *resultIndex++ = '%', *resultIndex++ = charToHex(*targetIndex >> 4), *resultIndex++ = charToHex(
                    *targetIndex & 15);
        }
        targetIndex++;
    }
    *resultIndex = '\0';
    return result;
}

inline char *urlDecode(char *target) {
    char *targetIndex = target;
    auto result = (char *) calloc((size_t) lengthPointerChar(target) + 1, sizeof(char));
    char *resultIndex = result;
    while (*targetIndex) {
        if (*targetIndex == '%') {
            if (targetIndex[1] && targetIndex[2]) {
                *resultIndex++ = charFromHex(targetIndex[1]) << 4 | charFromHex(targetIndex[2]);
                targetIndex += 2;
            }
        } else if (*targetIndex == '+') {
            *resultIndex++ = ' ';
        } else {
            *resultIndex++ = *targetIndex;
        }
        targetIndex++;
    }
    *resultIndex = '\0';
    return result;
}

inline char *findParam(char *name, char *params) {
    if (strcmp(params, "") == 0) {
        return stringCopy("");
    }

    char **queryPairs = stringSplit(params, "&");
    int lengthPairs = lengthPointerPointerChar(queryPairs);

#ifdef LINUX
    register
#endif
    int i;
    for (i = 0; i < lengthPairs; i++) {
        char **pair = stringSplit(queryPairs[ i ], "=");
        if (lengthPointerPointerChar(pair) == 2) {
            if (strcmp(pair[ 0 ], name) == 0) {
                char *result = stringCopy(pair[ 1 ]);
                freePointerPointerChar(pair);
                freePointerPointerChar(queryPairs);
                return result;
            }
        }
        freePointerPointerChar(pair);
    }

    freePointerPointerChar(queryPairs);
    return stringCopy("");
}

inline char *findParamFromUrl(char *name, char *url) {
    char **urlComponents = stringSplit(url, "?");

    if (lengthPointerPointerChar(urlComponents) < 2) {
        freePointerPointerChar(urlComponents);
        return stringCopy("");
    }

    char *queryUrl = urlComponents[ 1 ];
    char **queryPairs = stringSplit(queryUrl, "&");
    int lengthPairs = lengthPointerPointerChar(queryPairs);

#ifdef LINUX
    register
#endif
    int i;
    for (i = 0; i < lengthPairs; i++) {
        char **pair = stringSplit(queryPairs[ i ], "=");
        if (lengthPointerPointerChar(pair) == 2) {
            if (strcmp(pair[ 0 ], name) == 0) {
                char *result = stringCopy(pair[ 1 ]);
                freePointerPointerChar(urlComponents);
                freePointerPointerChar(queryPairs);
                freePointerPointerChar(pair);

                return result;
            }
        }
        freePointerPointerChar(pair);
    }

    freePointerPointerChar(urlComponents);
    freePointerPointerChar(queryPairs);

    return stringCopy("");
}

#endif