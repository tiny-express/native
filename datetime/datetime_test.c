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

//#include "../builtin.h"
//#include "../unit_test.h"
//
//TEST (DateTime, Timestamp) {
//	long first_time = timestamp();
//	int maxN = 10000000;
//	int i = 0;
//	int counter = 0;
//	for (i = 0; i < maxN; i++) {
//		counter++;
//	}
//	long last_time = timestamp();
//	ASSERT_EQUAL(maxN, counter);
//	// Time is greater than 9 ms
//	ASSERT_TRUE(( last_time - first_time ) / ( 1000 * 1000 ) > 9);
//}
//#endif
//
//TEST (DateTime, Format) {
//
//	long timestamp = 1473765499;
//	char *format = "d/m/y";
//	char *result1 = date(timestamp, format);
//	ASSERT_STR("13/09/2016", result1);
//	free(result1);
//
//	timestamp = 1511208660;
//	char *result2 = date(timestamp, format);
//	ASSERT_STR("20/11/2017", result2);
//	free(result2);
//
//	format = "y-m-d";
//	char *result3 = date(timestamp, format);
//	ASSERT_STR("2017-11-20", result3);
//	free(result3);
//}