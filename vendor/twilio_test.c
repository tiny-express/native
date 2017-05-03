// TODO
#include "../builtin.h"
#include "../unit_test.h"
#include "../vendor.h"


TEST(Builtin_Vendor, TestTwilio) {
    char* to = "84909015425";
    char* content = "HelloSms";
    ASSERT_TRUE(send_sms(to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(to, content));

    to = "849090 15425";
    content = "Hello Sms";
    ASSERT_FALSE(send_sms(to, content));

    to = "+84909015425";
    content = "Hello Sms";
    ASSERT_FALSE(send_sms(to, content));

    to = "+04909015425";
    content = "";
    ASSERT_FALSE(send_sms(to, content));

    to = "+04909015425";
    content = "";
    ASSERT_FALSE(send_sms(to, content));

    to = NULL;
    content = "";
    ASSERT_FALSE(send_sms(to, content));

    to = "+04909015425";
    content = NULL;
    ASSERT_FALSE(send_sms(to, content));
}