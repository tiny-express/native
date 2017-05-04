// TODO
#include "../builtin.h"
#include "../unit_test.h"
#include "../vendor.h"

char* from = "15005550006";

TEST(Vendor, Twilio) {
    char* to = "84909015425";
    char* content = "HelloSms";
    ASSERT_TRUE(send_sms(from, to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(from, to, content));

    to = "84 909 015 425";
    content = "Hello Sms";
    ASSERT_FALSE(send_sms(from, to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(from, to, content));

    to = "04909015425";
    content = "";
    ASSERT_FALSE(send_sms(from, to, content));

    to = NULL;
    content = "";
    ASSERT_FALSE(send_sms(from, to, content));

    to = "04909015425";
    content = NULL;
    ASSERT_FALSE(send_sms(from, to, content));
}