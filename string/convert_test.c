#include "../../native/builtin.h"
#include "../unit_test.h"

TEST(Builtin_String, FromShort) {
    int number = 123;
    char *expect="123";
    char *result= string_from_short(number);
    ASSERT_STR(expect, result);

    int number2 = -123;
    char *expect2="-123";
    char *result2=string_from_short(number2);
    ASSERT_STR(expect2, result2);
}

TEST(Builtin_String, FromInt) {
    int input = 0;
    char *expect="0";
    char *result=string_from_int(input);
    ASSERT_STR(expect, result);

    int input1 = 1;
    char *expect1="1";
    char *result1=string_from_int(input1);
    ASSERT_STR(expect1, result1);

    int input2 = 10;
    char *expect2="10";
    char *result2=string_from_int(input2);
    ASSERT_STR(expect2, result2);

    int input3 = 2147483647;
    char *expect3="2147483647";
    char *result3=string_from_int(input3);
    ASSERT_STR(expect3,result3);

    int input4 = -2147483647;
    char *expect4="-2147483647";
    char *result4=string_from_int(input4);
    ASSERT_STR(expect4,result4);
}

TEST(Builtin_String, FromLong) {
    long input = 2147483647;
    char *expect="2147483647";
    char *result=string_from_long(input);
    ASSERT_STR(expect,result);

    long input1 = -2147483647;
    char *expect1="-2147483647";
    char *result1=string_from_long(input1);
    ASSERT_STR(expect1,result1);
}

TEST(Builtin_String, FromFloat) {
    float input = 12.56;
    char *expect="12.56";
    char *result=string_from_float(input);
    ASSERT_STR(expect,result);

    float input1 = -1.56799;
    char *expect1="-1.56799";
    char *result1=string_from_float(input1);
    ASSERT_STR(expect1,result1);
}

TEST(Builtin_String, FromDouble) {
    // TODO: fix this
    double input = 125.569123;
    char *expect="125.569123";
    char *result=string_from_double(input);
    //ASSERT_STR(expect,result);

    double input1 = -125.56123;
    char *expect1="-125.56123";
    char *result1=string_from_double(input1);
    //ASSERT_STR(expect1,result1);
}

TEST(Builtin_String, ToShort) {
    ASSERT_EQUAL(0, StringToShort(NULL));

    char *input = "123";
    short result=StringToShort(input);
    ASSERT_EQUAL(123, result);

    char *input1 = "-123";
    short result1=StringToShort(input1);
    ASSERT_EQUAL(-123, result1);
}

TEST(Builtin_String, ToInt) {
    char *input = "123";
    int result=StringToInt(input);
    ASSERT_EQUAL(123, result);

    char *input1 = "-123";
    int result1=StringToInt(input1);
    ASSERT_EQUAL(-123, result1);
}

TEST(Builtin_String, ToLong) {
    char *input = "21474836";
    long result=StringToLong(input);
    ASSERT_EQUAL(21474836, result);

    char *input1 = "-21474836";
    long result1=StringToLong(input1);
    ASSERT_EQUAL(-21474836, result1);
}

TEST(Builtin_String, ToFloat) {
    char *input = "12.56";
    float result=StringToFloat(input);
    ASSERT_EQUAL(12.56, result);

    char *input1 = "-1.56799";
    float result1=StringToFloat(input1);
    ASSERT_EQUAL(-1.56799, result1);
}

TEST(Builtin_String, ToDouble) {
    char *input = "125.569123";
    double result=StringToDouble(input);
    ASSERT_EQUAL(125.569123, result);

    char *input1 = "-125.56123";
    double result1=StringToDouble(input1);
    ASSERT_EQUAL(-125.56123, result1);
}