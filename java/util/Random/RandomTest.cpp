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
#include "../../../kernel/test.h"
}

#include "Random.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"

TEST (JavaUtil, RandomNextInt) {
    // Given a random number generator
    Random random1;

    //TODO change to Integer::MAX_VALUE and Integer::MIN_VALUE
    int intMax = 0x7fffffff;
    int intMin = 0x80000000;

    // Test 100 number
    for (int index = 0; index < 100; index++) {
        int a = random1.nextInt();
        ASSERT_TRUE( a >= intMin && a <= intMax); // Check if the return value is in Integer range
    }
}

TEST (JavaUtil, RandomNextIntWithBound) {
    // Given a random number generator
    Random random1;

    // Test nextInt(bound) with bound < 0,
    // will throw IllegalArguementException("bound must be positive")
    try {
        random1.nextInt(-10);
    }
    catch (IllegalArgumentException &e) {
        ASSERT_STR("bound must be positive", e.getMessage().toString());
    }

    // Test nextInt(bound) with bound = 100
    int bound = 100;
    int index;
    for (index = 0; index < 100; index++) {
        int a = random1.nextInt(bound);
        ASSERT_TRUE( a >= 0 && a < bound); // Check if the return value is in [0, bound)
    }

    // Test nextInt(bound) with bound = 64 is a power of 2
    bound = 64;
    for (index = 0; index < 100; index++) {
        int a = random1.nextInt(bound);
        ASSERT_TRUE( a >= 0 && a < bound); // Check if the return value is in [0, bound)
    }
}

TEST (JavaUtil, RandomNextBytes) {
    // Given a random number generator
    Random random1;

    // Given a byte array
    Array<byte> byteArray(100);

    // Generates random bytes and places them into byteArray
    random1.nextBytes(&byteArray);

    // Test if every generated byte is in byte range
    byte byteMax = 255;
    byte byteMin = 0;
    int index;
    for (index = 0; index < byteArray.length; index++) {
        ASSERT_TRUE(byteArray[index] >= byteMin && byteArray[index] <= byteMax);
    }
}

TEST (JavaUtil, RandomNextDouble) {
    // Given a random number generator
    Random random1;

    // Test if every generated double is in [0, 1) range
    int index;
    for (index = 0; index < 100; index++) {
        double generatedDouble = random1.nextDouble();
        ASSERT_TRUE(generatedDouble >= 0 && generatedDouble < 1.0);
    }
}

TEST (JavaUtil, RandomNextLong) {
    // Given a random number generator
    Random random1;

    // Test if every generated long is in long range
    //TODO change to Long::MAX_VALUE and Long::MIN_VALUE
    long longMax = 0x7fffffffffffffffL;
    long longMin = 0x8000000000000000L;
    int index;
    for (index = 0; index < 100; index++) {
        double generatedLong = random1.nextLong();
        ASSERT_TRUE(generatedLong >= longMin && generatedLong <= longMax);
    }
}

TEST (JavaUtil, RandomNextFloat) {
    // Given a random number generator
    Random random1;

    // Test if every generated float is in [0, 1) range
    int index;
    for (index = 0; index < 100; index++) {
        float generatedFloat = random1.nextFloat();
        ASSERT_TRUE(generatedFloat >= 0 && generatedFloat < 1.0);
    }
}

TEST (JavaUtil, RandomNextBoolean) {
    // Given a random number generator
    Random random1;

    // Test if every generated Boolean is actually a bool
    int index;
    for (index = 0; index < 100; index++) {
        boolean generatedBool = random1.nextBoolean();
        ASSERT_TRUE(generatedBool == TRUE || generatedBool == FALSE);
    }
}

TEST (JavaUtil, RandomNextGaussian) {
    // Given a random number generator
    Random random1;

    // Test if every generated Gaussian != 0
    int index;
    for (index = 0; index < 100; index++) {
        double generatedGaussian = random1.nextGaussian();
    }
}


TEST (JavaUtil, RandomSetSeed) {
    // Given a random number generator
    Random random1;
    long expectSeed = (100 ^ 0x5DEECE66DL) & ((1L << 48) - 1);
    random1.setSeed(100);
    //ASSERT_EQUAL(expectSeed, random1.getSeed());
}