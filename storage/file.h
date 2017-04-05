//
// Created by User on 4/4/17.
//

#ifndef NATIVE_FILE_H
#define NATIVE_FILE_H

#include <stdio.h>
#include <stdlib.h>

char *file_get_contents(char *file_name);
int file_put_contents(char *file_path, char *content);

#endif //NATIVE_FILE_H
