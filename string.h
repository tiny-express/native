#ifndef BUILTIN_STRING_H
#define BUILTIN_STRING_H

#define ToString string_from_const_pointer_char
char* string_from_const_pointer_char(const char *target);

/****** STRING CONVERT *******/
#define ShortToString string_from_short
#define IntToString string_from_int
#define LongToString string_from_long
#define DoubleToString string_from_double
#define FloatToString string_from_float

#define StringToShort string_to_short
#define StringToInt string_to_int
#define StringToLong string_to_long
#define StringToDouble string_to_double
#define StringToFloat string_to_float

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

/****** STRING PROCESSING *******/
#define replaceString string_replace
#define subString string_substr
#define splitString string_split
#define indexOf string_index

char  *string_replace(char *target, char *find, char *replace_with);
char  *string_substr(char *target, int from, int to);
char **string_split(char *target, const char *delim);
char **string_slice(char **target, const char *flag);
char  *string_join(char **target, char const *delim);
int    string_index(char *target, char *subtarget);
char  *string_trim(char *target);
int    string_start(char *target, const char *prefix);
int    string_end(char *target, const char *suffix);
char  *string_random(char *target, int size);
char  *string_concat(char *target, char *subtarget);
char  *convert_to_pointer_char(char target[]);

char *string_from_to(char *target, int from, int to);
char *string_from(char *target, int from);
char *string_to(char *target, int to);
char *string_copy(char *target);
char *string_upper(char *target);
char *string_lower(char *target);
char *string_title(char *target);


#define CHAR_LIST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMBER_LIST "0123456789"

#endif

