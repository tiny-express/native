#include "default.h"
#include <stdio.h>

char* string_default(char *target) {
	if (target != NULL) {
		return target;
	}
	return " ";
}

double number_default(double target) {
	if (target) {
		return target;
	}
	return 0;
}
