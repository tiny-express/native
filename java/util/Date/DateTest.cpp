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

extern "C" {
#include "../../../kernel/test.h"
}

#include "Date.hpp"

using namespace Java::Util;

TEST(JavaUtil, DateConstructor) {
    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);

    // Create variable to test
    Date date;

    // Test Date(). This class return since 1900
    ASSERT_EQUAL(currentTime->tm_year + 1900, date.getYear());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date(long date)
    date = Date(1498042091);  // 2017
    ASSERT_EQUAL(2017, date.getYear());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(sameDate.getYear(), date.getYear());
    ASSERT_EQUAL(sameDate.getMonth(), date.getMonth());
    ASSERT_EQUAL(sameDate.getDate(), date.getDate());
    ASSERT_EQUAL(sameDate.getHours(), date.getHours());
    ASSERT_EQUAL(sameDate.getMinutes(), date.getMinutes());
    ASSERT_EQUAL(sameDate.getSeconds(), date.getSeconds());

    // Test Date::Date(String inputString, String pattern)
    // Create variable to test
    String expected;

    Date   actualDate;
    String actualString;
    String actualFormat;
    String actual;
    String localZone;

    String zone = actualDate.getZone();
#ifdef __unix__
    if (actualDate.getTimezoneOffset() == 0) {
        localZone = "UTC";
    } else {
        localZone = "LMT";
    }
#endif

#ifdef WIN32
    if (actualDate.getTimezoneOffset() == 0) {
        localZone = "GMT";
    } else {
        localZone = "LMT";
    }
#endif

    // Valid case
    expected     = "Thu Jan 09 12:35:34 " + zone + (string) " 2014";
    actualString = "Thu Jan 9 and 2014 12:35:34";
    actualFormat = "%a %b %d and %Y %H:%M:%S";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short date pattern. (en-US)
    expected     = "Mon Feb 13 00:00:00 " + zone + (string) " 2017";
    actualString = "02/13/17";
    actualFormat = "%m/%d/%y";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short date pattern. (en-US)
    expected     = "Mon Feb 13 00:00:00 " + zone + (string) " 2017";
    actualString = "02/13/2017";
    actualFormat = "%m/%d/%Y";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long date pattern. (en-US)
    expected     = "Mon Jun 15 00:00:00 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009";
    actualFormat = "%A, %B %d, %Y";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Full date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 1:45 PM";
    actualFormat = "%A, %B %d, %Y %I:%M %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Full date/time pattern (long time). (en-US)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    actualFormat = "%A, %B %d, %Y %I:%M:%S %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 01:45:30 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45:30";
    actualFormat = "%m/%d/%Y %H:%M:%S";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 01:45:30 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45:30";
    actualFormat = "%m/%d/%Y %H:%M:%S";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45 PM";
    actualFormat = "%m/%d/%Y %I:%M %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (long time). (en-US)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45:30 PM";
    actualFormat = "%m/%d/%Y %I:%M:%S %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Month/day pattern.(en-US)
    expected     = "Fri Jun 15 00:00:00 " + localZone + (string) " 1900";
    actualString = "June 15";
    actualFormat = "%B %d";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Round-trip date/time pattern. (DateTimeKind.Local)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15T13:45:30.0000000-07:00";
    actualFormat = "%Y-%m-%dT%H:%M:%S-%Z";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Round-trip date/time pattern. (DateTimeKind.Utc)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15T13:45:30.0000000Z";
    actualFormat = "%Y-%m-%dT%H:%M:%S%Z";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // TODO(thoangminh): check it
//    // RFC1123 pattern.
//    expected     = "Mon Jun 15 00:00:00 " + zone + (string) " 2009";
//    actualString = "Mon, 15 Jun 2009 20:45:30 GMT";
//    actualFormat = "%A, %d %B %Y %H:%M:%S %Z";
//    actualDate = Date(actualString, actualFormat);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());

    // Sortable date/time pattern. (DateTimeKind.Local)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15T13:45:30";
    actualFormat = "%Y-%m-%dT%H:%M:%S";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short time pattern. (en-US)
    expected     = "Sun Dec 31 13:45:00 " + localZone + (string) " 1899";
    actualString = "1:45 PM";
    actualFormat = "%I:%M %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long time pattern. (en-US)
    expected     = "Sun Dec 31 13:45:30 " + localZone + (string) " 1899";
    actualString = "1:45:30 PM";
    actualFormat = "%I:%M:%S %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Universal sortable date/time pattern. With a DateTime value:
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15 13:45:30Z";
    actualFormat = "%Y-%m-%d %H:%M:%S%p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Universal full date/time pattern. (en-US)
    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 8:45:30 PM";
    actualFormat = "%A, %B %d, %Y %I:%M:%S %p";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Year month pattern. (en-US)
    expected     = "Sun May 31 00:00:00 " + zone + (string) " 2009";
    actualString = "June, 2009";
    actualFormat = "%B, %Y";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 12. Invalid case => Sun Dec 31 00:00:00 LMT 1899
    expected     = "Sun Dec 31 00:00:00 " + localZone + (string) " 1899";
    actualString = "Sat 12 13 10:01:13 " + zone + (string) " 2017";
    actualFormat = "%a %b %d %H:%M:%S " + zone + (string) (string) " %Y";
    actualDate = Date(actualString, actualFormat);
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, DateSetYear) {
    // Create variable to test
    Date date;

    date.setYear(1900);
    ASSERT_EQUAL(1900, date.getYear());

    date.setYear(3000);
    ASSERT_EQUAL(3000, date.getYear());

    date.setYear(1889);
    ASSERT_EQUAL(3789, date.getYear());

    date.setYear(-1);
    ASSERT_EQUAL(1899, date.getYear());

    date.setYear(-900);
    ASSERT_EQUAL(1000, date.getYear());

    date.setYear(0);
    ASSERT_EQUAL(1900, date.getYear());
}

TEST(JavaUtil, DateGetYear) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    ASSERT_EQUAL(currentTime->tm_year + 1900, date.getYear());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(2017, date.getYear());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(2017, date.getYear());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(2017, date.getYear());

    // Test Date(long date)
    Date tempDate = Date(2017, 02, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(2017, date.getYear());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(2017, sameDate.getYear());
}

TEST(JavaUtil, DateSetMonth) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set month = 12 => Year+= 1 , month = 0.
    expected = Date(2018, 0, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(12);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 33 => Year+= 2, month = 9.
    expected = Date(2019, 9, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(33);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 0
    expected = Date(2017, 0, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(0);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -1 => Year-= 1, month = 11.
    expected = Date(2016, 11, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(-1);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -12 => Year-= 1, month = 0.
    expected = Date(2016, 0, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(-12);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -33 => Year-= 3, month = 3.
    expected = Date(2014, 3, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(-33);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetMonth) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    ASSERT_EQUAL(currentTime->tm_mon, date.getMonth());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(02, date.getMonth());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(02, date.getMonth());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(02, date.getMonth());

    // Test Date(long date)
    Date tempDate = Date(2017, 02, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(02, date.getMonth());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(02, sameDate.getMonth());
}

TEST(JavaUtil, DateSetDate) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set month = 3, date = -1 => month = 2, date = 30
    expected = Date(2017, 2, 30, 10, 01, 13);
    actual 	 = Date(2017, 3, 1, 10, 01, 13);
    actual.setDate(-1);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 6, date = -75 => month = 3, date = 16
    expected = Date(2017, 3, 16, 10, 01, 13);
    actual 	 = Date(2017, 6, 1, 10, 01, 13);
    actual.setDate(-75);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 3, date = 0 => month = 2, date = 31
    expected = Date(2017, 2, 31, 10, 01, 13);
    actual 	 = Date(2017, 3, 1, 10, 01, 13);
    actual.setDate(0);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 2, date = 0 => month = 1, date = 28
    expected = Date(2017, 1, 28, 10, 01, 13);
    actual 	 = Date(2017, 2, 1, 10, 01, 13);
    actual.setDate(0);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 5, date = 32 => month = 6, date = 2
    expected = Date(2017, 6, 2, 10, 01, 13);
    actual 	 = Date(2017, 5, 1, 10, 01, 13);
    actual.setDate(32);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetDate) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);;
    ASSERT_EQUAL(currentTime->tm_mday, date.getDate());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(13, date.getDate());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(13, date.getDate());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(13, date.getDate());

    // Test Date(long date)
    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(13, date.getDate());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(13, sameDate.getDate());
}

TEST(JavaUtil, DateSetHours) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set hour = -1 => date -= 1, hour = 23
    expected = Date(2017, 2, 12, 23, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(-1);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = -58 => date -= 3, hour = 14
    expected = Date(2017, 2, 10, 14, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(-58);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 0
    expected = Date(2017, 2, 13, 0, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(0);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 24. Day += 1, hour = 0
    expected = Date(2017, 2, 14, 0, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(24);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 49. Day += 2, hour = 1
    expected = Date(2017, 2, 15, 1, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(49);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetHour) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    ASSERT_EQUAL(currentTime->tm_hour, date.getHours());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(0, date.getHours());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(8, date.getHours());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(8, date.getHours());

    // Test Date(long date)
    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(8, date.getHours());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(8, sameDate.getHours());
}

TEST(JavaUtil, DateSetMinutes) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set minute = -1 => hour -= 1, minute = 59
    expected = Date(2017, 2, 13, 9, 59, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(-1);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected = Date(2017, 2, 13, 10, 0, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(0);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 60 => hour += 1, minute = 0
    expected = Date(2017, 2, 13, 11, 00, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(60);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 150 => hour += 2, minute = 30
    expected = Date(2017, 2, 13, 12, 30, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(150);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetMinutes) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    ASSERT_EQUAL(currentTime->tm_min, date.getMinutes());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(0, date.getMinutes());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(01, date.getMinutes());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(01, date.getMinutes());

    // Test Date(long date)
    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(01, date.getMinutes());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(01, sameDate.getMinutes());
}

TEST(JavaUtil, DateSetSeconds) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set second = -1 => minute -= 1, second = 59
    expected = Date(2017, 2, 13, 10, 00, 59);
    actual   = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(-1);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected = Date(2017, 2, 13, 10, 01, 0);
    actual   = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(0);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = 60 => minute += 1, second = 0
    expected = Date(2017, 2, 13, 10, 02, 00);
    actual   = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(60);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = 150 => minute += 2, second = 30
    expected = Date(2017, 2, 13, 10, 03, 30);
    actual   = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(150);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetSeconds) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    ASSERT_EQUAL(currentTime->tm_sec, date.getSeconds());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(0, date.getSeconds());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(0, date.getSeconds());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date(long date)
    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(13, sameDate.getSeconds());
}

TEST(JavaUtil, DateGetTime) {
    // Create variable to test
    Date date;

    // Test the current local time
    time_t now = time(nullptr);
    ASSERT_EQUAL(now, date.getTime());
}

TEST(JavaUtil, DateSetTime) {
    // Create variable to test
    Date tempDate;
    Date date;
    long tempTime;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    date.setTime(now);
    ASSERT_EQUAL(currentTime->tm_year + 1900, date.getYear());
    ASSERT_EQUAL(currentTime->tm_mon, date.getMonth());
    ASSERT_EQUAL(currentTime->tm_mday, date.getDate());
    ASSERT_EQUAL(currentTime->tm_hour, date.getHours());
    ASSERT_EQUAL(currentTime->tm_min, date.getMinutes());
    ASSERT_EQUAL(currentTime->tm_sec, date.getSeconds());

    // Test Date(int year, int month, int date)
    tempDate = Date(2017, 02, 13);
    tempTime = tempDate.getTime();
    date.setTime(tempTime);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(0, date.getHours());
    ASSERT_EQUAL(0, date.getMinutes());
    ASSERT_EQUAL(0, date.getSeconds());

    // Test Date(int year, int month, int date, int hrs, int min)
    tempDate = Date(2017, 02, 13, 8, 01);
    tempTime = tempDate.getTime();
    date.setTime(tempTime);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());
    ASSERT_EQUAL(0, date.getSeconds());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    tempDate = Date(2017, 02, 13, 8, 01, 13);
    tempTime = tempDate.getTime();
    date.setTime(tempTime);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date(long date)
    tempDate = Date(2017, 2, 13, 8, 1, 13);
    tempTime = tempDate.getTime();
    date.setTime(tempTime);
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(2, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(1, date.getMinutes());
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date sameDate = date;
    tempDate = Date(2017, 02, 13, 8, 01, 13);
    tempTime = tempDate.getTime();
    date.setTime(tempTime);
    Date sameDate = date;
    ASSERT_EQUAL(2017, sameDate.getYear());
    ASSERT_EQUAL(02, sameDate.getMonth());
    ASSERT_EQUAL(13, sameDate.getDate());
    ASSERT_EQUAL(8, sameDate.getHours());
    ASSERT_EQUAL(01, sameDate.getMinutes());
    ASSERT_EQUAL(13, sameDate.getSeconds());
}

TEST(JavaUtil, DateGetDay) {
    // Create variable to test
    Date date;

    // Test Sun - value 0
    date = Date(2017, 8, 17, 8, 01, 13);
    ASSERT_EQUAL(0, date.getDay());

    // Test Mon - value 1
    date = Date(2017, 8, 18, 8, 01, 13);
    ASSERT_EQUAL(1, date.getDay());

    // Test Tue - value 2
    date = Date(2017, 8, 19, 8, 01, 13);
    ASSERT_EQUAL(2, date.getDay());

    // Test Wed - value 3
    date = Date(2017, 8, 13, 8, 01, 13);
    ASSERT_EQUAL(3, date.getDay());

    // Test Thu - value 4
    date = Date(2017, 8, 14, 8, 01, 13);
    ASSERT_EQUAL(4, date.getDay());

    // Test Fri - value 5
    date = Date(2017, 8, 15, 8, 01, 13);
    ASSERT_EQUAL(5, date.getDay());

    // Test Sar - value 6
    date = Date(2017, 8, 16, 8, 01, 13);
    ASSERT_EQUAL(6, date.getDay());
}

TEST(JavaUtil, DateAfter) {
    // Create variable to test
    Date date;
    Date tempDate = Date(2017, 8, 10, 8, 01, 13);;

    // Test case TRUE
    date = Date(2017, 8, 11, 8, 01, 13);
    ASSERT_TRUE(date.after(tempDate));

    date = Date(2017, 9, 13, 8, 01, 13);
    ASSERT_TRUE(date.after(tempDate));

    date = Date(2018, 8, 14, 8, 01, 13);
    ASSERT_TRUE(date.after(tempDate));

    // Test case FALSE
    date = Date(2017, 8, 10, 8, 01, 13);
    ASSERT_FALSE(date.after(tempDate));

    date = Date(2017, 7, 5, 8, 01, 13);
    ASSERT_FALSE(date.after(tempDate));

    date = Date(2016, 8, 5, 8, 01, 13);
    ASSERT_FALSE(date.after(tempDate));
}

TEST(JavaUtil, DateBefore) {
    // Create variable to test
    Date date;
    Date tempDate = Date(2017, 8, 10, 8, 01, 13);;

    // Test case TRUE
    date = Date(2017, 8, 6, 8, 01, 13);
    ASSERT_TRUE(date.before(tempDate));

    date = Date(2017, 7, 5, 8, 01, 13);
    ASSERT_TRUE(date.before(tempDate));

    date = Date(2016, 8, 5, 8, 01, 13);
    ASSERT_TRUE(date.before(tempDate));

    // Test case FALSE
    date = Date(2017, 8, 10, 8, 01, 13);
    ASSERT_FALSE(date.before(tempDate));

    date = Date(2017, 9, 13, 8, 01, 13);
    ASSERT_FALSE(date.before(tempDate));

    date = Date(2018, 8, 14, 8, 01, 13);
    ASSERT_FALSE(date.before(tempDate));
}

TEST(JavaUtil, DateClone) {
    // Create variable to test
    Date tempDate;
    Date date;
    long tempTime;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    date = tempDate.clone();
    ASSERT_EQUAL(currentTime->tm_year + 1900, date.getYear());
    ASSERT_EQUAL(currentTime->tm_mon, date.getMonth());
    ASSERT_EQUAL(currentTime->tm_mday, date.getDate());
    ASSERT_EQUAL(currentTime->tm_hour, date.getHours());
    ASSERT_EQUAL(currentTime->tm_min, date.getMinutes());
    ASSERT_EQUAL(currentTime->tm_sec, date.getSeconds());

    // Test Date(int year, int month, int date)
    tempDate = Date(2017, 02, 13);
    date = tempDate.clone();
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(0, date.getHours());
    ASSERT_EQUAL(0, date.getMinutes());
    ASSERT_EQUAL(0, date.getSeconds());

    // Test Date(int year, int month, int date, int hrs, int min)
    tempDate = Date(2017, 02, 13, 8, 01);
    date = tempDate.clone();
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());
    ASSERT_EQUAL(0, date.getSeconds());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    tempDate = Date(2017, 02, 13, 8, 01, 13);
    date = tempDate.clone();
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date(long date)
    Date temp = Date(2017, 02, 13, 8, 01, 13);
    tempDate = Date(temp.getTime());
    date = tempDate.clone();
    ASSERT_EQUAL(2017, date.getYear());
    ASSERT_EQUAL(02, date.getMonth());
    ASSERT_EQUAL(13, date.getDate());
    ASSERT_EQUAL(8, date.getHours());
    ASSERT_EQUAL(01, date.getMinutes());
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date sameDate = date;
    tempDate = Date(2017, 02, 13, 8, 01, 13);
    date = tempDate.clone();
    Date sameDate = date;
    ASSERT_EQUAL(2017, sameDate.getYear());
    ASSERT_EQUAL(02, sameDate.getMonth());
    ASSERT_EQUAL(13, sameDate.getDate());
    ASSERT_EQUAL(8, sameDate.getHours());
    ASSERT_EQUAL(01, sameDate.getMinutes());
    ASSERT_EQUAL(13, sameDate.getSeconds());
}

TEST(JavaUtil, DateCompareTo) {
    // Create variable to test
    Date date;
    Date temp = Date(2017, 02, 13, 8, 01, 13);

    date = Date(2017, 02, 12, 8, 01, 13);
    ASSERT_EQUAL(-1, date.compareTo(temp));

    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(0, date.compareTo(temp));

    date = Date(2017, 02, 14, 8, 01, 13);
    ASSERT_EQUAL(1, date.compareTo(temp));
}

TEST(JavaUtil, DateHashCode) {
    Date date = Date(2017, 02, 14, 8, 01, 13);
    long expected = date.getTime();
    long actual = date.hashCode();
    ASSERT_EQUAL(expected, actual);
}

TEST(JavaUtil, DateGetTimezoneOffset) {
    // Create variable to test
    Date date;
    int expectedResult;

    // Test System time zone
    time_t now = time(nullptr);
    tm tempLocalTimer = {0};
    tm *localTimer = localtime_r(&now, &tempLocalTimer);
    expectedResult = static_cast<int> (- localTimer->tm_gmtoff / 60);

    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date(long date)
    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());
}

TEST(JavaUtil, DateToLocaleString) {
    // Create variable to test
    Date actualDate;
    string expected;
    String actual;

    // Valid case
    actualDate = Date(117, 2, 13, 10, 01, 13);
    expected = (string) "Mar 13, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 12 => Year+= 1 , month = 0.
    actualDate = Date(117, 12, 13, 10, 01, 13);
    expected = (string) "Jan 13, 2018 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 33 => Year+= 2, month = 9.
    actualDate = Date(117, 33, 13, 10, 01, 13);
    expected = (string) "Oct 13, 2019 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 0
    actualDate = Date(117, 0, 13, 10, 01, 13);
    expected = (string) "Jan 13, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = -1 => Year-= 1, month = 11.
    actualDate = Date(117, -1, 13, 10, 01, 13);
    expected = (string) "Dec 13, 2016 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = -12 => Year-= 1, month = 0.
    actualDate = Date(117, -12, 13, 10, 01, 13);
    expected = (string) "Jan 13, 2016 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = -33 => Year-= 3, month = 3.
    actualDate = Date(117, -33, 13, 10, 01, 13);
    expected = (string) "Apr 13, 2014 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 3, date = -1 => month = 2, date = 30
    actualDate = Date(117, 3, -1, 10, 01, 13);
    expected = (string) "Mar 30, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 6, date = -75 => month = 3, date = 16
    actualDate = Date(117, 6, -75, 10, 01, 13);
    expected = (string) "Apr 16, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 3, date = 0 => month = 2, date = 31
    actualDate = Date(117, 3, 0, 10, 01, 13);
    expected = (string) "Mar 31, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 2, date = 0 => month = 1, date = 28
    actualDate = Date(117, 2, 0, 10, 01, 13);
    expected = (string) "Feb 28, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set month = 5, date = 32 => month = 6, date = 2
    actualDate = Date(117, 5, 32, 10, 01, 13);
    expected = (string) "Jul 02, 2017 10:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set hour = -1 => day -= 1, hour = 11 PM
    actualDate = Date(117, 2, 13, -1, 01, 13);
    expected = (string) "Mar 12, 2017 11:01:13 PM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set hour = 0
    actualDate = Date(117, 2, 13, 0, 01, 13);
    expected = (string) "Mar 13, 2017 12:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set hour = 24. Day += 1, hour = 0
    actualDate = Date(117, 2, 13, 24, 01, 13);
    expected = (string) "Mar 14, 2017 12:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set hour = 49. Day += 2, hour = 1
    actualDate = Date(117, 2, 13, 49, 01, 13);
    expected = (string) "Mar 15, 2017 01:01:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set minute = -1 => hour -= 1, minute = 59
    actualDate = Date(117, 2, 13, 10, -1, 13);
    expected = (string) "Mar 13, 2017 09:59:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set minute = 0
    actualDate = Date(117, 2, 13, 10, 0, 13);
    expected = (string) "Mar 13, 2017 10:00:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set minute = 60 => hour += 1, minute = 0
    actualDate = Date(117, 2, 13, 10, 60, 13);
    expected = (string) "Mar 13, 2017 11:00:13 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set minute = 150 => hour += 2, minute = 30
    actualDate = Date(117, 2, 13, 10, 150, 13);
    expected = (string) "Mar 13, 2017 12:30:13 PM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set second = -1 => minute -= 1, second = 59
    actualDate = Date(117, 2, 13, 10, 01, -1);
    expected = (string) "Mar 13, 2017 10:00:59 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set minute = 0
    actualDate = Date(117, 2, 13, 10, 01, 0);
    expected = (string) "Mar 13, 2017 10:01:00 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set second = 60 => minute += 1, second = 0
    actualDate = Date(117, 2, 13, 10, 01, 60);
    expected = (string) "Mar 13, 2017 10:02:00 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());

    // Set second = 150 => minute += 2, second = 30
    actualDate = Date(117, 2, 13, 10, 01, 150);
    expected = (string) "Mar 13, 2017 10:03:30 AM";
    actual = actualDate.toLocaleString();
    ASSERT_STR(expected, actual.toString());
}

TEST(JavaUtil, DateUTC) {
    // Create variable to test
    Date expected = Date();
    String expectedString;
    Date actual = Date();
    long timeActual;
    long timeChange;

    // Valid case
    expected 	= Date(2017, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // TODO(thoangminh): This case return different result with Travis-ci
//    // Set year = 1900. Not work correctly
//    expected 	= Date(1900, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(1900, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    actual.setUTC(true);
//    ASSERT_EQUAL(expected.getYear(), actual.getYear());
//    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
//    ASSERT_EQUAL(expected.getDate(), actual.getDate());
//    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours()) % 24);
//    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
//    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
//    ASSERT_STR(expectedString.toString(), actual.toString().toString());

    // Set year = 3000
    expected 	= Date(3000, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(3000, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set year = 1889
    expected 	= Date(1889, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(1889, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // TODO(thoangminh): This case return different result with Travis-ci
//    // Set year = -1. Not work correctly
//    expected 	= Date(-1, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(-1, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    ASSERT_EQUAL(expected.getYear(), actual.getYear());
//    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
//    ASSERT_EQUAL(expected.getDate(), actual.getDate());
//    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours()) % 24);
//    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
//    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // TODO(thoangminh): This case return different result with Travis-ci
//    // Set year = -900. Not work correctly
//    expected 	= Date(-900, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(-900, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    ASSERT_EQUAL(expected.getYear(), actual.getYear());
//    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
//    ASSERT_EQUAL(expected.getDate(), actual.getDate());
//    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours()) % 24);
//    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
//    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // TODO(thoangminh): This case return different result with Travis-ci
//    // Set year = 0
//    expected 	= Date(1900, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(1900, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    ASSERT_EQUAL(expected.getYear(), actual.getYear());
//    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
//    ASSERT_EQUAL(expected.getDate(), actual.getDate());
//    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours()) % 24);
//    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
//    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 12 => Year+= 1 , month = 0.
    expected 	= Date(2018, 0, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 12, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 33 => Year+= 2, month = 9.
    expected 	= Date(2019, 9, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 33, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 0
    expected 	= Date(2017, 0, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 0, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -1 => Year-= 1, month = 11.
    expected 	= Date(2016, 11, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, -1, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -12 => Year-= 1, month = 0.
    expected 	= Date(2016, 0, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, -12, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -33 => Year-= 3, month = 3.
    expected 	= Date(2014, 3, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, -33, 13, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 3, date = -1 => month = 2, date = 30
    expected 	= Date(2017, 2, 30, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 3, -1, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 6, date = -75 => month = 3, date = 16
    expected 	= Date(2017, 3, 16, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 6, -75, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 3, date = 0 => month = 2, date = 31
    expected 	= Date(2017, 2, 31, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 3, 0, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 2, date = 0 => month = 1, date = 28
    expected 	= Date(2017, 1, 28, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 0, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 5, date = 32 => month = 6, date = 2
    expected 	= Date(2017, 6, 2, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 5, 32, 10, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = -1 => day -= 1, hour = 23
    expected 	= Date(2017, 2, 12, 23, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, -1, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());

    // Set hour = 0
    expected 	= Date(2017, 2, 13, 0, 01, 13);
    timeActual  = Date::UTC(2017, 2, 13, 0, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 24. Day += 1, hour = 0
    expected 	= Date(2017, 2, 14, 0, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 24, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 49. Day += 2, hour = 1
    expected 	= Date(2017, 2, 15, 1, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 49, 01, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = -1 => hour -= 1, minute = 59
    expected 	= Date(2017, 2, 13, 9, 59, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, -1, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected 	= Date(2017, 2, 13, 10, 0, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 0, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 60 => hour += 1, minute = 0
    expected 	= Date(2017, 2, 13, 11, 00, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 60, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 150 => hour += 2, minute = 30
    expected 	= Date(2017, 2, 13, 12, 30, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 150, 13);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = -1 => minute -= 1, second = 59
    expected 	= Date(2017, 2, 13, 10, 00, 59);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, -1);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected 	= Date(2017, 2, 13, 10, 01, 0);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 0);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = 60 => minute += 1, second = 0
    expected 	= Date(2017, 2, 13, 10, 02, 00);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 60);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = 150 => minute += 2, second = 30
    expected 	= Date(2017, 2, 13, 10, 03, 30);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 150);
    actual = Date(timeActual);
    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(timeChange);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), actual.getHours());
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateToString) {
    // Create variable to test
    Date actualDate = Date();
    String expected;
    String actual;
    String zone = actualDate.getZone();

    // Valid case
    actualDate = Date(117, 2, 13, 10, 01, 13);
    expected = "Mon Mar 13 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());


    // Set month = 12 => Year+= 1 , month = 0.
    actualDate = Date(117, 12, 13, 10, 01, 13);
    expected = "Sat Jan 13 10:01:13 " + zone + (string) " 2018";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 33 => Year+= 2, month = 9.
    actualDate = Date(117, 33, 13, 10, 01, 13);
    expected = "Sun Oct 13 10:01:13 " + zone + (string) " 2019";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 0
    actualDate = Date(117, 0, 13, 10, 01, 13);
    expected = "Fri Jan 13 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = -1 => Year-= 1, month = 11.
    actualDate = Date(117, -1, 13, 10, 01, 13);
    expected = "Tue Dec 13 10:01:13 " + zone + (string) " 2016";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = -12 => Year-= 1, month = 0.
    actualDate = Date(117, -12, 13, 10, 01, 13);
    expected = "Wed Jan 13 10:01:13 " + zone + (string) " 2016";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = -33 => Year-= 3, month = 3.
    actualDate = Date(117, -33, 13, 10, 01, 13);
    expected = "Sun Apr 13 10:01:13 " + zone + (string) " 2014";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 3, date = -1 => month = 2, date = 30
    actualDate = Date(117, 3, -1, 10, 01, 13);
    expected = "Thu Mar 30 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 6, date = -75 => month = 3, date = 16
    actualDate = Date(117, 6, -75, 10, 01, 13);
    expected = "Sun Apr 16 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 3, date = 0 => month = 2, date = 31
    actualDate = Date(117, 3, 0, 10, 01, 13);
    expected = "Fri Mar 31 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 2, date = 0 => month = 1, date = 28
    actualDate = Date(117, 2, 0, 10, 01, 13);
    expected = "Tue Feb 28 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set month = 5, date = 32 => month = 6, date = 2
    actualDate = Date(117, 5, 32, 10, 01, 13);
    expected = "Sun Jul 02 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set hour = -1 => day -= 1, hour = 11 PM
    actualDate = Date(117, 2, 13, -1, 01, 13);
    expected = "Sun Mar 12 23:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set hour = 0
    actualDate = Date(117, 2, 13, 0, 01, 13);
    expected = "Mon Mar 13 00:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set hour = 24. Day += 1, hour = 0
    actualDate = Date(117, 2, 13, 24, 01, 13);
    expected = "Tue Mar 14 00:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set hour = 49. Day += 2, hour = 1
    actualDate = Date(117, 2, 13, 49, 01, 13);
    expected = "Wed Mar 15 01:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set minute = -1 => hour -= 1, minute = 59
    actualDate = Date(117, 2, 13, 10, -1, 13);
    expected = "Mon Mar 13 09:59:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set minute = 0
    actualDate = Date(117, 2, 13, 10, 0, 13);
    expected = "Mon Mar 13 10:00:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set minute = 60 => hour += 1, minute = 0
    actualDate = Date(117, 2, 13, 10, 60, 13);
    expected = "Mon Mar 13 11:00:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set minute = 150 => hour += 2, minute = 30
    actualDate = Date(117, 2, 13, 10, 150, 13);
    expected = "Mon Mar 13 12:30:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set second = -1 => minute -= 1, second = 59
    actualDate = Date(117, 2, 13, 10, 01, -1);
    expected = "Mon Mar 13 10:00:59 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set minute = 0
    actualDate = Date(117, 2, 13, 10, 01, 0);
    expected = "Mon Mar 13 10:01:00 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set second = 60 => minute += 1, second = 0
    actualDate = Date(117, 2, 13, 10, 01, 60);
    expected = "Mon Mar 13 10:02:00 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Set second = 150 => minute += 2, second = 30
    actualDate = Date(117, 2, 13, 10, 01, 150);
    expected = "Mon Mar 13 10:03:30 " + zone + (string) " 2017";
    actual = actualDate.toString();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, DateParse) {
    // Create variable to test
    String expected;

    Date   actualDate;
    String actualString;
    String actualFormat;
    long   actualTime;
    String actual;
    String localZone;
    String zone;

#ifdef __unix__
    zone = actualDate.getZone();
    if (actualDate.getTimezoneOffset() == 0) {
        localZone = "UTC";
    } else {
        localZone = "LMT";
    }
#endif

#ifdef WIN32
    zone = actualDate.getZone();
    if (actualDate.getTimezoneOffset() == 0) {
        localZone = "GMT";
    } else {
        localZone = "LMT";
    }
#endif

    // Valid case
    expected     = "Thu Jan 09 12:35:34 " + zone + (string) " 2014";
    actualString = "Thu Jan 9 and 2014 12:35:34";
    actualFormat = "%a %b %d and %Y %H:%M:%S";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short date pattern. (en-US)
    expected     = "Mon Feb 13 00:00:00 " + zone + (string) " 2017";
    actualString = "02/13/2017";
    actualFormat = "%m/%d/%Y";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long date pattern. (en-US)
    expected     = "Mon Jun 15 00:00:00 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009";
    actualFormat = "%A, %B %d, %Y";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Full date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 1:45 PM";
    actualFormat = "%A, %B %d, %Y %I:%M %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Full date/time pattern (long time). (en-US)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    actualFormat = "%A, %B %d, %Y %I:%M:%S %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 01:45:00 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45";
    actualFormat = "%m/%d/%Y %H:%M";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45 PM";
    actualFormat = "%m/%d/%Y %I:%M %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (long time). (en-US)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45:30 PM";
    actualFormat = "%m/%d/%Y %I:%M:%S %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Month/day pattern.(en-US)
    expected     = "Fri Jun 15 00:00:00 " + localZone + (string) " 1900";
    actualString = "June 15";
    actualFormat = "%B %d";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Round-trip date/time pattern. (DateTimeKind.Local)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15T13:45:30.0000000-07:00";
    actualFormat = "%Y-%m-%dT%H:%M:%S%Z";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Round-trip date/time pattern. (DateTimeKind.Utc)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15T13:45:30.0000000Z";
    actualFormat = "%Y-%m-%dT%H:%M:%S%Z";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // RFC1123 pattern.
    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
    actualString = "Mon, 15 Jun 2009 20:45:30 UTC";
    actualFormat = "%A, %d %B %Y %H:%M:%S %Z";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Sortable date/time pattern. (DateTimeKind.Local)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15T13:45:30";
    actualFormat = "%Y-%m-%dT%H:%M:%S";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short time pattern. (en-US)
    expected     = "Sun Dec 31 13:45:00 " + localZone + (string)" 1899";
    actualString = "1:45 PM";
    actualFormat = "%I:%M %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long time pattern. (en-US)
    expected     = "Sun Dec 31 01:45:30 " + localZone + (string) " 1899";
    actualString = "1:45:30";
    actualFormat = "%H:%M:%S";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long time pattern. (en-US)
    expected     = "Sun Dec 31 13:45:30 " + localZone + (string) " 1899";
    actualString = "1:45:30 PM";
    actualFormat = "%I:%M:%S %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Universal sortable date/time pattern. With a DateTime value:
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15 13:45:30Z";
    actualFormat = "%Y-%m-%d %H:%M:%S%p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Universal full date/time pattern. (en-US)
    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 8:45:30 PM";
    actualFormat = "%A, %B %d, %Y %I:%M:%S %p";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Year month pattern. (en-US)
    expected     = "Sun May 31 00:00:00 " + zone + (string) " 2009";
    actualString = "June, 2009";
    actualFormat = "%B, %Y";
    actualTime = Date::parse(actualString, actualFormat.toString());
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, DateToGMTString) {
    Date expectedDate = Date(2017, 2, 13, 10, 01, 13);
    String actualString = expectedDate.toGMTString();
    String actualFormat = "%a %b %d %T UTC %Y";
    long actualTime = Date::parse(actualString, actualFormat.toString());
    Date actualDate = Date(actualTime);

    long timeChange = expectedDate.getTime()
                      + expectedDate.getTimezoneOffset() * 60;
    expectedDate.setTime(timeChange);

    String expected = expectedDate.toString();
    String actual = actualDate.toString();

    ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, DateGetSequenceNumber) {
    // Create variable to test
    int expected;
    int actual;
    int index;
    std::string actualString;

    expected     = 15;
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 13;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 2009;
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 17;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 1;
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 22;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 45;
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 24;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 6;
    actualString = "6/15/2009 1:45:30 PM";
    index = 0;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 15;
    actualString = "6/15/2009 1:45:30 PM";
    index = 2;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 2009;
    actualString = "2009-06-15T13:45:30.0000000-07:00";
    index = 0;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 15;
    actualString = "2009-06-15T13:45:30.0000000-07:00";
    index = 8;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);

    expected     = 30;
    actualString = "2009-06-15T13:45:30.0000000-07:00";
    index = 17;
    actual = Date::getSequenceNumber(actualString, index);
    ASSERT_EQUAL(expected, actual);
}

TEST(JavaUtil, DateGetSequenceChar) {
    // Create variable to test
    string expected;
    string actual = new char[10];
    std::string actualString;
    int index;

    expected     = (string) "Monday";
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 0;
    strcpy(actual, Date::getSequenceChar(actualString, index).c_str());
    ASSERT_STR(expected, actual);

    expected     = (string) "abc";
    actualString = "abc61";
    index = 0;
    strcpy(actual, Date::getSequenceChar(actualString, index).c_str());
    ASSERT_STR(expected, actual);

    expected     = (string) "June";
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 8;
    strcpy(actual, Date::getSequenceChar(actualString, index).c_str());
    ASSERT_STR(expected, actual);

    expected     = (string) "PM";
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    index = 30;
    strcpy(actual, Date::getSequenceChar(actualString, index).c_str());
    ASSERT_STR(expected, actual);

    expected     = (string) "T";
    actualString = "2009-06-15T13:45:30.0000000-07:00";
    index = 10;
    strcpy(actual, Date::getSequenceChar(actualString, index).c_str());
    ASSERT_STR(expected, actual);

    delete[] actual;
}

TEST(JavaUtil, DateGetPattern) {
    // Create variable to test
    std::string expected;
    std::string actual;
    String actualString;

    /** Test processing the number */

    /**
     * number: >= 100
     * year: %Y
     */
    actualString = "100";
    expected = "%Y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     * number: 60 -> 99
     * year: %y
     */
    actualString = "61";
    expected = "%y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "abc61";
    expected = "abc%y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "61abc";
    expected = "%yabc";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "aaa61bbb";
    expected = "aaa%ybbb";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     * number: 32 -> 59
     * year: %y
     * or minute: %M
     * or second: %S
     */
    actualString = "32/";
    expected = "%y/";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "32.";
    expected = "%y.";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "32";
    expected = "%y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "32 aaa";
    expected = "%y aaa";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "32:";
    expected = "%M:";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "32:40";
    expected = "%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "32:40 50";
    expected = "%M:%S %y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     *  number: 24 -> 31
     *  or day of month: %d
     *  or year: %y
     *  minute: %M
     *  or second: %S
     */
    actualString = "24 25:30 31";
    expected = "%d %M:%S %y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "25:30 24 31";
    expected = "%M:%S %d %y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
    *  number: 12 -> 23
    *  or day of month: %d
    *  or year: %y
    *  or hour: %H
    *  minute: %M
    *  or second: %S
    */
    actualString = "14 12:20:15 20";
    expected = "%d %H:%M:%S %y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "12:20:15 14 20";
    expected = "%H:%M:%S %d %y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     *  number: 1 -> 11
     *  or day of month: %d
     *  or month: %m
     *  or year: %y
     *  or hour: %H
     *  minute: %M
     *  or second: %S
     */
    actualString = "1/2/11 5:10:11";
    expected = "%m/%d/%y %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "1-2-11 11:10:05";
    expected = "%m-%d-%y %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "3:11:08 1/2/11";
    expected = "%H:%M:%S %m/%d/%y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     *  number: = 0
     *  hour: %H
     *  minute: %M
     *  or second: %S
     */
    actualString = "1/2/11 00:10:11";
    expected = "%m/%d/%y %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "1-2-11 11:00:05";
    expected = "%m-%d-%y %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "00:00:00 1/2/11";
    expected = "%H:%M:%S %m/%d/%y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "aaa00:00:00aa aa1/2/11 aaa";
    expected = "aaa%H:%M:%Saa aa%m/%d/%y aaa";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Valid case
    actualString = "Thursday January 9 and 2014 12:35:34";
    expected = "%A %B %d and %Y %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     * Sample Date format
     */

    // Short date pattern. (en-US)
    actualString = "02/13/2017";
    expected = "%m/%d/%Y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Long date pattern. (en-US)
    actualString = "Monday, June 15, 2009";
    expected = "%A, %B %d, %Y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Full date/time pattern (short time). (en-US)
    actualString = "Monday, June 15, 2009 1:45 PM";
    expected = "%A, %B %d, %Y %I:%M %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Full date/time pattern (long time). (en-US)
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    expected = "%A, %B %d, %Y %I:%M:%S %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // General date/time pattern (short time). (en-US)
    actualString = "6/15/2009 1:45";
    expected = "%m/%d/%Y %H:%M";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // General date/time pattern (short time). (en-US)
    actualString = "6/15/2009 1:45 PM";
    expected = "%m/%d/%Y %I:%M %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // General date/time pattern (long time). (en-US)
    actualString = "6/15/2009 1:45:30 PM";
    expected = "%m/%d/%Y %I:%M:%S %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Month/day pattern.(en-US)
    actualString = "June 15";
    expected = "%B %d";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

//    // Round-trip date/time pattern. (DateTimeKind.Local)
//    actualString = "2009-06-15T13:45:30 -07:00";
//    expected = "%Y-%m-%dT%H:%M:%S %Z";
//    actual = Date::getPattern(actualString).c_str();
//    ASSERT_STR(expected.c_str(), actual.c_str());

    // Round-trip date/time pattern. (DateTimeKind.Utc)
    actualString = "2009-06-15 13:45:30";
    expected = "%Y-%m-%d %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());
//
//    // TODO(thoangminh): check it
//    // RFC1123 pattern.
////    expected     = "Tue Jun 16 20:45:30 " + zone + (string) " 2009";
////    actualString = "Mon, 15 Jun 2009 20:45:30 UTC";
////    actualFormat = "%A, %d %B %Y %H:%M:%S %Z";
////    actualTime = Date::parse(actualString, actualFormat.toString());
////    actual = Date(actualTime).toString();
////    ASSERT_STR(expected.toString(), actual.toString());

    // Sortable date/time pattern. (DateTimeKind.Local)
    actualString = "2009-06-15 13:45:30";
    expected = "%Y-%m-%d %H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Short time pattern. (en-US)
    actualString = "1:45 PM";
    expected = "%I:%M %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Long time pattern. (en-US)
    actualString = "1:45:30";
    expected = "%H:%M:%S";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Long time pattern. (en-US)
    actualString = "1:45:30 PM";
    expected = "%I:%M:%S %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Universal full date/time pattern. (en-US)
    actualString = "Monday, June 15, 2009 8:45:30 PM";
    expected = "%A, %B %d, %Y %I:%M:%S %p";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    // Year month pattern. (en-US)
    actualString = "June, 2009";
    expected = "%B, %Y";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    /**
     * Test the time zone
     * +number or -number
     * or
     * {
     *      "gmt", "ut", "utc",
     *      "est", "edt", "cst",
     *      "cdt", "mst", "mdt",
     *      "pst", "pdt"
     * }
     */
    actualString = "2009-06-15 13:45:30 +07";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "2009-06-15 13:45:30 -07";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "2009-06-15 13:45:30 -0430";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "2009-06-15 13:45:30 GMT";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "2009-06-15 13:45:30 UT";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "2009-06-15 13:45:30 utc";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());

    actualString = "2009-06-15 13:45:30 pdt";
    expected = "%Y-%m-%d %H:%M:%S %Z";
    actual = Date::getPattern(actualString).c_str();
    ASSERT_STR(expected.c_str(), actual.c_str());
}

TEST(JavaUtil, DateParse2) {
    // Create variable to test
    String expected;

    Date   actualDate;
    String actualString;
    String actualFormat;
    long   actualTime;
    String actual;
    String localZone;
    String zone;

#ifdef __unix__
    zone = actualDate.getZone();
    if (actualDate.getTimezoneOffset() == 0) {
        localZone = "UTC";
    } else {
        localZone = "LMT";
    }
#endif

#ifdef WIN32
    zone = actualDate.getZone();
    if (actualDate.getTimezoneOffset() == 0) {
        localZone = "GMT";
    } else {
        localZone = "LMT";
    }
#endif

    // Valid case
    expected     = "Thu Jan 09 12:35:34 " + zone + (string) " 2014";
    actualString = "Thu Jan 9 and 2014 12:35:34";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short date pattern. (en-US)
    expected     = "Mon Feb 13 00:00:00 " + zone + (string) " 2017";
    actualString = "02/13/2017";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long date pattern. (en-US)
    expected     = "Mon Jun 15 00:00:00 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Full date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 1:45 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Full date/time pattern (long time). (en-US)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 1:45:30 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 01:45:00 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (short time). (en-US)
    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // General date/time pattern (long time). (en-US)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "6/15/2009 1:45:30 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Month/day pattern.(en-US)
    expected     = "Fri Jun 15 00:00:00 " + localZone + (string) " 1900";
    actualString = "June 15";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // RFC1123 pattern.
    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
    actualString = "Mon, 15 Jun 2009 20:45:30 UTC";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Sortable date/time pattern. (DateTimeKind.Local)
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15 13:45:30";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Short time pattern. (en-US)
    expected     = "Sun Dec 31 13:45:00 " + localZone + (string)" 1899";
    actualString = "1:45 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long time pattern. (en-US)
    expected     = "Sun Dec 31 01:45:30 " + localZone + (string) " 1899";
    actualString = "1:45:30";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Long time pattern. (en-US)
    expected     = "Sun Dec 31 13:45:30 " + localZone + (string) " 1899";
    actualString = "1:45:30 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Universal sortable date/time pattern. With a DateTime value:
    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
    actualString = "2009-06-15 13:45:30Z";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Universal full date/time pattern. (en-US)
    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
    actualString = "Monday, June 15, 2009 8:45:30 PM";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    // Year month pattern. (en-US)
    expected     = "Sun May 31 00:00:00 " + zone + (string) " 2009";
    actualString = "June, 2009";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /** Test processing the number */

    /**
     * number: >= 100
     * year: %Y
     */
    expected     = "Thu Dec 31 00:00:00 " + localZone + (string) " 99";
    actualString = "100";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /**
     * number: 60 -> 99
     * year: %y
     */
    expected     = "Fri Dec 31 00:00:00 " + zone + (string) " 2060";
    actualString = "61";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Fri Dec 31 00:00:00 " + zone + (string) " 2060";
    actualString = "abc61";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Fri Dec 31 00:00:00 " + zone + (string) " 2060";
    actualString = "61abc";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Fri Dec 31 00:00:00 " + zone + (string) " 2060";
    actualString = "aaa61bbb";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /**
     * number: 32 -> 59
     * year: %y
     * or minute: %M
     * or second: %S
     */
    expected     = "Wed Dec 31 00:00:00 " + zone + (string) " 2031";
    actualString = "32/";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Wed Dec 31 00:00:00 " + zone + (string) " 2031";
    actualString = "32.";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Wed Dec 31 00:00:00 " + zone + (string) " 2031";
    actualString = "32";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Wed Dec 31 00:00:00 " + zone + (string) " 2031";
    actualString = "32 aaa";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Dec 31 00:32:00 " + localZone + (string) " 1899";
    actualString = "32:";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Dec 31 00:32:40 " + localZone + (string) " 1899";
    actualString = "32:40";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Fri Dec 31 00:32:40 " + zone + (string) " 2049";
    actualString = "32:40 50";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /**
     *  number: 24 -> 31
     *  or day of month: %d
     *  or year: %y
     *  minute: %M
     *  or second: %S
     */
    expected     = "Fri Jan 24 00:25:30 " + zone + (string) " 2031";
    actualString = "24 25:30 31";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Fri Jan 24 00:25:30 " + zone + (string) " 2031";
    actualString = "25:30 24 31";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /**
    *  number: 12 -> 23
    *  or day of month: %d
    *  or year: %y
    *  or hour: %H
    *  minute: %M
    *  or second: %S
    */
    expected     = "Tue Jan 14 12:20:15 " + zone + (string) " 2020";
    actualString = "14 12:20:15 20";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Tue Jan 14 12:20:15 " + zone + (string) " 2020";
    actualString = "12:20:15 14 20";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /**
     *  number: 1 -> 11
     *  or day of month: %d
     *  or month: %m
     *  or year: %y
     *  or hour: %H
     *  minute: %M
     *  or second: %S
     */
    expected     = "Sun Jan 02 05:10:11 " + zone + (string) " 2011";
    actualString = "1/2/11 5:10:11";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Jan 02 11:10:05 " + zone + (string) " 2011";
    actualString = "1-2-11 11:10:05";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Jan 02 03:11:08 " + zone + (string) " 2011";
    actualString = "3:11:08 1/2/11";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    /**
     *  number: = 0
     *  hour: %H
     *  minute: %M
     *  or second: %S
     */
    expected     = "Sun Jan 02 00:10:11 " + zone + (string) " 2011";
    actualString = "1/2/11 00:10:11";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Jan 02 11:00:05 " + zone + (string) " 2011";
    actualString = "1-2-11 11:00:05";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Jan 02 00:00:00 " + zone + (string) " 2011";
    actualString = "00:00:00 1/2/11";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());

    expected     = "Sun Jan 02 00:00:00 " + zone + (string) " 2011";
    actualString = "aaa00:00:00aa aa1/2/11 aaa";
    actualTime = Date::parse(actualString);
    actual = Date(actualTime).toString();
    ASSERT_STR(expected.toString(), actual.toString());
}