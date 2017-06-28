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

#include "Float.hpp"

using namespace Java::Lang;


/**
 * Float initialization
 *
 * @param original
 */
Float::Float() {
	this->original = 0;
}

/**
 * Float initialization
 *
 * @param original
 */
Float::Float(float original) {
	this->original = original;
}

/**
 * Float initialization
 *
 * @param original
 */
Float::Float(const Float &floatNumber) {
	this->original = floatNumber.original;
}

Float::~Float() {

}

/**
 * Float value
 *
 * @return float
 */
float Float::floatValue() const {
	return this->original;
}

/**
 * Char value
 *
 * @return char
 */
char Float::charValue() const {
    string stringFromFloatResult = string_from_float(this->original);
    char floatCharValueResult = string_to_char(stringFromFloatResult);
    free(stringFromFloatResult);
	return floatCharValueResult;

}

/**
 * Short value
 *
 * @return short
 */
short Float::shortValue() const {
	return (short) this->original;
}

/**
 * Int value
 *
 * @return int
 */
int Float::intValue() const {
	return (int) this->original;
}

/**
 * Long value
 *
 * @return long
 */
long Float::longValue() const {
	return (long) this->original;
}

/**
 * Double value
 *
 * @return
 */
double Float::doubleValue() const {
	return this->original;
}

/**
 * Float to String
 *
 * @return String
 */
string Float::toString() const {
	return string_from_float(this->original);
}

/**
 * Float to String
 *
 * @return CString
 */
string Float::stringValue() const {
	return string_from_float(this->original);
}

/**
 * String to Float
 *
 * @param target
 * @return Float
 */
Float Float::parseFloat(String target) {
	return Float(string_to_float(target.toString()));
}

/**
 * Sum of this and target
 *
 * @param target
 * @return Float
 */
Float Float::operator+(const Float &target) {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Float
 *
 * @return float
 */
Float Float::operator-(const Float &target) {
	return this->original - target.original;
}

/**
* Make a multiplication with target Float
*
* @return float
*/
Float Float::operator*(const Float &target) {
	return this->original * target.original;
}

/**
* Make a division with target Float
*
* @return float
*/
Float Float::operator/(const Float &target) {
	return this->original / target.original;
}

/**
* Compare this Float is equal target
*
* @return bool
*/
boolean Float::operator==(const Float &target) const {
	return this->original == target.original;
}

/**
* Compare this Float is not equal target
*
* @return bool
*/
boolean Float::operator!=(const Float &target) const {
	return this->original != target.original;
}

/**
* Compare this Float is less than target
*
* @return bool
*/
boolean Float::operator<(const Float &target) const {
	return this->original < target.original;
}

/**
* Compare this Float is more than target
*
* @return bool
*/
boolean Float::operator>(const Float &target) const {
	return this->original > target.original;
}

/**
* Compare this Float is equal or less than target
*
* @return bool
*/
boolean Float::operator<=(const Float &target) const {
	return this->original <= target.original;
}

/**
*  Compare this Float is equal or more than target
*
* @return bool
*/
boolean Float::operator>=(const Float &target) const {
	return this->original >= target.original;
}