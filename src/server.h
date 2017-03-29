#define PAGE_404 "<html><head><title>404 File Not Found</title></head><body>libmicrohttpd demo</body></html>"

#define STATUS_OK                    200
#define STATUS_BAD_REQUEST           401
#define STATUS_NOT_FOUND             404
#define STATUS_INTERNAL_SERVER_ERROR 500
#define STATUS_UNAUTHORIZED          401

#define API_FAIL "{\"status\":0}"
#define API_OK "{\"status\":1}"

//TODO: remove these define below if not necessary anymore
#define WRONG_PASS(userType)                    ERROR_API(userType,     "1001 | wrong password")
#define WRONG_PHONE_NUMBER(userType)            ERROR_API(userType,     "1002 | wrong phone number")
#define WRONG_PASS_OR_PHONE_NUMBER(userType)    ERROR_API(userType,     "1003 | wrong password and phone number")
#define WRONG_ID(targetType)                    ERROR_API(targetType,   "1004 | wrong id")
#define ACCOUNT_ALREADY_EXIST(userType)         ERROR_API(userType,     "1005 | account already exist")
#define NOT_FOUND(targetType)                   ERROR_API(targetType,   "1006 | not found")


char *ERROR(int code, char *message);
char *ERROR_API(char *target, char *message);