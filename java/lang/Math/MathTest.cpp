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

extern "C" {
#include "../../../unit_test.h"
}

#include "Math.hpp"
#include "../Integer/Integer.hpp"
#include "../Long/Long.hpp"

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
    //Given 2 int
    int a = 1;
    int b = 2;
    int expectResult = 3;
    int actualResult = Math::addExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);

    int expectOverFlowResult = 0;
    int actualOverFlowResult = Math::addExact(Integer::MAX_VALUE, b);
    ASSERT_EQUAL(expectOverFlowResult, actualOverFlowResult);
}

TEST (JavaLang, MathAddExactLong){
    //Given 2 long
    long a = 1;
    long b = 2;
    long expectResult = 3;
    long actualResult = Math::addExact(a, b);
    ASSERT_EQUAL(expectResult, actualResult);

    long expectOverFlowResult = 0;
    long actualOverFlowResult = Math::addExact(Long::MAX_VALUE, b);
    ASSERT_EQUAL(expectOverFlowResult, actualOverFlowResult);
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
    //Given a variable equal to 3^3
    double cube = 27;
    ASSERT_DBL_NEAR(3, Math::cbrt(cube));
}

TEST (JavaLang, MathSqrt){
    // Given a variable equal to 3^2
    double square = 9;
    ASSERT_EQUAL(3, Math::sqrt(9));
    //
}

TEST (JavaLang, MathCeil){
    // Given two double numbers
    double x = 125.9;
    double y = 0.4873;
    ASSERT_EQUAL(126, Math::ceil(x));
    ASSERT_EQUAL(1, Math::ceil(y));
}

TEST (JavaLang, MathLog){
    // Given a variable for log 10-base
    double tenBase = 10;
    ASSERT_EQUAL(1, Math::log10(tenBase));

    // Given a variable for log e-base
    double eBase = Math::E;
	ASSERT_EQUAL(1, Math::log(eBase));
	ASSERT_EQUAL(1.313261688, Math::log1p(eBase));

}

TEST (JavaLang, MathRInt){
	// Given two double numbers
	double x = 125.9;
	double y = 0.4873;
	ASSERT_EQUAL(126, Math::rint(x));
	ASSERT_EQUAL(0, Math::rint(y));
}

TEST (JavaLang, MathExp){
	//Given a variable equal to E^3
	double eCubed = Math::pow(Math::E,3);
	ASSERT_EQUAL(eCubed, Math::exp(3));
	ASSERT_EQUAL(eCubed - 1, Math::expm1(3));
}

TEST (JavaLang, MathHypot){
	// Given two double numbers
	double x = 6;
	double y = 8;
	ASSERT_EQUAL(10, Math::hypot(x, y));
}

TEST (JavaLang, MathIEEERemainder){
	// Given two double numbers
	double x = 8;
	double y = 6;
	ASSERT_EQUAL(2, Math::IEEEremainder(x, y));
}

TEST (JavaLang, MathCosh){
	// Given a variable equal PI/2
	double radian = Math::PI/2;
	ASSERT_EQUAL(2.5091784786580567, Math::cosh(radian));
}

TEST (JavaLang, MathSinh){
	// Given a variable equal PI/2
	double radian = Math::PI/2;
	ASSERT_EQUAL(2.3012989023072947, Math::sinh(radian));
}

TEST (JavaLang, MathTanh){
	// Given a variable equal PI/2
	double radian = Math::PI/2;
	ASSERT_EQUAL(0.9171523356672744, Math::tanh(radian));
}
TEST (JavaLang, MathToRadian){
    // Given a variable radian which is equal to PI
    double radian = Math::PI;
    ASSERT_EQUAL(radian, Math::toRadians(180));
}

TEST (JavaLang, MathToDegree){
    // Given a variable degree which is equal to PI
    double degree = 180;
    ASSERT_EQUAL(degree, Math::toDegrees(Math::PI));
}

TEST (JavaLang, MathFloor) {
	return;
	double floor_value = 2.3;
	ASSERT_EQUAL(2, Math::floor(floor_value));

	double floor_value_1 = -2.3;
	ASSERT_EQUAL(-2, Math::floor(floor_value_1));
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
	return;
	double double_value_round = 1.23643435;
	ASSERT_EQUAL(1, Math::round(double_value_round));

	float float_value_round = 1.23643435;
	ASSERT_EQUAL(1, Math::round(float_value_round));
}

TEST (JavaLang, MathRandom) {
	//ASSERT_TRUE(Math::random() > 0 && Math::random() < 1);
}

TEST (JavaLang, MathMultipleExact){
    int base = Integer::MAX_VALUE;
    int power = 2;
    //ASSERT_EQUAL(4294967294, Math::multiplyExact(base,power));
}