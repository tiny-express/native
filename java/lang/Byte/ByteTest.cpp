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
    Byte defaultConstructorByte;
    int expectResult = 0;
    int actualByteValue = defaultConstructorByte.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("0", defaultConstructorByte.toString());

	Byte byteConstructorByte = Byte(3);
    expectResult = 3;
    actualByteValue = byteConstructorByte.intValue();
	assertEquals(expectResult, actualByteValue);
    assertEquals("3", byteConstructorByte.toString());


    // Constructor with String
    Byte stringConstructorByte = Byte("3");
    actualByteValue = stringConstructorByte.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", stringConstructorByte.toString());

    // Copy constructor
    Byte copyConstructorByte = Byte(stringConstructorByte);
    actualByteValue = copyConstructorByte.intValue();
    assertEquals(expectResult, actualByteValue);
    assertEquals("3", copyConstructorByte.toString());

    try {
        Byte exceptionByte = Byte("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteCharValue) {
    // Given a char and a Byte with the same value to compare the result of charValue()
    Byte byteToGetValue = 'a';
    char expectResult = 'a';
    char actualResult = byteToGetValue.charValue();
    assertEquals(expectResult,actualResult);
}

TEST(JavaLang, ByteByteValue) {
    // Given a byte and a Byte with the same value to compare the result of charValue()
    Byte byteToGetValue = 5;
    byte expectResult = 5;
    byte actualResult = byteToGetValue.byteValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteCompareTo) {
    // Given 3 Byte
    Byte firstByte = 1;
    Byte secondByte = 1;
    Byte thirdByte = 3;

    // Compare
    assertEquals(0, firstByte.compareTo(secondByte));
    assertTrue(firstByte.compareTo(thirdByte) < 0);
    assertTrue(thirdByte.compareTo(firstByte) > 0);

    Comparable<Byte> *comparable = &secondByte;
    assertEquals(0, comparable->compareTo(firstByte));
}

TEST(JavaLang, ByteDecode) {
    // Given a decimal value are decode and assigned to decByte
    Byte decByte = Byte::decode("100");
    byte expectDecResult = 100;
    byte actualDecResult = decByte.byteValue();
    assertEquals(expectDecResult, actualDecResult);

    // Given a hexadecimal values are decoded and assigned to hexByte
    Byte hexByte = Byte::decode("0x6b");
    byte expectHexResult = 107;
    byte actualHexResult = hexByte.byteValue();
    assertEquals(expectHexResult, actualHexResult);

    // Given an octal value is decoded and assigned to octalByte
    Byte octalByte = Byte::decode("0127");
    byte expectOctalResult = 87;
    byte actualOctalResult = octalByte.byteValue();
    assertEquals(expectOctalResult, actualOctalResult);

    try {
        Byte exceptionByte = Byte::decode("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::decode("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::decode("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::decode("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteDoubleValue) {
    // Given a Double and a Byte with the same value
    Byte byteToGetValue = 5;
    double expectResult = 5;
    double actualResult = byteToGetValue.doubleValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteByteEquals) {
    // Given 3 Byte
    Byte firstByte = 1;
    Byte secondByte = 1;
    Byte thirdByte = 3;

    assertTrue(firstByte.equals(secondByte));
    assertFalse(firstByte.equals(thirdByte));
    /*// Test Byte and Object
    Object object;
    assertFalse(firstByte.equals(object));*/
}

TEST(JavaLang, ByteFloatValue) {
    // Given a float and a Byte with the same value
    Byte byteToGetValue = 5;
    float expectResult = 5;
    float actualResult = byteToGetValue.floatValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteHashCode ) {
    // Given a Byte
    Byte byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.hashCode();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteIntValue) {
    // Given a int and a Byte with the same value
    Byte byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = byteToGetValue.intValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteLongValue) {
    // Given a int and a Byte with the same value
    Byte byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.longValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteParseByte) {
    // Assign value 20 to resultByte from a String using parseByte
    byte expectResult = 20;
    byte actualResult = Byte::parseByte("20");
    // need parseByte(string)
    assertEquals(expectResult, actualResult);

    try {
        Byte exceptionByte = Byte::parseByte("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::parseByte("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::parseByte("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::parseByte("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteParseByteWithRadix) {

    // Assign value 20 to resultByte from a String using parseByte with radix =10
    byte expectResult = 20;
    byte actualResult = Byte::parseByte("+20", 10);
    assertEquals(expectResult, actualResult);

    expectResult = 0;
    actualResult = Byte::parseByte("0", 15);
    assertEquals(expectResult, actualResult);

    expectResult = 255;
    actualResult = Byte::parseByte("FF", 16);
    assertEquals(expectResult, actualResult);

    expectResult = 102;
    actualResult = Byte::parseByte("1100110", 2);
    assertEquals(expectResult, actualResult);

    try {
        expectResult = Byte::parseByte((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        expectResult = Byte::parseByte((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage().toString());
    }

    try {
        expectResult = Byte::parseByte((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::parseByte("256", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteShortValue) {
    // Given a short and a Byte with the same value
    Byte byteToGetValue = 5;
    short expectResult = 5;
    short actualResult = byteToGetValue.shortValue();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteToString) {
    // Given a string and a Byte with the same value
    Byte byteToGetValue = 2;
    string expectResult = (string) "2";
    string actualResult = byteToGetValue.toString();
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteToStringWithByte) {
    // Given a string and a Byte with the same value
    byte byteToRepresent = 2;
    String expectResult = "2";
    String actualResult = Byte::toString(byteToRepresent);
    assertEquals(expectResult.toString(), actualResult.toString());
}

TEST(JavaLang, ByteValueOfByte) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    byte byteToGetValue = 50;
    Byte expectResult = Byte(50);
    Byte actualResult = Byte::valueOf(byteToGetValue);
    assertEquals(expectResult.intValue(), actualResult.intValue());
}

TEST(JavaLang, ByteValueOfString) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String stringToGetValue = "50";
    Byte expectResult = Byte(static_cast<byte>(50));
    Byte actualResult = Byte::valueOf(stringToGetValue);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    try {
        Byte exceptionByte = Byte::valueOf("");
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::valueOf("abcd");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::valueOf("999999999999");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::valueOf("256");
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteValueOfStringWithRadix) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String byteToGetValue = "50";
    Byte expectResult = Byte(50);
    Byte actualResult = Byte::valueOf(byteToGetValue, 10);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    expectResult = 0;
    actualResult = Byte::valueOf("0", 15);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    expectResult = 255;
    actualResult = Byte::valueOf("FF", 16);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    expectResult = 102;
    actualResult = Byte::valueOf("1100110", 2);
    assertEquals(expectResult.intValue(), actualResult.intValue());

    try {
        expectResult = Byte::valueOf((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage().toString());
    }

    try {
        expectResult = Byte::valueOf((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage().toString());
    }

    try {
        expectResult = Byte::valueOf((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage().toString());
    }

    try {
        Byte exceptionByte = Byte::valueOf("256", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteHashCodeWithByte) {
    byte byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = Byte::hashCode(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteCompare) {
    byte byte1 = 5;
    byte byte2 = 10;
    byte byte3 = 5;
    // Return a value < 0 if a < b
    assertTrue(Byte::compare(byte1, byte2) < 0);
    // Return a value > 0 if a > b
    assertTrue(Byte::compare(byte2, byte1) > 0);
    // Return a value = 0 if a < b
    assertEquals(0, Byte::compare(byte1, byte3));
}

TEST(JavaLang, ByteToUnsignedInt) {
    byte byteToGetValue = static_cast<byte>(-5);
    int expectResult = 251;
    int actualResult = Byte::toUnsignedInt(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteToUnsignedLong) {
    byte byteToGetValue = static_cast<byte>(-5);
    long expectResult = 251;
    long actualResult = Byte::toUnsignedLong(byteToGetValue);
    assertEquals(expectResult, actualResult);
}

TEST(JavaLang, ByteByteOperator) {
	// Given a valid number
	Byte validByte = 5;
	Byte targetByte = 3;
    Byte equalValidByte = 5;
    Byte zeroByte = 0;
	
	// Make a summation with targetByte
	Byte summationByte = 8;
	assertTrue(summationByte == (validByte + targetByte));
	
	// Make a subtraction with targetByte
	Byte subtractionByte = 2;
	assertTrue(subtractionByte == (validByte - targetByte));
	
	// Make a multiplication with targetByte
	Byte multiplicationByte = 15;
	assertTrue(multiplicationByte == (validByte * targetByte));
	
	// Make a division with targetByte
	Byte divisionByte = 1;
	assertTrue(divisionByte == (validByte / targetByte));

    try {
        divisionByte = validByte / zeroByte;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage().toString());
    }
	
	// Make a modulo with targetByte
	Byte modulusByte = 2;
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




