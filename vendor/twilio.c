// TODO - Twilio Service
#include <printf.h>
#include <stdio.h>
#include "../vendor.h"
#include "../network.h"
#include "../string.h"
#include "../crypto.h"
#include "../general.h"

char* account_id = "AC85ddd85dbdd4f002c799676b7ad28914";
char* account_token = "87c76ffe015078c17e7080d19af46cae";
char* from = "15005550006";
char* url = "https://api.twilio.com/2010-04-01/Accounts/AC85ddd85dbdd4f002c799676b7ad28914/Messages.json";

int send_sms(char* to, char* content) {

    char *auth_string = "";
    auth_string = string_concat(auth_string, account_id);
    auth_string = string_concat(auth_string, ":");
    auth_string = string_concat(auth_string,account_token);
//    auth_string = string_concat(auth_string, "@");
//    auth_string = base64_encode(auth_string, sizeof(auth_string));
    char *xbod;
//    asprintf(&xbody,);
    char *body[1] = {
            "&Body=Hello&From=%2B15005550006&To=%2B841657998592",
            '\0'
    };
    char *headers[5] = {
            "Content-Length: 90",
            "Content-Type: application/x-www-form-urlencoded",
            string_concat("Authorization: Basic ", "QUM4NWRkZDg1ZGJkZDRmMDAyYzc5OTY3NmI3YWQyODkxNDo4N2M3NmZmZTAxNTA3OGMxN2U3MDgwZDE5YWY0NmNhZQ=="),
            "\0"
    };

    char *response = http_request("POST", url, headers, body);
    printf("%s\n",response);
    //printf("%s\n", xbody);
    return 0;
}