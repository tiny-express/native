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

#include "Integer.hpp"

using namespace Java::Lang;

TEST (JavaLang, IntegerConstructor) {
	// Given empty value for Integer constructor and assign value - Return integer
	Integer emptyInteger;
	emptyInteger = 3;
	ASSERT_EQUAL(3, emptyInteger.intValue());

	// Given value for Integer constructor and assign value - Return string
	Integer validInteger = 3;
	ASSERT_EQUAL(3, validInteger.intValue());
}

TEST (JavaLang, IntegerComparision) {
	//Give a valid number and make a comparision
	Integer validNumber = 2;
	Integer targetNumber;

	// Test validNumber is equal targetNumber
	targetNumber = 2;
	ASSERT_TRUE(validNumber == targetNumber);

	// Test validNumber is not equal targetNumber
	targetNumber = 101;
	ASSERT_TRUE(validNumber != targetNumber);

	// Test validNumber is less than targetNumber
	targetNumber = 3;
	ASSERT_TRUE(validNumber < targetNumber);

	// Test validNumber is equal or less than targetNumber
	targetNumber = 3;
	ASSERT_TRUE(validNumber <= targetNumber);

	// Test validNumber is more than targetNumber
	targetNumber = 1;
	ASSERT_TRUE(validNumber > targetNumber);

	// Test validNumber is equal or more than targetNumber
	targetNumber = 2;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, IntegerOperator) {
	// Given a valid number
	Integer validNumber = 5;
	Integer targetNumber = 3;

	// Make a summation with targetNumber
	Integer summationNumber = 8;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

	// Make a subtraction with targetNumber
	Integer subtractionNumber = 2;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

	// Make a multiplication with targetNumber
	Integer multiplicationNumber = 15;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

	// Make a division with targetNumber
	Integer divisionNumber = 1;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));

	// Make a modulo with targetNumber
	Integer modNumber = 2;
	ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLang, IntegerParseInt) {
	#ifdef __APPLE__
		return;
	#endif
	// Given value for Integer constructor and assign value - Return integer
	Integer validIntegerPointer = Integer::parseInt("6");
	ASSERT_EQUAL(6, validIntegerPointer.intValue());
}

TEST(JavaLang, IntegerCompareTo) {
	/// Given valid Integer to compare with target
	Integer validValue = 15;
	Integer lessThanValue = 12;
	Integer equalValue = 15;
	Integer moreThanValue = 20;

    // Return 1 if validValue is more than lessThanValue
	ASSERT_EQUAL(1, validValue.compareTo(&lessThanValue));

    // Return 0 if validValue is more than equalValue
    ASSERT_EQUAL(0, validValue.compareTo(&equalValue));

    // Return -1 if validValue is less than moreThanValue
    ASSERT_EQUAL(-1, validValue.compareTo(&moreThanValue));

	/// Upcast Integer to test Comparable - this test case to ensure cast type to use in Java::Util::Arrays
	Comparable *comparable = (Comparable *)&validValue;
	Object *lessThanObject = (Object *)&lessThanValue;

	ASSERT_EQUAL(1, comparable->compareTo(lessThanObject));
}
