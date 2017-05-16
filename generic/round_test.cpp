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
    ASSERT_EQUAL(1.53, result);

    result = round(number, 3);
    ASSERT_EQUAL(1.535, result);

    result = round(number, 0);
    ASSERT_EQUAL(2, result);

    result = round(number, -2);
    ASSERT_EQUAL(0, result);

    result = round(number, -1);
    ASSERT_EQUAL(0, result);

    number = 153.45;
    result = round(number, -1);
    ASSERT_EQUAL(150, result);

    result = round(number, -2);
    ASSERT_EQUAL(200, result);

    double target = -1.5345;
    result = round(target, 2);
    ASSERT_EQUAL(-1.53, result);

    result = round(target, 3);
    ASSERT_EQUAL(-1.535, result);

    result = round(target, 0);
    ASSERT_EQUAL(0, result);

    result = round(target, -1);
    ASSERT_EQUAL(0, result);

    result = round(target, -2);
    ASSERT_EQUAL(0, result);

}