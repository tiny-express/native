# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)
&nbsp;[![Support Platform](https://img.shields.io/badge/platform-linux%20%7C%20osx-blue.svg)]()

This library provides low-level optimization and productivity library for C/C++ application.

Beside standard library, we would like to have a greater customization with some goals:

- Blazing fast performance with GAS & C
- Powerful structured programming in C++ for scalability
- Java standard packages for productivity & maintainability
- Support third party services for Food Tiny micro-services

This project is also useful for new developers in practical programming.

###  Optimization
- This library is originally developed in C but we can make classes go faster by optimizing in GAS for Linux amd64
- C version of every function should be delivered first

### Useful References
- [Example for GNU Assembly x64](http://cs.lmu.edu/~ray/notes/gasexamples)
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

#### Sample program (test.cpp)
```cpp
#include <native/library.hpp>
int main() {
    String text = "Hello world";
    System::out::println(text);
    return 0;
}
```
```bash
$ g++ -c -o test.o ./test.cpp
$ gcc -static -o native test.o -L/usr/local/lib libnative_static.a -lstdc++
$ ./native
```

#### Unit Test with C-Unit
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
- Please read guidelines in [CONTRIBUTION.md](https://github.com/foodtiny/native/tree/development/CONTRIBUTION.md)

# Documentation

#### Data Types
All data types are implemented and ready to use in C++ Application
- [x] char - Java & C++
- [x] byte - Java & C++ (unsigned char)
- [x] string - C++ (char*)
- [x] short - Java & C++
- [x] int - Java & C++
- [x] long - Java & C++
- [x] float - Java & C++
- [x] double - Java & C++
- [x] boolean - Java & C++ (bool)

#### Java Standard Packages
All Java packages are still in transformation so we can have a general look below
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
- [ ] Java.Lang.BufferedReader
- [ ] Java.Lang.FileWriter
- [ ] Java.Lang.IOException
- [ ] Java.Lang.OutputStreamWriter
- [ ] Java.Lang.Reader
- [ ] Java.Lang.Writer
##### Java.Util
- [ ] Java.Util.AbstractCollection
- [ ] Java.Util.ArrayList
- [ ] Java.Util.HashMap
- [ ] Java.Util.LinkedList
##### Java.Security
- [ ] Java.Security.MessageDigest
##### Java.Net
- [ ] Java.Net.URL
- [ ] Java.Net.HttpURLConnection

#### Additional features outside Java packages
- [x] Java.Lang.Array
- [ ] Java.Vendor.AbstractVendor
- [ ] Java.Vendor.ElasticSearch
- [ ] Java.Vendor.Etcd
- [ ] Java.Vendor.Firebase
- [ ] Java.Vendor.SendGrid
- [ ] Java.Vendor.Twilio