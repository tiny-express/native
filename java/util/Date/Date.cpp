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

#include <chrono>
#include "Date.hpp"

boolean Date::isUTC = false;

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
//	this->timer = Date::parse(s);
//	Date::updateLocalTimer();
//}

Date::~Date() {
}

// TODO(thoangminh): Need to check all methods below
void Date::setDate(int date) {
    initialize(this->year, this->mon, date,
           this->hour, this->min, this->sec);
}

void Date::setHours(int hours) {
    initialize(this->year, this->mon, this->mday,
           hours, this->min, this->sec);
}

void Date::setMinutes(int minutes) {
    initialize(this->year, this->mon, this->mday,
           this->hour, minutes, this->sec);
}

void Date::setMonth(int month) {
    initialize(this->year, month, this->mday,
           this->hour, this->min, this->sec);
}

void Date::setSeconds(int seconds) {
    initialize(this->year, this->mon, this->mday,
               this->hour, this->min, seconds);
}

void Date::setTime(long time) {
    initialize(time);
}

void Date::setYear(int year) {
    initialize(year % 1900, this->mon, this->mday,
               this->hour, this->min, this->sec);
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
    return this->timer;
}

int Date::getTimezoneOffset() {
    auto result = static_cast<int> (- this->gmtoff / 60);

    return result;
}

boolean Date::after(Date when) {
    if (this->timer > when.timer) {
        return true;
    }

    return false;
}

boolean Date::before(Date when) {
    if (this->timer < when.timer) {
        return true;
    }

    return false;
}

int Date::compareTo(Date anotherDate) {
    long temp = this->timer - anotherDate.timer;

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
//	tm *gmTimer = gmtime(&this->timer);
//
//	string timeString = this->toString0(gmTimer);
//	String result = timeString;
//
//	free(timeString);
//	return result;
//}

String Date::toString() {
    auto format = (string) "%a %b %d %T %Z %Y";

    if (Date::isUTC) {
        format = (string) "%a %b %d %T UTC %Y";
    }

    string convertResult = timeToString(format);
    String result = convertResult;
    free(convertResult);

    return result;
}

long Date::UTC(int year, int month, int date, int hrs, int min, int sec){
    Date tempDate = Date(year, month, date, hrs, min, sec);
    long result = tempDate.getTime() + tempDate.getTimezoneOffset() * 60;

    return result;
}

Date Date::clone() {
    Date clone = *this;
    return clone;
}

String Date::toLocaleString() {
    auto format = (string) "%b %d, %Y %I:%M:%S %p";
    string convertResult = this->timeToString(format);
    String result = convertResult;
    free(convertResult);

    return result;
}

long Date::parse(String inputString, string format) {
//    long result = Date::parseStringToTime(inputString);
//    if (result == -1) {
//        throw new IllegalArgumentException("syntax error");
//    }

    std::tm localTimer = {};
    strptime(inputString.toString(), format, &localTimer);
    return mktime(&localTimer);
}

string Date::getZone() {
    return (string) this->zone;
}

void Date::setUTC(boolean isUTC) {
    this->isUTC = isUTC;
}
