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

extern "C" {
#include "../../../kernel/test.h"
}

#include "Math.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST(JavaLang, MathAbs) {
	double double_value = -123;
	ASSERT_DBL_NEAR(123, Math::abs(double_value));

	float float_value = -123.123f;
	ASSERT_DBL_NEAR(123.123, Math::abs(float_value));

	int int_value = -123;
	ASSERT_EQUAL(123, Math::abs(int_value));

	long long_value = -1233453453;
	ASSERT_EQUAL(1233453453, Math::abs(long_value));
}

TEST(JavaLang, MathAddExactInt) {
    // Given 2 int
    int a = 1;
    int b = 2;
    int expectResult = 3;
    ASSERT_EQUAL(expectResult, Math::addExact(a, b));

    // Given an int equal to Integer::MAX_VALUE, 
    // test if addExact throw ArithmeticException("integer overflow")
    int c = Integer::MAX_VALUE;
    try {
        int overFlowResult = Math::addExact(c, b);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathAddExactLong) {
    // Given 2 long
    long a = 1;
    long b = 2;
    long expectResult = 3;
    ASSERT_EQUAL(expectResult, Math::addExact(a, b));

    // Given an int equal to Long::MAX_VALUE, 
    // test if addExact throw ArithmeticException("long overflow")
    long c = Long::MAX_VALUE;
    try {
        long overFlowResult = Math::addExact(c, b);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathCos) {
    // Given an angle equal to PI/ 2
    double angle = Math::PI / 2;
    double expectResult = 0;
    ASSERT_DBL_NEAR(expectResult, Math::cos(angle));

    // Given an angle equal to NAN
    double nanAngle = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::cos(nanAngle));

    // Given an angle equal to INFINITE
    double infAngle = INFINITY;
    double expectINFResult = NAN;
    ASSERT_DBL_NEAR(expectINFResult, Math::cos(infAngle));
}

TEST(JavaLang, MathAcos) {
    // Given a cosine equal to 0
    double cos = 0;
    double expectResult = Math::PI/2;
    ASSERT_DBL_NEAR(expectResult, Math::acos(cos));

    // Given a cosine equal to NAN
    double nanCos = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::acos(nanCos));

    // Given a cosine > 1
    double biggerThanOneCos = 2;
    double expectBiggerThanOneResult = NAN;
    ASSERT_DBL_NEAR(expectBiggerThanOneResult, Math::acos(biggerThanOneCos));
}

TEST(JavaLang, MathSin) {
    // Given an angle equal to PI/ 2
    double angle = Math::PI / 2;
    double expectResult = 1;
    ASSERT_DBL_NEAR(expectResult, Math::sin(angle));

    // Given an angle equal to NAN
    double nanAngle = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::sin(nanAngle));

    // Given an angle equal to -0.0
    double negativeZeroAngle = -0.0;
    double expectNegativeZeroAngleResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroAngleResult, Math::sin(negativeZeroAngle));

    // Given an angle equal to 0.0
    double positiveZeroAngle = 0.0;
    double expectPositiveZeroAngleResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroAngleResult, Math::sin(positiveZeroAngle));
}

TEST(JavaLang, MathAsin) {
    // Given a sine equal to 1
    double sin = 1;
    double expectResult = Math::PI/2;
    ASSERT_DBL_NEAR(expectResult, Math::asin(sin));

    // Given a sine equal to NAN
    double nanSin = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::asin(nanSin));

    // Given a cosine > 1
    double biggerThanOneSin = 2;
    double expectBiggerThanOneResult = NAN;
    ASSERT_DBL_NEAR(expectBiggerThanOneResult, Math::asin(biggerThanOneSin));

    // Given a sine value equal to -0.0
    double negativeZeroSin = -0.0;
    double expectNegativeZeroAngleResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroAngleResult, Math::asin(negativeZeroSin));

    // Given a sine value equal to 0.0
    double positiveZeroSin = 0.0;
    double expectPositiveZeroAngleResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroAngleResult, Math::sin(positiveZeroSin));
}

TEST(JavaLang, MathTan) {
    // Given an angle equal to PI/ 4
    double angle = Math::PI / 4;
    double expectResult = 1;
    ASSERT_DBL_NEAR(expectResult, Math::tan(angle));

    // Given an angle equal to NAN
    double nanAngle = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, tan(nanAngle));

    // Given an angle equal to -0.0
    double negativeZeroAngle = -0.0;
    double expectNegativeZeroAngleResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroAngleResult, Math::tan(negativeZeroAngle));

    // Given an angle equal to 0.0
    double positiveZeroAngle = 0.0;
    double expectPositiveZeroAngleResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroAngleResult, Math::tan(positiveZeroAngle));
}

TEST(JavaLang, MathAtan) {
    // Given a tangen equal to 1
    double tan = 1;
    double expectResult = Math::PI/4;
    ASSERT_DBL_NEAR(expectResult, Math::atan(tan));

    // Given a sine equal to NAN
    double nanTan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::atan(nanTan));

    // Given a sine value equal to -0.0
    double negativeZeroSin = -0.0;
    double expectNegativeZeroAngleResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroAngleResult, Math::atan(negativeZeroSin));

    // Given a sine value equal to 0.0
    double positiveZeroSin = 0.0;
    double expectPositiveZeroAngleResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroAngleResult, Math::atan(positiveZeroSin));
}

TEST(JavaLang, MathAtan2) {
    // Given 2 double for codinate x and cordinate y
    double cordinateX = Math::PI / 2;
    double cordinateY = Math::PI / 3;
    double expectResult = 0.9827937232473292;
    double actualResult = Math::atan2(cordinateX, cordinateY);
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Expect result
    double expectNANResult = NAN;
    double expectPositiveZeroResult = +0.0;
    double expectNegativeZeroResult = -0.0;
    double expectPositivePiResult = Math::PI;
    double expectNegativePiResult = -Math::PI;
    double expectPositiveHalfPiResult = Math::PI/2;
    double expectNegativeHalfPiResult = -Math::PI/2;
    double expectPositiveQuarterPiResult = Math::PI/4;
    double expectNegativeQuarterPiResult = -Math::PI/4;
    double expectPositiveThreeFourthsPiResult = 3 * Math::PI/4;
    double expectNegativeThreeFourthsPiResult = -3 * Math::PI/4;


    // Given 2 NaN for codinate x and cordinate y
    double nanCordinateX = NAN;
    double nanCordinateY = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::atan2(nanCordinateX, nanCordinateY));

    // Given positive zero codinate x and positive cordinate y
    double positiveZeroCordinateX = +0.0;
    double positiveCordinateY = 1;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::atan2(positiveZeroCordinateX, positiveCordinateY));

    // Given positive finite codinate x and positive infinite cordinate y
    double positiveFiniteCordinateX = 100;
    double positiveInfiniteCordinateY = +INFINITY;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::atan2(positiveFiniteCordinateX, positiveInfiniteCordinateY));

    // Given negative zero codinate x and positive cordinate y
    double negativeZeroCordinateX = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::atan2(negativeZeroCordinateX, positiveCordinateY));

    // Given negative finite codinate x and positive infinite y
    double negativeFiniteCordinateX = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::atan2(negativeFiniteCordinateX, positiveInfiniteCordinateY));

    // Given positive zero codinate x and negative cordinate y
    double negativeCordinateY = -1;
    ASSERT_DBL_NEAR(expectPositivePiResult, Math::atan2(positiveZeroCordinateX, negativeCordinateY));

    // Given positive finite codinate x and negative infinite cordinate y
    double negativeInfiniteCordinateY = -INFINITY;
    ASSERT_DBL_NEAR(expectPositivePiResult, Math::atan2(positiveFiniteCordinateX, negativeInfiniteCordinateY));

    // Given negative zero codinate x and negative cordinate y
    ASSERT_DBL_NEAR(expectNegativePiResult, Math::atan2(negativeZeroCordinateX, negativeCordinateY));

    // Given negative finite codinate x and negative infinite cordinate y
    ASSERT_DBL_NEAR(expectNegativePiResult, Math::atan2(negativeFiniteCordinateX, negativeInfiniteCordinateY));

    // Given positive codinate x and positive zero cordinate y
    double positiveCordinateX = 1;
    double positiveZeroCordinateY = +0.0;
    ASSERT_DBL_NEAR(expectPositiveHalfPiResult, Math::atan2(positiveCordinateX, positiveZeroCordinateY));

    // Given positive codinate x and negative zero cordinate y
    double negativeZeroCordinateY = -0.0;
    ASSERT_DBL_NEAR(expectPositiveHalfPiResult, Math::atan2(positiveCordinateX, negativeZeroCordinateY));

    // Given positive infinite cordinate x and finite cordinate y
    double positiveInfiniteCordinateX = +INFINITY;
    double finiteCordinateY = 100;
    ASSERT_DBL_NEAR(expectPositiveHalfPiResult, Math::atan2(positiveInfiniteCordinateX, finiteCordinateY));

    // Given negative codinate x and positive zero cordinate y
    double negativeCordinateX = -1;
    ASSERT_DBL_NEAR(expectNegativeHalfPiResult, Math::atan2(negativeCordinateX, positiveZeroCordinateY));

    // Given negative codinate x and negative zero cordinate y
    ASSERT_DBL_NEAR(expectNegativeHalfPiResult, Math::atan2(negativeCordinateX, negativeZeroCordinateY));

    // Given positive infinite cordinate x and finite cordinate y
    double negativeInfiniteCordinateX = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeHalfPiResult, Math::atan2(negativeInfiniteCordinateX, finiteCordinateY));

    // Given positive infinite cordinate x and positive infinite cordinate y
    ASSERT_DBL_NEAR(expectPositiveQuarterPiResult, Math::atan2(positiveInfiniteCordinateX, positiveInfiniteCordinateY));

    // Given negative infinite cordinate x and positive infinite cordinate y
    ASSERT_DBL_NEAR(expectNegativeQuarterPiResult, Math::atan2(negativeInfiniteCordinateX, positiveInfiniteCordinateY));

    // Given positive infinite cordinate x and negative infinite cordinate y
    ASSERT_DBL_NEAR(expectPositiveThreeFourthsPiResult, Math::atan2(positiveInfiniteCordinateX, negativeInfiniteCordinateY));

    // Given negative infinite cordinate x and negative infinite cordinate y
    ASSERT_DBL_NEAR(expectNegativeThreeFourthsPiResult, Math::atan2(negativeInfiniteCordinateX, negativeInfiniteCordinateY));
}

TEST(JavaLang, MathCbrt) {
    // Given a variable equal to 3 ^ 3 = 27
    double cube = 27;
    double expectResult = 3;
    ASSERT_DBL_NEAR(expectResult, Math::cbrt(cube));

    // Given a value equal to NAN
    double nanCube = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::cbrt(nanCube));

    // Given a value equal to INFINITE
    double positiveInfCube = INFINITY;
    double expectPositiveInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::cbrt(positiveInfCube));

    // Given a value equal to -INFINITE
    double negativeInfCube = -INFINITY;
    double expectNegativeInfResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfResult, Math::cbrt(negativeInfCube));

    // Given a value equal to ZERO
    double positiveZeroCube = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::cbrt(positiveZeroCube));

    // Given a value equal to -ZERO
    double negativeZeroCube = -0.0;
    double expectNegativeZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::cbrt(negativeZeroCube));
}

TEST(JavaLang, MathSqrt) {
    // Given a variable equal to 3 ^ 2 = 9
    double square = 9;
    double expectResult = 3;
    ASSERT_DBL_NEAR(expectResult, Math::sqrt(square));

    // Given a value equal to NAN
    double nanSquare = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::sqrt(nanSquare));

    // Given a value equal to INFINITE
    double positiveInfSquare = INFINITY;
    double expectPositiveInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::sqrt(positiveInfSquare));

    // Given a value equal to -INFINITE
    double negativeInfSquare = -INFINITY;
    double expectNegativeInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfResult, Math::sqrt(negativeInfSquare));

    // Given a value equal to ZERO
    double positiveZeroSquare = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::sqrt(positiveZeroSquare));

    // Given a value equal to -ZERO
    double negativeZeroSquare = -0.0;
    double expectNegativeZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::sqrt(negativeZeroSquare));
}

TEST(JavaLang, MathCeil) {
    // Given a double to
    double x = 125.9;
    double expectResult = 126;
    ASSERT_DBL_NEAR(expectResult, Math::ceil(x));

    // Given a double value equal to a mathematical integer
    double equalInt = 100;
    double expectEqualIntResult = 100;
    ASSERT_DBL_NEAR(expectEqualIntResult, Math::ceil(equalInt));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::ceil(nan));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::ceil(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::ceil(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::ceil(negativeZero));

    // Given a value > -1 and < 0
    double between = -0.4;
    double expectBetweenResult = -0.0;
    ASSERT_DBL_NEAR(expectBetweenResult, Math::ceil(between));
}

TEST(JavaLang, MathDecrementExactInt) {
    // Given 2 int
    int a = 5;
    int expectResult = 4;
    ASSERT_EQUAL(expectResult, Math::decrementExact(a));

    // Given an int equal to Integer::MIN_VALUE, 
    // test if decrementExact throw ArithmeticException("integer overflow")
    int c = Integer::MIN_VALUE;
    try {
        int overFlowResult = Math::decrementExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathDecrementExactLong) {
    // Given 2 int
    long a = 5;
    long expectResult = 4;
    ASSERT_EQUAL(expectResult, Math::decrementExact(a));

    // Given an int equal to Long::MIN_VALUE, test if decrementExact throw ArithmeticException("long overflow")
    long c = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::decrementExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathIncrementExactInt) {
    // Given 2 int
    int a = 5;
    int expectResult = 6;
    ASSERT_EQUAL(expectResult, Math::incrementExact(a));

    // Given an int equal to Integer::MAX_VALUE, 
    // test if incrementExact throw ArithmeticException("integer overflow")
    int c = Integer::MAX_VALUE;
    try {
        int overFlowResult = Math::incrementExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathIncrementExactLong) {
    // Given 2 int
    long a = 5;
    long expectResult = 6;
    ASSERT_EQUAL(expectResult, Math::incrementExact(a));

    // Given an int equal to Long::MAX_VALUE, 
    // test if incrementExact throw ArithmeticException("long overflow")
    long c = Long::MAX_VALUE;
    try {
        long overFlowResult = Math::incrementExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathMultiplyExact) {
    // Given 2 int which multiply result overflow an integer
    // test if multiplyExact throw ArithmeticException("integer overflow")
    int x = Integer::MAX_VALUE;
    int y = 2;
    try {
        int overFlowResult = Math::multiplyExact(x, y);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }


    // Given 2 int
    int a = 10;
    int b = 20;
    int expectResult = 200;
    ASSERT_EQUAL(expectResult, Math::multiplyExact(a, b));
}

TEST(JavaLang, MathMultiplyExactLong) {
    // Given 2 int
    long a = 5;
    long b = 6;
    long expectResult = 30;
    ASSERT_EQUAL(expectResult, Math::multiplyExact(a, b));

    // Given an int equal to Long::MAX_VALUE, 
    // test if multiplyExact throw ArithmeticException("long overflow")
    long c = Long::MAX_VALUE;
    try {
        long overFlowResult = Math::multiplyExact(c, 2L);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }

    // Given an int equal to Long::MIN_VALUE, multiply with -1
    // test if multiplyExact throw ArithmeticException("long overflow")
    long d = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::multiplyExact(d, -1L);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathNegateExactInt) {
    // Given an int
    int x = 100;
    int expectResult = -100;
    ASSERT_EQUAL(expectResult, Math::negateExact(x));

    // Given an int equal to Integer::MIN_VALUE, 
    // test if negateExact throw ArithmeticException("integer overflow")
    int c = Integer::MIN_VALUE;
    try {
        int overFlowResult = Math::negateExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathNegateExactLong) {
    // Given an int
    long x = 100;
    long expectResult = -100;
    ASSERT_EQUAL(expectResult, Math::negateExact(x));

    // Given an int equal to Long::MIN_VALUE, 
    // test if negateExact throw ArithmeticException("long overflow")
    long c = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::negateExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathLog) {
    // Given a variable equal to E
    double natural = Math::E;
    double expectNaturalResult = 1;
    ASSERT_DBL_NEAR(expectNaturalResult, Math::log(natural));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::log(nan));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::log(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = -INFINITY;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::log(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::log(negativeZero));

    // Given a value > 0
    double lessThanZero = - 1;
    double expectLessThanZeroResult = NAN;
    ASSERT_DBL_NEAR(expectLessThanZeroResult, Math::log(lessThanZero));
}

TEST(JavaLang, MathNextAfterDouble) {
    // Given 2 double
    double start = 98759.765;
    double direction = 154.28764;
    double expectResult = 98759.76499999998;
    ASSERT_DBL_NEAR(expectResult, Math::nextAfter(start, direction));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::nextAfter(nan, direction));

    // Given a value equal to INFINITE
    double inf = -INFINITY;
    double expectInfResult = -Double::MAX_VALUE;
    ASSERT_DBL_NEAR(expectInfResult, Math::nextAfter(inf, direction));

    // Given a start value equal to -Double::MIN_VALUE
    double startMinValue = -Double::MIN_VALUE;
    double expectMinValueResult = -0.0;
    ASSERT_DBL_NEAR(expectMinValueResult, Math::nextAfter(startMinValue, -1));

    // Given a start value equal to Double::MAX_VALUE
    double startMaxValue = Double::MAX_VALUE;
    double expectMaxValueResult = INFINITY;
    ASSERT_EQUAL(expectMaxValueResult, Math::nextAfter(startMaxValue, 1));

    // Given 2 value equal to two sign ZERO
    double positiveZero = 0.0;
    double negativeZero = -0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::nextAfter(negativeZero, positiveZero));

    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::nextAfter(positiveZero, negativeZero));
}

TEST(JavaLang, MathNextAfterFloat) {
    // Given 2 double
    float start = 98759.765f;
    double direction = 154.28764;
    double expectResult = 98759.76499999998;
    ASSERT_EQUAL(expectResult, Math::nextAfter(start, direction));

    // Given a value equal to NAN
    float nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::nextAfter(nan, direction));

    // Given a value equal to INFINITE
    double inf = -INFINITY;
    double expectInfResult = -Float::MAX_VALUE;
    ASSERT_EQUAL(expectInfResult, Math::nextAfter(inf, direction));

    // Given a start value equal to -Float::MIN_VALUE
    float startMinValue = -Float::MIN_VALUE;
    double expectMinValueResult = -0.0;
    ASSERT_DBL_NEAR(expectMinValueResult, Math::nextAfter(startMinValue, -1));

    // Given a start value equal to Float::MAX_VALUE
    float startMaxValue = Float::MAX_VALUE;
    double expectMaxValueResult = INFINITY;
    ASSERT_EQUAL(expectMaxValueResult, Math::nextAfter(startMaxValue, 1));

    // Given 2 value equal to two sign ZERO
    float positiveZero = 0.0f;
    float negativeZero = -0.0f;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::nextAfter(negativeZero, positiveZero));

    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::nextAfter(positiveZero, negativeZero));
}

TEST(JavaLang, MathScalbFloat) {
    // Given a float an a scale factor
    float a = 50.14;
    int scaleFactor = 4;
    float expectResult = 802.24;
    ASSERT_DBL_NEAR(expectResult, Math::scalb(a, scaleFactor));

    // Given a value equal to NAN
    float nan = NAN;
    float expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::scalb(nan, scaleFactor));

    // Given a value equal to INFINITE
    float positiveInf = INFINITY;
    float expectPositiveInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::scalb(positiveInf, scaleFactor));

    // Given a value equal to -INFINITE
    float negativeInf = -INFINITY;
    float expectNegativeInfResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfResult, Math::scalb(negativeInf, scaleFactor));

    // Given a value equal to ZERO
    float positiveZero = 0.0;
    float expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::scalb(positiveZero, scaleFactor));

    // Given a value equal to -ZERO
    float negativeZero = -0.0f;
    float expectNegativeZeroResult = -0.0f;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::scalb(negativeZero, scaleFactor));
}

TEST(JavaLang, MathScalbDouble) {
    // Given a float an a scale factor
    double a = 50.14;
    int scaleFactor = 4;
    double expectResult = 802.24;
    ASSERT_DBL_NEAR(expectResult, Math::scalb(a, scaleFactor));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::scalb(nan, scaleFactor));

    // Given a value equal to INFINITE
    double positiveInf = INFINITY;
    double expectPositiveInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::scalb(positiveInf, scaleFactor));

    // Given a value equal to -INFINITE
    double negativeInf = -INFINITY;
    double expectNegativeInfResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfResult, Math::scalb(negativeInf, scaleFactor));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::scalb(positiveZero, scaleFactor));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::scalb(negativeZero, scaleFactor));
}

TEST(JavaLang, MathLog10) {
    // Given a variable equal to 10
    double tenBase = 10;
    double expectTenBaseResult = 1;
    ASSERT_DBL_NEAR(expectTenBaseResult, Math::log10(tenBase));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::log10(nan));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::log10(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = -INFINITY;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::log10(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::log10(negativeZero));

    // Given a value > 0
    double lessThanZero = -1;
    double expectlessThanZeroResult = NAN;
    ASSERT_DBL_NEAR(expectlessThanZeroResult, Math::log10(lessThanZero));
}

TEST(JavaLang, MathLog1p) {
    // Given a variable equal to E-1
    double natural = Math::E - 1;
    double expectnaturalResult = 1;
    ASSERT_DBL_NEAR(expectnaturalResult, Math::log1p(natural));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::log1p(nan));

    // Given a value equal to -1;
    double negativeOne = -1;
    double expectNegativeOneResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeOneResult, Math::log1p(negativeOne));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::log1p(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::log1p(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::log1p(negativeZero));

    // Given a value > -1
    double lessThanZero = - 2;
    double expectlessThanZeroResult = NAN;
    ASSERT_DBL_NEAR(expectlessThanZeroResult, Math::log1p(lessThanZero));
}

TEST(JavaLang, MathRInt) {
	// Given a double number
	double x = 125.9;
    double expectXResult = 126;
    ASSERT_DBL_NEAR(expectXResult, Math::rint(x));

    // Given a double number
    double y = 0.4873;
    double expectYResult = 0;
	ASSERT_DBL_NEAR(expectYResult, Math::rint(y));

    // Given a double value equal to a mathematical integer
    double equalInt = 100;
    double expectEqualIntResult = 100;
    ASSERT_DBL_NEAR(expectEqualIntResult, Math::rint(equalInt));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::rint(nan));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::rint(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::rint(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::rint(negativeZero));
}

TEST(JavaLang, MathExp) {
	// Given a variable equal to E^3
	double eCubed = 3;
    double expectResult = Math::pow(Math::E, 3);
	ASSERT_DBL_NEAR(expectResult, Math::exp(eCubed));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::exp(nan));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::exp(inf));

    // Given a value equal to INFINITY
    double positiveInf = -INFINITY;
    double expectPositiveInfResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::exp(positiveInf));
}

TEST(JavaLang, MathExpm1) {
    // Given a variable equal to E^3
    double eCubed = 3;
    double expectResult = Math::pow(Math::E, 3) - 1;
    ASSERT_DBL_NEAR(expectResult, Math::expm1(eCubed));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::expm1(nan));

    // Given a value equal to INFINITY
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::expm1(inf));

    // Given a value equal to INFINITY
    double positiveInf = -INFINITY;
    double expectPositiveInfResult = -1.0;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::expm1(positiveInf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::expm1(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::expm1(negativeZero));
}

TEST(JavaLang, MathHypot) {
	// Given two double numbers
	double x = 6;
	double y = 8;
    double expectResult = 10;
	ASSERT_DBL_NEAR(expectResult, Math::hypot(x, y));

    // Given two double with one number equal INFINITY
    double z = 6;
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::hypot(z, inf));

    // Given two double with one number equal INFINITY
    double a = 6;
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::hypot(a, nan));

    // Given two double with one number equal INFINITY
    double inf1 = INFINITY;
    double inf2 = INFINITY;
    double expectBothInfResult = NAN;
    ASSERT_DBL_NEAR(expectBothInfResult, Math::hypot(inf1, inf2));
}

TEST(JavaLang, MathIEEERemainder) {
	// Given two double numbers
	double x = 8;
	double y = 6;
	double expectResult = 2;
    ASSERT_DBL_NEAR(expectResult, Math::IEEEremainder(x, y));

    // Given two double with First number equal INFINITY
    double z = 6;
    double inf = INFINITY;
    double expectFirstInfResult = NAN;
    ASSERT_DBL_NEAR(expectFirstInfResult, Math::IEEEremainder(inf, z));

    // Given two double with one number equal NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::IEEEremainder(z, nan));

    // Given two double with the second number is 0.0
    double positiveZero = 0.0;
    double expectPositiveZeroResult = NAN;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::IEEEremainder(z, positiveZero));

    // Given two double with the second number is -0.0
    double negativeZero = 0.0;
    double expectNegativeZeroResult = NAN;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::IEEEremainder(z, negativeZero));

    // Given two double with one number equal INFINITY
    double expectSecondInfResult = NAN;
    ASSERT_DBL_NEAR(expectSecondInfResult, Math::IEEEremainder(z, inf));
}

TEST(JavaLang, MathCosh) {
	// Given a variable equal PI/2
	double radian = Math::PI/2;
    double expectResult = 2.5091784786580567;
	ASSERT_DBL_NEAR(expectResult, Math::cosh(radian));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::cosh(nan));

    // Given a value equal to INFINITY
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::cosh(inf));

    // Given a value equal to ZERO
    double zero = 0.0;
    double expectZeroResult = 1.0;
    ASSERT_DBL_NEAR(expectZeroResult, Math::cosh(zero));
}

TEST(JavaLang, MathSinh) {
	// Given a variable equal PI/2
    double radian = Math::PI/2;
    double expectResult = 2.3012989023072947;
    ASSERT_DBL_NEAR(expectResult, Math::sinh(radian));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::sinh(nan));

    // Given a value equal to INFINITY
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::sinh(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::sinh(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::sinh(negativeZero));
}

TEST(JavaLang, MathTanh) {
    // Given a variable equal PI/2
    double radian = Math::PI/2;
    double expectResult = 0.9171523356672744;
    ASSERT_DBL_NEAR(expectResult, Math::tanh(radian));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::tanh(nan));

    // Given a value equal to INFINITY
    double positiveInf = INFINITY;
    double expectPositiveInfResult = 1.0;
    ASSERT_DBL_NEAR(expectPositiveInfResult, Math::tanh(positiveInf));

    // Given a value equal to -INFINITY
    double negtiveInf = -INFINITY;
    double expectNegtiveInfResult = -1.0;
    ASSERT_DBL_NEAR(expectNegtiveInfResult, Math::tanh(negtiveInf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::tanh(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::tanh(negativeZero));
}
TEST(JavaLang, MathToRadian) {
    // Given a variable degree which is equal to PI
    double degree = 180;
    double expectResult = Math::PI;
    ASSERT_DBL_NEAR(expectResult, Math::toRadians(degree));
}

TEST(JavaLang, MathToDegree) {
    // Given a variable degree which is equal to PI
    double radian = Math::PI;
    double expectResult = 180;
    ASSERT_DBL_NEAR(expectResult, Math::toDegrees(radian));
}

TEST(JavaLang, MathFloor) {
	double floor_value = 2.3;
    double expectResult = 2;
	ASSERT_DBL_NEAR(expectResult, Math::floor(floor_value));

    // Given a double value equal to a mathematical integer
    double equalInt = 100;
    double expectEqualIntResult = 100;
    ASSERT_DBL_NEAR(expectEqualIntResult, Math::floor(equalInt));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::floor(nan));

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    ASSERT_DBL_NEAR(expectInfResult, Math::floor(inf));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::floor(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::floor(negativeZero));
}

TEST(JavaLang, MathFloorDivInt) {
    // Given 2 int
    int dividend = 10;
    int divisor = 5;
    int expectResult = 2;
    ASSERT_EQUAL(expectResult, Math::floorDiv(dividend, divisor));

    // Given 2 int
    dividend = 11;
    divisor = -5;
    expectResult = -3;
    ASSERT_EQUAL(expectResult, Math::floorDiv(dividend, divisor));

    // Given 2 int
    dividend = 11;
    divisor = 0;
    try {
        int devideByZero = Math::floorDiv(dividend, divisor);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST(JavaLang, MathSignNumDouble) {
    // Given a double
    double a = 50.14;
    double expectResult = 1.0;
    ASSERT_DBL_NEAR(expectResult, Math::signum(a));

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::signum(nan));

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::signum(positiveZero));

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::signum(negativeZero));
}

TEST(JavaLang, MathSignNumFloat) {
    // Given a float
    float a = 50.14;
    float expectResult = 1.0;
    ASSERT_DBL_NEAR(expectResult, Math::signum(a));

    // Given a value equal to NAN
    float nan = NAN;
    float expectNaNResult = NAN;
    ASSERT_DBL_NEAR(expectNaNResult, Math::signum(nan));

    // Given a value equal to ZERO
    float positiveZero = 0.0;
    float expectPositiveZeroResult = 0.0;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::signum(positiveZero));

    // Given a value equal to -ZERO
    float negativeZero = -0.0f;
    float expectNegativeZeroResult = -0.0f;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::signum(negativeZero));
}

TEST(JavaLang, MathSubtractExactInt) {
    // Given 2 int
    int a = 10;
    int b = 20;
    int expectResult = -10;
    ASSERT_EQUAL(expectResult, Math::subtractExact(a, b));

    // Given an int equal to Integer::MIN_VALUE, 
    // test if subtractExact throw ArithmeticException("integer overflow")
    int c = Integer::MIN_VALUE;
    try {
        int overFlowResult = Math::subtractExact(c, b);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathSubtractExactLong) {
    // Given 2 long
    long a = 10;
    long b = 20;
    long expectResult = -10;
    ASSERT_EQUAL(expectResult, Math::subtractExact(a, b));

    // Given an int equal to Long::MIN_VALUE, 
    // test if subtractExact throw ArithmeticException("long overflow")
    long c = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::subtractExact(c, b);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathToIntExact) {
    // Given a long
    long a = 100;
    int expectResult = 100;
    ASSERT_EQUAL(expectResult, Math::toIntExact(a));

    // Given an int equal to Long::MAX_VALUE, 
    // test if toIntExact throw ArithmeticException("integer overflow")
    long c = Long::MAX_VALUE;
    try {
        int overFlowResult = Math::toIntExact(c);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST(JavaLang, MathFloorDivLong) {
    // Given 2 int
    long dividend = 10;
    long divisor = 5;
    long expectResult = 2;
    ASSERT_EQUAL(expectResult, Math::floorDiv(dividend, divisor));

    // Given 2 long
    dividend = 11;
    divisor = -5;
    expectResult = -3;
    ASSERT_EQUAL(expectResult, Math::floorDiv(dividend, divisor));

    // Given 2 long
    dividend = 11;
    divisor = 0;
    try {
        long devideByZero = Math::floorDiv(dividend, divisor);
    }
    catch (ArithmeticException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST(JavaLang, MathFloorModInt) {
    // Given 2 int
    int dividend = 10;
    int divisor = 5;
    int expectResult = 0;
    ASSERT_EQUAL(expectResult, Math::floorMod(dividend, divisor));

    // Given 2 int
    dividend = 11;
    divisor = -5;
    expectResult = -4;
    ASSERT_EQUAL(expectResult, Math::floorMod(dividend, divisor));
}

TEST(JavaLang, MathFloorModLong) {
    // Given 2 int
    long dividend = 10;
    long divisor = 5;
    long expectResult = 0;
    ASSERT_EQUAL(expectResult, Math::floorMod(dividend, divisor));

    // Given 2 long
    dividend = 11;
    divisor = -5;
    expectResult = -4;
    ASSERT_EQUAL(expectResult, Math::floorMod(dividend, divisor));
}

TEST(JavaLang, MathMax) {
	// return;
	double double_value_max_1 = 4;
	double double_value_max_2 = 2;
	ASSERT_DBL_NEAR(4, Math::max(double_value_max_1, double_value_max_2));

	float float_value_max_1 = 4.123;
	float float_value_max_2 = 2.312;
	ASSERT_DBL_NEAR(4.123, Math::max(float_value_max_1, float_value_max_2));

	int int_value_max_1 = 4;
	int int_value_max_2 = 2;
	ASSERT_EQUAL(4, Math::max(int_value_max_1, int_value_max_2));

	long long_value_max_1 = 4;
	long long_value_max_2 = 2;
	ASSERT_EQUAL(4, Math::max(long_value_max_1, long_value_max_2));
}

TEST(JavaLang, MathMin) {
	double double_value_min_1 = 4;
	double double_value_min_2 = 2;
	ASSERT_DBL_NEAR(2, Math::min(double_value_min_1, double_value_min_2));

	float float_value_min_1 = 4.123;
	float float_value_min_2 = 2.312;
	ASSERT_DBL_NEAR(2.312, Math::min(float_value_min_1, float_value_min_2));

    long long_value_min_1 = 4;
    long long_value_min_2 = 2;
    ASSERT_EQUAL(2, Math::min(long_value_min_1, long_value_min_2));

	int int_value_min_1 = 4;
	int int_value_min_2 = 2;
	ASSERT_EQUAL(2, Math::min(int_value_min_1, int_value_min_2));
}

TEST(JavaLang, MathPow) {
	double base = 3;
	double power = 3;
	ASSERT_DBL_NEAR(27, Math::pow(base, power));
}

TEST(JavaLang, MathRound) {
	double double_value_round = 1.23643435;
	ASSERT_EQUAL(1, Math::round(double_value_round));

	float float_value_round = 1.23643435f;
	ASSERT_DBL_NEAR(1, Math::round(float_value_round));
}

TEST(JavaLang, MathRandom) {
    // Test 100 number generated, check if all number are in range [0, 1)
    for (int index = 0; index < 100; index++) {
        double generatedNumber = Math::random();
        ASSERT_TRUE(generatedNumber >=  0 && generatedNumber < 1);
    }
}

TEST(JavaLang, MathGetExponentDouble) {
    // Given a double to get exponent
    double doubleNumber = 60984.1;
    int expectResult = 15;
    ASSERT_EQUAL(expectResult, Math::getExponent(doubleNumber));

    // Given a NAN to get exponent
    double nan = NAN;
    int expectNANResult = Double::MAX_EXPONENT + 1;
    ASSERT_EQUAL(expectNANResult, Math::getExponent(nan));

    // Given an Infinity to get exponent
    double infinity = INFINITY;
    int expectInfiniteResult = Double::MAX_EXPONENT + 1;
    ASSERT_EQUAL(expectInfiniteResult, Math::getExponent(infinity));

    // Given a zero to get exponent
    double zero = 0.0;
    int expectZeroResult = Double::MIN_EXPONENT - 1;
    ASSERT_EQUAL(expectZeroResult, Math::getExponent(zero));

   /* // Given a subnormal to get exponent
    double subNormal = 3.952525e-323;
    int expectSubNormalResult = Double::MIN_EXPONENT - 1;
    ASSERT_EQUAL(expectSubNormalResult, Math::getExponent(subNormal));*/
}

TEST(JavaLang, MathGetExponentFloat) {
   /* // Given a float to get exponent
    float floatNumber = 60984.1f;
    int expectResult = 15;
    ASSERT_EQUAL(expectResult, Math::getExponent(floatNumber));

    // Given a NAN to get exponent
    float nan = NAN;
    int expectNANResult = Float::MAX_EXPONENT + 1;
    ASSERT_EQUAL(expectNANResult, Math::getExponent(nan));

    // Given an Infinity to get exponent
    float infinity = INFINITY;
    int expectInfiniteResult = Float::MAX_EXPONENT + 1;
    ASSERT_EQUAL(expectInfiniteResult, Math::getExponent(infinity));

    // Given a zero to get exponent
    float zero = 0.0;
    int expectZeroResult = Float::MIN_EXPONENT - 1;
    ASSERT_EQUAL(expectZeroResult, Math::getExponent(zero));

    *//* // Given a subnormal to get exponent
     float subNormal = 3.952525e-323;
     int expectSubNormalResult = Double::MIN_EXPONENT - 1;
     ASSERT_EQUAL(expectSubNormalResult, Math::getExponent(subNormal));*/
}

TEST(JavaLang, MathNextDownDouble) {
    // Given a double
    double doubleNumber = 98759.765;
    double expectResult = 98759.76;
    ASSERT_EQUAL(expectResult, Math::nextDown(doubleNumber));

    // Given a NAN
    double nan = NAN;
    double expectNANResult = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::nextDown(nan));

    // Given a negative Infinity
    double negativeInfinite = -INFINITY;
    double expectNegativeInfiniteResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfiniteResult, Math::nextDown(negativeInfinite));

    // Given a zero
    double zero = 0.0;
    double expectZeroResult = -Double::MIN_VALUE;
    ASSERT_DBL_NEAR(expectZeroResult, Math::nextDown(zero));
}

TEST(JavaLang, MathNextDownFloat) {
/*    // Given a float
    float floatNumber = 98759.765;
    float expectResult = 98759.76;
    ASSERT_DBL_NEAR(expectResult, Math::nextDown(floatNumber));

    // Given a NAN
    float nan = NAN;
    float expectNANResult = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::nextDown(nan));

    // Given a negative Infinity
    float negativeInfinite = -INFINITY;
    float expectNegativeInfiniteResult = -INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfiniteResult, Math::nextDown(negativeInfinite));

    // Given a zero
    float zero = 0.0;
    float expectZeroResult = -Float::MIN_VALUE;
    ASSERT_DBL_NEAR(expectZeroResult, Math::nextDown(zero));*/
}

TEST(JavaLang, MathNextUpDouble) {
    // Given a double
    double doubleNumber = 98759.765;
    double expectResult = 98759.76500000001;
    ASSERT_EQUAL(expectResult, Math::nextUp(doubleNumber));

    // Given a NAN
    double nan = NAN;
    double expectNANResult = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::nextDown(nan));

    // Given a positive Infinity
    double positiveInfinite = INFINITY;
    double expectPositiveInfiniteResult = INFINITY;
    ASSERT_EQUAL(expectPositiveInfiniteResult, Math::nextDown(positiveInfinite));

    // Given a zero
    double zero = 0.0;
    double expectZeroResult = Double::MIN_VALUE;
    ASSERT_DBL_NEAR(expectZeroResult, Math::nextDown(zero));
}

TEST(JavaLang, MathNextUpFloat) {
 /*   // Given a float
    float floatNumber = 98759.765;
    float expectResult = 98759.76500000001;
    ASSERT_DBL_NEAR(expectResult,  Math::nextUp(floatNumber));

    // Given a NAN
    float nan = NAN;
    float expectNANResult = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::nextDown(nan));

    // Given a positive Infinity
    float positiveInfinite = INFINITY;
    float expectNegativeInfiniteResult = INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfiniteResult, Math::nextDown(positiveInfinite));

    // Given a zero
    float zero = 0.0;
    float expectZeroResult = Float::MIN_VALUE;
    ASSERT_DBL_NEAR(expectZeroResult, Math::nextDown(zero));*/
}

TEST(JavaLang, MathUlpDouble) {
    // Given a double
    double doubleNumber = 956.294;
    double expectResult = 1.1368683772161603E-13;
    ASSERT_DBL_NEAR(expectResult, Math::ulp(doubleNumber));

    // Given a NAN
    double nan = NAN;
    double expectNANResult = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::nextDown(nan));

    // Given a positive Infinity
    double positiveInfinite = +INFINITY;
    double expectPositiveInfiniteResult = +INFINITY;
    ASSERT_DBL_NEAR(expectPositiveInfiniteResult, Math::ulp(positiveInfinite));

    // Given a negative Infinity
    double negativeInfinite = -INFINITY;
    double expectNegativeInfiniteResult = +INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfiniteResult, Math::ulp(positiveInfinite));

    // Given a positive zero
    double positiveZero = +0.0;
    double expectPositiveZeroResult = Double::MIN_VALUE;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::nextDown(positiveZero));

    // Given a negative zero
    double negativeZero = -0.0;
    double expectNegativeZeroResult = Double::MIN_VALUE;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::ulp(negativeZero));

    // Given a Double::MAX_VALUE
    double positiveDoubleMaxValue = Double::MAX_VALUE;
    double expectPositiveDoubleMaxValueResult = Math::pow(2, 971);
    ASSERT_DBL_NEAR(expectPositiveDoubleMaxValueResult, Math::ulp(positiveDoubleMaxValue));

    // Given a -Double::MAX_VALUE
    double negativeDoubleMaxValue = Double::MAX_VALUE;
    double expectNegativeDoubleMaxValueResult = Math::pow(2, 971);
    ASSERT_DBL_NEAR(expectNegativeDoubleMaxValueResult, Math::ulp(negativeDoubleMaxValue));
}

TEST(JavaLang, MathUlpFloat) {
/*    // Given a float
    float floatNumber = 956.294f;
    float expectResult = 1.1368683772161603E-13;
    ASSERT_DBL_NEAR(expectResult, Math::ulp(floatNumber));

    // Given a NAN
    float nan = NAN;
    float expectNANResult = NAN;
    ASSERT_DBL_NEAR(expectNANResult, Math::nextDown(nan));

    // Given a positive Infinity
    float positiveInfinite = +INFINITY;
    float expectPositiveInfiniteResult = +INFINITY;
    ASSERT_DBL_NEAR(expectPositiveInfiniteResult, Math::ulp(positiveInfinite));

    // Given a negative Infinity
    float negativeInfinite = -INFINITY;
    float expectNegativeInfiniteResult = +INFINITY;
    ASSERT_DBL_NEAR(expectNegativeInfiniteResult, Math::ulp(positiveInfinite));

    // Given a positive zero
    float positiveZero = +0.0;
    float expectPositiveZeroResult = Float::MIN_VALUE;
    ASSERT_DBL_NEAR(expectPositiveZeroResult, Math::nextDown(positiveZero));

    // Given a negative zero
    float negativeZero = -0.0;
    float expectNegativeZeroResult = Float::MIN_VALUE;
    ASSERT_DBL_NEAR(expectNegativeZeroResult, Math::ulp(negativeZero));

    // Given a Float::MAX_VALUE
    float floatMaxValue = Float::MAX_VALUE;
    float expectFloatMaxValueResult = (float) Math::pow(2, 104);
    ASSERT_DBL_NEAR(expectFloatMaxValueResult, Math::ulp(floatMaxValue));

    // Given a -Float::MAX_VALUE
    float negativeFloatMaxValue = Float::MAX_VALUE;
    float expectNegativeFloatMaxValueResult = Math::pow(2, 971);
    ASSERT_DBL_NEAR(expectNegativeFloatMaxValueResult, Math::ulp(negativeFloatMaxValue));*/
}
