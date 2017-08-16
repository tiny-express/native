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

#ifndef JAVA_NET_HTTP_URL_CONNECTION_HPP_
#define JAVA_NET_HTTP_URL_CONNECTION_HPP_

#include "../URLConnection/URLConnection.hpp"

namespace Java {
		namespace Net {
				class HttpURLConnection : public URLConnection {
				protected:
						String method = "GET";
						int responseCode;
						String responseMessage;
						/**
						* HTTP Status-Code 200: OK.
						*/
						const int HTTP_OK = 200;
						
						/**
						* HTTP Status-Code 201: Created.
						*/
						const int HTTP_CREATED = 201;
						
						/**
						* HTTP Status-Code 202: Accepted.
						*/
						const int HTTP_ACCEPTED = 202;
						
						/**
						* HTTP Status-Code 203: Non-Authoritative Information.
						*/
						const int HTTP_NOT_AUTHORITATIVE = 203;
						
						/**
						* HTTP Status-Code 204: No Content.
						*/
						const int HTTP_NO_CONTENT = 204;
						
						/**
						* HTTP Status-Code 205: Reset Content.
						*/
						const int HTTP_RESET = 205;
						
						/**
						* HTTP Status-Code 206: Partial Content.
						*/
						const int HTTP_PARTIAL = 206;
						
						/* 3XX: relocation/redirect */
						
						/**
						* HTTP Status-Code 300: Multiple Choices.
						*/
						const int HTTP_MULT_CHOICE = 300;
						
						/**
						* HTTP Status-Code 301: Moved Permanently.
						*/
						const int HTTP_MOVED_PERM = 301;
						
						/**
						* HTTP Status-Code 302: Temporary Redirect.
						*/
						const int HTTP_MOVED_TEMP = 302;
						
						/**
						* HTTP Status-Code 303: See Other.
						*/
						const int HTTP_SEE_OTHER = 303;
						
						/**
						* HTTP Status-Code 304: Not Modified.
						*/
						const int HTTP_NOT_MODIFIED = 304;
						
						/**
						* HTTP Status-Code 305: Use Proxy.
						*/
						const int HTTP_USE_PROXY = 305;
						
						/* 4XX: client error */
						
						/**
						* HTTP Status-Code 400: Bad Request.
						*/
						const int HTTP_BAD_REQUEST = 400;
						
						/**
						* HTTP Status-Code 401: Unauthorized.
						*/
						const int HTTP_UNAUTHORIZED = 401;
						
						/**
						* HTTP Status-Code 402: Payment Required.
						*/
						const int HTTP_PAYMENT_REQUIRED = 402;
						
						/**
						* HTTP Status-Code 403: Forbidden.
						*/
						const int HTTP_FORBIDDEN = 403;
						
						/**
						* HTTP Status-Code 404: Not Found.
						*/
						const int HTTP_NOT_FOUND = 404;
						
						/**
						* HTTP Status-Code 405: Method Not Allowed.
						*/
						const int HTTP_BAD_METHOD = 405;
						
						/**
						* HTTP Status-Code 406: Not Acceptable.
						*/
						const int HTTP_NOT_ACCEPTABLE = 406;
						
						/**
						* HTTP Status-Code 407: Proxy Authentication Required.
						*/
						const int HTTP_PROXY_AUTH = 407;
						
						/**
						* HTTP Status-Code 408: Request Time-Out.
						*/
						const int HTTP_CLIENT_TIMEOUT = 408;
						
						/**
						* HTTP Status-Code 409: Conflict.
						*/
						const int HTTP_CONFLICT = 409;
						
						/**
						* HTTP Status-Code 410: Gone.
						*/
						const int HTTP_GONE = 410;
						
						/**
						* HTTP Status-Code 411: Length Required.
						*/
						const int HTTP_LENGTH_REQUIRED = 411;
						
						/**
						* HTTP Status-Code 412: Precondition Failed.
						*/
						const int HTTP_PRECON_FAILED = 412;
						
						/**
						* HTTP Status-Code 413: Request Entity Too Large.
						*/
						const int HTTP_ENTITY_TOO_LARGE = 413;
						
						/**
						* HTTP Status-Code 414: Request-URI Too Large.
						*/
						const int HTTP_REQ_TOO_LONG = 414;
						
						/**
						* HTTP Status-Code 415: Unsupported Media Type.
						*/
						const int HTTP_UNSUPPORTED_TYPE = 415;
						
						/* 5XX: server error */
						
						/**
						* HTTP Status-Code 500: Internal Server Error.
						* It is misplaced and shouldn't have existed.
						*/
						const int HTTP_SERVER_ERROR = 500;
						
						/**
						* HTTP Status-Code 500: Internal Server Error.
						*/
						const int HTTP_INTERNAL_ERROR = 500;
						
						/**
						* HTTP Status-Code 501: Not Implemented.
						*/
						const int HTTP_NOT_IMPLEMENTED = 501;
						
						/**
						* HTTP Status-Code 502: Bad Gateway.
						*/
						const int HTTP_BAD_GATEWAY = 502;
						
						/**
						* HTTP Status-Code 503: Service Unavailable.
						*/
						const int HTTP_UNAVAILABLE = 503;
						
						/**
						* HTTP Status-Code 504: Gateway Timeout.
						*/
						const int HTTP_GATEWAY_TIMEOUT = 504;
						
						/**
						* HTTP Status-Code 505: HTTP Version Not Supported.
						*/
						const int HTTP_VERSION = 505;
				protected:
						HttpURLConnection(URL url);
						~HttpURLConnection();
				
				public:
						virtual void disconnect() = 0;
						String getMethod();
						void setMethod(String method);
						int getResponseCode();
						String getResponseMessage();
				};
		}
}

#endif  // JAVA_NET_HTTP_URL_CONNECTION_HPP_