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

using namespace Java::Lang;

double Math::abs(double a) {
	return a >= 0 ? a : -a;
}

float Math::abs(float a) {
	return a >= 0 ? a : -a;
}

int Math::abs(int a) {
	return a >= 0 ? a : -a;
}

long Math::abs(long a) {
	return a >= 0 ? a : -a;
}

double Math::floor(double a) {
	return math_floor(a);
}

double Math::max(double a, double b) {
	return a > b ? a : b;
}

float Math::max(float a, float b) {
	return a > b ? a : b;
}

int Math::max(int a, int b) {
	return a > b ? a : b;
}

long Math::max(long a, long b) {
	return a > b ? a : b;
}

double Math::min(double a, double b) {
	return a < b ? a : b;
}

float Math::min(float a, float b) {
	return a < b ? a : b;
}

int Math::min(int a, int b) {
	return a < b ? a : b;
}

double Math::pow(double a, double b) {
	return math_pow(a, b);
}

double Math::random() {
	srand(time(NULL));
	return rand();
}

long Math::round(double a) {
	return math_round(a);
}

int Math::round(float a) {
	return math_round(a);
}

double Math::sqrt(double a) {
	return sqrt(a);
}