#include "../../builtin/builtin.h"
#include "../unit_test.h"

TEST(Builtin_Length, PointerChar) {
	char* data = "Hello world";
	ASSERT_EQUAL(11, length_pointer_char(data));
}

TEST(Builtin_Length, PointerShort) {
	short input[] = {1, 2, 3, 4, 5};
	//ASSERT_EQUAL(5, length_pointer_short(input));
    short input2[] = {1, 0, 2};
    //ASSERT_EQUAL(3, length_pointer_short(input2));
}

TEST(Builtin_Length, PointerInt) {
	int input[] = {1, 2, 3, 4, 5};
	//ASSERT_EQUAL(5, length_pointer_int(input));
    int input2[] = {1, 0, 2};
    //ASSERT_EQUAL(3, length_pointer_int(input2));
}

TEST(Builtin_Length, PointerLong) {
	long input[] = {1234, 223, 3423, 4432, 5423};
	//ASSERT_EQUAL(5, length_pointer_long(input));
    long input2[] = {1425, 2, 0, 4543};
    //ASSERT_EQUAL(4, length_pointer_long(input2));
}

TEST(Builtin_Length, PointerDouble) {
	double input[] = {1.234, 2, 3.66, 4, 5};
	//ASSERT_EQUAL(5, length_pointer_double(input));
    double input2[] = {1.234, 2, 3.66, 0};
    //ASSERT_EQUAL(4, length_pointer_double(input2));
}

TEST(Builtin_Length, PointerFloat) {
	float input[] = {1.2, 2, 3.5, 4, 5};
	//ASSERT_EQUAL(5, length_pointer_float(input));
    float input2[] = {1.3, 2, 0, 4, 5.5};
    //ASSERT_EQUAL(5, length_pointer_float(input2));
}

TEST(Builtin_Length, PointerConstChar) {
	const char* data = "Hello world";
	ASSERT_EQUAL(11, length_pointer_constant_char(data));
}

TEST(Builtin_Length, PointerPointerChar) {
	char *data_raw[] = {
		(char*) "abc",
		(char*) "abd",
		(char*) "abf",
		(char*) "xyz",
		(char*) "123",
		(char*) "3456",
		'\0'
	};
	char **data1 = (char**) data_raw;
	ASSERT_EQUAL(6, length_pointer_pointer_char(data1));
	// Dynamic string
	int NUM = 135;
	char** data2 = (char**) calloc(NUM + 1, sizeof(char*));
	for (int i=0; i<NUM; i++) {
		data2[i] = (char*) "test";
	}
	data2[NUM] = '\0';
	ASSERT_EQUAL(NUM, length_pointer_pointer_char(data2));
	free(data2);
}

TEST(Builtin_Length, Short) {
	short input = 0;
	ASSERT_EQUAL(1, length_short(input));
	input = 123;
	ASSERT_EQUAL(3, length_short(input));
}

TEST(Builtin_Length, Int) {
	int input = 0;
	ASSERT_EQUAL(1, length_int(input));
	input = 123;
	ASSERT_EQUAL(3, length_int(input));
}

TEST(Builtin_Length, Long) {
	long input = 0;
	ASSERT_EQUAL(1, length_long(input));
	input = 123456;
	ASSERT_EQUAL(6, length_long(input));
}

TEST(Builtin_Length, Double) {
	double input = 0;
	ASSERT_EQUAL(1, length_double(input));
	input = 123.456;
	ASSERT_EQUAL(7, length_double(input));
}

TEST(Builtin_Length, Float) {
	float input = 1.23;
	ASSERT_EQUAL(4, length_float(input));
	input = 0.345;
	ASSERT_EQUAL(5, length_float(input));
}


