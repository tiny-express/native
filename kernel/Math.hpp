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

double mathPow(double base, double exponent);
double mathFloor(double value);
double mathRound(double value);
double mathSqrt(double value);
double mathCbrt(double value);
double mathCeil(double value);
double mathExp(double value);
double mathExpm1(double value);
double mathHypot(double valueA, double valueB);
double mathLog(double value);
double mathLog10(double value);
double mathLog1p(double value);
double mathIeeeRemainder(double dividend, double divisor);
double mathRint(double value);
double mathAcos(double value);
double mathCos(double angle);
double mathCosh(double angle);
double mathSin(double angle);
double mathAsin(double value);
double mathSinh(double angle);
double mathAtan(double angle);
double mathAtan2(double coordinateX, double coordinateY);
double mathTan(double angle);
double mathTanh(double angle);
double mathCopySign(double magnitude, double sign);
float mathCopySignF(float magnitude, float sign);
double mathNextToward(double start, double direction);
float mathNextTowardF(float start, double direction);
double mathLdexp(double value, int scaleFactor);
float mathLdexpf(float value, int scaleFactor);


#endif
