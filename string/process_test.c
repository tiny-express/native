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

//    char *target3 = "Hello   World";
//    char *result3 = string_trim(target3);
//    ASSERT_STR(expect, result3);
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
    char *delim = "|";
    char *expect = "The|quick|brown|fox|jumps|over|the|lazy|dog";
    char *result = string_join(target, delim);

    ASSERT_STR(expect, string_join(target, delim));
}

TEST(String, ProcessSplit) {
    char *target = "The|quick|brown|fox|jumps|over|the|lazy|dog";
    char *delim = "|";
    char **result = string_split(target, delim);
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
    result = string_split(target, delim);
    ASSERT_STR("Nothing to split", result[0]);

    char *url = "/abc?username=loint&password=123&firstName=Loi&lastName=Nguyen";
    char** urlComponents = string_split(url, "?");
    ASSERT_EQUAL(2, length_pointer_pointer_char(urlComponents));
    ASSERT_STR("/abc", urlComponents[0]);
    ASSERT_STR("username=loint&password=123&firstName=Loi&lastName=Nguyen", urlComponents[1]);
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

