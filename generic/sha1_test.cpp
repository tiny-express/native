extern "C" {
#include "../unit_test.h"
}
#include "../native.h"

TEST(Generic, Sha1) {

    char *result2 = sha1(1234);
    const char *expect2 = "7110eda4d09e062aa5e4a390b0a572ac0d2c0220";
    ASSERT_STR(expect2, result2);

    char *result3 = sha1((long) 132412341234);
    const char *expect3 = "294adf8400362d825b8a86bd57e8c3980a0539bd";
    ASSERT_STR(expect3, result3);

    char *result4 = sha1(132412.341234);
    const char *expect4 = "40c745a7a3890bf3dde11e88464e20638d229ef4";
    ASSERT_STR(expect4, result4);

    std::string str = "happy";
    char *result5 = sha1(str);
    const char *expect5 = "3978d009748ef54ad6ef7bf851bd55491b1fe6bb";
    ASSERT_STR(expect5, result5);
}

