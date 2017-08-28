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

#ifndef JAVA_LANG_DOUBLE_HPP_
#define JAVA_LANG_DOUBLE_HPP_

#include "../Number/Number.hpp"
#include "../String/String.hpp"

#ifdef WIN32
#define unsigned_long_long unsigned __int64
#define long_long __int64
#else // gcc. Might not work on other compilers!
#define unsigned_long_long unsigned long long
#define long_long long long
#endif

/**
 * Bit mask to isolate the exponent field of a
 * double.
 */
static long EXP_BIT_MASK = 0x7FF0000000000000L;

/**
 * Bit mask to isolate the significand field of a
 * double
 */
static long SIGNIF_BIT_MASK = 0x000FFFFFFFFFFFFFL;

/**
 * A constant holding the positive infinity of type
 */
static double POSITIVE_INFINITY_DOUBLE = 1.0 / 0.0; // inf

/**
 * A constant holding the negative infinity of type
 */
static double NEGATIVE_INFINITY_DOUBLE = -1.0 / 0.0; // -inf

/**
 * A constant holding a Not-a-Number (NaN) value of type
 */
static double NaN_NUMBER_DOUBLE = 0.0 / 0.0; // -nan

/**
 * A constant holding the largest positive finite value of type
 */
static double MAX_VALUE_DOUBLE = std::numeric_limits<double>::max(); // 1.797693134862316e+308

/**
 * A constant holding the smallest positive normal value of type
 */
static double MIN_NORMAL_DOUBLE = std::numeric_limits<double>::denorm_min(); // 4.940656458412465e-324

/**
 * A constant holding the smallest positive nonzero value of type
 */
static double MIN_VALUE_DOUBLE = std::numeric_limits<double>::min(); //2.225073858507201e-308

/**
 * Minimum exponent a normalized <code>double</code> number may
 * have.  It is equal to the value returned by
 * <code>Math.ilogb(Double.MIN_NORMAL)</code>.
 */
static int MIN_EXPONENT_DOUBLE = -1022;

/**
 * Init Double::MAX_VALUE
 */
static constexpr double initDoubleMaxValue () noexcept {
    return (2 - pow(2, -52)) * pow(2, 1023);
}

/**
 * Init Double::MIN_VALUE
 */
static constexpr double initDoubleMinValue () noexcept {
    return pow(2, -1074);
}

/**
 * Init Double::MIN_NORMAL_DOUBLE
 */
static constexpr double initMinNormalDouble () noexcept {
    return pow(2, -1022);
}

namespace Java {
	namespace Lang {
		class Double : public Number {
        private:
			double original;
            string originalString;
        public:
            /**
             * A constant holding the smallest positive normal value of type double, 2^-1022.
             */
            static constexpr double MIN_NORMAL = 2.2250738585072014E-308;

            /**
             * The number of logical bits in the significand of a double number,
             * including the implicit bit.
             */
            static const int SIGNIFICAND_WIDTH = 53;

            /**
             * Maximum exponent a finite double number may have.
             */
            static const int MAX_EXPONENT = 1023;

            /**
             * Minimum exponent a normalized double number may have.
             */
            static const int MIN_EXPONENT = -1022;

            /**
             * The exponent the smallest positive double subnormal value would have
             * if it could be normalized.
             */
            static constexpr int MIN_SUB_EXPONENT = MIN_EXPONENT - (SIGNIFICAND_WIDTH - 1);

            /**
             * Bias used in representing a double exponent.
             */
            static const int EXP_BIAS = 1023;

            /**
             * Bit mask to isolate the sign bit of a double.
             */
            static const long SIGN_BIT_MASK = 0x8000000000000000L;

            /**
             * Bit mask to isolate the exponent field of a double.
             */
            static const long EXP_BIT_MASK = 0x7FF0000000000000L;

            /**
             * Bit mask to isolate the significand field of a double.
             */
            static const long    SIGNIF_BIT_MASK = 0x000FFFFFFFFFFFFFL;

            /**
             * A constant holding the positive infinity of type
             */
            static constexpr double POSITIVE_INFINITY = INFINITY; // inf

            /**
             * A constant holding the negative infinity of type
             */
            static constexpr double NEGATIVE_INFINITY = -INFINITY; // -inf

            /**
             * A constant holding a Not-a-Number (NaN) value of type
             */
            static constexpr double NOT_A_NUMBER_DOUBLE = NAN; // -nan

            /**
             * A constant holding the largest positive finite value of type
             */
            static constexpr double MAX_VALUE = initDoubleMaxValue();
            /**
             * A constant holding the smallest positive normal value of type
             */
            static constexpr double MIN_NORMAL_DOUBLE = initMinNormalDouble(); // 2.225073858507201e-308

            /**
             * A constant holding the smallest positive nonzero value of type
             */
            static constexpr double MIN_VALUE = initDoubleMinValue(); //4.940656458412465e-324

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

            /**
             * Checks if the values of two operands
             * are equal or not,
             *
             * @return boolean
             */
            boolean operator==(const Double &target) const;

            /**
             * Checks if the values of two operands
             * are equal or not,
             *
             * @return boolean
             */
            boolean operator!=(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is greater than the value of right operand
             *
             * @return boolean
             */
            boolean operator>(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is less than the value of right operand,
             *
             * @return boolean
             */
            boolean operator<(const Double &target) const;

            /**
             * Checks if the value of left operand
             * is greater than or equal to the value of right operand,
             *
             * @return boolean
             */
            boolean operator>=(const Double &target) const;

            /**
             *  Checks if the value of left operand
             *  is less than or equal to the value of right operand,
             *
             * @return boolean
             */
            boolean operator<=(const Double &target) const;

            /**
             *  Called Logical AND operator.
             *  If both the operands are non-zero
             *
             * @return boolean
             */
            boolean operator&&(const Double &target) const;

            /**
             *  Called Logical OR Operator.
             *  If any of the two operands is non-zero
             *
             * @return boolean
             */
            boolean operator||(const Double &target) const;
				
            /**
             * Simple assignment operator,
             * Assigns values from right side operands
             * to left side operand
             *
             * @param target
             * @return Double
             */
            Double &operator=(const Double &target);

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
            short shortValue() const override;

            /**
             * Double value in Double
             *
             * @return int
             */
            int intValue() const override;

            /**
             * Double value in Long
             *
             * @return long
             */
            long longValue() const override;

            /**
             * Double value in float
             *
             * @return float
             */
            float floatValue() const override;

            /**
             * Double value in double
             *
             * @return double
             */
            double doubleValue() const override;

            /**
             * Double to String
             *
             * @return String
             */
            string toString() const override;

            /**
             * Returns a string representation of the {double}
             * argument. All characters mentioned below are ASCII characters.
             *
             * @param d the {double} to be converted.
             * @return a string representation of the argument.
             */
            static String toString(double d);

            /**
             * Parse double
             *
             * @param target
             * @return double
             */
            static Double parseDouble(String target);

            /**
             * Returns the value of this {Double} as a {byte}
             * after a narrowing primitive conversion.
             *
             * @return  the {double} value represented by this object
             *          converted to type {byte}
             */
            byte byteValue() const ;

            /**
             * Compares the two specified {double} values. The sign
             * of the integer value returned is the same as that of the
             * integer that would be returned by the call:
             *    Double(double1).compareTo(Double(d2))
             *
             * @param   double1        the first {double} to compare
             * @param   double2        the second {double} to compare
             * @return  the value {0} if {double1} is
             *          numerically equal to {double2}; a value less than
             *          {0} if {double1} is numerically less than
             *          {double2}; and a value greater than {0}
             *          if {double1} is numerically greater than
             *          {double2}.
             */
            static int compare(double double1, double double2);

            /**
             * Compares two {Double} objects numerically.
             *
             * @param   anotherDouble   the {Double} to be compared.
             * @return  the value {0} if {anotherDouble} is
             *          numerically equal to this {Double}; a value
             *          less than {0} if this {Double}
             *          is numerically less than {anotherDouble};
             *          and a value greater than {0} if this
             *          {Double} is numerically greater than
             *          {anotherDouble}.
             */
            int compareTo(Double anotherDouble);

            /**
             * Returns a representation of the specified floating-point value
             * according to the IEEE 754 floating-point "double
             * format" bit layout.
             *
             * @param   value   a {double} precision floating-point number.
             * @return the bits that represent the floating-point number.
             */
            static long doubleToLongBits(double valueDouble);

            /**
             * Returns a representation of the specified floating-point value
             * according to the IEEE 754 floating-point "double
             * format" bit layout, preserving Not-a-Number (NaN) values.
             *
             * @param   value   a {double} precision floating-point number.
             * @return the bits that represent the floating-point number.
             */
            static long doubleToRawLongBits(double doubleInput);

            /**
             * Compares this object against the specified object.
             *
             * @param   obj   the object to compare with.
             * @return  {true} if the objects are the same;
             *          {false} otherwise.
             * @see java.lang.Double#doubleToLongBits(double)
             */
            boolean equals(const Double &object) const;

            /**
             * Returns a hash code for this {Double} object.
             *
             * @return  a {hash code} value for this object.
             */
            long hashCode();

            /**
             * Returns a hash code for a {double} value; compatible with
             * {Double.hashCode()}.
             *
             * @param value the value to hash
             * @return a hash code value for a {double} value.
             */
            static long hashCode(double doubleInput);

            /**
             * Returns {true} if the argument is a finite floating-point
             * value; returns {false} otherwise (for NaN and infinity
             * arguments).
             *
             * @param d the {double} value to be tested
             * @return {true} if the argument is a finite
             * floating-point value, {false} otherwise.
             */
            static boolean isFinite(double d);

            /**
             * Returns {true} if the specified number is infinitely
             * large in magnitude, {false} otherwise.
             *
             * @param   v   the value to be tested.
             * @return  {true} if the value of the argument is positive
             *          infinity or negative infinity; {false} otherwise.
             */
            static boolean isInfinite(double v);

            /**
            * Returns {true} if this {Double} value is
            * infinitely large in magnitude, {false} otherwise.
            *
            * @return  {true} if the value represented by this object is
            *          positive infinity or negative infinity;
            *          {false} otherwise.
            */
            boolean isInfinite();

            /**
             * Returns {true} if the specified number is a
             * Not-a-Number (NaN) value, {false} otherwise.
             *
             * @param   v   the value to be tested.
             * @return  {true} if the value of the argument is NaN;
             *          {false} otherwise.
             */
            static boolean isNaN(double v);

            /**
             * Returns {true} if this {Double} value is
             * a Not-a-Number (NaN), {false} otherwise.
             *
             * @return  {true} if the value represented by this object is
             *          NaN; {false} otherwise.
             */
            boolean isNaN() ;

            /**
             * Returns the {double} value corresponding to a given
             * bit representation.
             *
             * @param   bits   any {long} integer.
             * @return  the {double} floating-point value with the same
             *          bit pattern.
             */
            static double longBitsToDouble(long bits);

            /**
             * Returns the smaller of two {double} values
             * as if by calling {@link Math#min(double, double) Math.min}.
             *
             * @param a the first operand
             * @param b the second operand
             * @return the smaller of {a} and {b}.
             * @see java.util.function.BinaryOperator
             */
            static double min(double a, double b);

            // TODO FIXME
//            /**
//             * Returns a hexadecimal string representation of the
//             * {double} argument. All characters mentioned below
//             * are ASCII characters.
//             *
//             * @param   d   the {double} to be converted.
//             * @return a hex string representation of the argument.
//             */
//            static String toHexString(double d);
						
						/**
						* Convert double to binary 32 bit
						* (Single-precision floating-point format
						* In IEEE 754-2008)
						*
						* @param double
						* @return string binary 32 bit of input
						*/
						static string doubleToBinary32StringType(double doubleInput);
						
						/**
						* Convert double to binary 64 bit
						* (Double-precision floating-point format
						* In IEEE 754-2008)
						*
						* @param double
						* @return string binary 64 bit of input
						*/
						static string doubleToBinary64StringType(double doubleInput);
						
						/**
						* Convert binary64StringType To Double
						* (Double-precision floating-point format
						* In IEEE 754-2008)
						* To Double
						 *
						* @param  string
						* @return double
						*/
						static double binary64StringTypeToDouble(string Binary64StringTypeInput);
						
						/**
						* Convert longBits To Binary64StringType
						* (Double-precision floating-point format
						* In IEEE 754-2008)
						 *
						* @param  long
						* @return string
						*/
						static string longBitsToBinary64StringType(long longBitsInput);
						
						/**
						* Convert from string to double
						*
						* @param      s   the string to be parsed.
						* @return     a {Double} object holding the value
						*             represented by the {String} argument.
						* @throws     NumberFormatException  if the string does not contain a
						*             parsable number.
						*/
						static Double valueOf(String stringInput);
						
						/**
						* Assign value to Double variable
						*
						* @param  d a double value.
						* @return a {Double} instance representing {d}.
						*/
						static Double valueOf(double doubleInput);
				};
		}
}
#endif  // JAVA_LANG_DOUBLE_HPP_