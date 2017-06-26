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

// 	// Given empty value for Long constructor and assign value - Return Long
// 	Byte emptyByte;
// // 	emptyByte = 3;
// // 	ASSERT_EQUAL(3, emptyByte.byteValue());

// 	// Given value for Integer constructor and assign value - Return string
// 	Byte validByte = 3;
// 	ASSERT_EQUAL(3, validByte.longValue());

// 	Byte validByte2 = 3;
// 	ASSERT_EQUAL(3, validByte2.intValue());
	
// 	Byte validByte3 = 3;
// 	ASSERT_EQUAL(3.0, validByte3.floatValue());
	
// 	Byte validByte4 = 3;
// 	ASSERT_EQUAL(3, validByte4.doubleValue());
	
// 	Byte validByte5 = 3;
// 	ASSERT_EQUAL(3, validByte5.shortValue());
}

TEST (JavaLang, ByteComparision) {
	// Give a valid number and make a comparision
	byte validNumber = 12;
	byte targetNumber;

	// Test validNumber is equal targetNumber
	targetNumber = 12;
	ASSERT_TRUE(validNumber == targetNumber);

	// Test validNumber is not equal targetNumber
	targetNumber = 2;
	ASSERT_TRUE(validNumber != targetNumber);

	// Test validNumber is less than targetNumber
	targetNumber = 10;
	ASSERT_TRUE(validNumber < targetNumber);

	// Test validNumber is equal or less then targetNumber
	targetNumber = 11;
	ASSERT_TRUE(validNumber <= targetNumber);

	// Test validNumber is more than targetNumber
	targetNumber = 4;
	ASSERT_TRUE(validNumber > targetNumber);

	// Test validNumber is equal or more than targetNumber
	targetNumber = 6;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, ByteOperator) {
	// Given a valid number
	byte validNumber = 5;
	byte targetNumber = 3;

	// Make a summation with targetNumber
	byte summationNumber = 8;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

	// Make a subtraction with targetNumber
	byte subtractionNumber = 2;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

	// Make a multiplication with targetNumber
	byte multiplicationNumber = 15;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

	// Make a division with targetNumber
	byte divisionNumber = 1;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));

	// Make a modulo with targetNumber
	byte modNumber = 2;
	ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLang, ByteParseByte) {
	#ifdef __APPLE__
		return;
	#endif
	// Given value for Long constructor and assign value - Return long
	Byte validBytePointer = Byte::parseByte("6");
	ASSERT_EQUAL(6, validBytePointer.byteValue());
}
