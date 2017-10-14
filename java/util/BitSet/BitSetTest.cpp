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
#include "../BitSet/BitSet.hpp"
#include "../../lang/IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../../lang/NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../Arrays/Arrays.hpp"

TEST(JavaUtil, BitSetConstructor) {
    BitSet defaultBitSet;
    assertEquals(0, defaultBitSet.length());
    assertEquals(64, defaultBitSet.size());

    BitSet initialSizeBitSet(100);
    assertEquals(0, initialSizeBitSet.length());
    assertEquals(128, initialSizeBitSet.size());

    // numberOfBits < 0
    try {
        BitSet initialNegativeSizeBitSet(-1);
    } catch (NegativeArraySizeException &ex) {
        assertEquals("numberOfBits < 0: -1", ex.getMessage().toString());
    }

    initialSizeBitSet.set(50, 100, true);
    assertEquals(false, initialSizeBitSet.get(0));
    assertEquals(true, initialSizeBitSet.get(50));
    BitSet clonedBitSet(initialSizeBitSet);
    assertEquals(100, clonedBitSet.length());
    assertEquals(128, clonedBitSet.size());
    assertEquals(false, clonedBitSet.get(0));
    assertEquals(true, clonedBitSet.get(50));
}

TEST(JavaUtil, BitSetCardinality) {
    BitSet bitSet;
    assertEquals(0, bitSet.cardinality());
    bitSet.set(100);
    assertEquals(1, bitSet.cardinality());
}

TEST(JavaUtil, BitSetClear) {
    BitSet bitSet;
    assertEquals(0, bitSet.length());
    assertEquals(false, bitSet.get(9));
    // ... only bit set at index 9 is set to 1.
    bitSet.set(9);
    assertEquals(10, bitSet.length());
    assertEquals(1, bitSet.cardinality());
    assertEquals(true, bitSet.get(9));
    bitSet.clear();
    assertEquals(0, bitSet.length());
    assertEquals(0, bitSet.cardinality());
    assertEquals(false, bitSet.get(9));

    // bitIndex < 0
    try {
        bitSet.clear(-1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("bitIndex < 0: -1", ex.getMessage().toString());
    }

    assertEquals(false, bitSet.get(1));
    assertEquals(false, bitSet.get(5));
    bitSet.set(1);
    bitSet.set(5);
    assertEquals(true, bitSet.get(1));
    assertEquals(true, bitSet.get(5));
    bitSet.clear(1, 1);
    assertEquals(true, bitSet.get(1));
    bitSet.clear(2, 5);
    assertEquals(true, bitSet.get(1));
    assertEquals(true, bitSet.get(5));
    bitSet.clear(2, 6);
    assertEquals(true, bitSet.get(1));
    assertEquals(false, bitSet.get(5));

    // fromIndex < 0
    try {
        bitSet.clear(-1, 5);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        bitSet.clear(0, -1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        bitSet.clear(5, 3);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex: 5 > toIndex: 3", ex.getMessage().toString());
    }

    // Reset bitSet.
    bitSet.clear();

    // Clear a large range.
    // Set all bits set at index[0..1023] to 1.
    bitSet.set(0, 1024);
    assertEquals(1024, bitSet.length());
    assertEquals(true, bitSet.get(0));
    assertEquals(true, bitSet.get(512));
    assertEquals(true, bitSet.get(1023));
    assertEquals(false, bitSet.get(1024));
    bitSet.clear(512, 1024);
    assertEquals(true, bitSet.get(0));
    assertEquals(false, bitSet.get(512));
    assertEquals(false, bitSet.get(1023));
    assertEquals(false, bitSet.get(1024));
}

TEST(JavaUtil, BitSetClone) {
    BitSet bitSet1(100);
    assertEquals(0, bitSet1.length());
    assertEquals(128, bitSet1.size());

    BitSet clonedBitSet = bitSet1.clone();
    assertEquals(0, clonedBitSet.length());
    assertEquals(128, clonedBitSet.size());

    BitSet bitSet2;
    // Expanding words array.
    bitSet2.set(100, true);
    bitSet2.set(100, false);
    assertEquals(0, bitSet2.length());
    assertEquals(128, bitSet2.size());

    clonedBitSet = bitSet2.clone();
    assertEquals(0, clonedBitSet.length());
    // Trimming on clones.
    assertEquals(0, bitSet2.size());
    assertEquals(0, clonedBitSet.size());
}

TEST(JavaUtil, BitSetEquals) {
    String justString("Hello! I'm not a BitSet!");
    BitSet bitSet;
    assertFalse(bitSet.equals(justString));
    BitSet anotherBitSet(100);
    // Two of bit sets are equals because they contains only 0 bits.
    assertTrue(bitSet.equals(anotherBitSet));
    anotherBitSet.set(100, true);
    assertEquals(101, anotherBitSet.length());
    assertEquals(128, anotherBitSet.size());
    assertEquals(0, bitSet.length());
    // Two of bit sets have difference logical length.
    assertFalse(bitSet.equals(anotherBitSet));

    bitSet.clear();
    anotherBitSet.clear();
    assertTrue(bitSet.equals(anotherBitSet));

    bitSet.set(0, 1024, true);
    anotherBitSet.set(0, 1024, true);
    anotherBitSet.set(512, false);
    assertFalse(bitSet.equals(anotherBitSet));
}

TEST(JavaUtil, BitSetFlip) {
    BitSet bitSet;
    // 100110101
    bitSet.set(0, true);
    bitSet.set(1, false);
    bitSet.set(2, true);
    bitSet.set(3, false);
    bitSet.set(4, true);
    bitSet.set(5, true);
    bitSet.set(6, false);
    bitSet.set(7, false);
    bitSet.set(8, true);

    bitSet.flip(1);
    // 100110111
    assertEquals(true, bitSet.get(0));
    assertEquals(true, bitSet.get(1));
    assertEquals(true, bitSet.get(2));
    assertEquals(false, bitSet.get(3));
    assertEquals(true, bitSet.get(4));
    assertEquals(true, bitSet.get(5));
    assertEquals(false, bitSet.get(6));
    assertEquals(false, bitSet.get(7));
    assertEquals(true, bitSet.get(8));

    bitSet.flip(0, 9);
    // 011001000
    assertEquals(false, bitSet.get(0));
    assertEquals(false, bitSet.get(1));
    assertEquals(false, bitSet.get(2));
    assertEquals(true, bitSet.get(3));
    assertEquals(false, bitSet.get(4));
    assertEquals(false, bitSet.get(5));
    assertEquals(true, bitSet.get(6));
    assertEquals(true, bitSet.get(7));
    assertEquals(false, bitSet.get(8));

    // bitIndex < 0
    try {
        bitSet.flip(-1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("bitIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex < 0
    try {
        bitSet.flip(-1, 9);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        bitSet.flip(0, -1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        bitSet.flip(5, 1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex: 5 > toIndex: 1", ex.getMessage().toString());
    }

    // Reset bitSet.
    bitSet.clear();
    bitSet.set(0, 100, false);
    bitSet.set(100, 200, true);
    // Flip on a large range.
    bitSet.flip(50, 150);
    // Out range of "flip".
    assertEquals(false, bitSet.get(0));
    assertEquals(false, bitSet.get(49));
    assertEquals(true, bitSet.get(150));
    assertEquals(true, bitSet.get(199));
    // In range of "flip".
    assertEquals(true, bitSet.get(50));
    assertEquals(false, bitSet.get(100));
}

TEST(JavaUtil, BitSetHashCode) {
    BitSet bitSet1;
    BitSet bitSet2;
    assertTrue(bitSet1.hashCode() == bitSet2.hashCode());
    bitSet1.set(0, 100, true);
    bitSet2.set(0, 100, false);
    assertFalse(bitSet1.hashCode() == bitSet2.hashCode());
    bitSet2.set(0, 100, true);
    assertTrue(bitSet1.hashCode() == bitSet2.hashCode());
}

TEST(JavaUtil, BitSetIntersects) {
    BitSet bitSet1;
    BitSet bitSet2;
    bitSet1.set(0, 1024, false);
    bitSet2.set(0, 1024, true);
    assertFalse(bitSet1.intersects(bitSet2));
    bitSet1.set(512, true);
    assertTrue(bitSet1.intersects(bitSet2));

    bitSet1.clear();
    bitSet2.clear();
    bitSet1.set(0, 512, false);
    bitSet2.set(0, 1024, false);
    assertFalse(bitSet1.intersects(bitSet2));
    bitSet1.set(0, true);
    bitSet2.set(512, true);
    assertFalse(bitSet1.intersects(bitSet2));
}

TEST(JavaUtil, BitSetIsEmpty) {
    BitSet bitSet;
    assertTrue(bitSet.isEmpty());
    bitSet.set(1);
    assertFalse(bitSet.isEmpty());
    bitSet.clear();
    assertTrue(bitSet.isEmpty());
}

TEST(JavaUtil, BitSetLength) {
    BitSet defaultBitSet;
    assertEquals(0, defaultBitSet.length());
    BitSet initialSizeBitSet(100);
    assertEquals(0, initialSizeBitSet.length());
}

TEST(JavaUtil, BitSetNextClearBit) {
    BitSet bitSet;
    // fromIndex < 0
    try {
        bitSet.nextClearBit(-1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < 0: -1", ex.getMessage().toString());
    }
    assertEquals(0, bitSet.length());
    // fromIndex >= logical length.
    assertEquals(100, bitSet.nextClearBit(100));

    bitSet.set(0, 100, true);
    bitSet.set(100, 200, false);
    bitSet.set(200, 300, true);
    assertEquals(100, bitSet.nextClearBit(0));
    assertEquals(300, bitSet.nextClearBit(200));
    // logical length is power of 2.
    bitSet.set(0, 512, true);
    assertEquals(512, bitSet.nextClearBit(0));
}

TEST(JavaUtil, BitSetNextSetBit) {
    BitSet bitSet;
    // fromIndex < 0
    try {
        bitSet.nextSetBit(-1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < 0: -1", ex.getMessage().toString());
    }
    assertEquals(0, bitSet.length());
    // fromIndex >= logical length.
    assertEquals(-1, bitSet.nextSetBit(0));
    assertEquals(-1, bitSet.nextSetBit(100));

    bitSet.set(0, 100, true);
    bitSet.set(100, 200, false);
    bitSet.set(200, 300, true);
    assertEquals(0, bitSet.nextSetBit(0));
    assertEquals(5, bitSet.nextSetBit(5));
    assertEquals(200, bitSet.nextSetBit(100));
    assertEquals(200, bitSet.nextSetBit(200));
    assertEquals(-1, bitSet.nextSetBit(300));
}

TEST(JavaUtil, BitSetPreviousClearBit) {
    BitSet bitSet;
    // fromIndex = -1
    assertEquals(-1, bitSet.previousClearBit(-1));
    // fromIndex < -1
    try {
        bitSet.previousClearBit(-5);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < -1: -5", ex.getMessage().toString());
    }

    assertEquals(0, bitSet.length());
    // fromIndex > logical size
    assertEquals(0, bitSet.previousClearBit(0));
    assertEquals(100, bitSet.previousClearBit(100));

    bitSet.set(0, 100, true);
    bitSet.set(100, 200, false);
    bitSet.set(200, 300, true);
    assertEquals(-1, bitSet.previousClearBit(0));
    assertEquals(100, bitSet.previousClearBit(100));
    assertEquals(199, bitSet.previousClearBit(200));
    assertEquals(199, bitSet.previousClearBit(250));
    assertEquals(199, bitSet.previousClearBit(299));
    assertEquals(512, bitSet.previousClearBit(512));
}

TEST(JavaUtil, BitSetPreviousSetBit) {
    BitSet bitSet;
    // fromIndex = -1
    assertEquals(-1, bitSet.previousSetBit(-1));
    // fromIndex < -1
    try {
        bitSet.previousSetBit(-5);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < -1: -5", ex.getMessage().toString());
    }

    bitSet.set(0, 100, true);
    assertEquals(100, bitSet.length());
    // fromIndex > logical
    assertEquals(99, bitSet.previousSetBit(1000));

    // Reset bitSet.
    bitSet.clear();

    bitSet.set(0, 100, false);
    bitSet.set(100, 200, true);
    assertEquals(-1, bitSet.previousSetBit(99));
    assertEquals(100, bitSet.previousSetBit(100));
    assertEquals(199, bitSet.previousSetBit(200));
}

TEST(JavaUtil, BitSetGet) {
    BitSet bitSet1;
    assertEquals(0, bitSet1.length());
    assertEquals(64, bitSet1.size());
    // bitIndex < 0
    try {
        bitSet1.get(-1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("bitIndex < 0: -1", ex.getMessage().toString());
    }
    // bitIndex > logical length
    assertEquals(false, bitSet1.get(100));
    bitSet1.set(9);
    // => BitSet will be expanded.
    assertEquals(10, bitSet1.length());
    // bit set at index = 8 is currently set to 0.
    assertEquals(false, bitSet1.get(8));
    // bit set at index = 9 is currently set to 1.
    assertEquals(true, bitSet1.get(9));

    // bitSet2 will be same as bitSet 1.
    BitSet bitSet2 = bitSet1.get(0, 10);
    assertEquals(10, bitSet2.length());
    assertEquals(false, bitSet1.get(8));
    assertEquals(true, bitSet1.get(9));

    // fromIndex < 0
    try {
        BitSet bitSet3 = bitSet1.get(-1, 10);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        BitSet bitSet3 = bitSet1.get(0, -1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        BitSet bitSet3 = bitSet1.get(5, 2);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex: 5 > toIndex: 2", ex.getMessage().toString());
    }

    // Get on a large range.
    BitSet bitSet4(1024);
    bitSet4.set(0, 512, false);
    bitSet4.set(512, 1024, true);
    assertEquals(false, bitSet4.get(0));
    assertEquals(false, bitSet4.get(511));
    assertEquals(true, bitSet4.get(512));
    assertEquals(true, bitSet4.get(1023));
    assertEquals(false, bitSet4.get(1024));

    // fromIndex is power of 2.
    BitSet bitSet5 = bitSet4.get(512, 1024);
    assertEquals(512, bitSet5.length());
    assertEquals(true, bitSet5.get(0));
    assertEquals(false, bitSet5.get(512));

    // fromIndex, toIndex are in range.
    bitSet5 = bitSet4.get(200, 900);
    assertEquals(700, bitSet5.length());
    assertEquals(false, bitSet5.get(0));
    assertEquals(false, bitSet5.get(311));
    assertEquals(true, bitSet5.get(312));
    assertEquals(true, bitSet5.get(699));
    assertEquals(false, bitSet5.get(700));

    assertEquals(10, bitSet1.length());
    // fromIndex = toIndex
    BitSet bitSet6 = bitSet1.get(2, 2);
    assertEquals(0, bitSet6.length());
    // fromIndex >= logical length
    bitSet6 = bitSet1.get(10, 16);
    assertEquals(0, bitSet6.length());
    bitSet6 = bitSet1.get(0, 100);
    // toIndex > logical length
    assertEquals(10, bitSet6.length());
}

TEST(VavaUtil, BitSetSet) {
    BitSet bitSet1;
    assertEquals(0, bitSet1.length());
    assertEquals(64, bitSet1.size());
    // bitIndex < 0
    try {
        bitSet1.set(-1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("bitIndex < 0: -1", ex.getMessage().toString());
    }
    assertEquals(false, bitSet1.get(9));
    // bitIndex > logical length => BitSet will be expanded.
    bitSet1.set(9);
    // Highest index now is 9
    // => Logical length is 10
    assertEquals(10, bitSet1.length());
    assertEquals(true, bitSet1.get(9));
    // With specified value.
    bitSet1.set(9, false);
    assertEquals(false, bitSet1.get(9));
    bitSet1.set(9, true);
    assertEquals(true, bitSet1.get(9));

    BitSet bitSet2;
    bitSet2.set(0, 100);
    // index[0..100) => 100 bits set => logical length = 100.
    // maxIndex = 99.
    assertEquals(100, bitSet2.length());
    assertEquals(128, bitSet2.size());
    assertEquals(true, bitSet2.get(0));
    assertEquals(false, bitSet2.get(100));
    // Set by range with specified value.
    bitSet2.set(0, 100, false);
    assertEquals(false, bitSet2.get(0));
    assertEquals(false, bitSet2.get(100));
    bitSet2.set(0, 100, true);
    assertEquals(true, bitSet2.get(0));
    assertEquals(false, bitSet2.get(100));

    // fromIndex < 0
    try {
        bitSet2.set(-1, 100);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex < 0: -1", ex.getMessage().toString());
    }

    // toIndex < 0
    try {
        bitSet2.set(0, -1);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("toIndex < 0: -1", ex.getMessage().toString());
    }

    // fromIndex > toIndex
    try {
        bitSet2.set(20, 10);
    } catch (IndexOutOfBoundsException &ex) {
        assertEquals("fromIndex: 20 > toIndex: 10", ex.getMessage().toString());
    }

    // Reset bitSet.
    bitSet2.clear();

    // Set on a large range.
    bitSet2.set(0, 1024, true);
    assertEquals(1024, bitSet2.length());
    assertEquals(true, bitSet2.get(0));
    assertEquals(true, bitSet2.get(512));
    assertEquals(true, bitSet2.get(1023));
    assertEquals(false, bitSet2.get(1024));
    bitSet2.set(512, 1024, false);
    assertEquals(true, bitSet2.get(0));
    assertEquals(false, bitSet2.get(512));
    assertEquals(false, bitSet2.get(1023));
    assertEquals(false, bitSet2.get(1024));
}

TEST(JavaUtil, BitSetSize) {
    BitSet defaultBitSet;
    assertEquals(64, defaultBitSet.size());
    BitSet initialSizeBitSet(100);
    assertEquals(128, initialSizeBitSet.size());
}

TEST(JavaUtil, BitSetToString) {
    BitSet bitSet;
    assertEquals("{}", bitSet.toString());
    bitSet.set(2);
    assertEquals("{2}", bitSet.toString());
    bitSet.set(4);
    bitSet.set(10);
    assertEquals("{2, 4, 10}", bitSet.toString());
    bitSet.set(16384);
    assertEquals("{2, 4, 10, 16384}", bitSet.toString());
    bitSet.clear();
    assertEquals("{}", bitSet.toString());
}

TEST(JavaUtil, BitSetToByteArray) {
    BitSet bitSet;
    Array<byte> expectedResultByteArray = Array<byte>(0);
    Array<byte> resultByteArray = bitSet.toByteArray();
    assertTrue(Arrays::equals(expectedResultByteArray, resultByteArray));

    bitSet.set(0, 8, false);
    bitSet.set(8, 16, true);

    expectedResultByteArray = Array<byte> {0b00000000, 0b11111111};
    resultByteArray = bitSet.toByteArray();
    assertEquals(2, resultByteArray.length);
    assertTrue(Arrays::equals(expectedResultByteArray, resultByteArray));

    bitSet.clear();
    bitSet.set(0, 4, true);
    bitSet.set(4, 128, false);
    bitSet.set(128, 254, true);
    bitSet.set(254, 255, false);
    bitSet.set(255, 256, true);
    assertEquals(256, bitSet.length());
    assertEquals(256, bitSet.size());
    expectedResultByteArray = Array<byte>
            {0b00001111, 0b00000000, 0b00000000, 0b00000000,
             0b00000000, 0b00000000, 0b00000000, 0b00000000,
             0b00000000, 0b00000000, 0b00000000, 0b00000000,
             0b00000000, 0b00000000, 0b00000000, 0b00000000,
             0b11111111, 0b11111111, 0b11111111, 0b11111111,
             0b11111111, 0b11111111, 0b11111111, 0b11111111,
             0b11111111, 0b11111111, 0b11111111, 0b11111111,
             0b11111111, 0b11111111, 0b11111111, 0b10111111};
    resultByteArray = bitSet.toByteArray();
    assertEquals(32, expectedResultByteArray.length);
    assertEquals(32, resultByteArray.length);
    assertTrue(Arrays::equals(expectedResultByteArray, resultByteArray));
}

TEST(JavaUtil, BitSetToLongArray) {
    BitSet bitSet;
    Array<long> expectedResultLongArray = Array<long>(0);
    Array<long> resultLongArray = bitSet.toLongArray();
    assertTrue(Arrays::equals(expectedResultLongArray, resultLongArray));

    bitSet.set(0, 128, false);
    bitSet.set(128, 254, true);
    bitSet.set(254, 255, false);
    bitSet.set(255, 256, true);
    // -1L = 0xffffffffffffffffL
    // This test is checked on Java.
    expectedResultLongArray = Array<long> {0L, 0L, -1L, -4611686018427387905L};
    resultLongArray = bitSet.toLongArray();
    assertTrue(Arrays::equals(expectedResultLongArray, resultLongArray));
}

TEST(JavaUtil, BitSetValueOf) {
    // This input byte array has 4 zero bytes, it doesn't affect to result.
    Array<byte> inputByteArray = Array<byte>
            {0b00001111, 0b00000000, 0b00000000, 0b00000000,
             0b00000000, 0b00000000, 0b00000000, 0b00000000,
             0b00000000, 0b00000000, 0b00000000, 0b00000000,
             0b00000000, 0b00000000, 0b00000000, 0b00000000,
             0b11111111, 0b11111111, 0b11111111, 0b11111111,
             0b11111111, 0b11111111, 0b11111111, 0b11111111,
             0b11111111, 0b11111111, 0b11111111, 0b11111111,
             0b11111111, 0b11111111, 0b11111111, 0b10111111,
             0b00000000, 0b00000000, 0b00000000, 0b00000000};
    BitSet expectedResultByteArray;
    expectedResultByteArray.set(0, 4, true);
    expectedResultByteArray.set(4, 128, false);
    expectedResultByteArray.set(128, 254, true);
    expectedResultByteArray.set(254, 255, false);
    expectedResultByteArray.set(255, 256, true);
    BitSet resultByteArray = BitSet::valueOf(inputByteArray);
    assertTrue(expectedResultByteArray.equals(resultByteArray));

    // This input byte array has 4 zero longs, it doesn't affect to result.
    Array<long> inputLongArray =
            Array<long> {0L, 0L, -1L, -4611686018427387905L, 0L, 0L, 0L, 0L};
    BitSet expectedResultLongArray;
    expectedResultLongArray.set(0, 128, false);
    expectedResultLongArray.set(128, 254, true);
    expectedResultLongArray.set(254, 255, false);
    expectedResultLongArray.set(255, 256, true);
    BitSet resultLongArray = BitSet::valueOf(inputLongArray);
    assertTrue(expectedResultLongArray.equals(resultLongArray));
}

TEST(JavaUtil, BitSetCompareEqualsOperator) {
    BitSet bitSet1;
    BitSet bitSet2;
    assertTrue(bitSet1 == bitSet2);
    bitSet1.set(1);
    assertTrue(bitSet1 != bitSet2);
}

TEST(JavaUtil, BitSetAssignmentOperator) {
    BitSet bitSet1;
    bitSet1.set(0, 1024, true);
    assertEquals(1024, bitSet1.length());
    assertEquals(true, bitSet1.get(512));

    BitSet bitSet2;
    bitSet2.set(5000, true);
    bitSet2 = bitSet1;
    assertEquals(1024, bitSet2.length());
    assertEquals(true, bitSet2.get(512));
    assertTrue(bitSet1.equals(bitSet2));
}

TEST(JavaUtil, BitSetAnd) {
    BitSet bitSet1;
    bitSet1.set(0, 8, true);
    BitSet bitSet2;
    bitSet2.set(0, 8, true);
    // bitSet1 == bitSet2, nothing will be changed.
    bitSet1.bitAnd(bitSet2);
    assertEquals(8, bitSet1.length());
    assertEquals(8, bitSet2.length());
    assertEquals(true, bitSet1.get(0));
    assertEquals(true, bitSet2.get(0));
    assertEquals(true, bitSet1.get(7));
    assertEquals(true, bitSet2.get(7));

    bitSet2.set(4, false);
    bitSet1.set(0, 128, true);
    assertEquals(128, bitSet1.length());
    bitSet1.bitAnd(bitSet2);
    assertEquals(8, bitSet1.length());
    assertEquals(true, bitSet1.get(0));
    assertEquals(true, bitSet1.get(7));
    assertEquals(false, bitSet1.get(128));
    assertEquals(false, bitSet1.get(127));
    assertEquals(false, bitSet1.get(64));
    assertEquals(false, bitSet1.get(4));
}

TEST(JavaUtil, BitSetOr) {
    BitSet bitSet1;
    BitSet bitSet2;
    bitSet1.bitOr(bitSet2);
    // bitSet1 == bitSet2, nothing will be changed.
    assertTrue(bitSet1.equals(bitSet2));

    bitSet1.set(0, 512, false);
    bitSet1.set(512, 1024, true);
    bitSet2.set(0, 2048, true);
    bitSet1.bitOr(bitSet2);
    assertEquals(2048, bitSet1.length());
    assertEquals(2048, bitSet1.cardinality());
}

TEST(JavaUtil, BitSetXor) {
    BitSet bitSet1;
    BitSet bitSet2;
    bitSet1.set(0, 1024, true);
    bitSet2.set(0, 2048, true);

    bitSet1.bitXor(bitSet2);
    assertEquals(2048, bitSet1.length());
    assertEquals(1024, bitSet1.cardinality());
    assertEquals(false, bitSet1.get(0));
    assertEquals(false, bitSet1.get(1023));
    assertEquals(true, bitSet1.get(1024));
    assertEquals(true, bitSet1.get(2047));
}

TEST(JavaUtil, BitSetAndNot) {
    BitSet bitSet1;
    BitSet bitSet2;
    bitSet1.set(0, 1024, true);
    bitSet1.andNot(bitSet2);
    assertEquals(1024, bitSet1.length());
    assertEquals(true, bitSet1.get(0));
    assertEquals(true, bitSet1.get(1023));

    bitSet2.set(0, 1024, true);
    bitSet1.andNot(bitSet2);
    assertEquals(0, bitSet1.length());
}
