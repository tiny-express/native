extern "C" {
#include "../unit_test.h"
}
#include "../native.h"

TEST(Generic, Md5) {

    char *result2 = md5(1234);
    const char *expect2 = "81dc9bdb52d04dc20036dbd8313ed055";
    ASSERT_STR(expect2, result2);

    char *result3 = md5((long) 132412341234);
    const char *expect3 = "3365bbfd5d5e7f02df7c0d8412dc18ad";
    ASSERT_STR(expect3, result3);

    char *result4 = md5(132412.341234);
    const char *expect4 = "b018ba22165908a093cdd171c121a749";
    ASSERT_STR(expect4, result4);

    std::string str = "happy";
    char *result5 = md5(str);
    const char *expect5 = "56ab24c15b72a457069c5ea42fcfc640";
    ASSERT_STR(expect5, result5);
}
