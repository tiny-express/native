#ifndef BUILTIN_STRING_H
#define BUILTIN_STRING_H

#include "string.h"

char* string_from_short(short target);
char* string_from_int(int target);
char* string_from_long(long target);
char* string_from_double(double target);
char* string_from_float(float target);

short string_to_short(char* target);
int string_to_int(char* target);
long string_to_long(char* target);
double string_to_double(char* target);
float string_to_float(char* target);

char  *string_replace(char *target, char *find, char *replace_with);
char **string_split(char *target, const char *delim);
char  *string_join(char **target, char const *delim);
int    string_index(char *target, char *subtarget, int times);
char  *string_trim(char *target);
int    string_startswith(char *target, const char *prefix);
int    string_endswith(char *target, const char *suffix);
char  *string_random(char *target, int size);
char  *string_concat(char *target, char *subtarget);

char *string_from_to(char *target, int from, int to);
char *string_from(char *target, int from);
char *string_to(char *target, int to);
char *string_copy(char *target);
char *string_upper(char *target);
char *string_lower(char *target);
char *string_title(char *target);
char *string_standardized(char *target);

#define CHAR_LIST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMBER_LIST "0123456789"

#endif

