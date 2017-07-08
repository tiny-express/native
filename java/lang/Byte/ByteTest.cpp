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

TEST (JavaLang, ByteConstructor) {
	// Given empty value for Byte constructor and assign value - Return Byte
	Bytes byte1 = Bytes(3);
	ASSERT_EQUAL(3, byte1.intValue());
    // need parseByte(string, int)
    /*Bytes byte2 = Bytes("3");
    ASSERT_EQUAL(3, byte2.intValue());*/

}

TEST (JavaLang, CharValue){
    //Given a char and a Byte with the same value to compare the result of charValue()
    char aChar = 'A';
    Bytes byteToGetValue = 'A';
    ASSERT_EQUAL(aChar,byteToGetValue.charValue());
}

TEST (JavaLang, ByteValue){
    //Given a byte and a Byte with the same value to compare the result of charValue()
    byte aByte = 5;
    Bytes byteToGgetValue = 5;
    ASSERT_EQUAL( aByte, byteToGgetValue.byteValue());
}

TEST (JavaLang, CompareTo){
    //Given 3 Byte
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    ASSERT_TRUE(firstBytes.compareTo(secondBytes)==0);
    ASSERT_TRUE(firstBytes.compareTo(thirdBytes)<0);
    ASSERT_TRUE(thirdBytes.compareTo(firstBytes)>0);
}

TEST (JavaLang, Decode){
    //Given 4 Bytes and a String to decode into a Byte
    Bytes decByte, hexaByte, octalByte;
    // decimal value are decode and assigned to decByte
    decByte = Bytes::decode("100");

    // hexadecimal values are decoded and assigned to hexaByte
    hexaByte = Bytes::decode("0x6b");

    // octal value is decoded and assigned to octalByte
    octalByte = Bytes::decode("0127");

    // Check if decode succesful
    //ASSERT_EQUAL(100, decByte.byteValue());
    //ASSERT_EQUAL(107, hexaByte.byteValue());
    //ASSERT_EQUAL(87, octalByte.byteValue());

}

TEST (JavaLang, DoubleValue){
    //Given a Double and a Byte with the same value
    double aDouble = 5;
    Bytes byteToGetValue = 5;
    ASSERT_EQUAL(aDouble, byteToGetValue.doubleValue());

}

TEST (JavaLang, ByteEquals){
    //Given 3 Bytes
    Bytes firstBytes = 1;
    Bytes secondBytes = 1;
    Bytes thirdBytes = 3;

    //Given an object not a Bytes

    Object object;
    //Test Bytes and Bytes
    //Object instanceof return false
    //ASSERT_TRUE(firstBytes.equals(secondBytes));
    ASSERT_FALSE(firstBytes.equals(thirdBytes));

    //Test Bytes and Object
    ASSERT_FALSE(firstBytes.equals(object));

}

TEST (JavaLang, FloatValue){
    //Given a float and a Byte with the same value
    float aFloat = 5;
    Bytes byteToGetValue = 5;
    ASSERT_EQUAL(aFloat, byteToGetValue.floatValue());
}

TEST (JavaLang, HashCode ){
    //Given a Byte
    Bytes byteToGetValue = 5;
    ASSERT_EQUAL(5, byteToGetValue.hashCode());

}

TEST (JavaLang, IntValue){
    //Given a int and a Byte with the same value
    int anInt = 5;
    Bytes byteToGetValue = 5;
    ASSERT_EQUAL(anInt, byteToGetValue.intValue());

}

TEST (JavaLang, LongValue){
    //Given a int and a Byte with the same value
    long aLong = 5;
    Bytes byteToGetValue = 5;
    ASSERT_EQUAL(aLong, byteToGetValue.longValue());

}

TEST (JavaLang, ParseByte){
    //Given a byte to assign the result value
    byte resultByte;
    //Assign value 20 to resultByte from a String using parseByte
    resultByte = Bytes::parseByte("20");
    //need parseByte(string)
    //ASSERT_EQUAL(20,resultByte);
}

TEST (JavaLang, ParseByteWithRadix){
    //Given a byte to assign the result value
    byte resultByte;
    //Assign value 20 to resultByte from a String using parseByte with radix =10
    resultByte = Bytes::parseByte("20", 10);
    //need parseByte(string, radix)
    //ASSERT_EQUAL(20, resultByte);
}

TEST (JavaLang, ShortValue){
    //Given a short and a Byte with the same value
    short anShort = 5;
    Bytes byteToGetValue = 5;
    ASSERT_EQUAL(anShort,byteToGetValue.shortValue());
}

TEST (JavaLang, StringValue){
    //Given a string and a Byte with the same value
    string anString = (string) "val";
    Bytes byteToGetValue = Bytes("val");
    //need parseByte(string,radix)
    //ASSERT_TRUE(byteToGetValue.stringValue() == anString);
}

TEST (JavaLang, ToString){
    //Given a string and a Byte with the same value
    String anString = "2";
    Bytes byteToGetValue = 2;
    ASSERT_TRUE( byteToGetValue.toString() == anString);
}

TEST (JavaLang, ToStringWithByte){
    //Given a string and a Byte with the same value
    byte byteToRepresent = 2;
    //String anString = Bytes::toString(byteToRepresent);
    //ASSERT_TRUE(anString == "2");
}

TEST (JavaLang, ValueOfByte){
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    byte byteToGetValue = (byte) 50;
    Bytes aByte;
    aByte = Bytes::valueOf(byteToGetValue);
    //Check if aByte represent byteToGetValue
    ASSERT_TRUE(byteToGetValue == aByte.byteValue());
}

TEST (JavaLang, ValueOfString){
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String stringToGetValue = "-20";
    Bytes aByte;
    //aByte = Bytes::valueOf(stringToGetValue);
    //Check if aByte represent stringToGetValue
    //ASSERT_TRUE(stringToGetValue == aByte.stringValue());
}

TEST (JavaLang, ValueOfStringWithRadix){
    // Given a byte and a Byte, then assign value to Byte using valueOf(byte)
    String stringToGetValue = "-20";
    Bytes aByte;
    //aByte = Bytes::valueOf(stringToGetValue,10);
    //Check if aByte represent stringToGetValue
    //ASSERT_TRUE(stringToGetValue == aByte.stringValue());
}

TEST (JavaLang, ByteOperator) {
	// Given a valid number
	Bytes validByte = 5;
	Bytes targetByte = 3;
    Bytes equalValidByte = 5;
	
	// Make a summation with targetByte
	Bytes summationByte = 8;
	ASSERT_TRUE(summationByte == ( validByte + targetByte ));
	
	// Make a subtraction with targetByte
	Bytes subtractionByte = 2;
	ASSERT_TRUE(subtractionByte == ( validByte - targetByte ));
	
	// Make a multiplication with targetByte
	Bytes multiplicationByte = 15;
	ASSERT_TRUE(multiplicationByte == ( validByte * targetByte ));
	
	// Make a division with targetByte
	Bytes divisionByte = 1;
	ASSERT_TRUE(divisionByte == ( validByte / targetByte ));
	
	// Make a modulo with targetByte
	Bytes modByte = 2;
	ASSERT_TRUE(modByte == ( validByte % targetByte ));

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

    //Make a sumation from validByte with targetByte and assign the result value to this Byte
    validByte += targetByte;
    ASSERT_TRUE( summationByte == validByte );
    validByte = 5;

    //Make a subtraction from validByte with targetByte and assign the result value to this Byte
    validByte -= targetByte;
    ASSERT_TRUE( subtractionByte == validByte );
    validByte = 5;

    //Make a multiplication from validByte with targetByte and assign the result value to this Byte
    validByte *= targetByte;
    ASSERT_TRUE( multiplicationByte == validByte );
    validByte = 5;

    //Make a division from validByte with targetByte and assign the result value to this Byte
    validByte /= targetByte;
    ASSERT_TRUE( divisionByte == validByte );
    validByte = 5;

    //Make a modulo from validByte with targetByte and assign the result value to this Byte
    validByte %= targetByte;
    ASSERT_TRUE( modByte == validByte );
    validByte = 5;


}




