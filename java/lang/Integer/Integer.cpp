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

#include "Integer.hpp"

using namespace Java::Lang;

Integer::Integer() {
	this->original = 0;
	this->string_original = string_from_int(this->original);
}

Integer::Integer(int original) {
	this->original = original;
	this->string_original = string_from_int(this->original);
}
// TODO(thoangminh): Enable after finish parseInt(String inputString, int radix)
// Integer::Integer(String inputStringtringInput) {
// 	this->original = string_to_int(stringInput.toString());
// 	this->string_original = stringInput.toString();
// }

Integer::Integer(const Integer &integer) {
	this->original = integer.original;
	this->string_original = string_from_int(this->original);
}

Integer::~Integer() {
	if (this->string_original != NULL)  {
		free(this->string_original);
	}
}

/**
 * Integer to String
 *
 * @return String
 */
string Integer::toString() const {
	return this->string_original;
}

/**
 * Integer to Char
 *
 * @return char
 */
char Integer::charValue() const {
	string convertResult = string_from_int(this->original);
	char result = string_to_char(convertResult);
	free(convertResult);
	return result;
}

/**
 * Integer to String
 *
 * @return CString
 */
string Integer::stringValue() const {
    return this->string_original;
}

/**
 * Short value of Integer
 *
 * @return short
 */
short Integer::shortValue() const {
	return this->original;
}

/**
 * Integer value
 *
 * @return int
 */
int Integer::intValue() const {
	return this->original;
}

/**
 * Integer value in Long
 *
 * @return int
 */
long Integer::longValue() const {
	return this->original;
}

/**
 * Integer value in float
 *
 * @return int
 */
float Integer::floatValue() const {
	return (float) this->original;
}

/**
 * Integer value in double
 *
 * @return int
 */
double Integer::doubleValue() const {
	return (double) this->original;
}

/**
 * Assign value of this object same as target value
 *
 * @param target
 * @return Integer
 */
Integer Integer::operator=(const Integer &target) {
	this->original = target.original;
	free(this->string_original);
	this->string_original = string_from_int(this->original);
    return *this;
}

/**
 * Make a summation with target Integer
 *
 * @return Integer
 */
Integer Integer::operator+(const Integer &target) {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Integer
 *
 * @return Integer
 */
Integer Integer::operator-(const Integer &target) {
	return this->original - target.original;
}

/**
 * Compare this Integer is equal target
 *
 * @return bool
 */
boolean Integer::operator==(const Integer &target) const {
	return this->original == target.original;
}

/**
 * Compare this Integer is not equal target
 *
 * @return bool
 */
boolean Integer::operator!=(const Integer &target) const {
	return !this->operator==(target);
}

/**
 * Compare this Integer is less than target
 *
 * @return bool
 */
boolean Integer::operator<(const Integer &target) const {
	return this->original < target.original;
}

/**
 * Compare this Integer is more than target
 *
 * @return bool
 */
boolean Integer::operator>(const Integer &target) const {
	return this->original > target.original;
}

/**
 * Compare this Integer is equal or less than target
 *
 * @return bool
 */
boolean Integer::operator<=(const Integer &target) const {
	return this->original <= target.original;
}

/**
 *  Compare this Integer is equal or more than target
 *
 * @return bool
 */
boolean Integer::operator>=(const Integer &target) const {
	return this->original >= target.original;
}

/**
 *  Make a division from this Integer with target
 *
 * @return Integer
 */
Integer Integer::operator/(const Integer &target) {
	return ( this->original / target.original );
}

/**
 * Make a multiple from this Integer with target
 *
 * @return Integer
 */
Integer Integer::operator*(const Integer &target) {
	return ( this->original * target.original );
}

/**
 * Make a modulo from this Integer with target
 *
 * @return Integer
 */
Integer Integer::operator%(const Integer &target) {
	return ( this->original % target.original );
}

int Integer::bitCount(int intInput) {
	int resultBitCount = 0;
	
	if ( intInput < 0 ) {
		resultBitCount = 1;
		intInput = -intInput;
	}

	while( (intInput != 0) || resultBitCount == 32) {

		if( (intInput & 1) == 1) {
			resultBitCount++;
		}

		intInput = intInput >> 1;
	}

	return resultBitCount;
}

// byte Integer::byteValue() {

// 	return ;
// }

// int Integer::compare(int intInput_1, int intInput_2) {
// 	return ;

// }

// int Integer::compareTo(Integer anotherInteger) {

// 	return ;
// }

// int Integer::compareUnsigned(int intInput_1, int intInput_2) {

// 	return ;
// }

// Integer Integer::decode(String inputStringtringInput) {


// }

// int Integer::divideUnsigned(int dividend, int divisor) {


// }

// double Integer::doubleValue() {


// }

// boolean Integer::equals(Integer obj) {


// }

// Integer Integer::getInteger(String inputString) {


// }

// Integer Integer::getInteger(String inputString, int inputInt) {


// }

// Integer Integer::getInteger(String inputString, Integer inputInteger) {


// }

// int Integer::hashCode() {


// }

// int Integer::hashCode(int inputInt) {


// }

// int Integer::highestOneBit(int inputInt)  {

	
// }

// int Integer::lowestOneBit(int i) {


// }

// int Integer::max(int a, int b); {


// }

// int Integer::min(int a, int b) {


// }

// int Integer::numberOfLeadingZeros(int i) {


// }

// int Integer::numberOfTrailingZeros(int i) {


// }

// int Integer::parseInt(String inputString, int radix) {


// }

int Integer::parseInt(String inputString) {
	return string_to_int(inputString.toString());
}
