//
// Created by dquang on 5/20/17.
//

#ifndef NATIVE_MOCK_H
#define NATIVE_MOCK_H

void on_firebase_receive_request(int client_id, http_response* content);

void on_twilio_receive_request(int client_id, http_response* content);

void on_sendgrid_receive_request(int client_id, http_response* content);

void on_test_http_request(int client_id, http_response* content);

#endif //NATIVE_MOCK_H
