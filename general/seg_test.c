#include "../builtin.h"
#include "../unit_test.h"

TEST(Builtin_Segment, PointerType) {
    char *charArray = "Hello World";
    int from = 6;
    int to = 10;
    char *result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(5, length_pointer_char(result));
    ASSERT_STR("World", result);

    from = 6;
    to = 6;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(1, length_pointer_char(result));
    ASSERT_STR("W", result);

    from = 7;
    to = 6;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);
}

TEST(Builtin_Segment, PointerConstChar) {
    char *charArray = "Hello World";
    int from = 6;
    int to = 6;
    char *result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(1, length_pointer_char(result));
    ASSERT_STR("W", result);

    from = 7;
    to = 6;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);
}

TEST(Builtin_Segment, PointerPointerChar) {
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
    int from = 2;
    int to = 5;
    char **result = segment_pointer_pointer_char(target, from, to);

	ASSERT_EQUAL(4, length_pointer_pointer_char(result));
    ASSERT_STR("brown|fox|jumps|over", string_join(result, "|"));
}