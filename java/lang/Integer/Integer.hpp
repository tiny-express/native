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

#ifndef JAVA_LANG_INTEGER_HPP_
#define JAVA_LANG_INTEGER_HPP_

#include "../Number/Number.hpp"
#include "../String/String.hpp"
#include "../Comparable/Comparable.hpp"
#include <iostream>
#include <bitset>

using namespace Java::Lang;

namespace Java {
	namespace Lang {
		class Integer;
		
		class Integer : public Number , public virtual Comparable<Integer> {
        private:
			int original;
 			string originalString;

        private:
            /**
             * Max value of unsigned int
             */
            static constexpr unsigned int UNSIGNED_INT_MAX = 0xffffffff;

            /**
             * Max value of unsigned int
             */
            static constexpr unsigned int UNSIGNED_INT_MIN = 0;

        public:
            /**
             * The number of bits used to represent an int value in two's complement binary form.
             */
            static const int SIZE = 32;

            /**
             * The number of bytes used to represent a int value in two's complement binary form.
             */
            // TODO change from 8 to Byte::SIZE
            static const int BYTES = SIZE / 8;

            /**
             * A constant holding the maximum value of type int
             */
            static constexpr int MAX_VALUE = std::numeric_limits<int>::max();  // 2,147,483,647   2147483647

            /**
             * A constant holding the minimum value of type int
             */
            static constexpr int MIN_VALUE = std::numeric_limits<int>::min();  // –2,147,483,648  –2147483648

        public:
            /**
             * Integer initialization
             *
             */
            Integer();

            /**
             * Integer initialization with specific original value
             *
             * @param original
             */
            Integer(int original);

            /**
             * Integer initialization with specific original value from String
             *
             * @param inputString
             */
            Integer(String inputString);

            /**
             * Copy Constructor
             *
             * @param Integer &target
             */
            Integer(const Integer &target);

            /**
             * Integer Destructor
             */
            ~Integer();

        public:
            /**
             * Integer to Char
             *
             * @return char
             */
            char charValue() const;

            /**
             * Integer to string
             *
             * @return string
             */
            string stringValue() const;

            /**
             * Returns a String object representing
             * the specified integer.
             *
             * @return string
             */
            string toString() const override;

            /**
             * Assign value of this object same as target value
             *
             * @param target
             * @return Integer
             */
            Integer &operator=(const Integer &target);

            /**
             * Compares two Integer objects numerically.
             *
             * @param  Integer anotherInteger
             * @return the value 0 if this Integer is equal to the argument Integer;
             * a value less than 0 if this Integer is numerically less than the argument Integer;
             * and a value greater than 0 if this Integer is numerically greater than
             * the argument Integer (signed comparison).
             */
            int compareTo(const Integer &anotherInteger) const override ;

            /**
             * Make a summation with target Integer
             *
             * @return Integer
             */
            Integer operator+(const Integer &target);

            /**
             * Make a subtraction with target Integer
             *
             * @return Integer
             */
            Integer operator-(const Integer &target);

            /**
             * Make a division from this Integer with target
             *
             * @throw ArithmeticException if target is zero
             * @return Integer
             */
            Integer operator/(const Integer &target);

            /**
             * Make a multiple from this Integer with target
             *
             * @return Integer
             */
            Integer operator*(const Integer &target);

            /**
             * Make a modulo from this Integer with target
             *
             * @throw ArithmeticException if target is zero
             * @return Integer
             */
            Integer operator%(const Integer &target);

            /**
             * Compare this Integer is equal to target
             *
             * @return boolean
             */
            boolean operator==(const Integer &target) const;

            /**
             * Compare this Integer is not equal to target
             *
             * @return bool
             */
            boolean operator!=(const Integer &target) const;

            /**
             * Compare this Integer is less than target
             *
             * @return bool
             */
            boolean operator<(const Integer &target) const;

            /**
             * Compare this Integer is more than target
             *
             * @return bool
             */
            boolean operator>(const Integer &target) const;

            /**
             * Compare this Integer is equal to or less than target
             *
             * @return bool
             */
            boolean operator<=(const Integer &target) const;

            /**
             * Compare this Integer is equal to
             * or greater than target
             *
             * @return bool
             */
            boolean operator>=(const Integer &target) const;

            /**
             * Add target to this Integer and assign the value to this Integer
             *
             * @param target
             * @return Integer
             */
            Integer &operator+=(const Integer &target);

            /**
             * Subtract target from this Integer and assign the value to this Integer
             *
             * @param target
             * @return Integer
             */
            Integer &operator-=(const Integer &target);

            /**
             * Divide this Integer with target and assign the value to this Integer
             *
             * @throw ArithmeticException if target is zero
             * @param target
             * @return Integer
             */
            Integer &operator/=(const Integer &target);

            /**
             * Multiply this Integer with target and assign the value to this Integer
             *
             * @param target
             * @return Integer
             */
            Integer &operator*=(const Integer &target);

            /**
             * Modulus this Integer with target and assign the value to this Integer
             *
             * @throw ArithmeticException if target is zero
             * @param target
             * @return Integer
             */
            Integer &operator%=(const Integer &target);

            /**
             * Returns the number of one-bits in the
             * two's complement binary representation
             * of the specified int value.
             *
             * @param inputInt
             * @return int
             */
            static int bitCount(int inputInt);

            /**
             * Returns the value of this Integer as a byte
             * after a narrowing primitive conversion.
             *
             * @return byte
             */
            byte byteValue();

            /**
             * Compares two int values numerically.
             *
             * @param intA
             * @param intB
             * @return the value 0 if intA == intB; a value less than 0 if intA < intB;
             * and a value greater than 0 if intA > intB
             */
            static int compare(int intA, int intB);

            /**
             * Compares two int values numerically
             * treating the values as unsigned.
             *
             * @param intA
             * @param intA
             * @return the value 0 if intA == intB;
             * a value less than 0 if intA < intB as unsigned values;
             * and a value greater than 0 if intA > intB as unsigned values
             */
            static int compareUnsigned(int intA, int intB);

            /**
             * Decodes a String into an Integer. Accepts decimal, hexadecimal, and octal numbers
             *
             * @param inputString
             * @throw NumberFormatException - if the String does not contain a parsable integer
             * or the String contain a number outside the range of integer
             * @return an Integer object holding the int value represented by inputString
             */
            static Integer decode(String inputString);

            /**
             * Returns the unsigned quotient of dividing the first argument by the second
             * where each argument and the result is interpreted as an unsigned value
             *
             * @param dividend
             * @param divisor
             * @return the unsigned quotient of the first argument divided by the second argument
             */
            static int divideUnsigned(int dividend, int divisor);

            /**
             * Returns the value of this Integer as a double after
             * a widening primitive conversion.
             *
             * @return the value of this Integer as a double
             */
            double doubleValue() const override;

            /**
             * Compares this object to the specified object.
             *
             * @param object
             * @return true if the objects are the same; false otherwise.
             */
            // TODO need instanceof temporary use Integer instead of Object
            boolean equals(Integer object);

            /**
             * Returns the value of this Integer as
             * a float after a widening primitive conversion.
             *
             * @return the value of this Integer as a float
             */
            float floatValue() const override;

            /**
             * Determines the integer value of the system property with the specified name.
             *
             * @param propertyName
             * @throw SecurityException
             * @return the Integer value of the property.
             */
            // Not support this method yet
            // static Integer getInteger(String propertyName); // TODO(thoangminh): research it

            /**
             * Determines the integer value of the system property with the specified name.
             *
             * @param propertyName
             * @param defaultValue
             * @throw SecurityException
             * @return the Integer value of the property.
             */
            // Not support this method yet
            // static Integer getInteger(String propertyName, int defaultValue);

            /**
             * Returns the integer value of the system property with the specified name.
             *
             * @param propertyName
             * @param defaultValue
             * @throw SecurityException
             * @return Returns the integer value of the system property with the specified name.
             */
            // Not support this method yet
            // static Integer getInteger(String propertyName, Integer defaultValue);

            /**
             * Returns a hash code for this Integer.
             *
             * @return hash code of this Integer
             * equal to the primitive int value represented by this Integer object.
             */
            long hashCode() const override;

            /**
             * Returns a hash code for a int value;
             *
             * @param inputInt
             * @return a hash code value for inputInt
             */
            static int hashCode(int inputInt);

            /**
             * Returns an int value with at most a single one-bit, in the position of
             * the highest-order ("leftmost") one-bit in the specified int value.
             *
             * @param inputInt
             * @return an int value with a single one-bit,
             * in the position of the highest-order one-bit in the specified value,
             * or zero if the specified value is itself equal to zero.
             */
            static int highestOneBit(int inputInt);

            /**
             * Returns the value of this Integer as an int .
             *
             * @return the value of this Integer as an int
             */
            int intValue() const override;

            /**
             * Returns the value of this Integer as an long after
             * a widening primitive conversion
             *
             * @return he value of this Integer as an long
             */
            long longValue() const override;

            /**
             * Returns an int value with at most a single one-bit, in the position of
             * the lowest-order ("rightmost") one-bit in the specified int value.
             *
             * @param inputInt
             * @return an int value with a single one-bit, 
             * in the position of the lowest-order one-bit in the specified value, 
             * or zero if the specified value is itself equal to zero
             */
            static int lowestOneBit(int inputInt);

            /**
             * Returns the greater of two int values
             * as if by calling Math::max(int, int).
             *
             * @param intA
             * @param intB
             * @return intA if intA >= intB, else intB
             */
            static int max(int intA, int intB);

            /**
             * Returns the smaller of two int values
             * as if by calling Math::min(int,int).
             *
             * @param intA
             * @param intB
             * @return intA if intA <= intB, else intB
             */
            static int min(int intA, int intB);

            /**
             * Returns the number of zero bits preceding the highest-order
             * ("leftmost") one-bit in the two's complement
             * binary representation of the specified inputInt.
             *
             * @param inputInt
             * @return the number of zero bits preceding the highest-order ("leftmost") one-bit
             * in the two's complement binary representation of the specified int value,
             * or 32 if the value is equal to zero.
             */
            static int numberOfLeadingZeros(int inputInt);

            /**
             * Returns the number of zero bits following the lowest-order ("rightmost")
             * one-bit in the two's complement binary representation of the specified int value.
             *
             * @param inputInt
             * @return the number of zero bits preceding the highest-order ("leftmost") one-bit
             * in the two's complement binary representation of the specified int value,
             * or 32 if the value is equal to zero.
             */
            static int numberOfTrailingZeros(int inputInt);

            /**
             * Parses the string argument as
             * a signed integer in the radix
             * specified by the second argument.
             *
             * @param inputString
             * @param radix
             * @throw NumberFormatException if
             * The first argument is null or is a string of length zero.
             * The radix is either smaller than Character::MIN_RADIX or larger than Character::MAX_RADIX.
             * Any character of the string is not a digit of the specified radix,
             * The value represented by the string is not a value of type int.
             * @return int
             */
            static int parseInt(String inputString, int radix);

            /**
             * Parses the string argument as a signed decimal integer.
             *
             * @param inputString
             * @throw NumberFormatException - if the string does not contain a parsable integer.
             * @return the integer value represented by the argument in decimal.
             */
            static int parseInt(String inputString);

            /**
             * Parses the string argument as
             * a signed integer in the radix
             * specified by the second argument.
             *
             * @param inputString
             * @param radix
             * @throw NumberFormatException if
             * The first argument is null or is a string of length zero.
             * The radix is either smaller than Character::MIN_RADIX or larger than Character::MAX_RADIX.
             * Any character of the string is not a digit of the specified radix,
             * The value represented by the string is not a value of type unsigned int.
             * @return unsigned integer value represented by the argument in decimal
             */
            static int parseUnsignedInt(String inputString, int radix);

            /**
             * Parses the string argument as an unsigned decimal integer
             *
             * @param inputString
             * @throw NumberFormatException - if the string does not contain a parsable unsigned integer.
             * @return unsigned integer value represented by the argument in decimal
             */
            static int parseUnsignedInt(String inputString);

            /**
             * Returns the unsigned remainder from dividing the first argument by the second
             * where each argument and the result is interpreted as an unsigned value.
             *
             * @param dividend
             * @param divisor
             * @throw ArithmeticException if the divisor is zero
             * @return the unsigned remainder of the first argument divided by the second argument
             */
            static int remainderUnsigned(int dividend, int divisor);

            /**
             * Returns the value obtained by reversing the order
             * of the bits in the two's complement binary representation
             * of the specified int value.
             *
             * @param inputInt
             * @return the value obtained by reversing order of the bits in the specified int value.
             */
            static int reverse(int inputInt);

            /**
             * Returns the value obtained by reversing the order of the bytes in the two's complement
             * representation of the specified int value.
             *
             * @param inputInt
             * @return the value obtained by reversing the bytes in the specified int value.
             */
            static int reverseBytes(int inputInt);

            /**
             * Returns the value obtained by rotating the
             * two's complement binary representation of
             * the specified int value left by the specified number of bits
             *
             * @param inputInt
             * @param distance
             * @return the value obtained by rotating the two's complement binary
             * representation of the specified int value left by the specified number of bits.
             */
            static int rotateLeft(int inputInt, int distance);

            /**
             * Returns the value obtained by rotating the
             * two's complement binary representation of
             * the specified int value right by the specified number of bits
             *
             * @param inputInt
             * @param distance
             * @return the value obtained by rotating the two's complement binary
             * representation of the specified int value right by the specified number of bits.
             */
            static int rotateRight(int inputInt, int distance);

            /**
             * Returns the value of this Integer as
             * a short after a narrowing primitive conversion.
             *
             * @return the value of this Integer as a short
             */
            short shortValue() const override;

            /**
             * Returns the signum function of the specified int value.
             *
             * @param inputInt
             * @return the signum function of the specified int value.
             */
            static int signum(int inputInt);

            /**
             * Adds two integers together as per the + operator.
             *
             * @param intA
             * @param intA
             * @return sum of intA and intB
             */
            static int sum(int intA, int intB);

            /**
             * Returns a string representation of
             * the integer argument as an unsigned integer in base 2.
             *
             * @param inputInt
             * @return the string representation of the unsigned integer value
             * represented by the argument in binary
             */
            static String toBinaryString(int inputInt);

            /**
             * Returns a string representation of
             * the integer argument as an unsigned integer in base 16.
             *
             * @param inputInt
             * @return the string representation of the unsigned integer value
             * represented by the argument in hex
             */
            static String toHexString(int inputInt);

            /**
             * Returns a string representation of
             * the integer argument as an unsigned integer in base 8.
             *
             * @param inputInt
             * @return a String representation of the unsigned integer value
             * represented by the argument in base 8
             */
            static String toOctalString(int inputInt);

            /**
             * Returns a String object
             * representing the specified integer.
             *
             * @param inputInt
             * @return a String representation of inputInt in base 10.
             */
            static String toString(int inputInt);

            /**
             * Returns a string representation of the first argument in the radix
             * specified by the second argument.
             * Support radix 2, 8, 16, 10
             *
             * @param inputInt
             * @param radix
             * @throw UnsupportedOperationException - if radix is not support
             * @return a String representation of inputInt in the specified radix.
             */
            static String toString(int inputInt, int radix);

            /**
             * Converts the argument to a long by an unsigned conversion.
             *
             * @param longValue
             * @return the argument converted to long by an unsigned conversion
             */
            static long toUnsignedLong(int longValue);

            /**
             * Returns a string representation of the first argument as an unsigned
             * integer value in the radix specified by the second argument.
             * Support radix 2, 8, 16, 10
             *
             * @param inputInt
             * @param radix
             * @throw UnsupportedOperationException - if radix is not support
             * @return an unsigned String representation of the argument in the specified radix.
             */
            static String toUnsignedString(int inputInt, int radix);

            /**
             * Returns a string representation of
             * the argument as an unsigned decimal value.
             *
             * @param inputInt
             * @return an unsigned String representation of the argument.
             */
            static String toUnsignedString(int inputInt);

            /**
             * Returns an Integer object holding the value of the specified String .
             *
             * @param inputString
             * @throw NumberFormatException - if the string cannot be parsed as an integer.
             * @return an Integer object holding the value represented by the string argument.
             */
            static Integer valueOf(String inputString);

            /**
             * Returns an Integer instance representing the specified int value.
             *
             * @param inputInt
             * @return an Integer instance representing inputInt.
             */
            static Integer valueOf(int inputInt);

            /**
             * Returns an Integer object holding the value extracted from the specified String
             * when parsed with the radix given by the second argument.
             *
             * @param inputString
             * @param radix
             * @throw NumberFormatException - if the String does not contain a parsable int.
             * @return an Integer object holding the value represented by the string argument
             * in the specified radix.
             */
            static Integer valueOf(String inputString, int radix);

            /**
             * Stream insertion operator
             *
             * @param os
             * @param target
             * @return ostream
             */
            friend std::ostream &operator<<(std::ostream &os, const Integer &target) {
                std::cout << target.original;
                return os;
            }
		};
	}
}

#endif  // JAVA_LANG_INTEGER_HPP_
