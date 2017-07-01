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

#include "../validator.h"
#include "../unit_test.h"

TEST (Validator, IsEmail) {
	char *target = "anh_khoa.1@gmail.com";
	int result = is_email(target);
	ASSERT_TRUE(result);

	target = "";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = NULL;
	result = is_email(target);
	ASSERT_FALSE(result);


	target = "@foodtiny.vn";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "anh_khoa.1@as.vn";
	result = is_email(target);
	ASSERT_TRUE(result);

	target = "anh_khoa.1@foodtiny.vn.net.vn";
	result = is_email(target);
	ASSERT_TRUE(result);

	target = "anh_khoa.1@.vn";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "anh_khoa.1@-vn.com";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "^@gmail.com";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "a@gmail.*";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "aaa@aaa.aaa";
	result = is_email(target);
	ASSERT_TRUE(result);

	target = "a_b_1_a@ab.com";
	result = is_email(target);
	ASSERT_TRUE(result);

	target = "!@#@!#!@#!@!@$@!#12@xxx.com";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "______@____.______";
	result = is_email(target);
	ASSERT_FALSE(result);

	target = "info@abxxxxxxxc.aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	result = is_email(target);
	ASSERT_TRUE(result);
}

TEST (Validator, IsPhoneNumber) {
	char *target = "0986216213";
	int result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "";
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = NULL;
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "foodtiny.com.vn";
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "841658080147";
	result = is_phone_number(target);
	ASSERT_TRUE(result);

	target = "84986216214";
	result = is_phone_number(target);
	ASSERT_TRUE(result);

	target = "01678080147";
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "0985216214";
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "001678080147";
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "8 4 9 0 9 0 1 5 4 2 5";
	result = is_phone_number(target);
	ASSERT_FALSE(result);

	target = "+841657998592";
	result = is_phone_number(target);
	ASSERT_TRUE(result);

	target = "15005550006";
	result = is_phone_number(target);
	ASSERT_TRUE(result);

	target = "+15005550006";
	result = is_phone_number(target);
	ASSERT_TRUE(result);

	target = "11111111111111111111111111111111111111";
	result = is_phone_number(target);
	ASSERT_FALSE(result);
}

TEST (Validator, IsURL) {
	char *target = "https://goo-gle.com";
	int result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://google.com.net.vn:3000";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "http://localhost:3001";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://google.com.net.vn:3000/filepath/givemeaname/";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>value3";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "";
	result = is_url(target);
	ASSERT_FALSE(result);

	target = NULL;
	result = is_url(target);
	ASSERT_FALSE(result);

	target = "/google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>";
	result = is_url(target);
	ASSERT_FALSE(result);

	target = "https://www.google.com.vn/search?site=&source=hp&q=s.com&oq=s.com&gs_l=hp.3..0i10k1l2j0j0i20k1j0l2j0i10k1j0l3.250.973.0.1195.6.6.0.0.0.0.153.612.0j5.5.0....0...1c.1.64.hp..1.4.484.0..46j35i39k1j0i131k1j0i46k1.NYmuphuoiu0";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://www.google.com.vn/search?q=ハンサムなE3%83%8F%E3%83%B3%E3%82%B5%E3%83%A0%E3%81%AA%E5%85%89&gs_l=serp.3...232363.232363.0.232819.1.1.0.0.0.0.137.137.0j1.1.0....0...1c.1.64.serp..0.0.0.bWmCVIHE5kI";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://translate.google.com.vn/#vi/ja/Quang%20%C4%91%E1%BA%B9p%20trai";
	result = is_url(target);
	ASSERT_TRUE(result);;

	target = "https://foodtiny..vn";
	result = is_url(target);
	ASSERT_FALSE(result);

	target = "http://192.168.1.1";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "http://google.com/index.html";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "http://abc.xyz/";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "http://localhost/q=?xxx";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://foodtiny.com:1234?file/adsfasdf/aa";
	result = is_url(target);
	ASSERT_TRUE(result);

	target = "https://";
	result = is_url(target);
	ASSERT_FALSE(result);

	target = "https://foodtiny.com:1286?file/adsfasdf/aa";
	result = is_url(target);
	ASSERT_TRUE(result);
}

TEST (Validator, IsEmpty) {
	char *target1 = NULL;
	ASSERT_TRUE(is_empty(target1));
	
	char *target2 = "";
	ASSERT_TRUE(is_empty(target2));
	
	char *target3 = "abcd";
	ASSERT_FALSE(is_empty(target3));
}
