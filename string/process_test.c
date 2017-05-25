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

#include "../builtin.h"
#include "../unit_test.h"

TEST(String, ProcessReplace) {
    char *target = "Hello World";
    char *find = "World";
    char *replace_with = "Foodship";
    char *expect = "Hello Foodship";
    char *result = string_replace(target,find,replace_with);
    ASSERT_STR(expect, result);

    char *find1 = "Nothing";
    char *expect1 ="Hello World";
    char *result1 = string_replace(target,find1,replace_with);
    ASSERT_STR(expect1, result1);
}

TEST(String, ProcessTrim) {
    char *expect = "Hello World";
    char *target = "  Hello World  ";
    char *result = string_trim(target);
    ASSERT_STR(expect, result);

    char *target1 = "  Hello World";
    char *result1 = string_trim(target1);
    ASSERT_STR(expect, result1);

    char *target2 = "Hello World  ";
    char *result2 = string_trim(target2);
    ASSERT_STR(expect, result2);
}

TEST(String, ProcessJoin) {
    char *target[] = {
        (char *) "The",
        (char *) "quick",
        (char *) "brown",
        (char *) "fox",
        (char *) "jumps",
        (char *) "over",
        (char *) "the",
        (char *) "lazy",
        (char *) "dog",
        '\0'
    };
    char *delimiter = "|";
    char *expect = "The|quick|brown|fox|jumps|over|the|lazy|dog";
    char *result = string_join(target, delimiter);
    ASSERT_STR(expect, result);
}

TEST(String, ProcessSplit) {
    char *target = "The|quick|brown|fox|jumps|over|the|lazy|dog";
    char *delimiter = "|";
    char **result = string_split(target, delimiter);
    ASSERT_STR("The", result[0]);
    ASSERT_STR("quick", result[1]);
    ASSERT_STR("brown", result[2]);
    ASSERT_STR("fox", result[3]);
    ASSERT_STR("jumps", result[4]);
    ASSERT_STR("over", result[5]);
    ASSERT_STR("the", result[6]);
    ASSERT_STR("lazy", result[7]);
    ASSERT_STR("dog", result[8]);

    target = "Nothing to split";
    result = string_split(target, delimiter);
    ASSERT_STR("Nothing to split", result[0]);

    char *url = "/abc?username=loint&password=123&firstName=Loi&lastName=Nguyen";
    char** urlComponents = string_split(url, "?");
    ASSERT_EQUAL(2, length_pointer_pointer_char(urlComponents));
    ASSERT_STR("/abc", urlComponents[0]);
    ASSERT_STR("username=loint&password=123&firstName=Loi&lastName=Nguyen", urlComponents[1]);

    target = "HTTP/1.1 200 OK\n"
            "Content-Type: application/json; charset=UTF-8\n"
            "Content-Length: 1498\r\n"
            "\r\n"
            "{\"took\":26,\"timed_out\":false,\"_shards\":{\"total\":2,\"successful\":2,\"failed\":0},\"hits\":{\"total\":1,\"max_score\":4.495634,\"hits\":[{\"_index\":\"db_foodtiny_test\",\"_type\":\"food_with_shop\",\"_id\":\"[\\\"ebc0aa50-3a26-11e7-9d38-8f725678c689\\\",\\\"05b05ff0-3a27-11e7-9d38-8f725678c689\\\"]\",\"_score\":4.495634,\"_source\":{\"food_discount\":0.0,\"food_name\":{\"en_EN\":\"Noodles with deep fried tofu, shrimp paste\",\"vi_VN\":\"Bún đậu mắm tôm\"},\"food_menu_name\":{\"en_EN\":\"Noodles\",\"vi_VN\":\"Bún\"},\"food_shop_online_status\":false,\"food_shop_type\":{\"en_EN\":\"Diner\",\"vi_VN\":\"Quán Ăn\"},\"food_shop_id\":\"ebc0aa50-3a26-11e7-9d38-8f725678c689\",\"food_shop_rating\":4.0,\"food_id\":\"05b05ff0-3a27-11e7-9d38-8f725678c689\",\"food_image\":\"http://healthplus.vn/Images/Uploaded/Share/2013/08/25/e9020130521111500eP8Qt3fV2.jpg\",\"food_shop_logo\":\"http://thpt.daytot.vn/files/thpt/chi-pheo.jpg\",\"food_shop_phone_number\":\"0112\",\"food_ingredient_1\":{\"en_EN\":\"Noodles\",\"vi_VN\":\"Bún\"},\"food_price\":45000.0,\"food_shop_address\":{\"en_EN\":\"818 Nguyen Kiem, Ward 3, Go Vap District, HCMC\",\"vi_VN\":\"818 Nguyễn Kiệm, Phường 3, Gò Vấp, Hồ Chí Minh\"},\"food_ingredient_2\":{\"en_EN\":\"tofu\",\"vi_VN\":\"Đậu hũ\"},\"food_ingredient_3\":{\"en_EN\":\"Shrimp paste\",\"vi_VN\":\"Mắm tôm\"},\"food_shop_name\":\"Bún đậu Thị Nở\",\"food_shop_start_time\":\"08:00\",\"location\":\"10.817053, 106.678834\",\"food_shop_delivery_status\":false,\"food_cooking_method\":{\"en_EN\":\"None\",\"vi_VN\":\"None\"},\"food_shop_quota_shipping\":100000.0,\"food_shop_finish_time\":\"21:00\"}}]}}";

    result = string_split(target, "\r\n\r\n");
    ASSERT_EQUAL(1498, length_pointer_char(result[1]));
}

TEST(String, ProcessStartsWith) {
    char *target = "Hello World";
    char *prefix = "Hello";
    ASSERT_TRUE(string_startswith(target, prefix));

    prefix = "Nope";
    ASSERT_FALSE(string_startswith(target, prefix));

    prefix = "Prefix is longer than target";
    ASSERT_FALSE(string_startswith(target, prefix));
}

TEST(String, ProcessEndsWith) {
    char *target = "Hello World";
    char *suffix = "World";
    ASSERT_TRUE(string_endswith(target, suffix));

    suffix = "Nope";
    ASSERT_FALSE(string_endswith(target, suffix));

    suffix = "Suffix is longer than target";
    ASSERT_FALSE(string_endswith(target, suffix));

    suffix = "Suffix is longer than target";
    ASSERT_FALSE(string_endswith(target, suffix));
}

TEST(String, ProcessIndexOf) {
    char *target = "Hello World";
    char *subtarget = "World";
    int result = string_index(target, subtarget, 1);
    ASSERT_EQUAL(6, result);

    target = "Hello World World World World";
    subtarget = "World";
    result = string_index(target, subtarget, 3);
    ASSERT_EQUAL(18, result);

    target = "Hello World World World World";
    subtarget = "orl";
    result = string_index(target, subtarget, 2);
    ASSERT_EQUAL(13, result);

    target = "###############";
    subtarget = "##";
    result = string_index(target, subtarget, 4);
    ASSERT_EQUAL(3, result);

    subtarget = "Substring is longer than target";
    result = string_index(target, subtarget, 1);
    ASSERT_EQUAL(-1, result);

    subtarget = "Hello";
    result = string_index(target, subtarget, 1);
    ASSERT_EQUAL(-1, result);

    subtarget = "Nope";
    result = string_index(target, subtarget, 1);
    ASSERT_EQUAL(-1, result);

    subtarget = "xxx";
    target = "";
    result = string_index(target, subtarget, 1);
    ASSERT_EQUAL(-1, result);

    subtarget = "";
    target = "";
    result = string_index(target, subtarget, 2);
    ASSERT_EQUAL(-1, result);

    subtarget = "";
    target = NULL;
    result = string_index(target, subtarget, 2);
    ASSERT_EQUAL(-1, result);

    subtarget = NULL;
    target = NULL;
    result = string_index(target, subtarget, 2);
    ASSERT_EQUAL(-1, result);

    subtarget = "\0";
    target = "\0";
    result = string_index(target, subtarget, -1);
    ASSERT_EQUAL(-1, result);

    subtarget = "\0";
    target = NULL;
    result = string_index(target, subtarget, -1);
    ASSERT_EQUAL(-1, result);

    subtarget = NULL;
    target = "\0";
    result = string_index(target, subtarget, -1);
    ASSERT_EQUAL(-1, result);

}

TEST(String, ProcessRandom) {
    char *target = "ABCXYZ";
    int size = 4;
    char *result = string_random(target, size);

    ASSERT_EQUAL(4, length_pointer_char(result));
}

TEST(String, ProcessConcat) {
    char *target = "Hello\0";
    char *subtarget = "World\0";

    char *result = string_concat(target, subtarget);
    ASSERT_STR("HelloWorld", result);
    ASSERT_EQUAL(10, length_pointer_char(result));

    subtarget = "";
    result = string_concat(target, subtarget);
    ASSERT_STR("Hello", result);
    ASSERT_EQUAL(5, length_pointer_char(result));
}

TEST(String, ProcessConcatAsm) {
    return;
    // TODO loint@foodtiny.com
    char *target = "Hello\0";
    char *subtarget = "World\0";

    char *result = string_concat_asm(target, subtarget);
    ASSERT_STR("HelloWorld", result);
    ASSERT_EQUAL(10, length_pointer_char(result));

    subtarget = "";
    result = string_concat_asm(target, subtarget);
    ASSERT_STR("Hello", result);
    ASSERT_EQUAL(5, length_pointer_char(result));
}

TEST(String, ProcessFromTo) {
    char *target = "Hello World";
    int from = 6;
    int to = 11;
    char *result = string_from_to(target, from, to);
    char *expect = "World";
    ASSERT_STR(expect, result);

    from = 11;
    to = 6;
    result = string_from_to(target, from, to);
    expect = "";
    ASSERT_STR(expect, result);

    from = -1;
    to = 11;
    result = string_from_to(target, from, to);
    expect = "";
    ASSERT_STR(expect, result);

    from = 0;
    to = 20;
    result = string_from_to(target, from, to);
    expect = "Hello World";
    ASSERT_STR(expect, result);

    target = "HTTP/1.0 200 OK\n"
            "Content-Type: text/html; charset=utf-8\n"
            "Content-Length: 122\n"
            "Server: Werkzeug/0.12.2 Python/2.7.12\n"
            "Date: Wed, 24 May 2017 19:14:29 GMT\n"
            "\n"
            "{\"multicast_id\":5160844598332076776,\"success\":0,"
            "\"failure\":1,\"canonical_ids\":0,"
            "\"results\":[{\"error\":\"InvalidRegistration\"}]}";
    from = 30;
    to = 53;
    result = string_from_to(target, from, to);
    expect = "text/html; charset=utf-8";
    ASSERT_STR(expect, result);
}

TEST(String, ProcessFrom) {
    char *target = "Hello World";
    int from = 6;
    char *result = string_from(target, from);
    char *expect = "World";
    ASSERT_STR(expect, result);

    from = -1;
    expect = "";
    result = string_from(target, from);
    ASSERT_STR(expect, result);

    from = 20;
    expect = "";
    result = string_from(target, from);
    ASSERT_STR(expect, result);
}

TEST(String, ProcessTo) {
    char *target = "Hello World";
    int to = 4;
    char *result = string_to(target, to);
    char *expect = "Hello";
    ASSERT_STR(expect, result);
    
    to = -1;
    expect = "";
    result = string_to(target, to);
    ASSERT_STR(expect, result);

    to = 20;
    expect = "Hello World";
    result = string_to(target, to);
    ASSERT_STR(expect, result);
}

TEST(String, ProcessCopy) {
    char *target = "Hello World";
    char *result = string_copy(target);
    ASSERT_STR(target, result);

    target = "";
    result = string_copy(target);
    ASSERT_STR(target, result);
}

TEST(String, ProcessUpper) {
    char *target = "Hello World";
    char *result = string_upper(target);
    char *expect = "HELLO WORLD";
    ASSERT_STR(expect, result);

    target = "&*^&%&";
    result = string_upper(target);
    ASSERT_STR(target, result);

    target = "JIJjifje&*^";
    result = string_upper(target);
    expect = "JIJJIFJE&*^";
    ASSERT_STR(expect, result);
}

TEST(String, ProcessLower) {
    char *target = "HELLO WORLD";
    char *result = string_lower(target);
    char *expect = "hello world";
    ASSERT_STR(expect, result);

    target = "&*%&*";
    result = string_lower(target);
    ASSERT_STR(target, result);
    
    target = "HIhahaHI!@#";
    result = string_lower(target);
    expect = "hihahahi!@#";
    ASSERT_STR(expect, result);

    target = "1";
    result = string_lower(target);
    expect = "1";
    ASSERT_STR(expect, result);
}

TEST(String, ProcessTitle) {
    char *target = "hello world";
    char *result = string_title(target);
    char *expect = "Hello World";
    ASSERT_STR(expect, result);

    target = "#hi";
    expect = "#hi";
    result = string_title(target);
    ASSERT_STR(expect, result);
    
    target = "abcd";
    expect = "Abcd";
    result = string_title(target);
    ASSERT_STR(expect, result);
}

TEST(String, ProcessStandardized) {
    char *target = "  hello  world ";
    char *expect = "hello world";
    char *result = string_standardized(target);
    ASSERT_STR(expect, result);
    
    target = "     hello      world      world     ";
    expect = "hello world world";
    result = string_standardized(target);
    ASSERT_STR(expect, result);
}

TEST(String, ProcessEquals) {
    char *target1 = NULL;
    char *target2 = NULL;
    ASSERT_TRUE(string_equals(target1, target2));

    target1 = (char*) "hello";
    target2 = NULL;
    ASSERT_FALSE(string_equals(target1, target2));

    target1 = NULL;
    target2 = (char*) "hello";
    ASSERT_FALSE(string_equals(target1, target2));

    target1 = "hello  world ";
    target2 = "  hello world";
    ASSERT_FALSE(string_equals(target1, target2));

    target1 = "abcd";
    target2 = "abcd";
    ASSERT_TRUE(string_equals(target1, target2));
}




