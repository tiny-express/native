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

extern "C" {
}

#include "URL.hpp"

using namespace Java::Net;
using namespace Java::Lang;

//TEST (JavaNet, URLConstructor) {
//	String urlString = "http://test.com:3000/file/test?param=1";
//	URL url(urlString);
//	ASSERT_STR("http", url.getProtocol().toString());
//	ASSERT_STR("test.com", url.getHost().toString());
//	ASSERT_EQUAL(3000, url.getPort());
//	ASSERT_STR("/file/test", url.getPath().toString());
//	ASSERT_STR("param=1", url.getQuery().toString());
//
//	String urlString2 = "http://";
//	URL url2(urlString2);
//	ASSERT_STR("", url2.getProtocol().toString());
//	ASSERT_STR("", url2.getHost().toString());
//	ASSERT_STR("", url2.getPath().toString());
//	ASSERT_STR("", url2.getQuery().toString());
//	ASSERT_EQUAL(-1, url2.getPort());
//}
//
//TEST (JavaNet, URLToString) {
//	// Full URL with protocol, host, port, path and query
//	URL url = URL("http://test.com:80/file/test?param=1");
//	ASSERT_STR("test.com", url.getHost().toString());
//	ASSERT_STR("/file/test", url.getPath().toString());
//	ASSERT_EQUAL(80, url.getPort());
//	ASSERT_STR("http", url.getProtocol().toString());
//	ASSERT_STR("param=1", url.getQuery().toString());
//
//    string result = url.toString();
//	ASSERT_STR("http://test.com:80/file/test?param=1", result);
//	free(result);

//
//	// URL without port
//	urlString = "http://test.com/file/test?param=1";
//	URL url2(urlString);
//	ASSERT_STR("http://test.com/file/test?param=1", url2.toString());
//
//	// URL without path
//	urlString = "http://test.com:8080?param=1&param1=2";
//	URL url3(urlString);
//	ASSERT_STR("http://test.com:8080?param=1&param1=2", url3.toString());

//	// URL without query
//	urlString = "https://test.com:9200/index";
//	url = URL(urlString);
//	ASSERT_STR("https://test.com:9200/index", url.toString());
//
//	// URL with just protocol and host
//	urlString = "http://test.com";
//	url = URL(urlString);
//	ASSERT_STR("http://test.com", url.toString());
//}
