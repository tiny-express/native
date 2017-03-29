#ifndef BUILTIN_GENERIC_H
#define BUILTIN_GENERIC_H

char **append_pointer_char(char **target, char *append);

/*
#define P_LEN_H(TYPE); \
		TYPE *append_pointer_##TYPE(TYPE *target);
#define P_C_LEN_H(TYPE); \
		TYPE **append_pointer_constant_##TYPE(const TYPE *target);
#define P_P_LEN_H(TYPE); \
		TYPE **append_pointer_pointer_##TYPE(TYPE **target);
#define NUM_APPEND_H(TYPE); \
		TYPE _number_##TYPE(TYPE target);
char **append_pointer_pointer_char(char **target, char *append);
// append_pointer_char
P_APPEND_H(char);

/*
// append_pointer_constant_char
P_C_APPEND_H(char);
// append_pointer_pointer_char
P_P_APPEND_H(char);
// append_number_short
NUM_APPEND_H(short);
// append_pointer_short
P_APPEND_H(short);
// append_number_int
NUM_APPEND_H(int);
// append_pointer_int
P_APPEND_H(int);
// append_number_long
NUM_APPEND_H(long);
// append_pointer_long
P_APPEND_H(long);
// append_number_double
NUM_APPEND_H(double);
// append_pointer_double
P_APPEND_H(double);
// append_number_float
NUM_APPEND_H(float);
// append_pointer_float
P_APPEND_H(float);
*/

// Join

#define joinStringArray join_pointer_pointer_char
char *join_pointer_pointer_char(char **target);
char *join_delim_pointer_pointer_char(char **target, const char *delim);

char *join_pointer_short(short *target);
char *join_delim_pointer_short(short *target, const char *delim);

char *join_pointer_int(int *target);
char *join_delim_pointer_int(int *target, const char *delim);

char *join_pointer_long(long *target);
char *join_delim_pointer_long(long *target, const char *delim);

char *join_pointer_double(double *target);
char *join_delim_pointer_double(double *target, const char *delim);

char *join_pointer_float(float *target);
char *join_delim_pointer_float(float *target, const char *delim);

// Length

int length_pointer_char(char *target);
int length_pointer_constant_char(const char *target);
int length_pointer_pointer_char(char **target);

int length_short(short target);
int length_pointer_short(short *target);

int length_int(int target);
int length_pointer_int(int *target);

int length_long(long target);
int length_pointer_long(long *target);

int length_double(double target);
int length_pointer_double(double *target);

int length_float(float target);
int length_pointer_float(float *target);

// Segment

char *segment_pointer_char(char *target, int from, int to);
char *segment_pointer_constant_char(const char *target, int from, int to);
char **segment_pointer_pointer_char(char **target, int from, int to);

short *segment_pointer_short(short *target, int from, int to);
int *segment_pointer_int(int *target, int from, int to);
long *segment_pointer_long(long *target, int from, int to);
double *segment_pointer_double(double *target, int from, int to);
float *segment_pointer_float(float *target, int from, int to);

#endif
