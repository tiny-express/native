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

#include <time.h>
#include <stdlib.h>
#include "../datetime.h"
#include "../string.h"

/**
 * Format timestamp to date
 *
 * @param timestamp
 * @param format
 * @return
 */
char *date(long timestamp, char *format) {
	char *date_format = string_replace(format, "D", "%d");
	char *date_format2 = string_replace(date_format, "d", "%d");
	free(date_format);
	
	char *date_format3 = string_replace(date_format2, "M", "%m");
	free(date_format2);
	
	char *date_format4 = string_replace(date_format3, "m", "%m");
	free(date_format3);
	
	char *date_format5 = string_replace(date_format4, "Y", "%Y");
	free(date_format4);
	
	char *date_format6 = string_replace(date_format5, "y", "%Y");
	free(date_format5);
	
	char *result = calloc(11, sizeof(char));
	//strftime(result, 11, date_format6, gmtime(&timestamp));
	free(date_format6);
	
	return result;
}

/**
 * Return timestamp from 1970
 * Apple and Linux have difference way to retrieve timestamp
 *
 * @return long
 */
long timestamp() {
#ifdef __APPLE__
	double timebase = 0.0;
	mach_timebase_info_data_t tb = { 0 };
	mach_timebase_info(&tb);
	timebase = tb.numer;
	timebase = timebase / tb.denom;
	uint64_t current = mach_absolute_time() * timebase;
	return (long) current;
#endif
#ifdef __linux__
	struct timespec tsp;
	clock_gettime(0, &tsp);
	return (long) tsp.tv_sec * 1000000000 + tsp.tv_nsec;
#endif
    return 0;
}