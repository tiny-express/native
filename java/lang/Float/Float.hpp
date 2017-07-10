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

#ifndef NATIVE_JAVA_LANG_FLOAT_HPP
#define NATIVE_JAVA_LANG_FLOAT_HPP

#include "../Number/Number.hpp"

namespace Java {
	namespace Lang {
		
		class Float;
		
		class Float : public virtual Number {
		private:
			float original;
			string string_original;

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
			static const int MIN_SUB_EXPONENT = MIN_EXPONENT - (SIGNIFICAND_WIDTH - 1);

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

		public:
			Float();
			Float(float original);
			Float(const Float &target);
			~Float();
		
		public:
			char charValue() const;
			short shortValue() const;
			int intValue() const;
			long longValue() const;
			float floatValue() const;
			double doubleValue() const;
			string toString() const;
			
			static Float parseFloat(String target);
		
		public:
			Float operator=(const Float &target);
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
		};
	}
}

#endif//NATIVE_JAVA_LANG_FLOAT_HPP
