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

#include "Byte.hpp"

using namespace Java::Lang;

/**
 * Byte initialization
 *
 * @param original
 */
Byte::Byte() {
	this->original = 0;
}

/**
 * Byte initialization
 *
 * @param original
 */
Byte::Byte(byte original) {
	this->original = original;
}

/**
 * Byte initialization
 *
 * @param original
 */
Byte::Byte(const Byte &byteNumber) {
	this->original = byteNumber.original;
}

Byte::~Byte() {
}

/**
 * Parse long
 *
 * @param target
 * @return long
 */
long Byte::parseByte(String target) {
	return Byte(string_to_long(target.toString()));
}

/**
 * Byte to String
 *
 * @return String
 */
string Byte::toString() const {
	return string_from_char(this->original);
}

/**
 * Byte to Char
 *
 * @return char
 */
char Byte::charValue() const {
	return string_to_char(string_from_long(this->original));
}

/**
 * Long to String
 *
 * @return CString
 */
string Byte::stringValue() const {
	return Byte::valueOf(this->original).toString();
}

/**
 * Short value of Byte
 *
 * @return short
 */
short Byte::shortValue() const {
	return this->original;
}

/**
 * Integer value
 *
 * @return int
 */
int Byte::intValue() const {
	return this->original;
}

/**
 * Long value in Long
 *
 * @return int
 */
long Byte::longValue() const {
	return this->original;
}

/**
 * Long value of Byte
 *
 * @return int
 */
float Byte::floatValue() const {
	return (float) this->original;
}

/**
 * Double value of byte
 *
 * @return int
 */
double Byte::doubleValue() const {
	return (double) this->original;
}

/**
 * Make a summation with target Byte
 *
 * @return Byte
 */
Byte Byte::operator+(const byte &target) const {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Byte
 *
 * @return Byte
 */
Byte Byte::operator-(const byte &target) const {
	return this->original - target.original;
}

/**
 * Make a multiple from this Byte with target
 *
 * @return Byte
 */
Byte Byte::operator*(const byte &target) const {
	return ( this->original * target.original );
}

/**
 *  Make a division from this Byte with target
 *
 * @return Byte
 */
Byte Byte::operator/(const byte &target) const {
	return ( this->original / target.original );
}

/**
 * Make a modulo from this Byte with target
 *
 * @return Byte
 */
Byte Byte::operator%(const byte &target) const {
	return ( this->original % target.original );
}

/**
 * Compare this Byte is equal target
 *
 * @return bool
 */
boolean Byte::operator==(const byte &target) const {
	return this->original == target.original;
}

/**
 * Compare this Byte is not equal target
 *
 * @return bool
 */
boolean Byte::operator!=(const byte &target) const {
	return !this->operator==(target);
}

/**
 * Compare this Byte is less than target
 *
 * @return bool
 */
boolean Byte::operator<(const byte &target) const {
	return this->original < target.original;
}

/**
 * Compare this Byte is more than target
 *
 * @return bool
 */
boolean Byte::operator>(const byte &target) const {
	return this->original > target.original;
}

/**
 * Compare this Byte is equal or less than target
 *
 * @return bool
 */
boolean Byte::operator<=(const byte &target) const {
	return this->original <= target.original;
}

/**
 *  Compare this Byte is equal or more than target
 *
 * @return bool
 */
boolean Byte::operator>=(const byte &target) const {
	return this->original >= target.original;
}

