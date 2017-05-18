# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)
&nbsp;[![Support Platform](https://img.shields.io/badge/platform-linux%20%7C%20osx-blue.svg)]()

This library provides a set of standard functions which are common used in C/C++ application.

Beside C standard library, we would like to have a greater performance, custom optimization and easier to remember

We use this library in our production and unit test with Travis CI so it just works !

This project is also useful for new developers in practical programming

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

#### Installation
```bash
$ git clone https://github.com/foodtiny/native.git
$ make -j && make test
$ sudo make install
```

#### Sample program
```cpp
#include <stdio.h>
#include <native/native.h>

int main() {
    char *sample_text = "Hello World";
    printf("Length of sample_text is %d\n", len(sample_text));
    int sample_number = 1021;
    printf("Length of sample_number is %d\n", len(sample_number));
    fflush(stdout);
    return 0;
}
```

#### Unit test with native (thanks to C-Unit)
```cpp
#include <native/unit_test.h>

TEST(YourTestSuite, YourTestCase) {
    ASSERT_STR("me", "you");
}
```
```
Note: You need to link your program with native library (libnative_static.a or libnative.so)
```
### Contributors
- You can reference coding standard for C in [here](https://www.gnu.org/prep/standards/html_node/Writing-C.html) and previous implementation before starting your contribution
- Make sure that your commits must be passed before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Please read guidelines in CONTRIBUTION.md


# Documentation

### Productivity C++ Functions

#### Standard Type
- [ ] Short
- [x] Integer
- [x] Long
- [x] Float
- [x] Double
- [x] String
- [x] Boolean

#### Utility Functions
- [x] len
- [ ] copy
- [ ] split
- [ ] trim
- [ ] join
- [ ] range
- [ ] sorted
- [ ] reversed
- [ ] random
- [ ] print
- [ ] file
- [ ] chr
- [ ] ord
- [x] round
- [x] md5
- [x] sha1
- [ ] type

### Standard C Library
#### Common
- [x] length_pointer_char
- [x] length_pointer_pointer_char
- [x] join_pointer_pointer_char
#### Compress
#### Crypto
#### Datetime
#### Network
#### Storage
#### String
- [x] string_copy
- [x] string_split
- [x] string_concat
#### System
#### Thread
#### Type
#### Validator
#### Vendor
- [x] send_sms
- [x] send_mail
- [x] send_notification
