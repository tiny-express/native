//
//#include <stdlib.h>
//#include "response_parser.h"
//#include "../string.h"
//#include "../builtin.h"
//
///**
// * parse uri: method(GET, POST, PUT, PATCH ..), path and HTTP version
// * @param response
// * @param result
// * @return index of header start in response
// */
//int parse_uri(char* response, http_response *result);
//
///**
// * parse header
// * @param response
// * @param result
// * @param index
// * @return index of body start in response
// */
//int parse_header(char* response, http_response *result, int index);
//
///**
// * free memory of a pointer
// * @param pointer
// */
//void get_free(void** pointer);
//
//http_response *parse(char* response) {
//    printf("\nparse \n-%s-\n", response);
//    fflush(stdout);
//    http_response *result = malloc(sizeof(http_response));
//    printf("parse malloc\n");
//    fflush(stdout);
//    int header_index = parse_uri(response, result);
//    printf("parse uri\n");
//    fflush(stdout);
//    int body_index = parse_header(response, result, header_index);
//    printf("parse header\n");
//    result->body = string_from_to(response, body_index, length_pointer_char(response) - 1);
//    printf("end parse\n");
//    return result;
//}
//
//int parse_uri(char* response, http_response *result) {
//    result->method = malloc(sizeof(char*));
//    result->path = malloc(sizeof(char*));
//    result->version = malloc(sizeof(char*));
//    register int scan_index = 0;
//    register int mark_index = 0;
//    register int count = 0;
//    while (response[scan_index] != '\n' && response[scan_index] != '\0') {
//        if (response[scan_index] == ' ') {
//            count ++;
//            if (count == 1) {
//                result->method = string_from_to(response, mark_index, scan_index - 1);
//                mark_index = scan_index + 1;
//            } else if (count == 2) {
//                result->path = string_from_to(response, mark_index, scan_index - 1);
//                mark_index = scan_index + 1;
//            }
//        }
//        scan_index ++;
//    }
//    result->version = string_from_to(response, mark_index, scan_index - 1);
//    while (response[scan_index] == '\n' || response[scan_index] == '\r') {
//        scan_index++;
//    }
//    return scan_index;
//}
//
//int parse_header(char* response, http_response *result, int index) {
//    result->header_quantity = 0;
//    register int scan_index = index;
//    register int mark_index = scan_index;
//    while (response[scan_index - 1] != '\n' || response[scan_index] != '\n') {
//        printf("%d %d\n", scan_index, (int) response[scan_index]);
//        if (response[scan_index] == ':' && response[scan_index + 1] == ' ') {
//            result->headers[result->header_quantity] = malloc(sizeof(header*));
//            result->headers[result->header_quantity]->name = malloc(sizeof(char*));
//            char* name = string_from_to(response, mark_index, scan_index - 1);
//            result->headers[result->header_quantity]->name = name;
//            scan_index++;
//            mark_index = scan_index + 1;
////            printf("header %s: ", result->headers[result->header_quantity]->name);
////            fflush(stdout);
//        } else if (response[scan_index] == '\n') {
//            result->headers[result->header_quantity]->value = string_from_to(response, mark_index, scan_index - 1);
//            mark_index = scan_index + 1;
////            printf("%s \n", result->headers[result->header_quantity]->value);
////            fflush(stdout);
//            result->header_quantity ++;
//        }
//        scan_index ++;
//    }
//    while (response[scan_index] == '\n' || response[scan_index] == '\r') {
//        printf("%d %d\n", scan_index, (int) response[scan_index]);
//        scan_index++;
//    }
//    printf("%d %d\n", scan_index, (int) response[scan_index]);
//    printf("fuckkkkkkkkkkkkkkkkkkkkkkkkkkkk\n");
//    return scan_index;
//}
//
//// TODO @dthongvl please help me implement this function
//http_response *free_http_response(http_response *response) {
//    register int index;
//    for (index = 0; index < response->header_quantity; index++) {
//        get_free(response->headers[index]->name);
//        get_free(response->headers[index]->value);
//        get_free(response->headers[index]);
//    }
//    get_free(response->method);
//    get_free(response->path);
//    get_free(response->version);
//    get_free(response->body);
//    get_free(response);
//    return response;
//}
//
//void get_free(void** pointer) {
//    if (*pointer != NULL) {
//        free(*pointer);
//        *pointer = NULL;
//    }
//    return;
//}