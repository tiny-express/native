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


#ifndef JAVA_UTIL_DATE_HPP
#define JAVA_UTIL_DATE_HPP

#include "../../Lang.hpp"
#include "../ArrayList/ArrayList.hpp"
#include "../../../kernel/Platform.hpp"
#include <algorithm>
#include <string>

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class Date :
                public Object,
                public Comparable<Date>
        {
        private:
            long timer;
            tm *localTimer;
            string backUp = nullptr;
        private:
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
             * @param timer time seconds after
             *              January 1, 1970 00:00:00 GMT.
             */
            void initializeDate(long timer);

            /**
             * Convert the time seconds to String
             *
             * @param pattern
             * @param timeManagement
             * @return String
             */
            String timeToString(String pattern, tm *timeManagement) const;

            /**
             * Get the UTC time
             *
             * @param timer
             * @return long
             */
            static long getUTCTime(long timer);

            /**
             * Get current number from processing String
             * Sub method of Date::parse(String inputString)
             *
             * @param inputString
             * @param indexStart
             * @return int
             */
            static int getSequenceNumber(const String &inputString, int &indexStart);

            /**
            * Get current char sequence from processing String                                                                                                        From InputString
            * Sub method of Date::parse(String inputString)
            *
            * @param inputString
            * @param indexStart
            * @return String
            */
            static String getSequenceChar(const String &inputString, int &index);

            /**
             * Remove bracket and character inside bracket
             *
             * @param inputString
             * @return String with bracket and character inside it removed
             */
            static String removeBracket(String inputString);

            /**
             * Get time offset in second from local time zone to UTC
             *
             * @return long time offset in seconds
             */
            static long getOffsetFromUTC();

        public:
            /**
             * Default constructor
             */
            Date();

            /**
             * Create a date instance with specified year, month, date
             *
             * @param year
             * @param month
             * @param date
             */
            Date(int year, int month, int date);

            /**
             * Create a date instance with specified year, month, date,
             * hour, minute
             *
             * @param year
             * @param month
             * @param date
             * @param hour
             * @param minute
             */
            Date(int year, int month, int date, int hour, int minute);

            /**
             * Create a date instance with specified year, month, date,
             * hour, minute, second
             *
             * @param year
             * @param month
             * @param date
             * @param hour
             * @param minute
             * @param second
             */
            Date(int year, int month, int date, int hour, int minute, int second);

            /**
             * Create a date instance with specified timestamp since
             * "the epoch" in second
             *
             * @param date
             */
            Date(long date);

            /**
             * Create a date instance with specified String
             *
             * @param inputString
             */
            Date(String inputString);

            /**
             * Copy constructor
             *
             * @param anotherDate
             */
            Date(const Date &anotherDate);

            /**
             * Destructor, free backup string
             */
            ~Date();
        public:
            /**
             * Tests if this date is after the specified date.
             *
             * @param specifiedDate
             * @return boolean
             */
            boolean after(Date specifiedDate) const;

            /**
             * Tests if this date is before the specified date.
             *
             * @param specifiedDate
             * @return boolean
             */
            boolean before(Date specifiedDate) const;

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
            int compareTo(const Date &anotherDate) const;

            /**
             * Compares two dates for equality.
             *
             * @param obj
             * @return int
             */
            // TODO (anhnt) need instanceof, use Date instead of Object
            boolean equals(Date obj) const;

            /**
             * Get day of month
             *
             * @return int
             */
            int getDate() const;

            /**
             * Get day of week
             *
             * @return int
             */
            int getDay() const;

            /**
             * Get hour
             *
             * @return int
             */
            int getHours() const;

            /**
             * Get minute
             *
             * @return int
             */
            int getMinutes() const;

            /**
             * Get month
             *
             * @return int
             */
            int getMonth() const;

            /**
             * Get second
             *
             * @return int
             */
            int getSeconds() const;

            /**
             * Returns the number of seconds since
             * January 1, 1970, 00:00:00 GMT represented
             * by this Date object.
             *
             * @return long
             */
            long getTime() const;

            /**
             * Get time zone offset in minute
             *
             * @return int
             */
            int getTimezoneOffset() const;

            /**
             * Get year
             *
             * @return int
             */
            int getYear() const;

            /**
             * Returns a hash code value for this object.
             *
             * @return long
             */
            long hashCode() const override ;

            /**
             * Attempts to interpret the string s as a representation
             * of a date and time. If the attempt is successful, the time
             * indicated is returned represented as the distance, measured in
             * seconds, of that time from the epoch (00:00:00 GMT on
             * January 1, 1970).
             *
             * @param inputString   a string to be parsed as a date.
             *
             * @return long the number of seconds since January 1, 1970, 00:00:00 GMT
             * represented by the string argument.
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
             * in time that is time seconds after
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
            String toGMTString() const;

            /**
             * Return a string type of Date
             * using a local TimeZone.
             *
             * @return String
             */
            String toLocaleString() const;

            /**
             * Return a string type of Date
             * Example: "Mar 13, 2017 10:01:13 AM"
             *
             * @return string
             */
            string toString() const override ;

            /**
             * Return the time in seconds after
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

            /**
             * Assign operator
             *
             * @param anotherDate
             * @return a Date reference
             */
            Date& operator=(const Date& anotherDate);
        };
    }  // namespace Util
}  // namespace Java

#endif  // JAVA_UTIL_DATE_HPP
