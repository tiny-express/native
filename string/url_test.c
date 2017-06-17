/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include "../unit_test.h"
#include "../string.h"

TEST (Url, Encode) {
	char *target = "Quán ăn";
	char *result = url_encode(target);
	char *expect = "Qu%c3%a1n+%c4%83n";
	ASSERT_STR(expect, result);
}

TEST (Url, Decode) {
	char *target = "Qu%c3%a1n+%c4%83n";
	char *result = url_decode(target);
	char *expect = "Quán ăn";
	ASSERT_STR(expect, result);
}

TEST (Url, FindParam) {
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
    char *result = find_param("username", params3);
	ASSERT_STR("", result);
	free(result);

    result = find_param("firstName", params3);
	ASSERT_STR("", result);
    free(result);

    result = find_param("password", params3);
	ASSERT_STR("", result);
	free(result);

    result = find_param("lastName", params3);
	ASSERT_STR("", result);
	free(result);
}

TEST (Url, FindParamFromUrl) {
	char *url = "/abcd?username=loint&password=1234&firstName=Loi AbC&lastName=Nguyen";
	ASSERT_STR("loint", find_param_from_url("username", url));
	ASSERT_STR("Loi AbC", find_param_from_url("firstName", url));
	ASSERT_STR("1234", find_param_from_url("password", url));

	char *url2 = "/abcd/?username=&password=&firstName=Loi&&lastName=Nguyen";
	ASSERT_STR("", find_param_from_url("username", url2));
    free(url2);
	ASSERT_STR("Loi", find_param_from_url("firstName", url2));
	ASSERT_STR("", find_param_from_url("password", url2));
    free(url2);
	ASSERT_STR("Nguyen", find_param_from_url("lastName", url2));

	char *url3 = "/abcd/";
	ASSERT_STR("", ("username", url3));
	ASSERT_STR("", find_param_from_url("firstName", url3));
    free(url3);
    ASSERT_STR("", find_param_from_url("password", url3));
    free(url3);
    ASSERT_STR("", find_param_from_url("lastName", url3));
    free(url3);

	char *url4 = "/abcd/??";
	ASSERT_STR("", find_param_from_url("username", url4));
	free(url4);
	ASSERT_STR("", find_param_from_url("firstName", url4));
	free(url4);
	ASSERT_STR("", find_param_from_url("password", url4));
	free(url4);
	ASSERT_STR("", find_param_from_url("lastName", url4));
	free(url4);
}