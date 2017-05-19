//
// Created by huuphuoc on 19/05/2017.
//

extern "C" {
#include "../unit_test.h"
}
#include "../native.h"

TEST(Generic, Ord) {
    int tager = ord('a');
    ASSERT_EQUAL(97,tager);
}