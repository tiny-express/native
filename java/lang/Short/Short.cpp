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

#include "Short.hpp"

using namespace Java::Lang;

/**
 * Integer initialization
 *
 * @param original
 */
Short::Short() {
	this->original = 0;
	this->originalString = stringFromShort(this->original);
}

/**
 * Short initialization
 *
 * @param original
 */
Short::Short(short original) {
	this->original = original;
	this->originalString = stringFromShort(this->original);
}

/**
 * Short initialization
 *
 * @param original
 */
Short::Short(const Short &shortNumber) {
	this->original = shortNumber.original;
	this->originalString = stringFromShort(this->original);
}

Short::~Short() {
	if (this->originalString != NULL) {
		free(this->originalString);
	}
}

/**
 * Parse short
 *
 * @param target
 * @return short
 */
Short Short::parseShort(String target) {
	return Short(stringToShort(target.toString()));
}

/**
 * Short to String
 *
 * @return String
 */
string Short::toString() const {
	return this->originalString;
}

/**
 * Short to Char
 *
 * @return char
 */
char Short::charValue() const {
	return stringToChar(stringFromShort(this->original));
}

/**
 * Short value of Short
 *
 * @return short
 */
short Short::shortValue() const {
	return this->original;
}

/**
 * Integer value of short
 *
 * @return int
 */
int Short::intValue() const {
	return this->original;
}

/**
 * Long value of short
 *
 * @return int
 */
long Short::longValue() const {
	return this->original;
}

/**
 * Short value in float
 *
 * @return int
 */
float Short::floatValue() const {
	return (float) this->original;
}

/**
 * Short value in double
 *
 * @return int
 */
double Short::doubleValue() const {
	return (double) this->original;
}

/**
 * Assign value of this object same as value of target object
 *
 * @param target
 * @return Short
 */
Short Short::operator=(const Short &target) {
	this->original = target.original;
	free(this->originalString);
	this->originalString = stringFromShort(this->original);
	return *this;
}

/**
 * Make a summation with target Short
 *
 * @return Integer
 */
Short Short::operator+(const Short &target) {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Shortr
 *
 * @return Short
 */
Short Short::operator-(const Short &target) {
	return this->original - target.original;
}

/**
 * Make a multiple from this Short with target
 *
 * @return Short
 */
Short Short::operator*(const Short &target) {
	return ( this->original * target.original );
}

/**
 *  Make a division from this Short with target
 *
 * @return Short
 */
Short Short::operator/(const Short &target) {
	return ( this->original / target.original );
}

/**
 * Make a modulo from this Short with target
 *
 * @return Short
 */
Short Short::operator%(const Short &target) {
	return ( this->original % target.original );
}

/**
 * Compare this Long is equal target
 *
 * @return bool
 */
boolean Short::operator==(const Short &target) const {
	return this->original == target.original;
}

/**
 * Compare this Short is not equal target
 *
 * @return bool
 */
boolean Short::operator!=(const Short &target) const {
	return !this->operator==(target);
}

/**
 * Compare this Short is less than target
 *
 * @return bool
 */
boolean Short::operator<(const Short &target) const {
	return this->original < target.original;
}

/**
 * Compare this Short is more than target
 *
 * @return bool
 */
boolean Short::operator>(const Short &target) const {
	return this->original > target.original;
}

/**
 * Compare this Short is equal or less than target
 *
 * @return bool
 */
boolean Short::operator<=(const Short &target) const {
	return this->original <= target.original;
}

/**
 *  Compare this Short is equal or more than target
 *
 * @return bool
 */
boolean Short::operator>=(const Short &target) const {
	return this->original >= target.original;
}

