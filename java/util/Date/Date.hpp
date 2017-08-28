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

#ifndef JAVA_UTIL_UTIL_DATE_HPP_
#define JAVA_UTIL_UTIL_DATE_HPP_

#include <ctime>
#include "../../Lang.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Util {
				class Date : public Object
//        , public virtual Serializable
//        , public virtual Cloneable
//        , public virtual Comparable<Date>
				{
				 private:
                    time_t original;
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
                     * Update changes of this->localTimer
                     */
                    void update() {
                        // Update changes
                        this->original = mktime(this->localTimer);

                        this->sec = this->localTimer->tm_sec;
                        this->min = this->localTimer->tm_min;
                        this->hour = this->localTimer->tm_hour;
                        this->mday = this->localTimer->tm_mday;
                        this->mon = this->localTimer->tm_mon;
                        this->year = this->localTimer->tm_year;
                        this->wday = this->localTimer->tm_wday;
                        this->yday = this->localTimer->tm_yday;
                        this->isdst = this->localTimer->tm_isdst;
                        this->gmtoff =this->localTimer->tm_gmtoff;
                        this->zone =this->localTimer->tm_zone;
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
                    void initialize(int year, int month, int date, int hrs, int min, int sec) {
                        tm localTimer = { 0 };

                        localTimer.tm_year = year % 1900;
                        localTimer.tm_mon = month;
                        localTimer.tm_mday = date;
                        localTimer.tm_hour = hrs;
                        localTimer.tm_min = min;
                        localTimer.tm_sec = sec;

                        this->original = mktime(&localTimer);

                        this->localTimer = localtime(&this->original);

//                        time_t timer = mktime(&localTimer);
//                        tm tempTimer = {0};
//                        this->localTimer = localtime_r(&timer, &tempTimer);
                        update();
                    }

                    /**
                     * This function just work only by default constructor,
                     * every case call set() to this class
                     * will make this function disable
                     */
                    void initialize(time_t timer) {
                        this->original = timer;
                        this->localTimer = localtime(&this->original);

//                        tm tempTimer = {0};
//                        this->localTimer = localtime_r(&timer, &tempTimer);
                        update();

                    }

                    /**
                     * An alternative function for ctime(), asctime() of C++
                     * @param timePresenter
                     * @return String
                     */
                    string timeToString(string format, tm *timeManagement) {
                        size_t size = 100;
                        auto result = static_cast<string> (malloc(size * sizeof(char)));
                        strftime(result, size, format, timeManagement);

                        return result;
                    }

				 public:
                    /**
                     * Allocates a Date object and initializes it
                     * so that it represents the time at
                     * which it was allocated,measured to the nearest millisecond.
                     *
                     * @return
                     */
                    Date();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1,
                     * replaced by Calendar.set(year + 1900, month, date)
                     * or GregorianCalendar(year + 1900, month, date).
                     *
                     * @param year
                     * @param month
                     * @param date
                     * @return
                     */
                    Date(int year, int month, int date);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced
                     * by Calendar.set(year + 1900, month, date, hrs, min)
                     * or GregorianCalendar(year + 1900, month, date, hrs, min).
                     *
                     * @param year
                     * @param month
                     * @param date
                     * @param hrs
                     * @param min
                     * @return
                     */
                    Date(int year, int month, int date, int hrs, int min);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(year + 1900, month, date, hrs, min, sec)
                     * or GregorianCalendar(year + 1900, month, date, hrs, min, sec).
                     *
                     * @param year
                     * @param month
                     * @param date
                     * @param hrs
                     * @param min
                     * @param sec
                     * @return
                     */
                    Date(int year, int month, int date, int hrs, int min, int sec);

                    /**
                     * Allocates a Date object and initializes it
                     * to represent the specified number of milliseconds
                     * since the standard base time known as
                     * "the epoch", namely January 1, 1970, 00:00:00 GMT.
                     *
                     * @param date
                     * @return
                     */
                    Date(long date);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by DateFormat.parse(String s).
                     *
                     * @param s
                     * @return
                     */
                    Date(String s);

                    /**
                     *  Destructor
                     */
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
                     * We can hide function clone() on Object later
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
                     * This function was implement on Object, no need to define again
                     * Compares two dates for equality.
                     *
                     * @param obj
                     * @return int
                     */
//                  boolean equals(Object obj);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced
                     * by Calendar.get(Calendar.DAY_OF_MONTH).
                     *
                     * @return int
                     */
                    int getDate();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.get(Calendar.DAY_OF_WEEK).
                     * (0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday,
                     * 4 = Thursday, 5 = Friday, 6 = Saturday)
                     *
                     * @return int
                     */
                    int getDay();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced
                     * by Calendar.get(Calendar.HOUR_OF_DAY).
                     *
                     * @return int
                     */
                    int getHours();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by Calendar.get(Calendar.MINUTE).
                     *
                     * @return int
                     */
                    int getMinutes();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.get(Calendar.MONTH).
                     *
                     * @return int
                     */
                    int getMonth();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.get(Calendar.SECOND).
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
                     * Deprecated.
                     * As of JDK version 1.1,
                     * replaced by -(Calendar.get(Calendar.ZONE_OFFSET)
                     * + Calendar.get(Calendar.DST_OFFSET))
                     * / (60 * 1000).
                     *
                     * @return int
                     */
                    int getTimezoneOffset();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced
                     * by Calendar.get(Calendar.YEAR) - 1900.
                     *
                     * @return int
                     */
                    int getYear();

                    /**
                     * Returns a hash code value for this object.
                     * @return
                     */
//                      int	hashCode();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * DateFormat.parse(String s).
                     * FORMAT: <Day of week> <Month of year>
                     * <Day of month> <Year> <Hours>:<Minutes>:<Second>
                     * SAMPLE: Thu Jan 9 2014 12:35:34
                     *
                     * @param s
                     * @return long
                     */
                    static long parse(String inputString);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(Calendar.DAY_OF_MONTH, int date).
                     *
                     * @param date
                     */
                    void setDate(int date);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(Calendar.HOUR_OF_DAY, int hours).
                     *
                     * @param hours
                     */
                    void setHours(int hours);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(Calendar.MINUTE, int minutes).
                     *
                     * @param minutes
                     */
                    void setMinutes(int minutes);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(Calendar.MONTH, int month).
                     *
                     * @param month
                     */
                    void setMonth(int month);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(Calendar.SECOND, int seconds).
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
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(Calendar.YEAR, year + 1900).
                     *
                     * @param year
                     */
                    void setYear(int year);

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * DateFormat.format(Date date), using a GMT TimeZone.
                     *
                     * @return String
                     */
                    String toGMTString();

                    /**
                     * Deprecated.
                     * As of JDK version 1.1, replaced by
                     * DateFormat.format(Date date).
                     *
                     * @return String
                     */
                    String toLocaleString();

                    /**
                     * Return toLocaleString()
                     * @return String
                     */
                    String toString();

                    /**
                     * As of JDK version 1.1, replaced by
                     * Calendar.set(year + 1900, month, date, hrs, min, sec)
                     * or GregorianCalendar(year + 1900, month, date, hrs, min, sec),
                     * using a UTC TimeZone, followed by Calendar.getTime().getTime().
                     *
                     * @param year
                     * @param month
                     * @param date
                     * @param hrs
                     * @param min
                     * @param sec
                     * @return long
                     */
                    static long UTC(int year, int month, int date, int hrs, int min, int sec);
            };
    }  // namespace Util
}  // namespace Java

#endif //JAVA_UTIL_UTIL_DATE_HPP_