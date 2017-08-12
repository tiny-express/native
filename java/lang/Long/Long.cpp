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

#include "Long.hpp"
#include "../Math/Math.hpp"

using namespace Java::Lang;


/**
 * Default constructor
 *
 * @return
 */
Long::Long() {
	this->original = 0;
	this->originalString = string_from_long(this->original);
}

/**
 * Create new instance with an long value
 *
 * @param long value
 * @return Long
 */
Long::Long(long value) {
	this->original = value;
	this->originalString = string_from_long(this->original);
}

/**
 * Create new instance with a copy of target
 *
 * @param Long target
 * @return Long
 */
Long::Long(const Long &target) {
	this->original = target.original;
	this->originalString = string_from_long(this->original);
}

/**
 * Default destructor
 */
Long::~Long() {
	if (this->originalString != NULL) {
		free(this->originalString);
	}
}

/**
 * Returns the number of one-bits in the two's
 * complement binary representation of the specified long value.
 *
 * @param long i
 * @return int
 */
int Long::bitCount(long i) {
	i = i - (( i >> 1 ) & 0x5555555555555555L );
	i = ( i & 0x3333333333333333L ) + (( i >> 2 ) & 0x3333333333333333L );
	i = ( i + ( i >> 4 )) & 0x0f0f0f0f0f0f0f0fL;
	i = i + ( i >> 8 );
	i = i + ( i >> 16 );
	i = i + ( i >> 32 );
	return (int) i & 0x7f;
}

/**
 * Returns the value of this Long as a byte.
 *
 * @return int
 */
int Long::byteValue() {
	int result = (int) (char) this->original;
	return result;
}

/**
 * Compares two long values numerically.
 *
 * @param long x
 * @param long y
 * @return int
 */
int Long::compare(long x, long y) {
	if (x < y) {
		return -1;
	}
	if (x == y) {
		return 0;
	}
	return 1;
}

/**
 * Compares two Long objects numerically.
 *
 * @param Long anotherLong
 * @return int
 */
int Long::compareTo(Long anotherLong) {
	int result = compare(this->original, anotherLong.original);
	return result;
}

/**
 * Decodes a String into a Long.
 *
 * @param String nm
 * @return Long
 */
Long Long::decode(String target) {
	int radix = 10;
	int index = 0;
	boolean negative = false;
	Long result;
	
	if (target.length() == 0) {
		//FIXME: exception
		return -1;
	}
	
	char firstChar = target.charAt(0);
	// Handle sign, if present
	if (firstChar == '-') {
		negative = true;
		index++;
	} else if (firstChar == '+') {
		index++;
	}
	
	// Handle radix specifier, if present
	if (target.startsWith("0x", index) || target.startsWith("0X", index)) {
		index += 2;
		radix = 16;
	} else if (target.startsWith("#", index)) {
		index++;
		radix = 16;
	} else if (target.startsWith("0", index) && target.length() > 1 + index) {
		index++;
		radix = 8;
	}
	
	if (target.startsWith("-", index) || target.startsWith("+", index)) {
		//FIXME: exception
		return -1;
	}
	
	result = Long::parseLong(target.getStringFromIndex(index), radix);
	if (negative) {
		result = -result.longValue();
	}
	
	return result;
}

/**
 * Returns the value of this Long as a double.
 *
 * @return double
 */
double Long::doubleValue() const {
	return (double) this->original;
}

/**
 * Compares this object to the specified Long.
 *
 * @param Long target
 * @return boolean
 */
boolean Long::equals(Long target) {
	if (this->original == target.original) {
		return true;
	}
	return false;
}

/**
 * Returns the value of this Long as a float.
 *
 * @return float
 */
float Long::floatValue() const {
	return (float) this->original;
}

/**
 * Determines the long value of the system property with the specified name.
 *
 * @param String nm
 * @return Long
 */
Long Long::getLong(String nm) {
	Long result = decode(nm);
	return result;
}

/**
 * Determines the long value of the system property with the specified name.
 *
 * @param String nm
 * @param long val
 * @return Long
 */
Long Long::getLong(String nm, long val) {
	return Long();
}

/**
 * Returns the long value of the system property with the specified name.
 *
 * @param String nm
 * @param Long val
 * @return Long
 */
Long Long::getLong(String nm, Long val) {
	return Long();
}

/**
 * Returns a hash code for this Long.
 *
 * @return int
 */
int Long::hashCode() {
	return (int) ( this->original ^ ( this->original >> 32 ));
}

/**
 * Returns a long value with at most a single one-bit, in the position of the highest-order ("leftmost")
 * one-bit in the specified long value.
 *
 * @param long i
 * @return long
 */
long Long::highestOneBit(long i) {
	i |= ( i >> 1 );
	i |= ( i >> 2 );
	i |= ( i >> 4 );
	i |= ( i >> 8 );
	i |= ( i >> 16 );
	i |= ( i >> 32 );
	return ( i - ( i >> 1 ));
}

/**
 * Returns the value of this Long as an int.
 *
 * @return int
 */
int Long::intValue() const {
	return (int) this->original;
}

/**
 * Returns the value of this Long as a long value.
 *
 * @return long
 */
long Long::longValue() const {
	return this->original;
}

/**
 * Returns a long value with at most a single one-bit, in the position of the lowest-order ("rightmost")
 * one-bit in the specified long value.
 *
 * @param long i
 * @return long
 */
long Long::lowestOneBit(long i) {
	return ( i & -i );
}

/**
 * Returns the number of zero bits preceding the highest-order ("leftmost") one-bit
 * in the two's complement binary representation of the specified long value.
 *
 * @param source
 * @return int
 */
int Long::numberOfLeadingZeros(long source) {
    if (source == 0L) {
        return 64;
    }

    int shiftCount = 63;
    while (shiftCount >= 0) {
        if ((source & (1L << shiftCount)) != 0) {
            return 63 - shiftCount;
        }
        --shiftCount;
    }

    // for loop must return a value, so don't need to return anything after for loop.
}

/**
 * Returns the number of zero bits following the lowest-order ("rightmost") one-bit
 * in the two's complement binary representation of the specified long value.
 *
 * @param source
 * @return int
 */
int Long::numberOfTrailingZeros(long source) {
    if (source == 0L) {
        return 64;
    }

    int bitOrder;
    for (bitOrder = 0; bitOrder < 64; ++bitOrder) {
        if ((source & (1L << bitOrder)) != 0) {
            return bitOrder;
        }
    }

    // for loop must return a value, so don't need to return anything after for loop.
}

/**
 * Parses the string argument as a signed decimal long.
 *
 * @param String s
 * @return long
 */
long Long::parseLong(String s) {
	long result = parseLong(s, 10);
	return result;
}

/**
 * Parses the string argument as a signed long in the radix specified by the second argument.
 *
 * @param String s
 * @param int radix
 * @return long
 */
long Long::parseLong(String s, int radix) {
	//FIXME: correct radix, correct target, correct negative, correct '+' '-' in the target[0]
	
	long result = 0;
	boolean negative = false;
	int index = 0;
	int length = s.length();
	long limit = -Long::MAX_VALUE;
	long multmin;
	int digit;
	
	if (length > 0) {
		char firstChar = s.charAt(0);
		if (firstChar < '0') { // Possible leading "+" or "-"
			if (firstChar == '-') {
				negative = true;
				limit = Long::MIN_VALUE;
			} else if (firstChar != '+') {
				//FIXME: exception
				return -1;
			}
			if (length == 1) { // Cannot have lone "+" or "-"
				//FIXME: exception
				return -1;
			}
			
			index++;
		}
		
		multmin = limit / radix;
		while (index < length) {
			// Accumulating negatively avoids surprises near MAX_VALUE
			digit = Character::digit(s.charAt(index++), radix);
			if (digit < 0) {
				//FIXME: exception
				return -1;
			}
			if (result < multmin) {
				//FIXME: exception
				return -1;
			}
			result *= radix;
			if (result < limit + digit) {
				//FIXME: exception
				return -1;
			}
			result -= digit;
		}
	} else {
		//FIXME: exception
		return -1;
	}
	return negative ? result : -result;
}

/**
 * Returns the value obtained by reversing the order of the bits
 * in the two's complement binary representation of the specified long value.
 *
 * @param long i
 * @return long
 */
long Long::reverse(long i) {
	i = ( i & 0x5555555555555555L ) << 1 | ( i >> 1 ) & 0x5555555555555555L;
	i = ( i & 0x3333333333333333L ) << 2 | ( i >> 2 ) & 0x3333333333333333L;
	i = ( i & 0x0f0f0f0f0f0f0f0fL ) << 4 | ( i >> 4 ) & 0x0f0f0f0f0f0f0f0fL;
	i = ( i & 0x00ff00ff00ff00ffL ) << 8 | ( i >> 8 ) & 0x00ff00ff00ff00ffL;
	i = ( i << 48 ) | (( i & 0xffff0000L ) << 16 ) |
	    (( i >> 16 ) & 0xffff0000L ) | ( i >> 48 );
	return i;
}

/**
 * Returns the value obtained by reversing the order of the bytes
 * in the two's complement representation of the specified long value.
 *
 * @param long i
 * @return long
 */
long Long::reverseBytes(long i) {
	i = ( i & 0x00ff00ff00ff00ffL ) << 8 | ( i >> 8 ) & 0x00ff00ff00ff00ffL;
	return (( i << 48 ) | (( i & 0xffff0000L ) << 16 ) | (( i >> 16 ) & 0xffff0000L ) | ( i >> 48 ));
}

/**
 * Returns the value obtained by rotating the two's complement binary representation
 * of the specified long value left by the specified number of bits.
 *
 * @param long i
 * @param int distance
 * @return long
 */
long Long::rotateLeft(long i, int distance) {
	return (( i << distance ) | ( i >> -distance ));
}

/**
 * Returns the value obtained by rotating the two's complement binary representation
 * of the specified long value right by the specified number of bits.
 *
 * @param long i
 * @param int distance
 * @return long
 */
long Long::rotateRight(long i, int distance) {
	return (( i >> distance ) | ( i << -distance ));
}

/**
 * Returns the value of this Long as a short.
 *
 * @return short
 */
short Long::shortValue() const {
	return (short) this->original;
}

/**
 * Returns the signum function of the specified long value.
 *
 * @param long i
 * @return int
 */
int Long::signum(long i) {
	return (int) (( i >> 63 ) | ( -i >> 63 ));
}

/**
 * Returns a string representation of the long argument as an unsigned integer in base 2.
 *
 * @param long i
 * @return String
 */
String Long::toBinaryString(long i) {
	String result = toUnsignedString0(i, 1);
	return result;
}

/**
 * Returns a string representation of the long argument as an unsigned integer in base 16.
 *
 * @param long i
 * @return String
 */
String Long::toHexString(long i) {
	String result = toUnsignedString0(i, 4);
	return result;
}

/**
 * Returns a string representation of the long argument as an unsigned integer in base 8.
 *
 * @param long i
 * @return String
 */
String Long::toOctalString(long i) {
	String result = toUnsignedString0(i, 3);
	return result;
}

/**
 * Returns a String object representing this Long's value.
 *
 * @return String
 */
string Long::toString() const {
	return this->originalString;
}

/**
 * Returns a String object representing the specified long.
 *
 * @param long i
 * @return String
 */
string Long::toString(long i) {
	static Long result = i;
	return result.toString();
}

/**
 * Returns a Long instance representing the specified long value.
 *
 * @param long l
 * @return Long
 */
Long Long::valueOf(long l) {
	Long result = l;
	return result;
}

/**
 * Returns a Long object holding the value of the specified String.
 *
 * @param String s
 * @return Long
 */
Long Long::valueOf(String s) {
	Long result = decode(s);
	return result;
}

/**
 * Returns a Long object holding the value extracted from the specified String
 * when parsed with the radix given by the second argument.
 *
 * @param String s
 * @param int radix
 * @return Long
 */
Long Long::valueOf(String s, int radix) {
	Long result = parseLong(s, radix);
	return result;
}

/**
 * Format a long (treated as unsigned) into a character buffer.
 *
 * @param long val
 * @param int shift
 * @param Array<char> buf
 * @param int offset
 * @param int len
 * @return int
 */
int Long::formatUnsignedLong(long val, int shift, Array<char> &buf, int offset, int len) {
	int charPos = len;
	int radix = 1 << shift;
	int mask = radix - 1;
	
	//FIXME: move this to Integer.digits
	static char digits[] = {
		'0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9', 'a', 'b',
		'c', 'd', 'e', 'f', 'g', 'h',
		'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z'
	};
	
	do {
		buf[ offset + --charPos ] = digits[ ((int) val ) & mask ];
		val >>= shift;
	} while (val != 0 && charPos > 0);
	
	return charPos;
}

/**
 * Format a long (treated as unsigned) into a String.
 *
 * @param long val
 * @param int shift
 * @return String
 */
String Long::toUnsignedString0(long val, int shift) {
	// assert shift > 0 && shift <=5 : "Illegal shift value";
	static int SIZE = 64;
	
	int mag = SIZE - Long::numberOfLeadingZeros(val);
	int chars = Math::max((( mag + ( shift - 1 )) / shift ), 1);
	
	Array<char> buff;
	for (int i = 0; i < chars; ++i) { //Set empty array
		buff.push('0');
	}
	
	formatUnsignedLong(val, shift, buff, 0, chars);
	
	String result = String::fromCharArray(buff);
	return result;
}

/**
 * Assign value of this object same as value of target object
 *
 * @param target
 * @return Long
 */
Long Long::operator=(const Long &target) {
	this->original = target.original;
	if (this->originalString != NULL) {
		free(this->originalString);
	}
	this->originalString = string_from_long(this->original);
	return *this;
}

/**
 * Sum two Long
 *
 * @param Long target
 * @return Long
 */
Long Long::operator+(const Long &target) const {
	Long result = this->original + target.original;
	return result;
}

/**
 * Subtract two Long
 *
 * @param Long target
 * @return
 */
Long Long::operator-(const Long &target) const {
	Long result = this->original - target.original;
	return result;
}

/**
 * Divide two Long
 *
 * @param Long target
 * @return
 */
Long Long::operator/(const Long &target) const {
	Long result = this->original / target.original;
	return result;
}

/**
 * Modulo two Long
 *
 * @param Long target
 * @return
 */
Long Long::operator%(const Long &target) const {
	Long result = this->original % target.original;
	return result;
}

/**
 * Multiply two Long
 *
 * @param Long target
 * @return
 */
Long Long::operator*(const Long &target) const {
	Long result = this->original * target.original;
	return result;
}

/**
 * Compare equal
 *
 * @param Long target
 * @return boolean
 */
boolean Long::operator==(const Long &target) const {
	if (this->original == target.original) {
		return true;
	}
	return false;
}

/**
 * Compare not equal
 *
 * @param Long target
 * @return boolean
 */
boolean Long::operator!=(const Long &target) const {
	if (this->original != target.original) {
		return true;
	}
	
	return false;
}

/**
 * Compare less than
 *
 * @param Long target
 * @return boolean
 */
boolean Long::operator<(const Long &target) const {
	if (this->original < target.original) {
		return true;
	}
	
	return false;
}

/**
 * Compare more than
 *
 * @param Long target
 * @return boolean
 */
boolean Long::operator>(const Long &target) const {
	if (this->original > target.original) {
		return true;
	}
	
	return false;
}

/**
 * Compare less than or equal
 *
 * @param Long target
 * @return boolean
 */
boolean Long::operator<=(const Long &target) const {
	if (this->original > target.original) {
		return false;
	}
	
	return true;
}

/**
 * Compare more than or equal
 *
 * @param Long target
 * @return boolean
 */
boolean Long::operator>=(const Long &target) const {
	if (this->original < target.original) {
		return false;
	}
	return true;
}

/**
 * Subtract this with target
 *
 * @param target
 */
void Long::operator-=(const Long &target) {
	this->original -= target.original;
}

/**
 * Sum this with target
 *
 * @param target
 */
void Long::operator+=(const Long &target) {
	this->original += target.original;
}

/**
 * Multiply this with target
 *
 * @param target
 */
void Long::operator*=(const Long &target) {
	this->original *= target.original;
}

/**
 * Devide this with target
 *
 * @param target
 */
void Long::operator/=(const Long &target) {
	this->original /= target.original;
}

/**
 * Modulo this with target
 *
 * @param target
 */
void Long::operator%=(const Long &target) {
	this->original %= target.original;
}