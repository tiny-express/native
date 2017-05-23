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

### Useful resource
- [Example for GNU Assembly x64](http://cs.lmu.edu/~ray/notes/gasexamples)
- [GNU Coding Style for C](https://www.gnu.org/prep/standards/html_node/Writing-C.html)
- [GNU Coding Style for C++](https://gcc.gnu.org/wiki/CppConventions)
- [Oracle Java 8 API Documentation](https://docs.oracle.com/javase/8/docs/api/)

### Get Started

#### Prerequisites
- [x] CMake 2.8
- [x] GCC 4.8.1
- [x] OpenSSL
- [x] Zlib

#### Installation
```bash
$ git clone https://github.com/foodtiny/native.git
$ cmake . && make -j && make test
$ sudo make install
```

#### Usage (test.cpp)
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
- This library must be followed [Oracle Java 8 Documentation](https://docs.oracle.com/javase/8/docs/api) for standardization
- Make sure that your commits must be passed before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Best practices guidelines in [CONTRIBUTION.md](https://github.com/foodtiny/native/tree/development/CONTRIBUTION.md)

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
All Java packages are in transformation so we can have a general look about road map

##### Java.Lang
- [ ] Java.Lang.Appendable
- [ ] Java.Lang.Autocloseable
- [ ] Java.Lang.Boolean
- [ ] Java.Lang.Byte
- [ ] Java.Lang.Character
- [ ] Java.Lang.CharSequence
- [ ] Java.Lang.Cloneable
- [ ] Java.Lang.Comparable
- [ ] Java.Lang.Double
- [ ] Java.Lang.Enum
- [ ] Java.Lang.Error
- [ ] Java.Lang.Exception
- [ ] Java.Lang.Float
- [x] Java.Lang.Integer
- [ ] Java.Lang.Long
- [ ] Java.Lang.Math
- [x] Java.Lang.Number
- [x] Java.Lang.Object
- [ ] Java.Lang.Readable
- [ ] Java.Lang.Runnable
- [x] Java.Lang.Short
- [x] Java.Lang.String
- [ ] Java.Lang.System
- [ ] Java.Lang.Throwable
##### Java.IO
- [ ] Java.Lang.BufferedReader
- [ ] Java.Lang.BufferedWriter
- [ ] Java.Lang.CharArrayWriter
- [ ] Java.Lang.Console
- [ ] Java.Lang.FileDescriptor
- [ ] Java.Lang.FileFilter
- [ ] Java.Lang.FileWriter
- [ ] Java.Lang.Flushable
- [ ] Java.Lang.InputStream
- [ ] Java.Lang.IOError
- [ ] Java.Lang.IOException
- [ ] Java.Lang.ObjectInput
- [ ] Java.Lang.ObjectOutput
- [ ] Java.Lang.OutputStream
- [ ] Java.Lang.OutputStreamWriter
- [ ] Java.Lang.PipedWriter
- [ ] Java.Lang.PrintWriter
- [ ] Java.Lang.Reader
- [ ] Java.Lang.Serializable
- [ ] Java.Lang.StreamTokenizer
- [ ] Java.Lang.Writer

##### Java.Util
- [ ] Java.Util.AbstractCollection
- [ ] Java.Util.AbstractList
- [ ] Java.Util.AbstractMap
- [ ] Java.Util.AbstractSet
- [ ] Java.Util.ArrayList
- [ ] Java.Util.Arrays
- [ ] Java.Util.BitSet
- [ ] Java.Util.Base64
- [ ] Java.Util.Calendar
- [ ] Java.Util.Collection
- [ ] Java.Util.Collections
- [ ] Java.Util.Currency
- [ ] Java.Util.Date
- [ ] Java.Util.EnumMap
- [ ] Java.Util.EnumSet
- [ ] Java.Util.HashMap
- [ ] Java.Util.HashSet
- [ ] Java.Util.Iterable
- [ ] Java.Util.LinkedListHashSet
- [ ] Java.Util.LinkedList
- [ ] Java.Util.List
- [ ] Java.Util.Map
- [ ] Java.Util.Observable
- [ ] Java.Util.PriorityQueue
- [ ] Java.Util.Queue
- [ ] Java.Util.Random
- [ ] Java.Util.Scanner
- [ ] Java.Util.Set
- [ ] Java.Util.SimpleTimeZone
- [ ] Java.Util.Stack
- [ ] Java.Util.Timer
- [ ] Java.Util.TimerTask
- [ ] Java.Util.TimeZone
- [ ] Java.Util.TreeSet
- [ ] Java.Util.UUID
- [ ] Java.Util.Vector

##### Java.Security
- [ ] Java.Security.Certificate
- [ ] Java.Security.KeyFactory
- [ ] Java.Security.KeyStore
- [ ] Java.Security.MessageDigest

##### Java.Net
- [ ] Java.Net.HttpURLConnection
- [ ] Java.Net.URL
- [ ] Java.Net.URLEncoder
- [ ] Java.Net.URLDecoder

#### Additional features outside Java packages
- [x] Java.Lang.Array
- [ ] Java.Vendor.AbstractVendor
- [ ] Java.Vendor.ElasticSearch
- [ ] Java.Vendor.Etcd
- [ ] Java.Vendor.Firebase
- [ ] Java.Vendor.SendGrid
- [ ] Java.Vendor.Twilio