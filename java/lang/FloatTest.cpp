//
// Created by huuphuoc on 21/05/2017.
//

extern "C" {
#include "../../unit_test.h"
}
#include "Float.hpp"

using namespace Java::Lang;

TEST(JavaLang, Float) {
    Float emptyFloat;
    emptyFloat = 3.0;
    ASSERT_EQUAL(3, emptyFloat.intValue());

    Float validInteger = 3;
    ASSERT_EQUAL(3, validInteger.intValue());

    Float *validIntegerPointer = Float::parseInt("6");
    ASSERT_EQUAL(6, validIntegerPointer->intValue());
}