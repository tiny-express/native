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

#ifndef NATIVE_DATETIME_H
#define NATIVE_DATETIME_H

#include "platform.h"

#ifdef LINUX

#include <stdint.h>

#endif

#ifdef DARWIN
#include <mach/mach_time.h>
#endif

#include "type.h"
#include <time.h>

#define SEC_PER_MIN         60
#define SEC_PER_HOUR        3600
#define SEC_PER_DAY         86400
#define MOS_PER_YEAR        12
#define EPOCH_YEAR          1970
#define IS_LEAP_YEAR(year)  ( (((year)%4 == 0) && ((year)%100 != 0)) || ((year)%400 == 0) )

static int days_per_month[2][MOS_PER_YEAR] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

static int days_per_year[2] = {
	365, 366
};

/**
 *  Unix time in seconds
 *
 * @param sec
 * @param min
 * @param hrs
 * @param day
 * @param mon
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
	unsigned int year
                                       );

/**
 * Get unix timestamp
 *
 * @return unsigned long
 */
unsigned long timestamp();

/**
 *
 * @param timestamp
 * @param format
 * @return
 */
string date(unsigned long timestamp, char *format);

#endif