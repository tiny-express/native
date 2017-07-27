/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

#include "../Base64/Base64.hpp"
#include "../Arrays/Arrays.hpp"

using namespace Java::Util;

TEST(JavaUtil, Base64Encoder) {
    Array<byte> input1 = {'M', 'a', 'n'};
    Array<byte> input2 = {'M', 'a'};
    Array<byte> input3 = {'M'};

    Base64::Encoder encoder = Base64::getEncoder();
    Array<byte> output1 = encoder.encode(input1);
    Array<byte> output2 = encoder.encode(input2);
    Array<byte> output3 = encoder.encode(input3);
    ASSERT_TRUE(Arrays::equals(Array<byte>{'T', 'W', 'F', 'u'}, output1));
    ASSERT_TRUE(Arrays::equals(Array<byte>{'T', 'W', 'E', '='}, output2));
    ASSERT_TRUE(Arrays::equals(Array<byte>{'T', 'Q', '=', '='}, output3));
}

TEST(JavaUtil, Base64Decoder) {
    Array<byte> input1 = {'T', 'W', 'F', 'u'};
    Array<byte> input2 = {'T', 'W', 'E', '='};
    Array<byte> input3 = {'T', 'Q', '=', '='};

    Base64::Decoder decoder = Base64::getDecoder();
    Array<byte> output1 = decoder.decode(input1);
    Array<byte> output2 = decoder.decode(input2);
    Array<byte> output3 = decoder.decode(input3);
    ASSERT_TRUE(Arrays::equals(Array<byte> {'M', 'a', 'n'}, output1));
    ASSERT_TRUE(Arrays::equals(Array<byte> {'M', 'a'}, output2));
    ASSERT_TRUE(Arrays::equals(Array<byte> {'M', }, output3));
}
