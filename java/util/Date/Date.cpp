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

Date::Date(const Date &target) {
	this->refreshFlag = false;
	this->original = target.original;
	this->localTimer = localtime(&this->original);
}

Date::Date(int year, int month, int date) {
	this->refreshFlag = false;
	this->original = Date::UTC(year, month, date, 0, 0, 0);
	this->localTimer = localtime(&this->original);
}

Date::Date(int year, int month, int date, int hrs, int min) {
	this->refreshFlag = false;
	this->original = Date::UTC(year, month, date, hrs, min, 0);
	this->localTimer = localtime(&this->original);
}

Date::Date(int year, int month, int date, int hrs, int min, int sec) {
	this->refreshFlag = false;
	this->original = Date::UTC(year, month, date, hrs, min, sec);
	this->localTimer = localtime(&this->original);
}

Date::Date(long date) {
	this->refreshFlag = false;
	this->original = date;
	this->localTimer = localtime(&this->original);
}

Date::Date(String s) {
	this->refreshFlag = false;
	this->original = Date::parse(s);
	this->localTimer = localtime(&this->original);
}

Date::~Date() {
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
	
	if (this->original > when.original) {
		return false;
	}
	
	return true;
}

int Date::compareTo(Date anotherDate) {
	if (this->refreshFlag) {
		refreshTime();
	}
	
	long temp = this->original - anotherDate.original;
	
	if (temp < 0) {
		return -1;
	} else if (temp == 0) {
		return 0;
	} else {
		return 1;
	}
	
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
	return result;
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
	
	int result = this->localTimer->tm_year + 1900; //LocalTimer just keep tm_year since 1900
	
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
	tm *globalTimer = gmtime(&this->original);
	int result = this->localTimer->tm_hour - globalTimer->tm_hour;
	return result;
}

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
	
	this->localTimer->tm_year = year % 1900; //LocalTimer just keep year since 1900
	this->updateOriginal();
}

String Date::toGMTString() {
	if (this->refreshFlag) {
		refreshTime();
	}
	
	tm *gmTimer = gmtime(&this->original);
	
	string timeString = this->toString0(gmTimer);
	String result = timeString;
	
	free(timeString);
	return result;
}

String Date::toLocaleString() {
	if (this->refreshFlag) {
		refreshTime();
	}
	
	string timeString = this->toString0(this->localTimer);
	String result = timeString;
	
	free(timeString);
	return result;
}

String Date::toString() {
	if (this->refreshFlag) {
		refreshTime();
	}
	
	return this->toLocaleString();
}