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
Bytes::Bytes() {
	this->original = 0;
}

/**
 * Byte initialization
 *
 * @param original
 */
Bytes::Bytes(byte original) {
	this->original = original;
}

/**
 * Byte initialization
 *
 * @param original
 */
Bytes::Bytes(const Bytes &byteNumber) {
	this->original = byteNumber.original;
}

Bytes::~Bytes() {
}

/**
 * Parse byte
 *
 * @param target
 * @return Byte
 */
// byte Bytes::parseByte(String target) {
// 	byte result(string_to_byte(target.toString()));
// 	return result;
// }


/**
 * Byte to Char
 *
 * @return char
 */
char Bytes::charValue() {
	return string_to_char(string_from_char(this->original));
}

/**
 * Byte to String
 *
 * @return String
 */
string Bytes::stringValue() {
	return String::valueOf(this->original).toString();
}

/**
 * Short value of Byte
 *
 * @return short
 */
short Bytes::shortValue() {
	return (short)this->original;
}

/**
 * Integer value of Byte
 *
 * @return int
 */
int Bytes::intValue() {
	return (int)this->original;
}

/**
 * Long value of Byte
 *
 * @return long
 */
long Bytes::longValue() {
	return (long)this->original;
}

/**
 * Float value of Byte
 *
 * @return float
 */
float Bytes::floatValue() {
	return (float) this->original;
}

/**
 * Double value of Byte
 *
 * @return double
 */
double Bytes::doubleValue() {
	return (double) this->original;
}

/**
 * Byte value
 *
 * @return byte
 */
byte Bytes::byteValue() {
	return (byte) this->original;
}



/**
 * Make a summation with target Byte
 *
 * @return Byte
 */
byte Bytes::operator+(const byte &target) {
	return this->original + target;
}

/**
 * Make a subtraction with target Byte
 *
 * @return Byte
 */
byte Bytes::operator-(const byte &target) {
	return this->original - target;
}

/**
 *  Make a division from this Byte with target
 *
 * @return Byte
 */
byte Bytes::operator/(const byte &target) {
	return  this->original / target;
}

/**
 * Make a modulo from this Byte with target
 *
 * @return Byte
 */
byte Bytes::operator%(const byte &target) {
	return this->original % target;
}

/**
 * Make a multiple from this Byte with target
 *
 * @return Byte
 */
byte Bytes::operator*(const byte &target) {
	return this->original * target;
}

/**
 * Compare this Byte is equal target
 *
 * @return bool
 */
boolean Bytes::operator==(const byte &target) {
	return this->original == target;
}

/**
 * Compare this Byte is not equal target
 *
 * @return bool
 */
boolean Bytes::operator!=(const byte &target) {
	return this->original != target;
}

/**
 * Compare this Byte is less than target
 *
 * @return bool
 */
boolean Bytes::operator<(const byte &target) {
	return this->original < target;
}

/**
 * Compare this Byte is more than target
 *
 * @return bool
 */
boolean Bytes::operator>(const byte &target) {
	return this->original > target;
}

/**
 * Compare this Byte is equal or less than target
 *
 * @return bool
 */
boolean Bytes::operator<=(const byte &target) {
	return this->original <= target;
}

/**
 *  Compare this Byte is equal or more than target
 *
 * @return bool
 */
boolean Bytes::operator>=(const  byte &target) {
	return this->original >= target;
}








