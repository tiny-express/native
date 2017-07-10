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

using namespace Java::Lang;

RandomNumberGeneratorHolder *RandomNumberGeneratorHolder::instance =0;

long Math::negativeZeroDoubleBits = Double::doubleToRawLongBits(-0.0);

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
 */
double Math::acos(double value) {
    return math_acos(value);
}

/**
 * Returns the arc sine of a value
 *
 * @param value
 * @return principal arc sine of x, in the interval [-pi/2,+pi/2]] radians.
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
        //TODO throw new ArithmeticException("long overflow");

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
        //TODO throw new ArithmeticException("integer overflow");
    }
    return result;
}

/**
 * Returns the cube root of a double value.
 *
 * @param a
 * @return double
 */
double Math::cbrt(double a) {
    return math_cbrt(a);
}

/**
 * Returns the smallest (closest to negative infinity) double value that is greater than or equal
 * to the argument and is equal to a mathematical integer.
 *
 * @param a
 * @return double
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
//TODO need sun.misc.FpUtils
double Math::copySign(double magnitude, double sign) {
    return 0;
}

/**
 * Returns the first float argument with the sign of the second float argument.
 *
 * @param magnitude
 * @param sign
 * @return float
 */
//TODO need sun.misc.FpUtils
float Math::copySign(float magnitude, float sign) {
    return 0;
}

/**
 * Returns the trigonometric cosine of an angle
 *
 * @param a
 * @return the cosine of the argument
 */
double Math::cos(double a) {
    return math_cos(a);
}

/**
 * Returns the hyperbolic cosine of a double value.
 *
 * @param a
 * @return the hyperbolic cosine of a
 */
double Math::cosh(double a) {
    return math_cosh(a);
}

/**
 * Returns the argument decremented by one, throwing an exception if the result overflows an long.
 *
 * @param a
 * @return long
 */
long Math::decrementExact(long a) {
    if(Long::MIN_VALUE == a){
        //TODO throw new ArithmeticException("long overflow");
    }
    return a - 1;
}

/**
 * Returns the argument decremented by one, throwing an exception if the result overflows an long.
 *
 * @param a
 * @return int
 */
int Math::decrementExact(int a) {
    if(Integer::MIN_VALUE == a){
        //TODO throw new ArithmeticException("integer overflow");
    }
    return a - 1;
}

/**
 * Returns Euler's number e raised to the power of a double value
 *
 * @param a
 * @return the value e^a,
 */
double Math::exp(double a) {
    return math_exp(a);
}

/**
 * Returns Euler's number e raised to the power of a double value then subtract 1.
 *
 * @param a
 * @return the value (e^a)-1,
 */
double Math::expm1(double a) {
    return math_expm1(a);
}

/**
 * Returns the largest (closest to positive infinity) double value that is less than or equal
 * to the argument and is equal to a mathematical integer.
 *
 * @param a
 * @return double
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
 */
long Math::floorMod(long a, long b) {
    return a - (floorDiv(a, b) * b);
}

/**
 * Returns the unbiased exponent used in the representation of a double
 *
 * @param a
 * @return int
 */
int Math::getExponent(double a) {
    //return ((Double::floatToRawIntBits(a) & Double::EXP_BIT_MASK)
    //        >> (Double::SIGNIFICAND_WIDTH - 1)) - Double::EXP_BIAS;
}

/**
 * Returns the unbiased exponent used in the representation of a float
 *
 * @param a
 * @return int
 */
int Math::getExponent(float a) {
    //return ((Float::floatToRawIntBits(a) & Float::EXP_BIT_MASK)
    //        >> (Float::SIGNIFICAND_WIDTH - 1)) - Float::EXP_BIAS;
}

/**
 * Returns sqrt(x2 +y2) without intermediate overflow or underflow.
 *
 * @param a
 * @param b
 * @return
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
 */
double Math::IEEEremainder(double dividend, double divisor) {
    return math_ieeeremainder(dividend,divisor);
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
        //TODO throw new ArithmeticException("long overflow");
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
        //TODO throw new ArithmeticException("long overflow");
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
 */
double Math::log(double a) {
    return math_log(a);
}

/**
 * Returns the base 10 logarithm of a double value
 *
 * @param a
 * @return double
 */
double Math::log10(double a) {
    return math_log10(a);
}

/**
 * Returns the natural logarithm of the sum of the argument and 1
 *
 * @param a
 * @return double
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
        //TODO throw new ArithmeticException("integer overflow");
        return 0;
    }
    return (int)result;
}

long Math::multiplyExact(long a, long b) {
    long result = a * b;
    long absA = (unsigned) abs(a);
    long absB = (unsigned) abs(b);

    if (((absA | absB) >> 31 != 0)) {

        // Some bits greater than 2^31 that might cause overflow
        // Check the result using the divide operator
        // and check for the special case of Long.MIN_VALUE * -1

        if (((b != 0) && (result / b != a)) || (a == Long::MIN_VALUE && b == -1)) {
            //TODO throw new ArithmeticException("long overflow");
        }
    }
    return result;
}


/**
 * Returns the floating-point number adjacent to the first argument in the direction
 * of the second argument.If both arguments compare as equal the second argument is returned.
 *
 * @param start
 * @param direction
 * @return double
 */
double Math::nextAfter(double start, double direction) {
    return 0;
}

/**
 * Returns the floating-point number adjacent to the first argument in the direction
 * of the second argument.If both arguments compare as equal the second argument is returned.
 *
 * @param start
 * @param direction
 * @return float
 */
//TODO need sun.misc.FpUtils
float Math::nextAfter(float start, double direction) {
    return 0;
}

/**
 * Returns the floating-point value adjacent to f in the direction of positive infinity.
 *
 * @param a
 * @return float
 */
float Math::nextUp(float a) {
    return 0;
}

/**
 * Returns the floating-point value adjacent to f in the direction of positive infinity.
 *
 * @param a
 * @return double
 */
double Math::nextUp(double a) {
    return 0;
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
 * Returns a double value with a positive sign, greater than or equal to 0.0 and less than 1.0
 *
 * @return double
 */
//TODO need Random
double Math::random() {
    //if (randomNumberGenerator == null) initRNG();
    //return randomNumberGenerator.nextDouble();
}

/**
 * Returns the double value that is closest in value to the argument
 * and is equal to a mathematical integer
 *
 * @param a
 * @return
 */
double Math::rint(double a) {
    return math_rint(a);
}

/**
 * Returns the closest int to the argument.
 *
 * @param a
 * @return
 */
int Math::round(float a) {
    return (int) math_round(a);
}

/**
 * Returns the closest long to the argument.
 *
 * @param a
 * @return
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
 */
float Math::scalb(float a, int scaleFactor) {
    return 0;
}

/**
 * Return a × 2^scaleFactor rounded
 *
 * @param a
 * @param scaleFactor
 * @return double
 */
double Math::scalb(double a, int scaleFactor) {
    return 0;
}

/**
 * Returns the signum function of the argument
 *
 * @param a
 * @return zero if the argument is zero, 1.0 if the argument is greater than zero,
 * -1.0 if the argument is less than zero.
 */
//TODO need sun.misc.FpUtils
double Math::signum(double a) {
    return 0;
}

/**
 * Returns the signum function of the argument
 *
 * @param a
 * @return zero if the argument is zero, 1.0 if the argument is greater than zero,
 * -1.0 if the argument is less than zero.
 */
float Math::signum(float a) {
    return 0;
}

/**
 * Returns the trigonometric sine of an angle
 *
 * @param a
 * @return the sine of the a
 */
double Math::sin(double a) {
    return math_sin(a);
}

/**
 * Returns the hyperbolic sine of a double value.
 *
 * @param a
 * @return the hyperbolic sine of a
 */
double Math::sinh(double a) {
    return math_sinh(a);
}

/**
 * Returns the correctly rounded positive square root of a double value
 *
 * @param a
 * @return double
 */
double Math::sqrt(double a) {
	return math_sqrt(a);
}

/**
 * Returns the trigonometric tangent of an angle
 *
 * @param a
 * @return the tangent of the a
 */
double Math::tan(double a) {
    return math_tan(a);
}

/**
 * Returns the hyperbolic tangent of a double value.
 *
 * @param a
 * @return the hyperbolic tangent of a
 */
double Math::tanh(double a) {
    return math_tanh(a);
}

/**
 * Converts an angle measured in radians to an approximately equivalent angle measured in degrees.
 *
 * @param angleRadian
 * @return double
 */
double Math::toDegrees(double angleRadian) {
    return angleRadian * 180.0 / PI;
}

/**
 * Converts an angle measured in degrees to an approximately equivalent angle measured in radians.
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
 * @return float
 */
float Math::ulp(float a) {
    return 0;
}

/**
 * Returns the size of an ulp of the argument.
 *
 * @param a
 * @return double
 */
double Math::ulp(double a) {
    return 0;
}



















