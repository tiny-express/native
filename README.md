# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)
&nbsp;[![Support Platform](https://img.shields.io/badge/platform-linux%20%7C%20osx-blue.svg)]()

This library provides a set of low-level and productivity functions for C/C++ application.

Beside standard library, we would like to have a greater customization with main goals:

- Blazing fast performance of GAS & C/C++
- Using Java packages in C++ with human readable
- Third party clients support for Food Tiny micro-components will be in java.vendor

This project is also useful for new developers in practical programming.

###  Optimization
- This library is originally developed in C but we still can make things go faster by optimizing in GAS for Linux amd64
- C version of that function should be delivered first
- Documentation for GAS can be found at here: [http://cs.lmu.edu/~ray/notes/gasexamples](http://cs.lmu.edu/~ray/notes/gasexamples)

### Useful Resources
- Debugging & Profiling with [Valgrind](http://valgrind.org/)
- Data Race Detector with [ThreadSanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)
- Leak Memory Detector with [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer)

### Get Started

#### Installation
```bash
$ git clone https://github.com/foodtiny/native.git
$ cmake . && make -j && make test
$ sudo make install
```

#### Sample program
test.cpp
```cpp
#include <native/native.hpp>
using namespace java::lang;
int main() {
    String string = "Hello world";
    System::out::println(output);
    return 0;
}
```
Compilation & Run
```bash
$ g++ -o test test.cpp -I/usr/local/include -L/usr/local/lib/libnative_static.a
$ ./test
```

#### Unit Test with C-Unit
main_test.cpp
```cpp
#define CTEST_MAIN
#define CTEST_SEGFAULT

#include <native/unit_test.h>

int main(int argc, const char *argv[]) {
   int result = ctest_main(argc, argv);
   return result;
}

TEST(YourTestSuite, YourTestCase) {
    ASSERT_STR("me", "you");
}
```

### Contributors
- You can reference coding standard for C in [here](https://www.gnu.org/prep/standards/html_node/Writing-C.html) and previous implementation before starting your contribution
- Make sure that your commits must be passed before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Please read guidelines in CONTRIBUTION.md


# Documentation

### C++ Functions

#### Type Casting
- [ ] Short - short
- [x] Integer - int
- [x] Long - long
- [x] Float - float
- [x] Double - double
- [x] String - char*
- [x] Boolean - bool

#### Collections
- [ ] ArrayList
- [ ] LinkedList
- [ ] HashMap
- [ ] HashSet
- [ ] TreeSet
- [ ] PriorityQueue

#### Builtin Functions
- [x] empty
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

### C Library
#### Common
- [x] length_pointer_char
- [x] length_pointer_pointer_char
- [x] join_pointer_pointer_char
- [x] linear_search
- [x] binary_search
- [x] quick_sort
- [x] segment_pointer_char
- [x] segment_pointer_pointer_char
#### Compress
#### Crypto
- [x] base64_encode
- [x] base64_decode
- [x] md5_encode
- [x] sha1_encode
#### Datetime
- [x] date
- [x] timestamp
#### Network
#### Storage
#### String
- [x] string_copy
- [x] string_split
- [x] string_concat
#### System
#### Thread
- [x] set_interval
- [x] set_timeout
#### Validator
- [x] is_phone_number
- [x] is_email
- [x] is_url
#### Vendor
- [x] send_sms
- [x] send_mail
- [x] send_notification
