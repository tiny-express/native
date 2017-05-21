////
//// Created by dquang on 5/20/17.
////
//
//#include "../network.h"
//
//void on_firebase_receive_request(int client_id, http_response* content) {
//
//}
//
//void on_twilio_receive_request(int client_id, http_response* content) {
//
//}
//
//void on_sendgrid_receive_request(int client_id, http_response* content) {
//
//}
//
//void on_test_http_request(int client_id, http_response* content) {
//    char* response;
//    asprintf(response, "%s %s %s\n%s: %s\n%s",
//             content->method,
//             content->path,
//             content->version,
//             content->headers[0]->name,
//             content->headers[0]->value,
//             content->body
//    );
//    send_response(client_id, response);
//}