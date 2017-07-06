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

ByteCache *ByteCache::instance =0;

/**
 * Byte initialization
 *
 * @param original
 */
Bytes::Bytes(byte original) {
	this->original = original;
}

/**
 * Construct a new Byte with the value of string
 *
 * @param string
 */
Bytes::Bytes(String string) {
	this->original = parseByte(string,10);
}

Bytes::Bytes() {
}

Bytes::~Bytes() {
}

/**
 *Return the value of this Byte as a char
 *
 * @return char
 */
char Bytes::charValue() const {
    return (char)this->original;
}

/**
 * Byte value
 *
 * @return byte
 */
byte Bytes::byteValue() {
	return this->original;
}

/**
 * Compares two Byte objects numerically
 *
 * @param anotherByte
 * @return the value 0 if this Byte is equal to anotherByte;
 * a value less than 0 if this Byte is numerically less than anotherByte;
 * and a value greater than 0 if this Byte is numerically greater than anotherByte
 */
int Bytes::compareTo(const Bytes &anotherByte) const {
	return this->original-anotherByte.original;
}

/**
 * Decodes a String into a Byte. Accepts decimal, hexadecimal, and octal numbers
 *
 * @param stringToDecode
 * @return
 */
Bytes Bytes::decode(String stringToDecode) {
    //TODO need Integer::decode(string)
    /*int value = Integer::decode(stringToDecode);
    if (i < MIN_VALUE || i > MAX_VALUE)
        //TODO throw NumberFormatException
     return (byte)value;
     */
    return 0;//temporarily
}

/**
 * Double value of Byte
 *
 * @return double
 */
double Bytes::doubleValue() const{
	return (double) this->original;
}

/**
 * Compare this Byte to another Byte object
 *
 * @param object
 * @return true if object is a Byte and has the same value as this Bytes; false otherwise
 */
boolean Bytes::equals(Object object) {
    //instanceof return false with Byte object, need to fix
    boolean isByte =instanceof<Bytes>(object);
	if (isByte){
        return this->original == parseByte(object.toString());
    }
	return false;
}

/**
 * Returns the value of this Byte as an float.
 *
 * @return float
 */
float Bytes::floatValue() const {
    return (float) this->original;
}

/**
 * Returns a hash code for this Byte
 *
 * @return int
 */
int Bytes::hashCode() {
    return (int) this->original;
}

/**
 * Returns the value of this Byte as an int.
 *
 * @return int
 */
int Bytes::intValue() const {
    return (int) this->original;
}

/**
 * Returns the value of this Byte as an long.
 *
 * @return long
 */
long Bytes::longValue() const{
    return (long) this->original;
}

/**
 * Parse the parameter string as a byte
 *
 * @param stringToParse
 * @return Byte
 */
byte Bytes::parseByte(String stringToParse) {
	return parseByte(stringToParse,10);
}
/**
 * Parse the parameter string as a byte with radix =10
 *
 * @param stringToParse
 * @param radix
 * @return
 */
byte Bytes::parseByte(String stringToParse, int radix) {
    //TODO need Integer::parseInt(string, int)
    /*int value = Integer::parseInt(stringToParse, radix);
    if( value < MIN_VALUE || value > MAX_VALUE)
    {
        //TODO throw numberFormatException
    }
    return (byte)value;*/
    return 0;//temporarily
}


/**
 * Returns the value of this Byte as an short.
 *
 * @return short
 */
short Bytes::shortValue() const {
    return (short) this->original;
}
/**
 * Returns the value of this Byte as an String.
 *
 * @return string
 */
string Bytes::stringValue() const {
    return String::valueOf(this->original).toString();
}

/**
 * Returns a String object representing this Byte's value
 *
 * @return String
 */
String Bytes::toString() {
    return String::valueOf((int)this->original);
}

/**
 * Returns a new String object representing the specified byte with radix = 10
 *
 * @param byte
 * @return String
 */
String Bytes::toString(byte specifiedByte) {
    //TODO need Integer.toString(int,radix)
    //return Integer::toString((int)specifiedByte, 10);
}

/**
 * Returns a Byte instance representing the specified byte value.
 *
 * @param targetByte
 * @return Bytes
 */
Bytes Bytes::valueOf(byte targetByte) {
	const int offset = 128;
    return  ByteCache::getInstance()->cache.get((int)targetByte+offset);
}

/**
 * Returns a Byte instance representing the specified String value.
 *
 * @param targetString
 * @return Bytes
 */
Bytes Bytes::valueOf(String targetString) {
    return Bytes(parseByte(targetString));
}

/**
 * Returns a Byte instance representing the specified String value with radix
 *
 * @param targetString
 * @param radix
 * @return
 */
Bytes Bytes::valueOf(String targetString, int radix) {
    return Bytes(parseByte(targetString, radix));
}

/**
 * Make a summation with target Byte
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator+(const Bytes &target) {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Byte
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator-(const Bytes &target) {
	return this->original - target.original;
}

/**
 *  Make a division from this Byte with target
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator/(const Bytes &target) {
	return  this->original / target.original;
}

/**
 * Make a modulo from this Byte with target
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator%(const Bytes &target) {
	return this->original % target.original;
}

/**
 * Make a multiplication from this Byte with target
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator*(const Bytes &target) {
	return this->original * target.original;
}

/**
 * Compare 2 Byte
 *
 * @param target
 * @return true if target Byte is equal to this Byte; false otherwise
 */
boolean Bytes::operator==(const Bytes &target) {
	return this->original == target.original;
}

/**
 * Compare 2 Byte
 *
 * @param target
 * @return true if target Byte is not equal to this Byte; false otherwise
 */
boolean Bytes::operator!=(const Bytes &target) {
	return this->original != target.original;
}

/**
 * Determine if this Byte is smaller than target
 *
 * @param target
 * @return true if this Byte is smaller than target; false otherwise
 */
boolean Bytes::operator<(const Bytes &target) {
	return this->original < target.original;
}

/**
 * Determine if this Byte is bigger than target
 *
 * @param target
 * @return true if this Byte is bigger than target; false otherwise
 */
boolean Bytes::operator>(const Bytes &target) {
	return this->original > target.original;
}

/**
 * Determine if this Byte is equal or less than target
 *
 * @param target
 * @return true if this Byte is equal or less than target; false otherwise
 */
boolean Bytes::operator<=(const Bytes &target) {
	return this->original <= target.original;
}

/**
 * Determine if this Byte is equal or bigger than target
 *
 * @param target
 * @return true if this Byte is equal or bigger than target; false otherwise
 */
boolean Bytes::operator>=(const  Bytes &target) {
	return this->original >= target.original;
}

/**
 * Make a subtraction from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator-=(const Bytes &target) {
    this->original -= target.original;
}

/**
 * Make an sumation from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator+=(const Bytes &target) {
    this->original += target.original;
}
/**
 * Make a multiplication from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator*=(const Bytes &target) {
    this->original *= target.original;
}
/**
 * Make a division from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator/=(const Bytes &target) {
    this->original /= target.original;
}
/**
 * Make a modulo from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator%=(const Bytes &target) {
    this->original %= target.original;
}

/**
 *  Assign the value of target to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator=(const Bytes &target) {
    this->original = target.original;
}


















