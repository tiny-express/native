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
    Date sameDate = date;
    ASSERT_EQUAL(2017, sameDate.getYear());
}

TEST(JavaUtil, DateSetMonth) {
    // Create variable to test
    Date date;
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
    Date sameDate = date;
    ASSERT_EQUAL(02, sameDate.getMonth());
}

TEST(JavaUtil, DateSetDate) {
    // Create variable to test
    Date date;

    date.setDate(1);
    ASSERT_EQUAL(1, date.getDate());

    date.setDate(31);
    ASSERT_EQUAL(31, date.getDate());

    // TODO(thoangminh): Need to throw exeptions for these cases below
    date.setDate(0);
    ASSERT_EQUAL(0, date.getDate());

    date.setDate(32);
    ASSERT_EQUAL(32, date.getDate());

    date.setDate(-1);
    ASSERT_EQUAL(-1, date.getDate());
}

TEST(JavaUtil, DateGetDate) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
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
    Date sameDate = date;
    ASSERT_EQUAL(13, sameDate.getDate());
}

TEST(JavaUtil, DateSetHours) {
    // Create variable to test
    Date date;

    date.setHours(1);
    ASSERT_EQUAL(1, date.getHours());

    date.setHours(23);
    ASSERT_EQUAL(23, date.getHours());

    date.setHours(0);
    ASSERT_EQUAL(0, date.getHours());

    // TODO(thoangminh): Need to throw exeptions for these cases below
    date.setHours(-1);
    ASSERT_EQUAL(-1, date.getHours());

    date.setHours(24);
    ASSERT_EQUAL(24, date.getHours());
}

TEST(JavaUtil, DateGetHour) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
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
    Date sameDate = date;
    ASSERT_EQUAL(8, sameDate.getHours());
}

TEST(JavaUtil, DateSetMinutes) {
    // Create variable to test
    Date date;

    date.setMinutes(1);
    ASSERT_EQUAL(1, date.getMinutes());

    date.setMinutes(59);
    ASSERT_EQUAL(59, date.getMinutes());

    date.setMinutes(0);
    ASSERT_EQUAL(0, date.getMinutes());

    // TODO(thoangminh): Need to throw exeptions for these cases below
    date.setMinutes(-1);
    ASSERT_EQUAL(-1, date.getMinutes());

    date.setMinutes(60);
    ASSERT_EQUAL(60, date.getMinutes());
}

TEST(JavaUtil, DateGetMinutes) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
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
    Date sameDate = date;
    ASSERT_EQUAL(01, sameDate.getMinutes());
}

TEST(JavaUtil, DateSetSeconds) {
    // Create variable to test
    Date date;

    date.setSeconds(1);
    ASSERT_EQUAL(1, date.getSeconds());

    date.setSeconds(59);
    ASSERT_EQUAL(59, date.getSeconds());

    date.setSeconds(0);
    ASSERT_EQUAL(0, date.getSeconds());

    // TODO(thoangminh): Need to throw exeptions for these cases below
    date.setSeconds(-1);
    ASSERT_EQUAL(-1, date.getSeconds());

    date.setSeconds(60);
    ASSERT_EQUAL(60, date.getSeconds());
}

TEST(JavaUtil, DateGetSeconds) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    tm *currentTime = localtime(&now);
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
    date = Date(Date::UTC(2017, -28, 13, 8, 01, 13));
    ASSERT_EQUAL(13, date.getSeconds());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    ASSERT_EQUAL(13, sameDate.getSeconds());
}

TEST(JavaUtil, DateGetTime) {
    // Create variable to test
    Date date;

    // Get the current local time
    time_t now = time(nullptr);
    ASSERT_EQUAL(now, date.getTime());

    // TODO(thoangminh): These test work for Linux, fail in Windows
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    ASSERT_EQUAL(1489338000, date.getTime());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    ASSERT_EQUAL(1489366860, date.getTime());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    ASSERT_EQUAL(1489366873, date.getTime());
//
//    // Test Date(long date)
//    date = Date(Date::UTC(2017, -28, 13, 8, 01, 13));
//    ASSERT_EQUAL(1413162073, date.getTime());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    ASSERT_EQUAL(1489366873, sameDate.getTime());
}

TEST(JavaUtil, DateSetTime) {
    // Create variable to test
    Date tempDate;
    Date date;
    long tempTime;

    // Get the current local time
    time_t now = time(nullptr);
    tm *currentTime = localtime(&now);
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
    tempDate = Date(Date::UTC(2017, 2, 13, 8, 1, 13));
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

    // Test Sunday - value 0
    date = Date(2017, 8, 13, 8, 01, 13);
    ASSERT_EQUAL(0, date.getDay());

    // Test Monday - value 1
    date = Date(2017, 8, 14, 8, 01, 13);
    ASSERT_EQUAL(1, date.getDay());

    // Test Tuesday - value 2
    date = Date(2017, 8, 15, 8, 01, 13);
    ASSERT_EQUAL(2, date.getDay());

    // Test Wednesday - value 3
    date = Date(2017, 8, 16, 8, 01, 13);
    ASSERT_EQUAL(3, date.getDay());

    // Test Thursday - value 4
    date = Date(2017, 8, 17, 8, 01, 13);
    ASSERT_EQUAL(4, date.getDay());

    // Test Friday - value 5
    date = Date(2017, 8, 18, 8, 01, 13);
    ASSERT_EQUAL(5, date.getDay());

    // Test Saturday - value 6
    date = Date(2017, 8, 19, 8, 01, 13);
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
    tm *currentTime = localtime(&now);
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
    tempDate = Date(Date::UTC(2017, 02, 13, 8, 01, 13));
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

TEST(JavaUtil, DateGetTimezoneOffset) {
    // Create variable to test
    Date date;
    int expectedResult;

    // Test System time zone
    time_t now = time(nullptr);
    expectedResult = -(localtime(&now)->tm_hour - gmtime(&now)->tm_hour) *60;
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());

//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());
//
//    // Test Date(long date)
//    date = Date(Date::UTC(2017, -28, 13, 8, 01, 13));
//    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    ASSERT_EQUAL(expectedResult, date.getTimezoneOffset());
}


TEST(JavaUtil, DateToString) {
    // Create variable to test
    Date date;
    string expectedResult;

    // Get the current local time
    time_t now = time(nullptr);
    tm *currentTime = localtime(&now);
    auto format = (string) "%a %b %d %T UTC %Y";
    size_t size = 100;
    expectedResult = (string) (malloc(size * sizeof(char)));
    strftime(expectedResult, size, format, currentTime);
    ASSERT_STR(expectedResult, date.toString().toString());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    expectedResult = (string) "Mon Mar 13 00:00:00 UTC 2017";
    ASSERT_STR(expectedResult, date.toString().toString());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    expectedResult = (string) "Mon Mar 13 08:01:00 UTC 2017";
    ASSERT_STR(expectedResult, date.toString().toString());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    expectedResult = (string) "Mon Mar 13 08:01:13 UTC 2017";
    ASSERT_STR(expectedResult, date.toString().toString());

    // Test Date(long date)
    date = Date(Date::UTC(2017, 02, 13, 8, 01, 13));
    expectedResult = (string) "Mon Mar 13 08:01:13 UTC 2017";
    ASSERT_STR(expectedResult, date.toString().toString());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    expectedResult = (string) "Mon Mar 13 08:01:13 UTC 2017";
    ASSERT_STR(expectedResult, sameDate.toString().toString());
}