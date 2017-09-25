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
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"

/**
 * Only default constructor can refresh new time
 * Every single set value to this class will remove refreshFlag - mean this class will be not available to refresh new time
 * @return
 */
Date::Date() {
    initializeDate(time(nullptr));
}

Date::Date(int year, int month, int date) {
    initializeDate(year, month, date, 0, 0, 0);
}

Date::Date(int year, int month, int date, int hour, int minute) {
    initializeDate(year, month, date, hour, minute, 0);
}

Date::Date(int year, int month, int date, int hour, int minute, int second) {
    initializeDate(year, month, date, hour, minute, second);
}

Date::Date(long date) {
    long timer = date;
    initializeDate(timer);
}

Date::Date(String inputString) {
    long timer = Date::parse(inputString);
    initializeDate(timer);
}

Date::~Date() {
}

void Date::setDate(int date) {
    this->localTimer->tm_mday = date;
    updateDateStatus();
}

void Date::setHours(int hours) {
    this->localTimer->tm_hour = hours;
    updateDateStatus();
}

void Date::setMinutes(int minutes) {
    this->localTimer->tm_min = minutes;
    updateDateStatus();
}

void Date::setMonth(int month) {
    this->localTimer->tm_mon = month;
    updateDateStatus();
}

void Date::setSeconds(int seconds) {
    this->localTimer->tm_sec = seconds;
    updateDateStatus();
}

void Date::setTime(long time) {
    initializeDate(time);
}

void Date::setYear(int year) {
    // LocalTimer just keep year since 1900
    this->localTimer->tm_year = year % 1900;
    updateDateStatus();
}

int Date::getDate() {
    return this->dayOfMonth;
}

int Date::getDay() {
    int result = this->dayOfWeek;

    return result;
}

int Date::getHours() {
    return this->hour;
}

int Date::getMinutes() {
    return this->minute;
}

int Date::getMonth() {
    return this->month;
}

int Date::getSeconds() {
    return this->second;
}

int Date::getYear() {
    return this->year + 1900;
}

long Date::getTime() {
    return this->timer;
}

int Date::getTimezoneOffset() {
    int result = static_cast<int> (- this->gmtOffset / 60);

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

String Date::toString() {
    String pattern;

#ifdef LINUX
    if (this->getTimezoneOffset() == 0) {
        pattern = (string) "%a %b %d %T UTC %Y";
    }
#endif

#ifdef WINDOWS
    if (this->getTimezoneOffset() == 0) {
        pattern = (string) "%a %b %d %T GMT %Y";
    }
#endif

    pattern = (string) "%a %b %d %T %Z %Y";
    String convertResult = this->timeToString(pattern.toString(),
                                              this->localTimer);
    String result = convertResult;

    return result;
}

long Date::UTC(int year, int month, int date, int hour, int minute, int second) {
    Date tempDate = Date(year, month, date, hour, minute, second);
    long result = getUTCTime(tempDate.getTime());

    return result;
}

Date Date::clone() {
    Date clone = *this;
    return clone;
}

String Date::toLocaleString() {
    string pattern = (string) "%b %d, %Y %I:%M:%S %p";
    String convertResult = this->timeToString(pattern, this->localTimer);
    String result = convertResult;

    return result;
}

String Date::toGMTString() {
    string pattern;

#ifdef LINUX
    pattern = (string) "%a %b %d %T UTC %Y";
#endif

#ifdef WINDOWS
    pattern = (string) "%a %b %d %T GMT %Y";
#endif

    long utcTime = getUTCTime(this->timer);
    tm *utcTimer = localtime(&utcTime);

    String convertResult = this->timeToString(pattern, utcTimer);
    String result = convertResult;

    return result;
}

long Date::hashCode() {
    return this->timer;
}

String Date::removeIgnoredCharacter(String inputString) {
    int closeBracketOffSet = inputString.indexOf(')');
    int openBracketOffSet = inputString.indexOf('(');
    while (openBracketOffSet != -1 && closeBracketOffSet > openBracketOffSet ) {
        inputString = inputString.subString(0, openBracketOffSet) + inputString.subString(closeBracketOffSet + 1);
        openBracketOffSet = inputString.indexOf('(');
        closeBracketOffSet = inputString.indexOf(')');
    }

    return inputString;
}

long Date::parse(String inputString) {
//    int timeZoneOffset = 0;
//
//    tm localTimer = {};
//    String pattern = Date::getPattern(inputString, timeZoneOffset);
//    strptime(inputString.toString(), pattern.toString(), &localTimer);
//
//    long utcTime = mktime(&localTimer) + timeZoneOffset;
//
//    Date date = Date();
//
//    if (timeZoneOffset != 0) {
//        return utcTime - (date.getTimezoneOffset() * 60);
//    }
//
//    return utcTime;

    Array<String> wordTable = {
            "am", "pm",
            "monday", "tuesday", "wednesday", "thursday", "friday",
            "saturday", "sunday",
            "january", "february", "march", "april", "may", "june",
            "july", "august", "september", "october", "november", "december",
            "gmt", "ut", "utc", "est", "edt", "cst", "cdt",
            "mst", "mdt", "pst", "pdt"
    };

    Array<int> actionTable = {
            14, 1, 0, 0, 0, 0, 0, 0, 0,
            2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
            10000 + 0, 10000 + 0, 10000 + 0,    // GMT/UT/UTC
            10000 + 5 * 60, 10000 + 4 * 60,     // EST/EDT
            10000 + 6 * 60, 10000 + 5 * 60,     // CST/CDT
            10000 + 7 * 60, 10000 + 6 * 60,     // MST/MDT
            10000 + 8 * 60, 10000 + 7 * 60      // PST/PDT
    };

    DateTime dateTime = Date::DateTime();
    char previousChar = '\0';
    char curentChar;

    if (inputString.isEmpty()) {
        throw IllegalArgumentException();
    }

    inputString = Date::removeIgnoredCharacter(inputString);

    int limit = inputString.length() - 1;
    int index = -1;

    while (index < limit) {
        index++;
        curentChar = inputString.charAt(index);
        if (curentChar <= ' ' || curentChar == ',') {
            continue;
        }
        if (curentChar >= '0' && curentChar <='9') {
            int curentNumber = Date::getSequenceNumber(inputString.toString(), index);
            if (index < limit) {
                curentChar = inputString.charAt(index);
            }

            if (previousChar == '+' || previousChar == '-'
                                       && dateTime.year != Integer::MIN_VALUE) {
                // timezone offset
                if (curentNumber < 24) {
                    curentNumber = curentNumber * 60; // EG. "GMT-3"
                } else {
                    curentNumber = curentNumber % 100 + curentNumber / 100 * 60; // eg "GMT-0430"
                }

                if (previousChar == '+') {
                    curentNumber = -curentNumber;
                }   // plus means east of GMT

                if (dateTime.timeZoneOffset != 0 && dateTime.timeZoneOffset != -1) {
                    throw IllegalArgumentException();
                }

                dateTime.timeZoneOffset = curentNumber;
            } else if (curentNumber >= 70) {
                if (dateTime.year != Integer::MIN_VALUE) {
                    throw IllegalArgumentException();
                } else if (curentChar <= ' ' || curentChar == ','
                           || curentChar == '/' || index >= limit) {
                    dateTime.year = curentNumber;
                } else {
                    throw IllegalArgumentException();
                }
            } else if (curentChar == ':') {
                if (dateTime.hour < 0) {
                    dateTime.hour = (byte) curentNumber;
                } else if (dateTime.minute < 0) {
                    dateTime.minute = (byte) curentNumber;
                } else {
                    throw IllegalArgumentException();
                }
            } else if (curentChar == '/') {
                if (dateTime.month < 0) {
                    dateTime.month = (byte) (curentNumber - 1);
                } else if (dateTime.dayOfMonth < 0) {
                    dateTime.dayOfMonth = (byte) curentNumber;
                } else {
                    throw IllegalArgumentException();
                }
            } else if (index < limit && curentChar != ',' && curentChar > ' ' && curentChar != '-') {
                throw IllegalArgumentException();
            } else if (dateTime.hour >= 0 && dateTime.minute < 0) {
                dateTime.minute = (byte) curentNumber;
            } else if (dateTime.minute >= 0 && dateTime.second < 0) {
                dateTime.second = (byte) curentNumber;
            } else if (dateTime.dayOfMonth < 0) {
                dateTime.dayOfMonth = (byte) curentNumber;
            } else if (dateTime.year == Integer::MIN_VALUE && dateTime.month >= 0 && dateTime.dayOfMonth >= 0) {
                dateTime.year = curentNumber;
            } else {
                throw IllegalArgumentException();
            }
            previousChar = '\0';
        } else if (curentChar == '/' || curentChar == ':' || curentChar == '+' || curentChar == '-') {
            previousChar = curentChar;
        } else {
            int sequenceStart = index - 1;
            String curentWord = Date::getSequenceChar(inputString.toString(), index);
            if (index <= sequenceStart + 1) {
                throw IllegalArgumentException();
            }

            int tableIndex;
            for (tableIndex = wordTable.length; --tableIndex >= 0;) {
                if (wordTable[tableIndex].regionMatches(true, 0, curentWord, 0, curentWord.length())) {
                    int action = actionTable[tableIndex];
                    if (action != 0) {
                        if (action == 1) {  // pm
                            if (dateTime.hour > 12 || dateTime.hour < 1)
                                throw IllegalArgumentException();
                            else if (dateTime.hour < 12)
                                dateTime.hour += 12;
                        } else if (action == 14) {  // am
                            if (dateTime.hour > 12 || dateTime.hour < 1)
                                throw IllegalArgumentException();
                            else if (dateTime.hour == 12)
                                dateTime.hour = 0;
                        } else if (action <= 13) {  // month!
                            if (dateTime.month < 0)
                                dateTime.month = (byte) (action - 2);
                            else
                                throw IllegalArgumentException();
                        } else {
                            dateTime.timeZoneOffset = action - 10000;
                        }
                    }
                    break;
                }
            }

            if (tableIndex < 0)
                throw IllegalArgumentException();
            previousChar = 0;
        }
    }

    if (dateTime.year == Integer::MIN_VALUE || dateTime.month < 0 || dateTime.dayOfMonth < 0)
        throw IllegalArgumentException();
    // Parse 2-digit years within the correct default century.
    if (dateTime.year < 100) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        struct tm *currentTime = std::localtime(&now_c);
        int defaultCenturyStart = 0;

        if (defaultCenturyStart == 0) {
            defaultCenturyStart = currentTime->tm_year - 80;
        }
        dateTime.year += (defaultCenturyStart / 100) * 100;
        if (dateTime.year < defaultCenturyStart) {
            dateTime.year += 100;
        }
    }
    if (dateTime.second < 0)
        dateTime.second = 0;
    if (dateTime.minute < 0)
        dateTime.minute = 0;
    if (dateTime.hour < 0)
        dateTime.hour = 0;

    tm localTimer = { 0 };

    localTimer.tm_year = dateTime.year % 1900;
    localTimer.tm_mon = dateTime.month;
    localTimer.tm_mday = dateTime.dayOfMonth;
    localTimer.tm_hour = dateTime.hour;
    localTimer.tm_min = dateTime.minute;
    localTimer.tm_sec = dateTime.second;

    long timer = mktime(&localTimer);

    if (dateTime.timeZoneOffset == -1) {
        return timer;
    }
    return timer + dateTime.timeZoneOffset * (60 * 1000);
}

int Date::getSequenceNumber(string inputString, int &index) {

    boolean isNumber;
    boolean isInRange;
    char currentChar;
    int currentNumber = 0;
    int lengthInputString = length_pointer_char(inputString);

    do {
        currentChar = inputString[index];
        isNumber = ('0' <= currentChar) && (currentChar <= '9');
        if (isNumber) {
            currentNumber = currentNumber * 10 + (currentChar - '0');
            ++index;
        }
        isInRange = index < lengthInputString;

    } while (isInRange && isNumber);

    return currentNumber;
}

String Date::getSequenceChar(string inputString, int &index) {
    boolean isInRange;
    boolean isAlphabet;
    char currentChar;

    String sequenceChar = "";
    int lengthInputString = length_pointer_char(inputString);

    do {
        currentChar = inputString[index];
        /* Check is the char accepted : A -> Z, a -> z */
        isAlphabet = ('A' <= currentChar && currentChar <= 'Z')
                         || ('a' <= currentChar && currentChar <= 'z');
        if (isAlphabet) {
            sequenceChar += currentChar;
            index ++;
        }
        isInRange = index < lengthInputString;
    } while (isInRange && isAlphabet);

    return sequenceChar;
}

void Date::updateDateStatus() {
    // Update changes
    this->timer = mktime(this->localTimer);

    this->second = this->localTimer->tm_sec;
    this->minute = this->localTimer->tm_min;
    this->hour = this->localTimer->tm_hour;
    this->dayOfMonth = this->localTimer->tm_mday;
    this->month = this->localTimer->tm_mon;
    this->year = this->localTimer->tm_year;
    this->dayOfWeek = this->localTimer->tm_wday;
    this->dayOfYear = this->localTimer->tm_yday;
    this->isDaylightSavingTime = this->localTimer->tm_isdst;
    this->gmtOffset = this->localTimer->tm_gmtoff;
    this->timeZoneName = this->localTimer->tm_zone;

    this->defaultCenturyStart = (this->year / 100) * 100;
}

void Date::initializeDate(int year, int month, int date,
                          int hour, int minute, int second) {
    tm localTimer = { 0 };

    localTimer.tm_year = year % 1900;
    localTimer.tm_mon = month;
    localTimer.tm_mday = date;
    localTimer.tm_hour = hour;
    localTimer.tm_min = minute;
    localTimer.tm_sec = second;

    this->timer = mktime(&localTimer);

    this->localTimer = localtime(&this->timer);

    updateDateStatus();
}

void Date::initializeDate(long timer) {
    this->timer = timer;
    this->localTimer = localtime(&this->timer);

    updateDateStatus();
}

String Date::timeToString(String pattern, tm *timeManagement) {
    size_t size = 100;
    string holdResult = static_cast<string> (calloc(size, sizeof(char)));
    strftime(holdResult, size, pattern.toString(), timeManagement);

    String result = holdResult;
    free(holdResult);

    return result;
}

long Date::getUTCTime(long timer) {
    long tempTime = timer;
    tm tempTimer = {0};
    tm *utcTimer = gmtime_r(&tempTime, &tempTimer);

    return mktime(utcTimer);
}


