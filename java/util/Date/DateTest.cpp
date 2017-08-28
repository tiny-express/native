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


TEST(JavaUtil, DateToString) {
    // Create variable to test
    Date date = Date();
    string expectedResult;

    // Get the current local time
    time_t now = time(nullptr);
    tm tempTimer = {0};
    tm *currentTime = localtime_r(&now, &tempTimer);
    auto format = (string) "%a %b %d %T UTC %Y";
    size_t size = 100;
    expectedResult = (string) (malloc(size * sizeof(char)));
    strftime(expectedResult, size, format, currentTime);
    ASSERT_STR(expectedResult, date.toString().toString());
    free(expectedResult);

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

    // TODO(thoangminh): Need to pass this case
//    // Test Date(long date)
//    Date tempDate = Date(2017, 02, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    expectedResult = (string) "Mon Mar 13 08:01:13 UTC 2017";
//    ASSERT_STR(expectedResult, date.toString().toString());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    expectedResult = (string) "Mon Mar 13 08:01:13 UTC 2017";
    ASSERT_STR(expectedResult, sameDate.toString().toString());
}

TEST(JavaUtil, DateToLocaleString) {
    // Create variable to test
    Date actualDate;
    string expected;
    String actualString;

    // Valid case
    actualDate = Date(117, 2, 13, 10, 01, 13);
    expected = (string) "Mar 13, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 12 => Year+= 1 , month = 0.
    actualDate = Date(117, 12, 13, 10, 01, 13);
    expected = (string) "Jan 13, 2018 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 33 => Year+= 2, month = 9.
    actualDate = Date(117, 33, 13, 10, 01, 13);
    expected = (string) "Oct 13, 2019 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 0
    actualDate = Date(117, 0, 13, 10, 01, 13);
    expected = (string) "Jan 13, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = -1 => Year-= 1, month = 11.
    actualDate = Date(117, -1, 13, 10, 01, 13);
    expected = (string) "Dec 13, 2016 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = -12 => Year-= 1, month = 0.
    actualDate = Date(117, -12, 13, 10, 01, 13);
    expected = (string) "Jan 13, 2016 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = -33 => Year-= 3, month = 3.
    actualDate = Date(117, -33, 13, 10, 01, 13);
    expected = (string) "Apr 13, 2014 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 3, date = -1 => month = 2, date = 30
    actualDate = Date(117, 3, -1, 10, 01, 13);
    expected = (string) "Mar 30, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 6, date = -75 => month = 3, date = 16
    actualDate = Date(117, 6, -75, 10, 01, 13);
    expected = (string) "Apr 16, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 3, date = 0 => month = 2, date = 31
    actualDate = Date(117, 3, 0, 10, 01, 13);
    expected = (string) "Mar 31, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 2, date = 0 => month = 1, date = 28
    actualDate = Date(117, 2, 0, 10, 01, 13);
    expected = (string) "Feb 28, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set month = 5, date = 32 => month = 6, date = 2
    actualDate = Date(117, 5, 32, 10, 01, 13);
    expected = (string) "Jul 02, 2017 10:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set hour = -1 => day -= 1, hour = 11 PM
    actualDate = Date(117, 2, 13, -1, 01, 13);
    expected = (string) "Mar 12, 2017 11:01:13 PM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set hour = 0
    actualDate = Date(117, 2, 13, 0, 01, 13);
    expected = (string) "Mar 13, 2017 12:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set hour = 24. Day += 1, hour = 0
    actualDate = Date(117, 2, 13, 24, 01, 13);
    expected = (string) "Mar 14, 2017 12:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set hour = 49. Day += 2, hour = 1
    actualDate = Date(117, 2, 13, 49, 01, 13);
    expected = (string) "Mar 15, 2017 01:01:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set minute = -1 => hour -= 1, minute = 59
    actualDate = Date(117, 2, 13, 10, -1, 13);
    expected = (string) "Mar 13, 2017 09:59:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set minute = 0
    actualDate = Date(117, 2, 13, 10, 0, 13);
    expected = (string) "Mar 13, 2017 10:00:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set minute = 60 => hour += 1, minute = 0
    actualDate = Date(117, 2, 13, 10, 60, 13);
    expected = (string) "Mar 13, 2017 11:00:13 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set minute = 150 => hour += 2, minute = 30
    actualDate = Date(117, 2, 13, 10, 150, 13);
    expected = (string) "Mar 13, 2017 12:30:13 PM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set second = -1 => minute -= 1, second = 59
    actualDate = Date(117, 2, 13, 10, 01, -1);
    expected = (string) "Mar 13, 2017 10:00:59 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set minute = 0
    actualDate = Date(117, 2, 13, 10, 01, 0);
    expected = (string) "Mar 13, 2017 10:01:00 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set second = 60 => minute += 1, second = 0
    actualDate = Date(117, 2, 13, 10, 01, 60);
    expected = (string) "Mar 13, 2017 10:02:00 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());

    // Set second = 150 => minute += 2, second = 30
    actualDate = Date(117, 2, 13, 10, 01, 150);
    expected = (string) "Mar 13, 2017 10:03:30 AM";
    actualString = actualDate.toLocaleString();
    ASSERT_STR(expected, actualString.toString());
}

TEST(JavaUtil, DateUTC) {
    // Create variable to test
    Date expected = Date();
    Date actual = Date();
    long timeActual;
    int localTimeZoneInHours = - actual.getTimezoneOffset() / 60;
    int changeDay;

    if (localTimeZoneInHours > 0) {
        changeDay = 1;
    } else {
        changeDay = -1;
    }

    // Valid case
    expected 	= Date(2017, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // TODO(thoangminh): This case return different result with Travis-ci
//    // Set year = 1900. Not work correctly
//    expected 	= Date(1900, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(1900, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    ASSERT_EQUAL(expected.getYear(), actual.getYear());
//    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
//    ASSERT_EQUAL(expected.getDate(), actual.getDate());
//    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
//    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
//    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set year = 3000
    expected 	= Date(3000, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(3000, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set year = 1889
    expected 	= Date(1889, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(1889, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set year = -1. Not work correctly
    expected 	= Date(-1, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(-1, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set year = -900. Not work correctly
    expected 	= Date(-900, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(-900, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set year = 0
    expected 	= Date(1900, 2, 13, 10, 01, 13);
    timeActual 	= Date::UTC(1900, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_NOT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_NOT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 12 => Year+= 1 , month = 0.
    expected 	= Date(2018, 0, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 12, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 33 => Year+= 2, month = 9.
    expected 	= Date(2019, 9, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 33, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 0
    expected 	= Date(2017, 0, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 0, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -1 => Year-= 1, month = 11.
    expected 	= Date(2016, 11, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, -1, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -12 => Year-= 1, month = 0.
    expected 	= Date(2016, 0, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, -12, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = -33 => Year-= 3, month = 3.
    expected 	= Date(2014, 3, 13, 10, 01, 13);
    timeActual 	= Date::UTC(2017, -33, 13, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 3, date = -1 => month = 2, date = 30
    expected 	= Date(2017, 2, 30, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 3, -1, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 6, date = -75 => month = 3, date = 16
    expected 	= Date(2017, 3, 16, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 6, -75, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 3, date = 0 => month = 2, date = 31
    expected 	= Date(2017, 2, 31, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 3, 0, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 2, date = 0 => month = 1, date = 28
    expected 	= Date(2017, 1, 28, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 0, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set month = 5, date = 32 => month = 6, date = 2
    expected 	= Date(2017, 6, 2, 10, 01, 13);
    timeActual 	= Date::UTC(2017, 5, 32, 10, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = -1 => day -= 1, hour = 23
    expected 	= Date(2017, 2, 12, 23, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, -1, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

     // Set hour = 0
    expected 	= Date(2017, 2, 13, 0, 01, 13);
    timeActual  = Date::UTC(2017, 2, 13, 0, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate() + changeDay);
    ASSERT_EQUAL(expected.getHours(), ((actual.getHours() + localTimeZoneInHours) % 24) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 24. Day += 1, hour = 0
    expected 	= Date(2017, 2, 14, 0, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 24, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate() + changeDay);
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set hour = 49. Day += 2, hour = 1
    expected 	= Date(2017, 2, 15, 1, 01, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 49, 01, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate() + changeDay);
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = -1 => hour -= 1, minute = 59
    expected 	= Date(2017, 2, 13, 9, 59, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, -1, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected 	= Date(2017, 2, 13, 10, 0, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 0, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 60 => hour += 1, minute = 0
    expected 	= Date(2017, 2, 13, 11, 00, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 60, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 150 => hour += 2, minute = 30
    expected 	= Date(2017, 2, 13, 12, 30, 13);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 150, 13);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = -1 => minute -= 1, second = 59
    expected 	= Date(2017, 2, 13, 10, 00, 59);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, -1);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected 	= Date(2017, 2, 13, 10, 01, 0);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 0);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = 60 => minute += 1, second = 0
    expected 	= Date(2017, 2, 13, 10, 02, 00);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 60);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());

    // Set second = 150 => minute += 2, second = 30
    expected 	= Date(2017, 2, 13, 10, 03, 30);
    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 150);
    actual = Date(timeActual);
    ASSERT_EQUAL(expected.getYear(), actual.getYear());
    ASSERT_EQUAL(expected.getMonth(), actual.getMonth());
    ASSERT_EQUAL(expected.getDate(), actual.getDate());
    ASSERT_EQUAL(expected.getHours(), (actual.getHours() + localTimeZoneInHours) % 24);
    ASSERT_EQUAL(expected.getMinutes(), actual.getMinutes());
    ASSERT_EQUAL(expected.getSeconds(), actual.getSeconds());
}