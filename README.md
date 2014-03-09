C++ Primer Notes
============================

Write down notes about C++ Primer book.

> Consider yourseflf as a compiler for static language and find what C++ is used for, you will know what happen to C++.

> Use STL more but pointers in modern C++

Contents
========

* [Chapter 1 ](#chapter_1)
* [Chapter 12](#chapter_12)
* [Chapter 13](#chapter_13)
* [Chapter 14](#chapter_14)
* [Chapter 15](#chapter_15)
* [Chapter 16](#chapter_16)


Chapter 1
==========

Basic Type
-----------------------

> C++ Standard guarantee minimum sizes. Compiler can use larger size as needed.

**Integral type**: char\short\int\long\long long\ __bool__

It depends on compiler whether `char` is `unsigned char` or `signed char`.

> C++ Standard do not define how to represent `signed` data.

**How to get the value of unsigned?**: module (-1 % 256 = 255)

It is much faster to use `int` than `long`.

**When to use unsigned and signed**: unsigned is more situable to be used as index.

**How to judge a string to be a valid float?**

use `\` to split long cout expression.

The type of `6.` is double.

The 67 in `\67` is Oct. We can use `\000` and `\x000` but Dec.

Variables
----------

Chapter 12
=========

> C++ class is able to control initialization, copying, assigning and destorying.

> C++ class allow you to make your class be the same with other built-in class.


Class
-------

**Why shouldn't we implentation every function in definition?**

1. Function implemented in definition of Class is inline. Class definition is just like the definition of Struction. Function implemention in Class definition is inline function like Macro.
2. Definition and Implementation should better be departed which is useful for uplevel.

**Why should we add Class::?**

1. Function in file is __Global__ by default.

**Every object share the same function data, how did the function know which data he should operate on?**

They use pointer __this__ to point data which is very similar with structure. 

**How did C++ protect data?**

1. public\private\protected
2. const function `double avg_price() const;`


Exercise Section 12-1
--------------------

**const function**: In order to protect member, const function can only include const function.

**Is our class definitly safe?**: Never, we can use unit test to make sure that our function is safe under most situation. However, if we make our data member to be public, the status of our object is unstable.

**const string**: `const string &data = "hello";` we must use `const` to ensure only-read string.

**Use more private utility function**: for example, `display()` function.

Constructor Function
--------------------

**Initialization list**: we can only initial const and reference variable ininitialization list. It's the only chance.

Code below is wrong. Constructor function has two phases: Initialization and computation. ci and ri is already initialied which can't be assigned in function body(computation phase). Intialization list is Initialization Phase.

```cpp
class ConstRef {
    public:
        ConstRef (int ii) {
            i = ii;
            ci = ii;
            ri = i;
        }
    private:
        int i;
        const int ci;
        int &ri;
};
``` 

**Besides**: It's faster in initialization list than computation.

Constructor with Default Argument
---------------------------------

```cpp
class Person {
    public:
    Person(const string &_str = ""): str(_str) {}
    Person(istream &_is = cin): is(_is) {}

};
```

As for `Person p;`, it introduce ambigous.

static
--------

```cpp
class Bar {
    public:
    // ...
    private:
    static Bar mem1; // ok
    Bar *mem2;
    // ok
    Bar mem3;
    // error
};

```

Chapter 13
===========

Copy Constructor
----------------

> copy initialization(=) always create a temp object, then use copy constructor to copy. It's used for being compatiable with C syntax which use `=` to initial data.

```cpp
string null_book = "9-999-99999-9"; // copy-initialization
string dots(10, '.'); // direct-initialization
string empty_copy = string(); // copy-initialization
string empty_direct; // direct-initialization
vector<string> svec(5); // copy-initialization
```

**When should we make our copy-initialization?**
There are pointer members which need to copy data, or we want to do some extra job besides copy members one by one. 


Assigning Function
-----------------


Deconstructor
------------------

Dangling Pointers
------------------

Smart Pointers
--------------------


Chapter 14
============

It's not allowed to override operator on two built-in type.

> Common override operator: ==, <<, >>, !.


Chapter 15
============

> Inheriance make us define similar classes, while Dynamic Bind let us ignore differences between similar classed.

> There are static type and dynamic type about Reference and Pointer. They may be different.

> Handler

Chapter 16
============
