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

using namespace Java::Lang;

int Math::abs(int a) {
    return a >= 0 ? a : -a;
}

float Math::abs(float a) {
    return a >= 0 ? a : -a;
}

long Math::abs(long a) {
    return a >= 0 ? a : -a;
}

double Math::abs(double a) {
	return a >= 0 ? a : -a;
}

double Math::acos(double value) {
    return math_acos(value);
}

double Math::asin(double a) {
    return math_asin(a);
}

double Math::atan(double a) {
    return math_atan(a);
}

double Math::atan2(double corX, double corY) {
    return math_atan2(corX, corY);
}

long Math::addExact(long a, long b) {
    long result = a + b;
    if (((a ^ result) & (b ^ result)) < 0) {
        throw ArithmeticException("long overflow");
    }
    return result;
}

int Math::addExact(int a, int b) {
    int result = a + b;
    if (((a ^ result) & (b ^ result)) < 0) {
        throw ArithmeticException("integer overflow");
    }
    return result;
}

double Math::cbrt(double a) {
    return math_cbrt(a);
}

double Math::ceil(double a) {
    return math_ceil(a);
}

double Math::copySign(double magnitude, double sign) {
    return math_copysign(magnitude, sign);
}

float Math::copySign(float magnitude, float sign) {
    return math_copysignf(magnitude, sign);
}

double Math::cos(double a) {
    return math_cos(a);
}

double Math::cosh(double a) {
    return math_cosh(a);
}

long Math::decrementExact(long a) {
    if (a == Long::MIN_VALUE) {
        throw ArithmeticException("long overflow");
    }
    return a - 1;
}

int Math::decrementExact(int a) {
    if (a == Integer::MIN_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return a - 1;
}

double Math::exp(double a) {
    return math_exp(a);
}

double Math::expm1(double a) {
    return math_expm1(a);
}

double Math::floor(double a) {
	return math_floor(a);
}

int Math::floorDiv(int a, int b) {
    if (b == 0) {
        throw ArithmeticException();
    }
    int result = a / b;
    // if the signs are different and modulo not zero, round down
    if ((a ^ b) < 0 && (result * b != a)) {
        result--;
    }
    return result;
}

long Math::floorDiv(long a, long b) {
    if (b == 0) {
        throw ArithmeticException();
    }
    long result = a / b;
    // if the signs are different and modulo not zero, round down
    if ((a ^ b) < 0 && (result * b != a)) {
        result--;
    }
    return result;
}

int Math::floorMod(int a, int b) {
    return a - (floorDiv(a, b) * b);
}

long Math::floorMod(long a, long b) {
    return a - (floorDiv(a, b) * b);
}

int Math::getExponent(double a) {
    return static_cast<int>(((Double::doubleToRawLongBits(a) & Double::EXP_BIT_MASK)
                >> (Double::SIGNIFICAND_WIDTH - 1)) - Double::EXP_BIAS);
}

int Math::getExponent(float a) {
    // return ((Float::floatToRawIntBits(a) & Float::EXP_BIT_MASK)
    //        >> (Float::SIGNIFICAND_WIDTH - 1)) - Float::EXP_BIAS;
    return 0;
}

double Math::hypot(double a, double b) {
    return math_hypot(a, b);
}

double Math::IEEEremainder(double dividend, double divisor) {
    return math_ieeeremainder(dividend, divisor);
}

int Math::incrementExact(int a) {
    if (a == Integer::MAX_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return a + 1;
}

long Math::incrementExact(long a) {
    if (a == Long::MAX_VALUE) {
        throw ArithmeticException("long overflow");
    }
    return a + 1L;
}

double Math::log(double a) {
    return math_log(a);
}

double Math::log10(double a) {
    return math_log10(a);
}

double Math::log1p(double a) {
    return math_log1p(a);
}

int Math::max(int a, int b) {
    return a > b ? a : b;
}

float Math::max(float a, float b) {
    return a > b ? a : b;
}

long Math::max(long a, long b) {
    return a > b ? a : b;
}

double Math::max(double a, double b) {
	return a > b ? a : b;
}

int Math::min(int a, int b) {
    return a < b ? a : b;
}

float Math::min(float a, float b) {
	return a < b ? a : b;
}

long Math::min(long a, long b) {
    return a < b ? a : b;
}

double Math::min(double a, double b) {
    return a < b ? a : b;
}

int Math::multiplyExact(int a, int b) {
    long result = (long)a * (long)b;
    if ((int)result != result) {
        throw ArithmeticException("integer overflow");
    }
    return (int)result;
}

long Math::multiplyExact(long a, long b) {
    long result = a * b;
    unsigned long absA = abs(a);
    unsigned long absB = abs(b);

    if (((absA | absB) >> 31) != 0) {
        if ((a == Long::MIN_VALUE && b == -1) || ((b != 0) && (result / b != a))) {
            throw ArithmeticException("long overflow");
        }
    }
    return result;
}

int Math::negateExact(int a) {
    if (a == Integer::MIN_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return -a;
}

long Math::negateExact(long a) {
    if (a == Long::MIN_VALUE) {
        throw ArithmeticException("long overflow");
    }
    return -a;
}

double Math::nextAfter(double start, double direction) {
    return math_nexttoward(start, direction);
}

float Math::nextAfter(float start, double direction) {
    return math_nexttowardf(start, direction);
}

double Math::nextDown(double a) {
    if (Double::isNaN(a) || a == Double::NEGATIVE_INFINITY) {
        return a;
    } else {
        if (a == 0.0) {
            return -Double::MIN_VALUE;
        } else {
            return Double::longBitsToDouble(Double::doubleToRawLongBits(a) + ((a > 0.0) ? -1L : +1L));
        }
    }
}

// TODO need Float.intBitsToFloat, Float.floatToRawIntBits
float Math::nextDown(float a) {
    if (Float::isNaN(a) || a == Float::NEGATIVE_INFINITY) {
        return a;
    } else {
        if (a == 0.0) {
            return -Float::MIN_VALUE;
        }
        /*else {
               return Float.intBitsToFloat(Float.floatToRawIntBits(f) + ((f > 0.0f) ? -1 : +1));
        }*/
    }
}

// TODO need Float::intBitsToFloat, Float::floatToRawIntBits
float Math::nextUp(float a) {
    if (Float::isNaN(a) || a == Float::POSITIVE_INFINITY) {
        return a;
    } else {
        // a += 0.0f;
        // return Float::intBitsToFloat(Float::floatToRawIntBits(a) + ((a >= 0.0) ? +1 : -1));
    }
}

double Math::nextUp(double a) {
    if (Double::isNaN(a) || a == Double::POSITIVE_INFINITY) {
        return a;
    } else {
       a += 0.0f;
       return Double::longBitsToDouble(Double::doubleToRawLongBits(a) + ((a >= 0.0) ? +1 : -1));
    }
}

double Math::pow(double base, double exponent) {
    return math_pow(base, exponent);
}

double Math::powerOfTwoD(int n) {
    if (n < Double::MIN_EXPONENT || n > Double::MAX_EXPONENT) {
        // TODO throw Assertion error
        return 0;
    } else {
        return Double::longBitsToDouble((((long) n + (long) Double::EXP_BIAS)
                << (Double::SIGNIFICAND_WIDTH - 1)) & Double::EXP_BIT_MASK);
    }
}

// TODO need Float::intBitsToFloat
float Math::powerOfTwoF(int n) {
    if (n >= Float::MIN_EXPONENT && n <= Float::MAX_EXPONENT) {
        // TODO throw Assertion error
        return 0;
    } else {
      /*  return Float::intBitsToFloat(((n + Float::EXP_BIAS)
                << (Float::SIGNIFICAND_WIDTH-1)) & Float::EXP_BIT_MASK);*/
        return 1;
    }
}

double Math::random() {
    Random random1 = Random();
    return random1.nextDouble();
}

double Math::rint(double a) {
    return math_rint(a);
}

int Math::round(float a) {
    return (int) math_round(a);
}

long Math::round(double a) {
	return (long) math_round(a);
}

float Math::scalb(float a, int scaleFactor) {
    return math_ldexpf(a, scaleFactor);
}

double Math::scalb(double a, int scaleFactor) {
    return math_ldexp(a, scaleFactor);
}

double Math::signum(double a) {
    return (a == 0.0 || Double::isNaN(a)) ? a: copySign(1.0, a);
}

float Math::signum(float a) {
    return (a == 0.0f || Float::isNaN(a)) ? a : copySign(1.0f, a);
}

double Math::sin(double a) {
    return math_sin(a);
}

double Math::sinh(double a) {
    return math_sinh(a);
}

double Math::sqrt(double a) {
	return math_sqrt(a);
}

long Math::subtractExact(long a, long b) {
    long result = a - b;
    if (((a ^ b) & (a ^ result)) < 0) {
        throw ArithmeticException("long overflow");
    }
    return result;
}

int Math::subtractExact(int a, int b) {
    int result = a - b;
    if (((a ^ b) & (a ^ result)) < 0) {
        throw ArithmeticException("integer overflow");
    }
    return result;
}

double Math::tan(double a) {
    return math_tan(a);
}

double Math::tanh(double a) {
    return math_tanh(a);
}

double Math::toDegrees(double angleRadian) {
    return angleRadian * 180.0 / PI;
}

int Math::toIntExact(long a) {
    if ((int)a != a) {
        throw ArithmeticException("integer overflow");
    }
    return (int) a;
}

double Math::toRadians(double angleDegree) {
    return angleDegree / 180.0 * PI;
}

//TODO need Float::intBitsToFloat
float Math::ulp(float a) {
    if (a == Float::MAX_VALUE || a == -Float::MAX_VALUE) {
        return static_cast<float>(Math::pow(2, 104));
    }
    int exp = getExponent(a);
    switch(exp) {
        case Float::MAX_EXPONENT + 1:        // NaN or infinity
            return Math::abs(a);
        case Float::MIN_EXPONENT - 1:        // zero or subnormal
            return Float::MIN_VALUE;
        default:
            if (exp > Float::MAX_EXPONENT || exp < Float::MIN_EXPONENT) {
                //TODO Throw Assertion error
                return 0;
            } else {
                exp = exp - (Float::SIGNIFICAND_WIDTH - 1);
                if (exp >= Float::MIN_EXPONENT) {
                    return powerOfTwoF(exp);
                } else {
                 /*   return Float::intBitsToFloat(1 << (exp - (Float::MIN_EXPONENT
                                                              - (Float::SIGNIFICAND_WIDTH - 1)) ));*/
                }
            }
    }
}

double Math::ulp(double a) {
    if (a == Double::MAX_VALUE || a == -Double::MAX_VALUE) {
        return Math::pow(2, 971);
    }
    int exp = getExponent(a);
    switch(exp) {
        case Double::MAX_EXPONENT + 1:        // NaN or infinity
            return Math::abs(a);
        case Double::MIN_EXPONENT - 1:        // zero or subnormal
            return Double::MIN_VALUE;
        default:
            if (exp > Double::MAX_EXPONENT || exp < Double::MIN_EXPONENT) {
                // TODO Throw Assertion error
                return 0;
            } else {
                exp = exp - (Double::SIGNIFICAND_WIDTH - 1);
                if (exp >= Double::MIN_EXPONENT) {
                    return powerOfTwoD(exp);
                } else {
                    return Double::longBitsToDouble(1 << (exp - (Double::MIN_EXPONENT 
                                                                 - (Double::SIGNIFICAND_WIDTH - 1))));
                }
            }
    }
}




























