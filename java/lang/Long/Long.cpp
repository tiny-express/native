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
#include "../Math/Math.hpp"
#include "../Character/Character.hpp"

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
 * Decode a long value in a string
 * Just support for 0x (16) this time
 * @param target
 * @return
 */
Long Long::decode(String target) {
    //FIXME: @tucao implement correct this function after finish UUID.fromString

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
    } else if (firstChar == '+')
        index++;

    // Handle radix specifier, if present
    if (target.startsWith("0x", index) || target.startsWith("0X", index)) {
        index += 2;
        radix = 16;
    }
    else if (target.startsWith("#", index)) {
        index ++;
        radix = 16;
    }
    else if (target.startsWith("0", index) && target.length() > 1 + index) {
        index ++;
        radix = 8;
    }

    if (target.startsWith("-", index) || target.startsWith("+", index)) {
        //FIXME: exception
        return -1;
    }

    result = Long::parseLong(target.subString(index), radix);
    if (negative == true) {
        result = -result.longValue();
    }

    return result;
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
    if (radix != 16) {
        return -1;
    }

    static long maxValue = 0x7fffffffffffffffL;
    static long minValue = 0x8000000000000000L;

    long result = 0;
    boolean negative = false;
    int index = 0;
    int length = target.length();
    long limit = -maxValue;
    long multmin;
    int digit;

    if (length > 0) {
        char firstChar = target.charAt(0);
        if (firstChar < '0') { // Possible leading "+" or "-"
            if (firstChar == '-') {
                negative = true;
                limit = minValue;
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
            digit = Character::digit(target.charAt(index++), radix);
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
 * Long to hex string
 * @param target
 * @return String
 */
String Long::toHexString(long target) {
    return toUnsignedString0(target, 4);
}

/**
 * Format unsigned long
 * @param val
 * @param shift
 * @param buf
 * @param offset
 * @param len
 * @return int
 */
int Long::formatUnsignedLong(long val, int shift, Array<char> &buf, int offset, int len) {
    int charPos = len;
    int radix = 1 << shift;
    int mask = radix - 1;

    //FIXME: move this to Integer.digits
    static char digits[] = {
            '0' , '1' , '2' , '3' , '4' , '5' ,
            '6' , '7' , '8' , '9' , 'a' , 'b' ,
            'c' , 'd' , 'e' , 'f' , 'g' , 'h' ,
            'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
            'o' , 'p' , 'q' , 'r' , 's' , 't' ,
            'u' , 'v' , 'w' , 'x' , 'y' , 'z'
    };

    do {
        buf[offset + --charPos] = digits[((int) val) & mask];
        val >>= shift;
    } while (val != 0 && charPos > 0);

    return charPos;
}


/**
 * Returns the number of zero bits
 * @param target
 * @return int
 */
int Long::numberOfLeadingZeros(long target) {
    // HD, Figure 5-6
    if (target == 0)
        return 64;
    int n = 1;
    long x = (target >> 32);
    if (x == 0) { n += 32; x = (int)target; }
    if (x >> 16 == 0) { n += 16; x <<= 16; }
    if (x >> 24 == 0) { n +=  8; x <<=  8; }
    if (x >> 28 == 0) { n +=  4; x <<=  4; }
    if (x >> 30 == 0) { n +=  2; x <<=  2; }
    n -= x >> 31;
    return n;
}

/**
 * Format a long (treated as unsigned) into a String.
 * @param val
 * @param shift
 * @return String
 */
String Long::toUnsignedString0(long val, int shift) {
    // assert shift > 0 && shift <=5 : "Illegal shift value";
    static int SIZE = 64;

    int mag = SIZE - Long::numberOfLeadingZeros(val);
    int chars = Math::max(((mag + (shift - 1)) / shift), 1);

    Array<char> buff;
    for (int i = 0; i < chars; ++i) { //Set empty array
        buff.push('0');
    }

    formatUnsignedLong(val, shift, buff, 0, chars);

    String result = String::fromCharArray(buff);
    return result;
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

