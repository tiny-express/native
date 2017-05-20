//
// Created by huuphuoc on 19/05/2017.
//

extern "C" {
#include "../unit_test.h"
}
#include "../generic.hpp"

TEST(Generic, Chr) {
    char target = chr(97);
    ASSERT_EQUAL('a', target);

    target = chr(257);
    ASSERT_EQUAL(-1, target);
}