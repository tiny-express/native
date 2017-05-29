#include "../unit_test.h"
#include "response_parser.h"
#include <stdlib.h>
TEST (Network, Parser) {
#ifdef __APPLE__
    return;
#endif

    http_response* result3 = (http_response*) malloc(sizeof(http_response));
    free(result3);
    result3 = NULL;
    ASSERT_NULL(result3);
	
	char *response = "HTTP/1.0 200 OK\n"
		"Content-Type: text/html; charset=utf-8\n"
		"Content-Length: 122\n"
		"Server: Werkzeug/0.12.2 Python/2.7.12\n"
		"Date: Wed, 24 May 2017 19:14:29 GMT\n"
		"\n"
		"{\"multicast_id\":5160844598332076776,\"success\":0,"
		"\"failure\":1,\"canonical_ids\":0,"
		"\"results\":[{\"error\":\"InvalidRegistration\"}]}";
	http_response *result = parse(response);

	ASSERT_STR("HTTP/1.0", result->version);
	ASSERT_STR("200", result->status_code);
	ASSERT_STR("OK", result->status);
	ASSERT_STR("Content-Type", result->headers[ 0 ]->name);
	ASSERT_STR("text/html; charset=utf-8", result->headers[ 0 ]->value);
	ASSERT_STR("Content-Length", result->headers[ 1 ]->name);
	ASSERT_STR("122", result->headers[ 1 ]->value);
	ASSERT_STR("Server", result->headers[ 2 ]->name);
	ASSERT_STR("Werkzeug/0.12.2 Python/2.7.12", result->headers[ 2 ]->value);
	ASSERT_STR("Date", result->headers[ 3 ]->name);
	ASSERT_STR("Wed, 24 May 2017 19:14:29 GMT", result->headers[ 3 ]->value);
	ASSERT_STR("{\"multicast_id\":5160844598332076776,\"success\":0,"
		           "\"failure\":1,\"canonical_ids\":0,"
		           "\"results\":[{\"error\":\"InvalidRegistration\"}]}", result->body);

//     test free memory
	http_response *test = result;
	free_http_response(result);
	ASSERT_NULL(test->headers[ 0 ]);
	ASSERT_NULL(test->headers[ 1 ]);
	ASSERT_NULL(test->headers[ 2 ]);
	ASSERT_NULL(test->headers[ 3 ]);
	ASSERT_NULL(test->body);
	ASSERT_NULL(test->version);
	ASSERT_NULL(test->status);
	
	char *response2 = "HTTP/1.0 401 UNAUTHORIZED\n"
		"Content-Type: text/html; charset=utf-8\n"
		"Content-Length: 67\n"
		"Server: Werkzeug/0.12.2 Python/2.7.12\n"
		"Date: Wed, 24 May 2017 20:25:34 GMT\n"
		"\n"
		"Server-key delivered or Sender is not authorized to perform request";
	http_response *result2 = parse(response2);

	ASSERT_STR("HTTP/1.0", result2->version);
	ASSERT_STR("401", result2->status_code);
	ASSERT_STR("UNAUTHORIZED", result2->status);
	ASSERT_STR("Content-Type", result2->headers[ 0 ]->name);
	ASSERT_STR("text/html; charset=utf-8", result2->headers[ 0 ]->value);
	ASSERT_STR("Content-Length", result2->headers[ 1 ]->name);
	ASSERT_STR("67", result2->headers[ 1 ]->value);
	ASSERT_STR("Server", result2->headers[ 2 ]->name);
	ASSERT_STR("Werkzeug/0.12.2 Python/2.7.12", result2->headers[ 2 ]->value);
	ASSERT_STR("Date", result2->headers[ 3 ]->name);
	ASSERT_STR("Wed, 24 May 2017 20:25:34 GMT", result2->headers[ 3 ]->value);
	ASSERT_STR("Server-key delivered or Sender is not authorized to perform request", result2->body);

	//     test free memory
	test = result2;
	free_http_response(result);
	ASSERT_NULL(test->headers[ 0 ]);
	ASSERT_NULL(test->headers[ 1 ]);
	ASSERT_NULL(test->headers[ 2 ]);
	ASSERT_NULL(test->headers[ 3 ]);
//    ASSERT_NULL(result);
}
