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
			Float();
			Float(float original);
			Float(const Float &target);
			~Float();
		
		public:
			char charValue() const;
			short shortValue() const override;
			int intValue() const override;
			long longValue() const override;
			float floatValue() const override;
			double doubleValue() const override;
			string toString() const override;
			
			static Float parseFloat(String target);
            static boolean isNaN(float v);

		public:
			Float &operator=(const Float &target);
			Float operator+(const Float &target);
			Float operator-(const Float &target);
			Float operator/(const Float &target);
			Float operator*(const Float &target);
			
			boolean operator==(const Float &target) const;
			boolean operator!=(const Float &target) const;
			boolean operator<(const Float &target) const;
			boolean operator>(const Float &target) const;
			boolean operator<=(const Float &target) const;
			boolean operator>=(const Float &target) const;
			
			void operator-=(const Float &target);
			void operator+=(const Float &target);
			void operator*=(const Float &target);
			void operator/=(const Float &target);

		public:
			friend std::ostream &operator<<(std::ostream &os, const Float &target) {
				os << target.original;
				return os;
			}
		};
	}
}

#endif  // JAVA_LANG_FLOAT_HPP_
