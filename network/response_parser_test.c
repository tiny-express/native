#include "../unit_test.h"
#include "response_parser.h"

TEST (Network, Parser) {
    #ifdef __APPLE__
        return;
    #endif
    // TODO @anhkhoa please refactor testcases below
	char *response = "HTTP/1.0 200 OK\r\n"
		"Content-Type: text/html; charset=utf-8\r\n"
		"Content-Length: 122\r\n"
		"Server: Werkzeug/0.12.2 Python/2.7.12\r\n"
		"Date: Wed, 24 May 2017 19:14:29 GMT\r\n"
        "\r\n"
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

	free_http_response(result);

	char *response2 = "HTTP/1.0 401 UNAUTHORIZED\n"
		"Content-Type: text/html; charset=utf-8\n"
		"Content-Length: 67\n"
		"Server: Werkzeug/0.12.2 Python/2.7.12\n"
		"Date: Wed, 24 May 2017 20:25:34 GMT\r\n\r\n"
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

	free_http_response(result2);

	char* response3 = "HTTP/1.0 200 OK\n"
			"Content-Type: text/html; charset=utf-8\n"
			"Content-Length: 126\n"
			"Server: Werkzeug/0.12.2 Python/2.7.12\n"
			"Date: Sun, 18 Jun 2017 17:20:23 GMT"
            "\r\n\r\n"
			"{\"action\":\"get\",\"node\":{\"key\":\"/elassandra/development/seeds/test_node\",\"value\":\"404\",\"modifiedIndex\":379,\"createdIndex\":379}}";
	http_response *result3 = parse(response3);
    ASSERT_STR("{\"action\":\"get\",\"node\":{\"key\":\"/elassandra/development/seeds/test_node\",\"value\":\"404\",\"modifiedIndex\":379,\"createdIndex\":379}}", result3->body);
    free_http_response(result3);

    char* response4 = "HTTP/1.0 404 NOT FOUND\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 233\r\n"
            "Server: Werkzeug/0.12.2 Python/2.7.12\r\n"
            "Date: Mon, 19 Jun 2017 15:02:10 GMT\r\n"
            "\r\n"
            "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">\r\n"
            "<title>404 Not Found</title>\r\n"
            "<h1>Not Found</h1>\r\n"
            "<p>The requested URL was not found on the server.  If you entered the URL manually please check your spelling and try again.</p>";
    http_response *result4 = parse(response4);
    ASSERT_STR("NOT FOUND",result4->status);
	ASSERT_STR("404", result4->status_code);
    free_http_response(result4);

    // This case test free an empty http_response, no ASSERT here
	char* response5 = "";
	http_response *result5 = parse(response5);
	free_http_response(result5);
}
