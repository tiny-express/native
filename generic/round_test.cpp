//
// Created by huuphuoc on 14/05/2017.
//

extern "C" {
#include "../unit_test.h"

}
#include "../native.h"

TEST(Generic, Round) {
    double number = 1.5345;
    double result = round(number, 2);
    ASSERT_TRUE(result == 1.53);

    result = round(number, 3);
    ASSERT_TRUE(1.535 == result);

    result = round(number, 0);
    ASSERT_TRUE(2 == result);


    number = 2.3;
    result = round(number,0);
    ASSERT_TRUE(2 == result);

    number = 3.8;
    result = round(number,0);
    ASSERT_TRUE(4 == result);

    number = 5.5;
    result = round(number,0);
    ASSERT_TRUE(6.0 == result);

    number = -2.3;
    result = round(number,0);
    ASSERT_TRUE(-2.0 == result);

    number = -3.8;
    result = round(number,0);
    ASSERT_TRUE(-4 == result);

    number = -5.5;
    result = round(number,0);
    ASSERT_TRUE(-6.0 == result);

    double target = -1.5345;
    result = round(target, 2);
    ASSERT_TRUE(-1.53 == result);

    target = -1.5345;
    result = round(target, 3);
    ASSERT_TRUE(-1.535 == result);

    result = round(target, 0);
    ASSERT_TRUE(-2 == result);


    float target1 = 2.3;
    float result1 = round(target1,0);
    ASSERT_TRUE(2 == result1);

    target1 = 3.8;
    result1 = round(target1,0);
    ASSERT_TRUE(4 == result1);

    target1 = 5.5;
    result1 = round(target1,0);
    ASSERT_TRUE(6.0 == result1);

    target1 = -2.3;
    result1 = round(target1,0);
    ASSERT_TRUE(-2.0 == result1);

    target1 = -3.8;
    result1 = round(target1,0);
    ASSERT_TRUE(-4 == result1);

    target1 = -5.5;
    result1 = round(target1,0);
    ASSERT_TRUE(-6.0 == result1);

}