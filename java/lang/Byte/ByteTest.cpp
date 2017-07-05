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
    // TODO need parseByte(string, int)
    /*Bytes byte2 = Bytes("3");
    ASSERT_EQUAL(3, byte2.intValue());*/

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

    //Test Byte
    ASSERT_FALSE(firstBytes.equals(object));

}

TEST (JavaLang, ByteOperator) {
	// Given a valid number
	Bytes validNumber = 5;
	Bytes targetNumber = 3;
	
	// Make a summation with targetNumber
	Bytes summationNumber = 8;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));
	
	// Make a subtraction with targetNumber
	Bytes subtractionNumber = 2;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));
	
	// Make a multiplication with targetNumber
	Bytes multiplicationNumber = 15;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));
	
	// Make a division with targetNumber
	Bytes divisionNumber = 1;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));
	
	// Make a modulo with targetNumber
	Bytes modNumber = 2;
	ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLang, ByteParseByte) {
	// TODO
#ifdef __APPLE__
	return;
#endif
	// Given value for Byte constructor and assign value - Return byte
	// Bytes validBytePointer = Bytes::parseByte("6");
	// ASSERT_EQUAL(6, validBytePointer.intValue());
}




