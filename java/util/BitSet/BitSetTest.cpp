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

#include "../BitSet/BitSet.hpp"
#include "../../lang/IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../../lang/NegativeArraySizeException/NegativeArraySizeException.hpp"

TEST(JavaUtil, BitSetConstructor) {
    BitSet defaultBitSet;
    ASSERT_EQUAL(0, defaultBitSet.length());
    ASSERT_EQUAL(64, defaultBitSet.size());

    BitSet initialSizeBitSet(100);
    ASSERT_EQUAL(0, initialSizeBitSet.length());
    ASSERT_EQUAL(128, initialSizeBitSet.size());

    try {
        BitSet initialNegativeSizeBitSet(-1);
    } catch (NegativeArraySizeException ex) {
        ASSERT_STR("numberOfBits < 0: -1", ex.getMessage().toString());
    }
}

TEST(JavaUtil, BitSetCardinality) {
    BitSet defaultBitSet;
    ASSERT_EQUAL(0, defaultBitSet.cardinality());
}

TEST(JavaUtil, BitSetEquals) {
    // TODO(truongchauhien): Create test later.
}

TEST(JavaUtil, BitSetHashCode) {
    // TODO(truongchauhien): Create test later.
}

TEST(JavaUtil, BitSetLength) {
    BitSet defaultBitSet;
    ASSERT_EQUAL(0, defaultBitSet.length());
    BitSet initialSizeBitSet(100);
    ASSERT_EQUAL(0, initialSizeBitSet.length());
}

TEST(VavaUtil, BitSetSet) {
    BitSet bitSet;
    ASSERT_EQUAL(0, bitSet.length());
    ASSERT_EQUAL(64, bitSet.size());
    ASSERT_EQUAL(false, bitSet.get(9));
    bitSet.set(9);
    // Highest index now is 9
    // => Logical length is 10.
    ASSERT_EQUAL(10, bitSet.length());
    ASSERT_EQUAL(true, bitSet.get(9));
    try {
        bitSet.set(-1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("bitIndex < 0: -1", ex.getMessage().toString());
    }
}

TEST(JavaUtil, BitSetGet) {
    BitSet bitSet;
    ASSERT_EQUAL(0, bitSet.length());
    ASSERT_EQUAL(64, bitSet.size());
    try {
        bitSet.get(-1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("bitIndex < 0: -1", ex.getMessage().toString());
    }
    // bitIndex > logical length
    ASSERT_EQUAL(false, bitSet.get(100));
    bitSet.set(9);
    // bit at index = 8 is currently set to 0.
    ASSERT_EQUAL(false, bitSet.get(8));
    // bit at index = 8 is currently set to 1.
    ASSERT_EQUAL(true, bitSet.get(9));
}

TEST(JavaUtil, BitSetSize) {
    BitSet defaultBitSet;
    ASSERT_EQUAL(64, defaultBitSet.size());
    BitSet initialSizeBitSet(100);
    ASSERT_EQUAL(128, initialSizeBitSet.size());
}

TEST(JavaUtil, BitSetToString) {
    // TODO(truongchauhien): Create test later.
}
