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
#include "../Comparable/Comparable.hpp"
#include "iostream"

using namespace Java::Lang;

/**
 * A constant holding the maximum value of type int
 */
static int MAX_VALUE = std::numeric_limits<int>::max(); // 2,147,483,647   2147483647

/**
 * A constant holding the minimum value of type int
 */
static int MIN_VALUE = std::numeric_limits<int>::min(); // –2,147,483,648  –2147483648

namespace Java {
	namespace Lang {
		class Integer;
		
		class Integer : public virtual Number,
		                public virtual Comparable<Integer> {
		private:
			int original;
			string string_original;

		public:            
			/**
             * Integer initialization
             *
             * @param original
             */
            Integer();

            /**
             * Integer initialization
             *
             * @param original
             */
			Integer(int original);

            /**
             * Integer initialization
             *
             * @param string_original
             */
            Integer(String inputStringtringInput);

            /**
             * Integer initialization
             *
             * @param original
             */
			Integer(const Integer &target);

            /**
             * Integer Destructor
             */
			~Integer();
		private:
      /**
      * return size of a string
      *
      * @param int
      * @return int
      */
     int stringSize(int x);

		public:
			char charValue() const;
			string stringValue() const;
			short shortValue() const;
			int intValue() const;
			long longValue() const;
			float floatValue() const;
			double doubleValue() const;		

           /**
            * Returns a String object representing
            * the specified integer.
            *
            * @param target
            * @return String
            */
			string toString() const;

			int compareTo(const Integer &o) const override {
				if (hashCode() == o.hashCode()) {
					return 0;
				}
				if (instanceof<Integer>(o)) {
					if (original < o.original) {
						return -1;
					} else if (original == o.original) {
						return 0;
					}
				}
				return 1;
			}
		
		public:
			Integer operator=(const Integer &target);
			Integer operator+(const Integer &target);
			Integer operator-(const Integer &target);
			Integer operator/(const Integer &target);;
			Integer operator*(const Integer &target);
			Integer operator%(const Integer &target);
			
			boolean operator==(const Integer &target) const;
			boolean operator!=(const Integer &target) const;
			boolean operator<(const Integer &target) const;
			boolean operator>(const Integer &target) const;
			boolean operator<=(const Integer &target) const;
			boolean operator>=(const Integer &target) const;
			
			void operator+=(const Integer &target);
			void operator-=(const Integer &target);
			void operator/=(const Integer &target);
			void operator*=(const Integer &target);
			void operator%=(const Integer &target);

			friend std::ostream &operator<<(std::ostream &os, const Integer &target) {
				std::cout << target.original;
				return os;
			}

			/**
            * Returns the number of one-bits in the
            * two's complement binary representation
            * of the specified int value.
            *
            * @param int intInput
            * @return int
            */
           static int bitCount(int intInput);

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
            * @param target
            * @return boolean
            */
           static int compare(int intInput_1, int intInput_2);

           /**
            * Compares two Integer objects numerically.
            *
            * @param target
            * @return boolean
            */
           // int compareTo(Integer anotherInteger);

           /**
            * Compares two int values numerically
            * treating the values as unsigned.
            *
            * @param target
            * @return boolean
            */
           static int compareUnsigned(int intInput_1, int intInput_2);

           /**
            * Decodes a String into an Integer .
            *
            * @param target
			      * @exception NumberFormatException  if the String does not
    	      *            contain a parsable integer.
			      *
            * @return Integer
            */
           // static Integer decode(String inputStringtringInput);

           /**
            * Returns the unsigned quotient of dividing
            * the first argument by the second where each
            * argument and the result is interpreted as an unsigned value. ...
            *
            * @param target
            * @return int
            */
           static int divideUnsigned(int dividend, int divisor);

           // /**
           //  * Returns the value of this Integer as a
           //  * double after a widening primitive conversion.
           //  *
           //  * @param target
           //  * @return double
           //  */
           // double doubleValue();

           // /**
           //  * Compares this object to the specified object.
           //  *
           //  * @param target
           //  * @return boolean
           //  */
           // static boolean equals(Integer obj);

           // /**
           //  * Returns the value of this Integer as
           //  * a float after a widening primitive conversion.
           //  *
           //  * @param target
           //  * @return float
           //  */
           // float floatValue();

           // /**
           //  * Determines the integer value of the
           //  * system property with the specified name.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static Integer getInteger(String inputString); // TODO(thoangminh): research it

           // /**
           //  * Determines the integer value of the
           //  * system property with the specified name.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static Integer getInteger(String inputString, int inputInt); 

           // /**
           //  * Returns the integer value of the system
           //  * property with the specified name.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static Integer getInteger(String inputString, Integer inputInteger);

           // /**
           //  * Returns a hash code for this Integer.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int hashCode();

           // /**
           //  * Returns a hash code for a int value;
           //  * compatible with Integer.hashCode() .
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int hashCode(int inputInt);

           /**
            * Returns an int value with at most
            * a single one-bit, in the position of
            * the highest-order ("leftmost") one-bit
            * in the specified int value.
            *
            * @param target
            * @return int
            */
           static int highestOneBit(int inputInt);

           // /**
           //  * Returns the value of
           //  * this Integer as an int .
           //  *
           //  * @param target
           //  * @return int
           //  */
           // int intValue();

           // /**
           //  * Returns the value of this Integer as a
           //  * long after a widening primitive conversion.
           //  *
           //  * @param target
           //  * @return long
           //  */
           // long longValue();

           // /**
           //  * Returns an int value with at most
           //  * a single one-bit, in the position of
           //  * the lowest-order ("rightmost") one-bit in the specified int value.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int lowestOneBit(int inputInt);

           // /**
           //  * Returns the greater of two int values
           //  * as if by calling Math#max(int,int) Math.max .
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int max(int a, int b);

           // /**
           //  * Returns the smaller of two int values
           //  * as if by calling Math#min(int,int) Math.min .
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int min(int a, int b);

           // /**
           //  * Returns the number of zero bits
           //  * preceding the highest-order
           //  * ("leftmost") one-bit in the two's complement
           //  * binary representation of the specified ...
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int numberOfLeadingZeros(int inputInt);

           // /**
           //  * Returns the number of zero bits
           //  * following the lowest-order ("rightmost")
           //  * one-bit in the two's complement binary
           //  * representation of the specified ...
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int numberOfTrailingZeros(int inputInt);

           // /**
           //  * Parses the string argument as
           //  * a signed integer in the radix
           //  * specified by the second argument.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int parseInt(String inputString, int radix);

           /**
            * Parses the string argument as
            * a signed decimal integer.
            *
            * @param target
            * @return int
            */  
            
          static int parseInt(String inputString);
           // *
           //  * Parses the string argument as an unsigned
           //  * integer in the radix specified by the second argument.
           //  *
           //  * @param target
           //  * @return int
            
           // static int parseUnsignedInt(String inputString, int radix);

           // /**
           //  * Parses the string argument as
           //  * an unsigned decimal integer.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int parseUnsignedInt(String inputString);

           // /**
           //  * Returns the unsigned remainder from dividing
           //  * the first argument by the second where each
           //  * argument and the result is interpreted as an unsigned ...
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int remainderUnsigned(int dividend, int divisor);

           // /**
           //  * Returns the value obtained by reversing the order
           //  * of the bits in the two's complement binary representation
           //  * of the specified int value.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int reverse(int inputInt);

           // /**
           //  * Returns the value obtained by reversing
           //  * the order of the bytes in the two's complement
           //  * representation of the specified int value.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int reverseBytes(int inputInt);

           // /**
           //  * Returns the value obtained by rotating the
           //  * two's complement binary representation of
           //  * the specified int value left by the specified number of ...
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int rotateLeft(int inputInt, int distance);

           // /**
           //  * Returns the value obtained by rotating the
           //  * two's complement binary representation of
           //  * the specified int value right by the specified number of ...
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int rotateRight(int inputInt, int distance);

           // /**
           //  * Returns the value of this Integer as
           //  * a short after a narrowing primitive conversion.
           //  *
           //  * @param target
           //  * @return short
           //  */
           // short shortValue();

           // /**
           //  * Returns the signum function
           //  * of the specified int value.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int signum(int inputInt);
           
           // /**
           //  * Adds two integers together as per the + operator.
           //  *
           //  * @param target
           //  * @return int
           //  */
           // static int sum(int a, int b);

           // /**
           //  * Returns a string representation of
           //  * the integer argument as an unsigned integer in base 2.
           //  *
           //  * @param target
           //  * @return string
           //  */
           // static string toBinaryString(int inputInt);

           // /**
           //  * Returns a string representation of
           //  * the integer argument as an unsigned integer in base 16.
           //  *
           //  * @param target
           //  * @return string
           //  */
           // static string toHexString(int inputInt);

           // /**
           //  * Returns a string representation of
           //  * the integer argument as an unsigned integer in base 8.
           //  *
           //  * @param target
           //  * @return string
           //  */
           // static string toOctalString(int inputInt);

           // /**
           //  * Returns a String object representing
           //  * this Integer 's value.
           //  *
           //  * @param target
           //  * @return String
           //  */
           // static String toString();

          /**
           * Returns a String object 
           * representing the specified integer.
           */
          // static String toString(int i);

           // /**
           //  * Returns a string representation of
           //  * the first argument in the radix
           //  * specified by the second argument.
           //  *
           //  * @param target
           //  * @return string
           //  */
           // static string toString(int inputInt, int radix);

           /**
            * Converts the argument to a long
            * by an unsigned conversion.
            *
            * @param target
            * @return long
            */
           static long toUnsignedLong(int x);

           // /**
           //  * Returns a string representation of
           //  * the first argument as an unsigned
           //  * integer value in the radix specified by the second argument.
           //  *
           //  * @param target
           //  * @return string
           //  */
           // static string toUnsignedString(int inputInt, int radix);

           // /**
           //  * Returns a string representation of
           //  * the argument as an unsigned decimal value.
           //  *
           //  * @param target
           //  * @return string
           //  */
           // static string toUnsignedString(int inputInt);

           // /**
           //  * Returns an Integer object holding
           //  * the value of the specified String .
           //  *
           //  * @param target
           //  * @return Integer
           //  */
           // static Integer valueOf(String inputString);

           // /**
           //  * Returns an Integer instance representing
           //  * the specified int value.
           //  *
           //  * @param target
           //  * @return Integer
           //  */
           // static Integer valueOf(int inputInt);

           // /**
           //  * Returns an Integer object
           //  * holding the value extracted from the specified String
           //  * when parsed with the radix given by the second argument.
           //  *
           //  * @param String inputStringtringInput, int radixIntInput
           //  * @return Integer
           //  */
           // static Integer valueOf(String inputStringtringInput, int radixIntInput);
		};
	}
}

#endif  // JAVA_LANG_INTEGER_HPP_
