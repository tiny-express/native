#include "../unit_test.h"
#include "response_parser.h"

TEST(Network, Parser) {
//    char* response = "POST /fcm/send HTTP/1.1\n"
//            "Connection: close\n"
//            "Host: localhost:9999\n"
//            "Authorization: key=AAAA\n"
//            "Content-Type: application/json\n"
//            "Content-Length: 230\n"
//            "\n"
//            "{\"to\":\"dqs-1BB\"}";
//    http_response *result = parse(response);
//    ASSERT_STR("POST", result->method);
//    ASSERT_STR("/fcm/send", result->path);
//    ASSERT_STR("HTTP/1.1", result->version);
//    ASSERT_STR("Connection", result->headers[0]->name);
//    ASSERT_STR("close", result->headers[0]->value);
//    ASSERT_STR("Host", result->headers[1]->name);
//    ASSERT_STR("localhost:9999", result->headers[1]->value);
//    ASSERT_STR("Authorization", result->headers[2]->name);
//    ASSERT_STR("key=AAAA", result->headers[2]->value);
//    ASSERT_STR("Content-Type", result->headers[3]->name);
//    ASSERT_STR("application/json", result->headers[3]->value);
//    ASSERT_STR("Content-Length", result->headers[4]->name);
//    ASSERT_STR("230", result->headers[4]->value);
//    ASSERT_STR("{\"to\":\"dqs-1BB\"}", result->body);

    // test free memory
//    header *header0 = result->headers[0];
//    header *header1 = result->headers[1];
//    header *header2 = result->headers[2];
//    header *header3 = result->headers[3];
//    header *header4 = result->headers[4];
//    free_http_response(result);
//    ASSERT_NULL(header0);
//    ASSERT_NULL(header1);
//    ASSERT_NULL(header2);
//    ASSERT_NULL(header3);
//    ASSERT_NULL(header4);
//    ASSERT_NULL(result);

//    char* response2 = "POST /test HTTP/1.1\n"
//            "Connection: close\n"
//            "Host: localhost:9999\n"
//            "Content-Length: 3\n"
//            "\n"
//            "a=b";
//    http_response *result2 = parse(response2);
//    ASSERT_STR("POST", result2->method);
//    ASSERT_STR("/test", result2->path);
//    ASSERT_STR("HTTP/1.1", result2->version);
//    ASSERT_STR("Connection", result2->headers[0]->name);
//    ASSERT_STR("close", result2->headers[0]->value);
//    ASSERT_STR("Host", result2->headers[1]->name);
//    ASSERT_STR("localhost:9999", result2->headers[1]->value);
//    ASSERT_STR("Content-Length", result2->headers[2]->name);
//    ASSERT_STR("3", result2->headers[2]->value);
}
