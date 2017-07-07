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

// https://docs.oracle.com/javase/8/docs/api/java/lang/Math.html

#ifndef NATIVE_JAVA_LANG_MATH_HPP
#define NATIVE_JAVA_LANG_MATH_HPP

#include "../Object/Object.hpp"

namespace Java {
	namespace Lang {
		class Math final : public virtual Object {
		private:
			//static Random randomNumberGenerator;
			static long negativeZeroDoubleBits;
			static long negativeZeroFloatBits;
		private:
			Math(){}
			static void initRGN();
		public:
			static constexpr double E = 2.7182818284590452354;
			static constexpr double PI = 3.14159265358979323846;
		public:
			static int abs(int a);
			static float abs(float a);
			static long abs(long a);
			static double abs(double a);
			static double acos(double a);
			static double asin(double a);
			static double atan(double a);
			static double atan2(double a, double b);
			static double cbrt(double a);
			static double ceil(double a);
			static double copySign(double a, double b);
			static float copySign(float a, float b);
			static double cos(double a);
			static double cosh(double a);
			static double exp(double a);
			static double expm1(double a);
			static double floor(double a);
			static int getExponent(double a);
			static int getExponent(float a);
			static double hypot(double a, double b);
			static double IEEEremainder(double a, double b);
			static double log(double a);
			static double log10(double a);
			static double log1p(double a);
			static int max(int a, int b);
			static float max(float a, float b);
			static long max(long a, long b);
			static double max(double a, double b);
			static int min(int a, int b);
			static float min(float a, float b);
			static long min(long a, long b);
			static double min(double a, double b);
			static double nextAfter(double a, double b);
			static float nextAfter(float a, double b);
			static float nextUp(float a);
			static double nextUp(double a);
			static double pow(double a, double b);
			static double random();
			static double rint(double a);
			static int round(float a);
			static long round(double a);
			static float scalb(float a, int b);
			static double scalb(double a, int b);
			static double signum(double a);
			static float signum(float a);
			static double sin(double a);
			static double sinh(double a);
			static double sqrt(double a);
			static double tan(double a);
			static double tanh(double a);
			static double toDegrees(double a);
			static double toRadians(double a);
			static float ulp(float a);
			static double ulp(double a);
		};
	}
}

#endif//NATIVE_JAVA_LANG_MATH_HPP