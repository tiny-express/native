#include <stdio.h>
#include "../builtin.h"
#include "../unit_test.h"

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
	ASSERT_STR("loint", findParamFromUrl("username", url));
	ASSERT_STR("Loi AbC", findParamFromUrl("firstName", url));
	ASSERT_STR("1234", findParamFromUrl("password", url));
	
	char *url2 = "/abcd/?username=&password=&firstName=Loi&&lastName=Nguyen";
	ASSERT_STR("", findParamFromUrl("username", url2));
	ASSERT_STR("Loi", findParamFromUrl("firstName", url2));
	ASSERT_STR("", findParamFromUrl("password", url2));
	ASSERT_STR("Nguyen", findParamFromUrl("lastName", url2));
	
	char *url3 = "/abcd/";
	ASSERT_STR("", findParamFromUrl("username", url3));
	ASSERT_STR("", findParamFromUrl("firstName", url3));
	ASSERT_STR("", findParamFromUrl("password", url3));
	ASSERT_STR("", findParamFromUrl("lastName", url3));
	
	char *url4 = "/abcd/??";
	ASSERT_STR("", findParamFromUrl("username", url4));
	ASSERT_STR("", findParamFromUrl("firstName", url4));
	ASSERT_STR("", findParamFromUrl("password", url4));
	ASSERT_STR("", findParamFromUrl("lastName", url4));
}