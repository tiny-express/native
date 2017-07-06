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

#include "Double.hpp"

using namespace Java::Lang;

/**
 * Double initialization
 *
 * @param original
 */
Double::Double() {
	this->original = 0;
	this->string_original = string_from_double(this->original);
}

/**
 * Double initialization
 *
 * @param original
 */
Double::Double(double original) {
	this->original = original;
	this->string_original = string_from_double(this->original);
}

/**
 * Double initialization
 *
 * @param original
 */
Double::Double(const Double &doubleNumber) {
	this->original = doubleNumber.original;
	this->string_original = string_from_double(this->original);
}

/**
 * Double Destructor
 */
Double::~Double() {
	if (this->string_original != NULL) {
		free(this->string_original);
	}
}

/**
 * Parse double
 *
 * @param target
 * @return double
 */
Double Double::parseDouble(String target) {
	Double result = string_to_double(target.toString());
	return result;
}

/**
 * Double to String
 *
 * @return String
 */
string Double::toString() const {
	return this->string_original;
}

/**
 * Double to Char
 *
 * @return char
 */
char Double::charValue() const {
	return string_to_char(string_from_double(this->original));
}

/**
 * Double to String
 *
 * @return CString
 */
string Double::stringValue() const {
	return String::valueOf(this->original).toString();
}

/**
 * Short value of Double
 *
 * @return short
 */
short Double::shortValue() const {
	return this->original;
}

/**
 * Double value in Double
 *
 * @return int
 */
int Double::intValue() const {
	return this->original;
}

/**
 * Double value in Long
 *
 * @return long
 */
long Double::longValue() const {
	return this->original;
}

/**
 * Double value in float
 *
 * @return float
 */
float Double::floatValue() const {
	return (float) this->original;
}

/**
 * Double value in double
 *
 * @return double
 */
double Double::doubleValue() const {
	return (double) this->original;
}

/**
 * Assign value of this object same as target value
 *
 * @param target
 * @return Double
 */
Double Double::operator=(const Double &target) {
	this->original = target.original;
	free(this->string_original);
	this->string_original = string_from_double(this->original);
	return *this;
}

/**
 * Make a summation with target Long
 *
 * @return Double
 */
Double Double::operator+(const Double &target) {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Double
 *
 * @return Double
 */
Double Double::operator-(const Double &target) {
	return this->original - target.original;
}

/**
 * Make a multiple from this Double with target
 *
 * @return Double
 */
Double Double::operator*(const Double &target) {
	return ( this->original * target.original );
}

/**
 *  Make a division from this Double with target
 *
 * @return Double
 */
Double Double::operator/(const Double &target) {
	return ( this->original / target.original );
}

// /**
//  * Make a modulo from this Double with target
//  *
//  * @return Double
//  */
// Double Double::operator%(const Double &target) {
// 	return ( this->original % target.original );
// }

/**
 * Compare this Double is equal target
 *
 * @return bool
 */
boolean Double::operator==(const Double &target) const {
	return this->original == target.original;
}

/**
 * Compare this Double is not equal target
 *
 * @return bool
 */
boolean Double::operator!=(const Double &target) const {
	return !this->operator==(target);
}

/**
 * Compare this Double is less than target
 *
 * @return bool
 */
boolean Double::operator<(const Double &target) const {
	return this->original < target.original;
}

/**
 * Compare this Double is more than target
 *
 * @return bool
 */
boolean Double::operator>(const Double &target) const {
	return this->original > target.original;
}

/**
 * Compare this Double is equal or less than target
 *
 * @return bool
 */
boolean Double::operator<=(const Double &target) const {
	return this->original <= target.original;
}

/**
 *  Compare this Double is equal or more than target
 *
 * @return bool
 */
boolean Double::operator>=(const Double &target) const {
	return this->original >= target.original;
}

