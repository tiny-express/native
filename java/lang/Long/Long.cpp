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

#include "Long.hpp"

using namespace Java::Lang;

/**
 * Integer initialization
 *
 * @param original
 */
Long::Long() {
	this->original = 0;
}

/**
 * Long initialization
 *
 * @param original
 */
Long::Long(long original) {
	this->original = original;
}

/**
 * Long initialization
 *
 * @param original
 */
Long::Long(const Long &longNumber) {
	this->original = longNumber.original;
}

Long::~Long() {
}

/**
 * Parse long
 *
 * @param target
 * @return long
 */
Long Long::parseLong(String target) {
	return Long(string_to_long(target.toString()));
}

/**
 * Parse long with the target and radix
 *
 * @param target
 * @param radix
 * @return long
 */
Long Long::parseLong(String target, int radix) {
	//FIXME: @tucao will correct this with radix after finish radix 16 for UUID
    //FIXME: correct radix, correct target, correct negative, correct '+' '-' in the target[0]

    long result = 0;
    int index = 0;
    int length = target.length();
    int digit;

    if (length > 0) {
//        char firstChar =
    }

	return 0;
}

/**
 * Long to String
 *
 * @return String
 */
string Long::toString() const {
	return string_from_long(this->original);
}

/**
 * Long to Char
 *
 * @return char
 */
char Long::charValue() const {
	return string_to_char(string_from_long(this->original));
}

/**
 * Long to String
 *
 * @return CString
 */
string Long::stringValue() const {
	return String::valueOf(this->original).toString();
}

/**
 * Short value of Long
 *
 * @return short
 */
short Long::shortValue() const {
	return this->original;
}

/**
 * Integer value
 *
 * @return int
 */
int Long::intValue() const {
	return this->original;
}

/**
 * Long value in Long
 *
 * @return int
 */
long Long::longValue() const {
	return this->original;
}

/**
 * Long value in float
 *
 * @return int
 */
float Long::floatValue() const {
	return (float) this->original;
}

/**
 * Long value in double
 *
 * @return int
 */
double Long::doubleValue() const {
	return (double) this->original;
}

/**
 * Make a summation with target Long
 *
 * @return Integer
 */
Long Long::operator+(const Long &target) const {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Integer
 *
 * @return Integer
 */
Long Long::operator-(const Long &target) const {
	return this->original - target.original;
}

/**
 * Make a multiple from this Long with target
 *
 * @return Long
 */
Long Long::operator*(const Long &target) const {
	return ( this->original * target.original );
}

/**
 *  Make a division from this Long with target
 *
 * @return Integer
 */
Long Long::operator/(const Long &target) const {
	return ( this->original / target.original );
}

/**
 * Make a modulo from this Long with target
 *
 * @return Long
 */
Long Long::operator%(const Long &target) const {
	return ( this->original % target.original );
}

/**
 * Compare this Long is equal target
 *
 * @return bool
 */
boolean Long::operator==(const Long &target) const {
	return this->original == target.original;
}

/**
 * Compare this Long is not equal target
 *
 * @return bool
 */
boolean Long::operator!=(const Long &target) const {
	return !this->operator==(target);
}

/**
 * Compare this Long is less than target
 *
 * @return bool
 */
boolean Long::operator<(const Long &target) const {
	return this->original < target.original;
}

/**
 * Compare this Long is more than target
 *
 * @return bool
 */
boolean Long::operator>(const Long &target) const {
	return this->original > target.original;
}

/**
 * Compare this Long is equal or less than target
 *
 * @return bool
 */
boolean Long::operator<=(const Long &target) const {
	return this->original <= target.original;
}

/**
 *  Compare this Long is equal or more than target
 *
 * @return bool
 */
boolean Long::operator>=(const Long &target) const {
	return this->original >= target.original;
}

