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

#include "../unit_test.h"
#include "../crypto.h"
#include "../type.h"

TEST(Crypto, Base64Encode) {
    #ifdef __APPLE__
        //FIXME:
        /**
         * native_test(3841,0x7fff7da0a000) malloc: *** error for object 0x7fb3dbc03d20:
         * incorrect checksum for freed object - object was probably modified after being freed.
         * */
        return;
    #endif

    char *expect = "Zm9vZHRpbnk=";
    char *target = "foodtiny";
    char *result1 = base64_encode((const unsigned char*) target, (size_t) length_pointer_char(target));
    ASSERT_STR(expect, (char*) result1);

    expect = "7IKs656R7ZW0";
    target = "사랑해";
    char *result2 = base64_encode((const unsigned char*) target, (size_t) length_pointer_char(target));
    ASSERT_STR(expect, (char*) result2);

    expect = "4Lic4Lih4Lij4Lix4LiB4LiE4Li44LiT";
    target = "ผมรักคุณ";
    char *result3 = base64_encode((const unsigned char*) target, (size_t)  length_pointer_char(target));
    ASSERT_STR(expect, (char*) result3);
}

TEST(Crypto, Base64Decode) {
    #ifdef __APPLE__
    //FIXME:
    /**
     * native_test(3841,0x7fff7da0a000) malloc: *** error for object 0x7fb3dbc03d20:
     * incorrect checksum for freed object - object was probably modified after being freed.
     * */
        return;
    #endif

    char *expect = "foodtiny";
    char *target = "Zm9vZHRpbnk=";
    unsigned char *result1 = base64_decode((const char*) target, (size_t) length_pointer_char(target));
    ASSERT_STR(expect, (char*) result1);

    expect = "사랑해";
    target = "7IKs656R7ZW0";
    unsigned char *result2 = base64_decode((const char*) target, (size_t) length_pointer_char(target));
    ASSERT_STR(expect, (char*) result2);

    expect = "ผมรักคุณ";
    target = "4Lic4Lih4Lij4Lix4LiB4LiE4Li44LiT";
    unsigned char *result3 = base64_decode((const char*) target, (size_t) length_pointer_char(target));
    ASSERT_STR(expect, (char*) result3);
}
