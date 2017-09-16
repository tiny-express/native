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

namespace Java {
    namespace Util {
        class Date : public Object {
        public:
            Date();
            Date(int year, int month, int date);
            Date(int year, int month, int date, int hour, int minute);
            Date(int year, int month, int date, int hour, int minute, int second);
            Date(long date);
            Date(String inputString);
            ~Date();
        public:
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
             * @param hour
             * @param minute
             * @param second
             * @return long
             */
            static long UTC(int year, int month, int date,
                            int hour, int minute, int second);
        private:
            long timer;
            tm *localTimer;

            /**
             * Seconds.	[0-60] (1 leap second)
             */
            int second;

            /**
             * Minutes.	[0-59]
             */
            int minute;

            /**
             * Hours.	[0-23]
             */
            int hour;

            /**
             * Day.		[1-31]
             */
            int dayOfMonth;

            /**
             * Month.	[0-11]
             */
            int month;

            /**
             * Year	- 1900.
             */
            int year;

            /**
             * Day of week.	[0-6]
             */
            int dayOfWeek;

            /**
             * Days in year.[0-365]
             */
            int dayOfYear;

            /**
             * DST.		[-1/0/1]
             */
            int isDaylightSavingTime;

            /**
             * Seconds east of UTC.
             */
            long int gmtOffset;

            /**
             * Initialized just before the value is used.
             */

            /**
             * Time zone name
             */
            String timeZoneName;

            int defaultCenturyStart;

            /**
             * Update Date status
             */
            void updateDateStatus();

            /**
             * Allocates a Date object and initializes it so that
             * it represents the instant at the start of the second specified
             * by the year, month, date,
             * hour, minute, and second arguments,
             * in the local time zone.
             *
             * @param   year    the year minus 1900.
             * @param   month   the month between 0-11.
             * @param   date    the day of the month between 1-31.
             * @param   hour     the hours between 0-23.
             * @param   minute     the minutes between 0-59.
             * @param   second     the seconds between 0-59.
             */
            void initializeDate(int year, int month, int date,
                                int hour, int minute, int second);

            /**
             * Allocates a Date object and initializes it
             *
             * @param timer time milliseconds after
             *              January 1, 1970 00:00:00 GMT.
             */
            void initializeDate(long timer);

            /**
             * Convert the time milliseconds to String
             *
             * @param pattern
             * @return String
             */
            String timeToString(String pattern, tm *timeManagement);

            /**
             * Get the UTC time
             *
             * @param timer
             * @return long
             */
            static long getUTCTime(long timer);

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
            static int getSequenceNumber(string inputString, int &indexStart);

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
            static String getSequenceChar(string inputString, int &index);

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
            static String processNumber(
                    String previousString, int sequenceNumber,
                    char followedChar, DateTime &dateTime);

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
            static String processChars(String inputSequenceChars,
                                            DateTime &dateTime, int &timeZoneOffset);

            /**
             * support method
             * Date::parse(String inputString)
             *
             * @param s
             * @return string pattern of the input String
             *
             * @see Date::parse(String inputString)
             */
            static String getPattern(String s, int &timeZoneOffset);
        };
    }  // namespace Util
}  // namespace Java

#endif  // JAVA_UTIL_DATE_DATE_HPP_