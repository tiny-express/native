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

#include <ieee754.h>
#include "../math.h"

double math_pow(double a, double b) {
	return pow(a, b);
}

double math_floor(double a) {
	return floor(a);
}

double math_round(double a) {
	return round(a);
}

double math_sqrt(double a) {
    return sqrt(a);
}

double math_cbrt(double a) {
    return cbrt(a);
}

double math_ceil(double a){
    return ceil(a);
}

double math_exp(double a){
    return exp(a);
}

double math_expm1(double a){
    return expm1(a);
}

double math_log(double a){
    return log(a);
}

double math_log10(double a){
    return log10(a);
}

double math_log1p(double a){
    return log1p(a);
}

double math_remainder(double a, double b){
    return remainder(a,b);
}

double math_rint(double a){
    return rint(a);
}

double math_hypot(double a, double b){
    return hypot(a,b);
}

double math_acos(double a){
    return acos(a);
}

double math_cos(double a){
    return cos(a);
}

double math_cosh(double a){
    return cosh(a);
}

double math_asin(double a){
    return asin(a);
}

double math_sin(double a){
    return sin(a);
}

double math_sinh(double a){
    return sinh(a);
}

double math_atan(double a){
    return atan(a);
}

double math_atan2(double a, double b){
    return atan2(a,b);
}

double math_tan(double a){
    return tan(a);
}
double math_tanh(double a){
    return tanh(a);
}

