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
    // Timer of C++ to test current local time
    time_t now = time(0);
    tm *currentTime = localtime(&now);

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
    date = Date(1498042091); //2017
    ASSERT_EQUAL(2017, date.getYear());

    // TODO(thoangminh): Check it later
    // Test Date(String s)
//    String dateString = "Thu Jun 22 2017 12:35:34";
//    date = Date(dateString);
//    ASSERT_EQUAL(2017, date.getYear());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(sameDate.getYear(), date.getYear());
    ASSERT_EQUAL(sameDate.getMonth(), date.getMonth());
    ASSERT_EQUAL(sameDate.getDate(), date.getDate());
    ASSERT_EQUAL(sameDate.getHours(), date.getHours());
    ASSERT_EQUAL(sameDate.getMinutes(), date.getMinutes());
    ASSERT_EQUAL(sameDate.getSeconds(), date.getSeconds());
}

//TEST(JavaUtil, DateGetDayOfMonth) {
//    // Given valid date to test getDate()
//    int expectedDayOfMonth = 20;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedDayOfMonth, date.getDate());
//}
//
//TEST(JavaUtil, DateGetDayOfWeek) {
//    // Given valid date to test getDay()
//    int expectedDayOfWeek = 4; // Thursday
//    Date date = Date(2017, 05, 22, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedDayOfWeek, date.getDay());
//}

//TEST(JavaUtil, DateGetSeconds) {
//    // Given valid date to test getSeconds()
//    int expectedSecond = 58;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedSecond, date.getSeconds());
//}
//
//TEST(JavaUtil, DateGetTime) {
//    // Get current time of system to validate getTime()
//    long expectedTime = 1498032610;
//
//    Date date = expectedTime;
//
//    ASSERT_EQUAL(expectedTime, date.getTime());
//}

//TEST(JavaUtil, DateSetSeconds) {
//    // Given valid date to test setSeconds()
//    Date date;
//    int expectedSecond = 15;
//
//    date.setSeconds(expectedSecond);
//    ASSERT_EQUAL(expectedSecond, date.getSeconds());
//}
//
//TEST(JavaUtil, DateSetTime) {
//    // Given valid date to test setTime()
//    Date date;
//    int expectedTime = 1498028643;
//
//    date.setTime(expectedTime);
//    ASSERT_EQUAL(expectedTime, date.getTime());
//}

///**
// * This test case aim to make CI happy, no need to do like that
// * Usage:
// *  Date date;
// *  date.toGMTString()
// */
//TEST(JavaUtil, DateGMTString)  {
//    // Given valid date to test GMT time, this test case is based on Date.getTimeZoneOffset
//    Date date = Date(2017, 05, 22, 12, 35, 34);
//    int timeZone = date.getTimezoneOffset();
//
//    string timeString;
//    asprintf(&timeString, "Thu Jun 22 2017 %02d:35:34", 12 - timeZone);
//
//    String expectedGMTString = timeString;
//    free(timeString);
//
//    ASSERT_STR(expectedGMTString.toString(), date.toGMTString().toString());
//}
//
//TEST(JavaUtil, DateLocaleString) {
//    // Given valid date to test local time
//    Date date = Date(2017, 05, 22, 12, 35, 34);
//    String expectedLocaleString = "Thu Jun 22 2017 12:35:34";
//
//    ASSERT_STR(expectedLocaleString.toString(), date.toLocaleString().toString());
//}
//
//TEST(JavaUtil, DateAfter) {
//    // Given valid date to test another date is after this day or not
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date dateBefore = Date(2017, 05, 21, 14, 05, 40);
//    ASSERT_TRUE(date.after(dateBefore));
//
//    Date dateAfter = Date(2017, 05, 21, 14, 05, 45);
//    ASSERT_FALSE(date.after(dateAfter));
//}
//
//TEST(JavaUtil, DateBefore) {
//    // Given valid date to test another date is before this day or not
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date dateBefore = Date(2017, 05, 21, 14, 05, 40);
//    ASSERT_FALSE(date.before(dateBefore));
//
//    Date dateAfter = Date(2017, 05, 21, 14, 05, 45);
//    ASSERT_TRUE(date.before(dateAfter));
//}
//
//TEST(JavaUtil, DateClone) {
//    // Given valid date and make a copy of this date
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date target = date;
//    ASSERT_EQUAL(date.getSeconds(), target.getSeconds());
//}
//
//TEST(JavaUtil, DateCompare) {
//    // Given valid date to test compareTo() with dateBefore, dateAfter, dateEqual
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date dateBefore = Date(2017, 05, 21, 14, 05, 25);
//    Date dateAfter = Date(2017, 05, 21, 14, 05, 50);
//    Date dateEqual = Date(2017, 05, 21, 14, 05, 43);
//
//    int expectedResult = 1;
//    ASSERT_EQUAL(expectedResult, date.compareTo(dateBefore));
//
//    expectedResult = -1;
//    ASSERT_EQUAL(expectedResult, date.compareTo(dateAfter));
//
//    expectedResult = 0;
//    ASSERT_EQUAL(expectedResult, date.compareTo(dateEqual));
//}
//

TEST(JavaUtil, DateUTC) {
    // Create variable to test
    tm expectedTimer = {0};
    long expectedResult;
    long actualResult;

    // Test valid case
    expectedTimer.tm_year = 2017 - 1900;
    expectedTimer.tm_mon = 02;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Test month = 12
    expectedTimer.tm_year = 2018 - 1900;
    expectedTimer.tm_mon = 1;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, 12, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Test month > 12
    expectedTimer.tm_year = 2018 - 1900;
    expectedTimer.tm_mon = 3;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, 15, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2019 - 1900;
    expectedTimer.tm_mon = 1;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, 24, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2019 - 1900;
    expectedTimer.tm_mon = 1;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, 25, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2019 - 1900;
    expectedTimer.tm_mon = 4;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, 28, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Test month < 0
    expectedTimer.tm_year = 2016 - 1900;
    expectedTimer.tm_mon = 12;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, -1, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2016 - 1900;
    expectedTimer.tm_mon = 10;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, -3, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2016 - 1900;
    expectedTimer.tm_mon = 1;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, -12, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2015 - 1900;
    expectedTimer.tm_mon = 1;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, -24, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedTimer.tm_year = 2014 - 1900;
    expectedTimer.tm_mon = 9;
    expectedTimer.tm_mday = 13;
    expectedTimer.tm_hour = 8;
    expectedTimer.tm_min = 01;
    expectedTimer.tm_sec = 13;
    expectedResult = mktime(&expectedTimer);
    actualResult = Date::UTC(2017, -28, 13, 8, 01, 13);
    ASSERT_EQUAL(expectedResult, actualResult);
}
//
//TEST(JavaUtil, DateGetTimeZone) {
//    // Given valid date to test current time zone, this test case is based on Vietnam GMT+7
//    Date date;
//
//    // Init timer of system to test time zone
//    time_t now = time(0);
//    int expectedTimeZone = localtime(&now)->tm_hour - gmtime(&now)->tm_hour;
//
//    ASSERT_EQUAL(expectedTimeZone, date.getTimezoneOffset());
//}

TEST(JavaUtil, DateSetYear) {
    // Create variable to test
    Date date;

    date.setYear(1900);
    ASSERT_EQUAL(1900, date.getYear());

    date.setYear(1994);
    ASSERT_EQUAL(1994, date.getYear());

    date.setYear(2000);
    ASSERT_EQUAL(2000, date.getYear());

    date.setYear(2010);
    ASSERT_EQUAL(2010, date.getYear());

    date.setYear(2017);
    ASSERT_EQUAL(2017, date.getYear());

    date.setYear(2020);
    ASSERT_EQUAL(2020, date.getYear());
}

TEST(JavaUtil, DateGetYear) {
    // Create variable to test
    Date date;

    // Timer of C++ to test current local time
    time_t now = time(0);
    tm *currentTime = localtime(&now);

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
    date = Date(Date::UTC(2017, 02, 13, 8, 01, 13));
    ASSERT_EQUAL(2017, date.getYear());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(2017, date.getYear());
}

TEST(JavaUtil, DateSetMonth) {
    // Create variable to test
    Date date;

    date.setMonth(1);
    ASSERT_EQUAL(1, date.getMonth());

    date.setMonth(2);
    ASSERT_EQUAL(2, date.getMonth());

    date.setMonth(3);
    ASSERT_EQUAL(3, date.getMonth());

    date.setMonth(8);
    ASSERT_EQUAL(8, date.getMonth());

    date.setMonth(10);
    ASSERT_EQUAL(10, date.getMonth());

    date.setMonth(12);
    ASSERT_EQUAL(12, date.getMonth());
}

TEST(JavaUtil, DateGetMonth) {
    // Create variable to test
    Date date;

    // Timer of C++ to test current local time
    time_t now = time(0);
    tm *currentTime = localtime(&now);

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
    date = Date(Date::UTC(2017, 02, 13, 8, 01, 13));
    ASSERT_EQUAL(02, date.getMonth());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(02, date.getMonth());
}

TEST(JavaUtil, DateSetDate) {
    // Create variable to test
    Date date;

    date.setDate(1);
    ASSERT_EQUAL(1, date.getDate());

    date.setDate(2);
    ASSERT_EQUAL(2, date.getDate());

    date.setDate(13);
    ASSERT_EQUAL(13, date.getDate());

    date.setDate(28);
    ASSERT_EQUAL(28, date.getDate());

    date.setDate(30);
    ASSERT_EQUAL(30, date.getDate());

    date.setDate(31);
    ASSERT_EQUAL(31, date.getDate());
}

TEST(JavaUtil, DateGetDate) {
    // Create variable to test
    Date date;

    // Timer of C++ to test current local time
    time_t now = time(0);
    tm *currentTime = localtime(&now);

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
    date = Date(Date::UTC(2017, -28, 13, 8, 01, 13));
    ASSERT_EQUAL(13, date.getDate());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(13, date.getDate());
}

TEST(JavaUtil, DateSetHours) {
    // Create variable to test
    Date date;

    date.setHours(1);
    ASSERT_EQUAL(1, date.getHours());

    date.setHours(2);
    ASSERT_EQUAL(2, date.getHours());

    date.setHours(13);
    ASSERT_EQUAL(13, date.getHours());

    date.setHours(20);
    ASSERT_EQUAL(20, date.getHours());

    date.setHours(21);
    ASSERT_EQUAL(21, date.getHours());

    date.setHours(23);
    ASSERT_EQUAL(23, date.getHours());
}

TEST(JavaUtil, DateGetHour) {
    // Create variable to test
    Date date;

    // Timer of C++ to test current local time
    time_t now = time(0);
    tm *currentTime = localtime(&now);

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
    date = Date(Date::UTC(2017, -28, 13, 8, 01, 13));
    ASSERT_EQUAL(8, date.getHours());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(8, date.getHours());
}

TEST(JavaUtil, DateSetMinutes) {
    // Create variable to test
    Date date;

    date.setMinutes(1);
    ASSERT_EQUAL(1, date.getMinutes());

    date.setMinutes(2);
    ASSERT_EQUAL(2, date.getMinutes());

    date.setMinutes(13);
    ASSERT_EQUAL(13, date.getMinutes());

    date.setMinutes(20);
    ASSERT_EQUAL(20, date.getMinutes());

    date.setMinutes(21);
    ASSERT_EQUAL(21, date.getMinutes());

    date.setMinutes(59);
    ASSERT_EQUAL(59, date.getMinutes());
}

TEST(JavaUtil, DateGetMinutes) {
    // Create variable to test
    Date date;

    // Timer of C++ to test current local time
    time_t now = time(0);
    tm *currentTime = localtime(&now);

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
    date = Date(Date::UTC(2017, -28, 13, 8, 01, 13));
    ASSERT_EQUAL(01, date.getMinutes());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    ASSERT_EQUAL(01, date.getMinutes());
}
