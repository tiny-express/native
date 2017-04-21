#ifndef BUILTIN_GENERIC_H
#define BUILTIN_GENERIC_H

char **append_pointer_char(char **target, char *append);

char *join_pointer_pointer_char(char **target);
char *join_delim_pointer_pointer_char(char **target, const char *delim);

int length_pointer_char(char *target);
int length_pointer_pointer_char(char **target);

int length_short(short target);
int length_int(int target);
int length_long(long target);
int length_double(double target);
int length_float(float target);

char *segment_pointer_char(char *target, int from, int to);
char **segment_pointer_pointer_char(char **target, int from, int to);
#endif
