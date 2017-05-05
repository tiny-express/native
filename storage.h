#ifndef BUILTIN_STORAGE_H
#define BUILTIN_STORAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <errno.h>

char *file_get_contents(char *file_name);
int file_put_contents(char *file_path, char *content);

#endif