#include "../crypto.h"
#include "../unit_test.h"

TEST(Crypto, Sha1Encode) {
    char *result = sha1_encode("hello world");
    char *expect = "2aae6c35c94fcfb415dbe95f408b9ce91ee846ed";
    ASSERT_STR(expect, result);

//    char *result1 = sha1_encode("1234");
//    char *expect1 = "7110eda4d09e062aa5e4a390b0a572ac0d2c0220";
//    ASSERT_STR(expect1, result1);
}
