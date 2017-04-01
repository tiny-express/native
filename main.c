#define CTEST_MAIN
#define CTEST_SEGFAULT
#include <stdio.h>
#include "unit_test.h"

int main(int argc, const char *argv[]) {
   int result = ctest_main(argc, argv);
   return result;
}
