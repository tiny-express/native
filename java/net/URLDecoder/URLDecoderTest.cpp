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

#include "../../../kernel/Test.hpp"
#include "URLDecoder.hpp"
#include "../../io/UnsupportedEncodingException/UnsupportedEncodingException.hpp"

using namespace Java::Net;
using namespace Java::Lang;

TEST(JavaNet, URLDecoderDecode) {
    String target = "Qu%c3%a1n+%c4%83n";
    String result = URLDecoder::decode(target);
    String expect = u8"Quán ăn";
    assertEquals(expect.toString(), result.toString());
}

TEST(JavaNet, URLDecoderDecodeUsingSpecificEncodingScheme) {
    String target = "Qu%c3%a1n+%c4%83n";
    String result = URLDecoder::decode(target, "UTF-8");
    String expect = u8"Quán ăn";
    assertEquals(expect.toString(), result.toString());

    try {
        URLDecoder::decode(target, "UTF-0");
    } catch (UnsupportedEncodingException &ex) {
        assertEquals("UTF-0", ex.getMessage().toString());
    }
}
