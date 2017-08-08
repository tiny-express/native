/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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
#include "../string.h"
#include "../test.h"

TEST (KernelString, ConvertFromChar) {
	// Input a number character to convert from char to string
	char number_character = '6';
	
	// The result of string_from_char
	char *result = string_from_char(number_character);
	
	// Make a comparison between number_character and result
	ASSERT_STR("6", result);
	free(result);
	
	// Input a null character to convert from char to string
	char null_character = '\0';
	
	// The result of string_from_char
	result = string_from_char(null_character);
	
	// Make a comparison between number_character and result
	ASSERT_STR("", result);
	free(result);
}

TEST (KernelString, ConvertFromShort) {
	// Input a positive short number to convert from short to string
	int number = 123;
	
	// The expected result
	char *expect = "123";
	
	// The real result
	char *result = string_from_short(number);
	
	// Make a comparison between the expected result and the real result
	ASSERT_STR(expect, result);
	free(result);
	
	// Input a negative short number to convert from short to string
	int number2 = -123;
	
	// The expected result
	char *expect2 = "-123";
	
	// The real result
	char *result2 = string_from_short(number2);
	
	// Make a comparison between the expected result and the real result
	ASSERT_STR(expect2, result2);
	free(result2);
}

TEST (KernelString, ConvertFromInt) {
	// Input a 0 value to convert from int to string
	int input = 0;
	
	// The expect result
	char *expect = "0";
	
	// The real result
	char *result = string_from_int(input);
	
	// Make a comparison between the expect result and the real result
	ASSERT_STR(expect, result);
	free(result);
	
	// Input a 1 value to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input1 = 1;
	char *expect1 = "1";
	char *result1 = string_from_int(input1);
	ASSERT_STR(expect1, result1);
	free(result1);
	
	// Input a random positive value of type int such as 10 to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input2 = 10;
	char *expect2 = "10";
	char *result2 = string_from_int(input2);
	ASSERT_STR(expect2, result2);
	free(result2);
	
	// Input the maximum value of type int to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input3 = 2147483647;
	char *expect3 = "2147483647";
	char *result3 = string_from_int(input3);
	ASSERT_STR(expect3, result3);
	free(result3);
	
	// Input the minimum value of type int to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input4 = -2147483647;
	char *expect4 = "-2147483647";
	char *result4 = string_from_int(input4);
	ASSERT_STR(expect4, result4);
	free(result4);
}

TEST (KernelString, ConvertFromLong) {
	// Input the maximum value of type long to convert from long to string
	long input = (long) 393239259234023474;
	
	// The expected result
	char *expect = "393239259234023474";
	
	// The real result
	char *result = string_from_long(input);
	
	// Than make a comparison between the expect result and the real result
	ASSERT_STR(expect, result);
	free(result);
	
	// Input the minimum value of type long to convert from long to string
	// Than make a comparison between the expect result and the real result
	long input1 = -2147483647;
	char *expect1 = "-2147483647";
	char *result1 = string_from_long(input1);
	ASSERT_STR(expect1, result1);
	free(result1);
}

TEST (KernelString, ConvertFromFloat) {
	// Input a positive value of type float to convert from float to string
	float input = 12.56;
	
	// The expected result
	char *expect = "12.56";
	
	// The real result
	char *result = string_from_float(input);
	
	// Make a comparison between the expected result and the real result
	ASSERT_STR(expect, result);
	free(result);
	
	// Input a negative value of type float to convert from float to string
	// Than make a comparison between the expected result and the real result
	float input1 = -1.56799;
	char *expect1 = "-1.56799";
	char *result1 = string_from_float(input1);
	ASSERT_STR(expect1, result1);
	free(result1);
}

TEST (KernelString, ConvertFromDouble) {
	// Input a positive value of type double to convert from double to string
	double input = 125.569123;
	
	// The expected result
	char *expect = "125.569123";
	
	// The real result
	char *result = string_from_double(input);
	
	// Make a comparison between the expected result and the real result
	ASSERT_STR(expect, result);
	free(result);
	
	// Input a negative value of type double to convert from double to string
	// Than make a comparison between the expected result and the real result
	double input1 = -125.56123;
	char *expect1 = "-125.56123";
	char *result1 = string_from_double(input1);
	ASSERT_STR(expect1, result1);
	free(result1);
}

TEST (KernelString, ConvertToShort) {
	// Make a comparison between 0 and result of string_to_short(NULL)
	ASSERT_EQUAL(0, string_to_short(NULL));
	
	// Input a positive value of type short to convert from short to string
	char *input = "123";
	
	// The result
	short result = string_to_short(input);
	
	// Make a comparison between the input and the result
	ASSERT_EQUAL(123, result);
	
	// Input a negative value of type short to convert from short to string
	// Than make a comparison between the input and the result
	char *input1 = "-123";
	short result1 = string_to_short(input1);
	ASSERT_EQUAL(-123, result1);
}

TEST (KernelString, ConvertToInt) {
	// Input a string representing the positive number to convert from string to int
	char *input = "123\0";
	
	// The result of string_to_int
	int result = string_to_int(input);
	
	// Than make a comparison between the result and the right answer
	ASSERT_EQUAL(123, result);
	
	// Input a string representing negative number to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input1 = "-123\0";
	int result1 = string_to_int(input1);
	ASSERT_EQUAL(-123, result1);
	
	// Input a string representing 0 number to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input2 = "\0";
	int result2 = string_to_int(input2);
	ASSERT_EQUAL(0, result2);
	
	// Input a string representing nothing to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input3 = "";
	int result3 = string_to_int(input3);
	ASSERT_EQUAL(0, result3);
	
	// Input a string representing positive value of type float to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input4 = "12.321";
	int result4 = string_to_int(input4);
	ASSERT_EQUAL(12, result4);
	
	// Input a string representing characters to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input5 = "kajshdkashd";
	int result5 = string_to_int(input5);
	ASSERT_EQUAL(0, result5);
	
	// Input a string representing NULL to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input6 = NULL;
	int result6 = string_to_int(input6);
	ASSERT_EQUAL(0, result6);
	
	// Input a string representing characters to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input7 = "foodtiny.com";
	int result7 = string_to_int(input7);
	ASSERT_EQUAL(0, result7);
}

TEST (KernelString, ConvertToLong) {
	// Input a string representing the positive number to convert from string to long
	char *input = "21474836";
	
	// The result
	long result = string_to_long(input);
	
	// Than make a comparison between the result and the right answer
	ASSERT_EQUAL(21474836, result);
	
	// Input a string representing the negative number to convert from string to long
	// Than make a comparison between the result and the right answer
	char *input1 = "-21474836";
	long result1 = string_to_long(input1);
	ASSERT_EQUAL(-21474836, result1);
	
	// Input a string representing characters to convert from string to long
	// Than make a comparison between the result and the right answer
	char *input2 = "Hello world";
	long result2 = string_to_long(input2);
	ASSERT_EQUAL(0, result2);
}

TEST (KernelString, ConvertToFloat) {
	// Input a string representing a positive value of type float to convert from string to float
	char *input = "12.56";
	
	// The result
	float result = string_to_float(input);
	
	// Than make a comparison between the result and the right answer
	ASSERT_EQUAL(12.56, result);
	
	// Input a string representing a negative value of type float to convert from string to float
	// Than make a comparison between the result and the right answer
	char *input1 = "-1.56799";
	float result1 = string_to_float(input1);
	ASSERT_EQUAL(-1.56799, result1);
}

TEST (KernelString, ConvertToDouble) {
	// Input a string representing a positive value of type double to convert from string to double
	char *input = "125.569123";
	
	// The result
	double result = string_to_double(input);
	
	// Than make a comparison between the result and the right answer
	ASSERT_EQUAL(125.569123, result);
	
	// Input a string representing a negative value of type double to convert from string to double
	// Than make a comparison between the result and the right answer
	char *input1 = "-125.56123";
	double result1 = string_to_double(input1);
	ASSERT_EQUAL(-125.56123, result1);
}

TEST (KernelString, ConvertToBoolean) {
	// Input a string representing 1 to convert from string to boolean
	char *target0 = "1";
	
	// The result
	int boolean0 = string_to_boolean(target0);
	
	// Check if the result is TRUE or not
	ASSERT_TRUE(boolean0);
	
	// Input a string representing "TRUE" to convert from string to boolean
	// Than check if the result is TRUE or not
	char *target1 = "TRUE";
	int boolean1 = string_to_boolean(target1);
	ASSERT_TRUE(boolean1);
	
	// Input a string representing "True" to convert from string to boolean
	// Than check if the result is TRUE or not
	char *target2 = "True";
	int boolean2 = string_to_boolean(target2);
	ASSERT_TRUE(boolean2);
	
	// Input a string representing "true" to convert from string to boolean
	// Than check if the result is TRUE or not
	char *target3 = "true";
	int boolean3 = string_to_boolean(target3);
	ASSERT_TRUE(boolean3);
	
	// Input a string representing "FALSE" to convert from string to boolean
	// Than check if the result is FALSE or not
	char *target4 = "FALSE";
	int boolean4 = string_to_boolean(target4);
	ASSERT_FALSE(boolean4);
	
	// Input a string representing "False" to convert from string to boolean
	// Than check if the result is FALSE or not
	char *target5 = "False";
	int boolean5 = string_to_boolean(target5);
	ASSERT_FALSE(boolean5);
	
	// Input a string representing "False" to convert from string to boolean
	// Than check if the result is FALSE or not
	char *target6 = "false";
	int boolean6 = string_to_boolean(target6);
	ASSERT_FALSE(boolean6);
}

TEST (KernelString, ConvertFromBoolean) {
	// Input value 0 to convert from Boolean to String
	int value = 0;
	
	// The expected result
	
	char *expect = "false";
	
	// The real result of string_from_boolean
	char *result = string_from_boolean(value);
	
	// Make a comparison between the expected result and the real result
	ASSERT_STR(expect, result);
	free(result);
	
	// Input value 1 to convert from Boolean to String
	// Than make a comparison between the expected result and the real result
	value = 1;
	expect = "true";
	result = string_from_boolean(value);
	ASSERT_STR(expect, result);
	free(result);
	
	// Input a difference value like 10 to convert from Boolean to String
	// Than make a comparison between the expected result and the real result
	value = 10;
	
	expect = "true";
	result = string_from_boolean(value);
	ASSERT_STR(expect, result);
	free(result);
}
