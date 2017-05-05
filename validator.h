//
// Created by khoa on 24/04/2017.
//

#ifndef NATIVE_VALIDATOR_H
#define NATIVE_VALIDATOR_H

#define EMAIL_PATTERN "^[[:alnum:]._]+[@][a-z]{2,10}[.][a-z]{2,5}"
#define URL_PATTERN   "^http(s|)://[[:alnum:].-]+[.]([a-z]{2,5}|[0-9]{1,3})([:digit:]{1,5}||)(|[[:alnum:]?<>+=!/:]+)"
#define PHONE_PATTERN "^(0|84)(1[2689]|9|8)[0-9]{8}"
#define TRUE 1
#define FALSE 0

int match_email(char *email);
int match_phone_number(char *phone_number);
int match_url(char *url);

#endif //NATIVE_VALIDATOR_H
