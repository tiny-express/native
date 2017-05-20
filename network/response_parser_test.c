#include "../unit_test.h"
#include "response_parser.h"

TEST(Network, Parser) {
    char* response = "POST /fcm/send HTTP/1.1\n"
            "Connection: close\n"
            "Host: localhost:9999\n"
            "Authorization: key=AAAA\n"
            "Content-Type: application/json\n"
            "Content-Length: 230\n"
            "\n"
            "{\"to\":\"dqs-1BB}";
    http_response *result = parse(response);
    ASSERT_STR("POST", result->method);
    ASSERT_STR("/fcm/send", result->path);
    ASSERT_STR("HTTP/1.1", result->version);
    ASSERT_STR("Connection", result->headers[0]->name);
    ASSERT_STR("close", result->headers[0]->value);
    ASSERT_STR("Host", result->headers[1]->name);
    ASSERT_STR("localhost:9999", result->headers[1]->value);
    ASSERT_STR("Authorization", result->headers[2]->name);
    ASSERT_STR("key=AAAA", result->headers[2]->value);
    ASSERT_STR("Content-Type", result->headers[3]->name);
    ASSERT_STR("application/json", result->headers[3]->value);
    ASSERT_STR("Content-Length", result->headers[4]->name);
    ASSERT_STR("230", result->headers[4]->value);
    ASSERT_STR("{\"to\":\"dqs-1BB}", result->body);
    free_http_response(result);
}

TEST (Network, Free) {
    char* responses = "POST /fcm/send HTTP/1.1\n"
            "Connection: close\n"
            "Host: localhost:9999\n"
            "Authorization: key=AAAA\n"
            "Content-Type: application/json\n"
            "Content-Length: 230\n"
            "\n"
            "{\"to\":\"dqs-1BB}";
    http_response *result = parse(responses);
    free_http_response(result);
    ASSERT_NULL(result);
}