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
#include "../ArithmeticException/ArithmeticException.hpp"
#include "../AssertionError/AssertionError.hpp"

using namespace Java::Lang;

long int Math::abs(long int value) {
    return value >= 0 ? value : -value;
}

float Math::abs(float value) {
    return value >= 0 ? value : -value;
}

long long Math::abs(long long value) {
    return value >= 0 ? value : -value;
}

double Math::abs(double value) {
    if (Double::isNaN(value)) {
        return Double::NaN;
    }

    return value >= 0 ? value : -value;
}

double Math::acos(double value) {
    return ::acos(value);
}

double Math::asin(double value) {
    return ::asin(value);
}

double Math::atan(double value) {
    return ::atan(value);
}

double Math::atan2(double coordinateX, double coordinateY) {
    return ::atan2(coordinateX, coordinateY);
}

long long Math::addExact(long long valueA, long long valueB) {
    long long result = valueA + valueB;
    if (((valueA ^ result) & (valueB ^ result)) < 0) {
        throw ArithmeticException("long long overflow");
    }
    return result;
}

long int Math::addExact(long int valueA, long int valueB) {
    long int result = valueA + valueB;
    if (((valueA ^ result) & (valueB ^ result)) < 0) {
        throw ArithmeticException("integer overflow");
    }
    return result;
}

double Math::cbrt(double value) {
    return ::cbrt(value);
}

double Math::ceil(double value) {
    return ::ceil(value);
}

double Math::copySign(double magnitude, double sign) {
    return ::copysign(magnitude, sign);
}

float Math::copySign(float magnitude, float sign) {
    return ::copysignf(magnitude, sign);
}

double Math::cos(double angle) {
    double result = ::cos(angle);

    if (Double::isNaN(result)) {
        return Math::abs(result);
    }

    return ::cos(angle);
}

double Math::cosh(double angle) {
    return ::cosh(angle);
}

long long Math::decrementExact(long long value) {
    if (value == Long::MIN_VALUE) {
        throw ArithmeticException("long long overflow");
    }
    return value - 1;
}

long int Math::decrementExact(long int value) {
    if (value == Integer::MIN_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return value - 1;
}

double Math::exp(double exponent) {
    return ::exp(exponent);
}

double Math::expm1(double exponent) {
    return ::expm1(exponent);
}

double Math::floor(double value) {
    return ::floor(value);
}

long int Math::floorDiv(long int dividend, long int divisor) {
    if (divisor == 0) {
        throw ArithmeticException();
    }
    long int result = dividend / divisor;
    // if the signs are different and modulo not zero, round down
    if ((dividend ^ divisor) < 0 && (result * divisor != dividend)) {
        result--;
    }
    return result;
}

long long Math::floorDiv(long long dividend, long long divisor) {
    if (divisor == 0) {
        throw ArithmeticException();
    }
    long long result = dividend / divisor;
    // if the signs are different and modulo not zero, round down
    if ((dividend ^ divisor) < 0 && (result * divisor != dividend)) {
        result--;
    }
    return result;
}

long int Math::floorMod(long int dividend, long int divisor) {
    return dividend - (floorDiv(dividend, divisor) * divisor);
}

long long Math::floorMod(long long dividend, long long divisor) {
    return dividend - (floorDiv(dividend, divisor) * divisor);
}

long int Math::getExponent(double value) {
    if (Double::isNaN(value) || value == -INFINITY || value == INFINITY) {
        return Double::MAX_EXPONENT + 1;
    }

    if (value == -0 || value == 0) {
        return Double::MIN_EXPONENT - 1;
    }

    double mantissas;
    long int exponent;
    mantissas = std::frexp(value, &exponent);
    if (mantissas * 10 >= 1.0 && exponent - 1 < Double::MIN_EXPONENT) {
        return Double::MIN_EXPONENT - 1;
    }

    return exponent - 1;
}

long int Math::getExponent(float value) {
    if (Float::isNaN(value) || value == -INFINITY || value == INFINITY) {
        return Float::MAX_EXPONENT + 1;
    }

    if (value == -0 || value == 0) {
        return Float::MIN_EXPONENT - 1;
    }

    double mantissas;
    long int exponent;
    mantissas = std::frexp(value, &exponent);
    if ((mantissas * 10) >= 1.0 && (exponent - 1) < Float::MIN_EXPONENT) {
        return Float::MIN_EXPONENT - 1;
    }

    return exponent - 1;
}

double Math::hypot(double valueA, double valueB) {
    return ::hypot(valueA, valueB);
}

inline double math_ieeeremainder(double dividend, double divisor) {
    return dividend - (round(dividend / divisor) * divisor);
}

double Math::IEEERemainder(double dividend, double divisor) {
    double result = math_ieeeremainder(dividend, divisor);
    if (Double::isNaN(result)) {
        return Math::abs(result);
    }
    return result;
}

long int Math::incrementExact(long int value) {
    if (value == Integer::MAX_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return value + 1;
}

long long Math::incrementExact(long long value) {
    if (value == Long::MAX_VALUE) {
        throw ArithmeticException("long long overflow");
    }
    return value + 1;
}

double Math::log(double value) {
    return ::log(value);
}

double Math::log10(double value) {
    return ::log10(value);
}

double Math::log1p(double value) {
    double result = ::log1p(value);

    if (Double::isNaN(result)) {
        return Math::abs(result);
    }

    return ::log1p(value);
}

long int Math::max(long int valueA, long int valueB) {
    return valueA > valueB ? valueA : valueB;
}

float Math::max(float valueA, float valueB) {
    return valueA > valueB ? valueA : valueB;
}

long long Math::max(long long valueA, long long valueB) {
    return valueA > valueB ? valueA : valueB;
}

double Math::max(double valueA, double valueB) {
    return valueA > valueB ? valueA : valueB;
}

long int Math::min(long int valueA, long int valueB) {
    return valueA < valueB ? valueA : valueB;
}

float Math::min(float valueA, float valueB) {
    return valueA < valueB ? valueA : valueB;
}

long long Math::min(long long valueA, long long valueB) {
    return valueA < valueB ? valueA : valueB;
}

double Math::min(double valueA, double valueB) {
    return valueA < valueB ? valueA : valueB;
}

long int Math::multiplyExact(long int valueA, long int valueB) {
    long long result = (long) valueA * (long) valueB;
    if (result - (int) result > 0) {
        throw ArithmeticException("integer overflow");
    }
    return (int) result;
}

long long Math::multiplyExact(long long valueA, long long valueB) {
    if (valueA == Long::MIN_VALUE && valueB == -1) {
        throw ArithmeticException("long long overflow");

    }

    long long result = valueA * valueB;
    unsigned long long absA = (unsigned) abs(valueA);
    unsigned long long absB = (unsigned) abs(valueB);

    if (((absA | absB) >> 31) != 0) {
        if ((valueB != 0) && (result / valueB != valueA)) {
            throw ArithmeticException("long long overflow");
        }
    }
    return result;
}

long int Math::negateExact(long int intValue) {
    if (intValue == Integer::MIN_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return -intValue;
}

long long Math::negateExact(long long longValue) {
    if (longValue == Long::MIN_VALUE) {
        throw ArithmeticException("long long overflow");
    }
    return -longValue;
}

double Math::nextAfter(double start, double direction) {
    return nexttoward(start, direction);
}

float Math::nextAfter(float start, double direction) {
    return nexttowardf(start, direction);
}

double Math::nextDown(double value) {
    if (Double::isNaN(value) || value == Double::NEGATIVE_INFINITY) {
        return value;
    }
    if (value == 0.0) {
        return -Double::MIN_VALUE;
    }

    return ::nexttoward(value, Double::NEGATIVE_INFINITY);
}

float Math::nextDown(float value) {
    if (Float::isNaN(value) || value == Float::NEGATIVE_INFINITY) {
        return value;
    }

    if (value == 0.0) {
        return -Float::MIN_VALUE;
    }

    return ::nexttowardf(value, Float::NEGATIVE_INFINITY);
}

float Math::nextUp(float value) {
    if (Float::isNaN(value) || value == Float::POSITIVE_INFINITY) {
        return value;
    }

    return ::nexttowardf(value, Float::POSITIVE_INFINITY);
}

double Math::nextUp(double value) {
    if (Double::isNaN(value) || value == Double::POSITIVE_INFINITY) {
        return value;
    }

    return ::nexttoward(value, Double::POSITIVE_INFINITY);
}

double Math::pow(double base, double exponent) {
    return ::pow(base, exponent);
}

double Math::powerOfTwoD(long int exponent) {
    if (exponent < Double::MIN_EXPONENT || exponent > Double::MAX_EXPONENT) {
        throw AssertionError(exponent);
    }
    long long oneLong = 1;
    return Double::longBitsToDouble(((exponent + Double::EXP_BIAS)
            << (Double::SIGNIFICAND_WIDTH - oneLong)) & Double::EXP_BIT_MASK);
}

// TODO need Float::intBitsToFloat
float Math::powerOfTwoF(long int exponent) {
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
    return ::rint(value);
}

long int Math::round(float value) {
    return (int) ::roundf(value);
}

long long Math::round(double value) {
    return (long) ::round(value);
}

float Math::scalb(float value, long int scaleFactor) {
    return ::ldexpf(value, scaleFactor);
}

double Math::scalb(double value, long int scaleFactor) {
    return ::scalbn(value, scaleFactor);
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
    return ::sin(angle);
}

double Math::sinh(double angle) {
    return ::sinh(angle);
}

double Math::sqrt(double value) {
    return ::sqrt(value);
}

long long Math::subtractExact(long long valueA, long long valueB) {
    long long result = valueA - valueB;
    if (((valueA ^ valueB) & (valueA ^ result)) < 0) {
        throw ArithmeticException("long long overflow");
    }
    return result;
}

long int Math::subtractExact(long int valueA, long int valueB) {
    long int result = valueA - valueB;
    if (((valueA ^ valueB) & (valueA ^ result)) < 0) {
        throw ArithmeticException("integer overflow");
    }
    return result;
}

double Math::tan(double angle) {
    return ::tan(angle);
}

double Math::tanh(double angle) {
    return ::tanh(angle);
}

double Math::toDegrees(double angleRadian) {
    return angleRadian * 180.0 / PI;
}

long int Math::toIntExact(long long value) {
    if (value - (int) value > 0) {
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
    long int exp = getExponent(value);
    switch (exp) {
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
    long int exp = getExponent(value);
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