#include "../validator.h"
#include "../unit_test.h"
#include <stdlib.h>

TEST(Validator, EmailPattern) {
    char *target = "anh_khoa.1@gmail.com";
    int result = match_email(target);
    ASSERT_TRUE(result);

    target = "";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = NULL;
    result = match_email(target);
    ASSERT_FALSE(result);


    target = "@foodtiny.vn";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = "anh_khoa.1@as.vn";
    result = match_email(target);
    ASSERT_TRUE(result);

    target = "anh_khoa.1@foodtiny.vn.net.vn";
    result = match_email(target);
    ASSERT_TRUE(result);

    target = "anh_khoa.1@.vn";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = "anh_khoa.1@-vn.com";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = "^@gmail.com";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = "a@gmail.*";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = "aaa@aaa.aaa";
    result = match_email(target);
    ASSERT_TRUE(result);

    target = "a_b_1_a@ab.com";
    result = match_email(target);
    ASSERT_TRUE(result);

    target = "!@#@!#!@#!@!@$@!#12@xxx.com";
    result = match_email(target);
    ASSERT_FALSE(result);

    target = "______@____.______";
    result = match_email(target);
    ASSERT_FALSE(result);
}

TEST(Validator, PhonePattern) {
    char *target = "0986216213";
    int result = match_phone_number(target);
    ASSERT_TRUE(result);

    target = "";
    result = match_phone_number(target);
    ASSERT_FALSE(result);

    target = NULL;
    result = match_phone_number(target);
    ASSERT_FALSE(result);

    target = "foodtiny.com.vn";
    result = match_phone_number(target);
    ASSERT_FALSE(result);

    target = "841658080147";
    result = match_phone_number(target);
    ASSERT_TRUE(result);

    target = "84986216214";
    result = match_phone_number(target);
    ASSERT_TRUE(result);

    target = "01678080147";
    result = match_phone_number(target);
    ASSERT_TRUE(result);

    target = "0985216214";
    result = match_phone_number(target);
    ASSERT_TRUE(result);

    target = "001678080147";
    result = match_phone_number(target);
    ASSERT_FALSE(result);


    target = "849090 15425";
    result = match_phone_number(target);
    ASSERT_FALSE(result);

    target = "+841657998592";
    result =match_phone_number(target);
    ASSERT_FALSE(result);

    target = "15005550006";
    result =match_phone_number(target);
    ASSERT_TRUE(result);

    target = "+15005550006";
    result =match_phone_number(target);
    ASSERT_TRUE(result);
}

//TEST(Builtin_Validator, UrlPattern) {
//    char *target = "https://goo-gle.com";
//    int result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "https://google.com.net.vn:3000";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "https://google.com.net.vn:3000/";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "https://google.com.net.vn:3000/filepath/givemeaname/";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "https://google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>value3";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "";
//    result = match_url(target);
//    ASSERT_FALSE(result);
//
//    target = NULL;
//    result = match_url(target);
//    ASSERT_FALSE(result);
//
//    target = "/google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>";
//    result = match_url(target);
//    ASSERT_FALSE(result);
//
//    target = "https://www.google.com.vn/search?site=&source=hp&q=s.com&oq=s.com&gs_l=hp.3..0i10k1l2j0j0i20k1j0l2j0i10k1j0l3.250.973.0.1195.6.6.0.0.0.0.153.612.0j5.5.0....0...1c.1.64.hp..1.4.484.0..46j35i39k1j0i131k1j0i46k1.NYmuphuoiu0";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "https://www.google.com.vn/search?q=ハンサムなE3%83%8F%E3%83%B3%E3%82%B5%E3%83%A0%E3%81%AA%E5%85%89&gs_l=serp.3...232363.232363.0.232819.1.1.0.0.0.0.137.137.0j1.1.0....0...1c.1.64.serp..0.0.0.bWmCVIHE5kI";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "https://translate.google.com.vn/#vi/ja/Quang%20%C4%91%E1%BA%B9p%20trai";
//    result = match_url(target);
//    ASSERT_TRUE(result);;
//
//    target = "https://foodtiny..vn";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "http://192.168.1.1";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//    target = "http://google.com/index.html";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//
//
//    target = "http://abc.xyz/";
//    result = match_url(target);
//    ASSERT_TRUE(result);
//}


