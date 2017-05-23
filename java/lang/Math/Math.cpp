/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Math.hpp"
#include <math.h>
#include <stdlib.h>

using namespace Java::Lang;

double abs(double a) {
    if (a >= 0) {
        return a;
    }
    else {
        return -a; 
    }
}

float abs(float a) {
    if (a >= 0) {
        return a;
    }
    else {
        return -a; 
    }
}

int abs(int a) {
    if (a >= 0) {
        return a;
    }
    else {
        return -a; 
    }
}

long abs(long a) {
    if (a >= 0) {
        return a;
    }
    else {
        return -a; 
    }
}

double floor(double a) {
    return floor(a);
}

double max(double a, double b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

float max(float a, float b) {
     if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int	max(int a, int b) {
     if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

long max(long a, long b); {
     if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

double min(double a, double b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

float min(float a, float b) {
     if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

int	min(int a, int b) {
     if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

double pow(double a, double b) {
    return pow(a,b);
}

double random() {
    srand(time(NULL));
    return rand();
}

long round(double a) {
    return round(a);
}

int round(float a) {
    return round(a);
}

double sqrt(double a) {
    return sqrt(a);
}