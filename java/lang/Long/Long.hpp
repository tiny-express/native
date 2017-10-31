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

#ifndef NATIVE_JAVA_LANG_LONG_HPP
#define NATIVE_JAVA_LANG_LONG_HPP

#include "../../../kernel/String.hpp"
#include "../Number/Number.hpp"
#include "../String/String.hpp"

namespace Java {
    namespace Lang {

        class Long : public Number {

        private:
            long long original;
            string originalString;

        public:
            /**
             * A constant holding the maximum value a long long can have, 2^63-1.
             */
            static const long long MAX_VALUE = 0x7fffffffffffffffL;;

            /**
             * A constant holding the minimum value a long long can have, -2^63.
             */
            static const long long MIN_VALUE = 0x8000000000000000L;;

            /**
             * The number of bits used to represent a long long value in two's complement binary form.
             */
            static const long int SIZE = 64;

        public:
            /**
             * Default constructor
             *
             * @return Long
             */
            Long();

            /**
             * Create new instance with an long long value
             *
             * @param long long value
             * @return Long
             */
            Long(long long value);

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
             * complement binary representation of the specified long long value.
             *
             * @param long long i
             * @return int
             */
            static long int bitCount(long long i);

            /**
             * Returns the value of this Long as a int
             * There's not correct byte in C++, should to convert to long int to make this function same as Java
             *
             * @return int
             */
            long int byteValue();

            /**
             * Compares two long long values numerically.
             *
             * @param long long x
             * @param long long y
             * @return int
             */
            static long int compare(long long x, long long y);

            /**
             * Compares two Long objects numerically.
             *
             * @param Long anotherLong
             * @return int
             */
            long int compareTo(Long anotherLong);

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
             * Determines the long long value of the system property with the specified name.
             *
             * @param String nm
             * @return Long
             */
            static Long getLong(String nm);

            /**
             * Determines the long long value of the system property with the specified name.
             *
             * @param String nm
             * @param long long val
             * @return Long
             */
            static Long getLong(String nm, long long val);

            /**
             * Returns the long long value of the system property with the specified name.
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
            long int hashCode();

            /**
             * Returns a long long value with at most a single one-bit, in the position of the highest-order ("leftmost")
             * one-bit in the specified long long value.
             *
             * @param long long i
             * @return long
             */
            static long long highestOneBit(long long i);

            /**
             * Returns the value of this Long as an int.
             *
             * @return int
             */
            long int intValue() const;

            /**
             * Returns the value of this Long as a long long value.
             *
             * @return long
             */
            long long longValue() const;

            /**
             * Returns a long long value with at most a single one-bit, in the position of the lowest-order ("rightmost")
             * one-bit in the specified long long value.
             *
             * @param long long i
             * @return long
             */
            static long long lowestOneBit(long long i);

            /**
             * Returns the number of zero bits preceding the highest-order ("leftmost") one-bit
             * in the two's complement binary representation of the specified long long value.
             *
             * @param long long i
             * @return int
             */
            static long int numberOfLeadingZeros(long long i);

            /**
             * Returns the number of zero bits following the lowest-order ("rightmost") one-bit
             * in the two's complement binary representation of the specified long long value.
             *
             * @param long long i
             * @return int
             */
            static long int numberOfTrailingZeros(long long i);

            /**
             * Parses the string argument as a signed decimal long.
             *
             * @param String s
             * @return long
             */
            static long long parseLong(String s);

            /**
             * Parses the string argument as a signed long long in the radix specified by the second argument.
             *
             * @param String s
             * @param long int radix
             * @return long
             */
            static long long parseLong(String s, long int radix);

            /**
             * Returns the value obtained by reversing the order of the bits
             * in the two's complement binary representation of the specified long long value.
             *
             * @param long long i
             * @return long
             */
            static long long reverse(long long i);

            /**
             * Returns the value obtained by reversing the order of the bytes
             * in the two's complement representation of the specified long long value.
             *
             * @param long long i
             * @return long
             */
            static long long reverseBytes(long long i);

            /**
             * Returns the value obtained by rotating the two's complement binary representation
             * of the specified long long value left by the specified number of bits.
             *
             * @param long long i
             * @param long int distance
             * @return long
             */
            static long long rotateLeft(long long i, long int distance);

            /**
             * Returns the value obtained by rotating the two's complement binary representation
             * of the specified long long value right by the specified number of bits.
             *
             * @param long long i
             * @param long int distance
             * @return long
             */
            static long long rotateRight(long long i, long int distance);

            /**
             * Returns the value of this Long as a short.
             *
             * @return short
             */
            short shortValue() const;

            /**
             * Returns the signum function of the specified long long value.
             *
             * @param long long i
             * @return int
             */
            static long int signum(long long i);

            /**
             * Returns a string representation of the long long argument as an unsigned integer in base 2.
             *
             * @param long long i
             * @return String
             */
            static String toBinaryString(long long i);

            /**
             * Returns a string representation of the long long argument as an unsigned integer in base 16.
             *
             * @param long long i
             * @return String
             */
            static String toHexString(long long i);

            /**
             * Returns a string representation of the long long argument as an unsigned integer in base 8.
             *
             * @param long long i
             * @return String
             */
            static String toOctalString(long long i);

            /**
             * Returns a String object representing this Long's value.
             *
             * @return String
             */
            String toString() const;

            /**
             * Returns a String object representing the specified long.
             *
             * @param long long i
             * @return String
             */
            static String toString(long long i);

            /**
             * Returns a Long instance representing the specified long long value.
             *
             * @param long long l
             * @return Long
             */
            static Long valueOf(long long l);

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
             * @param long int radix
             * @return Long
             */
            static Long valueOf(String s, long int radix);

        private:
            /**
             * Format a long long (treated as unsigned) into a String.
             *
             * @param long long val
             * @param long int shift
             * @return String
             */
            static String toUnsignedString0(long long val, long int shift);

            /**
             * Format a long long (treated as unsigned) into a character buffer.
             *
             * @param long long val
             * @param long int shift
             * @param Array<char> buf
             * @param long int offset
             * @param long int len
             * @return int
             */
            static long int formatUnsignedLong(long long val, long int shift, Array<char> &buf, long int offset, long int len);

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

            inline size_t operator()(const Long &target) const {
                return std::hash<std::string>{}(target.toString().toCharPointer());
            }
        };
    }
}

using namespace Java::Lang;

namespace std {
    template<>
    struct hash<Long> {
        std::size_t operator()(const Long &k) const {
            return Long()(k);
        }
    };
}

#endif // NATIVE_JAVA_LANG__HPP
