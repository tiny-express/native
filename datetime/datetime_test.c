#include "../../native/builtin.h"
#include "../unit_test.h"

TEST(Builtin_DateTime, Now) {
    ASSERT_TRUE(now() > 0);
}

TEST(Builtin_DateTime, Date) {
    long timestamp = 1473765499;
    char *format = "d/m/y";
    ASSERT_STR("13/09/2016", date(timestamp, format));

    timestamp = 1511208660;
    ASSERT_STR("20/11/2017", date(timestamp, format));

    format = "y-m-d";
    ASSERT_STR("2017-11-20", date(timestamp, format));
}