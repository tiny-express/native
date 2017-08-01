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
    BitSet bitSet;
    ASSERT_EQUAL(0, bitSet.cardinality());
    bitSet.set(100);
    ASSERT_EQUAL(1, bitSet.cardinality());
}

TEST(JavaUtil, BitSetClear) {
    BitSet bitSet;
    ASSERT_EQUAL(0, bitSet.length());
    ASSERT_EQUAL(false, bitSet.get(9));
    // ... only bit set at index 9 is set to 1.
    bitSet.set(9);
    ASSERT_EQUAL(10, bitSet.length());
    ASSERT_EQUAL(1, bitSet.cardinality());
    ASSERT_EQUAL(true, bitSet.get(9));
    bitSet.clear();
    ASSERT_EQUAL(0, bitSet.length());
    ASSERT_EQUAL(0, bitSet.cardinality());
    ASSERT_EQUAL(false, bitSet.get(9));

    // bitIndex < 0
    try {
        bitSet.clear(-1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("bitIndex < 0: -1", ex.getMessage().toString());
    }

    ASSERT_EQUAL(false, bitSet.get(1));
    ASSERT_EQUAL(false, bitSet.get(5));
    bitSet.set(1);
    bitSet.set(5);
    ASSERT_EQUAL(true, bitSet.get(1));
    ASSERT_EQUAL(true, bitSet.get(5));
    bitSet.clear(2, 5);
    ASSERT_EQUAL(true, bitSet.get(1));
    ASSERT_EQUAL(true, bitSet.get(5));
    bitSet.clear(2, 6);
    ASSERT_EQUAL(true, bitSet.get(1));
    ASSERT_EQUAL(false, bitSet.get(5));

    // fromIndex < 0
    try {
        bitSet.clear(-1, 5);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        bitSet.clear(0, -1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        bitSet.clear(5, 3);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("fromIndex: 5 > toIndex: 3", ex.getMessage().toString());
    }

    // Reset bitSet.
    bitSet.clear();

    // Clear a large range.
    // Set all bits set at index[0..1023] to 1.
    bitSet.set(0, 1024);
    ASSERT_EQUAL(1024, bitSet.length());
    ASSERT_EQUAL(true, bitSet.get(0));
    ASSERT_EQUAL(true, bitSet.get(512));
    ASSERT_EQUAL(true, bitSet.get(1023));
    ASSERT_EQUAL(false, bitSet.get(1024));
    bitSet.clear(512, 1024);
    ASSERT_EQUAL(true, bitSet.get(0));
    ASSERT_EQUAL(false, bitSet.get(512));
    ASSERT_EQUAL(false, bitSet.get(1023));
    ASSERT_EQUAL(false, bitSet.get(1024));
}

TEST(JavaUtil, BitSetEquals) {
    // TODO(truongchauhien): Create test later.
}

TEST(JavaUtil, BitSetHashCode) {
    BitSet bitSet1;
    BitSet bitSet2;
    ASSERT_EQUAL(bitSet1.hashCode(), bitSet2.hashCode());
}

TEST(JavaUtil, BitSetLength) {
    BitSet defaultBitSet;
    ASSERT_EQUAL(0, defaultBitSet.length());
    BitSet initialSizeBitSet(100);
    ASSERT_EQUAL(0, initialSizeBitSet.length());
}

TEST(JavaUtil, BitSetGet) {
    BitSet bitSet1;
    ASSERT_EQUAL(0, bitSet1.length());
    ASSERT_EQUAL(64, bitSet1.size());
    // bitIndex < 0
    try {
        bitSet1.get(-1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("bitIndex < 0: -1", ex.getMessage().toString());
    }
    // bitIndex > logical length
    ASSERT_EQUAL(false, bitSet1.get(100));
    bitSet1.set(9);
    // => BitSet will be expanded.
    ASSERT_EQUAL(10, bitSet1.length());
    // bit set at index = 8 is currently set to 0.
    ASSERT_EQUAL(false, bitSet1.get(8));
    // bit set at index = 9 is currently set to 1.
    ASSERT_EQUAL(true, bitSet1.get(9));

    // bitSet2 will be same as bitSet 1.
    BitSet bitSet2 = bitSet1.get(0, 10);
    ASSERT_EQUAL(10, bitSet2.length());
    ASSERT_EQUAL(false, bitSet1.get(8));
    ASSERT_EQUAL(true, bitSet1.get(9));

    // fromIndex < 0
    try {
        BitSet bitSet3 = bitSet1.get(-1, 10);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        BitSet bitSet3 = bitSet1.get(0, -1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        BitSet bitSet3 = bitSet1.get(5, 2);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("fromIndex: 5 > toIndex: 2", ex.getMessage().toString());
    }

    // Get on a large range.
    BitSet bitSet4(1024);
    bitSet4.set(0, 512, false);
    bitSet4.set(512, 1024, true);
    ASSERT_EQUAL(false, bitSet4.get(0));
    ASSERT_EQUAL(false, bitSet4.get(511));
    ASSERT_EQUAL(true, bitSet4.get(512));
    ASSERT_EQUAL(true, bitSet4.get(1023));
    ASSERT_EQUAL(false, bitSet4.get(1024));

    BitSet bitSet5 = bitSet4.get(200, 900);
    ASSERT_EQUAL(700, bitSet5.length());
    ASSERT_EQUAL(false, bitSet5.get(0));
    ASSERT_EQUAL(false, bitSet5.get(311));
    ASSERT_EQUAL(true, bitSet5.get(312));
    ASSERT_EQUAL(true, bitSet5.get(699));
    ASSERT_EQUAL(false, bitSet5.get(700));
}

TEST(VavaUtil, BitSetSet) {
    BitSet bitSet1;
    ASSERT_EQUAL(0, bitSet1.length());
    ASSERT_EQUAL(64, bitSet1.size());
    // bitIndex < 0
    try {
        bitSet1.set(-1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("bitIndex < 0: -1", ex.getMessage().toString());
    }
    ASSERT_EQUAL(false, bitSet1.get(9));
    // bitIndex > logical length => BitSet will be expanded.
    bitSet1.set(9);
    // Highest index now is 9
    // => Logical length is 10
    ASSERT_EQUAL(10, bitSet1.length());
    ASSERT_EQUAL(true, bitSet1.get(9));
    // With specified value.
    bitSet1.set(9, false);
    ASSERT_EQUAL(false, bitSet1.get(9));
    bitSet1.set(9, true);
    ASSERT_EQUAL(true, bitSet1.get(9));

    BitSet bitSet2;
    bitSet2.set(0, 100);
    // index[0..100) => 100 bits set => logical length = 100.
    // maxIndex = 99.
    ASSERT_EQUAL(100, bitSet2.length());
    ASSERT_EQUAL(128, bitSet2.size());
    ASSERT_EQUAL(true, bitSet2.get(0));
    ASSERT_EQUAL(false, bitSet2.get(100));
    // Set by range with specified value.
    bitSet2.set(0, 100, false);
    ASSERT_EQUAL(false, bitSet2.get(0));
    ASSERT_EQUAL(false, bitSet2.get(100));
    bitSet2.set(0, 100, true);
    ASSERT_EQUAL(true, bitSet2.get(0));
    ASSERT_EQUAL(false, bitSet2.get(100));

    // fromIndex < 0
    try {
        bitSet2.set(-1, 100);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        bitSet2.set(0, -1);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        bitSet2.set(20, 10);
    } catch (IndexOutOfBoundsException ex) {
        ASSERT_STR("fromIndex: 20 > toIndex: 10", ex.getMessage().toString());
    }

    // Reset bitSet.
    bitSet2.clear();

    // Set on a large range.
    bitSet2.set(0, 1024, true);
    ASSERT_EQUAL(1024, bitSet2.length());
    ASSERT_EQUAL(true, bitSet2.get(0));
    ASSERT_EQUAL(true, bitSet2.get(512));
    ASSERT_EQUAL(true, bitSet2.get(1023));
    ASSERT_EQUAL(false, bitSet2.get(1024));
    bitSet2.set(512, 1024, false);
    ASSERT_EQUAL(true, bitSet2.get(0));
    ASSERT_EQUAL(false, bitSet2.get(512));
    ASSERT_EQUAL(false, bitSet2.get(1023));
    ASSERT_EQUAL(false, bitSet2.get(1024));
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
