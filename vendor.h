/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

#ifndef BUILTIN_VENDOR_H
#define BUILTIN_VENDOR_H

#define POST_METHOD "POST"
#define GET_METHOD "GET"
#define ETCD_LOCALHOST "http://127.0.0.1:2379"
#define ETCD_MASTER "http://etcd.foodtiny.net:80"
#define ETCD_DEVELOPMENT_PATH "/v2/keys/elassandra/development/seeds"

char* etcd_get(char* host, char *key);
char* etcd_set(char* host, char *key, char *value);

char *es_query(char *host, char *index, char *query);
int send_sms(char* account_id, char* account_token, char* url, char* from, char* to, char* content);
int send_mail(char *from_email, char *to_email, char *subject, char *content, char *service_url, char *service_token);
int send_notification(char *service_url, char* service_token, char* device_token, char* title, char* body, char* data);

#endif
