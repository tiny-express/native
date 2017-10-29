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

#include "../../../kernel/Test.hpp"
#include "Bytes.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST (JavaLangByte, Constructor) {
    // Given empty value for Bytes constructor and assign value - Return Byte
    Bytes defaultConstructorBytes;
    int expectResult = 0;
    int actualByteValue = defaultConstructorBytes.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("0", defaultConstructorBytes.toString());
    
    Bytes byteConstructorBytes = Bytes(3);
    expectResult = 3;
    actualByteValue = byteConstructorBytes.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", byteConstructorBytes.toString());
    
    // Constructor with String
    Bytes stringConstructorBytes = Bytes("3");
    actualByteValue = stringConstructorBytes.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", stringConstructorBytes.toString());

    // Copy constructor
    Bytes copyConstructorBytes = Bytes(stringConstructorBytes);
    actualByteValue = copyConstructorBytes.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", copyConstructorBytes.toString());

    try {
        Bytes exceptionBytes = Bytes("");
    } catch (NumberFormatException &e) {
        assertEquals(String("input string is null"), e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST (JavaLangByte, CharValue) {
    // Given a char and a Bytes with the same value to compare the result of charValue()
    Bytes byteToGetValue = 'a';
    char expectResult = 'a';
    char actualResult = byteToGetValue.charValue();
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, ByteValue) {
    // Given a byte and a Bytes with the same value to compare the result of charValue()
    Bytes byteToGetValue = 5;
    byte expectResult = 5;
    byte actualResult = byteToGetValue.byteValue();
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, CompareTo) {
    // Given 3 Byte
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    // Compare
    assertEquals(0, firstBytes.compareTo(secondBytes));
    assertTrue(firstBytes.compareTo(thirdBytes) < 0);
    assertTrue(thirdBytes.compareTo(firstBytes) > 0);

    Comparable<Bytes> *comparable = &secondBytes;
    assertEquals(0, comparable->compareTo(firstBytes));
}

TEST (JavaLangByte, Decode) {
    // Given a decimal value are decode and assigned to decByte
    Bytes decBytes = Bytes::decode("100");
    byte expectDecResult = 100;
    byte actualDecResult = decBytes.byteValue();
    assertEquals(expectDecResult, actualDecResult);

    // Given a hexadecimal values are decoded and assigned to hexByte
    Bytes hexBytes = Bytes::decode("0x6b");
    byte expectHexResult = 107;
    byte actualHexResult = hexBytes.byteValue();
    assertEquals(expectHexResult, actualHexResult);

    // Given an octal value is decoded and assigned to octalByte
    Bytes octalBytes = Bytes::decode("0127");
    byte expectOctalResult = 87;
    byte actualOctalResult = octalBytes.byteValue();
    assertEquals(expectOctalResult, actualOctalResult);

    try {
        Bytes exceptionBytes = Bytes::decode("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes::decode("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes::decode("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes::decode("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST (JavaLangByte, DoubleValue) {
    // Given a Double and a Bytes with the same value
    Bytes byteToGetValue = 5;
    double expectResult = 5;
    double actualResult = byteToGetValue.doubleValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLangByte, Equals) {
    // Given 3 Byte
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    assertTrue(firstBytes.equals(secondBytes));
    assertFalse(firstBytes.equals(thirdBytes));
}

TEST (JavaLangByte, FloatValue) {
    // Given a float and a Bytes with the same value
    Bytes byteToGetValue = 5;
    float expectResult = 5;
    float actualResult = byteToGetValue.floatValue();
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, HashCode) {
// Given a Byte
//    Bytes byteToGetValue = 5;
//    long expectResult = 5;
//    long actualResult = byteToGetValue.hashCode();
//    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, IntValue) {
    // Given a int and a Bytes with the same value
    Bytes byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = byteToGetValue.intValue();
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, LongValue) {
    // Given a int and a Bytes with the same value
    Bytes byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.longValue();
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, ParseBytes) {
    // Assign value 20 to resultBytes from a String using parseByte
    byte expectResult = 20;
    byte actualResult = Bytes::parseBytes("20");
    // need parseBytes(string)
    assertEquals(expectResult, actualResult);

    try {
        Bytes exceptionBytes = Bytes::parseBytes("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes::parseBytes("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes::parseBytes("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionBytes = Bytes::parseBytes("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST (JavaLangByte, ParseByteWithRadix) {

    // Assign value 20 to resultBytes from a String using parseBytes with radix =10
    byte expectResult = 20;
    byte actualResult = Bytes::parseBytes("+20", 10);
    assertEquals(expectResult, actualResult);

    expectResult = 0;
    actualResult = Bytes::parseBytes("0", 15);
    assertEquals(expectResult, actualResult);

    expectResult = 255;
    actualResult = Bytes::parseBytes("FF", 16);
    assertEquals(expectResult, actualResult);

    expectResult = 102;
    actualResult = Bytes::parseBytes("1100110", 2);
    assertEquals(expectResult, actualResult);

    try {
        Bytes::parseBytes((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes::parseBytes((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage().toString());
    }

    try {
        Bytes::parseBytes((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes::parseBytes("256", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST (JavaLangByte, ShortValue) {
    // Given a short and a Bytes with the same value
    Bytes byteToGetValue = 5;
    short expectResult = 5;
    short actualResult = byteToGetValue.shortValue();
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, ToString) {
    // Given a string and a Bytes with the same value
    Bytes byteToGetValue = 2;
    String expectResult = "2";
    assertEquals(expectResult, byteToGetValue.toString());
}

TEST (JavaLangByte, ToStringWithBytes) {
    // Given a string and a Bytes with the same value
    byte byteToRepresent = 2;
    String expectResult = "2";
    String actualResult = Bytes::toString(byteToRepresent);
    assertEquals(expectResult.toString(), actualResult.toString());
}

TEST (JavaLangByte, ValueOfBytes) {
    // Given a byte and a Byte, then assign value to Bytes using valueOf(byte)
    byte byteToGetValue = 50;
    Bytes expectResult = Bytes(50);
    Bytes actualResult = Bytes::valueOf(byteToGetValue);
    assertEquals(expectResult.intValue(), actualResult.intValue());
}

TEST (JavaLangByte, ValueOfString) {
    // Given a byte and a Byte, then assign value to Bytes using valueOf(byte)
    String stringToGetValue = "50";
    Bytes expectResult = Bytes(static_cast<byte>(50));
    Bytes actualResult = Bytes::valueOf(stringToGetValue);
    assertEquals(expectResult.intValue(), actualResult.intValue());
    
    try {
        Bytes::valueOf("");
    } catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes::valueOf("abcd");
    } catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes::valueOf("256");
    } catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST (JavaLangByte, ValueOfStringWithRadix) {
    // Given a byte and a Byte, then assign value to Bytes using valueOf(byte)
    String byteToGetValue = "50";
    Bytes expectResult = Bytes(50);
    Bytes actualResult = Bytes::valueOf(byteToGetValue, 10);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    expectResult = 0;
    actualResult = Bytes::valueOf("0", 15);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    expectResult = 255;
    actualResult = Bytes::valueOf("FF", 16);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    expectResult = 102;
    actualResult = Bytes::valueOf("1100110", 2);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    try {
        expectResult = Bytes::valueOf((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes::valueOf((String) "Kona", 33);
    } catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage().toString());
    }

    try {
        Bytes::valueOf((String) "", 2);
    } catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes::valueOf("256", 10);
    } catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST (JavaLangByte, HashCodeWithBytes) {
    byte byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = Bytes::hashCode(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, Compare) {
    byte byte1 = 5;
    byte byte2 = 10;
    byte byte3 = 5;
    // Return a value < 0 if a < b
    assertTrue(Bytes::compare(byte1, byte2) < 0);
    // Return a value > 0 if a > b
    assertTrue(Bytes::compare(byte2, byte1) > 0);
    // Return a value = 0 if a < b
    assertEquals(0, Bytes::compare(byte1, byte3));
}

TEST (JavaLangByte, ToUnsignedInt) {
    auto byteToGetValue = static_cast<byte>(-5);
    int expectResult = 251;
    int actualResult = Bytes::toUnsignedInt(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, ToUnsignedLong) {
    auto byteToGetValue = static_cast<byte>(-5);
    long expectResult = 251;
    long actualResult = Bytes::toUnsignedLong(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST (JavaLangByte, ByteOperator) {
    // Given a valid number
    Bytes validBytes = 5;
    Bytes targetBytes = 3;
    Bytes equalValidBytes = 5;
    Bytes zeroBytes = 0;

    // Make a summation with targetByte
    Bytes summationBytes = 8;
    assertTrue(summationBytes == (validBytes + targetBytes));

    // Make a subtraction with targetByte
    Bytes subtractionBytes = 2;
    assertTrue(subtractionBytes == (validBytes - targetBytes));

    // Make a multiplication with targetByte
    Bytes multiplicationBytes = 15;
    assertTrue(multiplicationBytes == (validBytes * targetBytes));

    // Make a division with targetByte
    Bytes divisionBytes = 1;
    assertTrue(divisionBytes == (validBytes / targetBytes));

    try {
        divisionBytes = validBytes / zeroBytes;
    } catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }

    // Make a modulo with targetByte
    Bytes modulusBytes = 2;
    assertTrue(modulusBytes == (validBytes % targetBytes));

    try {
        modulusBytes = validBytes % zeroBytes;
    } catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }

    // Determine if 2 byte is equal
    assertTrue(validBytes == equalValidBytes);
    assertFalse(validBytes == targetBytes);
    assertTrue(validBytes != targetBytes);
    assertFalse(validBytes != equalValidBytes);

    // Determine if validBytes is bigger than targetByte
    assertTrue(validBytes > targetBytes);
    assertFalse(targetBytes > validBytes);

    // Determine if validBytes is smaller than targetByte
    assertTrue(targetBytes < validBytes);
    assertFalse(validBytes < targetBytes);

    // Determine if validBytes is bigger than targetByte
    assertTrue(validBytes >= targetBytes);
    assertTrue(validBytes >= equalValidBytes);
    assertFalse(targetBytes >= validBytes);

    // Determine if validBytes is bigger than targetByte
    assertTrue(targetBytes <= validBytes);
    assertTrue(validBytes <= equalValidBytes);
    assertFalse(validBytes <= targetBytes);

    // Make a summation from validBytes with targetBytes and assign the result value to this Byte
    validBytes += targetBytes;
    assertEquals(summationBytes.intValue(), validBytes.intValue());
    assertEquals(summationBytes.toString(), validBytes.toString());
    validBytes = 5;

    // Make a subtraction from validBytes with targetBytes and assign the result value to this Byte
    validBytes -= targetBytes;
    assertEquals(subtractionBytes.intValue(), validBytes.intValue());
    assertEquals(subtractionBytes.toString(), validBytes.toString());

    validBytes = 5;

    // Make a multiplication from validBytes with targetBytes and assign the result value to this Byte
    validBytes *= targetBytes;
    assertEquals(multiplicationBytes.intValue(), validBytes.intValue());
    assertEquals(multiplicationBytes.toString(), validBytes.toString());
    validBytes = 5;

    // Make a division from validBytes with targetBytes and assign the result value to this Byte
    validBytes /= targetBytes;
    assertEquals(validBytes.intValue(), validBytes.intValue());
    assertEquals(divisionBytes.toString(), validBytes.toString());
    validBytes = 5;

    try {
        validBytes /= zeroBytes;
    } catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }

    // Make a modulo from validBytes with targetBytes and assign the result value to this Byte
    validBytes %= targetBytes;
    assertEquals(modulusBytes.intValue(), validBytes.intValue());
    assertEquals(modulusBytes.toString(), validBytes.toString());
    validBytes = 5;

    try {
        validBytes %= zeroBytes;
    } catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }
}




