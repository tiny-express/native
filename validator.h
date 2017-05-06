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

#ifndef NATIVE_VALIDATOR_H
#define NATIVE_VALIDATOR_H

#define EMAIL_PATTERN "^[a-zA-Z0-9](([.]{1}|[_]{1})?[a-zA-Z0-9])*[@]([a-z0-9]+([.]{1}|-)?)*[a-zA-Z0-9]+[.]{1}[a-z]{2,253}$"
#define URL_PATTERN   "^http(s)?:\/\/([a-z0-9]+([\-\.]{1}[a-z0-9]+)*[\.]{1}([a-z]{2,5}|[1-9]{1,3})|localhost)(:[0-9]{1,5})?(\/.*)?([?]{1}[a-z0-9]*)*"
#define PHONE_PATTERN "^[+]{0,1}[1-9]{1,2}([0-9]){5,13}"


int is_email(char *email);
int is_phone_number(char *phone_number);
int is_url(char *url);

#endif //NATIVE_VALIDATOR_H
