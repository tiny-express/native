#include "../validator.h"
#include "../unit_test.h"

TEST(Builtin_Validator, EmailPattern) {
    char *target = "anh_khoa.1@gmail.com";
    int expect = 1;
    int result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@foodtiny.vn";
    expect = 1;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "@foodtiny.vn";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@as.vn";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@foodtiny.vn.net.vn";
    expect = 1;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@.vn";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "anh_khoa.1@-vn.com";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "^@gmail.com";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "a@gmail.*";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "aaa@aaa.aaa";
    expect = 1;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "a_b_1_a@ab.com";
    expect = 1;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "!@#@!#!@#!@!@$@!#12@xxx.com";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);

    target = "______@____.______";
    expect = 0;
    result = match_email(target);
    ASSERT_EQUAL(expect, result);
}

TEST(Builtin_Validator, PhonePattern) {
    char *target = "0986216213";
    int expect = 1;
    int result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "foodtiny";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "0012238364";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "1234";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "1234567890909090";
    expect = 0;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "01657998592";
    expect = 1;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);

    target = "841657998592";
    expect = 1;
    result = match_phone_number(target);
    ASSERT_EQUAL(expect, result);
}

TEST(Builtin_Validator, UrlPattern) {
    char *target = "https://goo-gle.com/";
    int expect = 1;
    int result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3000";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3000/";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3000/filepath/givemeaname/";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>value3";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "";
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = NULL;
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "/google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>";
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://www.google.com.vn/search?site=&source=hp&q=s.com&oq=s.com&gs_l=hp.3..0i10k1l2j0j0i20k1j0l2j0i10k1j0l3.250.973.0.1195.6.6.0.0.0.0.153.612.0j5.5.0....0...1c.1.64.hp..1.4.484.0..46j35i39k1j0i131k1j0i46k1.NYmuphuoiu0";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://www.google.com.vn/search?q=ハンサムなE3%83%8F%E3%83%B3%E3%82%B5%E3%83%A0%E3%81%AA%E5%85%89&gs_l=serp.3...232363.232363.0.232819.1.1.0.0.0.0.137.137.0j1.1.0....0...1c.1.64.serp..0.0.0.bWmCVIHE5kI";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://translate.google.com.vn/#vi/ja/Quang%20%C4%91%E1%BA%B9p%20trai";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "http://thiendia.com/";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "http://lauxanh.us";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "https://foodtiny..vn";
    expect = 0;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "http://192.168.1.1";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

    target = "http://google.com/index.html";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);


    target = "http://abc.xyz/";
    expect = 1;
    result = match_url(target);
    ASSERT_EQUAL(expect, result);

}


