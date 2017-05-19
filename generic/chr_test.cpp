//
// Created by huuphuoc on 19/05/2017.
//

extern "C" {
#include "../unit_test.h"
}
#include "../native.h"

TEST(Generic, Chr) {
    char tager = chr(97);
    ASSERT_EQUAL('a',tager);

    tager = chr(257);
    ASSERT_EQUAL(-1,tager);
}