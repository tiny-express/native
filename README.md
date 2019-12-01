# Native Library
[![Join Gitter Chat Channel -](https://badges.gitter.im/tiny-express/native.svg)](https://gitter.im/tiny-express/native?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build status](https://ci.appveyor.com/api/projects/status/5rbqtwl3nyb1vcyl/branch/master?svg=true)](https://ci.appveyor.com/project/tiny-express/native)&nbsp;[![Build Status](https://travis-ci.org/tiny-express/native.svg?branch=master)](https://travis-ci.org/tiny-express/native)
[![Coverage status](https://img.shields.io/codecov/c/github/tiny-express/native/master.svg)](https://codecov.io/gh/tiny-express/native)&nbsp;[![Support Platform](https://img.shields.io/badge/platform-windows%20%7C%20linux%20%7C%20darwin-blue.svg)]()

**Native Library** provides a set of Java packages are re-written in C++

* Blazing fast - small footprint - no dependency required
* Cross platform - outstanding performance powered by C++ STL
* Integrate directly with any C/C++ project with productivity of Java
* Prevents nearly all memory leak and segmentation fault by destructors
* Packages are strictly tested with unit tests, clean with Valgrind and follow Oracle documentation
* Feel free to use in your commercial products and welcome for contributions

## Getting started
#### Docker
```bash
$ docker pull foodtiny/native:latest
```

#### Installation
```bash
$ git clone https://github.com/tiny-express/native.git
$ cd native
$ cmake . -DCMAKE_BUILD_TYPE=Release && make native -j4 && sudo make install
```

#### Post installation
Ubuntu
```bash
$ sudo ldconfig
```

#### Examples
```cpp
#include <native/library.hpp>

#include <native/library.hpp>

class MainApplication {
public:
    static void main(Array<String> arguments) {
        HashMap<String, String> hashMap = {};
        var index = 0;
        for (var argument : arguments) {
            hashMap.put(String::valueOf(index++), argument);
        }
        hashMap.forEach([](const String &key, const String &value) {
            System::out::println(String::format("Key is %s - Value is %s", key, value));
        });
    }
};

int main(int argc, char **argv) {
    return Application(MainApplication::main, argc, argv);
}
```

Compile your source and link with native library
```bash
$ g++ -c -o main.o HelloWorld.cpp
$ g++ -o main main.o -lnative -lstdc++
$ ./main one two three
```

Output:
```javascript
Key is 3 - Value is three
Key is 2 - Value is two
Key is 0 - Value is ./main
Key is 1 - Value is one
```

Test memory clean up with Valgrind
```bash
$ valgrind ./main one two three
```

Output:
```javascript
==14685== Memcheck, a memory error detector
==14685== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==14685== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==14685== Command: ./main one two three
==14685==
Key is 3 - Value is three
Key is 2 - Value is two
Key is 0 - Value is ./main
Key is 1 - Value is one
==14685==
==14685== HEAP SUMMARY:
==14685==     in use at exit: 0 bytes in 0 blocks
==14685==   total heap usage: 2,971 allocs, 2,971 frees, 380,013 bytes allocated
==14685==
==14685== All heap blocks were freed -- no leaks are possible
==14685==
==14685== For counts of detected and suppressed errors, rerun with: -v
==14685== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

More examples can be found [here](https://github.com/tiny-express/native/tree/master/examples)
Support unit test by default via ApplicationTest [here](https://github.com/tiny-express/native/tree/master/examples/Docker/ApplicationTest)  - Powered by CUnit

# Documentation
[![Documentation](https://img.shields.io/badge/documentation-doxygen-ff69b4.svg)](https://tiny-express.github.io/native/annotated.html)
#### Differences
This library provides Java classes in C++ so its syntax are friendly for
both programming languages:

- Namespace - Package
```java
// Java
System.out.println("Java");
```
```cpp
// C++
System::out::println("C++");
```
- Array
```java
// Java
byte[] byes = {};
```
```cpp
// C++
Array<byte> bytes = {};
```

#### Primitive Data Types
All data types are implemented and ready to use in C++ Application
- [x] char - Java.Lang.Character
- [x] byte - Java.Lang.Byte
- [x] string - Java.Lang.String
- [x] short - Java.Lang.Short
- [x] int - Java.Lang.Integer
- [x] long - Java.Lang.Long
- [x] float - Java.Lang.Float
- [x] double - Java.Lang.Double
- [x] boolean - Java.Lang.Boolean
- [x] enum - Java.Lang.Enum
