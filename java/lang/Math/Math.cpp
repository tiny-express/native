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

using namespace Java::Lang;

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
    return math_atan2(corX,corY);
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
 * Returns the unbiased exponent used in the representation of a double
 *
 * @param a
 * @return int
 */
//TODO need sun.misc.FpUtils
int Math::getExponent(double a) {
    return 0;
}

/**
 * Returns the unbiased exponent used in the representation of a float
 *
 * @param a
 * @return int
 */
//TODO need sun.misc.FpUtils
int Math::getExponent(float a) {
    return 0;
}

/**
 * Returns sqrt(x2 +y2) without intermediate overflow or underflow.
 *
 * @param a
 * @param b
 * @return
 */
double Math::hypot(double a, double b) {
    return math_hypot(a,b);
}

/**
 * Computes the remainder operation on two arguments as prescribed by the IEEE 754 standard.
 *
 * @param dividend
 * @param divisor
 * @return the remainder when dividend is divided by divisor.
 */
double Math::IEEEremainder(double dividend, double divisor) {
    return math_remainder(dividend,divisor);
}

/**
 * initialize the randomNumberGenerator
 */
//TODO need Random
void Math::initRGN() {

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

//TODO need sun.misc.FpUtils
double Math::nextAfter(double start, double direction) {
    return 0;
}

//TODO need sun.misc.FpUtils
float Math::nextAfter(float start, double direction) {
    return 0;
}

//TODO need sun.misc.FpUtils
float Math::nextUp(float a) {
    return 0;
}

//TODO need sun.misc.FpUtils
double Math::nextUp(double a) {
    return 0;
}

double Math::pow(double base, double exponent) {
    return math_pow(base, exponent);
}

double Math::random() {
	srand(time(NULL));
	return rand();
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

//TODO need sun.misc.FpUtils
float Math::scalb(float a, int scaleFactor) {
    return 0;
}

//TODO need sun.misc.FpUtils
double Math::scalb(double a, int scaleFactor) {
    return 0;
}

//TODO need sun.misc.FpUtils
double Math::signum(double a) {
    return 0;
}

//TODO need sun.misc.FpUtils
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

double Math::toDegrees(double angleRadian) {
    return angleRadian * 180.0 / PI;
}

double Math::toRadians(double angleDegree) {
    return angleDegree / 180.0 * PI;
}

//TODO need sun.misc.FpUtils
float Math::ulp(float a) {
    return 0;
}

//TODO need sun.misc.FpUtils
double Math::ulp(double a) {
    return 0;
}












