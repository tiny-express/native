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
#include "../Integer/Integer.hpp"
#include "../Long/Long.hpp"
#include "../Exception/Exception.hpp"

using namespace Java::Lang;

TEST (JavaLang, MathAbs) {
	double double_value = -123;
	ASSERT_EQUAL(123, Math::abs(double_value));

	float float_value = -123.123;
	ASSERT_EQUAL(123.123, Math::abs(float_value));

	int int_value = -123;
	ASSERT_EQUAL(123, Math::abs(int_value));

	long long_value = -1233453453;
	ASSERT_EQUAL(1233453453, Math::abs(long_value));
}

TEST (JavaLang, MathAddExactInt){
    // Given 2 int
    int a = 1;
    int b = 2;
    int expectResult = 3;
    int actualResult = Math::addExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);
    
    // Given an int equal to Integer::MAX_VALUE,
    // test if addExact throw ArithmeticException("integer overflow")
    int c = Integer::MAX_VALUE;
    try {
        int overFlowResult = Math::addExact(c, b);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathAddExactLong){
    // Given 2 long
    long a = 1;
    long b = 2;
    long expectResult = 3;
    long actualResult = Math::addExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MAX_VALUE,
    // test if addExact throw ArithmeticException("long overflow")
    long c = Long::MAX_VALUE;
    try {
        long overFlowResult = Math::addExact(c, b);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathCos){
    // Given an angle equal to PI/ 2
    double angle = Math::PI / 2;
    double actualResult = Math::cos(angle);
    double expectResult = 0;
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given an angle equal to NAN
    double nanAngle = NAN;
    double actualNaNResult = Math::cos(nanAngle);
    double expectNaNResult = NAN;
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given an angle equal to INFINITE
    double infAngle = INFINITY;
    double actualINFResult = Math::cos(infAngle);
    double expectINFResult = NAN;
    ASSERT_EQUAL(expectINFResult, actualINFResult);
}

TEST (JavaLang, MathAcos){
    // Given a cosine equal to 0
    double cos = 0;
    double actualResult = Math::acos(cos);
    double expectResult = Math::PI/2;
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given a cosine equal to NAN
    double nanCos = NAN;
    double actualNaNResult = Math::acos(nanCos);
    double expectNaNResult = NAN;
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a cosine > 1
    double biggerThanOneCos = 2;
    double actualBiggerThanOneResult = Math::acos(biggerThanOneCos);
    double expectBiggerThanOneResult = NAN;
    ASSERT_EQUAL(expectBiggerThanOneResult, actualBiggerThanOneResult);
}

TEST (JavaLang, MathSin){
    // Given an angle equal to PI/ 2
    double angle = Math::PI / 2;
    double actualResult = Math::sin(angle);
    double expectResult = 1;
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given an angle equal to NAN
    double nanAngle = NAN;
    double actualNaNResult = Math::sin(nanAngle);
    double expectNaNResult = NAN;
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given an angle equal to -0.0
    double negativeZeroAngle = -0.0;
    double actualnegativeZeroAngleResult = Math::sin(negativeZeroAngle);
    double expectnegativeZeroAngleResult = -0.0;
    ASSERT_EQUAL(expectnegativeZeroAngleResult, actualnegativeZeroAngleResult);

    // Given an angle equal to 0.0
    double positiveZeroAngle = 0.0;
    double actualpositiveZeroAngleResult = Math::sin(negativeZeroAngle);
    double expectpositiveZeroAngleResult = 0.0;
    ASSERT_EQUAL(expectpositiveZeroAngleResult, actualpositiveZeroAngleResult);
}

TEST (JavaLang, MathAsin){
    // Given a sine equal to 1
    double sin = 1;
    double actualResult = Math::asin(sin);
    double expectResult = Math::PI/2;
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given a sine equal to NAN
    double nanSin = NAN;
    double actualNaNResult = Math::asin(nanSin);
    double expectNaNResult = NAN;
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a cosine > 1
    double biggerThanOneSin = 2;
    double actualBiggerThanOneResult = Math::asin(biggerThanOneSin);
    double expectBiggerThanOneResult = NAN;
    ASSERT_EQUAL(expectBiggerThanOneResult, actualBiggerThanOneResult);

    // Given a sine value equal to -0.0
    double negativeZeroSin = -0.0;
    double actualnegativeZeroAngleResult = Math::asin(negativeZeroSin);
    double expectnegativeZeroAngleResult = -0.0;
    ASSERT_EQUAL(expectnegativeZeroAngleResult, actualnegativeZeroAngleResult);

    // Given a sine value equal to 0.0
    double positiveZeroSin = 0.0;
    double actualpositiveZeroAngleResult = Math::sin(negativeZeroSin);
    double expectpositiveZeroAngleResult = 0.0;
    ASSERT_EQUAL(expectpositiveZeroAngleResult, actualpositiveZeroAngleResult);
}

TEST (JavaLang, MathTan){
    // Given an angle equal to PI/ 4
    double angle = Math::PI / 4;
    double actualResult = Math::tan(angle);
    double expectResult = 1;
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given an angle equal to NAN
    double nanAngle = NAN;
    double actualNaNResult = Math::tan(nanAngle);
    double expectNaNResult = NAN;
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given an angle equal to -0.0
    double negativeZeroAngle = -0.0;
    double actualnegativeZeroAngleResult = Math::tan(negativeZeroAngle);
    double expectnegativeZeroAngleResult = -0.0;
    ASSERT_EQUAL(expectnegativeZeroAngleResult, actualnegativeZeroAngleResult);

    // Given an angle equal to 0.0
    double positiveZeroAngle = 0.0;
    double actualpositiveZeroAngleResult = Math::tan(negativeZeroAngle);
    double expectpositiveZeroAngleResult = 0.0;
    ASSERT_EQUAL(expectpositiveZeroAngleResult, actualpositiveZeroAngleResult);
}

TEST (JavaLang, MathAtan){
    // Given a tangen equal to 1
    double tan = 1;
    double actualResult = Math::atan(tan);
    double expectResult = Math::PI/4;
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given a sine equal to NAN
    double nanTan = NAN;
    double actualNaNResult = Math::atan(nanTan);
    double expectNaNResult = NAN;
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a sine value equal to -0.0
    double negativeZeroSin = -0.0;
    double actualnegativeZeroAngleResult = Math::atan(negativeZeroSin);
    double expectnegativeZeroAngleResult = -0.0;
    ASSERT_EQUAL(expectnegativeZeroAngleResult, actualnegativeZeroAngleResult);

    // Given a sine value equal to 0.0
    double positiveZeroSin = 0.0;
    double actualpositiveZeroAngleResult = Math::atan(negativeZeroSin);
    double expectpositiveZeroAngleResult = 0.0;
    ASSERT_EQUAL(expectpositiveZeroAngleResult, actualpositiveZeroAngleResult);
}

TEST (JavaLang, MathAtan2){

}

TEST (JavaLang, MathCbrt){
    // Given a variable equal to 3^3 =27
    double cube = 27;
    double expectResult = 3;
    double actualResult = Math::cbrt(cube);
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given a value equal to NAN
    double nanCube = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::cbrt(nanCube);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double positiveInfCube = INFINITY;
    double expectPositiveInfResult = INFINITY;
    double actualPositiveInfResult = Math::cbrt(positiveInfCube);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);

    // Given a value equal to -INFINITE
    double negativeInfCube = -INFINITY;
    double expectNegativeInfResult = INFINITY;
    double actualNegativeInfResult = Math::cbrt(negativeInfCube);
    ASSERT_EQUAL(expectNegativeInfResult, actualNegativeInfResult);

    // Given a value equal to ZERO
    double positiveZeroCube = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::cbrt(positiveZeroCube);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZeroCube = -0.0;
    double expectNegativeZeroResult = 0.0;
    double actualNegativeZeroResult = Math::cbrt(negativeZeroCube);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathSqrt){
    // Given a variable equal to 3^2 = 9
    double square = 9;
    double expectResult = 3;
    double actualResult = Math::sqrt(square);
    ASSERT_DBL_NEAR(expectResult, actualResult);

    // Given a value equal to NAN
    double nanSquare = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::sqrt(nanSquare);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double positiveInfSquare = INFINITY;
    double expectPositiveInfResult = INFINITY;
    double actualPositiveInfResult = Math::sqrt(positiveInfSquare);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);

    // Given a value equal to -INFINITE
    double negativeInfSquare = -INFINITY;
    double expectNegativeInfResult = INFINITY;
    double actualNegativeInfResult = Math::sqrt(negativeInfSquare);
    ASSERT_EQUAL(expectNegativeInfResult, actualNegativeInfResult);

    // Given a value equal to ZERO
    double positiveZeroSquare = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::sqrt(positiveZeroSquare);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZeroSquare = -0.0;
    double expectNegativeZeroResult = 0.0;
    double actualNegativeZeroResult = Math::sqrt(negativeZeroSquare);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathCeil){
    // Given a double to
    double x = 125.9;
    double expectResult = 126;
    double actualResult = Math::ceil(x);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a double value equal to a mathematical integer
    double equalInt = 100;
    double expectEqualIntResult = 100;
    double actualEqualIntResult = Math::ceil(equalInt);
    ASSERT_EQUAL(expectEqualIntResult, actualEqualIntResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::ceil(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::ceil(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::ceil(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::ceil(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);

    // Given a value > -1 and < 0
    double between = -0.4;
    double expectBetweenResult = -0.0;
    double actualBetweenResult = Math::ceil(between);
    ASSERT_EQUAL(expectBetweenResult, actualBetweenResult);
}

TEST (JavaLang, MathDecrementExactInt){
    // Given 2 int
    int a = 5;
    int expectResult = 4;
    int actualResult = Math::decrementExact(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Integer::MIN_VALUE,
    // test if decrementExact throw ArithmeticException("integer overflow")
    int c = Integer::MIN_VALUE;
    try {
        int overFlowResult = Math::decrementExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathDecrementExactLong){
    // Given 2 int
    long a = 5;
    long expectResult = 4;
    long actualResult = Math::decrementExact(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MIN_VALUE, test if decrementExact throw ArithmeticException("long overflow")
    long c = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::decrementExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathIncrementExactInt){
    // Given 2 int
    int a = 5;
    int expectResult = 6;
    int actualResult = Math::incrementExact(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Integer::MAX_VALUE,
    // test if incrementExact throw ArithmeticException("integer overflow")
    int c = Integer::MAX_VALUE;
    try {
        int overFlowResult = Math::incrementExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathIncrementExactLong){
    // Given 2 int
    long a = 5;
    long expectResult = 6;
    long actualResult = Math::incrementExact(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MAX_VALUE,
    // test if incrementExact throw ArithmeticException("long overflow")
    long c = Long::MAX_VALUE;
    try {
        long overFlowResult = Math::incrementExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathMultiplyExact){
    // Given 2 int which multiply result overflow an integer
    // test if multiplyExact throw ArithmeticException("integer overflow")
    int x = Integer::MAX_VALUE;
    int y = 2;
    try {
        int overFlowResult = Math::multiplyExact(x, y);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }


    // Given 2 int
    int a = 10;
    int b = 20;
    int expectResult = 200;
    int actualResult = Math::multiplyExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST (JavaLang, MathMultiplyExactLong){
    // Given 2 int
    long a = 5;
    long b = 6;
    long expectResult = 30;
    long actualResult = Math::multiplyExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MAX_VALUE,
    // test if multiplyExact throw ArithmeticException("long overflow")
    long c = Long::MAX_VALUE;
    try {
        long overFlowResult = Math::multiplyExact(c, 2L);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }

    // Given an int equal to Long::MIN_VALUE, multiply with -1
    // test if multiplyExact throw ArithmeticException("long overflow")
    long d = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::multiplyExact(d, -1L);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }

}

TEST (JavaLang, MathNegateExactInt){
    // Given an int
    int x = 100;
    int expectResult = -100;
    int actualResult = Math::negateExact(x);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Integer::MIN_VALUE,
    // test if negateExact throw ArithmeticException("integer overflow")
    int c = Integer::MIN_VALUE;
    try {
        int overFlowResult = Math::negateExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathNegateExactLong){
    // Given an int
    long x = 100;
    long expectResult = -100;
    long actualResult = Math::negateExact(x);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MIN_VALUE,
    // test if negateExact throw ArithmeticException("long overflow")
    long c = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::negateExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathLog){
    // Given a variable equal to E
    double natural = Math::E;
    double expectNaturalResult = 1;
    double actualNaturalResult = Math::log(natural);
    ASSERT_EQUAL(expectNaturalResult, expectNaturalResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::log(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::log(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = INFINITY;
    double actualPositiveZeroResult = Math::log(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult =INFINITY;
    double actualNegativeZeroResult = Math::log(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);

    // Given a value > 0
    double lessThanZero = - 1;
    double expectlessThanZeroResult = NAN;
    double actuallessThanZeroResult = Math::log(lessThanZero);
    ASSERT_EQUAL(expectlessThanZeroResult, actuallessThanZeroResult);
}

TEST (JavaLang, MathNextAfterDouble){
    // Given 2 double
    double start = 98759.765;
    double direction = 154.28764;
    double expectResult = 98759.76499999998;
    double actualResult = Math::nextAfter(start, direction);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::nextAfter(nan, direction);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = -INFINITY;
    double expectInfResult = -Double::MAX_VALUE;
    double actualInfResult = Math::nextAfter(inf, direction);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a start value equal to -Double::MIN_VALUE
    double startMinValue = -Double::MIN_VALUE;
    double expectMinValueResult = -0.0;
    double actualMinValueResult = Math::nextAfter(startMinValue, -1);
    ASSERT_EQUAL(expectMinValueResult, actualMinValueResult);

    // Given a start value equal to Double::MAX_VALUE
    double startMaxValue = Double::MAX_VALUE;
    double expectMaxValueResult = INFINITY;
    double actualMaxValueResult = Math::nextAfter(startMaxValue, 1);
    ASSERT_EQUAL(expectMaxValueResult, actualMaxValueResult);

    // Given 2 value equal to two sign ZERO
    double positiveZero = 0.0;
    double negativeZero = -0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::nextAfter(negativeZero, positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::nextAfter(positiveZero, negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathNextAfterFloat){
    // Given 2 double
    float start = 98759.765;
    double direction = 154.28764;
    double expectResult = 98759.76499999998;
    double actualResult = Math::nextAfter(start, direction);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    float nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::nextAfter(nan, direction);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = -INFINITY;
    double expectInfResult = -Float::MAX_VALUE;
    double actualInfResult = Math::nextAfter(inf, direction);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a start value equal to -Float::MIN_VALUE
    float startMinValue = -Float::MIN_VALUE;
    double expectMinValueResult = -0.0;
    double actualMinValueResult = Math::nextAfter(startMinValue, -1);
    ASSERT_EQUAL(expectMinValueResult, actualMinValueResult);

    // Given a start value equal to Float::MAX_VALUE
    float startMaxValue = Float::MAX_VALUE;
    double expectMaxValueResult = INFINITY;
    double actualMaxValueResult = Math::nextAfter(startMaxValue, 1);
    ASSERT_EQUAL(expectMaxValueResult, actualMaxValueResult);

    // Given 2 value equal to two sign ZERO
    float positiveZero = 0.0;
    float negativeZero = -0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::nextAfter(negativeZero, positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::nextAfter(positiveZero, negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathScalbFloat){
    // Given a float an a scalefator
    float a = 50.14;
    int scaleFactor = 4;
    float expectResult = 802.24;
    float actualResult = Math::scalb(a, scaleFactor);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    float nan = NAN;
    float expectNaNResult = NAN;
    float actualNaNResult = Math::scalb(nan, scaleFactor);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    float positiveInf = INFINITY;
    float expectPositiveInfResult = INFINITY;
    float actualPositiveInfResult = Math::scalb(positiveInf, scaleFactor);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);

    // Given a value equal to -INFINITE
    float negativeInf = -INFINITY;
    float expectNegativeInfResult = -INFINITY;
    float actualNegativeInfResult = Math::scalb(negativeInf, scaleFactor);
    ASSERT_EQUAL(expectNegativeInfResult, actualNegativeInfResult);

    // Given a value equal to ZERO
    float positiveZero = 0.0;
    float expectPositiveZeroResult = 0.0;
    float actualPositiveZeroResult = Math::scalb(positiveZero, scaleFactor);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    float negativeZero = -0.0;
    float expectNegativeZeroResult = -0.0;
    float actualNegativeZeroResult = Math::scalb(negativeZero, scaleFactor);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathScalbDouble){
    // Given a float an a scalefator
    double a = 50.14;
    int scaleFactor = 4;
    double expectResult = 802.24;
    double actualResult = Math::scalb(a, scaleFactor);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::scalb(nan, scaleFactor);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double positiveInf = INFINITY;
    double expectPositiveInfResult = INFINITY;
    double actualPositiveInfResult = Math::scalb(positiveInf, scaleFactor);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);

    // Given a value equal to -INFINITE
    double negativeInf = -INFINITY;
    double expectNegativeInfResult = -INFINITY;
    double actualNegativeInfResult = Math::scalb(negativeInf, scaleFactor);
    ASSERT_EQUAL(expectNegativeInfResult, actualNegativeInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::scalb(positiveZero, scaleFactor);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::scalb(negativeZero, scaleFactor);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathLog10){
    // Given a variable equal to 10
    double tenBase = 10;
    double expectTenBaseResult = 1;
    double actualTenBaseResult = Math::log10(tenBase);
    ASSERT_EQUAL(expectTenBaseResult, actualTenBaseResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::log10(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::log10(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = INFINITY;
    double actualPositiveZeroResult = Math::log10(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = INFINITY;
    double actualNegativeZeroResult = Math::log10(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);

    // Given a value > 0
    double lessThanZero = - 1;
    double expectlessThanZeroResult = NAN;
    double actuallessThanZeroResult = Math::log10(lessThanZero);
    ASSERT_EQUAL(expectlessThanZeroResult, actuallessThanZeroResult);
}

TEST (JavaLang, MathLog1p){
    // Given a variable equal to E-1
    double natural = Math::E - 1;
    double expectnaturalResult = 1;
    double actualnaturalResult = Math::log1p(natural);
    ASSERT_EQUAL(expectnaturalResult, actualnaturalResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::log1p(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to -1;
    double negativeOne = -1;
    double expectnegativeOneResult = -INFINITY;
    double actualnegativeOneResult = Math::log1p(negativeOne);
    ASSERT_EQUAL(expectnegativeOneResult, actualnegativeOneResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::log1p(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::log1p(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::log1p(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);

    // Given a value > -1
    double lessThanZero = - 2;
    double expectlessThanZeroResult = NAN;
    double actuallessThanZeroResult = Math::log1p(lessThanZero);
    ASSERT_EQUAL(expectlessThanZeroResult, actuallessThanZeroResult);
}

TEST (JavaLang, MathRInt){
	// Given a double number
	double x = 125.9;
    double actualXResult = 126;
    double expectXResult = Math::rint(x);
    ASSERT_EQUAL(expectXResult, Math::rint(x));

    // Given a double number
    double y = 0.4873;
    double actualYResult = 0;
    double expectYResult = Math::rint(y);
	ASSERT_EQUAL(expectYResult, actualYResult);

    // Given a double value equal to a mathematical integer
    double equalInt = 100;
    double expectEqualIntResult = 100;
    double actualEqualIntResult = Math::rint(equalInt);
    ASSERT_EQUAL(expectEqualIntResult, actualEqualIntResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::rint(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::rint(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::rint(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::rint(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathExp){
	// Given a variable equal to E^3
	double eCubed = 3;
    double expectResult = Math::pow(Math::E, 3);
    double actualResult = Math::exp(eCubed);
	ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::exp(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::exp(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to INFINITY
    double positiveInf = -INFINITY;
    double expectPositiveInfResult = 0.0;
    double actualPositiveInfResult = Math::exp(positiveInf);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);
}

TEST (JavaLang, MathExpm1){
    // Given a variable equal to E^3
    double eCubed = 3;
    double expectResult = Math::pow(Math::E, 3) - 1;
    double actualResult = Math::expm1(eCubed);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::expm1(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITY
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::expm1(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to INFINITY
    double positiveInf = -INFINITY;
    double expectPositiveInfResult = -1.0;
    double actualPositiveInfResult = Math::expm1(positiveInf);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::expm1(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::expm1(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathHypot){
	// Given two double numbers
	double x = 6;
	double y = 8;
    double expectResult = 10;
    double actualResult = Math::hypot(x, y);
	ASSERT_EQUAL(expectResult, actualResult);

    // Given two double with one number equal INFINITY
    double z = 6;
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::hypot(z, inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given two double with one number equal INFINITY
    double a = 6;
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::hypot(a, nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given two double with one number equal INFINITY
    double inf1 = INFINITY;
    double inf2 = INFINITY;
    double expectBothInfResult = NAN;
    double actualBothInfResult = Math::hypot(inf1, inf2);
    ASSERT_EQUAL(expectBothInfResult, actualBothInfResult);
}

TEST (JavaLang, MathIEEERemainder){
	// Given two double numbers
	double x = 8;
	double y = 6;
	double expectResult = 2;
    double actualResult = Math::IEEEremainder(x, y);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given two double with First number equal INFINITY
    double z = 6;
    double inf = INFINITY;
    double expectFirstInfResult = NAN;
    double actualFirstInfResult = Math::IEEEremainder(inf, z);
    ASSERT_EQUAL(expectFirstInfResult, actualFirstInfResult);

    // Given two double with one number equal NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::IEEEremainder(z, nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given two double with the second number is 0.0
    double positiveZero = 0.0;
    double expectPositiveZeroResult = NAN;
    double actualPositiveZeroResult = Math::IEEEremainder(z, positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given two double with the second number is -0.0
    double negativeZero = 0.0;
    double expectNegativeZeroResult = NAN;
    double actualNegativeZeroResult = Math::IEEEremainder(z, negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);

    // Given two double with one number equal INFINITY
    double expectSecondInfResult = NAN;
    double actualSecondInfResult = Math::IEEEremainder(z, inf);
    ASSERT_EQUAL(expectSecondInfResult, actualSecondInfResult);
}

TEST (JavaLang, MathCosh){
	// Given a variable equal PI/2
	double radian = Math::PI/2;
    double expectResult = 2.5091784786580567;
    double actualResult = Math::cosh(radian);
	ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::cosh(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITY
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::cosh(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double zero = 0.0;
    double expectZeroResult = 1.0;
    double actualZeroResult = Math::cosh(zero);
    ASSERT_EQUAL(expectZeroResult, actualZeroResult);
}

TEST (JavaLang, MathSinh){
	// Given a variable equal PI/2
    double radian = Math::PI/2;
    double expectResult = 2.3012989023072947;
    double actualResult = Math::sinh(radian);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::sinh(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITY
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::sinh(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::sinh(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::sinh(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathTanh){

    // Given a variable equal PI/2
    double radian = Math::PI/2;
    double expectResult = 0.9171523356672744;
    double actualResult = Math::tanh(radian);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::tanh(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITY
    double positiveInf = INFINITY;
    double expectPositiveInfResult = 1.0;
    double actualPositiveInfResult = Math::tanh(positiveInf);
    ASSERT_EQUAL(expectPositiveInfResult, actualPositiveInfResult);

    // Given a value equal to -INFINITY
    double negtiveInf = -INFINITY;
    double expectNegtiveInfResult = -1.0;
    double actualNegtiveInfResult = Math::tanh(negtiveInf);
    ASSERT_EQUAL(expectNegtiveInfResult, actualNegtiveInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::tanh(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::tanh(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}
TEST (JavaLang, MathToRadian){
    // Given a variable degree which is equal to PI
    double degree = 180;
    double expectResult = Math::PI;
    double actualResult = Math::toRadians(degree);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST (JavaLang, MathToDegree){
    // Given a variable degree which is equal to PI
    double radian = Math::PI;
    double expectResult = 180;
    double actualResult = Math::toDegrees(radian);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST (JavaLang, MathFloor) {
	double floor_value = 2.3;
    double expectResult = 2;
    double actualResult = Math::floor(floor_value);
	ASSERT_EQUAL(expectResult, actualResult);

    // Given a double value equal to a mathematical integer
    double equalInt = 100;
    double expectEqualIntResult = 100;
    double actualEqualIntResult = Math::floor(equalInt);
    ASSERT_EQUAL(expectEqualIntResult, actualEqualIntResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::floor(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to INFINITE
    double inf = INFINITY;
    double expectInfResult = INFINITY;
    double actualInfResult = Math::floor(inf);
    ASSERT_EQUAL(expectInfResult, actualInfResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::floor(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::floor(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathFloorDivInt){
    // Given 2 int
    int dividend1 = 10;
    int divisor1 = 5;
    int expectResult1 = 2;
    int actualResult1 = Math::floorDiv(dividend1, divisor1);
    ASSERT_EQUAL(expectResult1, actualResult1);

    // Given 2 int
    int dividend2 = 11;
    int divisor2 = -5;
    int expectResult2 = -3;
    int actualResult2 = Math::floorDiv(dividend2, divisor2);
    ASSERT_EQUAL(expectResult2, actualResult2);

    // Given 2 int
    int dividend3 = 11;
    int divisor3 = 0;
    try {
        int devideByZero = Math::floorDiv(dividend3, divisor3);
    }
    catch (Exception e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, MathSignNumDouble){
    // Given a double
    double a = 50.14;
    double expectResult = 1.0;
    double actualResult = Math::signum(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    double nan = NAN;
    double expectNaNResult = NAN;
    double actualNaNResult = Math::signum(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to ZERO
    double positiveZero = 0.0;
    double expectPositiveZeroResult = 0.0;
    double actualPositiveZeroResult = Math::signum(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    double negativeZero = -0.0;
    double expectNegativeZeroResult = -0.0;
    double actualNegativeZeroResult = Math::signum(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathSignNumFloat){
    // Given a float
    float a = 50.14;
    float expectResult = 1.0;
    float actualResult = Math::signum(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given a value equal to NAN
    float nan = NAN;
    float expectNaNResult = NAN;
    float actualNaNResult = Math::signum(nan);
    ASSERT_EQUAL(expectNaNResult, actualNaNResult);

    // Given a value equal to ZERO
    float positiveZero = 0.0;
    float expectPositiveZeroResult = 0.0;
    float actualPositiveZeroResult = Math::signum(positiveZero);
    ASSERT_EQUAL(expectPositiveZeroResult, actualPositiveZeroResult);

    // Given a value equal to -ZERO
    float negativeZero = -0.0;
    float expectNegativeZeroResult = -0.0;
    float actualNegativeZeroResult = Math::signum(negativeZero);
    ASSERT_EQUAL(expectNegativeZeroResult, actualNegativeZeroResult);
}

TEST (JavaLang, MathSubtractExactInt){
    // Given 2 int
    int a = 10;
    int b = 20;
    int expectResult = -10;
    int actualResult = Math::subtractExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Integer::MIN_VALUE,
    // test if subtractExact throw ArithmeticException("integer overflow")
    int c = Integer::MIN_VALUE;
    try {
        int overFlowResult = Math::subtractExact(c, b);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathSubtractExactLong){
    // Given 2 long
    long a = 10;
    long b = 20;
    long expectResult = -10;
    long actualResult = Math::subtractExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MIN_VALUE,
    // test if subtractExact throw ArithmeticException("long overflow")
    long c = Long::MIN_VALUE;
    try {
        long overFlowResult = Math::subtractExact(c, b);
    }
    catch (Exception e) {
        ASSERT_STR("long overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathToIntExact){
    // Given a long
    long a = 100;
    int expectResult = 100;
    int actualResult = Math::toIntExact(a);
    ASSERT_EQUAL(expectResult, actualResult);

    // Given an int equal to Long::MAX_VALUE,
    // test if toIntExact throw ArithmeticException("integer overflow")
    long c = Long::MAX_VALUE;
    try {
        int overFlowResult = Math::toIntExact(c);
    }
    catch (Exception e) {
        ASSERT_STR("integer overflow", e.getMessage().toString());
    }
}

TEST (JavaLang, MathFloorDivLong) {
    // Given 2 int
    long dividend1 = 10;
    long divisor1 = 5;
    long expectResult1 = 2;
    long actualResult1 = Math::floorDiv(dividend1, divisor1);
    ASSERT_EQUAL(expectResult1, actualResult1);

    // Given 2 long
    long dividend2 = 11;
    long divisor2 = -5;
    long expectResult2 = -3;
    long actualResult2 = Math::floorDiv(dividend2, divisor2);
    ASSERT_EQUAL(expectResult2, actualResult2);

    // Given 2 long
    long dividend3 = 11;
    long divisor3 = 0;
    try {
        long devideByZero = Math::floorDiv(dividend3, divisor3);
    }
    catch (Exception e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, MathFloorModInt){
    // Given 2 int
    int dividend1 = 10;
    int divisor1 = 5;
    int expectResult1 = 0;
    int actualResult1 = Math::floorMod(dividend1, divisor1);
    ASSERT_EQUAL(expectResult1, actualResult1);

    // Given 2 int
    int dividend2 = 11;
    int divisor2 = -5;
    int expectResult2 = -4;
    int actualResult2 = Math::floorMod(dividend2, divisor2);
    ASSERT_EQUAL(expectResult2, actualResult2);
}

TEST (JavaLang, MathFloorModLong){
    // Given 2 int
    long dividend1 = 10;
    long divisor1 = 5;
    long expectResult1 = 0;
    long actualResult1 = Math::floorMod(dividend1, divisor1);
    ASSERT_EQUAL(expectResult1, actualResult1);

    // Given 2 long
    long dividend2 = 11;
    long divisor2 = -5;
    long expectResult2 = -4;
    long actualResult2 = Math::floorMod(dividend2, divisor2);
    ASSERT_EQUAL(expectResult2, actualResult2);
}

TEST (JavaLang, MathMax) {
	// return;
	double double_value_max_1 = 4;
	double double_value_max_2 = 2;
	ASSERT_EQUAL(4, Math::max(double_value_max_1, double_value_max_2));

	float float_value_max_1 = 4.123;
	float float_value_max_2 = 2.312;
	ASSERT_EQUAL(4.123, Math::max(float_value_max_1, float_value_max_2));

	int int_value_max_1 = 4;
	int int_value_max_2 = 2;
	ASSERT_EQUAL(4, Math::max(int_value_max_1, int_value_max_2));

	long long_value_max_1 = 4;
	long long_value_max_2 = 2;
	ASSERT_EQUAL(4, Math::max(long_value_max_1, long_value_max_2));
}

TEST (JavaLang, MathMin) {
	double double_value_min_1 = 4;
	double double_value_min_2 = 2;
	ASSERT_EQUAL(2, Math::min(double_value_min_1, double_value_min_2));

	float float_value_min_1 = 4.123;
	float float_value_min_2 = 2.312;
	ASSERT_EQUAL(2.312, Math::min(float_value_min_1, float_value_min_2));

    long long_value_min_1 = 4;
    long long_value_min_2 = 2;
    ASSERT_EQUAL(2, Math::min(long_value_min_1, long_value_min_2));

	int int_value_min_1 = 4;
	int int_value_min_2 = 2;
	ASSERT_EQUAL(2, Math::min(int_value_min_1, int_value_min_2));
}

TEST (JavaLang, MathPow) {
	double base = 3;
	double power = 3;
	ASSERT_EQUAL(27, Math::pow(base, power));
}

TEST (JavaLang, MathRound) {
	double double_value_round = 1.23643435;
	ASSERT_EQUAL(1, Math::round(double_value_round));

	float float_value_round = 1.23643435;
	ASSERT_EQUAL(1, Math::round(float_value_round));
}

TEST (JavaLang, MathRandom) {
	//ASSERT_TRUE(Math::random() > 0 && Math::random() < 1);
}

