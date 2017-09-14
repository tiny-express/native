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

#ifndef JAVA_UTIL_DATE_DATE_HPP_
#define JAVA_UTIL_DATE_DATE_HPP_

#include "../../Lang.hpp"
#include "../ArrayList/ArrayList.hpp"
#include <algorithm>
#include <string>

using namespace Java::Lang;

namespace test {
    struct Tester;
}

namespace Java {
    namespace Util {
        class Date : public Object {
        public:
            Date();
            Date(int year, int month, int date);
            Date(int year, int month, int date, int hrs, int min);
            Date(int year, int month, int date, int hrs, int min, int sec);
            Date(long date);
            Date(String inputString);
            ~Date();

         public:
            static string testLower(string inputString) {
                String upperStr = inputString;
                String lowerStr = upperStr.toLowerCase();
                string lower = lowerStr.toString();

                return lower;
            }
            /**
             * Tests if this date is after the specified date.
             *
             * @param when: Date
             * @return boolean
             */
            boolean after(Date when);

            /**
             * Tests if this date is before the specified date.
             *
             * @param when
             * @return boolean
             */
            boolean before(Date when);

            /**
             * Return a copy of this object.
             *
             * @return Object
             */

            Date clone();

            /**
             * Compares two Dates for ordering.
             * @param anotherDate
             *
             * @return int
             */
            int compareTo(Date anotherDate);

            /**
             * Compares two dates for equality.
             *
             * @param obj
             * @return int
             */
//                  boolean equals(Object obj);

            /**
             * Get day of month
             *
             * @return int
             */
            int getDate();

            /**
             * Get day of week
             *
             * @return int
             */
            int getDay();

            /**
             * Get hour
             *
             * @return int
             */
            int getHours();

            /**
             * Get minute
             *
             * @return int
             */
            int getMinutes();

            /**
             * Get month
             *
             * @return int
             */
            int getMonth();

            /**
             * Get second
             *
             * @return int
             */
            int getSeconds();

            /**
             * Returns the number of milliseconds since
             * January 1, 1970, 00:00:00 GMT represented
             * by this Date object.
             *
             * @return long
             */
            long getTime();

            /**
             * Get time zone offset in minute
             *
             * @return int
             */
            int getTimezoneOffset();

            /**
             * Get current GMT time zone
             */
            string getZone();

            /**
             * Get year
             *
             * @return int
             */
            int getYear();

            /**
             * Returns a hash code value for this object.
             * @return
             */
            long hashCode();

            /**
             * Attempts to interpret the string s as a representation
             * of a date and time. If the attempt is successful, the time
             * indicated is returned represented as the distance, measured in
             * milliseconds, of that time from the epoch (00:00:00 GMT on
             * January 1, 1970). If the attempt fails, an
             * IllegalArgumentException is thrown.
             *
             * Format syntax:
             *
             * %a	Abbreviated weekday name --- Ex: Thu
             * %A	Full weekday name --- Ex: Thursday
             * %b	Abbreviated month name --- Ex: Aug
             * %B	Full month name --- Ex: August
             * %c	Date and time representation --- Ex: Thu Aug 23 14:55:02 2001
             * %C	Year divided by 100 and truncated to integer (00-99) --- Ex: 20
             * %d	Day of the month, zero-padded (01-31) --- Ex: 23
             * %D	Short MM/DD/YY date, equivalent to %m/%d/ * %y --- Ex: 08/23/01
             * %e	Day of the month, space-padded ( 1-31) --- Ex: 23
             * %F	Short YYYY-MM-DD date, equivalent to %Y-%m-%d --- Ex: 2001-08-23
             * %g	Week-based year, last two digits (00-99) --- Ex: 01
             * %G	Week-based year --- Ex: 2001
             * %h	Abbreviated month name * (same as %b) --- Ex: Aug
             * %H	Hour in 24h format (00-23) --- Ex: 14
             * %I	Hour in 12h format (01-12) --- Ex: 02
             * %j	Day of the year (001-366) --- Ex: 235
             * %m	Month as a decimal number (01-12) --- Ex: 08
             * %M	Minute (00-59) --- Ex: 55
             * %n	New-line character ('\n')
             * %p	AM or PM designation --- Ex: PM
             * %r	12-hour clock time --- Ex: 02:55:02 pm
             * %R	24-hour HH:MM time, equivalent to %H:%M --- Ex: 14:55
             * %S	Second (00-61) --- Ex: 02
             * %t	Horizontal-tab character --- Ex: ('\t')
             * %T	ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S --- Ex: 14:55:02
             * %u	ISO 8601 weekday as number with Monday as 1 (1-7) --- Ex: 4
             * %U	Week number with the first Sunday as the first day of week one (00-53) --- Ex: 33
             * %V	ISO 8601 week number (01-53) --- Ex: 34
             * %w	Weekday as a decimal number with Sunday as 0 (0-6) --- Ex: 4
             * %W	Week number with the first Monday as the first day of week one (00-53) --- Ex: 34
             * %x	Date representation --- Ex: 08/23/01
             * %X	Time representation --- Ex: 14:55:02
             * %y	Year, last two digits (00-99) --- Ex: 01
             * %Y	Year --- Ex: 2001
             * %z	ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100)
             * If timezone cannot be determined, no characters	+100
             * %Z	Timezone name or abbreviation *
             * If timezone cannot be determined, no characters	CDT
             * %%	A % sign	%
             *
             * @param   inputString   a string to be parsed as a date.
             * @param   format        format time of inputString
             * @return  the number of milliseconds since January 1, 1970, 00:00:00 GMT
             *          represented by the string argument.
             * @see     java.text.DateFormat
             * @deprecated As of JDK version 1.1,
             * replaced by DateFormat.parse(String s).
             */
            static long parse(String inputString, string pattern);

            /**
             * Attempts to interpret the string s as a representation
             * of a date and time. If the attempt is successful, the time
             * indicated is returned represented as the distance, measured in
             * milliseconds, of that time from the epoch (00:00:00 GMT on
             * January 1, 1970).
             *
             * @param   inputString   a string to be parsed as a date.
             * @param   format        format time of inputString
             * @return  the number of milliseconds since January 1, 1970, 00:00:00 GMT
             *          represented by the string argument.
             */
            static long parse(String inputString);

            /**
             * Set date
             *
             * @param date
             */
            void setDate(int date);

            /**
             * Set hour
             *
             * @param hours
             */
            void setHours(int hours);

            /**
             * Set minute
             *
             * @param minutes
             */
            void setMinutes(int minutes);

            /**
             * Set month
             *
             * @param month
             */
            void setMonth(int month);

            /**
             * Set second
             *
             * @param seconds
             */
            void setSeconds(int seconds);

            /**
             * Sets this Date object to represent a point
             * in time that is time milliseconds after
             * January 1, 1970 00:00:00 GMT.
             *
             * @param time
             */
            void setTime(long time);

            /**
             * Set year
             *
             * @param year
             */
            void setYear(int year);

            /**
             * Return a string type of Date
             * using a GMT TimeZone.
             *
             * @return String
             */
            String toGMTString();

            /**
             * Return a string type of Date
             * using a local TimeZone.
             *
             * @return String
             */
            String toLocaleString();

            /**
             * Return a string type of Date
             *
             * Example: "Mar 13, 2017 10:01:13 AM"
             *
             * @return String
             */
            String toString();

            /**
             * Return the time in milliseconds after
             * January 1, 1970 00:00:00 GMT.
             *
             * @param year
             * @param month
             * @param date
             * @param hrs
             * @param min
             * @param sec
             * @return long
             */
            static long UTC(int year, int month, int date,
                            int hrs, int min, int sec);

         private:
            time_t timer;
            tm *localTimer;

            /**
             * Seconds.	[0-60] (1 leap second)
             */
            int sec;

            /**
             * Minutes.	[0-59]
             */
            int min;

            /**
             * Hours.	[0-23]
             */
            int hour;

            /**
             * Day.		[1-31]
             */
            int mday;

            /**
             * Month.	[0-11]
             */
            int mon;

            /**
             * Year	- 1900.
             */
            int year;

            /**
             * Day of week.	[0-6]
             */
            int wday;

            /**
             * Days in year.[0-365]	*/
            int yday;

            /**
             * DST.		[-1/0/1]*/
            int isdst;

            /**
             * Seconds east of UTC.
             */
            long int gmtoff;

            /**
             * Timezone abbreviation.
             */
            const char *zone;

            /**
             * Initialized just before the value is used.
             */
            int defaultCenturyStart;

            /**
             * Update changes of this->localTimer
             */
            void update() {
                // Update changes
                this->timer = mktime(this->localTimer);

                this->sec = this->localTimer->tm_sec;
                this->min = this->localTimer->tm_min;
                this->hour = this->localTimer->tm_hour;
                this->mday = this->localTimer->tm_mday;
                this->mon = this->localTimer->tm_mon;
                this->year = this->localTimer->tm_year;
                this->wday = this->localTimer->tm_wday;
                this->yday = this->localTimer->tm_yday;
                this->isdst = this->localTimer->tm_isdst;
                this->gmtoff = this->localTimer->tm_gmtoff;
                this->zone = this->localTimer->tm_zone;

                this->defaultCenturyStart = (this->year / 100) * 100;
            }

            /**
             * Allocates a Date object and initializes it so that
             * it represents the instant at the start of the second specified
             * by the year, month, date,
             * hrs, min, and sec arguments,
             * in the local time zone.
             *
             * @param   year    the year minus 1900.
             * @param   month   the month between 0-11.
             * @param   date    the day of the month between 1-31.
             * @param   hrs     the hours between 0-23.
             * @param   min     the minutes between 0-59.
             * @param   sec     the seconds between 0-59.
             */
            void initialize(int year, int month, int date,
                            int hrs, int min, int sec) {
                tm localTimer = { 0 };

                localTimer.tm_year = year % 1900;
                localTimer.tm_mon = month;
                localTimer.tm_mday = date;
                localTimer.tm_hour = hrs;
                localTimer.tm_min = min;
                localTimer.tm_sec = sec;

                this->timer = mktime(&localTimer);

                this->localTimer = localtime(&this->timer);

                update();
            }

            /**
             * Allocates a Date object and initializes it
             *
             * @param timer time milliseconds after
             *              January 1, 1970 00:00:00 GMT.
             */
            void initialize(time_t timer) {
                this->timer = timer;
                this->localTimer = localtime(&this->timer);

                update();
            }

            /**
             * Convert the time milliseconds after
             * January 1, 1970 00:00:00 GMT to string
             * type - represent the Date object
             *
             * @param timePresenter
             * @return String
             */
            string timeToString(string pattern, tm *timeManagement) {
                size_t size = 100;
                auto result = static_cast<string> (malloc(size * sizeof(char)));
                strftime(result, size, pattern, timeManagement);

                return result;
            }

            /**
             * Get the UTC time
             *
             * @param timer
             * @return long
             */
            static long getUTCTime(long timer) {
                time_t tempTime = timer;
                tm tempTimer = {0};
                tm *utcTimer = gmtime_r(&tempTime, &tempTimer);

                return mktime(utcTimer);
            }

            /**
             * Get Current Number From InputString
             * Sub method of Date::parse(String inputString)
             *
             * @param inputString
             * @param indexStart
             * @return int
             *
             * @see Date::getPattern(String inputString)
             * @see Date::parse(String inputString)
             */
            static int getSequenceNumber(string inputString, int &indexStart) {
                boolean isNumber;
                boolean isInRange;
                char currentChar;
                int currentNumber = 0;
                int &index = indexStart;
                int lengthInputString = length_pointer_char(inputString);

                currentChar = inputString[index];
                isNumber = ('0' <= currentChar) && (currentChar <= '9');
                isInRange = indexStart < lengthInputString;

                /** Get the currentNumber */
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
                }  // End while (index < inputString.length() && isNumber)

                return currentNumber;
            }

            /**
            * Get Current Sequence Char From InputString                                                                                                            From InputString
            * Sub method of Date::parse(String inputString)
            *
            * @param inputString
            * @param indexStart
            * @return string
            *
            * @see Date::getPattern(String inputString)
            * @seeDate::parse(String inputString)
            */
            static String getSequenceChar(string inputString, int &index) {
                boolean isInRange;
                boolean isAcceptedChar;
                char currentChar;

                String sequenceChar = "";
                int lengthInputString = length_pointer_char(inputString);

                currentChar = inputString[index];
                isInRange = index < lengthInputString;

                /** Check is the char accepted : A -> Z, a -> z */
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

            /**
             * Store Date status
             * support method
             * Date::getPattern(String inputString)
             *
             * @see Date::getPattern(String inputString)
             * @see Date::parse(String inputString)
             */
            struct DateTime {
                boolean year = false;
                boolean month = false;
                boolean dayOfMonth = false;
                boolean hour = false;
                boolean minute = false;
                boolean second = false;
                boolean dayOfWeek = false;
                boolean is12hFormat = false;
                boolean timeZone = false;
            };

            /**
             * support method
             * Date::getPattern(String inputString)
             *
             * @param previousString
             * @param number
             * @param followedChar
             * @param dateTime
             * @return string pattern of number
             *
             * @see Date::getPattern(String inputString)
             * @see Date::parse(String inputString)
             */
            static string processNumber(
                    string previousString, int sequenceNumber,
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

                    if (strcmp(previousString, ":") == 0 && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (strcmp(previousString, ":") == 0 && dateTime.minute == true
                        && dateTime.second == false) {

                        dateTime.second = true;
                        return "%S";
                    }

                    if (dateTime.minute == false && followedChar == ':') {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (dateTime.year == false) {

                        dateTime.year = true;
                        return "%y";
                    }

                    if (dateTime.year == true && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (dateTime.year == true && dateTime.minute == true
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

                    if (strcmp(previousString, ":") == 0 && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (strcmp(previousString, ":") == 0 && dateTime.minute == true
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

                    if (dateTime.dayOfMonth == true && dateTime.year == false) {

                        dateTime.year = true;
                        return "%y";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.year == true
                        && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.year == true
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

                    if (strcmp(previousString, ":") == 0 && dateTime.hour == true
                        && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (strcmp(previousString, ":") == 0 && dateTime.hour == true
                        && dateTime.minute == true && dateTime.second == false) {

                        dateTime.second = true;
                        return "%S";
                    }

                    if (dateTime.dayOfMonth == false) {

                        dateTime.dayOfMonth = true;
                        return "%d";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.year == false) {

                        dateTime.year = true;
                        return "%y";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.year == true
                        && dateTime.hour == false) {

                        dateTime.hour = true;
                        return "%H";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.year == true
                        && dateTime.hour == true && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.year == true
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

                    if (strcmp(previousString, ":") == 0 && dateTime.hour == true
                        && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (strcmp(previousString, ":") == 0 && dateTime.hour == true
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

                    if (dateTime.dayOfMonth == true && dateTime.month == false) {

                        dateTime.month = true;
                        return "%m";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.month == true
                        && dateTime.year == false) {

                        dateTime.year = true;
                        return "%y";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.month == true
                        && dateTime.year == true && dateTime.hour == false) {

                        dateTime.hour = true;
                        return "%H";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.month == true
                        && dateTime.year == true && dateTime.hour == true
                        && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (dateTime.dayOfMonth == true && dateTime.month == true
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

                    if (strcmp(previousString, ":") == 0 && dateTime.hour == true
                        && dateTime.minute == false) {

                        dateTime.minute = true;
                        return "%M";
                    }

                    if (strcmp(previousString, ":") == 0 && dateTime.hour == true
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

                return (string) std::to_string(sequenceNumber).c_str();
            }

            /**
             * support method
             * Date::getPattern(String inputString)
             *
             * @param chars
             * @param dateTime
             * @param pattern
             * @return string pattern of chars
             *
             * @see Date::getPattern(String inputString)
             * @see Date::parse(String inputString)
             */
            static String processChars(string inputSequenceChars,
                                            DateTime &dateTime, int &timeZoneOffset) {

                String originalSequenceChars = inputSequenceChars;
                String holdString = inputSequenceChars;
                String sequenceChars = holdString.toLowerCase();

                String temp;

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
                if (sequenceChars == "am"
                    || sequenceChars == "pm") {
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
                for (index = 0; index < arrayAbbreviatedSampleDayOfWeek.size(); ++index) {

                    temp = arrayAbbreviatedSampleDayOfWeek.get(index).toString();
                    findResult =  (temp == sequenceChars);

                    if (findResult) {
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
                for (index = 0; index < arraySampleDayOfWeek.size(); ++index) {

                    temp = arraySampleDayOfWeek.get(index).toString();
                    findResult =  (temp == sequenceChars);

                    if (findResult) {
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
                for (index = 0; index < arrayAbbreviatedSampleMonth.size(); ++index) {

                    temp = arrayAbbreviatedSampleMonth.get(index).toString();
                    findResult =  (temp == sequenceChars);

                    if (findResult) {
                        dateTime.month = true;
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
                for (index = 0; index < arraySampleMonth.size(); ++index) {

                    temp = arraySampleMonth.get(index).toString();
                    findResult =  (temp == sequenceChars);

                    if (findResult) {
                        dateTime.month = true;
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
                for (index = 0; index < arraySampleTimezone.size(); ++index) {

                    temp = arraySampleTimezone.get(index).toString();
                    findResult =  (temp == sequenceChars);

                    if (findResult) {
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
                if (!findResult) {
                    return originalSequenceChars;
                }
            }

            /**
             * support method
             * Date::parse(String inputString)
             *
             * @param s
             * @return std::string pattern of the input String
             *
             * @see Date::parse(String inputString)
             */
//            static String getPattern(String s, int &timeZoneOffset) {
//                // Create variable to store a Date
//                std::string tempString(s.toString());
//                string inputString = (string) tempString.c_str();
//                int lengthInputString = length_pointer_char(inputString);
//
//                DateTime dateTime;
//
//                char currentChar;
//                int index = 0;
//                int sequenceNumber;
//                int idOfCurrentPart = 0;
//                timeZoneOffset = 0;
//                unsigned long findResult = std::string::npos;
//
//                boolean isNumber;
//                boolean isAcceptedChar;
//                boolean isInRange;
//
//                std::string processArray[500];
//                processArray[0] = "";
//                String sequenceChars;
//                String pattern = "";
//
//                // Stop if inputString is empty
//                if (inputString == "") {
//                    return "";
//                }
//
//                isInRange = index < lengthInputString;
//
//                // Scan the inputString
//                while (isInRange) {
//                    /**
//                     * 1. Segmentation
//                     */
//
//                    /** Get the current sequenceNumber */
//                    currentChar = inputString[index];
//                    isInRange = index < lengthInputString;
//                    isNumber = ('0' <= currentChar) && (currentChar <= '9');
//
//                    if (isInRange && isNumber) {
//                        sequenceNumber = Date::getSequenceNumber(inputString, index);
//                        // TODO(thoangminh): check it
//                        string tempString = (string) processArray[idOfCurrentPart].c_str();
//                        pattern += processNumber(tempString, sequenceNumber,
//                                                 inputString[index], dateTime);
//                        processArray[++idOfCurrentPart] = std::to_string(sequenceNumber);
//                    }
//
//                    /** Get current sequenceChar  : A -> Z, a -> z */
//                    currentChar = inputString[index];
//                    isInRange = index < lengthInputString;
//                    isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
//                                     || ('a' <= currentChar && currentChar <= 'z');
//
//                    if (isInRange && isAcceptedChar) {
//                        sequenceChars = Date::getSequenceChar(inputString, index);
//
//                        pattern += Date::processChars(sequenceChars, dateTime, timeZoneOffset);
//
//                        processArray[++idOfCurrentPart] = sequenceChars;
//                    }  // End Get currentSubString : A -> Z, a -> z
//
//                    /** Not isNumber && Not isAcceptedChar */
//                    currentChar = inputString[index];
//                    isNumber = ('0' <= currentChar) && (currentChar <= '9');
//                    isAcceptedChar = ('A' <= currentChar && currentChar <= 'Z')
//                                     || ('a' <= currentChar && currentChar <= 'z');
//
//                    if (!isNumber && !isAcceptedChar && index < lengthInputString) {
//
//                        ++index;
//
//                        if (currentChar != '+' && currentChar != '-') {
//                            pattern += currentChar;
//                        }
//
//                        if (currentChar != ' ' && currentChar != '+'
//                            && currentChar != '-') {
//
//                            processArray[++idOfCurrentPart] = currentChar;
//                        }
//
//                        if (currentChar == '+') {
//                            currentChar = inputString[index];
//                            isNumber = ('0' <= currentChar) && (currentChar <= '9');
//
//                            if (isNumber) {
//                                sequenceNumber = getSequenceNumber(inputString, index);
//                                pattern += "%z";
//
//                                processArray[++idOfCurrentPart]
//                                        = currentChar + std::to_string(sequenceNumber);
//
//                                if (sequenceNumber < 14) {
//                                    timeZoneOffset = -sequenceNumber * 3600;
//                                }
//
//                                if (sequenceNumber > 14) {
//                                    int tempHour = sequenceNumber / 100;
//                                    int tempMinute = sequenceNumber - ((sequenceNumber / 100) * 100);
//                                    timeZoneOffset = - (tempHour * 3600 + tempMinute * 60);
//                                }
//                            }
//
//                            if (!isNumber) {
//                                pattern += currentChar;
//                            }
//                        }
//
//                        if (currentChar == '-' && dateTime.dayOfMonth == true
//                            && dateTime.month == true && dateTime.year == true) {
//
//                            currentChar = inputString[index];
//                            isNumber = ('0' <= currentChar) && (currentChar <= '9');
//
//                            if (isNumber) {
//                                sequenceNumber = getSequenceNumber(inputString, index);
//                                pattern += "%z";
//
//                                processArray[++idOfCurrentPart]
//                                        = currentChar + std::to_string(sequenceNumber);
//
//                                if (sequenceNumber < 14) {
//                                    timeZoneOffset = sequenceNumber * 3600;
//                                }
//
//                                if (sequenceNumber > 14) {
//                                    int tempHour = sequenceNumber / 100;
//                                    int tempMinute = sequenceNumber - ((sequenceNumber / 100) * 100);
//                                    timeZoneOffset = (tempHour * 3600 + tempMinute * 60);
//                                }
//                            }
//
//                            if (!isNumber) {
//                                pattern += currentChar;
//                            }
//                        }
//
//                        if (currentChar == '-' && (dateTime.dayOfMonth == false
//                                                   || dateTime.month == false || dateTime.year == false)) {
//
//                            pattern += currentChar;
//                        }
//                    }  // End Not isAcceptedChar && Not isNumber
//
//                    isInRange = index < lengthInputString;
//                }  // End scan the inputString
//
//                /**
//                 * Process the 12 hour format
//                 */
//                if (dateTime.is12hFormat == true) {
//                    String result = string_replace(pattern.toString(),
//                                                   (string) "%H",
//                                                   (string) "%I");
//                    pattern = result.toString();
//                }
//
//                return pattern;
//            }

            friend struct ::test::Tester;
        };
    }  // namespace Util
}  // namespace Java

#endif  // JAVA_UTIL_DATE_DATE_HPP_