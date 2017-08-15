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

#include "Math.hpp"

#include <cmath>
#include "../ArithmeticException/ArithmeticException.hpp"
#include "../AssertionError/AssertionError.hpp"

using namespace Java::Lang;

int Math::abs(int value) {
	return value >= 0 ? value : -value;
}

float Math::abs(float value) {
	return value >= 0 ? value : -value;
}

long Math::abs(long value) {
	return value >= 0 ? value : -value;
}

double Math::abs(double value) {
	if(Double::isNaN(value)) {
		return Double::NOT_A_NUMBER_DOUBLE;
	}
	
	return value >= 0 ? value : -value;
}

double Math::acos(double value) {
	return math_acos(value);
}

double Math::asin(double value) {
	return math_asin(value);
}

double Math::atan(double value) {
	return math_atan(value);
}

double Math::atan2(double coordinateX, double coordinateY) {
	return math_atan2(coordinateX, coordinateY);
}

long Math::addExact(long valueA, long valueB) {
	long result = valueA + valueB;
	if (((valueA ^ result) & (valueB ^ result)) < 0) {
		throw ArithmeticException("long overflow");
	}
	return result;
}

int Math::addExact(int valueA, int valueB) {
	int result = valueA + valueB;
	if (((valueA ^ result) & (valueB ^ result)) < 0) {
		throw ArithmeticException("integer overflow");
	}
	return result;
}

double Math::cbrt(double value) {
	return math_cbrt(value);
}

double Math::ceil(double value) {
	return math_ceil(value);
}

double Math::copySign(double magnitude, double sign) {
	return math_copysign(magnitude, sign);
}

float Math::copySign(float magnitude, float sign) {
	return math_copysignf(magnitude, sign);
}

double Math::cos(double angle) {
	double result = math_cos(angle);
	
	if(Double::isNaN(result)) {
		return Math::abs(result);
	}
	
	return math_cos(angle);
}

double Math::cosh(double angle) {
	return math_cosh(angle);
}

long Math::decrementExact(long value) {
	if (value == Long::MIN_VALUE) {
		throw ArithmeticException("long overflow");
	}
	return value - 1;
}

int Math::decrementExact(int value) {
	if (value == Integer::MIN_VALUE) {
		throw ArithmeticException("integer overflow");
	}
	return value - 1;
}

double Math::exp(double exponent) {
	return math_exp(exponent);
}

double Math::expm1(double exponent) {
	return math_expm1(exponent);
}

double Math::floor(double value) {
	return math_floor(value);
}

int Math::floorDiv(int dividend, int divisor) {
	if (divisor == 0) {
		throw ArithmeticException();
	}
	int result = dividend / divisor;
	// if the signs are different and modulo not zero, round down
	if ((dividend ^ divisor) < 0 && (result * divisor != dividend)) {
		result--;
	}
	return result;
}

long Math::floorDiv(long dividend, long divisor) {
	if (divisor == 0) {
		throw ArithmeticException();
	}
	long result = dividend / divisor;
	// if the signs are different and modulo not zero, round down
	if ((dividend ^ divisor) < 0 && (result * divisor != dividend)) {
		result--;
	}
	return result;
}

int Math::floorMod(int dividend, int divisor) {
	return dividend - (floorDiv(dividend, divisor) * divisor);
}

long Math::floorMod(long dividend, long divisor) {
	return dividend - (floorDiv(dividend, divisor) * divisor);
}

int Math::getExponent(double value) {
	if (Double::isNaN(value) || value == -INFINITY || value == INFINITY) {
		return Double::MAX_EXPONENT + 1;
	}
	
	if (value == -0 || value == 0) {
		return Double::MIN_EXPONENT - 1;
	}
	
	double mantissas;
	int exponent;
	mantissas = std::frexp(value, &exponent);
	if (mantissas * 10 >= 1.0 && exponent - 1 < Double::MIN_EXPONENT) {
		return Double::MIN_EXPONENT - 1;
	}
	
	return exponent - 1;
}

int Math::getExponent(float value) {
	if (Float::isNaN(value) || value == -INFINITY || value == INFINITY) {
		return Float::MAX_EXPONENT + 1;
	}
	
	if (value == -0 || value == 0) {
		return Float::MIN_EXPONENT - 1;
	}
	
	double mantissas;
	int exponent;
	mantissas = std::frexp(value, &exponent);
	if ((mantissas * 10) >= 1.0 && (exponent - 1) < Float::MIN_EXPONENT) {
		return Float::MIN_EXPONENT - 1;
	}
	
	return exponent - 1;
}

double Math::hypot(double valueA, double valueB) {
	return math_hypot(valueA, valueB);
}

double Math::IEEERemainder(double dividend, double divisor) {
	double result = math_ieeeremainder(dividend, divisor);
	if(Double::isNaN(result)) {
		return Math::abs(result);
	}
	
	return math_ieeeremainder(dividend, divisor);
}

int Math::incrementExact(int value) {
	if (value == Integer::MAX_VALUE) {
		throw ArithmeticException("integer overflow");
	}
	return value + 1;
}

long Math::incrementExact(long value) {
	if (value == Long::MAX_VALUE) {
		throw ArithmeticException("long overflow");
	}
	return value + 1;
}

double Math::log(double value) {
	return math_log(value);
}

double Math::log10(double value) {
	return math_log10(value);
}

double Math::log1p(double value) {
	double result = math_log1p(value);
	
	if(Double::isNaN(result)) {
		return Math::abs(result);
	}
	
	return math_log1p(value);
}

int Math::max(int valueA, int valueB) {
	return valueA > valueB ? valueA : valueB;
}

float Math::max(float valueA, float valueB) {
	return valueA > valueB ? valueA : valueB;
}

long Math::max(long valueA, long valueB) {
	return valueA > valueB ? valueA : valueB;
}

double Math::max(double valueA, double valueB) {
	return valueA > valueB ? valueA : valueB;
}

int Math::min(int valueA, int valueB) {
	return valueA < valueB ? valueA : valueB;
}

float Math::min(float valueA, float valueB) {
	return valueA < valueB ? valueA : valueB;
}

long Math::min(long valueA, long valueB) {
	return valueA < valueB ? valueA : valueB;
}

double Math::min(double valueA, double valueB) {
	return valueA < valueB ? valueA : valueB;
}

int Math::multiplyExact(int valueA, int valueB) {
	long result = (long)valueA * (long)valueB;
	if ((int)result != result) {
		throw ArithmeticException("integer overflow");
	}
	return (int)result;
}

long Math::multiplyExact(long valueA, long valueB) {
	if (valueA == Long::MIN_VALUE && valueB == -1) {
		throw ArithmeticException("long overflow");
		
	}
	
	long result = valueA * valueB;
	unsigned long absA = (unsigned) abs(valueA);
	unsigned long absB = (unsigned) abs(valueB);
	
	if (((absA | absB) >> 31) != 0) {
		if ((valueB != 0) && (result / valueB != valueA)) {
			throw ArithmeticException("long overflow");
		}
	}
	return result;
}

int Math::negateExact(int intValue) {
	if (intValue == Integer::MIN_VALUE) {
		throw ArithmeticException("integer overflow");
	}
	return -intValue;
}

long Math::negateExact(long longValue) {
	if (longValue == Long::MIN_VALUE) {
		throw ArithmeticException("long overflow");
	}
	return -longValue;
}

double Math::nextAfter(double start, double direction) {
	return math_nexttoward(start, direction);
}

float Math::nextAfter(float start, double direction) {
	return math_nexttowardf(start, direction);
}

double Math::nextDown(double value) {
	if (Double::isNaN(value) || value == Double::NEGATIVE_INFINITY) {
		return value;
	}
	if (value == 0.0) {
		return -Double::MIN_VALUE;
	}
	
	return math_nexttoward(value, Double::NEGATIVE_INFINITY);
}

float Math::nextDown(float value) {
	if (Float::isNaN(value) || value == Float::NEGATIVE_INFINITY) {
		return value;
	}
	
	if (value == 0.0) {
		return -Float::MIN_VALUE;
	}
	
	return math_nexttowardf(value, Float::NEGATIVE_INFINITY);
}

float Math::nextUp(float value) {
	if (Float::isNaN(value) || value == Float::POSITIVE_INFINITY) {
		return value;
	}
	
	return math_nexttowardf(value, Float::POSITIVE_INFINITY);
}

double Math::nextUp(double value) {
	if (Double::isNaN(value) || value == Double::POSITIVE_INFINITY) {
		return value;
	}
	
	return math_nexttoward(value, Double::POSITIVE_INFINITY);
}

double Math::pow(double base, double exponent) {
	return math_pow(base, exponent);
}

double Math::powerOfTwoD(int exponent) {
	if (exponent < Double::MIN_EXPONENT || exponent > Double::MAX_EXPONENT) {
		throw AssertionError(exponent);
	}
	long oneLong = 1;
	return Double::longBitsToDouble(((exponent + Double::EXP_BIAS)
		<< (Double::SIGNIFICAND_WIDTH - oneLong)) & Double::EXP_BIT_MASK);
}

// TODO need Float::intBitsToFloat
float Math::powerOfTwoF(int exponent) {
	if (exponent < Float::MIN_EXPONENT || exponent > Float::MAX_EXPONENT) {
		throw AssertionError(exponent);
	}
	
	/*return Float::intBitsToFloat(((exponent + Float::EXP_BIAS)
			<< (Float::SIGNIFICAND_WIDTH-1)) & Float::EXP_BIT_MASK);*/
	return 0;
}

double Math::random() {
	Random random1 = Random();
	return random1.nextDouble();
}

double Math::rint(double value) {
	return math_rint(value);
}

int Math::round(float value) {
	return (int) math_round(value);
}

long Math::round(double value) {
	return (long) math_round(value);
}

float Math::scalb(float value, int scaleFactor) {
	return math_ldexpf(value, scaleFactor);
}

double Math::scalb(double value, int scaleFactor) {
	return math_ldexp(value, scaleFactor);
}

double Math::signum(double value) {
	if (value == 0.0 || Double::isNaN(value)) {
		return value;
	}
	return Math::copySign(1.0, value);
}

float Math::signum(float value) {
	if (value == 0.0f || Float::isNaN(value)) {
		return value;
	}
	
	if (value == 0.0f) {
		return -0.0f;
	}
	
	return Math::copySign(1.0f, value);
}

double Math::sin(double angle) {
	return math_sin(angle);
}

double Math::sinh(double angle) {
	return math_sinh(angle);
}

double Math::sqrt(double value) {
	return math_sqrt(value);
}

long Math::subtractExact(long valueA, long valueB) {
	long result = valueA - valueB;
	if (((valueA ^ valueB) & (valueA ^ result)) < 0) {
		throw ArithmeticException("long overflow");
	}
	return result;
}

int Math::subtractExact(int valueA, int valueB) {
	int result = valueA - valueB;
	if (((valueA ^ valueB) & (valueA ^ result)) < 0) {
		throw ArithmeticException("integer overflow");
	}
	return result;
}

double Math::tan(double angle) {
	return math_tan(angle);
}

double Math::tanh(double angle) {
	return math_tanh(angle);
}

double Math::toDegrees(double angleRadian) {
	return angleRadian * 180.0 / PI;
}

int Math::toIntExact(long value) {
	if ((int)value != value) {
		throw ArithmeticException("integer overflow");
	}
	return (int) value;
}

double Math::toRadians(double angleDegree) {
	return angleDegree / 180.0 * PI;
}

//TODO need Float::intBitsToFloat
float Math::ulp(float value) {
	if (value == Float::MAX_VALUE || value == -Float::MAX_VALUE) {
		return (float) Math::pow(2, 104);
	}
	int exp = getExponent(value);
	switch(exp) {
		case Float::MAX_EXPONENT + 1:        // NaN or infinity
			return Math::abs(value);
		case Float::MIN_EXPONENT - 1:        // zero or subnormal
			return Float::MIN_VALUE;
		default:
			if (exp > Float::MAX_EXPONENT || exp < Float::MIN_EXPONENT) {
				throw AssertionError(exp);
			}
			
			exp = exp - (Float::SIGNIFICAND_WIDTH - 1);
			if (exp >= Float::MIN_EXPONENT) {
				return powerOfTwoF(exp);
			}
			/*   return Float::intBitsToFloat(1 << (exp - (Float::MIN_EXPONENT
														 - (Float::SIGNIFICAND_WIDTH - 1)) ));*/
	}
}

double Math::ulp(double value) {
	if (value == Double::MAX_VALUE || value == -Double::MAX_VALUE) {
		return Math::pow(2, 971);
	}
	int exp = getExponent(value);
	switch (exp) {
		case Double::MAX_EXPONENT + 1:        // NaN or infinity
			return Math::abs(value);
		case Double::MIN_EXPONENT - 1:        // zero or subnormal
			return Double::MIN_VALUE;
		default:
			if (exp > Double::MAX_EXPONENT || exp < Double::MIN_EXPONENT) {
				throw AssertionError(exp);
			}
			
			exp = exp - (Double::SIGNIFICAND_WIDTH - 1);
			if (exp >= Double::MIN_EXPONENT) {
				return powerOfTwoD(exp);
			}
			
			return Double::longBitsToDouble(1 << (exp - (Double::MIN_EXPONENT
			                                             - (Double::SIGNIFICAND_WIDTH - 1))));
	}
}