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
#include "../Double/Double.hpp"
#include "../Float/Float.hpp"
#include "cmath"

namespace Java {
	namespace Lang {
		class Math final : public virtual Object {

        private:
			Math(){}
			static void initRGN();
		public:
            // e number
			static constexpr double E = 2.7182818284590452354;
            // pi number
			static constexpr double PI = 3.14159265358979323846;

            static long negativeZeroFloatBits;

            static long negativeZeroDoubleBits;


		public:
			static int abs(int a);

			static float abs(float a);

			static long abs(long a);

			static double abs(double a);

			static double acos(double a);

			static double asin(double a);

			static double atan(double a);

			static double atan2(double corX, double corY);

			static long addExact(long a, long b);

			static int addExact(int a, int b);

			static double cbrt(double a);

			static double ceil(double a);

			static double copySign(double magnitude, double sign);

			static float copySign(float magnitude, float sign);

			static double cos(double a);

			static double cosh(double a);

			static long decrementExact(long a);

			static int decrementExact(int a);

			static double exp(double a);

			static double expm1(double a);

			static double floor(double a);

			static int floorDiv(int a, int b);

			static long floorDiv(long a, long b);

			static int floorMod(int a, int b);

			static long floorMod(long a, long b);

			static int getExponent(double a);

			static int getExponent(float a);

			static double hypot(double a, double b);

			static double IEEEremainder(double devidend, double devisor);

			static int incrementExact(int a);

			static long incrementExact(long a);

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

            static int multiplyExact(int a, int b);

            static long multiplyExact(long a, long b);

            static int negateExact(int a);

            static long negateExact(long a);

			static double nextAfter(double start, double direction);

			static float nextAfter(float start, double direction);

            static double nextDown(double a);

            static float nextDown(float a);

			static float nextUp(float a);

			static double nextUp(double a);

			static double pow(double base, double exponent);

            static double powerOfTwoD(int n);

            static float powerOfTwoF(int n);

			static double random();

			static double rint(double a);

			static int round(float a);

			static long round(double a);

			static float scalb(float a, int scaleFactor);

			static double scalb(double a, int scaleFactor);

			static double signum(double a);

			static float signum(float a);

			static double sin(double a);

			static double sinh(double a);

			static double sqrt(double a);

            static long subtractExact(long a, long b);

            static int subtractExact(int a, int b);

			static double tan(double a);

			static double tanh(double a);

			static double toDegrees(double angleRadian);

            static int toIntExact(long a);

			static double toRadians(double angleDegree);

			static float ulp(float a);

			static double ulp(double a);



		};

        class RandomNumberGeneratorHolder {
            static RandomNumberGeneratorHolder *instance;

        public:
            RandomNumberGeneratorHolder(){
                //randomNumberGenerator.Random();
            };

            //Random randomNumberGenerator;

            static RandomNumberGeneratorHolder *getInstance()
            {
                if (!instance)
                    instance = new RandomNumberGeneratorHolder();
                return instance;
            }
        };
	}
}

#endif//NATIVE_JAVA_LANG_MATH_HPP