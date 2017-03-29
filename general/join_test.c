#include "../../builtin/builtin.h"
#include "../unit_test.h"

TEST(Builtin_Join, PointerType) {
    int intArray1[] = {1, 2, 3, 4, 5, NULL};
    //ASSERT_STR("12345", join_pointer_int(intArray1));
	int intArray2[] = { 13456, 21, 36, -12, 65 };
	//ASSERT_STR("134562136-1265", join_pointer_int((char*) intArray2));
}

TEST(Builtin_Join, DelimPointerType) {
    int intArray[] = {1, 2, 3, 4, 5, NULL};
    ASSERT_STR("1|2|3|4|5", join_delim_pointer_int(intArray, "|"));
}

TEST(Builtin_Join, PointerPointerChar) {
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
    char *expect = "Thequickbrownfoxjumpsoverthelazydog";
    ASSERT_STR(expect, join_pointer_pointer_char(target));
}

TEST(Builtin_Join, DelimPointerPointerChar) {
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
	ASSERT_STR(expect, join_delim_pointer_pointer_char(target, delim));
}
