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

#include <sstream>
#include "Integer.hpp"
#include "../Math/Math.hpp"
#include "../Character/Character.hpp"
#include "../NumberFormatException/NumberFormatException.h"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"

using namespace Java::Lang;

Integer::Integer() {
	this->original = 0;
	this->stringOriginal = string_from_int(this->original);
}

Integer::Integer(int original) {
	this->original = original;
	this->stringOriginal = string_from_int(this->original);
}

Integer::Integer(String inputString) {
    this->original = Integer::parseInt(inputString);
	this->stringOriginal = string_from_int(this->original);
}

Integer::Integer(const Integer &integer) {
	this->original = integer.original;
	this->stringOriginal = string_from_int(this->original);
}

Integer::~Integer() {
	if (this->stringOriginal != nullptr)  {
		free(this->stringOriginal);
	}
}

char Integer::charValue() const {
	string convertResult = string_from_int(this->original);
	char result = string_to_char(convertResult);
	free(convertResult);
	return result;
}

string Integer::stringValue() const {
    return this->stringOriginal;
}

short Integer::shortValue() const {
	return (short) this->original;
}

int Integer::intValue() const {
	return this->original;
}

long Integer::longValue() const {
	return (long) this->original;
}

float Integer::floatValue() const {
	return (float) this->original;
}

double Integer::doubleValue() const {
	return (double) this->original;
}

Integer &Integer::operator=(const Integer &target) {
	this->original = target.original;
    free(this->stringOriginal);
	this->stringOriginal = string_from_int(this->original);
    return *this;
}

Integer Integer::operator+(const Integer &target) {
	return this->original + target.original;
}

Integer Integer::operator-(const Integer &target) {
	return this->original - target.original;
}

boolean Integer::operator==(const Integer &target) const {
	return this->original == target.original;
}

boolean Integer::operator!=(const Integer &target) const {
	return !this->operator==(target);
}

boolean Integer::operator<(const Integer &target) const {
	return this->original < target.original;
}

boolean Integer::operator>(const Integer &target) const {
	return this->original > target.original;
}

boolean Integer::operator<=(const Integer &target) const {
	return this->original <= target.original;
}

boolean Integer::operator>=(const Integer &target) const {
	return this->original >= target.original;
}

Integer Integer::operator/(const Integer &target) {
	return ( this->original / target.original );
}

Integer Integer::operator*(const Integer &target) {
	return ( this->original * target.original );
}

Integer Integer::operator%(const Integer &target) {
	return ( this->original % target.original );
}

int Integer::bitCount(int inputInt) {
	int resultBitCount = 0;
	if (inputInt < 0) {
		resultBitCount = 1;
		inputInt = -inputInt;
	}

	while((inputInt != 0) || resultBitCount == 32) {
		if((inputInt & 1) == 1) {
			resultBitCount++;
		}
		inputInt = inputInt >> 1;
	}

	return resultBitCount;
}

byte Integer::byteValue() {
	return static_cast<byte> (this->original);
}

int Integer::compare(int inputInt1, int inputInt2) {
	if(inputInt1 < inputInt2) {
		return -1;
	}

	if(inputInt1 > inputInt2) {
		return 1;
	}

	return 0;
}

int Integer::compareTo(const Integer &anotherInteger) const {
	return compare(this->original, anotherInteger.intValue());
}

int Integer::compareUnsigned(int intA, int intB) {
	return compare(intA + MIN_VALUE, intB + MIN_VALUE);
}

Integer Integer::decode(String inputString) {
    if (inputString.length() == 0) {
        throw NumberFormatException("input string is null");
    }

    if (inputString.charAt(0) == '0' && inputString.length() == 1) {
        return 0;
    }

    boolean isNegative = false;
    int base = 10;
    char sign = inputString.charAt(0);
    if (sign == '-' && ((isdigit(sign)) == 0)) {
        isNegative = true;
        inputString = inputString.getStringFromIndex(1);
    }

    if (inputString.charAt(0) == '0') {
        if (inputString.charAt(1) == 'x' || inputString.charAt(1) == 'X') {
            base = 16;
        } else {
            base = 8;
        }
    }

    int result = parseInt(inputString, base);
    if (isNegative) {
        return static_cast<Integer>(-result);
    }
    return static_cast<Integer>(result);
}

int Integer::divideUnsigned(int dividend, int divisor) {
    if (divisor == 0) {
        //TODO throw ArithmeticException("Divide by zero");
        return 0;
    }
	return (int) (toUnsignedLong(dividend) / toUnsignedLong(divisor));
}

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
// 	return inputInt;
// }

int Integer::highestOneBit(int inputInt)  {
	inputInt |= (inputInt >> 1);
    inputInt |= (inputInt >> 2);
    inputInt |= (inputInt >> 4);
    inputInt |= (inputInt >> 8);
    inputInt |= (inputInt >> 16);

    return inputInt - ((unsigned int) inputInt >> 1);
}

int Integer::lowestOneBit(int inputInt) {
	return inputInt & -inputInt;
}

int Integer::max(int inputInt_1, int inputInt_2) {
	return Math::max(inputInt_1, inputInt_2);
}

int Integer::min(int inputInt_1, int inputInt_2) {
	return Math::min(inputInt_1, inputInt_2);
}

int Integer::numberOfLeadingZeros(int inputInt) {
	if (inputInt == 0) {
        return 32;
	}

    int n = 1;

    if ((unsigned int) inputInt >> 16 == 0) {
        n += 16;
        inputInt <<= 16;
    }

    if ((unsigned int) inputInt >> 24 == 0) {
        n += 8;
        inputInt <<= 8;
    }

    if ((unsigned int) inputInt >> 28 == 0) {
        n += 4;
        inputInt <<= 4;
    }

    if ((unsigned int) inputInt >> 30 == 0) {
        n += 2;
        inputInt <<= 2;
    }

    n -= (unsigned int) inputInt >> 31;

    return n;
}

int Integer::numberOfTrailingZeros(int inputInt) {
	int y;

    if (inputInt == 0)
        return 32;

    int n = 31;
    y = inputInt << 16;

    if (y != 0) {
        n = n - 16;
        inputInt = y;
    }

    y = inputInt << 8;

    if (y != 0) {
        n = n - 8;
        inputInt = y;
    }

    y = inputInt << 4;

    if (y != 0) {
        n = n - 4;
        inputInt = y;
    }

    y = inputInt << 2;

    if (y != 0) {
        n = n - 2;
        inputInt = y;
    }

    return n - ((unsigned int) (inputInt << 1) >> 31);
}

int Integer::parseInt(String inputString, int radix) {
	if (inputString.length() == 0) {
        throw NumberFormatException("input string is null");
    }

    if (radix > 32 || radix < 2) {
        throw NumberFormatException("radix out of range");
    }

    if (inputString.charAt(0) == '0' && inputString.length() == 1) {
        return 0;
    }

    boolean isNegative = false;
    char sign = inputString.charAt(0);
    if (sign == '-' && ((isdigit(sign)) == 0)) {
        isNegative = true;
        inputString = inputString.getStringFromIndex(1);
    }

    unsigned long unsignedResult = 0;
    try {
        unsignedResult = std::stoul(inputString.toString(), nullptr, radix);
    }
    catch (const std::invalid_argument &e) {
        throw NumberFormatException("Not a number");
    }
    catch (const std::out_of_range &e) {
        throw NumberFormatException("Integer out of range");
    }

    long result = unsignedResult;

    if (isNegative) {
        result = -unsignedResult;
    }

    if (result > Integer::MAX_VALUE || result < Integer::MIN_VALUE) {
        throw NumberFormatException("Integer out of range");
    }

    return (int) result;
}

int Integer::parseInt(String inputString) {
	return Integer::parseInt(inputString, 10);
}

int Integer::parseUnsignedInt(String inputString, int radix) {
    if (inputString.length() == 0) {
        throw NumberFormatException("input string is null");
    }

    if (radix > 32 || radix < 2) {
        throw NumberFormatException("radix out of range");
    }

    if (inputString.charAt(0) == '0' && inputString.length() == 1) {
        return 0;
    }

    char sign = inputString.charAt(0);


    if ((isdigit(sign)) == 0) {
        if (sign == '-') {
            throw NumberFormatException("Illegal leading minus sign");
        }

        if (sign == '+') {
            inputString = inputString.getStringFromIndex(1);
        }
    }
    unsigned long unsignedResult = 0;
    try {
        unsignedResult = std::stoul(inputString.toString(), nullptr, radix);
    }
    catch (const std::invalid_argument &e) {
        throw NumberFormatException("Not a number");
    }
    catch (const std::out_of_range &e) {
        throw NumberFormatException("Unsigned integer out of range");
    }

    long result = unsignedResult;

    if (result > std::numeric_limits<uint>::max()
        || result < std::numeric_limits<uint>::min()) {
        throw NumberFormatException("Unsigned integer out of range");
    }

    return (int) result;
}

int Integer::parseUnsignedInt(String inputString) {
    return Integer::parseUnsignedInt(inputString, 10);
}

int Integer::remainderUnsigned(int dividend, int divisor) {
    if (divisor == 0) {
        //TODO throw ArithmeticException("Divide by zero");
        return 0;
    }
	return (int) (toUnsignedLong(dividend) % toUnsignedLong(divisor));
}

int Integer::reverse(int inputInt) {
	inputInt = (inputInt & 0x55555555) << 1 
				| ((unsigned int) inputInt >> 1) & 0x55555555;

    inputInt = (inputInt & 0x33333333) << 2
    			| ((unsigned int) inputInt >> 2) & 0x33333333;

    inputInt = (inputInt & 0x0f0f0f0f) << 4 
    			| ((unsigned int) inputInt >> 4) & 0x0f0f0f0f;

    inputInt = (inputInt << 24) | ((inputInt & 0xff00) << 8)
    			| (((unsigned int) inputInt >> 8) & 0xff00)
    			| ((unsigned int) inputInt >> 24);

    return inputInt;
}

int Integer::reverseBytes(int inputInt) {
	inputInt = (((unsigned int) inputInt >> 24))
				| ((inputInt >> 8) & 0xFF00)
				| ((inputInt << 8) & 0xFF0000)
				| ((inputInt << 24));

	return inputInt;
}

int Integer::rotateLeft(int inputInt, int distance) {
	inputInt = (inputInt << distance) | ((unsigned int) inputInt >> -distance);

	return inputInt;
}

int Integer::rotateRight(int inputInt, int distance) {
	return ((unsigned int) inputInt >> distance) | (inputInt << -distance);
}

string Integer::toString() const {
	return this->stringOriginal;
}

// String Integer::toString(int i) {


// }

// string Integer::toString(int inputInt, int radix) {


// }

long Integer::toUnsignedLong(int inputInt) {
	// Make the overload bits is 0 to make sure inputInt in 32 bit type.
	return ((long) inputInt) & 0xffffffff;
}

String Integer::toStringObject() {
    return String(this->stringOriginal);
}

boolean Integer::equals(Integer object) {
    return this->original == object.intValue();
}

int Integer::hashCode(int inputInt) {
    return inputInt;
}

long Integer::hashCode() const {
    return Integer::hashCode(this->original);
}

int Integer::signum(int inputInt) {
    if (inputInt == 0) {
        return 0;
    }

    if (inputInt > 0) {
        return 1;
    }

    return -1;
}

int Integer::sum(int intA, int intB) {
    return intA + intB;
}

String Integer::toBinaryString(int inputInt) {
    return Integer::toUnsignedString(inputInt, 2);
}

String Integer::toUnsignedString(int inputInt, int radix) {
    if (inputInt == 0) {
        return String("0");
    }

    if (radix > 32 || radix < 2) {
        radix = 10;
    }

    std::stringstream stream;
    std::string binaryString;
    String result;

    switch (radix) {
        case 2:
            binaryString = std::bitset<32> ((unsigned long long int) toUnsignedLong(inputInt)).to_string();
            result = binaryString.c_str();
            result = result.getStringFromIndex(result.indexOf('1'));
            return result;
        case 8:
            stream << std::oct << toUnsignedLong(inputInt);
            result = stream.str();
            return result;
        case 16:
            stream << std::hex << toUnsignedLong(inputInt);
            result = stream.str();
            return result;;
        case 10:
            stream << std::dec << toUnsignedLong(inputInt);
            result = stream.str();
            return result;
        default:
            throw UnsupportedOperationException("Haven't support this radix yet");
    }
}

String Integer::toUnsignedString(int inputInt) {
    return Integer::toUnsignedString(inputInt, 10);
}

String Integer::toHexString(int inputInt) {
    return Integer::toUnsignedString(inputInt, 16);
}

String Integer::toOctalString(int inputInt) {
    return Integer::toUnsignedString(inputInt, 8);
}

Integer Integer::valueOf(int inputInt) {
    return Integer(inputInt);
}

Integer Integer::valueOf(String inputString) {
    return Integer::valueOf(Integer::parseInt(inputString));
}

Integer Integer::valueOf(String inputString, int radix) {
    return Integer::valueOf(Integer::parseInt(inputString, radix));
}

String Integer::toString(int inputInt) {
    return Integer::toString(inputInt, 10);
}

String Integer::toString(int inputInt, int radix) {
    if (inputInt < 0) {
        inputInt = -inputInt;  // Math::abs(inputInt);
        return String("-") + Integer::toUnsignedString(inputInt, radix);
    }

    return Integer::toUnsignedString(inputInt, radix);
}

Integer &Integer::operator+=(const Integer &target) {
    this->original += target.original;
    free(this->stringOriginal);
    this->stringOriginal = string_from_int(this->original);
    return *this;
}

Integer &Integer::operator-=(const Integer &target) {
    this->original += target.original;
    free(this->stringOriginal);
    this->stringOriginal = string_from_int(this->original);
    return *this;
}

Integer &Integer::operator/=(const Integer &target) {
    this->original += target.original;
    free(this->stringOriginal);
    this->stringOriginal = string_from_int(this->original);
    return *this;
}

Integer &Integer::operator*=(const Integer &target) {
    this->original += target.original;
    free(this->stringOriginal);
    this->stringOriginal = string_from_int(this->original);
    return *this;
}

Integer &Integer::operator%=(const Integer &target) {
    this->original += target.original;
    free(this->stringOriginal);
    this->stringOriginal = string_from_int(this->original);
    return *this;
}
