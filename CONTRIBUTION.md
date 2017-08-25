# CONTRIBUTION

##### COMMENT STYLE
```c
/**
* Describe what method does
* 
* @param paramName its meaning
* @param paramName2 its meaning
* @throw exception and situations it would be thrown
* @see anotherClassOrMethod they need to reference
* @return returnDataType describe what will returned
**/
```

Example:
```c
/**
 *  A test class. A more elaborate class description.
 */
class Javadoc_Test
{
  public:
    /** 
     * An enum.
     * More detailed enum description.
     */
    enum TEnum { 
          TVal1, /**< enum value TVal1. */  
          TVal2, /**< enum value TVal2. */  
          TVal3  /**< enum value TVal3. */  
         } 
       *enumPtr, /**< enum pointer. Details. */
       enumVar;  /**< enum variable. Details. */
       
      /**
       * A constructor.
       * A more elaborate description of the constructor.
       */
      Javadoc_Test();
      
      /**
       * A destructor.
       * A more elaborate description of the destructor.
       */
     ~Javadoc_Test();
    
      /**
       * a normal member taking two arguments and returning an integer value.
       *
       * @param a an integer argument.
       * @param s a constant character pointer.
       * @see Javadoc_Test()
       * @see ~Javadoc_Test()
       * @see testMeToo()
       * @see publicVar()
       * @return int The test results
       */
       int testMe(int a,const char *s);
       
      /**
       * A pure virtual member.
       *
       * @see testMe()
       * @param c1 the first argument.
       * @param c2 the second argument.
       * @throw IllegalArgumentException if c1 is uppercase
       */
       virtual void testMeToo(char c1,char c2) = 0;
   
      /** 
       * a public variable.
       * Details.
       */
       int publicVar;
       
      /**
       * a function variable.
       * Details.
       */
       int (*handler)(int a,int b);
};

```

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
// but only for Linux platform
#ifdef __linux_
register
#elif
int index = 0;
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