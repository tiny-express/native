/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

extern "C" {
#include "../../../unit_test.h"
}
#include "URL.hpp"

using namespace Java::Net;
using namespace Java::Lang;

TEST(JavaNet, URLConstructor) {
    String urlString = "http://test.com";
    URL url(urlString);
    ASSERT_STR("http://test.com", url.getURL().toCharArray());
}

TEST(JavaNet, URLIsURL) {
    String urlString = "https://goo-gle.com";
    URL url(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://google.com.net.vn:3000";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "http://localhost:3001";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://google.com.net.vn:3000/filepath/givemeaname/";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>value3";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "";
    url = URL(urlString);
    ASSERT_FALSE(url.isURL());

    urlString = "/google.com.net.vn:3334/vietnam/tphochiminh?value1+value2>";
    url = URL(urlString);
    ASSERT_FALSE(url.isURL());

    urlString = "https://www.google.com.vn/search?site=&source=hp&q=s.com&oq=s.com&gs_l=hp.3..0i10k1l2j0j0i20k1j0l2j0i10k1j0l3.250.973.0.1195.6.6.0.0.0.0.153.612.0j5.5.0....0...1c.1.64.hp..1.4.484.0..46j35i39k1j0i131k1j0i46k1.NYmuphuoiu0";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://www.google.com.vn/search?q=ハンサムなE3%83%8F%E3%83%B3%E3%82%B5%E3%83%A0%E3%81%AA%E5%85%89&gs_l=serp.3...232363.232363.0.232819.1.1.0.0.0.0.137.137.0j1.1.0....0...1c.1.64.serp..0.0.0.bWmCVIHE5kI";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://translate.google.com.vn/#vi/ja/Quang%20%C4%91%E1%BA%B9p%20trai";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://foodtiny..vn";
    url = URL(urlString);
    ASSERT_FALSE(url.isURL());

    urlString = "http://192.168.1.1";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "http://google.com/index.html";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "http://abc.xyz/";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "http://localhost/q=?xxx";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://foodtiny.com:1234?file/adsfasdf/aa";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());

    urlString = "https://";
    url = URL(urlString);
    ASSERT_FALSE(url.isURL());

    urlString = "https://foodtiny.com:1286?file/adsfasdf/aa";
    url = URL(urlString);
    ASSERT_TRUE(url.isURL());
}
