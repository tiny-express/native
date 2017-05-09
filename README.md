# Native Library

[![Build Status](https://travis-ci.com/foodtiny/native.svg?token=p64HTBqDyw43Lh5iDLxP&branch=master)](https://travis-ci.com/foodtiny/native)

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
- Please read coding standard for C in [here](https://www.gnu.org/prep/standards/html_node/Writing-C.html) here before starting your contribution
- Make sure that your commits must be passed before you create pull request
- At least one contributor in this project reviews your commits (except you) before merging
- Some rules for text cases

####SHOULD
```c
TEST(General, DistributionCountingSort) {
    // Assert whatever you want
}
```

####SHOULD NOT
```c
TEST(General, binary_search) {
    // Can not be accepted
}
```