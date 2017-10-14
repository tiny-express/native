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

#ifndef NATIVE_KERNEL_COMMON_HPP
#define NATIVE_KERNEL_COMMON_HPP

// C++ builtin functions
#include "Builtin.hpp"

#define _BOOL                   1
#define CHAR                    2
#define SHORT_INT               3
#define INT                     4
#define LONG_INT                5
#define LONG_LONG_INT           6
#define FLOAT                   7
#define LONG_DOUBLE             8
#define VOID_POINTER            9
#define UNSIGNED_CHAR           10
#define SIGNED_CHAR             11
#define UNSIGNED_SHORT_INT      12
#define UNSIGNED_INT            13
#define UNSIGNED_LONG_INT       14
#define UNSIGNED_LONG_LONG_INT  15
#define DOUBLE                  16
#define CHAR_POINTER            17
#define INT_POINTER             18
#define OTHER                   19

#define typename(x)  _Generic((x),                                            \
        _Bool: _BOOL,                  unsigned char: UNSIGNED_CHAR,          \
         char: CHAR,                     signed char: SIGNED_CHAR,            \
    short int: SHORT_INT,         unsigned short int: UNSIGNED_SHORT_INT,     \
          int: INT,                     unsigned int: UNSIGNED_INT,           \
     long int: LONG_INT,           unsigned long int: UNSIGNED_LONG_INT,      \
long long int: LONG_LONG_INT, unsigned long long int: UNSIGNED_LONG_LONG_INT, \
        float: FLOAT,                         double: DOUBLE,                 \
  long double: LONG_DOUBLE,                   char *: CHAR_POINTER,           \
       void *: VOID_POINTER,                   int *: INT_POINTER,            \
      default: OTHER)

#include "Common/Append.hpp"
#include "Common/Join.hpp"
#include "Common/Segment.hpp"

#endif //NATIVE_KERNEL_COMMON_HPP