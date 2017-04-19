#include "../builtin.h"
#include "../unit_test.h"

TEST(Builtin_String, Replace) {
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

TEST(Builtin_String, Trim) {
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

    char *target3 = "Hello   World";
    char *result3 = string_trim(target3);
    //ASSERT_STR(expect, result3);
}

TEST(Builtin_String, Join) {
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

TEST(Builtin_String, Split) {
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

TEST(Builtin_String, StartWith) {
    char *target = "Hello World";
    char *prefix = "Hello";
    ASSERT_TRUE(string_start(target, prefix));

    prefix = "Nope";
    ASSERT_FALSE(string_start(target, prefix));

    prefix = "Prefix is longer than target";
    ASSERT_FALSE(string_start(target, prefix));
}

TEST(Builtin_String, EndWith) {
    char *target = "Hello World";
    char *suffix = "World";
    ASSERT_TRUE(string_end(target, suffix));

    suffix = "Nope";
    ASSERT_FALSE(string_end(target, suffix));

    suffix = "Suffix is longer than target";
    ASSERT_FALSE(string_end(target, suffix));
}

TEST(Builtin_String, IndexOf) {
    char *target = "Hello World";
    char *subtarget = "World";
    ASSERT_EQUAL(6, string_index(target, subtarget));

    subtarget = "Substring is longer than target";
    ASSERT_EQUAL(-1, string_index(target, subtarget));

    subtarget = "Hello";
    ASSERT_EQUAL(0, string_index(target, subtarget));

    subtarget = "Nope";
    ASSERT_EQUAL(-1, string_index(target, subtarget));
}

TEST(Builtin_String, Random) {
    char *target = "ABCXYZ";
    int size = 4;
    char *result = string_random(target, size);

    ASSERT_EQUAL(4, length_pointer_char(result));
}


TEST(Builtin_String, Concat) {
    char *target = "Hello";
    char *subtarget = "World";

    char *result = string_concat(target, subtarget);
    ASSERT_STR("HelloWorld", result);
    ASSERT_EQUAL(10, length_pointer_char(result));

    subtarget = "";
    result = string_concat(target, subtarget);
    ASSERT_STR("Hello", result);
    ASSERT_EQUAL(5, length_pointer_char(result));
}

// Convert
TEST(Builtin_String, ConvertToPointerChar){
    char *target = "Hello Hello Hello Hello Hello Hello!";
    char array[50] = "Hello Hello Hello Hello Hello Hello!";
    char *result = convert_to_pointer_char(array);

    ASSERT_STR(result, target);
}

TEST(Builtin_String, FromTo) {
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
    expect = "";
    ASSERT_STR(expect, result);
}

TEST(Builtin_String, From) {
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

TEST(Builtin_String, To) {
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
    expect = "";
    result = string_to(target, to);
    ASSERT_STR(expect, result);
}

TEST(Builtin_String, Copy) {
    char *target = "Hello World";
    char *result = string_copy(target);
    ASSERT_STR(target, result);

    target = "";
    result = string_copy(target);
    ASSERT_STR(target, result);
}

TEST(Builtin_String, ToUpper) {
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

TEST(Builtin_String, Lower) {
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

TEST(Builtin_String, Title) {
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


<<<<<<< HEAD
TEST(Builtin_String, FromToElement) {
    char *target = "https://www.google.com/search?client=ubuntu&channel=fs&q=dich&ie=utf-8&oe=utf-8";
    char *result = string_from_to_element(target, LENGHT_OF_HTTPS, "+?/");
    ASSERT_STR(result, "www.google.com");

    result = string_from_to_element(target, 0, " ");
    ASSERT_STR(result, target);

    ASSERT_EQUAL(string_from_to_element("", 0,"/"), NULL);
}
=======
>>>>>>> 46fdb4e8168657fe7052b618db37ba400ef9c741
