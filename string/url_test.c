#include "../unit_test.h"
#include "../string.h"

TEST(String, UrlEncode) {
    char *target = "Quán ăn";
    char *result = url_encode(target);
    char *expect = "Qu%c3%a1n+%c4%83n";
    ASSERT_STR(expect, result);
}

TEST(String, UrlDecode) {
    char *target = "Qu%c3%a1n+%c4%83n";
    char *result = url_decode(target);
    char *expect = "Quán ăn";
    ASSERT_STR(expect, result);
}

TEST(Context, FindParam) {
    char *params = "username=loint&password=1234&firstName=Loi AbC&lastName=Nguyen";
    ASSERT_STR("loint", find_param("username", params));
    ASSERT_STR("Loi AbC", find_param("firstName", params));
    ASSERT_STR("1234", find_param("password", params));

    char *params2 = "username=&password=&firstName=Loi&&lastName=Nguyen";
    ASSERT_STR("", find_param("username", params2));
    ASSERT_STR("Loi", find_param("firstName", params2));
    ASSERT_STR("", find_param("password", params2));
    ASSERT_STR("Nguyen", find_param("lastName", params2));

    char *params3 = "";
    ASSERT_STR("", find_param("username", params3));
    ASSERT_STR("", find_param("firstName", params3));
    ASSERT_STR("", find_param("password", params3));
    ASSERT_STR("", find_param("lastName", params3));
}

TEST(Context, FindParamFromUrl) {
    char *url = "/abcd?username=loint&password=1234&firstName=Loi AbC&lastName=Nguyen";
    ASSERT_STR("loint", find_param_from_url("username", url));
    ASSERT_STR("Loi AbC", find_param_from_url("firstName", url));
    ASSERT_STR("1234", find_param_from_url("password", url));

    char *url2 = "/abcd/?username=&password=&firstName=Loi&&lastName=Nguyen";
    ASSERT_STR("", find_param_from_url("username", url2));
    ASSERT_STR("Loi", find_param_from_url("firstName", url2));
    ASSERT_STR("", find_param_from_url("password", url2));
    ASSERT_STR("Nguyen", find_param_from_url("lastName", url2));

    char *url3 = "/abcd/";
    ASSERT_STR("", find_param_from_url("username", url3));
    ASSERT_STR("", find_param_from_url("firstName", url3));
    ASSERT_STR("", find_param_from_url("password", url3));
    ASSERT_STR("", find_param_from_url("lastName", url3));

    char *url4 = "/abcd/??";
    ASSERT_STR("", find_param_from_url("username", url4));
    ASSERT_STR("", find_param_from_url("firstName", url4));
    ASSERT_STR("", find_param_from_url("password", url4));
    ASSERT_STR("", find_param_from_url("lastName", url4));
}