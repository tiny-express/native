//
// Created by User on 4/4/17.
//

#ifndef NATIVE_FILE_H
#define NATIVE_FILE_H

#include <stdio.h>
#include <stdlib.h>

// Get content of file
char *file_get_contents(char *filename);

// Put content into file
int file_put_content(char *file_path, char *content);

#endif //NATIVE_FILE_H
