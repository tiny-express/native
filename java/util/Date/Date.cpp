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

#include <malloc.h>
#include "Date.hpp"

/**
 * Only default constructor can refresh new time
 * Every single set value to this class will remove refreshFlag - mean this class will be not available to refresh new time
 * @return
 */
Date::Date() {
    initialize(time(nullptr));
}

Date::Date(int year, int month, int date) {
    initialize(year, month, date, 0, 0, 0);
}

Date::Date(int year, int month, int date, int hrs, int min) {
    initialize(year, month, date, hrs, min, 0);
}

Date::Date(int year, int month, int date, int hrs, int min, int sec) {
    initialize(year, month, date, hrs, min, sec);
}

Date::Date(long date) {
    time_t timer = date;
    initialize(timer);
}

// TODO(thoangminh): Check this method later
//Date::Date(String s) {
//	this->refreshFlag = false;
//	this->original = Date::parse(s);
//	Date::updateLocalTimer();
//}

Date::~Date() {
}

// TODO(thoangminh): Need to check all methods below
void Date::setDate(int date) {
    this->localTimer->tm_mday = date;
    update();
}

void Date::setHours(int hours) {
    this->localTimer->tm_hour = hours;
    update();
}

void Date::setMinutes(int minutes) {
    this->localTimer->tm_min = minutes;
    update();
}

void Date::setMonth(int month) {
    this->localTimer->tm_mon = month;
    update();
}

void Date::setSeconds(int seconds) {
    this->localTimer->tm_sec = seconds;
    update();
}

void Date::setTime(long time) {
    initialize(time);
}

void Date::setYear(int year) {
    // LocalTimer just keep year since 1900
    this->localTimer->tm_year = year % 1900;
    update();
}

int Date::getDate() {
    return this->mday;
}

int Date::getDay() {
    int result = this->wday;

    switch (result) {
        case 0: return 4;
        case 1: return 5;
        case 2: return 6;
        case 3: return 0;
        case 4: return 1;
        case 5: return 2;
        case 6: return 3;
    }

    return result;
}

int Date::getHours() {
    return this->hour;
}

int Date::getMinutes() {
    return this->min;
}

int Date::getMonth() {
    return this->mon;
}

int Date::getSeconds() {
    return this->sec;
}

int Date::getYear() {
    return this->year + 1900;
}

long Date::getTime() {
    return this->original;
}

int Date::getTimezoneOffset() {
    auto result = static_cast<int> (- this->gmtoff / 60);

    return result;
}

boolean Date::after(Date when) {
	if (this->original > when.original) {
		return true;
	}

	return false;
}

boolean Date::before(Date when) {
	if (this->original < when.original) {
		return true;
	}

	return false;
}

int Date::compareTo(Date anotherDate) {
	long temp = this->original - anotherDate.original;

	if (temp < 0) {
		return -1;
	}

    if (temp > 0) {
        return 1;
    }

    return 0;
}

//String Date::toGMTString() {
//	if (this->refreshFlag) {
//		initialize(time(nullptr));
//	}
//
//	tm *gmTimer = gmtime(&this->original);
//
//	string timeString = this->toString0(gmTimer);
//	String result = timeString;
//
//	free(timeString);
//	return result;
//}

String Date::toString() {
    auto format = (string) "%a %b %d %T UTC %Y";
    string convertResult = this->timeToString(format, this->localTimer);
    String result = convertResult;
    free(convertResult);

    return result;
}

long Date::UTC(int year, int month, int date, int hrs, int min, int sec) {
    Date tempDate = Date(year, month, date, hrs, min, sec);
    long result = tempDate.getTime() + tempDate.getTimezoneOffset() * 60;

    return result;
}

Date Date::clone() {
    Date clone = *this;
    return clone;
}

//long Date::parse(String inputString) {
//    tm timer = {0};
//    long result;
//

//    // strptime(timeString, "%a %b %d %Y %H:%M:%S", &timer);
////    string timeString = inputString.toString();
//
//    result = Date::initialize(timer.tm_year, timer.tm_mon, timer.tm_mday,
//                            timer.tm_hour, timer.tm_min, timer.tm_sec);
//    return result;
//}

String Date::toLocaleString() {
    auto format = (string) "%b %d, %Y %I:%M:%S %p";
    string convertResult = this->timeToString(format, this->localTimer);
    String result = convertResult;
    free(convertResult);

    return result;
}