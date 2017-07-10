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

#ifndef NATIVE_MATH_H
#define NATIVE_MATH_H

#include <stdio.h>
#include <math.h>

double math_pow(double base, double exponent);
double math_floor(double a);
double math_round(double a);
double math_sqrt(double a);
double math_cbrt(double a);
double math_ceil(double a);
double math_exp(double a);
double math_expm1(double a);
double math_hypot(double a, double b);
double math_log(double a);
double math_log10(double a);
double math_log1p(double a);
double math_ieeeremainder(double a, double b);
double math_rint(double a);
double math_acos(double a);
double math_cos(double a);
double math_cosh(double a);
double math_sin(double a);
double math_asin(double a);
double math_sinh(double a);
double math_atan(double a);
double math_atan2(double a, double b);
double math_tan(double a);
double math_tanh(double a);
double math_copysign(double a, double b);
float math_copysignf(float a, float b);
double math_nexttoward(double a, double b);
float math_nexttowardf(float a, double b);
double math_ldexp(double a, int exp);
float math_ldexpf(float a, int exp);




#endif
