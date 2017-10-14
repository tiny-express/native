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
#include "../String.hpp"
#include "../Test.hpp"

TEST (KernelStringConvert, StringFromChar) {
	// Input a number character to convert from char to string
	char number_character = '6';
	
	// The result of stringFromChar
	char *result = stringFromChar(number_character);
	
	// Make a comparison between number_character and result
	assertEquals("6", result);
	free(result);
	
	// Input a null character to convert from char to string
	char null_character = '\0';
	
	// The result of stringFromChar
	result = stringFromChar(null_character);
	
	// Make a comparison between number_character and result
	assertEquals("", result);
	free(result);
}

TEST (KernelStringConvert, StringFromShort) {
	// Input a positive short number to convert from short to string
	int number = 123;
	
	// The expected result
	auto expect = (string) "123";
	
	// The real result
	char *result = stringFromShort(number);
	
	// Make a comparison between the expected result and the real result
	assertEquals(expect, result);
	free(result);
	
	// Input a negative short number to convert from short to string
	int number2 = -123;
	
	// The expected result
	auto expect2 = (string) "-123";
	
	// The real result
	char *result2 = stringFromShort(number2);
	
	// Make a comparison between the expected result and the real result
	assertEquals(expect2, result2);
	free(result2);
}

TEST (KernelStringConvert, StringFromInt) {
	// Input a 0 value to convert from int to string
	int input = 0;
	
	// The expect result
	char *expect = (string) "0";
	
	// The real result
	char *result = stringFromInt(input);
	
	// Make a comparison between the expect result and the real result
	assertEquals(expect, result);
	free(result);
	
	// Input a 1 value to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input1 = 1;
	auto expect1 = (string) "1";
	char *result1 = stringFromInt(input1);
	assertEquals(expect1, result1);
	free(result1);
	
	// Input a random positive value of type int such as 10 to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input2 = 10;
	auto expect2 = (string) "10";
	char *result2 = stringFromInt(input2);
	assertEquals(expect2, result2);
	free(result2);
	
	// Input the maximum value of type int to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input3 = 2147483647;
	auto expect3 = (string) "2147483647";
	char *result3 = stringFromInt(input3);
	assertEquals(expect3, result3);
	free(result3);
	
	// Input the minimum value of type int to convert from int to string
	// Than make a comparison between the expect result and the real result
	int input4 = -2147483647;
	auto expect4 = (string) "-2147483647";
	char *result4 = stringFromInt(input4);
	assertEquals(expect4, result4);
	free(result4);
}

TEST (KernelStringConvert, StringFromLong) {
	// Input the maximum value of type long to convert from long to string
	auto input = (long) 393239259234023474;
	
	// The expected result
	auto expect = (string) "393239259234023474";
	
	// The real result
	char *result = stringFromLong(input);
	
	// Than make a comparison between the expect result and the real result
	assertEquals(expect, result);
	free(result);
	
	// Input the minimum value of type long to convert from long to string
	// Than make a comparison between the expect result and the real result
	long input1 = -2147483647;
	auto expect1 = (string) "-2147483647";
	char *result1 = stringFromLong(input1);
	assertEquals(expect1, result1);
	free(result1);
}

TEST (KernelStringConvert, StringFromFloat) {
	// Input a positive value of type float to convert from float to string
	float input = 12.56;
	
	// The expected result
	auto expect = (string) "12.56";
	
	// The real result
	char *result = stringFromFloat(input);
	
	// Make a comparison between the expected result and the real result
	assertEquals(expect, result);
	free(result);
	
	// Input a negative value of type float to convert from float to string
	// Than make a comparison between the expected result and the real result
	auto input1 = (float) -1.56799;
	auto expect1 = (string) "-1.56799";
	char *result1 = stringFromFloat(input1);
	assertEquals(expect1, result1);
	free(result1);
}

TEST (KernelStringConvert, StringFromDouble) {
	// Input a positive value of type double to convert from double to string
	double input = 125.569123;
	
	// The expected result
	auto expect = (string) "125.569123000000005";
	
	// The real result
	char *result = stringFromDouble(input);
	
	// Make a comparison between the expected result and the real result
	assertEquals(expect, result);
	free(result);
	
	// Input a negative value of type double to convert from double to string
	// Than make a comparison between the expected result and the real result
	double input1 = -125.56123;
	auto expect1 = (string) "-125.561229999999995";
	char *result1 = stringFromDouble(input1);
	assertEquals(expect1, result1);
	free(result1);
}

TEST (KernelStringConvert, StringToShort) {
	// Make a comparison between 0 and result of stringToShort(nullptr)
	assertEquals(0, stringToShort(nullptr));
	
	// Input a positive value of type short to convert from short to string
	char *input = (string) "123";
	
	// The result
	short result = stringToShort(input);
	
	// Make a comparison between the input and the result
	assertEquals(123, result);
	
	// Input a negative value of type short to convert from short to string
	// Than make a comparison between the input and the result
	auto input1 = (string) "-123";
	short result1 = stringToShort(input1);
	assertEquals(-123, result1);
}

TEST (KernelStringConvert, StringToInt) {
	// Input a string representing the positive number to convert from string to int
	auto input = (string) "123\0";
	
	// The result of stringToInt
	int result = stringToInt(input);
	
	// Than make a comparison between the result and the right answer
	assertEquals(123, result);
	
	// Input a string representing negative number to convert from string to int
	// Than make a comparison between the result and the right answer
	auto input1 = (string) "-123\0";
	int result1 = stringToInt(input1);
	assertEquals(-123, result1);
	
	// Input a string representing 0 number to convert from string to int
	// Than make a comparison between the result and the right answer
	auto input2 = (string) "\0";
	int result2 = stringToInt(input2);
	assertEquals(0, result2);
	
	// Input a string representing nothing to convert from string to int
	// Than make a comparison between the result and the right answer
	auto input3 = (string) "";
	int result3 = stringToInt(input3);
	assertEquals(0, result3);
	
	// Input a string representing positive value of type float to convert from string to int
	// Than make a comparison between the result and the right answer
	auto input4 = (string) "12.321";
	int result4 = stringToInt(input4);
	assertEquals(12, result4);
	
	// Input a string representing characters to convert from string to int
	// Than make a comparison between the result and the right answer
	auto input5 = (string) "kajshdkashd";
	int result5 = stringToInt(input5);
	assertEquals(0, result5);
	
	// Input a string representing nullptr to convert from string to int
	// Than make a comparison between the result and the right answer
	char *input6 = nullptr;
	int result6 = stringToInt(input6);
	assertEquals(0, result6);
	
	// Input a string representing characters to convert from string to int
	// Than make a comparison between the result and the right answer
	auto input7 = (string) "foodtiny.com";
	int result7 = stringToInt(input7);
	assertEquals(0, result7);
}

TEST (KernelStringConvert, StringToLong) {
	// Input a string representing the positive number to convert from string to long
	auto input = (string) "21474836";
	
	// The result
	long result = stringToLong(input);
	
	// Than make a comparison between the result and the right answer
	assertEquals(21474836, result);
	
	// Input a string representing the negative number to convert from string to long
	// Than make a comparison between the result and the right answer
	auto input1 = (string) "-21474836";
	long result1 = stringToLong(input1);
	assertEquals(-21474836, result1);
	
	// Input a string representing characters to convert from string to long
	// Than make a comparison between the result and the right answer
	auto input2 = (string) "Hello world";
	long result2 = stringToLong(input2);
	assertEquals(0, result2);
}

TEST (KernelStringConvert, StringToFloat) {
	// Input a string representing a positive value of type float to convert from string to float
	auto input = (string) "12.56";
	
	// The result
	float result = stringToFloat(input);
	
	// Than make a comparison between the result and the right answer
	assertEquals(12.56, result);
	
	// Input a string representing a negative value of type float to convert from string to float
	// Than make a comparison between the result and the right answer
	auto input1 = (string) "-1.56799";
	float result1 = stringToFloat(input1);
	assertEquals(-1.56799, result1);
}

TEST (KernelStringConvert, StringToDouble) {
	// Input a string representing a positive value of type double to convert from string to double
	auto input = (string) "125.569123";
	
	// The result
	double result = stringToDouble(input);
	
	// Than make a comparison between the result and the right answer
	assertEquals(125.569123, result);
	
	// Input a string representing a negative value of type double to convert from string to double
	// Than make a comparison between the result and the right answer
	auto input1 = (string) "-125.56123";
	double result1 = stringToDouble(input1);
	assertEquals(-125.56123, result1);
}

TEST (KernelStringConvert, StringToBoolean) {
	// Input a string representing 1 to convert from string to boolean
	char *target0 = (string) "1";
	
	// The result
	int boolean0 = stringToBoolean(target0);
	
	// Check if the result is TRUE or not
	assertTrue(boolean0);
	
	// Input a string representing "TRUE" to convert from string to boolean
	// Than check if the result is TRUE or not
	auto target1 = (string) "TRUE";
	int boolean1 = stringToBoolean(target1);
	assertTrue(boolean1);
	
	// Input a string representing "True" to convert from string to boolean
	// Than check if the result is TRUE or not
	auto target2 = (string) "True";
	int boolean2 = stringToBoolean(target2);
	assertTrue(boolean2);
	
	// Input a string representing "true" to convert from string to boolean
	// Than check if the result is TRUE or not
	auto target3 = (string) "true";
	int boolean3 = stringToBoolean(target3);
	assertTrue(boolean3);
	
	// Input a string representing "FALSE" to convert from string to boolean
	// Than check if the result is FALSE or not
	auto target4 = (string) "FALSE";
	int boolean4 = stringToBoolean(target4);
	assertFalse(boolean4);
	
	// Input a string representing "False" to convert from string to boolean
	// Than check if the result is FALSE or not
	auto target5 = (string) "False";
	int boolean5 = stringToBoolean(target5);
	assertFalse(boolean5);
	
	// Input a string representing "False" to convert from string to boolean
	// Than check if the result is FALSE or not
	auto target6 = (string) "false";
	int boolean6 = stringToBoolean(target6);
	assertFalse(boolean6);
}

TEST (KernelStringConvert, StringFromBoolean) {
	// Input value 0 to convert from Boolean to String
	int value = 0;
	
	// The expected result
	
	auto expect = (string) "false";
	
	// The real result of stringFromBoolean
	char *result = stringFromBoolean(value);
	
	// Make a comparison between the expected result and the real result
	assertEquals(expect, result);
	free(result);
	
	// Input value 1 to convert from Boolean to String
	// Than make a comparison between the expected result and the real result
	value = 1;
	expect = (string) "true";
	result = stringFromBoolean(value);
	assertEquals(expect, result);
	free(result);
	
	// Input a difference value like 10 to convert from Boolean to String
	// Than make a comparison between the expected result and the real result
	value = 10;
	
	expect = (string) "true";
	result = stringFromBoolean(value);
	assertEquals(expect, result);
	free(result);
}
