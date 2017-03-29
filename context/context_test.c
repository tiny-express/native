#include <stdio.h>
#include "../../native/builtin.h"
#include "../unit_test.h"

TEST(Builtin_Context, FindParam) {
    char *params = "username=loint&password=1234&firstName=Loi AbC&lastName=Nguyen";
    ASSERT_STR("loint", findParam("username", params));
    ASSERT_STR("Loi AbC", findParam("firstName", params));
    ASSERT_STR("1234", findParam("password", params));

    char *params2 = "username=&password=&firstName=Loi&&lastName=Nguyen";
    ASSERT_STR("", findParam("username", params2));
    ASSERT_STR("Loi", findParam("firstName", params2));
    ASSERT_STR("", findParam("password", params2));
    ASSERT_STR("Nguyen", findParam("lastName", params2));

    char *params3 = "";
    ASSERT_STR("", findParam("username", params3));
    ASSERT_STR("", findParam("firstName", params3));
    ASSERT_STR("", findParam("password", params3));
    ASSERT_STR("", findParam("lastName", params3));
}

TEST(Builtin_Context, FindParamFromUrl) {
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