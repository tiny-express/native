/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

Date::Date() {
    refreshTime();
}

Date::Date(const Date &target) {
    this->original = target.original;
}

Date::Date(int year, int month, int date) {
    this->original = Date::UTC(year, month, date, 0, 0, 0);
}

Date::Date(int year, int month, int date, int hrs, int min) {
    this->original = Date::UTC(year, month, date, hrs, min, 0);
}

Date::Date(int year, int month, int date, int hrs, int min, int sec) {
    this->original = Date::UTC(year, month, date, hrs, min, sec);
}

Date::Date(long date) {
    this->original = date;
}

Date::Date(String s) {
    //Sample: Thu Jan 9 2014 12:35:34
    tm timePresenter;
    string timeString = s.toString();

    strptime(timeString, "%a %b %d %Y %H:%M:%S", &timePresenter);

    this->original = Date::UTC(timePresenter.tm_year, timePresenter.tm_mon, timePresenter.tm_mday, timePresenter.tm_hour, timePresenter.tm_min, timePresenter.tm_sec);
}

Date::~Date() {
}

boolean Date::after(Date when) {

}

boolean Date::before(Date when) {

}

int Date::compareTo(Date anotherDate) {

}

int Date::getDate() {

}

int Date::getDay() {

}

int	Date::getHours() {

}

int	Date::getMinutes() {

}

int	Date::getMonth() {

}

int	Date::getSeconds() {

}

long Date::getTime() {

}

int	Date::getTimezoneOffset() {
    // return Locale.hours - GMT.hours
}

int	Date::getYear() {
    refreshTime();

    int result = this->timePresenter->tm_year;
    return result;
}

void Date::setDate(int date) {

}

void Date::setHours(int hours) {

}

void Date::setMinutes(int minutes) {

}

void Date::setMonth(int month) {

}

void Date::setSeconds(int seconds) {

}

void Date::setTime(long time) {

}

void Date::setYear(int year) {

}

String Date::toGMTString() {

}

String Date::toLocaleString() {

}

String Date::toString() {
    return this->toLocaleString();
}