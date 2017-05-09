# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)
&nbsp; [![Support Platform](https://img.shields.io/badge/platform-linux%20%7C%20osx-yellow.svg)]()

This library provides set of functions which are common used in C/C++ application.

Beside C standard library, we would like to have a greater performance, custom optimization and easier to remember

We use this library in our production and it 's cared by Unit Test with Travis CI so it just works !

This project is also useful for new developers in practical programming 

### Standard Library
- General (length, append, join, segment, sort & search)
- Compression (gzip)
- Cryptography (md5, sha1, base64)
- Datetime (time format)
- Network (http, ip address)
- Storage (file)
- String (converter, processor)
- Threading (multiple threading, timer)
- Validation (phone, email, url)
- Data TYPE (json)
- Third Party Client (Twillio, SendGrid, Etcd, Elastic Search, Stripe, Apple/Google Push Notification)

### Road map
- Inherit good builtin functions from PHP, Python, Ruby, NodeJS and Java
- Optimize fundamental functions in GNU Assembly for performance but C version will be delivered first
- Develop fundamental algorithms and advanced data structure

### Assembly Optimization
This library is originally developed in C but we still can make things go faster by optimizing in GNU Assembly.

Note that GNU Assembly is ONLY work with Linux AMD64.

No need to enable ASM optimization for Apple MacOSX because only development.

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
register int index = 0;
for (index = 0; index < 10; index++) {
    // doSomething()
}
```

##### SHOULD NOT (C99 mode does not allowed)
```c
for (int index = 0; index < 10; index++) {
    // doSomething()
}
```
