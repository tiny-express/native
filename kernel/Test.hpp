/* Copyright 2011-2016 Bas van den Berg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NATIVE_KERNEL_TEST_H
#define NATIVE_KERNEL_TEST_H

#include "Type.hpp"
#include "../java/lang/String/String.hpp"
#include "../java/lang/Integer/Integer.hpp"
#include "../java/lang/Double/Double.hpp"
#include "../java/util/ArrayList/ArrayList.hpp"

using namespace Java::Lang;

#if defined _WIN32 || defined __CYGWIN__
#ifndef WIN32
#define WIN32
#endif
#endif

#ifndef WIN32
#define WEAK __attribute__ ((weak))
#else
#define WEAK
#endif

#include <cinttypes> /* intmax_t, uintmax_t, PRI* */
#include <cstddef> /* size_t */
#include <csignal>
#include "Common.hpp"

typedef void (*SetupFunc)(void *);

typedef void (*TearDownFunc)(void *);

struct CTEST {
    const char *ssname;  // suite name
    const char *ttname;  // test name
    void (*run)();

    int skip;

    void *data;
    SetupFunc setup;
    TearDownFunc teardown;

    unsigned int magic;
};

#define __FNAME(sname, tname) __ctest_##sname##_##tname##_run
#define __TNAME(sname, tname) __ctest_##sname##_##tname

#define __CTEST_MAGIC (0xdeadbeef)
#ifdef __APPLE__
#define __Test_Section __attribute__ ((used, section ("__DATA, .CTEST")))
#else
#define __Test_Section __attribute__ ((used, section (".CTEST")))
#endif

#define __CTEST_STRUCT(sname, tname, _skip, __data, __setup, __teardown) \
    static struct CTEST __TNAME(sname, tname) __Test_Section = { \
        .ssname=#sname, \
        .ttname=#tname, \
        .run = __FNAME(sname, tname), \
        .skip = _skip, \
        .data = __data, \
        .setup = (SetupFunc)__setup,                                        \
        .teardown = (TearDownFunc)__teardown,                                \
        .magic = __CTEST_MAGIC };

#define CTEST_DATA(sname) struct sname##_data

#define CTEST_SETUP(sname) \
    void WEAK sname##_setup(struct sname##_data* data)

#define CTEST_TEARDOWN(sname) \
    void WEAK sname##_teardown(struct sname##_data* data)

#define __CTEST_INTERNAL(sname, tname, _skip) \
    void __FNAME(sname, tname)(); \
    __CTEST_STRUCT(sname, tname, _skip, nullptr, nullptr, nullptr) \
    void __FNAME(sname, tname)()

#ifdef __APPLE__
#define SETUP_FNAME(sname) nullptr
#define TEARDOWN_FNAME(sname) nullptr
#else
#define SETUP_FNAME(sname) sname##_setup
#define TEARDOWN_FNAME(sname) sname##_teardown
#endif

#define __CTEST2_INTERNAL(sname, tname, _skip) \
    static struct sname##_data  __ctest_##sname##_data; \
    CTEST_SETUP(sname); \
    CTEST_TEARDOWN(sname); \
    void __FNAME(sname, tname)(struct sname##_data* data); \
    __CTEST_STRUCT(sname, tname, _skip, &__ctest_##sname##_data, SETUP_FNAME(sname), TEARDOWN_FNAME(sname)) \
    void __FNAME(sname, tname)(struct sname##_data* data)


void CTEST_LOG(const char *fmt, ...);

void CTEST_ERR(const char *fmt, ...);  // doesn't return

#define CTEST(sname, tname) __CTEST_INTERNAL(sname, tname, 0)
#define CTEST_SKIP(sname, tname) __CTEST_INTERNAL(sname, tname, 1)

#define CTEST2(sname, tname) __CTEST2_INTERNAL(sname, tname, 0)
#define CTEST2_SKIP(sname, tname) __CTEST2_INTERNAL(sname, tname, 1)

#define sampleString (char*) ""
#define sampleConstString ""
#define sampleInt 1
#define sampleDouble 0.1

template<typename Type, typename AnotherType>
boolean isSame(Type type, AnotherType anotherType) {
    return std::is_same<Type, AnotherType>::value;
}

/**
 * Asserts that two strings are equal.
 *
 * @param expected
 * @param actual
 */
void assertEqualsString(String expected,
                        String actual,
                        const_string file,
                        int line);

/**
 * Asserts that two intmax_ts are equal.
 * @param expected
 * @param actual
 */
void assertEqualsInt(int expected,
                     int actual,
                     const_string file,
                     int line);

/**
 * Asserts that two doubles are equal.
 * With the default precision is 15.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertEqualsDouble(double expected,
                        double actual,
                        const_string file,
                        int line);

/**
 * Asserts that two strings are not equal.
 *
 * @param expected
 * @param actual
 */
void assertNotEqualsString(String expected,
                           String actual,
                           const_string file,
                           int line);

/**
 * Asserts that two intmax_ts are not equal.
 * @param expected
 * @param actual
 */
void assertNotEqualsInt(int expected,
                        int actual,
                        const_string file,
                        int line);

/**
 * Asserts that two doubles are not equal.
 * With the default precision is 15.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertNotEqualsDouble(double expected,
                           double actual,
                           const_string file,
                           int line);

/**
 * Assert Array All Type
 *
 * @param expected
 * @param expectedSize
 * @param actual
 * @param actualSize
 */
template<typename Type>
void assertArrayAllType(Type expected,
                        Type actual,
                        const_string file,
                        int line);

#define assertArray(expected, actual)\
assertArrayAllType(expected, actual, __FILE__, __LINE__)

/**
 * Assert ArrayList<Type>
 *
 * @param expected
 * @param expectedSize
 * @param actual
 * @param actualSize
 */
template<typename Type>
void assertArrayAllType(ArrayList<Type> &expected,
                        ArrayList<Type> &actual,
                        const_string file,
                        int line) {
    size_t index;

    int expectedSize = expected.size();
    int actualSize = actual.size();

    if (expectedSize != actualSize) {
        CTEST_ERR("%s:%d  expected size %" PRIuMAX " bytes, got %" PRIuMAX,
                  file, line, (uintmax_t) expectedSize,
                  (uintmax_t) actualSize);
    }

    for (index = 0; index < expectedSize; index++) {
        if (expected.get(index) != actual.get(index)) {

            String expectedString = expected.get(index).toString();
            String actualString = actual.get(index).toString();

            CTEST_ERR("%s:%d expected 0x%02x at offset %" PRIuMAX " got 0x%02x",
                      file,
                      line,
                      expectedString.toString(),
                      (uintmax_t) index,
                      actualString.toString());
        }
    }
}

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

/**
 * Assert raw pointer
 *
 * @param expected
 * @param expectedSize
 * @param actual
 * @param actualSize
 */
template<typename Type>
void assertArrayAllType(Type *expected,
                        Type *actual,
                        const_string file,
                        int line) {
    size_t index;

    int expectedSize = ARRAY_SIZE(expected);
    int actualSize = ARRAY_SIZE(actual);

    if (expectedSize != actualSize) {
        CTEST_ERR("%s:%d  expected size %" PRIuMAX " bytes, got %" PRIuMAX,
                  file, line, (uintmax_t) expectedSize,
                  (uintmax_t) actualSize);
    }

    for (index = 0; index < expectedSize; index++) {
        if (expected[index] != actual[index]) {
            CTEST_ERR("%s:%d expected 0x%02x at offset %" PRIuMAX " got 0x%02x",
                      file, line, expected[index], (uintmax_t) index, actual[index]);
        }
    }
}

/**
 * Asserts that two unsigned intmax_ts are equal.
 *
 * @param expected
 * @param actual
 */
void assertEqualsIntUnsignedInt(uintmax_t expected,
                                uintmax_t actual,
                                string file,
                                int line);

#define assertEqualsUnsigned(expected, actual)\
assertEqualsIntUnsignedInt(expected, actual, __FILE__, __LINE__)

/**
 * Asserts that two unsigned intmax_ts are not equal.
 *
 * @param expected
 * @param actual
 */
void assertNotEqualsUnsignedInt(uintmax_t expected,
                                uintmax_t actual,
                                const_string file,
                                int line);

#define assertNotEqualsUnsigned(expected, actual)\
assertNotEqualsUnsignedInt(expected, actual, __FILE__, __LINE__)

/**
 * Assert Interval
 *
 * @param expectedFirst
 * @param expectedSecond
 * @param actual
 */
void assertIntervalInt(intmax_t expectedFirst,
                       intmax_t expectedSecond,
                       intmax_t actual,
                       string file,
                       int line);

#define assertInterval(expectedFirst, expectedSecond, actual)\
assertInteverInt(expectedFirst, expectedSecond, actual, __FILE__, __LINE__);

/**
 * Assert Null
 *
 * @param actual
 */
void assertNullVoid(void *actual,
                    const_string file,
                    int line);

#define assertNull(actual)\
assertNullVoid(actual, __FILE__, __LINE__)

/**
 * Assert Not Null
 *
 * @param actual
 */
void assertNotNullVoid(const void *actual,
                       string file,
                       int line);

#define assertNotNull(actual)\
assertNotNullVoid(actual, __FILE__, __LINE__)

/**
 * Assert True
 *
 * @param actual
 */
void assertTrueInt(int actual,
                   const_string file,
                   int line);

#define assertTrue(actual)\
assertTrueInt(actual, __FILE__, __LINE__)

/**
 * Assert False
 *
 * @param actual
 */
void assertFalseInt(int actual,
                    const_string file,
                    int line);

#define assertFalse(actual)\
assertFalseInt(actual, __FILE__, __LINE__);

/**
 * Assert Fail
 */
void assertFailNoneArgument(const_string file, int line);

#define assertFail()\
assertFailNoneArgument(__FILE__, __LINE__);

/**
 * Asserts that two doubles are equal.
 * With the input precision.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertEqualsPrecisionDouble(double expected,
                                 double actual,
                                 int precision,
                                 const_string file,
                                 int line);

#define assertEqualsPrecision(expected, actual, precision)\
assertEqualsPrecisionDouble(expected, actual, precision, __FILE__, __LINE__);


/**
 * Asserts that two doubles are equal.
 * With the input precision.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertNotEqualsPrecisionDouble(double expected,
                                    double actual,
                                    int precision,
                                    const_string file,
                                    int line);

#define assertNotEqualsPrecision(expected, actual, precision)\
assertNotEqualsPrecisionDouble(expected, actual, precision, __FILE__, __LINE__);

/**
 * Asserts that two Types are equal.
 *
 * @tparam Type
 * @param expected
 * @param actual
 * @param file
 * @param line
 */
template<typename Type, typename AnotherType>
void assertEqualsAll(Type expected,
                     AnotherType actual,
                     const_string file,
                     int line) {

    String expectedString = String::valueOf(expected);
    String actualString = String::valueOf(actual);

    boolean isInt = isSame(expected, sampleInt)
                    && isSame(actual, sampleInt);
    boolean isDouble = isSame(expected, sampleDouble);

    boolean isString = isSame(expected, sampleString)
                       || isSame(expected, sampleConstString);

    // Assert int equals
    if (isInt) {
        int expectedInt = Integer::valueOf(expectedString).intValue();
        int actualInt = Integer::valueOf(actualString).intValue();
        assertEqualsInt(expectedInt, actualInt, file, line);
    }

    // Assert double equals
    if (isDouble) {
        double expectedDouble = Double::valueOf(expectedString).doubleValue();
        double actualDouble = Double::valueOf(actualString).doubleValue();

        assertEqualsDouble(expectedDouble, actualDouble, file, line);
    }

    // Assert string equals
    if (isString) {
        assertEqualsString(expectedString, actualString, file, line);
    }
}

#define assertEquals(expected, actual)\
assertEqualsAll(expected, actual, __FILE__, __LINE__);

/**
 * Asserts that two Types are not equal.
 *
 * @tparam Type
 * @param expected
 * @param actual
 * @param file
 * @param line
 */
template<typename Type, typename AnotherType>
void assertNotEqualsAll(Type expected,
                        AnotherType actual,
                        const_string file,
                        int line) {

    String expectedString = String::valueOf(expected);
    String actualString = String::valueOf(actual);

    boolean isInt = isSame(expected, sampleInt)
                    && isSame(actual, sampleInt);
    boolean isDouble = isSame(expected, sampleDouble);

    boolean isString = isSame(expected, sampleString)
                       || isSame(expected, sampleConstString);

    // Assert int equals
    if (isInt) {
        int expectedInt = Integer::valueOf(expectedString).intValue();
        int actualInt = Integer::valueOf(actualString).intValue();
        assertNotEqualsInt(expectedInt, actualInt, file, line);
    }

    // Assert double equals
    if (isDouble) {
        double expectedDouble = Double::valueOf(expectedString).doubleValue();
        double actualDouble = Double::valueOf(actualString).doubleValue();

        assertNotEqualsDouble(expectedDouble, actualDouble, file, line);
    }

    // Assert string equals
    if (isString) {
        assertNotEqualsString(expectedString, actualString, file, line);
    }
}

#define assertNotEquals(expected, actual)\
assertNotEqualsAll(expected, actual, __FILE__, __LINE__);

#ifdef TESTING

#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <dlfcn.h>
#endif

static size_t ctest_errorsize;
static string ctest_errormsg;
#define MSG_SIZE 4096
static char ctest_errorbuffer[MSG_SIZE];
static jmp_buf ctest_err;
static int color_output = 1;
static const_string suite_name;

typedef int (*filter_func)(struct CTEST*);

#define ANSI_BLACK    "\033[0;30m"
#define ANSI_RED      "\033[0;31m"
#define ANSI_GREEN    "\033[0;32m"
#define ANSI_YELLOW   "\033[0;33m"
#define ANSI_BLUE     "\033[0;34m"
#define ANSI_MAGENTA  "\033[0;35m"
#define ANSI_CYAN     "\033[0;36m"
#define ANSI_GREY     "\033[0;37m"
#define ANSI_DARKGREY "\033[01;30m"
#define ANSI_BRED     "\033[01;31m"
#define ANSI_BGREEN   "\033[01;32m"
#define ANSI_BYELLOW  "\033[01;33m"
#define ANSI_BBLUE    "\033[01;34m"
#define ANSI_BMAGENTA "\033[01;35m"
#define ANSI_BCYAN    "\033[01;36m"
#define ANSI_WHITE    "\033[01;37m"
#define ANSI_NORMAL   "\033[0m"

static CTEST(suite, test) { }

inline static void vprint_errormsg(const_string fmt, va_list ap) {
    // (v)snprintf returns the number that would have been written
    const int ret = vsnprintf(ctest_errormsg, ctest_errorsize, fmt, ap);
    if (ret < 0) {
        ctest_errormsg[0] = 0x00;
    } else {
        const size_t size = (size_t) ret;
        const size_t s = (ctest_errorsize <= size ? size -ctest_errorsize : size);
        // ctest_errorsize may overflow at this point
        ctest_errorsize -= s;
        ctest_errormsg += s;
    }
}

inline static void print_errormsg(const_string fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    vprint_errormsg(fmt, argp);
    va_end(argp);
}

static void msg_start(const_string color, const_string title) {
    if (color_output) {
        print_errormsg("%s", color);
    }
    print_errormsg("  %s: ", title);
}

static void msg_end() {
    if (color_output) {
        print_errormsg(ANSI_NORMAL);
    }
    print_errormsg("\n");
}

void CTEST_LOG(const_string fmt, ...)
{
    va_list argp;
    msg_start(ANSI_BLUE, "LOG");

    va_start(argp, fmt);
    vprint_errormsg(fmt, argp);
    va_end(argp);

    msg_end();
}

void CTEST_ERR(const_string fmt, ...)
{
    va_list argp;
    msg_start(ANSI_YELLOW, "\nERROR");

    va_start(argp, fmt);
    vprint_errormsg(fmt, argp);
    va_end(argp);

    msg_end();
    longjmp(ctest_err, 1);
}

void assertEqualsIntUnsigned(uintmax_t expected,
                    uintmax_t actual,
                    string file,
                    int line) {
    if (expected != actual) {
    CTEST_ERR("%s:%d  expected %" PRIuMAX ", got %" PRIuMAX,
                file, line, expected, actual);
    }
}

void assertNotEqualsIntUnsigned(uintmax_t expected,
                        uintmax_t actual,
                        string file,
                        int line) {
    if ((expected) == (actual)) {
    CTEST_ERR("%s:%d  should not be %" PRIuMAX,
            file, line, actual);
    }
}

void assertIntervalInt(intmax_t expectedFirst,
                        intmax_t expectedSecond,
                        intmax_t actual,
                        string file,
                        int line) {

    if (actual < expectedFirst || actual > expectedSecond) {
    CTEST_ERR("%s:%d  expected %" PRIdMAX "-%" PRIdMAX ", got %" PRIdMAX,
                file, line, expectedFirst, expectedSecond, actual);
    }
}

void assert_dbl_far(double expected, double actual, int precision, const_string caller, int line) {
    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    string expectedString = (string) calloc(1079, sizeof(char));
    string actualString = (string) calloc(1079, sizeof(char));

    // Get string type of input number
    if(expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if(actual == -0.0f && actual < 0) {
        sprintf(actualString, "-%.*f", precision, actual);
    } else {
        sprintf(actualString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == nullptr && actualString != nullptr) ||
    (expectedString != nullptr && actualString == nullptr) ||
    (expectedString && actualString && strcmp(expectedString, actualString) == 0)) {
    CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n", caller, line, expectedString, actualString);
    }

    // Free
    free(expectedString);
    free(actualString);
}

void assertEqualsString(String expected,
                        String actual,
                        const_string file,
                        int line) {
    if (expected != actual) {
        CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n",
                  file, line, expected.toString(), actual.toString());
    }
}

void assertEqualsInt(int expected,
                     int actual,
                     const_string file,
                     int line) {

    if (expected != actual) {
        CTEST_ERR("%s:%d  expected %" PRIdMAX ", got %" PRIdMAX,
                  file, line, expected, actual);
    }
}

/**
 * Asserts that two doubles are equal.
 * With the default precision is 15.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertEqualsDouble(double expected,
                        double actual,
                        const_string file,
                        int line) {
    int precision = 15;

    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    string expectedString = (string) calloc(1079, sizeof(char));
    string actualString = (string) calloc(1079, sizeof(char));

    // Get string type of input number
    if (expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if (actual == -0.0f && actual < 0) {
        sprintf(actualString, "-%.*f", precision, actual);
    } else {
        sprintf(actualString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == nullptr && actualString != nullptr) ||
        (expectedString != nullptr && actualString == nullptr) ||
        (expectedString && actualString && strcmp(expectedString, actualString) != 0)) {
        CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n",
                  file, line, expectedString, actualString);
    }

    // Free
    free(expectedString);
    free(actualString);
}



void assertNotEqualsString(String expected,
                        String actual,
                        const_string file,
                        int line) {
    if (expected == actual) {
        CTEST_ERR("%s:%d\nEXPECTED\n'%'\nACTUAL \n'%s'\n",
                  file, line, expected.toString(), actual.toString());
    }
}

void assertNotEqualsInt(int expected,
                     int actual,
                     const_string file,
                     int line) {

    if (expected == actual) {
        CTEST_ERR("%s:%d  expected %" PRIdMAX ", got %" PRIdMAX,
                  file, line, expected, actual);
    }
}

/**
 * Asserts that two doubles are equal.
 * With the default precision is 15.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertNotEqualsDouble(double expected,
                        double actual,
                        const_string file,
                        int line) {
    int precision = 15;

    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    string expectedString = (string) calloc(1079, sizeof(char));
    string actualString = (string) calloc(1079, sizeof(char));

    // Get string type of input number
    if (expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if (actual == -0.0f && actual < 0) {
        sprintf(actualString, "-%.*f", precision, actual);
    } else {
        sprintf(actualString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == nullptr && actualString != nullptr) ||
        (expectedString != nullptr && actualString == nullptr) ||
        (expectedString && actualString && strcmp(expectedString, actualString) == 0)) {
        CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n",
                  file, line, expectedString, actualString);
    }

    // Free
    free(expectedString);
    free(actualString);
}

/**
 * Asserts that two unsigned intmax_ts are equal.
 *
 * @param expected
 * @param actual
 */
void assertEqualsUnsignedInt(uintmax_t expected,
                   uintmax_t actual,
                   string file,
                   int line);

/**
 * Asserts that two intmax_ts are not equal.
 *
 * @param expected
 * @param actual
 */
void assertNotEqualsInt(intmax_t expected,
                            intmax_t actual,
                            const_string file,
                            int line) {
    if ((expected) == (actual)) {
        CTEST_ERR("%s:%d  should not be %" PRIdMAX,
                  file, line, actual);
    }
}

/**
 * Asserts that two unsigned intmax_ts are not equal.
 *
 * @param expected
 * @param actual
 */
void assertNotEqualsUnsignedInt(uintmax_t expected,
                        uintmax_t actual,
                        string file,
                        int line);

/**
 * Assert Null
 *
 * @param actual
 */
void assertNullVoid(void *actual,
                const_string file,
                int line) {
    if ((actual) != nullptr) {
        CTEST_ERR("%s:%d  should be nullptr", file, line);
    }
}

/**
 * Assert Not Null
 *
 * @param actual
 */
void assertNotNullVoid(const void* actual,
                   const_string file,
                   int line) {
    if (actual == nullptr) {
    CTEST_ERR("%s:%d  should not be nullptr", __FILE__, __LINE__);
    }
}

/**
 * Assert True
 *
 * @param actual
 */
void assertTrueInt(int actual, const_string file, int line) {
    if ((actual) == 0) {
        CTEST_ERR("%s:%d  should be true", file, line);
    }
}

/**
 * Assert False
 *
 * @param actual
 */
void assertFalseInt(int actual, const_string file, int line) {
    if ((actual) != 0) {
        CTEST_ERR("%s:%d  should be false", file, line);
    }
}

/**
 * Assert Fail
 */
void assertFailNoneArgument(const_string file, int line) {
    CTEST_ERR("%s:%d  shouldn't come here", file, line);
}

/**
 * Asserts that two doubles are equal.
 * With the input precision.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertEqualsPrecisionDouble(double expected,
                                  double actual,
                                  int precision,
                                  const_string file,
                                  int line) {
    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    string expectedString = (string) calloc(1079, sizeof(char));
    string actualString = (string) calloc(1079, sizeof(char));

    // Get string type of input number
    if (expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if (actual == -0.0f && actual < 0) {
        sprintf(actualString, "-%.*f", precision, actual);
    } else {
        sprintf(actualString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == nullptr && actualString != nullptr) ||
        (expectedString != nullptr && actualString == nullptr) ||
        (expectedString && actualString && strcmp(expectedString, actualString) != 0)) {
        CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n",
                  file, line, expectedString, actualString);
    }

    // Free
    free(expectedString);
    free(actualString);
}

/**
 * Asserts that two doubles are equal.
 * With the input precision.
 *
 * @param expected
 * @param actual
 * @param precision
 */
void assertNotEqualsPrecisionDouble(double expected,
                                  double actual,
                                  int precision,
                                  const_string file,
                                  int line) {
    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    string expectedString = (string) calloc(1079, sizeof(char));
    string actualString = (string) calloc(1079, sizeof(char));

    // Get string type of input number
    if (expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if (actual == -0.0f && actual < 0) {
        sprintf(actualString, "-%.*f", precision, actual);
    } else {
        sprintf(actualString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == nullptr && actualString != nullptr) ||
        (expectedString != nullptr && actualString == nullptr) ||
        (expectedString && actualString && strcmp(expectedString, actualString) == 0)) {
        CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n",
                  file, line, expectedString, actualString);
    }

    // Free
    free(expectedString);
    free(actualString);
}

static int suite_all(struct CTEST* t) {
    (void) t; // fix unused parameter warning
    return 1;
}

static int suite_filter(struct CTEST* t) {
    return strncmp(suite_name, t->ssname, strlen((char *)suite_name)) == 0;
}

static uint64_t getCurrentTime() {
    struct timeval now;
    gettimeofday(&now, nullptr);
    uint64_t now64 = (uint64_t) now.tv_sec;
    now64 *= 1000000;
    now64 += ((uint64_t) now.tv_usec);
    return now64;
}

static void color_print(const_string color, const_string text) {
    if (color_output)
    printf("%s%s " ANSI_NORMAL "\n", color, text);
    else
    printf("%s\n", text);
}

#ifdef __APPLE__
static void *find_symbol(struct CTEST *test, const char *fname)
{
    size_t len = strlen(test->ssname) + 1 + strlen(fname);
    char *symbol_name = (char *) calloc(len + 1, sizeof(char));
    memset(symbol_name, 0, len + 1);
    snprintf(symbol_name, len + 1, "%s_%s", test->ssname, fname);

    //fprintf(stderr, ">>>> dlsym: loading %s\n", symbol_name);
    void *symbol = dlsym(RTLD_DEFAULT, symbol_name);
    if (!symbol) {
    //fprintf(stderr, ">>>> ERROR: %s\n", dlerror());
    }
    // returns nullptr on error

    free(symbol_name);
    return symbol;
}
#endif

#ifdef TESTING
#ifndef __APPLE__
#include <signal.h>
#endif

static void sighandler(int signum)
{
    char msg[128];
    sprintf(msg, "[SIGNAL %d]", signum);
    color_print(ANSI_BRED, msg);
    fflush(stdout);

    /* "Unregister" the signal handler and send the signal back to the process
     * so it can terminate as expected */
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}
#endif

int ctest_main(int argc, const char *argv[])
{
    static int total = 0;
    static int num_ok = 0;
    static int num_fail = 0;
    static int num_skip = 0;
    static int index = 1;
    static filter_func filter = suite_all;

#ifdef CTEST_SEGFAULT
    signal(SIGSEGV, sighandler);
#endif

    if (argc == 2) {
    suite_name = argv[1];
    filter = suite_filter;
    }
#ifdef CTEST_NO_COLORS
    color_output = 0;
#else
    color_output = isatty(1);
#endif
    uint64_t t1 = getCurrentTime();

    struct CTEST* ctest_begin = &__TNAME(suite, test);
    struct CTEST* ctest_end = &__TNAME(suite, test);
    // find begin and end of section by comparing magics
    while (1) {
    struct CTEST* t = ctest_begin-1;
    if (t->magic != __CTEST_MAGIC) break;
    ctest_begin--;
    }
    while (1) {
    struct CTEST* t = ctest_end+1;
    if (t->magic != __CTEST_MAGIC) break;
    ctest_end++;
    }
    ctest_end++;    // end after last one

    static struct CTEST* test;
    for (test = ctest_begin; test != ctest_end; test++) {
    if (test == &__TNAME(suite, test)) continue;
    if (filter(test)) total++;
    }

    for (test = ctest_begin; test != ctest_end; test++) {
    if (test == &__TNAME(suite, test)) continue;
    if (filter(test)) {
        ctest_errorbuffer[0] = 0;
        ctest_errorsize = MSG_SIZE-1;
        ctest_errormsg = ctest_errorbuffer;
        printf("TEST %d/%d %s:%s ", index, total, test->ssname, test->ttname);
        fflush(stdout);
        if (test->skip) {
        color_print(ANSI_BYELLOW, "[SKIPPED]");
        num_skip++;
        } else {
        int result = setjmp(ctest_err);
        if (result == 0) {
#ifdef __APPLE__
            if (!test->setup) {
            test->setup = (SetupFunc) find_symbol(test, "setup");
            }
            if (!test->teardown) {
            test->teardown = (TearDownFunc) find_symbol(test, "teardown");
            }
#endif

            if (test->setup) test->setup(test->data);
//                    if (test->data)
//                        test->run(test->data);
//                    else
            test->run();
            if (test->teardown) test->teardown(test->data);
            // if we got here it's ok
#ifdef CTEST_COLOR_OK
            color_print(ANSI_GREEN, "[OK]");
#else
            color_print(ANSI_GREEN, "[OK]");
#endif
            num_ok++;
        } else {
            color_print(ANSI_BRED, "[FAIL]");
            num_fail++;
        }
        if (ctest_errorsize != MSG_SIZE-1) printf("%s", ctest_errorbuffer);
        }
        index++;
    }
    }
    uint64_t t2 = getCurrentTime();

    const_string color = (num_fail) ? ANSI_BRED : ANSI_GREEN;
    char results[80];
    sprintf(results, "RESULTS: %d tests (%d ok, %d failed, %d skipped) ran in %" PRIu64 " ms", total, num_ok, num_fail, num_skip, (t2 - t1)/1000);
    color_print(color, results);
    return num_fail;
}

#endif

#endif//NATIVE_KERNEL_TEST_H

#define TEST CTEST