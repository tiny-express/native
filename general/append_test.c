#include <stdio.h>
#include "../builtin.h"
#include "../unit_test.h"

TEST(Builtin_Append, PointerChar) {
	char *target[] = {
			(char *) "The",
			(char *) "quick",
			(char *) "brown",
			(char *) "fox",
			(char *) "jumps",
			(char *) "over",
			(char *) "the",
			(char *) "lazy",
	        '\0'
	};
	char *append = "dog";
	ASSERT_EQUAL(8, length_pointer_pointer_char(target));
	char **result = append_pointer_char(target, append);
	ASSERT_EQUAL(9, length_pointer_pointer_char(result));
	ASSERT_STR("The", result[0]);
	ASSERT_STR("quick", result[1]);
    ASSERT_STR("brown", result[2]);
    ASSERT_STR("fox", result[3]);
    ASSERT_STR("jumps", result[4]);
    ASSERT_STR("over", result[5]);
    ASSERT_STR("the", result[6]);
    ASSERT_STR("lazy", result[7]);
    ASSERT_STR("dog", result[8]);

    append = "";
    result = append_pointer_char(target, append);
	ASSERT_EQUAL(8, length_pointer_pointer_char(target));
}


