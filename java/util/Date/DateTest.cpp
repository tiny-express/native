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

#include "../../../kernel/Test.hpp"

#include "Date.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Util;

TEST(JavaUtil, DateConstructor) {
    // Get the current local time
    long now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);

    // Create variable to test
    Date date;

    // Test Date(). This class return since 1900
    assertEquals(currentTime->tm_year, date.getYear());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    assertEquals(2017, date.getYear());
    assertEquals(02, date.getMonth());
    assertEquals(13, date.getDate());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    assertEquals(2017, date.getYear());
    assertEquals(02, date.getMonth());
    assertEquals(13, date.getDate());
    assertEquals(8, date.getHours());
    assertEquals(01, date.getMinutes());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    assertEquals(2017, date.getYear());
    assertEquals(02, date.getMonth());
    assertEquals(13, date.getDate());
    assertEquals(8, date.getHours());
    assertEquals(01, date.getMinutes());
    assertEquals(13, date.getSeconds());

    // Test Date(long date)
    date = Date(1498042091);  // 2017
    assertEquals(117, date.getYear());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate;
    sameDate = date;
    assertEquals(sameDate.getYear(), date.getYear());
    assertEquals(sameDate.getMonth(), date.getMonth());
    assertEquals(sameDate.getDate(), date.getDate());
    assertEquals(sameDate.getHours(), date.getHours());
    assertEquals(sameDate.getMinutes(), date.getMinutes());
    assertEquals(sameDate.getSeconds(), date.getSeconds());

    // Test Date::Date(String inputString)
    // Create variable to test
    Date expected;
    Date actualDate;
    String actualString;

    // Valid case
    expected = Date(114, 0, 9, 12, 35, 34);
    actualString = "Thu Jan 9 (and) 2014 12:35:34";
    actualDate = Date(actualString);
    assertEquals(expected.toString(), actualDate.toString());
}

TEST(JavaUtil, DateSetYear) {
    // Create variable to test
    Date date;

    // year = 1900, "the epoch" year
    date.setYear(1900);
    assertEquals(1900, date.getYear());

    // year > 1900
    date.setYear(3000);
    assertEquals(3000, date.getYear());

    // year < 1900
    date.setYear(1889);
    assertEquals(1889, date.getYear());

    // year < 0
    date.setYear(-1);
    assertEquals(-1, date.getYear());

    // year = 0
    date.setYear(0);
    assertEquals(0, date.getYear());

    // year = 4000
    date.setYear(4000);
    assertEquals(4000, date.getYear());
}

TEST(JavaUtil, DateGetYear) {
    // Create variable to test
    Date date;

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    assertEquals(2017, date.getYear());

    // Test Date(int year, int month, int date)
    date = Date(4000, 02, 13);
    assertEquals(4000, date.getYear());

}

TEST(JavaUtil, DateSetMonth) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set month = 12 => Year+= 1 , month = 0.
    expected = Date(2018, 0, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(12);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = 33 => Year+= 2, month = 9.
    expected = Date(2019, 9, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(33);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = 0
    expected = Date(2017, 0, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(0);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = -1 => Year-= 1, month = 11.
    expected = Date(2016, 11, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(-1);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = -12 => Year-= 1, month = 0.
    expected = Date(2016, 0, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(-12);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = -33 => Year-= 3, month = 3.
    expected = Date(2014, 3, 13, 10, 01, 13);
    actual 	 = Date(2017, 1, 13, 10, 01, 13);
    actual.setMonth(-33);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetMonth) {
    // Create variable to test
    Date date;

    // Assign date value
    date = Date(2017, 02, 13);
    assertEquals(2, date.getMonth());
}

TEST(JavaUtil, DateSetDate) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set month = 3, date = -1 => month = 2, date = 30
    expected = Date(2017, 2, 30, 10, 01, 13);
    actual 	 = Date(2017, 3, 1, 10, 01, 13);
    actual.setDate(-1);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = 6, date = -75 => month = 3, date = 16
    expected = Date(2017, 3, 16, 10, 01, 13);
    actual 	 = Date(2017, 6, 1, 10, 01, 13);
    actual.setDate(-75);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = 3, date = 0 => month = 2, date = 31
    expected = Date(2017, 2, 31, 10, 01, 13);
    actual 	 = Date(2017, 3, 1, 10, 01, 13);
    actual.setDate(0);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = 2, date = 0 => month = 1, date = 28
    expected = Date(2017, 1, 28, 10, 01, 13);
    actual 	 = Date(2017, 2, 1, 10, 01, 13);
    actual.setDate(0);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set month = 5, date = 32 => month = 6, date = 2
    expected = Date(2017, 6, 2, 10, 01, 13);
    actual 	 = Date(2017, 5, 1, 10, 01, 13);
    actual.setDate(32);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetDate) {
    // Create variable to test
    Date date;

    // Assign date value
    date = Date(2017, 02, 13);
    assertEquals(13, date.getDate());
}

TEST(JavaUtil, DateSetHours) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set hour = -1 => date -= 1, hour = 23
    expected = Date(2017, 2, 12, 23, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(-1);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set hour = -58 => date -= 3, hour = 14
    expected = Date(2017, 2, 10, 14, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(-58);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set hour = 0
    expected = Date(2017, 2, 13, 0, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(0);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set hour = 24. Day += 1, hour = 0
    expected = Date(2017, 2, 14, 0, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(24);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set hour = 49. Day += 2, hour = 1
    expected = Date(2017, 2, 15, 1, 01, 13);
    actual 	 = Date(2017, 2, 13, 1, 01, 13);
    actual.setHours(49);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetHour) {
    // Create variable to test
    Date date;

    // Assign date value
    date = Date(2017, 02, 13, 8, 01);
    assertEquals(8, date.getHours());
}

TEST(JavaUtil, DateSetMinutes) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set minute = -1 => hour -= 1, minute = 59
    expected = Date(2017, 2, 13, 9, 59, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(-1);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected = Date(2017, 2, 13, 10, 0, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(0);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set minute = 60 => hour += 1, minute = 0
    expected = Date(2017, 2, 13, 11, 00, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(60);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set minute = 150 => hour += 2, minute = 30
    expected = Date(2017, 2, 13, 12, 30, 13);
    actual 	 = Date(2017, 2, 13, 10, 1, 13);
    actual.setMinutes(150);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetMinutes) {
    // Create variable to test
    Date date;

    // Get the current local time
    long now = time(nullptr);
    tm tempCurrentTime;
    tm *currentTime = localtime_r(&now, &tempCurrentTime);
    assertEquals(currentTime->tm_min, date.getMinutes());

    // Test Date(int year, int month, int date)
    date = Date(2017, 02, 13);
    assertEquals(0, date.getMinutes());

    // Test Date(int year, int month, int date, int hrs, int min)
    date = Date(2017, 02, 13, 8, 01);
    assertEquals(01, date.getMinutes());

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    assertEquals(01, date.getMinutes());

    // Test Date(long date)
    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
    date = Date(tempDate.getTime());
    assertEquals(01, date.getMinutes());

    // Test Date sameDate = date;
    date = Date(2017, 02, 13, 8, 01, 13);
    Date sameDate = date;
    assertEquals(01, sameDate.getMinutes());
}

TEST(JavaUtil, DateSetSeconds) {
    // Create variable to test
    Date expected;
    Date actual;

    // Set second = -1 => minute -= 1, second = 59
    expected = Date(2017, 2, 13, 10, 00, 59);
    actual = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(-1);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set minute = 0
    expected = Date(2017, 2, 13, 10, 01, 0);
    actual = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(0);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set second = 60 => minute += 1, second = 0
    expected = Date(2017, 2, 13, 10, 02, 00);
    actual = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(60);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());

    // Set second = 150 => minute += 2, second = 30
    expected = Date(2017, 2, 13, 10, 03, 30);
    actual = Date(2017, 2, 13, 10, 01, 1);
    actual.setSeconds(150);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateGetSeconds) {
    // Create variable to test
    Date date;

    // Assign date value
    date = Date(2017, -28, 13, 8, 01, 13);
    assertEquals(13, date.getSeconds());
}

TEST(JavaUtil, DateGetTime) {
    // Create variable to test
    Date date;

    // Test the current local time
    long now = time(nullptr);
    assertEquals(now, date.getTime());
}

TEST(JavaUtil, DateSetTime) {
    // Create variable to test
    Date tempDate;
    Date date;
    long tempTime;

    // Test Date(int year, int month, int date)
    tempDate = Date(2017, 02, 13);
    tempTime = tempDate.getTime();
    date.setTime(tempTime);
    assertEquals(2017, date.getYear());
    assertEquals(02, date.getMonth());
    assertEquals(13, date.getDate());
    assertEquals(0, date.getHours());
    assertEquals(0, date.getMinutes());
    assertEquals(0, date.getSeconds());
}

TEST(JavaUtil, DateGetDay) {
    // Create variable to test
    Date date;

    // Test Sun - value 0
    date = Date(117, 8, 17, 8, 01, 13);
    assertEquals(0, date.getDay());
}

TEST(JavaUtil, DateAfter) {
    // Create variable to test
    Date date;
    Date tempDate = Date(2017, 8, 10, 8, 01, 13);;

    // Test case TRUE
    date = Date(2017, 8, 11, 8, 01, 13);
    assertTrue(date.after(tempDate));

    // Test case FALSE
    date = Date(2017, 8, 10, 8, 01, 13);
    assertFalse(date.after(tempDate));
}

TEST(JavaUtil, DateBefore) {
    // Create variable to test
    Date date;
    Date tempDate = Date(2017, 8, 10, 8, 01, 13);;

    // Test case TRUE
    date = Date(2017, 8, 6, 8, 01, 13);
    assertTrue(date.before(tempDate));

    // Test case FALSE
    date = Date(2017, 8, 10, 8, 01, 13);
    assertFalse(date.before(tempDate));
}

TEST(JavaUtil, DateClone) {
    // Create variable to test
    Date tempDate;
    Date date;

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    tempDate = Date(2017, 02, 13, 8, 01, 13);
    date = tempDate.clone();
    assertEquals(2017, date.getYear());
    assertEquals(02, date.getMonth());
    assertEquals(13, date.getDate());
    assertEquals(8, date.getHours());
    assertEquals(01, date.getMinutes());
    assertEquals(13, date.getSeconds());
}

TEST(JavaUtil, DateCompareTo) {
    // Create variable to test
    Date date;
    Date temp = Date(2017, 02, 13, 8, 01, 13);

    date = Date(2017, 02, 12, 8, 01, 13);
    assertEquals(-1, date.compareTo(temp));

    date = Date(2017, 02, 13, 8, 01, 13);
    assertEquals(0, date.compareTo(temp));

    date = Date(2017, 02, 14, 8, 01, 13);
    assertEquals(1, date.compareTo(temp));

    Comparable<Date> *notEqualDate = &date;
    assertEquals(1, notEqualDate->compareTo(temp));
}

TEST(JavaUtil, DateHashCode) {
    Date date = Date(2017, 02, 14, 8, 01, 13);
    long expected = date.getTime();
    long actual = date.hashCode();
    assertEquals(expected, actual);
}

TEST(JavaUtil, DateGetTimezoneOffset) {
    // Create variable to test
    Date date;
    int expectedResult;

    long now = time(nullptr);
    tm tempLocalTimer = {0};
    tm *localTimer = localtime_r(&now, &tempLocalTimer);
    expectedResult = static_cast<int> (- localTimer->tm_gmtoff / 60);

    // Test Date(int year, int month, int date, int hrs, int min, int sec)
    date = Date(2017, 02, 13, 8, 01, 13);
    assertEquals(expectedResult, date.getTimezoneOffset());
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
    assertEquals(expected, actual.toString());
}

TEST(JavaUtil, DateUTC) {
    // Create variable to test
    Date expected;
    String expectedString;
    Date actual;
    long timeActual;
    long utcTime;

    // Valid case
    expected = Date(2017, 2, 13, 10, 01, 13);
    timeActual = Date::UTC(2017, 2, 13, 10, 01, 13);
    actual = Date(timeActual);
    utcTime = expected.getTime() + expected.getTimezoneOffset() * 60;
    expected.setTime(utcTime);
    assertEquals(expected.getYear(), actual.getYear());
    assertEquals(expected.getMonth(), actual.getMonth());
    assertEquals(expected.getDate(), actual.getDate());
    assertEquals(expected.getHours(), actual.getHours());
    assertEquals(expected.getMinutes(), actual.getMinutes());
    assertEquals(expected.getSeconds(), actual.getSeconds());
}

TEST(JavaUtil, DateToString) {
    // Create variable to test
    Date actualDate = Date();
    String expected;
    String actual;

    tzset();
    extern char *tzname[2];
    String zone = (string) tzname[0];

    // Valid case
    actualDate = Date(117, 2, 13, 10, 01, 13);
    expected = "Mon Mar 13 10:01:13 " + zone + (string) " 2017";
    actual = actualDate.toString();
    assertEquals(expected.toString(), actual.toString());
}

TEST(JavaUtil, DateToGMTString) {
    Date expected = Date("13 Mar 2017 10:03:30 GMT");
    Date actualDate = Date("13 Mar 2017 10:03:30 UTC");
    assertEquals(expected.toGMTString().toString(), actualDate.toGMTString().toString());
}

TEST(JavaUtil, DateParse) {
    // Create variable to test
    Date expected;

    Date   actualDate;
    String actualString;
    long   actualTime;

    // Empty String
    actualString = "";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // String with bracket
    expected = Date(114, 0, 9, 12, 35, 34);
    actualString = "Thu Jan 9 (ababa) (and ) 2014 12:35:34";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Short date pattern. (en-US)
    expected = Date(117, 1, 13);
    actualString = "02/13/2017";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Short date pattern. (en-US)
    expected = Date(117, 1, 13);
    actualString = "02/13/17";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Long date pattern. (en-US)
    expected = Date(109, 5, 15);
    actualString = "Monday, June 15, 2009";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Full date/time pattern with PM
    expected = Date(109, 5, 15, 13, 45);
    actualString = "Monday, June 15, 2009 1:45 PM";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Full date/time pattern with AM
    expected = Date(109, 5, 15, 1, 45);
    actualString = "Monday, June 15, 2009 1:45 AM";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Full date/time pattern with AM and hour = 12
    expected = Date(109, 5, 15, 0, 45);
    actualString = "Monday, June 15, 2009 12:45 AM";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Date time with TimeZone
    expected = Date("Mon Jun 15 20:45:30 GMT 2009");
    actualString = "Mon, 15 Jun 2009 20:45:30 UTC";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Date time with TimeZoneOffset
    expected = Date("Sun Jun 14 21:15:30 GMT 2009");
    actualString = "Monday, June 15, 2009 1:45:30 +0430";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Date time with TimeZone UTC and TimeZoneOffset
    expected = Date("Sun Jun 14 21:15:30 GMT 2009");;
    actualString = "Monday, June 15, 2009 1:45:30 UTC +0430";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Date time with TimeZone GMT and TimeZoneOffset
    expected = Date("Sun Jun 14 21:15:30 GMT 2009");;
    actualString = "Monday, June 15, 2009 1:45:30 GMT +0430";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Date time with TimeZone UT and TimeZoneOffset
    expected = Date("Sun Jun 14 21:15:30 GMT 2009");
    actualString = "Monday, June 15, 2009 1:45:30 UT +0430";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Full date/time pattern with TimeZoneOffset as hour
    expected = Date("Sun Jun 14 18:45:30 GMT 2009");
    actualString = "Monday, June 15, 2009 1:45:30 UTC +7";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Full date/time pattern with Year < 100 as hour
    expected = Date("Sun Jun 14 18:45:30 GMT 2009");
    actualString = "Monday, June 15, 9 1:45:30 UTC +7";
    actualTime = Date::parse(actualString);
    actualDate = Date(actualTime);
    assertEquals(expected.toString(), actualDate.toString());

    // Input String with ignored character
    actualString = "Monday, 2009 June 15, 2009 1:45:30 UTC +7";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Input String with ignored character
    actualString = "Monday, June 15, 80x 1:45:30 UTC+7";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Input String with ignored character
    actualString = "Monday, abc June 15, 2009 1:45:30 UTC+0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Input String hour > 12 and has AM
    actualString = "Monday, June 15, 2009 13:45:30 AM";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Input String hour > 12 and has PM
    actualString = "Monday, June 15, 2009 13:45:30 PM";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with TimeZone not UTC || UT || GMT and TimeZoneOffset
    actualString = "Monday, June 15, 2009 1:45:30 EST+0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with more than one time sequence
    actualString = "Monday, June 15, 2009 1:45:30 12:12 UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with more than one date sequence
    actualString = "Monday, June 15, 20/6/2017 2009 1:45:30 UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with ignored symbol after number
    actualString = "Monday, June 15x 2009 1:45:30 UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with number does not belong to date, time or timeZone sequence
    actualString = "Monday, June 15, 2009 1:45:30 12 UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with accepted word does not belong to date, time or timeZone sequence
    actualString = "Monday, June 15, 2009 1:45:30 June UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // Full date/time pattern with ignored symbol
    actualString = "Monday, * June 15, 2009 1:45:30 UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }

    // String without date
    actualString = "1:45:30 UTC +0430";
    try {
    actualTime = Date::parse(actualString);
    }
    catch (IllegalArgumentException &e) {
    assertTrue(e.getMessage().isEmpty());
    }
}

TEST(JavaUtil, DateEquals) {
    // Create Variable to test
    Date largerDate = Date(2014, 10, 15);
    Date smallerDate = Date(2014, 10, 16);
    Date equalToLargerDate = Date(2014, 10, 15);

    //
    assertTrue(largerDate.equals(equalToLargerDate));
    assertFalse(largerDate.equals(smallerDate));
}