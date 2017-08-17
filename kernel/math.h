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

#ifndef NATIVE_MATH_H
#define NATIVE_MATH_H

#include <stdio.h>
#include <math.h>

double math_pow(double base, double exponent);
double math_floor(double value);
double math_round(double value);
double math_sqrt(double value);
double math_cbrt(double value);
double math_ceil(double value);
double math_exp(double value);
double math_expm1(double value);
double math_hypot(double valueA, double valueB);
double math_log(double value);
double math_log10(double value);
double math_log1p(double value);
double math_ieeeremainder(double dividend, double divisor);
double math_rint(double value);
double math_acos(double value);
double math_cos(double angle);
double math_cosh(double angle);
double math_sin(double angle);
double math_asin(double value);
double math_sinh(double angle);
double math_atan(double angle);
double math_atan2(double coordinateX, double coordinateY);
double math_tan(double angle);
double math_tanh(double angle);
double math_copysign(double magnitude, double sign);
float math_copysignf(float magnitude, float sign);
double math_nexttoward(double start, double direction);
float math_nexttowardf(float start, double direction);
double math_ldexp(double value, int scaleFactor);
float math_ldexpf(float value, int scaleFactor);


#endif
