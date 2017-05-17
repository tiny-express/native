#include "../crypto.h"
#include "../unit_test.h"
#include <stdlib.h>

TEST(Crypto, Sha1) {
    char *result = sha1_encode((unsigned char*)"hello world");
    char *expect = "2aae6c35c94fcfb415dbe95f408b9ce91ee846ed";
    ASSERT_STR(expect, result);
    free(result);

    char *result1 = sha1_encode((unsigned char*)"1234");
    char *expect1 = "7110eda4d09e062aa5e4a390b0a572ac0d2c0220";
    ASSERT_STR(expect1, result1);
    free(result1);

    char *result2 = sha1_encode((unsigned char*)"-1234");
    char *expect2 = "b3b24bf88506f9c55e4c1fe23eba7d5322c2448b";
    ASSERT_STR(expect2, result2);
    free(result2);

    char *result3 = sha1_encode((unsigned char*)"1234.12341234");
    char *expect3 = "4c9ca7e60770fbc9b07724081e2fa783a7743337";
    ASSERT_STR(expect3, result3);
    free(result3);
}
