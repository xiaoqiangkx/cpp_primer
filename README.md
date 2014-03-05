C++ Primer Notes
============================

Write down notes about C++ Primer book.

> Consider yourseflf as a compiler for static language and find what C++ is used for, you will know what happen to C++.

Contents
========

* [Chapter 12](#chapter_12)


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
