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

#include "Date.hpp"

/**
 * Only default constructor can refresh new time
 * Every single set value to this class will remove refreshFlag - mean this class will be not available to refresh new time
 * @return
 */
Date::Date() {
	this->refreshFlag = true;
	refreshTime();
}

Date::Date(const Date &inputDate) {
	this->refreshFlag = false;
	this->original = inputDate.original;
    Date::updateLocalTimer();
}

Date::Date(int year, int month, int date) {
	this->refreshFlag = false;
	this->original = Date::UTC(year, month, date, 0, 0, 0);
    time_t now = time(nullptr);
	Date::updateLocalTimer();
}

Date::Date(int year, int month, int date, int hrs, int min) {
	this->refreshFlag = false;
	this->original = Date::UTC(year, month, date, hrs, min, 0);
	Date::updateLocalTimer();
}

Date::Date(int year, int month, int date, int hrs, int min, int sec) {
	this->refreshFlag = false;
	this->original = Date::UTC(year, month, date, hrs, min, sec);
	Date::updateLocalTimer();
}

Date::Date(long date) {
	this->refreshFlag = false;
	this->original = date;
	Date::updateLocalTimer();
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
    this->refreshFlag = false;

    this->localTimer->tm_mday = date;
}

void Date::setHours(int hours) {
    this->refreshFlag = false;

    this->localTimer->tm_hour = hours;
    this->updateOriginal();
}

void Date::setMinutes(int minutes) {
    this->refreshFlag = false;

    this->localTimer->tm_min = minutes;
    this->updateOriginal();
}

void Date::setMonth(int month) {
    this->refreshFlag = false;

    this->localTimer->tm_mon = month;
    this->updateOriginal();
}

void Date::setSeconds(int seconds) {
    this->refreshFlag = false;

    this->localTimer->tm_sec = seconds;
    this->updateOriginal();
}

void Date::setTime(long time) {
    this->refreshFlag = false;

    this->original = time;
    this->updateLocalTimer();
}

void Date::setYear(int year) {
    this->refreshFlag = false;

    // LocalTimer just keep year since 1900
    this->localTimer->tm_year = year % 1900;
    this->updateOriginal();
}

int Date::getDate() {
    if (this->refreshFlag) {
        refreshTime();
    }

    int result = this->localTimer->tm_mday;

    return result;
}

int Date::getDay() {
    if (this->refreshFlag) {
        refreshTime();
    }

    int result = this->localTimer->tm_wday;

    switch (result) {
        case 0: return 4;
        case 1: return 5;
        case 2: return 6;
        case 3: return 0;
        case 4: return 1;
        case 5: return 2;
        case 6: return 3;
    }
}

int Date::getHours() {
    if (this->refreshFlag) {
        refreshTime();
    }

    int result = this->localTimer->tm_hour;
    return result;
}

int Date::getMinutes() {
    if (this->refreshFlag) {
        refreshTime();
    }

    int result = this->localTimer->tm_min;
    return result;
}

int Date::getMonth() {
    if (this->refreshFlag) {
        refreshTime();
    }

    int result = this->localTimer->tm_mon;
    return result;
}

int Date::getSeconds() {
    if (this->refreshFlag) {
        refreshTime();
    }

    int result = this->localTimer->tm_sec;
    return result;
}

int Date::getYear() {
    if (this->refreshFlag) {
        refreshTime();
    }

    // LocalTimer just keep tm_year since 1900
    int result = this->localTimer->tm_year + 1900;

    return result;
}

long Date::getTime() {
    if (this->refreshFlag) {
        refreshTime();
    }

    long result = this->original;
    return result;
}

int Date::getTimezoneOffset() {
    return this->timezoneOffset;
}

boolean Date::after(Date when) {
	if (this->refreshFlag) {
		refreshTime();
	}

	if (this->original > when.original) {
		return true;
	}

	return false;
}

boolean Date::before(Date when) {
	if (this->refreshFlag) {
		refreshTime();
	}

	if (this->original < when.original) {
		return true;
	}

	return false;
}

int Date::compareTo(Date anotherDate) {
	if (this->refreshFlag) {
		refreshTime();
	}

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
//		refreshTime();
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
	if (this->refreshFlag) {
		refreshTime();
	}

    auto format = (string) "%a %b %d %T UTC %Y";
	return this->timeToString(format, this->localTimer);
}

long Date::UTC(int year, int month, int date, int hrs, int min, int sec) {
    long result;
    tm localTimer = { 0 };

    localTimer.tm_year = year % 1900;
    localTimer.tm_mon = month;
    localTimer.tm_mday = date;
    localTimer.tm_hour = hrs;
    localTimer.tm_min = min;
    localTimer.tm_sec = sec;

    result = mktime(&localTimer);

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
//    // TODO(anhkhoa): Fix for WIN32
//    // strptime(timeString, "%a %b %d %Y %H:%M:%S", &timer);
////    string timeString = inputString.toString();
//
//    result = Date::UTC(timer.tm_year, timer.tm_mon, timer.tm_mday,
//                            timer.tm_hour, timer.tm_min, timer.tm_sec);
//    return result;
//}

String Date::toLocaleString() {
    if (this->refreshFlag) {
        refreshTime();
    }

    auto format = (string) "%b %d, %Y %I:%M:%S %p";
    return this->timeToString(format, this->localTimer);
}