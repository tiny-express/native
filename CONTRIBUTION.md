# CONTRIBUTION

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