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

#ifndef JAVA_LANG_FLOAT_HPP_
#define JAVA_LANG_FLOAT_HPP_

#include "../Number/Number.hpp"
#include "../String/String.hpp"

/**
 * A constant holding the positive infinity of type
 */
static float POSITIVE_INFINITY = float(1.0 / 0.0); // inf

/**
 * A constant holding the negative infinity of type
 */
static float NEGATIVE_INFINITY = float(-1.0 / 0.0); // -inf

/**
 * A constant holding a Not-a-Number (NaN) value of type
 */
static float NaN_NUMBER = float(0.0 / 0.0); // -nan

/**
 * A constant holding the largest positive finite value of type
 */
static float MAX_VALUE = std::numeric_limits<float>::max(); // 3.403e+38

/**
 * The smallest subnormal value has sign bit = 0, exponent = 0
 * and only the least significant bit of the fraction is 1
 */
static float MIN_NORMAL = std::numeric_limits<float>::denorm_min(); // 1.401e-45

/**
 * A constant holding the smallest value of type
 */
static float MIN_VALUE = std::numeric_limits<float>::min(); // 1.175e-38

/**
 * Minimum exponent a normalized double number may have
 */
static int  MIN_EXPONENT      = -126;

/**
 * Init Float::MAX_VALUE
 */
static constexpr float initFloatMaxValue () noexcept {
	return (float) ((2 - pow(2, -23)) * pow(2, 127));
}

/**
 * Init Float::MIN_VALUE
 */
static constexpr float initFloatMinValue () noexcept {
	return (float) pow(2, -149);
}

namespace Java {
	namespace Lang {

		class Float;

		class Float : public virtual Number {
		private:
			float original;
			string originalString;

		public:
			/**
            * A constant holding the smallest positive normal value of type float, 2-126.
            */
			static constexpr float MIN_NORMAL = 1.17549435E-38f;

			/**
             * The number of logical bits in the significand of a float number,
             * including the implicit bit.
             */
			static constexpr int SIGNIFICAND_WIDTH = 24;

			/**
             * Maximum exponent a finite float number may have.
             */
			static const int MAX_EXPONENT = 127;

			/**
             * Minimum exponent a normalized float number may have.
             */
			static const int MIN_EXPONENT = -126;

			/**
             * The exponent the smallest positive float subnormal value would have
             * if it could be normalized.
             */
			static constexpr int MIN_SUB_EXPONENT = MIN_EXPONENT - (SIGNIFICAND_WIDTH - 1);

			/**
             * Bias used in representing a float exponent.
             */
			static const int EXP_BIAS = 127;

			/**
             * Bit mask to isolate the sign bit of a float.
             */
			static const int SIGN_BIT_MASK = 0x80000000;

			/**
             * Bit mask to isolate the exponent field of a float.
             */
			static const int EXP_BIT_MASK = 0x7F800000;

			/**
             * Bit mask to isolate the significand field of a float.
             */
			static const int SIGNIF_BIT_MASK = 0x007FFFFF;

			/**
             * A constant holding the positive infinity of type float.
             */
			static constexpr float POSITIVE_INFINITY = INFINITY;

			/**
            * A constant holding the negative infinity of type float.
            */
			static constexpr float NEGATIVE_INFINITY = -INFINITY;

			/**
             * A constant holding a Not-a-Number (NaN) value of type float.
             */
			static constexpr float NaN = NAN;

			/**
             * A constant holding the largest positive finite value of type float, (2-2-23)·2127.
             */
			static constexpr float MAX_VALUE = initFloatMaxValue(); // 3.4028235e+38f

			/**
             * A constant holding the smallest positive nonzero value of type float, 2^-149.
             * It is equal to the hexadecimal floating-point literal 0x0.000002P-126f
             * and also equal to Float.intBitsToFloat(0x1).
             */
			static constexpr float MIN_VALUE = initFloatMinValue(); // 1.4e-45f

			/**
             * The number of bits used to represent a float value.
             */
			static const int SIZE = 32;

			/**
             * The number of bytes used to represent a float value.
             */
			static constexpr int BYTES = SIZE / 8;

		public:
			/**
       * Float initialization
       *
       * @param original
       */
			Float();

			/**
       * Float initialization
       *
       * @param original
       */
			Float(float original);

			/**
       * Float initialization
       *
       * @param original
       */
			Float(const Float &target);

			/**
       * Float Destructor
       */
			~Float();

		public:
			/**
             * Adds two operands
             *
             * @return Float
             */
			Float operator+(const Float &target);

			/**
             * Subtracts second operand from the first
             *
             * @return Float
             */
			Float operator-(const Float &target);

			/**
             *  Multiplies both operands
             *
             * @return Float
             */
			Float operator*(const Float &target);

			/**
             * Divides numerator by de-numerator
             *
             * @return Float
             */
			Float operator/(const Float &target);

			/**
             * Checks if the values of two operands
             * are equal or not,
             *
             * @return boolean
             */
			boolean operator==(const Float &target) const;

			/**
             * Checks if the values of two operands
             * are equal or not,
             *
             * @return boolean
             */
			boolean operator!=(const Float &target) const;

			/**
             * Checks if the value of left operand
             * is greater than the value of right operand
             *
             * @return boolean
             */
			boolean operator>(const Float &target) const;

			/**
             * Checks if the value of left operand
             * is less than the value of right operand,
             *
             * @return boolean
             */
			boolean operator<(const Float &target) const;

			/**
             * Checks if the value of left operand
             * is greater than or equal to the value of right operand,
             *
             * @return boolean
             */
			boolean operator>=(const Float &target) const;

			/**
             *  Checks if the value of left operand
             *  is less than or equal to the value of right operand,
             *
             * @return boolean
             */
			boolean operator<=(const Float &target) const;

			/**
             *  Called Logical AND operator.
             *  If both the operands are non-zero
             *
             * @return boolean
             */
			boolean operator&&(const Float &target) const;

			/**
             *  Called Logical OR Operator.
             *  If any of the two operands is non-zero
             *
             * @return boolean
             */
			boolean operator||(const Float &target) const;


			/**
             * Simple assignment operator,
             * Assigns values from right side operands
             * to left side operand
             *
             * @param target
             * @return Float
             */
			Float operator=(const Float &target);

			/**
             * Add AND assignment operator,
             * It adds right operand to the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Float
             */
			Float operator+=(const Float &target) const;

			/**
             * Subtract AND assignment operator,
             * It subtracts right operand from the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Float
             */
			Float operator-=(const Float &target) const;

			/**
             * Multiply AND assignment operator,
             * It multiplies right operand with the left operand
             * and assign the result to left operand
             *
             * @param target
             * @return Float
             */
			Float operator*=(const Float &target) const;

			/**
             * Divide AND assignment operator,
             * It divides left operand with the right operand
             * and assign the result to left operand
             *
             * @param target
             * @return Float
             */
			Float operator/=(const Float &target) const;

			/**
             * Float to Char
             *
             * @return char
             */
			char charValue() const;

			/**
             * Float to String
             *
             * @return CString
             */
			string stringValue() const;

			/**
             * Short value of Float
             *
             * @return short
             */
			short shortValue() const;

			/**
             * Float value in Float
             *
             * @return int
             */
			int intValue() const;

			/**
             * Float value in Long
             *
             * @return long
             */
			long longValue() const;

			/**
             * Float value in float
             *
             * @return float
             */
			float floatValue() const;

			/**
             * Float value in double
             *
             * @return double
             */
			double doubleValue() const;

			/**
             * Float to String
             *
             * @return String
             */
			string toString() const;

			/**
             * Returns a string representation of the {double}
             * argument. All characters mentioned below are ASCII characters.
             *
             * @param   d   the {double} to be converted.
             * @return a string representation of the argument.
             */
			static String toString(float d);

			/**
             * Parse float
             *
             * @param target
             * @return float
             */
			static Float parseFloat(String target);

			/**
             * Returns the value of this {Float} as a {byte}
             * after a narrowing primitive conversion.
             *
             * @return  the {float} value represented by this object
             *          converted to type {byte}
             */
			byte byteValue() const ;

			/**
             * Compares the two specified {float} values. The sign
             * of the integer value returned is the same as that of the
             * integer that would be returned by the call:
             *    Float(float1).compareTo(Float(d2))
             *
             * @param   float1        the first {float} to compare
             * @param   float2        the second {float} to compare
             * @return  the value {0} if {float1} is
             *          numerically equal to {float2}; a value less than
             *          {0} if {float1} is numerically less than
             *          {float2}; and a value greater than {0}
             *          if {float1} is numerically greater than
             *          {float2}.
             */
			static int compare(float float1, float float2);

			/**
             * Compares two {Float} objects numerically.
             *
             * @param   anotherFloat   the {Float} to be compared.
             * @return  the value {0} if {anotherFloat} is
             *          numerically equal to this {Float}; a value
             *          less than {0} if this {Float}
             *          is numerically less than {anotherFloat};
             *          and a value greater than {0} if this
             *          {Float} is numerically greater than
             *          {anotherFloat}.
             */
			int compareTo(Float anotherFloat);

			/**
             * Returns a representation of the specified floating-point value
             * according to the IEEE 754 floating-point "float
             * format" bit layout.
             *
             * @param   value   a {float} precision floating-point number.
             * @return the bits that represent the floating-point number.
             */
			static long floatToLongBits(float valueFloat);

			/**
             * Returns a representation of the specified floating-point value
             * according to the IEEE 754 floating-point "float
             * format" bit layout, preserving Not-a-Number (NaN) values.
             *
             * @param   value   a {float} precision floating-point number.
             * @return the bits that represent the floating-point number.
             */
			static long floatToRawLongBits(float floatInput);

			/**
             * Compares this object against the specified object.
             *
             * @param   obj   the object to compare with.
             * @return  {true} if the objects are the same;
             *          {false} otherwise.
             * @see java.lang.Float#floatToLongBits(float)
             */
			boolean equals(const Float &object) const;

			/**
             * Returns a hash code for this {Float} object.
             *
             * @return  a {hash code} value for this object.
             */
			long hashCode();

			/**
             * Returns a hash code for a {float} value; compatible with
             * {Float.hashCode()}.
             *
             * @param value the value to hash
             * @return a hash code value for a {float} value.
             */
			static long hashCode(float floatInput);

			/**
             * Returns {true} if the argument is a finite floating-point
             * value; returns {false} otherwise (for NaN and infinity
             * arguments).
             *
             * @param d the {float} value to be tested
             * @return {true} if the argument is a finite
             * floating-point value, {false} otherwise.
             */
			static boolean isFinite(float d);

			/**
             * Returns {true} if the specified number is infinitely
             * large in magnitude, {false} otherwise.
             *
             * @param   v   the value to be tested.
             * @return  {true} if the value of the argument is positive
             *          infinity or negative infinity; {false} otherwise.
             */
			static boolean isInfinite(float v);

			/**
            * Returns {true} if this {Float} value is
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
			static boolean isNaN(float v);


			/**
             * Returns {true} if this {Float} value is
             * a Not-a-Number (NaN), {false} otherwise.
             *
             * @return  {true} if the value represented by this object is
             *          NaN; {false} otherwise.
             */
			boolean isNaN() ;

			/**
             * Returns the {float} value corresponding to a given
             * bit representation.
             *
             * @param   bits   any {long} integer.
             * @return  the {float} floating-point value with the same
             *          bit pattern.
             */
			static float longBitsToFloat(long bits);

			/**
             * Returns the smaller of two {float} values
             * as if by calling {@link Math#min(float, float) Math.min}.
             *
             * @param a the first operand
             * @param b the second operand
             * @return the smaller of {a} and {b}.
             * @see java.util.function.BinaryOperator
             */
			static float min(float a, float b);

			// TODO FIXME
//            /**
//             * Returns a hexadecimal string representation of the
//             * {float} argument. All characters mentioned below
//             * are ASCII characters.
//             *
//             * @param   d   the {float} to be converted.
//             * @return a hex string representation of the argument.
//             */
//            static String toHexString(float d);

			/**
            * Convert float to binary 32 bit
            * (Single-precision floating-point format
            * In IEEE 754-2008)
            *
            * @param float
            * @return string binary 32 bit of input
            */
			static string floatToBinary32StringType(float floatInput );

			/**
            * Convert float to binary 64 bit
            * (Float-precision floating-point format
            * In IEEE 754-2008)
            *
            * @param float
            * @return string binary 64 bit of input
            */
			static string floatToBinary64StringType(float floatInput );

			/**
            * Convert binary64StringType To Float
            * (Float-precision floating-point format
            * In IEEE 754-2008)
            * To Float
             *
            * @param  string
            * @return float
            */
			static float binary64StringTypeToFloat(string Binary64StringTypeInput);

			/**
            * Convert longBits To Binary64StringType
            * (Float-precision floating-point format
            * In IEEE 754-2008)
             *
            * @param  long
            * @return string
            */
			static string longBitsToBinary64StringType(long longBitsInput);

			/**
            * Convert from string to float
            *
            * @param      s   the string to be parsed.
            * @return     a {Float} object holding the value
            *             represented by the {String} argument.
            * @throws     NumberFormatException  if the string does not contain a
            *             parsable number.
            */
			static Float valueOf(String stringInput);

			/**
            * Assign value to Float variable
            *
            * @param  d a float value.
            * @return a {Float} instance representing {d}.
            */
			static Float valueOf(float floatInput);
		};
	}
}

#endif  // JAVA_LANG_FLOAT_HPP_
