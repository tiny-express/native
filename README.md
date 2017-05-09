# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)
&nbsp;[![Support Platform](https://img.shields.io/badge/platform-linux%20%7C%20osx-yellow.svg)]()

This library provides a set of standard functions which are common used in C/C++ application.

Beside C standard library, we would like to have a greater performance, custom optimization and easier to remember

We use this library in our production and unit test with Travis CI so it just works !

This project is also useful for new developers in practical programming

### Standard Library
- Generic functions (length, append, join, segment, sort, search)
- Compression (gzip)
- Cryptography (md5, sha1, base64)
- Datetime (timestamp, date format)
- Network (http, ip address)
- Storage (file)
- String (converter, processor)
- Threading (multiple threading, timer)
- Validation (phone, email, url)
- Data Type (json)
- Third Party (Twilio, SendGrid, Etcd, ElasticSearch, Stripe, Firebase)

### Road map
- Inherit good builtin functions from PHP, Python, Ruby, NodeJS, Perl
- Develop fundamental algorithms and advanced data structure
- Fix comments and complete test cases for all exported functions

### Assembly Optimization
- This library is originally developed in C but we still can make things go faster by optimizing in GNU Assembly
- C version of that function should be implemented first then optimize again for Linux platform
- GNU Assembly (GAS) in this project is ONLY compatible with Linux amd64

### Useful Resources
- Debugging & Profiling with [Valgrind](http://valgrind.org/)
- Data Race Detector with [ThreadSanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)
- Leak Memory Detector with [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer)

### Get Started
Installation
```bash
git clone https://github.com/foodtiny/native.git
$ make -j && make test
$ sudo make install
```
Sample program with length_pointer_char
```c
#include <stdio.h>
#include <native/general.h>

int main() {
    char *sample_text = "Hello World";
    printf("Length of sample_text is %d\n", length_pointer_char(sample));
    fflush(stdout);
    return 0;
}
```
Note: You need to link your program with native library (libnative_static.a or libnative.so)


### Contributors
- Please read coding standard for C in [here](https://www.gnu.org/prep/standards/html_node/Writing-C.html) and previous implementation before starting your contribution
- Make sure that your commits must be passed before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Some popular rules in this project

##### SHOULD (Test case name must be named in camel syntax)
```c
TEST(General, DistributionCountingSort) {
    // Assert whatever you want
}
```

##### SHOULD NOT
```c
TEST(General, distribution_sort) {
    // Can not be accepted
}
```

##### SHOULD
```c
int array_length = 10;
// Put loop variable in register to optimize performance
register int index = 0;
for (index = 0; index < array_length; index++) {
    // doSomething()
}
```

##### SHOULD NOT
- C99 mode - Declaring variable inside loop parameters can not be allowed here
- Use calculation in loop parameters
```c
for (int index = 0; index < length_pointer_char(array); index++) {
    // doSomething()
}
```