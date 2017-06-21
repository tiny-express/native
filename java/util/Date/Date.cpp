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

//Date::Date(int year, int month, int date) {}

//Date::Date(int year, int month, int date, int hrs, int min) {}

//Date::Date(int year, int month, int date, int hrs, int min, int sec) {}

Date::Date(long date) {
    this->original = date;
}

//Date::Date(String s) {}

boolean Date::after(Date when) {

}

boolean Date::before(Date when) {

}

int Date::compareTo(Date anotherDate) {

}

boolean Date::equals(Object obj) {

}

int Date::getDate() {

}

int Date::getDay() {
    refreshTime();

    tm *local = localtime(&this->original);
    int day = local->tm_mday;

    return day;
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

}

int	Date::getYear() {

}

int	Date::hashCode() {

}
//
//static long	Date::parse(String s) {
//
//}

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

}

//static long	Date::UTC(int year, int month, int date, int hrs, int min, int sec) {
//
//}