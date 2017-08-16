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

#include "../math.h"

double math_pow(double base, double exponent) {
	return pow(base, exponent);
}

double math_floor(double value) {
	return floor(value);
}

double math_round(double value) {
	return round(value);
}

double math_sqrt(double value) {
	return sqrt(value);
}

double math_cbrt(double value) {
	return cbrt(value);
}

double math_ceil(double value) {
	return ceil(value);
}

double math_exp(double value) {
	return exp(value);
}

double math_expm1(double value) {
	return expm1(value);
}

double math_log(double value) {
	return log(value);
}

double math_log10(double value) {
	return log10(value);
}

double math_log1p(double value) {
	return log1p(value);
}

double math_ieeeremainder(double dividend, double divisor) {
	return dividend - ( round(dividend / divisor) * divisor );
}

double math_rint(double value) {
	return rint(value);
}

double math_hypot(double valueA, double valueB) {
	return hypot(valueA, valueB);
}

double math_acos(double value) {
	return acos(value);
}

double math_cos(double angle) {
	return cos(angle);
}

double math_cosh(double angle) {
	return cosh(angle);
}

double math_asin(double value) {
	return asin(value);
}

double math_sin(double angle) {
	return sin(angle);
}

double math_sinh(double angle) {
	return sinh(angle);
}

double math_atan(double value) {
	return atan(value);
}

double math_atan2(double coordinateX, double coordinateY) {
	return atan2(coordinateX, coordinateY);
}

double math_tan(double angle) {
	return tan(angle);
}

double math_tanh(double angle) {
	return tanh(angle);
}

double math_copysign(double magnitude, double sign) {
	return copysign(magnitude, sign);
}

float math_copysignf(float magnitude, float sign) {
	return copysignf(magnitude, sign);
}

double math_nexttoward(double start, double direction) {
	return nexttoward(start, direction);
}

float math_nexttowardf(float start, double direction) {
	return nexttowardf(start, direction);
}

double math_ldexp(double value, int scaleFactor) {
	return ldexp(value, scaleFactor);
}

float math_ldexpf(float value, int scaleFactor) {
	return ldexpf(value, scaleFactor);
}

