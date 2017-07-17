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

#include "Math.hpp"
#include "../Long/Long.hpp"
#include "../Integer/Integer.hpp"
#include "exception"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

RandomNumberGeneratorHolder *RandomNumberGeneratorHolder::instance =0;

long Math::negativeZeroDoubleBits = Double::doubleToRawLongBits(-0.0);

//TODO need Float::floatToRawIntBits
//long Math::negativeZeroFloatBits = Float::floatToRawIntBits(-0.0f);

/**
 * Returns the absolute value of an int value
 *
 * @param a
 * @return a if a is positive, else -a
 */
int Math::abs(int a) {
    return a >= 0 ? a : -a;
}

/**
 * Returns the absolute value of an float value
 *
 * @param a
 * @return a if a is positive, else -a
 */
float Math::abs(float a) {
    return a >= 0 ? a : -a;
}

/**
 * Returns the absolute value of an long value
 *
 * @param a
 * @return a if a is positive, else -a
 */
long Math::abs(long a) {
    return a >= 0 ? a : -a;
}

/**
 * Returns the absolute value of an double value
 *
 * @param a
 * @return a if a is positive, else -a
 */
double Math::abs(double a) {
	return a >= 0 ? a : -a;
}

/**
 * Returns the arc cosine of a value
 *
 * @param value
 * @return principal arc cosine of x, in the interval [0,pi] radians.
 * If the argument is NaN or its absolute value is greater than 1, then the result is NaN.
 */
double Math::acos(double value) {
    return math_acos(value);
}

/**
 * Returns the arc sine of a value
 *
 * @param value
 * @return principal arc sine of x, in the interval [-pi/2,+pi/2]] radians.
 * If the argument is NaN or its absolute value is greater than 1, then the result is NaN.
 * If the argument is zero, then the result is a zero with the same sign as the argument.
 */
double Math::asin(double a) {
    return math_asin(a);
}

/**
 * Returns the arc tangent of a value
 *
 * @param value
 * @return Principal arc tangent of x, in the interval [-pi/2,+pi/2] radians.
 */
double Math::atan(double a) {
    return math_atan(a);
}

/**
 * Returns the principal value of the arc tangent of y/x
 *
 * @param corX
 * @param corY
 * @return Principal arc tangent of y/x, in the interval [-pi,+pi] radians.
 */
double Math::atan2(double corX, double corY) {
    return math_atan2(corX, corY);
}

/**
 * Returns the sum of its arguments, throwing an exception if the result overflows a long.
 *
 * @param a
 * @param b
 * @return long
 */
long Math::addExact(long a, long b) {
    long result = a + b;
    if (((a ^ result) & (b ^ result)) < 0) {
        throw ArithmeticException("long overflow");
    }
    return result;
}

/**
 * Returns the sum of its arguments, throwing an exception if the result overflows a long.
 *
 * @param a
 * @param b
 * @return int
 */
int Math::addExact(int a, int b) {
    int result = a + b;
    if (((a ^ result) & (b ^ result)) < 0) {
        throw ArithmeticException("integer overflow");
    }
    return result;
}

/**
 * Returns the cube root of a double value.
 *
 * @param a
 * @return
 *  If the argument is NaN, then the result is NaN.
 *  If the argument is infinite, then the result is an
 *  infinity with the same sign as the argument.
 *  If the argument is zero, then the result is a zero
 *  with the same sign as the argument.
 */
double Math::cbrt(double a) {
    return math_cbrt(a);
}

/**
 * Returns the smallest (closest to negative infinity) double value
 * that is greater than or equal to the argument and is equal to a mathematical integer.
 *
 * @param a
 * @return double
 * If the argument value is already equal to a mathematical integer,
 * then the result is the same as the argument.
 * If the argument is NaN or an infinity or positive zero or negative zero,
 * then the result is the same as the argument.
 * If the argument value is less than zero but greater than -1.0,
 * then the result is negative zero.
 */
double Math::ceil(double a) {
    return math_ceil(a);
}

/**
 * Returns the first double argument with the sign of the second double argument.
 *
 * @param magnitude
 * @param sign
 * @return double
 */
double Math::copySign(double magnitude, double sign) {
    return math_copysign(magnitude, sign);
}

/**
 * Returns the first float argument with the sign of the second float argument.
 *
 * @param magnitude
 * @param sign
 * @return float
 */
float Math::copySign(float magnitude, float sign) {
    return math_copysignf(magnitude, sign);
}

/**
 * Returns the trigonometric cosine of an angle
 *
 * @param a
 * @return the cosine of the argument
 * If the argument is NaN or an infinity, then the result is NaN.
 */
double Math::cos(double a) {
    return math_cos(a);
}

/**
 * Returns the hyperbolic cosine of a double value.
 *
 * @param a
 * @return the hyperbolic cosine of a
 *  If the argument is NaN, then the result is NaN.
 *  If the argument is infinite, then the result is positive infinity.
 *  If the argument is zero, then the result is 1.0.
 */
double Math::cosh(double a) {
    return math_cosh(a);
}

/**
 * Returns the argument decremented by one,
 * throwing an exception if the result overflows an long.
 *
 * @param a
 * @return long
 */
long Math::decrementExact(long a) {
    if(a == Long::MIN_VALUE){
        throw ArithmeticException("long overflow");
    }
    return a - 1;
}

/**
 * Returns the argument decremented by one,
 * throwing an exception if the result overflows an long.
 *
 * @param a
 * @return int
 */
int Math::decrementExact(int a) {
    if(a == Integer::MIN_VALUE){
        throw ArithmeticException("integer overflow");
    }
    return a - 1;
}

/**
 * Returns Euler's number e raised to the power of a double value
 *
 * @param a
 * @return the value (e^a),
 * If the argument is NaN, the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is negative infinity, then the result is positive zero.
 */
double Math::exp(double a) {
    return math_exp(a);
}

/**
 * Returns Euler's number e raised to the power of a double value then subtract 1.
 *
 * @param a
 * @return the value (e^a)-1
 * If the argument is NaN, the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is negative infinity, then the result is positive zero.
 */
double Math::expm1(double a) {
    return math_expm1(a);
}

/**
 * Returns the largest (closest to positive infinity) double value
 * that is less than or equal
 * to the argument and is equal to a mathematical integer.
 *
 * @param a
 * @return double
 * If the argument value is already equal to a mathematical integer,
 * then the result is the same as the argument.
 * If the argument is NaN or an infinity or positive zero or negative zero,
 * then the result is the same as the argument.
 */
double Math::floor(double a) {
	return math_floor(a);
}

/**
 * Returns the largest (closest to positive infinity)
 * int value that is less than or equal to the algebraic quotient
 *
 * @param a
 * @param b
 * @return int
 */
int Math::floorDiv(int a, int b) {
    if(b == 0)
        throw ArithmeticException();
    int result = a / b;
    // if the signs are different and modulo not zero, round down
    if ((a ^ b) < 0 && (result * b != a)) {
        result--;
    }
    return result;
}

/**
 * Returns the largest (closest to positive infinity)
 * int value that is less than or equal to the algebraic quotient
 *
 * @param a
 * @param b
 * @return long
 */
long Math::floorDiv(long a, long b) {
    if(b == 0)
        throw ArithmeticException();
    long result = a / b;
    // if the signs are different and modulo not zero, round down
    if ((a ^ b) < 0 && (result * b != a)) {
        result--;
    }
    return result;
}

/**
 * Returns the floor modulus of the int arguments.
 *
 * @param a
 * @param b
 * @return int
 * If the signs of the arguments are the same, the results of floorMod
 * and the % operator are the same.
 * If the signs of the arguments are different, the results differ from the % operator.
 */
int Math::floorMod(int a, int b) {
    return a - (floorDiv(a, b) * b);
}

/**
 * Returns the floor modulus of the int arguments.
 *
 * @param a
 * @param b
 * @return long
 * If the signs of the arguments are the same, the results of floorMod
 * and the % operator are the same.
 * If the signs of the arguments are different, the results differ from the % operator.
 */
long Math::floorMod(long a, long b) {
    return a - (floorDiv(a, b) * b);
}

/**
 * Returns the unbiased exponent used in the representation of a double
 *
 * @param a
 * @return int
 * If the argument is NaN or infinite, then the result is Double::MAX_EXPONENT + 1.
 * If the argument is zero or subnormal, then the result is Double::MIN_EXPONENT -1.
 */
int Math::getExponent(double a) {
    //return ((Double::floatToRawIntBits(a) & Double::EXP_BIT_MASK)
    //        >> (Double::SIGNIFICAND_WIDTH - 1)) - Double::EXP_BIAS;
    return 0;
}

/**
 * Returns the unbiased exponent used in the representation of a float
 *
 * @param a
 * @return int
 * If the argument is NaN or infinite, then the result is Float::MAX_EXPONENT + 1.
 * If the argument is zero or subnormal, then the result is Float::MIN_EXPONENT -1.
 */
int Math::getExponent(float a) {
    //return ((Float::floatToRawIntBits(a) & Float::EXP_BIT_MASK)
    //        >> (Float::SIGNIFICAND_WIDTH - 1)) - Float::EXP_BIAS;
    return 0;
}

/**
 * Returns sqrt(x2 +y2) without intermediate overflow or underflow.
 *
 * @param a
 * @param b
 * @return double
 *
 * If either argument is infinite, then the result is positive infinity.
 * If either argument is NaN and neither argument is infinite, then the result is NaN.
 */
double Math::hypot(double a, double b) {
    return math_hypot(a, b);
}

/**
 * Computes the remainder operation on two arguments as prescribed by the IEEE 754 standard.
 *
 * @param dividend
 * @param divisor
 * @return the remainder when dividend is divided by divisor.
 * If either argument is NaN, or the first argument is infinite,
 * or the second argument is positive zero or negative zero, then the result is NaN.
 * If the first argument is finite and the second argument is infinite,
 * then the result is the same as the first argument.
 */
double Math::IEEEremainder(double dividend, double divisor) {
    return math_ieeeremainder(dividend, divisor);
}

/**
 * Returns the argument incremented by one,
 * throwing an exception if the result overflows a long.
 *
 * @param a
 * @return int
 */
int Math::incrementExact(int a) {
    if (a == Integer::MAX_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return a + 1;
}

/**
 * Returns the argument incremented by one,
 * throwing an exception if the result overflows a long.
 *
 * @param a
 * @return long
 */
long Math::incrementExact(long a) {
    if (a == Long::MAX_VALUE) {
        throw ArithmeticException("long overflow");
    }
    return a + 1L;
}



/**
 * initialize the randomNumberGenerator
 */
//TODO need Random
void Math::initRGN() {

}

/**
 * Returns the natural logarithm (base e) of a double value
 *
 * @param a
 * @return double
 * If the argument is NaN or less than zero, then the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is positive zero or negative zero, then the result is negative infinity.
 */
double Math::log(double a) {
    return math_log(a);
}

/**
 * Returns the base 10 logarithm of a double value
 *
 * @param a
 * @return double
 * If the argument is NaN or less than zero, then the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is positive zero or negative zero, then the result is negative infinity.
 * If the argument is equal to 10n for integer n, then the result is n.
 */
double Math::log10(double a) {
    return math_log10(a);
}

/**
 * Returns the natural logarithm of the sum of the argument and 1
 *
 * @param a
 * @return double
 * If the argument is NaN or less than -1, then the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is negative one, then the result is negative infinity.
 * If the argument is zero, then the result is a zero with the same sign as the argument.
 */
double Math::log1p(double a) {
    return math_log1p(a);
}

/**
 * Returns the greater of two int values.
 *
 * @param a
 * @param b
 * @return a if a>b; else b
 */
int Math::max(int a, int b) {
    return a > b ? a : b;
}

/**
 * Returns the greater of two float values.
 *
 * @param a
 * @param b
 * @return a if a>b; else b
 */
float Math::max(float a, float b) {
    return a > b ? a : b;
}

/**
 * Returns the greater of two long values.
 *
 * @param a
 * @param b
 * @return a if a>b; else b
 */
long Math::max(long a, long b) {
    return a > b ? a : b;
}

/**
 * Returns the greater of two double values.
 *
 * @param a
 * @param b
 * @return a if a>b; else b
 */
double Math::max(double a, double b) {
	return a > b ? a : b;
}

/**
 * Returns the smaller of two int values.
 *
 * @param a
 * @param b
 * @return a if a<b; else b
 */
int Math::min(int a, int b) {
    return a < b ? a : b;
}

/**
 * Returns the greater of two float values.
 *
 * @param a
 * @param b
 * @return a if a<b; else b
 */
float Math::min(float a, float b) {
	return a < b ? a : b;
}

/**
 * Returns the greater of two long values.
 *
 * @param a
 * @param b
 * @return a if a<b; else b
 */
long Math::min(long a, long b) {
    return a < b ? a : b;
}

/**
 * Returns the greater of two double values.
 *
 * @param a
 * @param b
 * @return a if a<b; else b
 */
double Math::min(double a, double b) {
    return a < b ? a : b;
}

/**
 * Returns the product of the arguments,
 * throwing an exception if the result overflows an int.
 *
 * @param a
 * @param b
 * @return
 */
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
        if((a == Long::MIN_VALUE && b == -1) || ((b != 0) && (result / b != a)))
            throw ArithmeticException("long overflow");
    }
    return result;
}

/**
 * Returns the negation of the argument,
 * throwing an exception if the result overflows a long.
 *
 * @param a
 * @return int
 */
int Math::negateExact(int a) {
    if (a == Integer::MIN_VALUE) {
        throw ArithmeticException("integer overflow");
    }
    return -a;
}

/**
 * Returns the negation of the argument,
 * throwing an exception if the result overflows a long.
 *
 * @param a
 * @return long
 */
long Math::negateExact(long a) {
    if (a == Long::MIN_VALUE) {
        throw ArithmeticException("long overflow");
    }
    return -a;
}


/**
 * Returns the floating-point number adjacent to the first argument in the direction
 * of the second argument.If both arguments compare as equal the second argument is returned.
 *
 * @param start
 * @param direction
 * @return double
 * If either argument is a NaN, then NaN is returned.
 * If both arguments are signed zeros, a value equivalent to direction is returned.
 * If start is ±Double.MIN_VALUE and direction has a value such that the result should
 *  have a smaller magnitude, then a zero with the same sign as start is returned.
 * If start is infinite and direction has a value such that the result should have
 *  a smaller magnitude, Double.MAX_VALUE with the same sign as start is returned.
 * If start is equal to ± Double.MAX_VALUE and direction has a value such that the
 *  result should have a larger magnitude, an infinity with same sign as start is returned.
 */
double Math::nextAfter(double start, double direction) {
    return math_nexttoward(start, direction);
}

/**
 * Returns the floating-point number adjacent to the first argument in the direction
 * of the second argument.If both arguments compare as equal the second argument is returned.
 *
 * @param start
 * @param direction
 * @return float
 * If either argument is a NaN, then NaN is returned.
 * If both arguments are signed zeros, a value equivalent to direction is returned.
 * If start is ±Float.MIN_VALUE and direction has a value such that the result should
 *  have a smaller magnitude, then a zero with the same sign as start is returned.
 * If start is infinite and direction has a value such that the result should have
 *  a smaller magnitude, Float.MAX_VALUE with the same sign as start is returned.
 * If start is equal to ± Float.MAX_VALUE and direction has a value such that the
 *  result should have a larger magnitude, an infinity with same sign as start is returned.
 */
//TODO need sun.misc.FpUtils
float Math::nextAfter(float start, double direction) {
    return math_nexttowardf(start, direction);
}

/**
 * Returns the floating-point value adjacent to f in the direction of negative infinity.
 *
 * @param a
 * @return double
 *  If the argument is NaN, the result is NaN.
 *  If the argument is negative infinity, the result is negative infinity.
 *  If the argument is zero, the result is -Double.MIN_VALUE
 */
//TODO need Double::longBitsToDouble, Double::doubleToRawLongBits
double Math::nextDown(double a) {
    if (Double::isNaN(a) || a == Double::NEGATIVE_INFINITY)
        return a;
    else {
        if (a == 0.0)
            return -Double::MIN_VALUE;
  /*      else
            return Double::longBitsToDouble(Double::doubleToRawLongBits(a)
                                           + ((a > 0.0)?-1L:+1L));*/
    }
}

/**
 * Returns the floating-point value adjacent to f in the direction of negative infinity.
 *
 * @param a
 * @return float
 *  If the argument is NaN, the result is NaN.
 *  If the argument is negative infinity, the result is negative infinity.
 *  If the argument is zero, the result is -Double.MIN_VALUE
 */
//TODO need Float.intBitsToFloat, Float.floatToRawIntBits
float Math::nextDown(float a) {
    if (Float::isNaN(a) || a == Float::NEGATIVE_INFINITY)
        return a;
    else {
        if (a == 0.0)
            return -Float::MIN_VALUE;
        /*else
               return Float.intBitsToFloat(Float.floatToRawIntBits(f) +
                                            ((f > 0.0f)?-1:+1));*/
    }
}


/**
 * Returns the floating-point value adjacent to f in the direction of positive infinity.
 *
 * @param a
 * @return float
 * If the argument is NaN, the result is NaN.
 * If the argument is positive infinity, the result is positive infinity.
 * If the argument is zero, the result is Float.MIN_VALUE
 */
 //TODO need Float::intBitsToFloat, Float::floatToRawIntBits
float Math::nextUp(float a) {
    if( Float::isNaN(a) || a == Float::POSITIVE_INFINITY)
        return a;
 /*   else {
        a += 0.0f;
        return Float::intBitsToFloat(Float::floatToRawIntBits(a) +
                                            ((a >= 0.0)?+1:-1));
    }*/
}

/**
 * Returns the floating-point value adjacent to f in the direction of positive infinity.
 *
 * @param a
 * @return double
 * If the argument is NaN, the result is NaN.
 * If the argument is positive infinity, the result is positive infinity.
 * If the argument is zero, the result is Double.MIN_VALUE
 */
//TODO need Double::longBitsToDouble, Double::doubleToRawLongBits
double Math::nextUp(double a) {
    if( Double::isNaN(a) || a == Double::POSITIVE_INFINITY)
        return a;
       else {
           a += 0.0f;
           return Double::longBitsToDouble(Double::doubleToRawLongBits(a) +
                                               ((a >= 0.0)?+1:-1));
       }
}

/**
 * Returns the value of the first argument raised to the power of the second argument
 *
 * @param base
 * @param exponent
 * @return double
 */
double Math::pow(double base, double exponent) {
    return math_pow(base, exponent);
}

/**
 * Returns a floating-point power of two in the normal range.
 *
 * @param n
 * @return double
 */
//TODO need Double::longBitsToDouble
double Math::powerOfTwoD(int n) {
    if(n < Double::MIN_EXPONENT || n > Double::MAX_EXPONENT)
        //TODO throw Assertion error
        return 0;
    else
        return Double::longBitsToDouble((((long)n + (long)Double::EXP_BIAS) <<
               (Double::SIGNIFICAND_WIDTH - 1)) & Double::EXP_BIT_MASK);
}

/**
 * Returns a floating-point power of two in the normal range.
 *
 * @param n
 * @return float
 */
//TODO need Float::intBitsToFloat
float Math::powerOfTwoF(int n) {
    if(n >= Float::MIN_EXPONENT && n <= Float::MAX_EXPONENT)
        //TODO throw Assertion error
        return 0;
    else
   /* return Float::intBitsToFloat(((n + Float::EXP_BIAS) <<
           (Float::SIGNIFICAND_WIDTH-1)) & Float::EXP_BIT_MASK);*/
        return 1;
}

/**
 * Returns a double value with a positive sign, greater than or equal to 0.0
 * and less than 1.0
 *
 * @return double
 */
//TODO need Random
double Math::random() {
    //if (randomNumberGenerator == null) initRNG();
    //return randomNumberGenerator.nextDouble();
    return 0;
}

/**
 * Returns the double value that is closest in value to the argument
 * and is equal to a mathematical integer
 *
 * @param a
 * @return double
 * If the argument value is already equal to a mathematical integer,
 * then the result is the same as the argument.
 * If the argument is NaN or an infinity or positive zero or negative zero,
 * then the result is the same as the argument.
 */
double Math::rint(double a) {
    return math_rint(a);
}

/**
 * Returns the closest int to the argument.
 *
 * @param a
 * @return int
 * If the argument is NaN, the result is 0.
 * If the argument is negative infinity or any value less than or equal
 * to the value of Integer.MIN_VALUE, the result is equal to the value of Integer.MIN_VALUE.
 * If the argument is positive infinity or any value greater than or equal
 * to the value of Integer.MAX_VALUE, the result is equal to the value of Integer.MAX_VALUE.
 */
int Math::round(float a) {
    return (int) math_round(a);
}

/**
 * Returns the closest long to the argument.
 *
 * @param a
 * @return long
 * If the argument is NaN, the result is 0.
 * If the argument is negative infinity or any value less than or equal
 * to the value of Long.MIN_VALUE, the result is equal to the value of Integer.MIN_VALUE.
 * If the argument is positive infinity or any value greater than or equal
 * to the value of Long.MAX_VALUE, the result is equal to the value of Integer.MAX_VALUE.
 */
long Math::round(double a) {
	return (long) math_round(a);
}

/**
 * Return a × 2^scaleFactor rounded
 *
 * @param a
 * @param scaleFactor
 * @return float
 * If the first argument is NaN, NaN is returned.
 * If the first argument is infinite, then an infinity of the same sign is returned.
 * If the first argument is zero, then a zero of the same sign is returned.
 */
float Math::scalb(float a, int scaleFactor) {
    return math_ldexpf(a, scaleFactor);
}

/**
 * Return a × 2^scaleFactor rounded
 *
 * @param a
 * @param scaleFactor
 * @return double
 * If the first argument is NaN, NaN is returned.
 * If the first argument is infinite, then an infinity of the same sign is returned.
 * If the first argument is zero, then a zero of the same sign is returned.
 */
double Math::scalb(double a, int scaleFactor) {
    return math_ldexp(a, scaleFactor);
}

/**
 * Returns the signum function of the argument
 *
 * @param a
 * @return zero if the argument is zero, 1.0 if the argument is greater than zero,
 * -1.0 if the argument is less than zero.
 * If the argument is NaN, then the result is NaN.
 * If the argument is positive zero or negative zero, then the result
 * is the same as the argument.
 */
double Math::signum(double a) {
    return (a == 0.0 || Double::isNaN(a)) ? a: copySign(1.0, a);
}

/**
 * Returns the signum function of the argument
 *
 * @param a
 * @return zero if the argument is zero, 1.0 if the argument is greater than zero,
 * -1.0 if the argument is less than zero.
 * If the argument is NaN, then the result is NaN.
 * If the argument is positive zero or negative zero, then the result
 * is the same as the argument.
 */
float Math::signum(float a) {
    return (a == 0.0f || Float::isNaN(a)) ? a : copySign(1.0f, a);
}

/**
 * Returns the trigonometric sine of an angle
 *
 * @param a
 * @return the sine of the a
 * If the argument is NaN or an infinity, then the result is NaN.
 * If the argument is zero, then the result is a zero with the same sign as the argument.
 */
double Math::sin(double a) {
    return math_sin(a);
}

/**
 * Returns the hyperbolic sine of a double value.
 *
 * @param a
 * @return the hyperbolic sine of a
 * If the argument is NaN, then the result is NaN.
 * If the argument is infinite, then the result is an infinity with the same sign as the argument.
 * If the argument is zero, then the result is a zero with the same sign as the argument.
 */
double Math::sinh(double a) {
    return math_sinh(a);
}

/**
 * Returns the correctly rounded positive square root of a double value
 *
 * @param a
 * @return double
 * If the argument is NaN or less than zero, then the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is positive zero or negative zero, then the result is
 * the same as the argument.
 */
double Math::sqrt(double a) {
	return math_sqrt(a);
}

/**
 * Returns the difference of the arguments,
 * throwing an exception if the result overflows an long.
 *
 * @param a
 * @param b
 * @return
 */
long Math::subtractExact(long a, long b) {
    long result = a - b;
    if (((a ^ b) & (a ^ result)) < 0) {
        throw ArithmeticException("long overflow");
    }
    return result;
}

/**
 * Returns the difference of the arguments,
 * throwing an exception if the result overflows an int.
 *
 * @param a
 * @param b
 * @return int
 */
int Math::subtractExact(int a, int b) {
    int result = a - b;
    if (((a ^ b) & (a ^ result)) < 0) {
        throw ArithmeticException("integer overflow");
    }
    return result;
}

/**
 * Returns the trigonometric tangent of an angle
 *
 * @param a
 * @return the tangent of the a
 * If the argument is NaN or an infinity, then the result is NaN.
 * If the argument is zero, then the result is a zero with the same sign as the argument.
 */
double Math::tan(double a) {
    return math_tan(a);
}

/**
 * Returns the hyperbolic tangent of a double value.
 *
 * @param a
 * @return the hyperbolic tangent of a
 * If the argument is NaN, then the result is NaN.
 * If the argument is zero, then the result is a zero with the same sign as the argument.
 * If the argument is positive infinity, then the result is +1.0.
 * If the argument is negative infinity, then the result is -1.0.
 */
double Math::tanh(double a) {
    return math_tanh(a);
}

/**
 * Converts an angle measured in radians to an approximately equivalent angle
 * measured in degrees.
 *
 * @param angleRadian
 * @return double
 * If the argument is NaN, the result is NaN.
 * If the argument is positive infinity, then the result is positive infinity.
 * If the argument is negative infinity, then the result is positive zero.
 */
double Math::toDegrees(double angleRadian) {
    return angleRadian * 180.0 / PI;
}

/**
 * Returns the value of the long argument;
 * throwing an exception if the value overflows an int.
 *
 * @param a
 * @return
 */
int Math::toIntExact(long a) {
    if ((int)a != a) {
        throw ArithmeticException("integer overflow");
    }
    return (int) a;
}

/**
 * Converts an angle measured in degrees to an approximately equivalent angle measured in radians.
 * The conversion from radians to degrees is generally inexact;
 * users should not expect cos(toRadians(90.0)) to exactly equal 0.0.
 *
 * @param angleDegree
 * @return
 */
double Math::toRadians(double angleDegree) {
    return angleDegree / 180.0 * PI;
}

/**
 * Returns the size of an ulp of the argument.
 *
 * @param a
 * @return
 *  If the argument is NaN, then the result is NaN.
 *  If the argument is positive or negative infinity, then the result is positive infinity.
 *  If the argument is positive or negative zero, then the result is Float::MIN_VALUE.
 *  If the argument is ±Float::MAX_VALUE, then the result is equal to 2^104.
 */
float Math::ulp(float a) {
    int exp = getExponent(a);
    switch(exp) {
        case Float::MAX_EXPONENT + 1:        // NaN or infinity
            return Math::abs(a);
        case Float::MIN_EXPONENT - 1:        // zero or subnormal
            return Float::MIN_VALUE;
        default:
            if(exp > Float::MAX_EXPONENT || exp < Float::MIN_EXPONENT)
                //TODO Throw Assertion error
                return 0;
            else {
                exp = exp - (Float::SIGNIFICAND_WIDTH - 1);
                if (exp >= Float::MIN_EXPONENT) {
                    return powerOfTwoF(exp);
                }
                /*else {
                    return Float::intBitsToFloat(1 <<
                    (exp - (Float::MIN_EXPONENT - (Float::SIGNIFICAND_WIDTH - 1)) ));
                }*/
            }
    }
}

/**
 * Returns the size of an ulp of the argument.
 *
 * @param a
 * @return
 *  If the argument is NaN, then the result is NaN.
 *  If the argument is positive or negative infinity, then the result is positive infinity.
 *  If the argument is positive or negative zero, then the result is Double.MIN_VALUE.
 *  If the argument is ±Double.MAX_VALUE, then the result is equal to 2^971.
 */
double Math::ulp(double a) {
    int exp = getExponent(a);
    switch(exp) {
        case Double::MAX_EXPONENT + 1:        // NaN or infinity
            return Math::abs(a);
        case Double::MIN_EXPONENT - 1:        // zero or subnormal
            return Double::MIN_VALUE;
        default:
            if(exp > Double::MAX_EXPONENT || exp < Double::MIN_EXPONENT)
                return 0;
            else {
                exp = exp - (Double::SIGNIFICAND_WIDTH - 1);
                if (exp >= Double::MIN_EXPONENT)
                    return powerOfTwoD(exp);
                else {
                    return Double::longBitsToDouble(1 <<
                    (exp - (Double::MIN_EXPONENT - (Double::SIGNIFICAND_WIDTH - 1)) ));
                }
            }
    }
}




























