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

#include "Byte.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"

using namespace Java::Lang;

TEST(JavaLang, ByteConstructor) {
	// Given empty value for Byte constructor and assign value - Return Byte
    Bytes defaultConstructorByte;
    int expectResult = 0;
    int actualByteValue = defaultConstructorByte.intValue();
    ASSERT_EQUAL(expectResult, actualByteValue);
    ASSERT_STR("0", defaultConstructorByte.toString().toString());

	Bytes byteConstructorByte = Bytes(3);
    expectResult = 3;
    actualByteValue = byteConstructorByte.intValue();
	ASSERT_EQUAL(expectResult, actualByteValue);
    ASSERT_STR("3", byteConstructorByte.toString().toString());


    // Constructor with String
    Bytes stringConstructorByte = Bytes("3");
    actualByteValue = stringConstructorByte.intValue();
    ASSERT_EQUAL(expectResult, actualByteValue);
    ASSERT_STR("3", stringConstructorByte.toString().toString());

    // Copy constructor
    Bytes copyConstructorByte = Bytes(stringConstructorByte);
    actualByteValue = copyConstructorByte.intValue();
    ASSERT_EQUAL(expectResult, actualByteValue);
    ASSERT_STR("3", copyConstructorByte.toString().toString());

    try {
        Bytes exceptionByte = Bytes("");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes("abcd");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes("999999999999");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes("256");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteCharValue) {
    // Given a char and a Byte with the same value to compare the result of charValue()
    Bytes byteToGetValue = 'a';
    char expectResult = 'a';
    char actualResult = byteToGetValue.charValue();
    ASSERT_EQUAL(expectResult,actualResult);
}

TEST(JavaLang, ByteByteValue) {
    // Given a byte and a Byte with the same value to compare the result of charValue()
    Bytes byteToGetValue = 5;
    byte expectResult = 5;
    byte actualResult = byteToGetValue.byteValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteCompareTo) {
    // Given 3 Byte
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    // Compare
    ASSERT_EQUAL(0, firstBytes.compareTo(secondBytes));
    ASSERT_TRUE(firstBytes.compareTo(thirdBytes) < 0);
    ASSERT_TRUE(thirdBytes.compareTo(firstBytes) > 0);

    Comparable<Bytes> *comparable = &secondBytes;
    ASSERT_EQUAL(0, comparable->compareTo(firstBytes));
}

TEST(JavaLang, ByteDecode) {
    // Given a decimal value are decode and assigned to decByte
    Bytes decByte = Bytes::decode("100");
    byte expectDecResult = 100;
    byte actualDecResult = decByte.byteValue();
    ASSERT_EQUAL(expectDecResult, actualDecResult);

    // Given a hexadecimal values are decoded and assigned to hexByte
    Bytes hexByte = Bytes::decode("0x6b");
    byte expectHexResult = 107;
    byte actualHexResult = hexByte.byteValue();
    ASSERT_EQUAL(expectHexResult, actualHexResult);

    // Given an octal value is decoded and assigned to octalByte
    Bytes octalByte = Bytes::decode("0127");
    byte expectOctalResult = 87;
    byte actualOctalResult = octalByte.byteValue();
    ASSERT_EQUAL(expectOctalResult, actualOctalResult);

    try {
        Bytes exceptionByte = Bytes::decode("");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::decode("abcd");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::decode("999999999999");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::decode("256");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteDoubleValue) {
    // Given a Double and a Byte with the same value
    Bytes byteToGetValue = 5;
    double expectResult = 5;
    double actualResult = byteToGetValue.doubleValue();
    ASSERT_DBL_NEAR(expectResult, actualResult);
}

TEST(JavaLang, ByteByteEquals) {
    // Given 3 Bytes
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    ASSERT_TRUE(firstBytes.equals(secondBytes));
    ASSERT_FALSE(firstBytes.equals(thirdBytes));
    /*// Test Bytes and Object
    Object object;
    ASSERT_FALSE(firstBytes.equals(object));*/
}

TEST(JavaLang, ByteFloatValue) {
    // Given a float and a Byte with the same value
    Bytes byteToGetValue = 5;
    float expectResult = 5;
    float actualResult = byteToGetValue.floatValue();
    ASSERT_DBL_NEAR(expectResult, actualResult);
}

TEST(JavaLang, ByteHashCode ) {
    // Given a Byte
    Bytes byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.hashCode();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteIntValue) {
    // Given a int and a Byte with the same value
    Bytes byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = byteToGetValue.intValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteLongValue) {
    // Given a int and a Byte with the same value
    Bytes byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.longValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteParseByte) {
    // Assign value 20 to resultByte from a String using parseByte
    byte expectResult = 20;
    byte actualResult = Bytes::parseByte("20");
    // need parseByte(string)
    ASSERT_EQUAL(expectResult, actualResult);

    try {
        Bytes exceptionByte = Bytes::parseByte("");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("abcd");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("999999999999");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("256");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteParseByteWithRadix) {

    // Assign value 20 to resultByte from a String using parseByte with radix =10
    byte expectResult = 20;
    byte actualResult = Bytes::parseByte("+20", 10);
    ASSERT_EQUAL(expectResult, actualResult);

    expectResult = 0;
    actualResult = Bytes::parseByte("0", 15);
    ASSERT_EQUAL(expectResult, actualResult);

    expectResult = 255;
    actualResult = Bytes::parseByte("FF", 16);
    ASSERT_EQUAL(expectResult, actualResult);

    expectResult = 102;
    actualResult = Bytes::parseByte("1100110", 2);
    ASSERT_EQUAL(expectResult, actualResult);

    try {
        expectResult = Bytes::parseByte((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::parseByte((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("radix out of range", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::parseByte((String) "", 2);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::parseByte("256", 10);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteShortValue) {
    // Given a short and a Byte with the same value
    Bytes byteToGetValue = 5;
    short expectResult = 5;
    short actualResult = byteToGetValue.shortValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteStringValue) {
    // Given a string and a Byte with the same value
    Bytes byteToGetValue = Bytes("100");
    string expectResult = (string) "100";
    string actualResult = byteToGetValue.stringValue();
    ASSERT_STR(expectResult, actualResult);
}

TEST(JavaLang, ByteToString) {
    // Given a string and a Byte with the same value
    Bytes byteToGetValue = 2;
    String expectResult = "2";
    String actualResult = byteToGetValue.toString();
    ASSERT_STR(expectResult.toString(), actualResult.toString());
}

TEST(JavaLang, ByteToStringWithByte) {
    // Given a string and a Byte with the same value
    byte byteToRepresent = 2;
    String expectResult = "2";
    String actualResult = Bytes::toString(byteToRepresent);
    ASSERT_STR(expectResult.toString(), actualResult.toString());
}

TEST(JavaLang, ByteValueOfByte) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    byte byteToGetValue = 50;
    Bytes expectResult = Bytes(50);
    Bytes actualResult = Bytes::valueOf(byteToGetValue);
    ASSERT_EQUAL(expectResult.intValue(), actualResult.intValue());
}

TEST(JavaLang, ByteValueOfString) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String stringToGetValue = "50";
    Bytes expectResult = Bytes(static_cast<byte>(50));
    Bytes actualResult = Bytes::valueOf(stringToGetValue);
    ASSERT_EQUAL(expectResult.intValue(), actualResult.intValue());

    try {
        Bytes exceptionByte = Bytes::valueOf("");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("abcd");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("999999999999");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Integer out of range", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("256");
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteValueOfStringWithRadix) {
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String byteToGetValue = "50";
    Bytes expectResult = Bytes(50);
    Bytes actualResult = Bytes::valueOf(byteToGetValue, 10);
    ASSERT_EQUAL(expectResult.intValue(), actualResult.intValue());

    expectResult = 0;
    actualResult = Bytes::valueOf("0", 15);
    ASSERT_EQUAL(expectResult.intValue(), actualResult.intValue());

    expectResult = 255;
    actualResult = Bytes::valueOf("FF", 16);
    ASSERT_EQUAL(expectResult.intValue(), actualResult.intValue());

    expectResult = 102;
    actualResult = Bytes::valueOf("1100110", 2);
    ASSERT_EQUAL(expectResult.intValue(), actualResult.intValue());

    try {
        expectResult = Bytes::valueOf((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("Not a number", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::valueOf((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("radix out of range", e.getMessage().toString());
    }

    try {
        expectResult = Bytes::valueOf((String) "", 2);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("input string is null", e.getMessage().toString());
    }

    try {
        Bytes exceptionByte = Bytes::valueOf("256", 10);
    }
    catch (NumberFormatException &e) {
        ASSERT_STR("out of byte range", e.getMessage().toString());
    }
}

TEST(JavaLang, ByteHashCodeWithByte) {
    byte byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = Bytes::hashCode(byteToGetValue);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteCompare) {
    byte byte1 = 5;
    byte byte2 = 10;
    byte byte3 = 5;
    // Return a value < 0 if a < b
    ASSERT_TRUE(Bytes::compare(byte1, byte2) < 0);
    // Return a value > 0 if a > b
    ASSERT_TRUE(Bytes::compare(byte2, byte1) > 0);
    // Return a value = 0 if a < b
    ASSERT_EQUAL(0, Bytes::compare(byte1, byte3));
}

TEST(JavaLang, ByteToUnsignedInt) {
    byte byteToGetValue = static_cast<byte>(-5);
    int expectResult = 251;
    int actualResult = Bytes::toUnsignedInt(byteToGetValue);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteToUnsignedLong) {
    byte byteToGetValue = static_cast<byte>(-5);
    long expectResult = 251;
    long actualResult = Bytes::toUnsignedLong(byteToGetValue);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteByteOperator) {
	// Given a valid number
	Bytes validByte = 5;
	Bytes targetByte = 3;
    Bytes equalValidByte = 5;
	
	// Make a summation with targetByte
	Bytes summationByte = 8;
	ASSERT_TRUE(summationByte == (validByte + targetByte));
	
	// Make a subtraction with targetByte
	Bytes subtractionByte = 2;
	ASSERT_TRUE(subtractionByte == (validByte - targetByte));
	
	// Make a multiplication with targetByte
	Bytes multiplicationByte = 15;
	ASSERT_TRUE(multiplicationByte == (validByte * targetByte));
	
	// Make a division with targetByte
	Bytes divisionByte = 1;
	ASSERT_TRUE(divisionByte == (validByte / targetByte));
	
	// Make a modulo with targetByte
	Bytes modByte = 2;
	ASSERT_TRUE(modByte == (validByte % targetByte));

    // Determine if 2 byte is equal
    ASSERT_TRUE(validByte == equalValidByte);
    ASSERT_FALSE(validByte == targetByte);
    ASSERT_TRUE(validByte != targetByte);
    ASSERT_FALSE(validByte != equalValidByte);

    // Determine if validByte is bigger than targetByte
    ASSERT_TRUE(validByte > targetByte);
    ASSERT_FALSE(targetByte > validByte);

    // Determine if validByte is smaller than targetByte
    ASSERT_TRUE(targetByte < validByte);
    ASSERT_FALSE(validByte < targetByte);

    // Determine if validByte is bigger than targetByte
    ASSERT_TRUE(validByte >= targetByte);
    ASSERT_TRUE(validByte >= equalValidByte);
    ASSERT_FALSE(targetByte >= validByte);

    // Determine if validByte is bigger than targetByte
    ASSERT_TRUE(targetByte <= validByte);
    ASSERT_TRUE(validByte <= equalValidByte);
    ASSERT_FALSE(validByte <= targetByte);

    // Make a summation from validByte with targetByte and assign the result value to this Byte
    validByte += targetByte;
    ASSERT_EQUAL(summationByte.intValue(), validByte.intValue());
    ASSERT_STR(summationByte.toString().toString(), validByte.toString().toString());
    validByte = 5;

    // Make a subtraction from validByte with targetByte and assign the result value to this Byte
    validByte -= targetByte;
    ASSERT_EQUAL(subtractionByte.intValue(), validByte.intValue());
    ASSERT_STR(subtractionByte.toString().toString(), validByte.toString().toString());

    validByte = 5;

    // Make a multiplication from validByte with targetByte and assign the result value to this Byte
    validByte *= targetByte;
    ASSERT_EQUAL(multiplicationByte.intValue(), validByte.intValue());
    ASSERT_STR(multiplicationByte.toString().toString(), validByte.toString().toString());
    validByte = 5;

    // Make a division from validByte with targetByte and assign the result value to this Byte
    validByte /= targetByte;
    ASSERT_EQUAL(divisionByte.intValue(), validByte.intValue());
    ASSERT_STR(divisionByte.toString().toString(), validByte.toString().toString());
    validByte = 5;

    // Make a modulo from validByte with targetByte and assign the result value to this Byte
    validByte %= targetByte;
    ASSERT_EQUAL(modByte.intValue(), validByte.intValue());
    ASSERT_STR(modByte.toString().toString(), validByte.toString().toString());
    validByte = 5;
}




