#include <stdlib.h>
#include "../crypto.h"
#include "../unit_test.h"


TEST(Crypto, Md5) {
    char *result = md5_encode((unsigned char*)"ahihi");
    char *expect = "24dca22fdab7a594baa005d55db4f7bf";
    ASSERT_STR(expect, result);
    free(result);

    char *result1 = md5_encode((unsigned char*)"1234");
    char *expect1 = "81dc9bdb52d04dc20036dbd8313ed055";
    ASSERT_STR(expect1, result1);
    free(result1);

    char *result2 = md5_encode((unsigned char*)"-1234");
    char *expect2 = "880123d345caee2413e8e83e483fc201";
    ASSERT_STR(expect2, result2);
    free(result2);

    char *result3 = md5_encode((unsigned char*)"0.123412341234");
    char *expect3 = "fdb8b828f4f3a9d695ce759eb95006f5";
    ASSERT_STR(expect3, result3);
    free(result3);
}
