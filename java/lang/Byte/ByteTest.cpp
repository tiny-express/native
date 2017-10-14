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
#include "Byte.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST(JavaLang, ByteConstructor) {
	// Given empty value for Byte constructor and assign value - Return Byte
    Bytes defaultConstructorByte;
    int expectResult = 0;
    int actualByteValue = defaultConstructorByte.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("0", defaultConstructorByte.toString());

	Bytes byteConstructorByte = Bytes(3);
    expectResult = 3;
    actualByteValue = byteConstructorByte.intValue();
	assertEquals(expectResult, actualByteValue);
    assertEquals("3", byteConstructorByte.toString());


    // Constructor with String
    Bytes stringConstructorByte = Bytes("3");
    actualByteValue = stringConstructorByte.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", stringConstructorByte.toString());

    // Copy constructor
    Bytes copyConstructorByte = Bytes(stringConstructorByte);
    actualByteValue = copyConstructorByte.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", copyConstructorByte.toString());

    try {
        Bytes exceptionByte = Bytes("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteCharValue) {
    // Given a char and a Byte with the same value to compare the result of charValue()
    Bytes byteToGetValue = 'a';
    char expectResult = 'a';
    char actualResult = byteToGetValue.charValue();
    assertEquals(expectResult,actualResult);
}

TEST(JavaLang, ByteByteValue) {
    // Given a byte and a Byte with the same value to compare the result of charValue()
    Bytes byteToGetValue = 5;
    byte expectResult = 5;
    byte actualResult = byteToGetValue.byteValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteCompareTo) {
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

TEST(JavaLang, ByteDecode) {
    // Given a decimal value are decode and assigned to decByte
    Bytes decByte = Bytes::decode("100");
    byte expectDecResult = 100;
    byte actualDecResult = decByte.byteValue();
    assertEquals(expectDecResult, actualDecResult);

    // Given a hexadecimal values are decoded and assigned to hexByte
    Bytes hexByte = Bytes::decode("0x6b");
    byte expectHexResult = 107;
    byte actualHexResult = hexByte.byteValue();
    assertEquals(expectHexResult, actualHexResult);

    // Given an octal value is decoded and assigned to octalByte
    Bytes octalByte = Bytes::decode("0127");
    byte expectOctalResult = 87;
    byte actualOctalResult = octalByte.byteValue();
    assertEquals(expectOctalResult, actualOctalResult);

    try {
        Bytes exceptionByte = Bytes::decode("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::decode("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::decode("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::decode("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteDoubleValue) {
    // Given a Double and a Byte with the same value
    Bytes byteToGetValue = 5;
    double expectResult = 5;
    double actualResult = byteToGetValue.doubleValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteByteEquals) {
    // Given 3 Bytes
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    assertTrue(firstBytes.equals(secondBytes));
    assertFalse(firstBytes.equals(thirdBytes));
    /*// Test Bytes and Object
    Object object;
    assertFalse(firstBytes.equals(object));*/
}

TEST(JavaLang, ByteFloatValue) {
    // Given a float and a Byte with the same value
    Bytes byteToGetValue = 5;
    float expectResult = 5;
    float actualResult = byteToGetValue.floatValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteHashCode ) {
    // Given a Byte
    Bytes byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.hashCode();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteIntValue) {
    // Given a int and a Byte with the same value
    Bytes byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = byteToGetValue.intValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteLongValue) {
    // Given a int and a Byte with the same value
    Bytes byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.longValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteParseByte) {
    // Assign value 20 to resultByte from a String using parseByte
    byte expectResult = 20;
    byte actualResult = Bytes::parseByte("20");
    // need parseByte(string)
    assertEquals(expectResult, actualResult);

    try {
        Bytes exceptionByte = Bytes::parseByte("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteParseByteWithRadix) {

    // Assign value 20 to resultByte from a String using parseByte with radix =10
    byte expectResult = 20;
    byte actualResult = Bytes::parseByte("+20", 10);
    assertEquals(expectResult, actualResult);

    expectResult = 0;
    actualResult = Bytes::parseByte("0", 15);
    assertEquals(expectResult, actualResult);

    expectResult = 255;
    actualResult = Bytes::parseByte("FF", 16);
    assertEquals(expectResult, actualResult);

    expectResult = 102;
    actualResult = Bytes::parseByte("1100110", 2);
    assertEquals(expectResult, actualResult);

    try {
        expectResult = Bytes::parseByte((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::parseByte((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::parseByte((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("256", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteShortValue) {
    // Given a short and a Byte with the same value
    Bytes byteToGetValue = 5;
    short expectResult = 5;
    short actualResult = byteToGetValue.shortValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteToString) {
    // Given a string and a Byte with the same value
    Bytes byteToGetValue = 2;
    string expectResult = (string) "2";
    string actualResult = byteToGetValue.toString();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteToStringWithByte) {
    // Given a string and a Byte with the same value
    byte byteToRepresent = 2;
    String expectResult = "2";
    String actualResult = Bytes::toString(byteToRepresent);
    assertEquals(expectResult.toString(), actualResult.toString());
}

TEST(JavaLang, ByteValueOfByte) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    byte byteToGetValue = 50;
    Bytes expectResult = Bytes(50);
    Bytes actualResult = Bytes::valueOf(byteToGetValue);
    assertEquals(expectResult.intValue(), actualResult.intValue());
}

TEST(JavaLang, ByteValueOfString) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String stringToGetValue = "50";
    Bytes expectResult = Bytes(static_cast<byte>(50));
    Bytes actualResult = Bytes::valueOf(stringToGetValue);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    try {
        Bytes exceptionByte = Bytes::valueOf("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteValueOfStringWithRadix) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
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
        expectResult = Bytes::valueOf((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::valueOf((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("256", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteHashCodeWithByte) {
    byte byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = Bytes::hashCode(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteCompare) {
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

TEST(JavaLang, ByteToUnsignedInt) {
    byte byteToGetValue = static_cast<byte>(-5);
    int expectResult = 251;
    int actualResult = Bytes::toUnsignedInt(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteToUnsignedLong) {
    byte byteToGetValue = static_cast<byte>(-5);
    long expectResult = 251;
    long actualResult = Bytes::toUnsignedLong(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteByteOperator) {
	// Given a valid number
	Bytes validByte = 5;
	Bytes targetByte = 3;
    Bytes equalValidByte = 5;
    Bytes zeroByte = 0;
	
	// Make a summation with targetByte
	Bytes summationByte = 8;
	assertTrue(summationByte == (validByte + targetByte));
	
	// Make a subtraction with targetByte
	Bytes subtractionByte = 2;
	assertTrue(subtractionByte == (validByte - targetByte));
	
	// Make a multiplication with targetByte
	Bytes multiplicationByte = 15;
	assertTrue(multiplicationByte == (validByte * targetByte));
	
	// Make a division with targetByte
	Bytes divisionByte = 1;
	assertTrue(divisionByte == (validByte / targetByte));

    try {
        divisionByte = validByte / zeroByte;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }
	
	// Make a modulo with targetByte
	Bytes modulusByte = 2;
	assertTrue(modulusByte == (validByte % targetByte));

    try {
        modulusByte = validByte % zeroByte;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }

    // Determine if 2 byte is equal
    assertTrue(validByte == equalValidByte);
    assertFalse(validByte == targetByte);
    assertTrue(validByte != targetByte);
    assertFalse(validByte != equalValidByte);

    // Determine if validByte is bigger than targetByte
    assertTrue(validByte > targetByte);
    assertFalse(targetByte > validByte);

    // Determine if validByte is smaller than targetByte
    assertTrue(targetByte < validByte);
    assertFalse(validByte < targetByte);

    // Determine if validByte is bigger than targetByte
    assertTrue(validByte >= targetByte);
    assertTrue(validByte >= equalValidByte);
    assertFalse(targetByte >= validByte);

    // Determine if validByte is bigger than targetByte
    assertTrue(targetByte <= validByte);
    assertTrue(validByte <= equalValidByte);
    assertFalse(validByte <= targetByte);

    // Make a summation from validByte with targetByte and assign the result value to this Byte
    validByte += targetByte;
    assertEquals(summationByte.intValue(), validByte.intValue());
    assertEquals(summationByte.toString(), validByte.toString());
    validByte = 5;

    // Make a subtraction from validByte with targetByte and assign the result value to this Byte
    validByte -= targetByte;
    assertEquals(subtractionByte.intValue(), validByte.intValue());
    assertEquals(subtractionByte.toString(), validByte.toString());

    validByte = 5;

    // Make a multiplication from validByte with targetByte and assign the result value to this Byte
    validByte *= targetByte;
    assertEquals(multiplicationByte.intValue(), validByte.intValue());
    assertEquals(multiplicationByte.toString(), validByte.toString());
    validByte = 5;

    // Make a division from validByte with targetByte and assign the result value to this Byte
    validByte /= targetByte;
    assertEquals(validByte.intValue(), validByte.intValue());
    assertEquals(divisionByte.toString(), validByte.toString());
    validByte = 5;

    try {
        validByte /= zeroByte;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }

    // Make a modulo from validByte with targetByte and assign the result value to this Byte
    validByte %= targetByte;
    assertEquals(modulusByte.intValue(), validByte.intValue());
    assertEquals(modulusByte.toString(), validByte.toString());
    validByte = 5;

    try {
        validByte %= zeroByte;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }
}




