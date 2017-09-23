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

#ifndef NATIVE_STRING_H
#define NATIVE_STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

namespace Kernel {
    char *stringFromChar(char target);
    char *stringFromShort(short target);
    char *stringFromInt(int target);
    char *stringFromLong(long target);
    char *stringFromDouble(double target);
    char *stringFromFloat(float target);

    char stringToChar(char *target);
    short stringToShort(char *target);
    int stringToInt(char *target);
    long stringToLong(char *target);
    double stringToDouble(char *target);
    float stringToFloat(char *target);

    char *stringReplace(char *target, char *find, char *replace_with);
    char **stringSplit(char *target, char *delimiter);
    char *stringJoin(char **target, char *delimiter);
    int stringIndex(char *target, char *subtarget, int times);
    char *stringTrim(char *target);
    int stringStartswith(char *target, char *prefix);
    int stringEndswith(char *target, char *suffix);
    char *stringRandom(char *target, int size);
    char *stringAppend(char **target, char subtarget);
    char *stringConcat(char *target, char *subtarget);
    int stringEquals(char *target1, char *target2);
    char *string_concat_asm(char *target, char *subtarget);
    char *stringReverse(char *target);
    int stringMatches(char *target, char *regex);

    char *stringFromTo(char *target, int from, int to);
    char *stringFrom(char *target, int from);
    char *stringTo(char *target, int to);
    char *stringCopy(char *target);
    char *stringUpper(char *target);
    char *stringLower(char *target);
    char *stringTitle(char *target);
    char *stringStandardized(char *target);
    int stringToBoolean(char *target);
    char *stringFromBoolean(int target);
    char *urlEncode(char *target);
    char *urlDecode(char *target);

    char *findParam(char *name, char *params);
    char *findParamFromUrl(char *name, char *url);

    void freePointerPointerChar(char **char_array);
}

#define CHAR_LIST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMBER_LIST "0123456789"

#endif

