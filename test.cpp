#include <stdio.h>
#include <native/native.hpp>

int main() {
    char *text = String("Hello World");
    puts(String(len(text)));
    int number = 1021;
    puts(String(len(number)));
    return 0;
}

