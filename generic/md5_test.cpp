extern "C" {
#include "../unit_test.h"
}
#include "../native.h"

TEST(Generic, Md5) {
//    char *result1 = md5(NULL);
//    const char *expect1 = "d41d8cd98f00b204e9800998ecf8427e";
//    ASSERT_STR(expect1, result1);

    short shortNumber = 1234;
    char *result2 = md5(shortNumber);
    const char *expect2 = "81dc9bdb52d04dc20036dbd8313ed055";
    ASSERT_STR(expect2, result2);

    long longNumber = 0;
    char *result3 = md5(longNumber);
    const char *expect3 = "cfcd208495d565ef66e7dff9f98764da";
    ASSERT_STR(expect3, result3);

    double doubleNumber = 132412.341234;
    char *result4 = md5(doubleNumber);
    const char *expect4 = "b018ba22165908a093cdd171c121a749";
    ASSERT_STR(expect4, result4);

    std::string str = "happy";
    char *result5 = md5(str);
    const char *expect5 = "56ab24c15b72a457069c5ea42fcfc640";
    ASSERT_STR(expect5, result5);

    char *pointerChar = (char*)"";
    char *result6 = md5(pointerChar);
    const char *expect6 = "d41d8cd98f00b204e9800998ecf8427e";
    ASSERT_STR(expect6, result6);
}
