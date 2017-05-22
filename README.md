# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)
&nbsp;[![Support Platform](https://img.shields.io/badge/platform-linux%20%7C%20osx-blue.svg)]()

This library provides a set of low-level and productivity library for C/C++ application.

Beside standard library, we would like to have a greater customization with main goals:

- Blazing fast performance with GAS & C
- Powerful structured programming in C++ with scalability
- Java standard packages with productivity & maintainability
- Third party clients support for micro-services architecture

This project is also useful for new developers in practical programming.

###  Optimization
- This library is originally developed in C but we can make classes go faster by optimizing in GAS for Linux Amd64
- C version of that function should be delivered first

### Useful References
- [Example for GNU Assembly](http://cs.lmu.edu/~ray/notes/gasexamples)
- [GNU Coding Style for C](https://www.gnu.org/prep/standards/html_node/Writing-C.html)
- [GNU Coding Style for C++](https://gcc.gnu.org/wiki/CppConventions)
- [Oracle Java 8 API Documentation](https://docs.oracle.com/javase/8/docs/api/)

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
using namespace Java::Lang;
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
- Make sure that your commits must be passed before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Please read guidelines in CONTRIBUTION.md

# Documentation

#### Data Types
- [x] char
- [x] byte
- [x] string
- [x] short
- [x] int
- [x] long
- [x] float
- [x] double
- [x] boolean

### Additional features outside Java packages
- [x] Java.Lang.Array
- [ ] Java.Vendor.AbstractVendor
- [ ] Java.Vendor.ElasticSearch
- [ ] Java.Vendor.Etcd
- [ ] Java.Vendor.Firebase
- [ ] Java.Vendor.SendGrid
- [ ] Java.Vendor.Twilio

### Java Standard Packages
##### Java.Lang
- [ ] Java.Lang.Boolean
- [ ] Java.Lang.Byte
- [ ] Java.Lang.Character
- [ ] Java.Lang.CharSequence
- [ ] Java.Lang.Comparable
- [ ] Java.Lang.Double
- [ ] Java.Lang.Exception
- [ ] Java.Lang.Float
- [x] Java.Lang.Integer
- [ ] Java.Lang.Long
- [ ] Java.Lang.Math
- [ ] Java.Lang.Number
- [ ] Java.Lang.Object
- [ ] Java.Lang.Short
- [x] Java.Lang.String
- [ ] Java.Lang.System
- [ ] Java.Lang.Throwable
##### Java.IO
##### Java.Util
##### Java.Security
##### Java.Net