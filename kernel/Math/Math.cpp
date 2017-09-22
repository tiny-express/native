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

#include "../Math.hpp"

double mathPow(double base, double exponent) {
	return pow(base, exponent);
}

double mathFloor(double value) {
	return floor(value);
}

double mathRound(double value) {
	return round(value);
}

double mathSqrt(double value) {
	return sqrt(value);
}

double mathCbrt(double value) {
	return cbrt(value);
}

double mathCeil(double value) {
	return ceil(value);
}

double mathExp(double value) {
	return exp(value);
}

double mathExpm1(double value) {
	return expm1(value);
}

double mathLog(double value) {
	return log(value);
}

double mathLog10(double value) {
	return log10(value);
}

double mathLog1p(double value) {
	return log1p(value);
}

double mathIeeeRemainder(double dividend, double divisor) {
	return dividend - ( round(dividend / divisor) * divisor );
}

double mathRint(double value) {
	return rint(value);
}

double mathHypot(double valueA, double valueB) {
	return hypot(valueA, valueB);
}

double mathAcos(double value) {
	return acos(value);
}

double mathCos(double angle) {
	return cos(angle);
}

double mathCosh(double angle) {
	return cosh(angle);
}

double mathAsin(double value) {
	return asin(value);
}

double mathSin(double angle) {
	return sin(angle);
}

double mathSinh(double angle) {
	return sinh(angle);
}

double mathAtan(double value) {
	return atan(value);
}

double mathAtan2(double coordinateX, double coordinateY) {
	return atan2(coordinateX, coordinateY);
}

double mathTan(double angle) {
	return tan(angle);
}

double mathTanh(double angle) {
	return tanh(angle);
}

double mathCopySign(double magnitude, double sign) {
	return copysign(magnitude, sign);
}

float mathCopySignF(float magnitude, float sign) {
	return copysignf(magnitude, sign);
}

double mathNextToward(double start, double direction) {
	return nexttoward(start, direction);
}

float mathNextTowardF(float start, double direction) {
	return nexttowardf(start, direction);
}

double mathLdexp(double value, int scaleFactor) {
	return ldexp(value, scaleFactor);
}

float mathLdexpf(float value, int scaleFactor) {
	return ldexpf(value, scaleFactor);
}

