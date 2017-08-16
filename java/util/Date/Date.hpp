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

#ifndef JAVA_UTIL_DATE_HPP_
#define JAVA_UTIL_DATE_HPP_

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
						boolean refreshFlag;
						
						/**
						 * This function just work only by default constructor, every case call set() to this class
						 * will make this function disable
						 */
						void refreshTime() {
							this->original = time(0);
							this->localTimer = localtime(&this->original);
						}
						
						/**
						 * An alternative function for ctime(), asctime() of C++
						 * @param timePresenter
						 * @return String
						 */
						string toString0(tm *timePresenter) {
							string result = (string) malloc(80 * sizeof(char));
							
							strftime(result, 80, "%a %b %d %Y %H:%M:%S", timePresenter);
							
							return result;
						}
						
						/**
						 * Update this->original whenever user set value to this class
						 */
						void updateOriginal() {
							tm *timePresenter = this->localTimer;
							this->original = Date::UTC(timePresenter->tm_year, timePresenter->tm_mon, timePresenter->tm_mday,
							                           timePresenter->tm_hour, timePresenter->tm_min, timePresenter->tm_sec);
						}
						
						/**
						 * Update this->localTimer whenever user set new value for this->original through setTime()
						 */
						void updateLocalTimer() {
							this->localTimer = localtime(&this->original);
						}
				
				public:
						/**
						 * Allocates a Date object and initializes it so that it represents the time at
						 * which it was allocated,measured to the nearest millisecond.
						 * @return
						 */
						Date();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(year + 1900, month, date)
						 * or GregorianCalendar(year + 1900, month, date).
						 * @param year
						 * @param month
						 * @param date
						 * @return
						 */
						Date(int year, int month, int date);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(year + 1900, month, date, hrs, min)
						 * or GregorianCalendar(year + 1900, month, date, hrs, min).
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
						 * As of JDK version 1.1, replaced by Calendar.set(year + 1900, month, date, hrs, min, sec)
						 * or GregorianCalendar(year + 1900, month, date, hrs, min, sec).
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
						 * Allocates a Date object and initializes it to represent the specified number of milliseconds
						 * since the standard base time known as "the epoch", namely January 1, 1970, 00:00:00 GMT.
						 * @param date
						 * @return
						 */
						Date(long date);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by DateFormat.parse(String s).
						 * @param s
						 * @return
						 */
						Date(String s);
						
						/**
						 * Alloc a new object have sample orginal as target
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
						 * @param when: Date
						 * @return boolean
						 */
						boolean after(Date when);
						
						/**
						 * Tests if this date is before the specified date.
						 * @param when
						 * @return boolean
						 */
						boolean before(Date when);
						
						/**
						 * We can hide function clone() on Object later
						 * Return a copy of this object.
						 * @return E
						 */
						template <typename E>
						E clone() {
							Date clone = *this;
							return clone;
						}
						
						/**
						 * Compares two Dates for ordering.
						 * @param anotherDate
						 * @return int
						 */
						int compareTo(Date anotherDate);
						
						/**
						 * This function was implement on Object, no need to define again
						 * Compares two dates for equality.
						 * @param obj
						 * @return int
						 */
//            boolean equals(Object obj);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.DAY_OF_MONTH).
						 * @return int
						 */
						int getDate();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.DAY_OF_WEEK).
						 * (0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday)
						 * @return int
						 */
						int getDay();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.HOUR_OF_DAY).
						 * @return int
						 */
						int getHours();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.MINUTE).
						 * @return int
						 */
						int getMinutes();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.MONTH).
						 * @return int
						 */
						int getMonth();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.SECOND).
						 * @return int
						 */
						int getSeconds();
						
						/**
						 * Returns the number of milliseconds since January 1, 1970, 00:00:00 GMT represented by this Date object.
						 * @return long
						 */
						long getTime();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1,
						 * replaced by -(Calendar.get(Calendar.ZONE_OFFSET) + Calendar.get(Calendar.DST_OFFSET)) / (60 * 1000).
						 * @return int
						 */
						int getTimezoneOffset();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.get(Calendar.YEAR) - 1900.
						 * @return int
						 */
						int getYear();
						
						/**
						 * This function was implemented on Object, no need to define again
						 * Returns a hash code value for this object.
						 * @return
						 */
//            int	hashCode();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by DateFormat.parse(String s).
						 * FORMAT: <Day of week> <Month of year> <Day of month> <Year> <Hours>:<Minutes>:<Second>
						 * SAMPLE: Thu Jan 9 2014 12:35:34
						 * @param s
						 * @return long
						 */
						static long parse(String s) {
							tm timer;
							string timeString = s.toString();
							
							// TODO - Fix for WIN32
							// strptime(timeString, "%a %b %d %Y %H:%M:%S", &timer);
							long result = Date::UTC(timer.tm_year, timer.tm_mon, timer.tm_mday,
							                        timer.tm_hour, timer.tm_min, timer.tm_sec);
							return result;
						}
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(Calendar.DAY_OF_MONTH, int date).
						 * @param date
						 */
						void setDate(int date);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(Calendar.HOUR_OF_DAY, int hours).
						 * @param hours
						 */
						void setHours(int hours);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(Calendar.MINUTE, int minutes).
						 * @param minutes
						 */
						void setMinutes(int minutes);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(Calendar.MONTH, int month).
						 * @param month
						 */
						void setMonth(int month);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(Calendar.SECOND, int seconds).
						 * @param seconds
						 */
						void setSeconds(int seconds);
						
						/**
						 * Sets this Date object to represent a point in time that is time milliseconds after January 1, 1970 00:00:00 GMT.
						 * @param time
						 */
						void setTime(long time);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by Calendar.set(Calendar.YEAR, year + 1900).
						 * @param year
						 */
						void setYear(int year);
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by DateFormat.format(Date date), using a GMT TimeZone.
						 * @return String
						 */
						String toGMTString();
						
						/**
						 * Deprecated.
						 * As of JDK version 1.1, replaced by DateFormat.format(Date date).
						 * @return String
						 */
						String toLocaleString();
						
						/**
						 * Return toLocaleString()
						 * @return String
						 */
						String toString();
						
						/**
						 * As of JDK version 1.1, replaced by Calendar.set(year + 1900, month, date, hrs, min, sec)
						 * or GregorianCalendar(year + 1900, month, date, hrs, min, sec),
						 * using a UTC TimeZone, followed by Calendar.getTime().getTime().
						 * @param year
						 * @param month
						 * @param date
						 * @param hrs
						 * @param min
						 * @param sec
						 * @return long
						 */
						static long UTC(int year, int month, int date, int hrs, int min, int sec) {
							tm localTimer = { 0 };
							localTimer.tm_year = year % 1900;
							localTimer.tm_mon = month;
							localTimer.tm_mday = date;
							localTimer.tm_hour = hrs;
							localTimer.tm_min = min;
							localTimer.tm_sec = sec;
							
							time_t result = mktime(&localTimer);
							return result;
						}
					
					
				};
		}
}

#endif //JAVA_UTIL_DATE_HPP_