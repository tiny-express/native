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
#include "../crypto.h"
#include "../string.h"
}
#include <iostream>

/**
 * SHA1 Encode from char pointer
 *
 * @param target
 * @return SHA1 encoded string
 */
char *sha1(char *target) {
    char *result = sha1_encode((unsigned char*)target);
    return result;
}

/**
 * SHA1 Encode from std::string
 *
 * @param target
 * @return SHA1 encoded string
 */
char *sha1(std::string target) {
    char *result = sha1_encode((unsigned char*)target.c_str());
    return result;
}

/**
 * SHA1 Encode from short
 *
 * @param target
 * @return SHA1 encoded string
 */
char *sha1(short target) {
    char *result = sha1_encode((unsigned char*)string_from_short(target));
    return result;
}

/**
 * SHA1 Encode from int
 *
 * @param target
 * @return SHA1 encoded string
 */
char *sha1(int target) {
    char *result = sha1_encode((unsigned char*) string_from_int(target));
    return result;
}

/**
 * SHA1 Encode from long
 *
 * @param target
 * @return SHA1 encoded string
 */
char *sha1(long target) {
    char *result = sha1_encode((unsigned char*) string_from_long(target));
    return result;
}

/**
 * SHA1 Encode from double
 *
 * @param target
 * @return SHA1 encoded string
 */
char *sha1(double target) {
    char *result = sha1_encode((unsigned char*) string_from_double(target));
    return result;
}






