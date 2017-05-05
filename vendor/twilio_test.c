// TODO
#include "../builtin.h"
#include "../unit_test.h"
#include "../vendor.h"

char* account_id = "AC85ddd85dbdd4f002c799676b7ad28914";
char* from = "15005550006";
char* account_token = "87c76ffe015078c17e7080d19af46cae";
char* url = "https://api.twilio.com/2010-04-01/Accounts/AC85ddd85dbdd4f002c799676b7ad28914/Messages.json";

TEST(Vendor, Twilio) {
    char* to = "84909015425";
    char* content = "HelloSms";
    ASSERT_TRUE(send_sms(account_id, account_token, url, from, to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(account_id, account_token, url, from, to, content));

    to = "84 909 015 425";
    content = "Hello Sms";
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(account_id, account_token, url, from, to, content));

    to = "04909015425";
    content = "";
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));

    to = NULL;
    content = "";
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));

    to = "04909015425";
    content = NULL;
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));
}