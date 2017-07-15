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
#include "../../../unit_test.h"
}

#include "Random.hpp"

TEST (JavaUtil, RandomConstructor) {
    Random random1;
    ASSERT_TRUE(random1.getSeed() != 0);

    long seed = 60;
    Random random2 = Random(seed);
    ASSERT_TRUE(random2.getSeed() != 0);
}

TEST (JavaUtil, nextInt) {
    // Given a random number generator
    Random random1;
    int intMax = 0x7fffffff;
    int intMin = 0x80000000;

    // Test 10 number
    for(int index = 0; index < 10; index ++){
        int a = random1.nextInt();
        ASSERT_TRUE( a >= intMin && a <= intMax); // Check if the return value is in Integer range
    }
}

TEST (JavaUtil, nextIntWithBound) {
    // Given a random number generator
    Random random1;

    // Test nextInt(bound) with bound < 0,
    // will throw illegalArguementException("bound must be positive")
    try {
        random1.nextInt(-10);
    }
    catch (Exception e) {
        ASSERT_STR("bound must be positive", e.getMessage().toString());
    }

    // Test nextInt(bound) with bound = 100
    int bound = 100;
    for(int index = 0; index < 10; index ++){
        int a = random1.nextInt(bound);
        ASSERT_TRUE( a >= 0 && a < bound); // Check if the return value is in [0, bound)
    }
}