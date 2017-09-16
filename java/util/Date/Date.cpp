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

#ifdef __unix__
    if (this->getTimezoneOffset() == 0) {
        pattern = (string) "%a %b %d %T UTC %Y";
    }
#endif

#ifdef WIN32
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

#ifdef __unix__
    pattern = (string) "%a %b %d %T UTC %Y";
#endif

#ifdef WIN32
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

long Date::parse(String inputString) {
    int timeZoneOffset = 0;

    tm localTimer = {};
    String pattern = Date::getPattern(inputString, timeZoneOffset);
    strptime(inputString.toString(), pattern.toString(), &localTimer);

    long utcTime = mktime(&localTimer) + timeZoneOffset;

    Date date = Date();

    if (timeZoneOffset != 0) {
        return utcTime - (date.getTimezoneOffset() * 60);
    }

    return utcTime;
}

int Date::getSequenceNumber(string inputString, int &indexStart) {

    boolean isNumber;
    boolean isInRange;
    char currentChar;
    int currentNumber = 0;
    int &index = indexStart;
    int lengthInputString = length_pointer_char(inputString);

    currentChar = inputString[index];
    isNumber = ('0' <= currentChar) && (currentChar <= '9');
    isInRange = indexStart < lengthInputString;

    /* Get the currentNumber */
    while (isInRange && isNumber) {
        currentNumber = currentNumber * 10 + (currentChar - '0');
        ++index;

        // Check isInRange
        if (index < lengthInputString) {
            currentChar = inputString[index];
            isInRange = true;
        } else {
            isInRange = false;
        }

        // Check isNumber
        if ('0' <= currentChar && currentChar <= '9') {
            isNumber = true;
        } else {
            isNumber = false;
        }
    }  // End while (isInRange && isNumber)

    return currentNumber;
}

String Date::getSequenceChar(string inputString, int &index) {
    boolean isInRange;
    boolean isAcceptedChar;
    char currentChar;

    String sequenceChar = "";
    int lengthInputString = length_pointer_char(inputString);

    currentChar = inputString[index];
    isInRange = index < lengthInputString;

    /* Check is the char accepted : A -> Z, a -> z */
    isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
                     || ('a' <= currentChar && currentChar <= 'z');

    while (isInRange && isAcceptedChar) {

        char arrayChar[2];
        arrayChar[0] = currentChar;
        arrayChar[1] = '\0';
        String holdChar = arrayChar;
        sequenceChar += holdChar;

        ++index;

        if (index < lengthInputString) {
            currentChar = inputString[index];
            isInRange = true;
        } else {
            isInRange = false;
        }

        if (('A' <= currentChar && currentChar <= 'Z')
            || ('a' <= currentChar && currentChar <= 'z')) {
            isAcceptedChar = true;
        } else {
            isAcceptedChar = false;
        }
    }  // End while (isInRange && isAcceptedChar)

    return sequenceChar;
}

String Date::processNumber(
        String previousString, int sequenceNumber,
        char followedChar, DateTime &dateTime) {
    /*
     * sequenceNumber: >= 100
     * year: %Y
     */
    if (sequenceNumber >= 100) {
        if (!dateTime.year) {
            dateTime.year = true;
            return "%Y";
        }
    }

    /*
     * sequenceNumber: 60 -> 99
     * year: %y
     */
    if (60 <= sequenceNumber && sequenceNumber <= 99) {
        if (!dateTime.year) {
            dateTime.year = true;
            return "%y";
        }
    }

    /*
     * sequenceNumber: 32 -> 59
     * year: %y
     * or minute: %M
     * or second: %S
     */
    if (32 <= sequenceNumber && sequenceNumber <= 59) {

        if (previousString == ":" && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && dateTime.minute
            && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }

        if (!dateTime.minute && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (!dateTime.year) {

            dateTime.year = true;
            return "%y";
        }

        if (dateTime.year && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.year && dateTime.minute
            && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }
    }

    /*
     *  sequenceNumber: 24 -> 31
     *  or day of month: %d
     *  or year: %y
     *  minute: %M
     *  or second: %S
     */
    if (24 <= sequenceNumber && sequenceNumber <= 31) {

        if (previousString == ":" && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && dateTime.minute
            && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }

        if (!dateTime.minute && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (!dateTime.dayOfMonth) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if (dateTime.dayOfMonth && !dateTime.year) {

            dateTime.year = true;
            return "%y";
        }

        if (dateTime.dayOfMonth && dateTime.year
            && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.dayOfMonth && dateTime.year
            && dateTime.minute && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }
    }

    /*
     *  sequenceNumber: 12 -> 23
     *  or day of month: %d
     *  or year: %y
     *  or hour: %H
     *  minute: %M
     *  or second: %S
     */
    if (12 <= sequenceNumber && sequenceNumber <= 23) {

        if (!dateTime.hour && followedChar == ':') {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour && !dateTime.minute
            && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && dateTime.hour
            && dateTime.minute && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }

        if (!dateTime.dayOfMonth) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if (dateTime.dayOfMonth && !dateTime.year) {

            dateTime.year = true;
            return "%y";
        }

        if (dateTime.dayOfMonth && dateTime.year
            && !dateTime.hour) {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.dayOfMonth && dateTime.year
            && dateTime.hour && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.dayOfMonth && dateTime.year
            && dateTime.hour && dateTime.minute
            && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }
    }

    /*
     *  sequenceNumber: 1 -> 11
     *  or day of month: %d
     *  or month: %m
     *  or year: %y
     *  or hour: %H
     *  minute: %M
     *  or second: %S
     */
    if (1 <= sequenceNumber && sequenceNumber <= 11) {

        if (!dateTime.hour && followedChar == ':') {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour && !dateTime.minute
            && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && dateTime.hour
            && dateTime.minute && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }

        if (!dateTime.month
            && (followedChar == '/' || followedChar == '-')) {

            dateTime.month = true;
            return "%m";
        }

        if (dateTime.month && !dateTime.dayOfMonth
            && (followedChar == '/' || followedChar == '-')) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if (!dateTime.dayOfMonth) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if (dateTime.dayOfMonth && !dateTime.month) {

            dateTime.month = true;
            return "%m";
        }

        if (dateTime.dayOfMonth && dateTime.month
            && !dateTime.year) {

            dateTime.year = true;
            return "%y";
        }

        if (dateTime.dayOfMonth && dateTime.month
            && dateTime.year && !dateTime.hour) {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.dayOfMonth && dateTime.month
            && dateTime.year && dateTime.hour
            && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.dayOfMonth && dateTime.month
            && dateTime.year && dateTime.hour
            && dateTime.minute && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }
    }

    /*
     *  sequenceNumber: = 0
     *  hour: %H
     *  minute: %M
     *  or second: %S
     */
    if (sequenceNumber == 0) {

        if (!dateTime.hour && followedChar == ':') {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour && !dateTime.minute
            && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString == ":" && dateTime.hour
            && dateTime.minute && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }

        if (!dateTime.hour) {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour && !dateTime.minute) {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.hour && dateTime.minute
            && !dateTime.second) {

            dateTime.second = true;
            return "%S";
        }
    }

    return String::valueOf(sequenceNumber);
}

String Date::processChars(String inputSequenceChars,
                           DateTime &dateTime, int &timeZoneOffset) {

    String originalSequenceChars = inputSequenceChars;
    String sequenceChars = inputSequenceChars.toLowerCase();

    String resultArrayGetString;

    boolean findResult = false;
    int index;

    ArrayList<String> arrayAbbreviatedSampleDayOfWeek = {
            "mon", "tue",
            "wed", "thu",
            "fri", "sat", "sun"
    };

    ArrayList<String> arraySampleDayOfWeek = {
            "monday", "tuesday",
            "wednesday", "thursday",
            "friday", "saturday", "sunday"
    };

    ArrayList<String> arrayAbbreviatedSampleMonth = {
            "jan", "feb", "mar",
            "apr", "may", "jun", "jul",
            "aug", "sep", "oct",
            "nov", "dec"
    };

    ArrayList<String> arraySampleMonth = {
            "january", "february", "march",
            "april", "may", "june", "july",
            "august", "september", "october",
            "november", "december"
    };

    ArrayList<String> arraySampleTimezone = {
            "gmt", "ut", "utc",
            "est", "edt", "cst",
            "cdt", "mst", "mdt",
            "pst", "pdt"
    };

    int arrayTimezoneOffset[] = {
            0, 0, 0,  // GMT/UT/UTC
            5 * 3600, 4 * 3600,  // EST/EDT
            6 * 3600, 5 * 3600,  // CST/CDT
            7 * 3600, 6 * 3600,  // MST/MDT
            8 * 3600, 7 * 3600  // PST/PDT
    };

    /*
     * sequenceChars == 12 hours time format
     *
     * {
     *      "am", "pm"
     * }
     *
     * @return %p
     */
    if (sequenceChars == "am"
        || sequenceChars == "pm") {
        dateTime.is12hFormat = true;

        return "%p";
    }

    /*
    * sequenceChars == abbreviated day of week
    *
    * {
    *      "mon", "tue",
    *      "wed", "thu",
    *      "fri", "sat", "sun"
    * }
    *
    * @return %a
    */
    for (index = 0; index < arrayAbbreviatedSampleDayOfWeek.size(); ++index) {

        resultArrayGetString = arrayAbbreviatedSampleDayOfWeek.get(index).toString();
        findResult =  (resultArrayGetString == sequenceChars);

        if (findResult) {
            dateTime.dayOfWeek = true;
            return "%a";
        }
    }

    /*
     * sequenceChars == day of week
     *
     * {
     *      "monday", "tuesday",
     *      "wednesday", "thursday",
     *      "friday", "saturday", "sunday"
     * }
     *
     * @return %A
     */
    for (index = 0; index < arraySampleDayOfWeek.size(); ++index) {

        resultArrayGetString = arraySampleDayOfWeek.get(index).toString();
        findResult =  (resultArrayGetString == sequenceChars);

        if (findResult) {
            dateTime.dayOfWeek = true;
            return "%A";
        }
    }

    /*
     * sequenceChars == abbreviated month
     *
     * {
     *      "jan", "feb", "mar",
     *      "apr", "may", "jun", "jul",
     *      "aug", "sep", "oct",
     *      "nov", "dec"
     * }
     *
     * @return %b
     */
    for (index = 0; index < arrayAbbreviatedSampleMonth.size(); ++index) {

        resultArrayGetString = arrayAbbreviatedSampleMonth.get(index).toString();
        findResult =  (resultArrayGetString == sequenceChars);

        if (findResult) {
            dateTime.month = true;
            return "%b";
        }
    }

    /*
     * sequenceChars == month
     *
     * {
     *      "january", "february", "march",
     *      "april", "may", "june", "july",
     *      "august", "september", "october",
     *      "november", "december"
     * }
     *
     * @return %B
     */
    for (index = 0; index < arraySampleMonth.size(); ++index) {

        resultArrayGetString = arraySampleMonth.get(index).toString();
        findResult =  (resultArrayGetString == sequenceChars);

        if (findResult) {
            dateTime.month = true;
            return "%B";
        }
    }

    /*
     * sequenceChars == timezone
     *
     * {
     *      "gmt", "ut", "utc",
     *      "est", "edt", "cst",
     *      "cdt", "mst", "mdt",
     *      "pst", "pdt"
     * }
     *
     * @return %Z
     */
    for (index = 0; index < arraySampleTimezone.size(); ++index) {

        resultArrayGetString = arraySampleTimezone.get(index).toString();
        findResult =  (resultArrayGetString == sequenceChars);

        if (findResult) {
            dateTime.timeZone = true;
            timeZoneOffset = arrayTimezoneOffset[index];
            return "%Z";
        }
    }

    /*
     * sequenceChars not match any sample
     *
     * @return originalSequenceChars
     */
    if (!findResult) {
        return originalSequenceChars;
    }
}

String Date::getPattern(String s, int &timeZoneOffset) {
    // Create variable to store a Date
    string inputString = s.toString();
    int lengthInputString = s.length();

    DateTime dateTime;

    char currentChar;
    int index = 0;
    int sequenceNumber;
    int indexOfCurrentPart = 0;
    timeZoneOffset = 0;

    boolean isNumber;
    boolean isAcceptedChar;
    boolean isInRange;

    ArrayList<String> processArray;
    processArray.add("");
    String sequenceChars;
    String pattern = "";
    String previousString;
    char followedChar;

    // Stop if inputString is empty
    if (s.isEmpty()) {
        return "";
    }

    isInRange = index < lengthInputString;

    // Scan the inputString
    while (isInRange) {
        /*
         * 1. Segmentation
         */

        /* Get the current sequenceNumber */
        currentChar = inputString[index];
        isInRange = index < lengthInputString;
        isNumber = ('0' <= currentChar) && (currentChar <= '9');

        if (isInRange && isNumber) {
            sequenceNumber = Date::getSequenceNumber(inputString, index);
            previousString = processArray.get(indexOfCurrentPart);
            followedChar = inputString[index];

            pattern += processNumber(previousString.toString(), sequenceNumber,
                                     followedChar, dateTime);

            ++indexOfCurrentPart;
            processArray.add(String::valueOf(sequenceNumber));
        }

        /* Get current sequenceChar  : A -> Z, a -> z */
        currentChar = inputString[index];
        isInRange = index < lengthInputString;
        isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
                         || ('a' <= currentChar && currentChar <= 'z');

        if (isInRange && isAcceptedChar) {
            sequenceChars = Date::getSequenceChar(inputString, index);

            pattern += Date::processChars(sequenceChars, dateTime, timeZoneOffset);

            ++indexOfCurrentPart;
            processArray.add(sequenceChars);
        }  // End Get currentSubString : A -> Z, a -> z

        /* Not isNumber && Not isAcceptedChar */
        currentChar = inputString[index];
        isNumber = ('0' <= currentChar) && (currentChar <= '9');
        isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
                         || ('a' <= currentChar && currentChar <= 'z');

        if (!isNumber && !isAcceptedChar && index < lengthInputString) {

            ++index;

            if (currentChar != '+' && currentChar != '-') {
                pattern += currentChar;
            }

            if (currentChar != ' ' && currentChar != '+'
                && currentChar != '-') {

                char arrayChar[2];
                arrayChar[0] = currentChar;
                arrayChar[1] = '\0';

                ++indexOfCurrentPart;
                processArray.add(arrayChar);
            }

            if (currentChar == '+') {
                currentChar = inputString[index];
                isNumber = ('0' <= currentChar) && (currentChar <= '9');

                if (isNumber) {
                    sequenceNumber = getSequenceNumber(inputString, index);
                    pattern += "%z";

                    char arrayChar[2];
                    arrayChar[0] = currentChar;
                    arrayChar[1] = '\0';

                    String stringArrayChar = arrayChar;
                    String stringSequenceNumber = String::valueOf(sequenceNumber);

                    stringArrayChar += stringSequenceNumber;
                    previousString = stringArrayChar;

                    ++indexOfCurrentPart;
                    processArray.add(previousString);

                    if (sequenceNumber < 14) {
                        timeZoneOffset = -sequenceNumber * 3600;
                    }

                    if (sequenceNumber > 14) {
                        int tempHour = sequenceNumber / 100;
                        int tempMinute = sequenceNumber - ((sequenceNumber / 100) * 100);
                        timeZoneOffset = - (tempHour * 3600 + tempMinute * 60);
                    }
                }

                if (!isNumber) {
                    pattern += currentChar;
                }
            }

            if (currentChar == '-' && dateTime.dayOfMonth
                && dateTime.month && dateTime.year) {

                currentChar = inputString[index];
                isNumber = ('0' <= currentChar) && (currentChar <= '9');

                if (isNumber) {
                    sequenceNumber = getSequenceNumber(inputString, index);
                    pattern += "%z";

                    char arrayChar[2];
                    arrayChar[0] = currentChar;
                    arrayChar[1] = '\0';

                    String stringArrayChar = arrayChar;
                    String stringSequenceNumber = String::valueOf(sequenceNumber);

                    stringArrayChar += stringSequenceNumber;
                    ++indexOfCurrentPart;
                    processArray.add(stringArrayChar);

                    if (sequenceNumber < 14) {
                        timeZoneOffset = sequenceNumber * 3600;
                    }

                    if (sequenceNumber > 14) {
                        int tempHour = sequenceNumber / 100;
                        int tempMinute = sequenceNumber - ((sequenceNumber / 100) * 100);
                        timeZoneOffset = (tempHour * 3600 + tempMinute * 60);
                    }
                }

                if (!isNumber) {
                    pattern += currentChar;
                }
            }

            if (currentChar == '-' && (!dateTime.dayOfMonth
                                       || !dateTime.month || !dateTime.year)) {

                pattern += currentChar;
            }
        }  // End while (isInRange)

        isInRange = index < lengthInputString;
    }  // End scan the inputString

    /*
     * Process the 12 hour format
     */
    if (dateTime.is12hFormat) {
        string result = string_replace(pattern.toString(),
                                       (string) "%H",
                                       (string) "%I");
        pattern = result;
        free(result);
    }

    return pattern;
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
