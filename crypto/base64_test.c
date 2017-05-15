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
#include "../general.h"

TEST(Crypto, Base64Encode) {
    char *expect = "Zm9vZHRpbnk=";
    char *target = "foodtiny";
    char *result = base64_encode(target, length_pointer_char(target));
    ASSERT_STR(expect, result);

    expect = "7IKs656R7ZW0";
    target = "사랑해";
    result = base64_encode(target, length_pointer_char(target));
    ASSERT_STR(expect, result);

    expect = "4Lic4Lih4Lij4Lix4LiB4LiE4Li44LiT";
    target = "ผมรักคุณ";
    result = base64_encode(target, length_pointer_char(target));
    ASSERT_STR(expect, result);
}

TEST(Crypto, Base64Decode) {
    char *expect = "foodtiny";
    char *target = "Zm9vZHRpbnk=";
    char *result = base64_decode(target, length_pointer_char(target));
    ASSERT_STR(expect, result);

    expect = "사랑해";
    target = "7IKs656R7ZW0";
    result = base64_decode(target, length_pointer_char(target));
    ASSERT_STR(expect, result);

    expect = "ผมรักคุณ";
    target = "4Lic4Lih4Lij4Lix4LiB4LiE4Li44LiT";
    result = base64_decode(target, length_pointer_char(target));
    ASSERT_STR(expect, result);
}
