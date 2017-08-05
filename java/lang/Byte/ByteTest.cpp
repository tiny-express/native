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

#include "Byte.hpp"

using namespace Java::Lang;

TEST(JavaLang, ByteConstructor) {
	// Given empty value for Byte constructor and assign value - Return Byte
	Bytes byte1 = Bytes(3);
    int expectResult = 3;
    int actualResult = byte1.intValue();
	ASSERT_EQUAL(expectResult, actualResult);
    // need parseByte(string, int)
    /*Bytes byte2 = Bytes("3");
    int actualStringResult = byte2.intValue();
    ASSERT_EQUAL(expectResult, actualStringResult);*/

}

TEST(JavaLang, CharValue){
    // Given a char and a Byte with the same value to compare the result of charValue()
    Bytes byteToGetValue = 'a';
    char expectResult = 'a';
    char actualResult = byteToGetValue.charValue();
    ASSERT_EQUAL(expectResult,actualResult);
}

TEST(JavaLang, ByteValue){
    // Given a byte and a Byte with the same value to compare the result of charValue()
    Bytes byteToGetValue = 5;
    byte expectResult = 5;
    byte actualResult = byteToGetValue.byteValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, CompareTo){
    // Given 3 Byte
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    // Compare
    ASSERT_TRUE(firstBytes.compareTo(secondBytes)==0);
    ASSERT_TRUE(firstBytes.compareTo(thirdBytes)<0);
    ASSERT_TRUE(thirdBytes.compareTo(firstBytes)>0);
    
    // 
}

TEST(JavaLang, Decode){
    // Given a decimal value are decode and assigned to decByte
    Bytes decByte = Bytes::decode("100");
    byte expectDecResult = 100;
    byte actualDecResult = decByte.byteValue();
    // ASSERT_EQUAL(expectDecResult, actualDecResult);

    // Given a hexadecimal values are decoded and assigned to hexByte
    Bytes hexByte = Bytes::decode("0x6b");
    byte expectHexResult = 107;
    byte actualHexResult = hexByte.byteValue();
    // ASSERT_EQUAL(expectHexResult, actualHexResult);

    // Given an octal value is decoded and assigned to octalByte
    Bytes octalByte = Bytes::decode("0127");
    byte expectOctalResult = 87;
    byte actualOctalResult = octalByte.byteValue();
   // ASSERT_EQUAL(87, octalByte.byteValue());
}

TEST(JavaLang, DoubleValue){
    // Given a Double and a Byte with the same value
    Bytes byteToGetValue = 5;
    double expectResult = 5;
    double actualResult = byteToGetValue.doubleValue();
    ASSERT_DBL_NEAR(expectResult, actualResult);
}

TEST(JavaLang, ByteEquals){
    // Given 3 Bytes
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    // Given an object not a Bytes
    Object object;
    // Test Bytes and Bytes
    // Object instanceof return false
    // ASSERT_TRUE(firstBytes.equals(secondBytes));
    // ASSERT_FALSE(firstBytes.equals(thirdBytes));
    // Test Bytes and Object
    // ASSERT_FALSE(firstBytes.equals(object));
}

TEST(JavaLang, FloatValue){
    // Given a float and a Byte with the same value
    Bytes byteToGetValue = 5;
    float expectResult = 5;
    float actualResult = byteToGetValue.floatValue();
    ASSERT_DBL_NEAR(expectResult, actualResult);
}

TEST(JavaLang, HashCode ){
    // Given a Byte
    Bytes byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = byteToGetValue.hashCode();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, IntValue){
    // Given a int and a Byte with the same value
    Bytes byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = byteToGetValue.intValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, LongValue){
    // Given a int and a Byte with the same value
    Bytes byteToGetValue = 5;
    long expectResult = 5;
    long actualResult = byteToGetValue.longValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ParseByte){
    // Assign value 20 to resultByte from a String using parseByte
    byte expectResult = 20;
    byte actualResult = Bytes::parseByte("20");
    // need parseByte(string)
    // ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ParseByteWithRadix){

    // Assign value 20 to resultByte from a String using parseByte with radix =10
    byte expectResult = 20;
    byte actualResult = Bytes::parseByte("20", 10);
    // need parseByte(string)
    // ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ShortValue){
    // Given a short and a Byte with the same value
    Bytes byteToGetValue = 5;
    short expectResult = 5;
    short actualResult = byteToGetValue.shortValue();
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, StringValue){
    // Given a string and a Byte with the same value
    Bytes byteToGetValue = Bytes("val");
    string expectResult =(string) "val";
    string actualResult = byteToGetValue.stringValue();
    // need parseByte(string,radix)
    // ASSERT_TRUE(actualResult == actualResult);
}

TEST(JavaLang, ToString){
    // Given a string and a Byte with the same value
    Bytes byteToGetValue = 2;
    String expectResult = "2";
    String actualResult = byteToGetValue.toString();
    ASSERT_TRUE(expectResult == actualResult);
}

TEST(JavaLang, ToStringWithByte){
    // Given a string and a Byte with the same value
    byte byteToRepresent = 2;
    String expectResult = "2";
    // String actualResult = Bytes::toString(byteToRepresent);
    // ASSERT_TRUE(expectResult == actualResult);
}

TEST(JavaLang, ValueOfByte){
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    byte byteToGetValue = static_cast<byte>(-50);
    Bytes expectResult = Bytes(static_cast<byte>(-50));
    Bytes actualResult = Bytes::valueOf(byteToGetValue);
    ASSERT_TRUE(expectResult == actualResult);
}

TEST(JavaLang, ValueOfString){
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String stringToGetValue = "-50";
    Bytes expectResult = Bytes(static_cast<byte>(-50));
    // Bytes actualResult = Bytes::valueOf(stringToGetValue);
    // ASSERT_TRUE(expectResult == actualResult);
}

TEST(JavaLang, ValueOfStringWithRadix){
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String byteToGetValue = "-50";
    Bytes expectResult = Bytes(static_cast<byte>(-50));
    // Bytes actualResult = Bytes::valueOf(byteToGetValue, 10);
    // ASSERT_TRUE(expectResult == actualResult);
}

TEST(JavaLang, HashCodeWithByte){
    byte byteToGetValue = 5;
    int expectResult = 5;
    int actualResult = Bytes::hashCode(byteToGetValue);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, Compare){
    byte byte1 = 5;
    byte byte2 = 10;
    byte byte3 = 5;
    // Return a value < 0 if a < b
    ASSERT_TRUE(Bytes::compare(byte1, byte2) < 0);
    // Return a value > 0 if a > b
    ASSERT_TRUE(Bytes::compare(byte2, byte1) > 0);
    // Return a value = 0 if a < b
    ASSERT_TRUE(Bytes::compare(byte1, byte3) == 0);
}

TEST(JavaLang, ToUnsignedInt){
    byte byteToGetValue = static_cast<byte>(-5);
    int expectResult = 251;
    int actualResult = Bytes::toUnsignedInt(byteToGetValue);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ToUnsignedLong){
    byte byteToGetValue = static_cast<byte>(-5);
    long expectResult = 251;
    long actualResult = Bytes::toUnsignedLong(byteToGetValue);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, ByteOperator) {
	// Given a valid number
	Bytes validByte = 5;
	Bytes targetByte = 3;
    Bytes equalValidByte = 5;
	
	// Make a summation with targetByte
	Bytes summationByte = 8;
	ASSERT_TRUE(summationByte == (validByte + targetByte ));
	
	// Make a subtraction with targetByte
	Bytes subtractionByte = 2;
	ASSERT_TRUE(subtractionByte == (validByte - targetByte ));
	
	// Make a multiplication with targetByte
	Bytes multiplicationByte = 15;
	ASSERT_TRUE(multiplicationByte == (validByte * targetByte ));
	
	// Make a division with targetByte
	Bytes divisionByte = 1;
	ASSERT_TRUE(divisionByte == (validByte / targetByte ));
	
	// Make a modulo with targetByte
	Bytes modByte = 2;
	ASSERT_TRUE(modByte == (validByte % targetByte ));

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
    ASSERT_TRUE(summationByte == validByte );
    validByte = 5;

    // Make a subtraction from validByte with targetByte and assign the result value to this Byte
    validByte -= targetByte;
    ASSERT_TRUE(subtractionByte == validByte );
    validByte = 5;

    // Make a multiplication from validByte with targetByte and assign the result value to this Byte
    validByte *= targetByte;
    ASSERT_TRUE(multiplicationByte == validByte );
    validByte = 5;

    // Make a division from validByte with targetByte and assign the result value to this Byte
    validByte /= targetByte;
    ASSERT_TRUE(divisionByte == validByte );
    validByte = 5;

    // Make a modulo from validByte with targetByte and assign the result value to this Byte
    validByte %= targetByte;
    ASSERT_TRUE(modByte == validByte );
    validByte = 5;
}




