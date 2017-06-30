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
 * A constant holding the maximum value a long can have, 2^63-1.
 */
long Long::MAX_VALUE = 0x7fffffffffffffffL;;

/**
 * A constant holding the minimum value a long can have, -2^63.
 */
long Long::MIN_VALUE = 0x8000000000000000L;;

/**
 * The number of bits used to represent a long value in two's complement binary form.
 */
int Long::SIZE = 64;

/**
 * Default constructor
 * @return
 */
Long::Long() {
    this->original = 0;
}

/**
 * Create new instance with an long value
 * @param long value
 * @return Long
 */
Long::Long(long value) {
    this->original = value;
}

/**
 * Create new instance with a copy of target
 * @param Long target
 * @return Long
 */
Long::Long(const Long &target) {
    this->original = target.original;
}

/**
 * Default destructor
 */
Long::~Long() {
}

int Long::bitCount(long i) {
    return -1;
}

/**
 * Returns the value of this Long as a byte.
 * @return byte
 */
byte Long::byteValue() const {
    return 0;
}

/**
 * Compares two long values numerically.
 * @param long x
 * @param long y
 * @return int
 */
int Long::compare(long x, long y) {
    return -1;
}

/**
 * Compares two Long objects numerically.
 * @param Long anotherLong
 * @return int
 */
int	Long::compareTo(Long anotherLong) {
    return -1;
}

/**
 * Decodes a String into a Long.
 * @param String nm
 * @return Long
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
    if (negative) {
        result = -result.longValue();
    }

    return result;
}

/**
 * Returns the value of this Long as a double.
 * @return double
 */
double Long::doubleValue() const {
    return 0;
}

/**
 * Compares this object to the specified object.
 * @param Object obj
 * @return boolean
 */
boolean	Long::equals(Object obj) {
    return false;
}

/**
 * Returns the value of this Long as a float.
 * @return float
 */
float Long::floatValue() const {
    return 0;
}

/**
 * Determines the long value of the system property with the specified name.
 * @param String nm
 * @return Long
 */
Long Long::getLong(String nm) {
    return Long();
}

/**
 * Determines the long value of the system property with the specified name.
 * @param String nm
 * @param long val
 * @return Long
 */
Long Long::getLong(String nm, long val) {
    return Long();
}

/**
 * Returns the long value of the system property with the specified name.
 * @param String nm
 * @param Long val
 * @return Long
 */
Long Long::getLong(String nm, Long val) {
    return Long();
}

/**
 * Returns a hash code for this Long.
 * @return int
 */
int	Long::hashCode() {
    return -1;
}

/**
 * Returns a long value with at most a single one-bit, in the position of the highest-order ("leftmost")
 * one-bit in the specified long value.
 * @param long i
 * @return long
 */
long Long::highestOneBit(long i) {
    return -1;
}

/**
 * Returns the value of this Long as an int.
 * @return int
 */
int	Long::intValue() const {
    return -1;
}

/**
 * Returns the value of this Long as a long value.
 * @return long
 */
long Long::longValue() const {
    return -1;
}

/**
 * Returns a long value with at most a single one-bit, in the position of the lowest-order ("rightmost")
 * one-bit in the specified long value.
 * @param long i
 * @return long
 */
long Long::lowestOneBit(long i) {
    return -1;
}

/**
 * Returns the number of zero bits preceding the highest-order ("leftmost") one-bit
 * in the two's complement binary representation of the specified long value.
 * @param long i
 * @return int
 */
int Long::numberOfLeadingZeros(long i) {
    // HD, Figure 5-6
    if (i == 0)
        return 64;
    int n = 1;
    long x = (i >> 32);
    if (x == 0) { n += 32; x = (int)i; }
    if (x >> 16 == 0) { n += 16; x <<= 16; }
    if (x >> 24 == 0) { n +=  8; x <<=  8; }
    if (x >> 28 == 0) { n +=  4; x <<=  4; }
    if (x >> 30 == 0) { n +=  2; x <<=  2; }
    n -= x >> 31;
    return n;
}

/**
 * Returns the number of zero bits following the lowest-order ("rightmost") one-bit
 * in the two's complement binary representation of the specified long value.
 * @param long i
 * @return int
 */
int Long::numberOfTrailingZeros(long i) {
    return -1;
}

/**
 * Parses the string argument as a signed decimal long.
 * @param String s
 * @return long
 */
long Long::parseLong(String s) {
    long result = string_to_long(s.toString());
    return result;
}

/**
 * Parses the string argument as a signed long in the radix specified by the second argument.
 * @param String s
 * @param int radix
 * @return long
 */
long Long::parseLong(String s, int radix) {
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
    int length = s.length();
    long limit = -maxValue;
    long multmin;
    int digit;

    if (length > 0) {
        char firstChar = s.charAt(0);
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
 * @param long i
 * @return long
 */
long Long::reverse(long i) {
    return -1;
}

/**
 * Returns the value obtained by reversing the order of the bytes
 * in the two's complement representation of the specified long value.
 * @param long i
 * @return long
 */
long Long::reverseBytes(long i) {
    return -1;
}

/**
 * Returns the value obtained by rotating the two's complement binary representation
 * of the specified long value left by the specified number of bits.
 * @param long i
 * @param int distance
 * @return long
 */
long Long::rotateLeft(long i, int distance) {
    return -1;
}

/**
 * Returns the value obtained by rotating the two's complement binary representation
 * of the specified long value right by the specified number of bits.
 * @param long i
 * @param int distance
 * @return long
 */
long Long::rotateRight(long i, int distance) {
    return -1;
}

/**
 * Returns the value of this Long as a short.
 * @return short
 */
short Long::shortValue() const {
    return -1;
}

/**
 * Returns the signum function of the specified long value.
 * @param long i
 * @return int
 */
int Long::signum(long i) {
    return -1;
}

/**
 * Returns a string representation of the long argument as an unsigned integer in base 2.
 * @param long i
 * @return String
 */
String Long::toBinaryString(long i) {
    return String();
}

/**
 * Returns a string representation of the long argument as an unsigned integer in base 16.
 * @param long i
 * @return String
 */
String Long::toHexString(long i) {
    return toUnsignedString0(i, 4);
}

/**
 * Returns a string representation of the long argument as an unsigned integer in base 8.
 * @param long i
 * @return String
 */
String Long::toOctalString(long i) {
    return String();
}

/**
 * Returns a String object representing this Long's value.
 * @return String
 */
String Long::toString() {
    return string_from_long(this->original);
}

/**
 * Returns a String object representing the specified long.
 * @param long i
 * @return String
 */
String Long::toString(long i) {
    return String();
}

/**
 * Returns a string representation of the first argument in the radix specified by the second argument.
 * @param int i
 * @param int radix
 * @return String
 */
String Long::toString(long i, int radix) {
    return String();
}

/**
 * Returns a Long instance representing the specified long value.
 * @param long l
 * @return Long
 */
Long Long::valueOf(long l) {
    return Long();
}

/**
 * Returns a Long object holding the value of the specified String.
 * @param String s
 * @return Long
 */
Long Long::valueOf(String s) {
    return Long();
}

/**
 * Returns a Long object holding the value extracted from the specified String
 * when parsed with the radix given by the second argument.
 * @param String s
 * @param int radix
 * @return Long
 */
Long Long::valueOf(String s, int radix) {
    return Long();
}

/**
 * Format a long (treated as unsigned) into a String.
 * @param long val
 * @param int shift
 * @return String
 */
String toUnsignedString0(long val, int shift) {
    return String();
}

/**
 * Format a long (treated as unsigned) into a character buffer.
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
 * Format a long (treated as unsigned) into a String.
 * @param long val
 * @param int shift
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
 * Sum two Long
 * @param Long target
 * @return Long
 */
Long Long::operator+(const Long &target) const {
    Long result = this->original + target.original;
    return result;
}

/**
 * Subtract two Long
 * @param Long target
 * @return
 */
Long Long::operator-(const Long &target) const {
    Long result = this->original - target.original;
    return result;
}

/**
 * Divide two Long
 * @param Long target
 * @return
 */
Long Long::operator/(const Long &target) const {
    Long result = this->original / target.original;
    return result;
}

/**
 * Modulo two Long
 * @param Long target
 * @return
 */
Long Long::operator%(const Long &target) const {
    Long result = this->original % target.original;
    return result;
}

/**
 * Multiply two Long
 * @param Long target
 * @return
 */
Long Long::operator*(const Long &target) const {
    Long result = this->original * target.original;
    return result;
}

/**
 * Compare equal
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
 * @param target
 */
void Long::operator-=(const Long &target) {
    this->original -= target.original;
}

/**
 * Sum this with target
 * @param target
 */
void Long::operator+=(const Long &target) {
    this->original += target.original;
}

/**
 * Multiply this with target
 * @param target
 */
void Long::operator*=(const Long &target) {
    this->original *= target.original;
}

/**
 * Devide this with target
 * @param target
 */
void Long::operator/=(const Long &target) {
    this->original /= target.original;
}

/**
 * Modulo this with target
 * @param target
 */
void Long::operator%=(const Long &target) {
    this->original %= target.original;
}