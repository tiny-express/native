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

#ifndef JAVA_LANG_LONG_HPP_
#define JAVA_LANG_LONG_HPP_

#include "../Number/Number.hpp"
#include "../String/String.hpp"

namespace Java {
		namespace Lang {
				
				class Long : public Number {
				
				private:
						long original;
						string originalString;
				
				public:
						/**
						 * A constant holding the maximum value a long can have, 2^63-1.
						 */
						static const long MAX_VALUE = 0x7fffffffffffffffL;;
						
						/**
						 * A constant holding the minimum value a long can have, -2^63.
						 */
						static const long MIN_VALUE = 0x8000000000000000L;;
						
						/**
						 * The number of bits used to represent a long value in two's complement binary form.
						 */
						static const int SIZE = 64;
				
				public:
						/**
						 * Default constructor
						 *
						 * @return Long
						 */
						Long();
						
						/**
						 * Create new instance with an long value
						 *
						 * @param long value
						 * @return Long
						 */
						Long(long value);
						
						/**
						 * Create new instance with a copy of target
						 *
						 * @param Long target
						 * @return Long
						 */
						Long(const Long &target);
						
						/**
						 * Default destructor
						 */
						~Long();
				
				public:
						/**
						 * Returns the number of one-bits in the two's
						 * complement binary representation of the specified long value.
						 *
						 * @param long i
						 * @return int
						 */
						static int bitCount(long i);
						
						/**
						 * Returns the value of this Long as a int
						 * There's not correct byte in C++, should to convert to int to make this function same as Java
						 *
						 * @return int
						 */
						int byteValue();
						
						/**
						 * Compares two long values numerically.
						 *
						 * @param long x
						 * @param long y
						 * @return int
						 */
						static int compare(long x, long y);
						
						/**
						 * Compares two Long objects numerically.
						 *
						 * @param Long anotherLong
						 * @return int
						 */
						int compareTo(Long anotherLong);
						
						/**
						 * Decodes a String into a Long.
						 *
						 * @param String nm
						 * @return Long
						 */
						static Long decode(String nm);
						
						/**
						 * Returns the value of this Long as a double.
						 *
						 * @return double
						 */
						double doubleValue() const;
						
						/**
						 * Compares this object to the specified Long.
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean equals(Long target);
						
						/**
						 * Returns the value of this Long as a float.
						 *
						 * @return float
						 */
						float floatValue() const;
						
						/**
						 * Determines the long value of the system property with the specified name.
						 *
						 * @param String nm
						 * @return Long
						 */
						static Long getLong(String nm);
						
						/**
						 * Determines the long value of the system property with the specified name.
						 *
						 * @param String nm
						 * @param long val
						 * @return Long
						 */
						static Long getLong(String nm, long val);
						
						/**
						 * Returns the long value of the system property with the specified name.
						 *
						 * @param String nm
						 * @param Long val
						 * @return Long
						 */
						static Long getLong(String nm, Long val);
						
						/**
						 * Returns a hash code for this Long.
						 *
						 * @return int
						 */
						int hashCode();
						
						/**
						 * Returns a long value with at most a single one-bit, in the position of the highest-order ("leftmost")
						 * one-bit in the specified long value.
						 *
						 * @param long i
						 * @return long
						 */
						static long highestOneBit(long i);
						
						/**
						 * Returns the value of this Long as an int.
						 *
						 * @return int
						 */
						int intValue() const;
						
						/**
						 * Returns the value of this Long as a long value.
						 *
						 * @return long
						 */
						long longValue() const;
						
						/**
						 * Returns a long value with at most a single one-bit, in the position of the lowest-order ("rightmost")
						 * one-bit in the specified long value.
						 *
						 * @param long i
						 * @return long
						 */
						static long lowestOneBit(long i);
						
						/**
						 * Returns the number of zero bits preceding the highest-order ("leftmost") one-bit
						 * in the two's complement binary representation of the specified long value.
						 *
						 * @param long i
						 * @return int
						 */
						static int numberOfLeadingZeros(long i);
						
						/**
						 * Returns the number of zero bits following the lowest-order ("rightmost") one-bit
						 * in the two's complement binary representation of the specified long value.
						 *
						 * @param long i
						 * @return int
						 */
						static int numberOfTrailingZeros(long i);
						
						/**
						 * Parses the string argument as a signed decimal long.
						 *
						 * @param String s
						 * @return long
						 */
						static long parseLong(String s);
						
						/**
						 * Parses the string argument as a signed long in the radix specified by the second argument.
						 *
						 * @param String s
						 * @param int radix
						 * @return long
						 */
						static long parseLong(String s, int radix);
						
						/**
						 * Returns the value obtained by reversing the order of the bits
						 * in the two's complement binary representation of the specified long value.
						 *
						 * @param long i
						 * @return long
						 */
						static long reverse(long i);
						
						/**
						 * Returns the value obtained by reversing the order of the bytes
						 * in the two's complement representation of the specified long value.
						 *
						 * @param long i
						 * @return long
						 */
						static long reverseBytes(long i);
						
						/**
						 * Returns the value obtained by rotating the two's complement binary representation
						 * of the specified long value left by the specified number of bits.
						 *
						 * @param long i
						 * @param int distance
						 * @return long
						 */
						static long rotateLeft(long i, int distance);
						
						/**
						 * Returns the value obtained by rotating the two's complement binary representation
						 * of the specified long value right by the specified number of bits.
						 *
						 * @param long i
						 * @param int distance
						 * @return long
						 */
						static long rotateRight(long i, int distance);
						
						/**
						 * Returns the value of this Long as a short.
						 *
						 * @return short
						 */
						short shortValue() const;
						
						/**
						 * Returns the signum function of the specified long value.
						 *
						 * @param long i
						 * @return int
						 */
						static int signum(long i);
						
						/**
						 * Returns a string representation of the long argument as an unsigned integer in base 2.
						 *
						 * @param long i
						 * @return String
						 */
						static String toBinaryString(long i);
						
						/**
						 * Returns a string representation of the long argument as an unsigned integer in base 16.
						 *
						 * @param long i
						 * @return String
						 */
						static String toHexString(long i);
						
						/**
						 * Returns a string representation of the long argument as an unsigned integer in base 8.
						 *
						 * @param long i
						 * @return String
						 */
						static String toOctalString(long i);
						
						/**
						 * Returns a String object representing this Long's value.
						 *
						 * @return String
						 */
						string toString() const;
						
						/**
						 * Returns a String object representing the specified long.
						 *
						 * @param long i
						 * @return String
						 */
						static string toString(long i);
						
						/**
						 * Returns a Long instance representing the specified long value.
						 *
						 * @param long l
						 * @return Long
						 */
						static Long valueOf(long l);
						
						/**
						 * Returns a Long object holding the value of the specified String.
						 *
						 * @param String s
						 * @return Long
						 */
						static Long valueOf(String s);
						
						/**
						 * Returns a Long object holding the value extracted from the specified String
						 * when parsed with the radix given by the second argument.
						 *
						 * @param String s
						 * @param int radix
						 * @return Long
						 */
						static Long valueOf(String s, int radix);
				
				private:
						/**
						 * Format a long (treated as unsigned) into a String.
						 *
						 * @param long val
						 * @param int shift
						 * @return String
						 */
						static String toUnsignedString0(long val, int shift);
						
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
						static int formatUnsignedLong(long val, int shift, Array<char> &buf, int offset, int len);
				
				public:
						
						/**
						 * Assign value of this object same as value of target object
						 *
						 * @param target
						 * @return Long
						 */
						Long operator=(const Long &target);
						
						/**
						 * Sum two Long
						 *
						 * @param Long target
						 * @return Long
						 */
						Long operator+(const Long &target) const;
						
						/**
						 * Subtract two Long
						 *
						 * @param Long target
						 * @return
						 */
						Long operator-(const Long &target) const;
						
						/**
						 * Divide two Long
						 *
						 * @param Long target
						 * @return
						 */
						Long operator/(const Long &target) const;
						
						/**
						 * Modulo two Long
						 *
						 * @param Long target
						 * @return
						 */
						Long operator%(const Long &target) const;
						
						/**
						 * Multiply two Long
						 *
						 * @param Long target
						 * @return
						 */
						Long operator*(const Long &target) const;
						
						/**
						 * Compare equal
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean operator==(const Long &target) const;
						
						/**
						 * Compare not equal
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean operator!=(const Long &target) const;
						
						/**
						 * Compare less than
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean operator<(const Long &target) const;
						
						/**
						 * Compare more than
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean operator>(const Long &target) const;
						
						/**
						 * Compare less than or equal
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean operator<=(const Long &target) const;
						
						/**
						 * Compare more than or equal
						 *
						 * @param Long target
						 * @return boolean
						 */
						boolean operator>=(const Long &target) const;
						
						/**
						 * Subtract this with target
						 *
						 * @param target
						 */
						void operator-=(const Long &target);
						
						/**
						 * Sum this with target
						 *
						 * @param target
						 */
						void operator+=(const Long &target);
						
						/**
						 * Multiply this with target
						 *
						 * @param target
						 */
						void operator*=(const Long &target);
						
						/**
						 * Devide this with target
						 *
						 * @param target
						 */
						void operator/=(const Long &target);
						
						/**
						 * Modulo this with target
						 *
						 * @param target
						 */
						void operator%=(const Long &target);
				
				public:
						friend std::ostream &operator<<(std::ostream &os, const Long &target) {
							os << target.original;
							return os;
						}
				};
		}
}

#endif  // JAVA_LANG__HPP_
