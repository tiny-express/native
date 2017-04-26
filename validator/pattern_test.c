#include "../validator.h"
#include "../unit_test.h"

TEST(Builtin_Validator, EmailPattern) {
    char *target = "anh_khoa.1@gmail.com";
    int expect = 1;
    int result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@foodtiny.vn";
    expect = 1;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "@foodtiny.vn";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@as.vn";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@foodtiny.vn.net.vn";
    expect = 1;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);
}

TEST(Builtin_Validator, PhonePattern) {
    char *target = "0986216213";
    int expect = 1;
    int result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "foodtiny";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "0012238364";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "1234";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "1234567890909090";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);
}

TEST(Builtin_Validator, UrlPattern) {
    char *target = "https://goo-gle.com/";
    int expect = 1;
    int result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3000";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3000/";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3000/filepath/givemeaname/";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>value3";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "/google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>";
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);
}


