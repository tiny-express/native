#include "../crypto.h"
#include "../unit_test.h"


TEST(Crypto, Md5Encode) {
    char *result = md5_encode((unsigned char*)"ahihi");
    char *expect = "24dca22fdab7a594baa005d55db4f7bf";
    ASSERT_STR(expect, result);
}
