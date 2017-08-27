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
#include <chrono>
#include <tuple>

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
                    boolean refreshFlag;
                    time_t now = time(nullptr);
                    int timezoneOffset;

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
                    long initialize(int year, int month, int date, int hrs, int min, int sec) {
                        long result;
                        tm localTimer = { 0 };

                        localTimer.tm_year = year % 1900;
                        localTimer.tm_mon = month;
                        localTimer.tm_mday = date;
                        localTimer.tm_hour = hrs;
                        localTimer.tm_min = min;
                        localTimer.tm_sec = sec;

                        result = mktime(&localTimer);

                        return result;
                    }

                    /**
                     * This function just work only by default constructor,
                     * every case call set() to this class
                     * will make this function disable
                     */
                    void refreshTime() {
                        this->original = time(nullptr);
                        this->localTimer = localtime(&this->original);

                        tm tempLocalTimeManager;
                        tm *localTimeMagager = localtime_r(&now, &tempLocalTimeManager);
                        tm tempUTCTimeManager;
                        tm *utcTimeManager = gmtime_r(&now, &tempUTCTimeManager);
                        this->timezoneOffset = -(localTimeMagager->tm_hour
                                                 - utcTimeManager->tm_hour) *60;
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

                    /**
                     * Update this->original
                     * whenever user set value to this class
                     */
                    void updateOriginal() {
                        tm *timePresenter = this->localTimer;
                        this->original = Date::UTC(timePresenter->tm_year, timePresenter->tm_mon, timePresenter->tm_mday,
                                                   timePresenter->tm_hour, timePresenter->tm_min, timePresenter->tm_sec);
                    }

                    /**
                     * Update this->localTimer
                     * whenever user set new value
                     * for this->original through setTime()
                     */
                    void updateLocalTimer() {
                        this->localTimer = localtime(&this->original);

                        // Update timezoneOffset
                        time_t now = time(nullptr);
                        tm tempLocalTimeManager = {0};
                        tm *localTimeMagager = localtime_r(&now, &tempLocalTimeManager);
                        tm tempUTCTimeManager = {0};
                        tm *utcTimeManager = gmtime_r(&now, &tempUTCTimeManager);
                        this->timezoneOffset = -(localTimeMagager->tm_hour
                                                   - utcTimeManager->tm_hour) *60;
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
                     * Alloc a new object have sample orginal as target
                     *
                     * @param target
                     * @return
                     */
                    Date(const Date &target);

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

                   /** Returns number of days since civil 1970-01-01.  Negative values indicate
                    *    days prior to 1970-01-01.
                    * Preconditions:  y-m-d represents a date in the civil (Gregorian) calendar
                    *                 m is in [1, 12]
                    *                 d is in [1, last_day_of_month(y, m)]
                    *                 y is "approximately" in
                    *                   [numeric_limits<Int>::min()/366, numeric_limits<Int>::max()/366]
                    *                 Exact range of validity is:
                    *                 [civil_from_days(numeric_limits<Int>::min()),
                    *                  civil_from_days(numeric_limits<Int>::max()-719468)]
                    */
                    template <class Int>
                    constexpr
                    Int
                    days_from_civil(Int y, unsigned m, unsigned d) noexcept
                    {
                        static_assert(std::numeric_limits<unsigned>::digits >= 18,
                                      "This algorithm has not been ported to a 16 bit unsigned integer");
                        static_assert(std::numeric_limits<Int>::digits >= 20,
                                      "This algorithm has not been ported to a 16 bit signed integer");
                        y -= m <= 2;
                        const Int era = (y >= 0 ? y : y-399) / 400;
                        const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
                        const unsigned doy = (153*(m + (m > 2 ? -3 : 9)) + 2)/5 + d-1;  // [0, 365]
                        const unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;         // [0, 146096]
                        return era * 146097 + static_cast<Int>(doe) - 719468;
                    }

                   /** Returns year/month/day triple in civil calendar
                    * Preconditions:  z is number of days since 1970-01-01 and is in the range:
                    *                 [numeric_limits<Int>::min(), numeric_limits<Int>::max()-719468].
                    */
                    template <class Int>
                    constexpr
                    std::tuple<Int, unsigned, unsigned>
                    civil_from_days(Int z) noexcept
                    {
                        static_assert(std::numeric_limits<unsigned>::digits >= 18,
                                      "This algorithm has not been ported to a 16 bit unsigned integer");
                        static_assert(std::numeric_limits<Int>::digits >= 20,
                                      "This algorithm has not been ported to a 16 bit signed integer");
                        z += 719468;
                        const Int era = (z >= 0 ? z : z - 146096) / 146097;
                        auto doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
                        const unsigned yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;  // [0, 399]
                        const Int y = static_cast<Int>(yoe) + era * 400;
                        const unsigned doy = doe - (365*yoe + yoe/4 - yoe/100);                // [0, 365]
                        const unsigned mp = (5*doy + 2)/153;                                   // [0, 11]
                        const unsigned d = doy - (153*mp+2)/5 + 1;                             // [1, 31]
                        const unsigned m = mp + (mp < 10 ? 3 : -9);                            // [1, 12]
                        return std::tuple<Int, unsigned, unsigned>(y + (m <= 2), m, d);
                    }

                    template <class Int>
                    constexpr
                    unsigned
                    weekday_from_days(Int z) noexcept
                    {
                        return static_cast<unsigned>(z >= -4 ? (z+4) % 7 : (z+5) % 7 + 6);
                    }

                    template <class To, class Rep, class Period>
                    To
                    round_down(const std::chrono::duration<Rep, Period>& d)
                    {
                        To t = std::chrono::duration_cast<To>(d);
                        if (t > d)
                            --t;
                        return t;
                    }

                    template <class Duration>
                    std::tm
                    make_utc_tm(std::chrono::time_point<std::chrono::system_clock, Duration> tp)
                    {
                        using namespace std;
                        using namespace std::chrono;
                        typedef duration<int, ratio_multiply<hours::period, ratio<24>>> days;

                        // t is time duration since 1970-01-01
                        Duration t = tp.time_since_epoch();

                        // d is days since 1970-01-01
                        days d = round_down<days>(t);

                        // t is now time duration since midnight of day d
                        t -= d;

                        // break d down into year/month/day
                        int year;
                        unsigned month;
                        unsigned day;
                        std::tie(year, month, day) = civil_from_days(d.count());

                        // start filling in the tm with calendar info
                        std::tm tm = {0};
                        tm.tm_year = year - 1900;
                        tm.tm_mon = month - 1;
                        tm.tm_mday = day;
                        tm.tm_wday = weekday_from_days(d.count());
                        tm.tm_yday = d.count() - days_from_civil(year, 1, 1);

                        // Fill in the time
                        tm.tm_hour = duration_cast<hours>(t).count();
                        t -= hours(tm.tm_hour);
                        tm.tm_min = duration_cast<minutes>(t).count();
                        t -= minutes(tm.tm_min);
                        tm.tm_sec = duration_cast<seconds>(t).count();

                        return tm;
                }
            };
    }  // namespace Util
}  // namespace Java

#endif //JAVA_UTIL_UTIL_DATE_HPP_