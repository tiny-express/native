# Native Library
[![Build status](https://ci.appveyor.com/api/projects/status/5rbqtwl3nyb1vcyl/branch/master?svg=true)](https://ci.appveyor.com/project/foodtiny/native)&nbsp;[![Build Status](https://travis-ci.org/foodtiny/native.svg?branch=master)](https://travis-ci.org/foodtiny/native)
[![Coverage status](https://img.shields.io/codecov/c/github/foodtiny/native/master.svg)](https://codecov.io/gh/foodtiny/native)&nbsp;[![Support Platform](https://img.shields.io/badge/platform-windows%20%7C%20linux%20%7C%20darwin-blue.svg)]()

**Native Library** brings productivity and maintainability for your C/C++ application as a Java program.

* Blazing fast, small footprint with no dependency required
* Provide rich Java Core classes beside C++ Standard Library
* Prevents nearly all memory leak and  segfaults via automatic storage
* Support bindings for NodeJS addon and Python module development (experimental)
* Classes are strictly tested with unit tests, clean with Valgrind and follow Oracle documentation
* Feel free to use in your commercial products and welcome for contributions

This project is also useful for new developers in practical programming.


## Getting started
#### Docker
```bash
$ docker pull foodtiny/native:latest
```

#### Installation
```bash
$ git clone https://github.com/foodtiny/native.git
$ cmake -DCMAKE_BUILD_TYPE=Release
$ make native && sudo make install
```

#### Benchmarking with C++/STL
[Google Benchmark](https://github.com/google/benchmark) is required for benchmarking
if you're using Linux or Mac please use ./misc/benchmark.sh to install
```bash
$ cmake -DCMAKE_BUILD_TYPE=Release
$ make native_benchmark
$ ./native_benchmark
```

#### Examples
```cpp
#include <native/library.hpp>

class MainApplication {
public:
    static void main(Array<String> arguments) {
        HashMap<String, String> hashMap;
        int counter = 0;
        for (String argument : arguments) {
            hashMap.put("argument " + String::valueOf(counter), argument);
            counter++;
        }
        System::out::println("We have 4 pairs:");
        String pairs = "Pairs: \n";
        for (Map<String, String>::Entry entry : hashMap.entrySet()) {
            pairs += entry.getKey() + String(" - ") + entry.getValue() + String("\n");
        }
        System::out::println(pairs);
        ArrayList<HashMap<String, String>> arrayList;
        arrayList.add(hashMap);
        System::out::println(arrayList.toString());
    }
};

int main(int argc, char **argv) {
    return Application(MainApplication::main, argv);
}
```

Compile your source and link with native library
```bash
$ g++ -c -o main.o HelloWorld.cpp
$ g++ -o main main.o -lnative
$ ./main one two three
```

Output:
```javascript
We have 4 pairs:
argument 3 is three
argument 2 is two
argument 1 is one
argument 0 is ./main

[{"argument 0": "./main", "argument 1": "one", "argument 2": "two", "argument 3": "three"}]
```
More examples can be found [here](https://github.com/foodtiny/native/tree/master/examples)

### Contributors
- This library must be followed [Oracle Java 8 Documentation](https://docs.oracle.com/javase/8/docs/api) for standardization
- Make sure your commits must be passed with [check](./check)  before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Best practices guidelines in [CONTRIBUTION.md](https://github.com/foodtiny/native/tree/master/CONTRIBUTION.md)

# Documentation
[![Documentation](https://img.shields.io/badge/documentation-doxygen-ff69b4.svg)](https://foodtiny.github.io/native/annotated.html)
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

#### Data Types
All data types are implemented and ready to use in C++ Application
- [x] char - Java.Lang.Character
- [x] byte - Java.Lang.Byte
- [x] string - Java.Lang.String
- [x] unicode - java.lang.Character
- [x] short - Java.Lang.Short
- [x] int - Java.Lang.Integer
- [x] long - Java.Lang.Long
- [x] float - Java.Lang.Float
- [x] double - Java.Lang.Double
- [x] boolean - Java.Lang.Boolean
- [x] enum - Java.Lang.Enum
