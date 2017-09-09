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

Date::Date(String inputString, String pattern) {
    time_t timer = Date::parse(inputString, pattern.toString());
    initialize(timer);
}

Date::~Date() {
}

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

String Date::toString() {
    String zone = this->zone;
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

    if (zone == "UTC") {
        zone = "GMT";
    }
#endif

    pattern = (string) "%a %b %d %T %Z %Y";
    string convertResult = this->timeToString(pattern.toString(),
                                              this->localTimer);
    String result = convertResult;
    free(convertResult);

    return result;
}

long Date::UTC(int year, int month, int date, int hrs, int min, int sec) {
    Date tempDate = Date(year, month, date, hrs, min, sec);
    long result = getUTCTime(tempDate.getTime());

    return result;
}

Date Date::clone() {
    Date clone = *this;
    return clone;
}

String Date::toLocaleString() {
    auto pattern = (string) "%b %d, %Y %I:%M:%S %p";
    string convertResult = this->timeToString(pattern, this->localTimer);
    String result = convertResult;
    free(convertResult);

    return result;
}

long Date::parse(String inputString, string pattern) {
    tm localTimer = {};
    strptime(inputString.toString(), pattern, &localTimer);
    return mktime(&localTimer);

//    tm inputTimer = {};
//    strptime(inputString.toString(), pattern, &inputTimer);
//    time_t inputTime = mktime(&inputTimer);
//
//    // Get the utc time
//    tm tempUTCTimer = {};
//    tm *utcTimer = gmtime_r(&inputTime, &tempUTCTimer);
//
//    // Get the local time
//    time_t localTime = {0};
//    tm tempLocalTimer = {};
//    tm *localTimer = localtime_r(&localTime, &tempLocalTimer);
//
//    // Convert the input time to local time
//    return mktime(utcTimer) + localTimer->tm_gmtoff;;
}

string Date::getZone() {
    return (string) this->zone;
}

String Date::toGMTString() {
    string pattern;

#ifdef __unix__
    pattern = (string) "%a %b %d %T UTC %Y";
#endif

#ifdef WIN32
    pattern = (string) "%a %b %d %T GMT %Y";
#endif

    time_t utcTime = getUTCTime(this->timer);
    tm *utcTimer = localtime(&utcTime);

    string convertResult = this->timeToString(pattern, utcTimer);
    String result = convertResult;
    free(convertResult);

    return result;
}

long Date::hashCode() {
    return this->timer;
}

int Date::getSequenceNumber(std::string inputString, int &indexStart) {
    boolean isNumber;
    boolean isInRange;
    char currentChar;
    int currentNumber = 0;
    int &index = indexStart;

    currentChar = inputString[index];
    isNumber = ('0' <= currentChar) && (currentChar <= '9');
    isInRange = indexStart < inputString.length();

    /** Get the currentNumber */
    while (isInRange && isNumber) {
        currentNumber = currentNumber * 10 + (currentChar - '0');
        ++index;

        // Check isInRange
        if (index < inputString.length()) {
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
    }  // End while (index < inputString.length() && isNumber)

    return currentNumber;
}

std::string Date::getSequenceChar(std::string inputString, int &indexStart) {
    boolean isInRange;
    boolean isAcceptedChar;
    char currentChar;
    int &index = indexStart;
    std::string sequenceChar = "";

    currentChar = inputString[index];
    isInRange = indexStart < inputString.length();

    /** Check is the char accepted : A -> Z, a -> z */
    isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
                     || ('a' <= currentChar && currentChar <= 'z');

    while (isInRange && isAcceptedChar) {
        sequenceChar += currentChar;
        ++index;

        if (index < inputString.length()) {
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

std::string Date::getPattern(String s, int &timeZoneOffset) {
    // Create variable to store a Date
    std::string inputString(s.toString());

    DateTime dateTime;

    char currentChar;
    int index = 0;
    int sequenceNumber;
    int idOfCurrentPart = 0;
    timeZoneOffset = 0;
    unsigned long findResult = std::string::npos;

    boolean isNumber;
    boolean isAcceptedChar;
    boolean isInRange;

    std::string processArray[500];
    processArray[0] = "";
    std::string sequenceChars = "";
    std::string pattern = "";

    // Stop if inputString is empty
    if (inputString.compare("") == 0) {
        return "";
    }

    isInRange = index < inputString.length();

    // Scan the inputString
    while (isInRange) {
        /**
         * 1. Segmentation
         */

        /** Get the current sequenceNumber */
        currentChar = inputString[index];
        isInRange = index < inputString.length();
        isNumber = ('0' <= currentChar) && (currentChar <= '9');

        if (isInRange && isNumber) {
            sequenceNumber = Date::getSequenceNumber(inputString, index);
            pattern += processNumber(processArray[idOfCurrentPart],
                                     sequenceNumber, inputString[index], dateTime);
            processArray[++idOfCurrentPart] = std::to_string(sequenceNumber);
        }

        /** Get current sequenceChar  : A -> Z, a -> z */
        currentChar = inputString[index];
        isInRange = index < inputString.length();
        isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
                         || ('a' <= currentChar && currentChar <= 'z');

        if (isInRange && isAcceptedChar) {
            sequenceChars = Date::getSequenceChar(inputString, index);

            pattern += Date::processChars(sequenceChars, dateTime, timeZoneOffset);

            processArray[++idOfCurrentPart] = sequenceChars;
        }  // End Get currentSubString : A -> Z, a -> z

        /** Not isNumber && Not isAcceptedChar */
        currentChar = inputString[index];
        isNumber = ('0' <= currentChar) && (currentChar <= '9');
        isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
                         || ('a' <= currentChar && currentChar <= 'z');

        if (!isNumber && !isAcceptedChar && index < inputString.length()) {

            ++index;

            if (currentChar != '+' && currentChar != '-') {
                pattern += currentChar;
            }

            if (currentChar != ' ' && currentChar != '+'
                && currentChar != '-') {

                processArray[++idOfCurrentPart] = currentChar;
            }

            if (currentChar == '+') {
                currentChar = inputString[index];
                isNumber = ('0' <= currentChar) && (currentChar <= '9');

                if (isNumber) {
                    sequenceNumber = getSequenceNumber(inputString, index);
                    pattern += "%z";

                    processArray[++idOfCurrentPart]
                            = currentChar + std::to_string(sequenceNumber);

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

            if (currentChar == '-' && dateTime.dayOfMonth == true
                    && dateTime.month == true && dateTime.year == true) {

                currentChar = inputString[index];
                isNumber = ('0' <= currentChar) && (currentChar <= '9');

                if (isNumber) {
                    sequenceNumber = getSequenceNumber(inputString, index);
                    pattern += "%z";

                    processArray[++idOfCurrentPart]
                            = currentChar + std::to_string(sequenceNumber);

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

            if (currentChar == '-' && (dateTime.dayOfMonth == false
                || dateTime.month == false || dateTime.year == false)) {

                pattern += currentChar;
            }

        }  // End Not isAcceptedChar && Not isNumber

        isInRange = index < inputString.length();
    }  // End scan the inputString

//    // get processArray
//    std::string stringProcessArray = "";
//    for (int index = 1; index <= idOfCurrentPart; index++) {
//        stringProcessArray += processArray[index] + "_";
//    }
//    return stringProcessArray;

    /**
     * Process the 12 hour format
     */
    if (dateTime.is12hFormat == true) {
        findResult = pattern.find("%H");

        if (findResult != std::string::npos) {
            pattern.replace(findResult, 2, "%I");
        }
    }

    return pattern;
}

std::string Date::processNumber(std::string previousString, int sequenceNumber,
                                char followedChar, DateTime &dateTime) {
    /**
     * sequenceNumber: >= 100
     * year: %Y
     */
    if (sequenceNumber >= 100) {
        if (dateTime.year == false) {
            dateTime.year = true;
            return "%Y";
        }
    }

    /**
     * sequenceNumber: 60 -> 99
     * year: %y
     */
    if (60 <= sequenceNumber && sequenceNumber <= 99) {
        if (dateTime.year == false) {
            dateTime.year = true;
            return "%y";
        }
    }

    /**
     * sequenceNumber: 32 -> 59
     * year: %y
     * or minute: %M
     * or second: %S
     */
    if (32 <= sequenceNumber && sequenceNumber <= 59) {

        if (previousString.compare(":") == 0 && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.minute == true
            && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }

        if (dateTime.minute == false && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if(dateTime.year == false) {

            dateTime.year = true;
            return "%y";
        }

        if (dateTime.year == true && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if(dateTime.year == true && dateTime.minute == true
           && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }
    }

    /**
     *  sequenceNumber: 24 -> 31
     *  or day of month: %d
     *  or year: %y
     *  minute: %M
     *  or second: %S
     */
    if (24 <= sequenceNumber && sequenceNumber <= 31) {

        if (previousString.compare(":") == 0 && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.minute == true
            && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }

        if (dateTime.minute == false && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.dayOfMonth == false) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == false) {

            dateTime.year = true;
            return "%y";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == true
           && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == true
           && dateTime.minute == true && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }
    }

    /**
     *  sequenceNumber: 12 -> 23
     *  or day of month: %d
     *  or year: %y
     *  or hour: %H
     *  minute: %M
     *  or second: %S
     */
    if (12 <= sequenceNumber && sequenceNumber <= 23) {

        if (dateTime.hour == false && followedChar == ':') {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour == true && dateTime.minute == false
            && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.hour == true
            && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.hour == true
            && dateTime.minute == true && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }

        if (dateTime.dayOfMonth == false) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == false) {

            dateTime.year = true;
            return "%y";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == true
           && dateTime.hour == false) {

            dateTime.hour = true;
            return "%H";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == true
           && dateTime.hour == true && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if(dateTime.dayOfMonth == true && dateTime.year == true
           && dateTime.hour == true && dateTime.minute == true
           && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }
    }

    /**
     *  sequenceNumber: 1 -> 11
     *  or day of month: %d
     *  or month: %m
     *  or year: %y
     *  or hour: %H
     *  minute: %M
     *  or second: %S
     */
    if (1 <= sequenceNumber && sequenceNumber <= 11) {

        if (dateTime.hour == false && followedChar == ':') {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour == true && dateTime.minute == false
            && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.hour == true
            && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.hour == true
            && dateTime.minute == true && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }

        if (dateTime.month == false
            && (followedChar == '/' || followedChar == '-')) {

            dateTime.month = true;
            return "%m";
        }

        if (dateTime.month == true && dateTime.dayOfMonth == false
            && (followedChar == '/' || followedChar == '-')) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if (dateTime.dayOfMonth == false) {

            dateTime.dayOfMonth = true;
            return "%d";
        }

        if(dateTime.dayOfMonth == true && dateTime.month == false) {

            dateTime.month = true;
            return "%m";
        }

        if(dateTime.dayOfMonth == true && dateTime.month == true
           && dateTime.year == false) {

            dateTime.year = true;
            return "%y";
        }

        if(dateTime.dayOfMonth == true && dateTime.month == true
           && dateTime.year == true && dateTime.hour == false) {

            dateTime.hour = true;
            return "%H";
        }

        if(dateTime.dayOfMonth == true && dateTime.month == true
           && dateTime.year == true && dateTime.hour == true
           && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if(dateTime.dayOfMonth == true && dateTime.month == true
           && dateTime.year == true && dateTime.hour == true
           && dateTime.minute == true && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }
    }

    /**
     *  sequenceNumber: = 0
     *  hour: %H
     *  minute: %M
     *  or second: %S
     */
    if (sequenceNumber == 0) {

        if (dateTime.hour == false && followedChar == ':') {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour == true && dateTime.minute == false
            && followedChar == ':') {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.hour == true
            && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if (previousString.compare(":") == 0 && dateTime.hour == true
            && dateTime.minute == true && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }

        if (dateTime.hour == false) {

            dateTime.hour = true;
            return "%H";
        }

        if (dateTime.hour == true && dateTime.minute == false) {

            dateTime.minute = true;
            return "%M";
        }

        if (dateTime.hour == true && dateTime.minute == true
            && dateTime.second == false) {

            dateTime.second = true;
            return "%S";
        }
    }

    return std::to_string(sequenceNumber);
}

std::string Date::processChars(std::string sequenceChars,
                               Date::DateTime &dateTime, int &timeZoneOffset) {

    std::string originalSequenceChars = sequenceChars;

    std::transform(sequenceChars.begin(), sequenceChars.end(),
                   sequenceChars.begin(), ::tolower);

    long findResult = std::string::npos;
    int index;

    std::string arrayAbbreviatedSampleDayOfWeek[] = {
            "mon", "tue",
            "wed", "thu",
            "fri", "sat", "sun"
    };
    int lengthArrayAbbreviatedSampleDayOfWeek = 7;

    std::string arraySampleDayOfWeek[] = {
            "monday", "tuesday",
            "wednesday", "thursday",
            "friday", "saturday", "sunday"
    };
    int lengthArraySampleDayOfWeek = 7;

    std::string arrayAbbreviatedSampleMonth[] = {
            "jan", "feb", "mar",
            "apr", "may", "jun", "jul",
            "aug", "sep", "oct",
            "nov", "dec"
    };
    int lengthArrayAbbreviatedSampleMonth = 12;

    std::string arraySampleMonth[] = {
            "january", "february", "march",
            "april", "may", "june", "july",
            "august", "september", "october",
            "november", "december"
    };
    int lengthArraySampleMonth = 12;

    std::string arraySampleTimezone[] = {
            "gmt", "ut", "utc",
            "est", "edt", "cst",
            "cdt", "mst", "mdt",
            "pst", "pdt"
    };
    int lengthArraySampleTimezone = 11;

    int arrayTimezoneOffset[] = {
            0, 0, 0, // GMT/UT/UTC
            5 * 3600, 4 * 3600, // EST/EDT
            6 * 3600, 5 * 3600, // CST/CDT
            7 * 3600, 6 * 3600, // MST/MDT
            8 * 3600, 7 * 3600 // PST/PDT
    };

    /**
     * sequenceChars == 12 hours time format
     *
     * {
     *      "am", "pm"
     * }
     *
     * @return %p
     */
    if (sequenceChars.compare("am") == 0
        || sequenceChars.compare("pm") == 0) {
        dateTime.is12hFormat = true;

        return "%p";
    }

    /**
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
    for (index = 0; index < lengthArrayAbbreviatedSampleDayOfWeek; ++index) {

        findResult = arrayAbbreviatedSampleDayOfWeek[index].find(sequenceChars);

        if (findResult != std::string::npos) {
            dateTime.dayOfWeek = true;
            return "%a";
        }
    }

    /**
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
    for (index = 0; index < lengthArraySampleDayOfWeek; ++index) {

        findResult = arraySampleDayOfWeek[index].find(sequenceChars);

        if (findResult != std::string::npos) {
            dateTime.dayOfWeek = true;
            return "%A";
        }
    }

    /**
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
    for (index = 0; index < lengthArrayAbbreviatedSampleMonth; ++index) {

        findResult = arrayAbbreviatedSampleMonth[index].find(sequenceChars);

        if (findResult != std::string::npos) {
            dateTime.monthInChars = true;
            return "%b";
        }
    }

    /**
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
    for (index = 0; index < lengthArraySampleMonth; ++index) {

        findResult = arraySampleMonth[index].find(sequenceChars);

        if (findResult != std::string::npos) {
            dateTime.monthInChars = true;
            return "%B";
        }
    }

    /**
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
    for (index = 0; index < lengthArraySampleTimezone; ++index) {

        findResult = arraySampleTimezone[index].find(sequenceChars);

        if (findResult != std::string::npos) {
            dateTime.timeZone = true;
            timeZoneOffset = arrayTimezoneOffset[index];
            return "%Z";
        }
    }

    /**
     * sequenceChars not match any sample
     *
     * @return originalSequenceChars
     */
    if (findResult == std::string::npos) {
        return originalSequenceChars;
    }
}

long Date::parse(String inputString) {
    int timeZoneOffset = 0;

    tm localTimer = {};
    std::string pattern = Date::getPattern(inputString, timeZoneOffset);
    strptime(inputString.toString(), pattern.c_str(), &localTimer);

    long utcTime = mktime(&localTimer) + timeZoneOffset;

    Date date = Date();

    if (timeZoneOffset != 0) {
        return utcTime - (date.getTimezoneOffset() * 60);
    }

    return utcTime;
}
