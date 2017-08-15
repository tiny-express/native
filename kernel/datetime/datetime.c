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
#include "../platform.h"

#ifdef WINDOWS
#include <windows.h>
#endif

#include "../datetime.h"
#include "../string.h"

/**
 * Format timestamp to date
 *
 * @param timestamp
 * @param format
 * @return
 */
string date(unsigned long timestamp, string format) {
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
	strftime(result, 11, date_format6, gmtime(&timestamp));
	free(date_format6);
	
	return result;
}

#ifdef WINDOWS
/**
 *
 * @param millisecond
 * @param second
 * @param minute
 * @param hour
 * @param day
 * @param month
 * @param year
 * @return
 */
unsigned long unix_time_in_milliseconds(
		unsigned int millisecond,
		unsigned int second,
		unsigned int minute,
		unsigned int hour,
		unsigned int day,
		unsigned int month,
		unsigned int year)
{
	unsigned long ts = 0;
	//  Add up the seconds from all prev years, up until this year.
	unsigned int years = 0;
	unsigned int leap_years = 0;
	int y_k;
	for (y_k  = EPOCH_YEAR; y_k<year; y_k++ ) {
		if( IS_LEAP_YEAR( y_k ) ) {
			leap_years++;
		} else {
			years++;
		}
	}
	ts += ( (years*days_per_year[0]) + (leap_years*days_per_year[1]) ) * SEC_PER_DAY;
	//  Add up the seconds from all prev days this year, up until today.
	unsigned int year_index = (IS_LEAP_YEAR( year )) ? 1 : 0;
	int mo_k;
	for (mo_k = 0; mo_k<(month - 1); mo_k++ ) { //  days from previous months this year
		ts += days_per_month[ year_index ][ mo_k ] * SEC_PER_DAY;
	}
	ts += (day-1) * SEC_PER_DAY; // days from this month
	//  Calculate seconds elapsed just today.
	ts += hour * SEC_PER_HOUR;
	ts += minute * SEC_PER_MIN;
	ts += second;
	ts = ts * 1000 + millisecond;
	return ts;
}
#endif

/**
 * Return timestamp from 1970
 * Apple and Linux have difference way to retrieve timestamp
 *
 * @return long
 */
unsigned long timestamp() {
#ifdef OSX
	double timebase = 0.0;
	mach_timebase_info_data_t tb = { 0 };
	mach_timebase_info(&tb);
	timebase = tb.numer;
	timebase = timebase / tb.denom;
	uint64_t current = mach_absolute_time() * timebase;
	return (long) current;
#endif
#ifdef LINUX
	struct timespec tsp;
	clock_gettime(0, &tsp);
	return (long) tsp.tv_sec * 1000000000 + tsp.tv_nsec;
#endif
#ifdef WINDOWS
	SYSTEMTIME current_time;
	GetSystemTime(&current_time);
	unsigned long timestamp_in_millisecond = unix_time_in_milliseconds(
			current_time.wMilliseconds,
			current_time.wSecond,
			current_time.wMinute,
			current_time.wHour,
			current_time.wDay,
			current_time.wMonth,
			current_time.wYear
	);
	// Timestamp should be in nano seconds
	return timestamp_in_millisecond * 1000;
#endif
	return 0;
}