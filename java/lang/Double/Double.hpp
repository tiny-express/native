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

#ifndef NATIVE_JAVA_LANG_DOUBLE_HPP
#define NATIVE_JAVA_LANG_DOUBLE_HPP

#include "../Number/Number.hpp"

namespace Java {
	namespace Lang {
		class Double : public Number {
		private:
			double original;
            string string_original;

		public:
            /**
             * Double initialization
             *
             * @param original
             */
            Double();

            /**
             * Double initialization
             *
             * @param original
             */
			Double(double original);

            /**
             * Double initialization
             *
             * @param original
             */
			Double(const Double &target);

            /**
             * Double Destructor
             */
			~Double();

        public:
            /// ---------- Arithmetic Operators ----------

            /**
             * Adds two operands
             *
             * @return Double
             */
            Double operator+(const Double &target);

            /**
             * Subtracts second operand from the first
             *
             * @return Double
             */
            Double operator-(const Double &target);

            /**
             *  Multiplies both operands
             *
             * @return Double
             */
            Double operator*(const Double &target);

            /**
             * Divides numerator by de-numerator
             *
             * @return Double
             */
            Double operator/(const Double &target);

//             For Integer, Long, Short ...
//            /**
//             * Modulus Operator and remainder
//             * of after an integer division
//             *
//             * @return Double
//             */
//            Double operator%(const Double &target) const;

//            /**
//             * Increment operator,
//             * increases integer value by one
//             *
//             * @return Double
//             */
//            Double operator++(const Double &target) const;

//            /**
//             * Decrement operator,
//             * decreases integer value by one
//             *
//             * @return Double
//             */
//            Double operator--(const Double &target) const;

            /// ---------- Relational Operators ----------

            /**
             * Checks if the values of two operands
             * are equal or not,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator==(const Double &target) const;

            /**
             * Checks if the values of two operands
             * are equal or not,
             * if values are not equal
             * then condition becomes true
             *
             * @return boolean
             */
            boolean operator!=(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is greater than the value of right operand,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator>(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is less than the value of right operand,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator<(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is greater than or equal to the value of right operand,
             * if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator>=(const Double &target) const;

            /**
             *  Checks if the value of left operand
             *  is less than or equal to the value of right operand,
             *  if yes then condition becomes true.
             *
             * @return boolean
             */
            boolean operator<=(const Double &target) const;

            /// ---------- Logical Operators ----------

            /**
             *  Called Logical AND operator.
             *  If both the operands are non-zero,
             *  then condition becomes true.
             *
             * @return boolean
             */
            boolean operator&&(const Double &target) const;

            /**
             *  Called Logical OR Operator.
             *  If any of the two operands is non-zero,
             *  then condition becomes true.
             *
             * @return boolean
             */
            boolean operator||(const Double &target) const;

//            /**
//             *  Called Logical NOT Operator.
//             *  Use to reverses the logical state of its operand.
//             *  If a condition is true,
//             *  then Logical NOT operator will make false.
//             *
//             * @return boolean
//             */
//            boolean operator!(const Double &target) const;


//            /// ---------- Bitwise Operators ---------- // For Integer, Long, Short ...
//
//            /**
//             *  Binary AND Operator copies a bit
//             *  to the result if it exists in both operands.
//             *
//             * @return boolean
//             */
//            boolean operator&(const Double &target) const;
//
//            /**
//             *  Binary OR Operator copies a bit
//             *  if it exists in either operand.
//             *
//             * @return boolean
//             */
//            boolean operator|(const Double &target) const;
//
//            /**
//             *  Binary XOR Operator copies the bit
//             *  if it is set in one operand but not both.
//             *
//             * @return boolean
//             */
//            boolean operator^(const Double &target) const;
//
//            /**
//             *  Binary Ones Complement Operator
//             *  is unary and has the effect of 'flipping' bits.
//             *
//             * @return Double
//             */
//            Double operator~(const Double &target);
//
//            /**
//             *  Binary Left Shift Operator.
//             *  The left operands value is moved left
//             *  by the number of bits specified by the right operand.
//             *
//             * @return Double
//             */
//            Double operator<<(const Double &target) const;
//
//            /**
//             *  Binary Right Shift Operator.
//             *  The left operands value is moved right
//             *  by the number of bits specified by the right operand.
//             *
//             * @return Double
//             */
//            Double operator>>(const Double &target) const;

            /// ---------- Assignment Operators ----------

            /**
             * Simple assignment operator,
             * Assigns values from right side operands
             * to left side operand
             *
             * @param target
             * @return Double
             */
            Double operator=(const Double &target);

            /**
             * Add AND assignment operator,
             * It adds right operand to the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator+=(const Double &target) const;

            /**
             * Subtract AND assignment operator,
             * It subtracts right operand from the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator-=(const Double &target) const;

            /**
             * Multiply AND assignment operator,
             * It multiplies right operand with the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator*=(const Double &target) const;

            /**
             * Divide AND assignment operator,
             * It divides left operand with the right operand
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
            Double operator/=(const Double &target) const;

            /**
             * Modulus AND assignment operator,
             * It takes modulus using two operands
             * and assign the result to left operand
             *
             * @param target
             * @return Double
             */
//              For ingeger , long , short ... only
//            Double operator%=(const Double &target) const;
//
//            /**
//             * Left shift AND assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator<<=(const Double &target) const;
//
//            /**
//             * Right shift AND assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator>>=(const Double &target) const;
//
//            /**
//             * Bitwise AND assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator&=(const Double &target) const;
//
//            /**
//             * bitwise exclusive OR and assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator^=(const Double &target) const;
//
//            /**
//             * bitwise inclusive OR and assignment operator
//             *
//             * @param target
//             * @return Double
//             */
//            Double operator|=(const Double &target) const;

            /// ---------- Method Value ----------

            /**
             * Double to Char
             *
             * @return char
             */
            char charValue() const;

            /**
             * Double to String
             *
             * @return CString
             */
            string stringValue() const;

            /**
             * Short value of Double
             *
             * @return short
             */
            short shortValue() const;

            /**
             * Double value in Double
             *
             * @return int
             */
            int intValue() const;

            /**
             * Double value in Long
             *
             * @return long
             */
            long longValue() const;

            /**
             * Double value in float
             *
             * @return float
             */
            float floatValue() const;

            /**
             * Double value in double
             *
             * @return double
             */
            double doubleValue() const;

            /**
             * Double to String
             *
             * @return String
             */
            string toString() const;

            /**
             * Parse double
             *
             * @param target
             * @return double
             */
            static Double parseDouble(String target);
            /**
             * Returns the value of this {@code Double} as a {@code byte}
             * after a narrowing primitive conversion.
             *
             * @return  the {@code double} value represented by this object
             *          converted to type {@code byte}
             */
            byte byteValue() const ;

            /// ---------- Method ----------

            /**
             * Compares the two specified {@code double} values. The sign
             * of the integer value returned is the same as that of the
             * integer that would be returned by the call:
             *    Double(double1).compareTo(Double(d2))
             *
             * @param   double1        the first {@code double} to compare
             * @param   double2        the second {@code double} to compare
             * @return  the value {@code 0} if {@code double1} is
             *          numerically equal to {@code double2}; a value less than
             *          {@code 0} if {@code double1} is numerically less than
             *          {@code double2}; and a value greater than {@code 0}
             *          if {@code double1} is numerically greater than
             *          {@code double2}.
             */
            static int compare(double double1, double double2);

            /**
             * Compares two {@code Double} objects numerically.  There
             * are two ways in which comparisons performed by this method
             * differ from those performed by the Java language numerical
             * comparison operators ({@code <, <=, ==, >=, >})
             * when applied to primitive {@code double} values:
             *
             *          {@code Double.NaN} is considered by this method
             *          to be equal to itself and greater than all other
             *          {@code double} values (including
             *          {@code Double.POSITIVE_INFINITY}).
             * 
             *          {@code 0.0d} is considered by this method to be greater
             *          than {@code -0.0d}.
             * 
             * This ensures that the natural ordering of
             * {@code Double} objects imposed by this method is consistent
             * with equals.
             *
             * @param   anotherDouble   the {@code Double} to be compared.
             * @return  the value {@code 0} if {@code anotherDouble} is
             *          numerically equal to this {@code Double}; a value
             *          less than {@code 0} if this {@code Double}
             *          is numerically less than {@code anotherDouble};
             *          and a value greater than {@code 0} if this
             *          {@code Double} is numerically greater than
             *          {@code anotherDouble}.
             */
            int compareTo(Double anotherDouble);

            /**
             * Returns a representation of the specified floating-point value
             * according to the IEEE 754 floating-point "double
             * format" bit layout.
             *
             * Bit 63 (the bit that is selected by the mask
             * {@code 0x8000000000000000L}) represents the sign of the
             * floating-point number. Bits
             * 62-52 (the bits that are selected by the mask
             * {@code 0x7ff0000000000000L}) represent the exponent. Bits 51-0
             * (the bits that are selected by the mask
             * {@code 0x000fffffffffffffL}) represent the significand
             * (sometimes called the mantissa) of the floating-point number.
             *
             * If the argument is positive infinity, the result is
             * {@code 0x7ff0000000000000L}.
             *
             * If the argument is negative infinity, the result is
             * {@code 0xfff0000000000000L}.
             *
             * If the argument is NaN, the result is
             * {@code 0x7ff8000000000000L}.
             *
             * In all cases, the result is a {@code long} integer that, when
             * given to the {@link #longBitsToDouble(long)} method, will produce a
             * floating-point value the same as the argument to
             * {@code doubleToLongBits} (except all NaN values are
             * collapsed to a single "canonical" NaN value).
             *
             * @param   value   a {@code double} precision floating-point number.
             * @return the bits that represent the floating-point number.
             */
            static long doubleToLongBits(double valueDouble);

            /**
             * Returns a representation of the specified floating-point value
             * according to the IEEE 754 floating-point "double
             * format" bit layout, preserving Not-a-Number (NaN) values.
             *
             * Bit 63 (the bit that is selected by the mask
             * {@code 0x8000000000000000L}) represents the sign of the
             * floating-point number. Bits
             * 62-52 (the bits that are selected by the mask
             * {@code 0x7ff0000000000000L}) represent the exponent. Bits 51-0
             * (the bits that are selected by the mask
             * {@code 0x000fffffffffffffL}) represent the significand
             * (sometimes called the mantissa) of the floating-point number.
             *
             * If the argument is positive infinity, the result is
             * {@code 0x7ff0000000000000L}.
             *
             * If the argument is negative infinity, the result is
             * {@code 0xfff0000000000000L}.
             *
             * If the argument is NaN, the result is the {@code long}
             * integer representing the actual NaN value.  Unlike the
             * {@code doubleToLongBits} method,
             * {@code doubleToRawLongBits} does not collapse all the bit
             * patterns encoding a NaN to a single "canonical" NaN
             * value.
             *
             * In all cases, the result is a {@code long} integer that,
             * when given to the {@link #longBitsToDouble(long)} method, will
             * produce a floating-point value the same as the argument to
             * {@code doubleToRawLongBits}.
             *
             * @param   value   a {@code double} precision floating-point number.
             * @return the bits that represent the floating-point number.
             * @since 1.3
             */
            static long doubleToRawLongBits(double value);

            /**
             * Compares this object against the specified object.  The result
             * is {@code true} if and only if the argument is not
             * {@code null} and is a {@code Double} object that
             * represents a {@code double} that has the same value as the
             * {@code double} represented by this object. For this
             * purpose, two {@code double} values are considered to be
             * the same if and only if the method {@link
             * #doubleToLongBits(double)} returns the identical
             * {@code long} value when applied to each.
             *
             * Note that in most cases, for two instances of class
             * {@code Double}, {@code d1} and {@code d2}, the
             * value of {@code d1.equals(d2)} is {@code true} if and
             * only if
             *
             * 
             *  {@code d1.doubleValue() == d2.doubleValue()}
             * 
             *
             * also has the value {@code true}. However, there are two
             * exceptions:
             * 
             * If {@code d1} and {@code d2} both represent
             *     {@code Double.NaN}, then the {@code equals} method
             *     returns {@code true}, even though
             *     {@code Double.NaN==Double.NaN} has the value
             *     {@code false}.
             * If {@code d1} represents {@code +0.0} while
             *     {@code d2} represents {@code -0.0}, or vice versa,
             *     the {@code equal} test has the value {@code false},
             *     even though {@code +0.0==-0.0} has the value {@code true}.
             * </ul>
             * This definition allows hash tables to operate properly.
             * @param   obj   the object to compare with.
             * @return  {@code true} if the objects are the same;
             *          {@code false} otherwise.
             * @see java.lang.Double#doubleToLongBits(double)
             */
            boolean equals(const Double &object);

            /**
             * Returns a hash code for this {@code Double} object. The
             * result is the exclusive OR of the two halves of the
             * {@code long} integer bit representation, exactly as
             * produced by the method {@link #doubleToLongBits(double)}, of
             * the primitive {@code double} value represented by this
             * {@code Double} object. That is, the hash code is the value
             * of the expression:
             *
             *  {@code (int)(v^(v>>>32))}
             *
             * where {@code v} is defined by:
             *
             *  {@code long v = Double.doubleToLongBits(this.doubleValue());}
             *
             * @return  a {@code hash code} value for this object.
             */
            long hashCode();

            /**
             * Returns a hash code for a {@code double} value; compatible with
             * {@code Double.hashCode()}.
             *
             * @param value the value to hash
             * @return a hash code value for a {@code double} value.
             */
            static long hashCode(double value);

            /**
             * Returns {@code true} if the argument is a finite floating-point
             * value; returns {@code false} otherwise (for NaN and infinity
             * arguments).
             *
             * @param d the {@code double} value to be tested
             * @return {@code true} if the argument is a finite
             * floating-point value, {@code false} otherwise.
             */
            static boolean isFinite(double d);

            /**
             * Returns {@code true} if the specified number is infinitely
             * large in magnitude, {@code false} otherwise.
             *
             * @param   v   the value to be tested.
             * @return  {@code true} if the value of the argument is positive
             *          infinity or negative infinity; {@code false} otherwise.
             */
            static boolean isInfinite(double v);

            /**
            * Returns {@code true} if this {@code Double} value is
            * infinitely large in magnitude, {@code false} otherwise.
            *
            * @return  {@code true} if the value represented by this object is
            *          positive infinity or negative infinity;
            *          {@code false} otherwise.
            */
            boolean isInfinite();

            /**
             * Returns {@code true} if the specified number is a
             * Not-a-Number (NaN) value, {@code false} otherwise.
             *
             * @param   v   the value to be tested.
             * @return  {@code true} if the value of the argument is NaN;
             *          {@code false} otherwise.
             */
            static boolean isNaN(double v);

            /**
             * Returns {@code true} if this {@code Double} value is
             * a Not-a-Number (NaN), {@code false} otherwise.
             *
             * @return  {@code true} if the value represented by this object is
             *          NaN; {@code false} otherwise.
             */
            boolean isNaN() ;

            /**
             * Returns the {@code double} value corresponding to a given
             * bit representation.
             * The argument is considered to be a representation of a
             * floating-point value according to the IEEE 754 floating-point
             * "double format" bit layout.
             *
             * If the argument is {@code 0x7ff0000000000000L}, the result
             * is positive infinity.
             *
             * If the argument is {@code 0xfff0000000000000L}, the result
             * is negative infinity.
             *
             * If the argument is any value in the range
             * {@code 0x7ff0000000000001L} through
             * {@code 0x7fffffffffffffffL} or in the range
             * {@code 0xfff0000000000001L} through
             * {@code 0xffffffffffffffffL}, the result is a NaN.  No IEEE
             * 754 floating-point operation provided by Java can distinguish
             * between two NaN values of the same type with different bit
             * patterns.  Distinct values of NaN are only distinguishable by
             * use of the {@code Double.doubleToRawLongBits} method.
             *
             * In all other cases, let s, e, and m be three
             * values that can be computed from the argument:
             *
             * {@code
             * int s = ((bits >> 63) == 0) ? 1 : -1;
             * int e = (int)((bits >> 52) & 0x7ffL);
             * long m = (e == 0) ?
             *                 (bits & 0xfffffffffffffL) << 1 :
             *                 (bits & 0xfffffffffffffL) | 0x10000000000000L;
             * }
             *
             * Then the floating-point result equals the value of the mathematical
             * expression s&middot;m&middot;2<sup>e-1075</sup>.
             *
             * Note that this method may not be able to return a
             * {@code double} NaN with exactly same bit pattern as the
             * {@code long} argument.  IEEE 754 distinguishes between two
             * kinds of NaNs, quiet NaNs and signaling NaNs.  The
             * differences between the two kinds of NaN are generally not
             * visible in Java.  Arithmetic operations on signaling NaNs turn
             * them into quiet NaNs with a different, but often similar, bit
             * pattern.  However, on some processors merely copying a
             * signaling NaN also performs that conversion.  In particular,
             * copying a signaling NaN to return it to the calling method
             * may perform this conversion.  So {@code longBitsToDouble}
             * may not be able to return a {@code double} with a
             * signaling NaN bit pattern.  Consequently, for some
             * {@code long} values,
             * {@code doubleToRawLongBits(longBitsToDouble(start))} may
             * not equal {@code start}.  Moreover, which
             * particular bit patterns represent signaling NaNs is platform
             * dependent; although all NaN bit patterns, quiet or signaling,
             * must be in the NaN range identified above.
             *
             * @param   bits   any {@code long} integer.
             * @return  the {@code double} floating-point value with the same
             *          bit pattern.
             */
            static double longBitsToDouble(long bits);

            /**
             * Returns the smaller of two {@code double} values
             * as if by calling {@link Math#min(double, double) Math.min}.
             *
             * @param a the first operand
             * @param b the second operand
             * @return the smaller of {@code a} and {@code b}.
             * @see java.util.function.BinaryOperator
             * @since 1.8
             */
            static double min(double a, double b);

            // TODO FIXME
//            /**
//             * Returns a hexadecimal string representation of the
//             * {@code double} argument. All characters mentioned below
//             * are ASCII characters.
//             *
//             * If the argument is NaN, the result is the string
//             *     "{@code NaN}".
//             * Otherwise, the result is a string that represents the sign
//             * and magnitude of the argument. If the sign is negative, the
//             * first character of the result is '{@code -}'
//             * ({@code '\u005Cu002D'}); if the sign is positive, no sign
//             * character appears in the result. As for the magnitude m:
//             *
//             *
//             * If m is infinity, it is represented by the string
//             * {@code "Infinity"}; thus, positive infinity produces the
//             * result {@code "Infinity"} and negative infinity produces
//             * the result {@code "-Infinity"}.
//             *
//             * If m is zero, it is represented by the string
//             * {@code "0x0.0p0"}; thus, negative zero produces the result
//             * {@code "-0x0.0p0"} and positive zero produces the result
//             * {@code "0x0.0p0"}.
//             *
//             * If m is a {@code double} value with a
//             * normalized representation, substrings are used to represent the
//             * significand and exponent fields.  The significand is
//             * represented by the characters {@code "0x1."}
//             * followed by a lowercase hexadecimal representation of the rest
//             * of the significand as a fraction.  Trailing zeros in the
//             * hexadecimal representation are removed unless all the digits
//             * are zero, in which case a single zero is used. Next, the
//             * exponent is represented by {@code "p"} followed
//             * by a decimal string of the unbiased exponent as if produced by
//             * a call to {@link Integer#toString(int) Integer.toString} on the
//             * exponent value.
//             *
//             * If m is a {@code double} value with a subnormal
//             * representation, the significand is represented by the
//             * characters {@code "0x0."} followed by a
//             * hexadecimal representation of the rest of the significand as a
//             * fraction.  Trailing zeros in the hexadecimal representation are
//             * removed. Next, the exponent is represented by
//             * {@code "p-1022"}.  Note that there must be at
//             * least one nonzero digit in a subnormal significand.
//             *
//             * Examples
//             * Floating-point Value<th>Hexadecimal String
//             * {@code 1.0} {@code 0x1.0p0}
//             * {@code -1.0}        {@code -0x1.0p0}
//             * {@code 2.0} {@code 0x1.0p1}
//             * {@code 3.0} {@code 0x1.8p1}
//             * {@code 0.5} {@code 0x1.0p-1}
//             * {@code 0.25}        {@code 0x1.0p-2}
//             * {@code Double.MAX_VALUE}
//             *     {@code 0x1.fffffffffffffp1023}
//             * {@code Minimum Normal Value}
//             *     {@code 0x1.0p-1022}
//             * {@code Maximum Subnormal Value}
//             *     {@code 0x0.fffffffffffffp-1022}
//             * {@code Double.MIN_VALUE}
//             *     {@code 0x0.0000000000001p-1022}
//             *
//             * @param   d   the {@code double} to be converted.
//             * @return a hex string representation of the argument.
//             */
//            static String toHexString(double d);

		};
	}
}
#endif//NATIVE_JAVA_LANG_DOUBLE_HPP