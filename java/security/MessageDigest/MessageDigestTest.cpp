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

extern "C" {
#include "../../../kernel/test.h"
}

#include "MessageDigest.hpp"

using namespace Java::Lang;
using namespace Java::Security;

TEST(JavaSecurity, MD5) {
    byte expect[] = {0x77, 0xad, 0xd1, 0xd5, 0xf4, 0x12, 0x23, 0xd5, 0x58,
                     0x2f, 0xca, 0x73, 0x6a, 0x5c, 0xb3, 0x35};
    String input = "the quick brown fox jumps over the lazy dog";
    byte* result = NULL;

    MessageDigest* md5 = MessageDigest::getInstance("MD5");
    if (md5) {
        md5->update((byte*)input.toString(), 0, input.getSize());
        result = new byte[md5->getDigestLength()]();
        md5->digest(result, 0, md5->getDigestLength());
        ASSERT_DATA(expect,
                    sizeof(expect),
                    result,
                    (size_t)md5->getDigestLength());
        delete[] result;
    }
}