/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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

#include "../../../Test.hpp"
#include "HttpURLConnection.hpp"

using namespace Java::Net;
using namespace Java::Lang;

TEST (JavaNetHttpURLConnection, Constants) {
	{
		assertEquals(200, HttpURLConnection::HTTP_OK);
		assertEquals(201, HttpURLConnection::HTTP_CREATED);
		assertEquals(202, HttpURLConnection::HTTP_ACCEPTED);
		assertEquals(203, HttpURLConnection::HTTP_NOT_AUTHORITATIVE);
		assertEquals(204, HttpURLConnection::HTTP_NO_CONTENT);
		assertEquals(205, HttpURLConnection::HTTP_RESET);
		assertEquals(206, HttpURLConnection::HTTP_PARTIAL);
	}
	{
		assertEquals(300, HttpURLConnection::HTTP_MULT_CHOICE);
		assertEquals(301, HttpURLConnection::HTTP_MOVED_PERM);
		assertEquals(302, HttpURLConnection::HTTP_MOVED_TEMP);
		assertEquals(303, HttpURLConnection::HTTP_SEE_OTHER);
		assertEquals(304, HttpURLConnection::HTTP_NOT_MODIFIED);
		assertEquals(305, HttpURLConnection::HTTP_USE_PROXY);
	}
	{
		assertEquals(400, HttpURLConnection::HTTP_BAD_REQUEST);
		assertEquals(401, HttpURLConnection::HTTP_UNAUTHORIZED);
		assertEquals(402, HttpURLConnection::HTTP_PAYMENT_REQUIRED);
		assertEquals(403, HttpURLConnection::HTTP_FORBIDDEN);
		assertEquals(404, HttpURLConnection::HTTP_NOT_FOUND);
		assertEquals(405, HttpURLConnection::HTTP_BAD_METHOD);
		assertEquals(406, HttpURLConnection::HTTP_NOT_ACCEPTABLE);
		assertEquals(407, HttpURLConnection::HTTP_PROXY_AUTH);
		assertEquals(408, HttpURLConnection::HTTP_CLIENT_TIMEOUT);
		assertEquals(409, HttpURLConnection::HTTP_CONFLICT);
		assertEquals(410, HttpURLConnection::HTTP_GONE);
		assertEquals(411, HttpURLConnection::HTTP_LENGTH_REQUIRED);
		assertEquals(412, HttpURLConnection::HTTP_PRECON_FAILED);
		assertEquals(413, HttpURLConnection::HTTP_ENTITY_TOO_LARGE);
		assertEquals(414, HttpURLConnection::HTTP_REQ_TOO_LONG);
		assertEquals(415, HttpURLConnection::HTTP_UNSUPPORTED_TYPE);
	}
	{
		assertEquals(500, HttpURLConnection::HTTP_INTERNAL_ERROR);
		assertEquals(501, HttpURLConnection::HTTP_NOT_IMPLEMENTED);
		assertEquals(502, HttpURLConnection::HTTP_BAD_GATEWAY);
		assertEquals(503, HttpURLConnection::HTTP_UNAVAILABLE);
		assertEquals(504, HttpURLConnection::HTTP_GATEWAY_TIMEOUT);
		assertEquals(505, HttpURLConnection::HTTP_VERSION);
	}
}
