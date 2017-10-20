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

#include "../DateTime.hpp"
#include "../Test.hpp"

TEST (KernelDateTime, UnixTimestampInMilliseconds) {
#ifdef WIN
	unsigned int millisecond = 123;
	unsigned int second = 3;
	unsigned int minute = 20;
	unsigned int hour = 17;
	unsigned int day  = 16;
	unsigned int month = 7;
	unsigned int year = 2017;
	unsigned long timestamp = unixTimeInMilliseconds(
			millisecond,
			second,
			minute,
			hour,
			day,
			month,
			year
	);
	assertEquals(1500225603123, (long) timestamp);
#endif
}

TEST (KernelDateTime, TimestampInNanoSeconds) {
    // Timestamp in seconds is 1506237734
    // but nano seconds we need multiply with 1,000,000,000
    // so it will be look likes this 1506237734000000000
    // length of timestamp in nano seconds is 19 digits
	long timestamps = timestamp();
	assertTrue(timestamps > 1506237163070843650);
    assertTrue(timestamps < 2506237163070843650);
}

TEST (KernelDateTime, Format) {
	long timestamp = 1473765499;
	auto format = (string) "d/m/y";
	string result1 = date(timestamp, format);
	assertEquals("13/09/2016", result1);
	free(result1);

	timestamp = 1511208660;
	char *result2 = date(timestamp, format);
	assertEquals("20/11/2017", result2);
	free(result2);

	format = (string) "y-m-d";
	char *result3 = date(timestamp, format);
	assertEquals("2017-11-20", result3);
	free(result3);
}