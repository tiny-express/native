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
#include "../datetime.h"
#include "../test.h"

TEST (KernelDateTime, UnixTimestampInMilliseconds) {
#ifdef WINDOWS
	unsigned int millisecond = 123;
	unsigned int second = 3;
	unsigned int minute = 20;
	unsigned int hour = 17;
	unsigned int day  = 16;
	unsigned int month = 7;
	unsigned int year = 2017;
	unsigned long timestamp = unix_time_in_milliseconds(
			millisecond,
			second,
			minute,
			hour,
			day,
			month,
			year
	);
	ASSERT_EQUAL(timestamp, 1500225603123);
#endif
}

TEST (KernelDateTime, TimestampInNanoSeconds) {
	long first_time = timestamp();
	ASSERT_TRUE(first_time > 1500198318489000);
	int maxN = 20000000;
	int i = 0;
	int counter = 0;
	for (i = 0; i < maxN; i++) {
		counter++;
		counter--;
		counter++;
	}
	long last_time = timestamp();
	ASSERT_EQUAL(maxN, counter);
	unsigned int delta = ( last_time - first_time ) / 1000;
	ASSERT_TRUE(delta > 50);
}

TEST (KernelDateTime, Format) {
	long timestamp = 1473765499;
	string format = "d/m/y";
	string result1 = date(timestamp, format);
	ASSERT_STR("13/09/2016", result1);
	free(result1);
	
	timestamp = 1511208660;
	char *result2 = date(timestamp, format);
	ASSERT_STR("20/11/2017", result2);
	free(result2);
	
	format = "y-m-d";
	char *result3 = date(timestamp, format);
	ASSERT_STR("2017-11-20", result3);
	free(result3);
}