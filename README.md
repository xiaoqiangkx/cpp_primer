C++ Primer Notes
============================

Write down notes about C++ Primer book.

> Consider yourseflf as a compiler for static language and find what C++ is used for, you will know what happen to C++.

> Use STL more but pointers in modern C++

> C++ is compatible with C. He has many features that is not suitable but inheritanted from C.

Contents
========

* [Chapter 2 ](#chapter_2)
* [Chapter 3 ](#chapter_3)
* [Chapter 4 ](#chapter_4)
* [Chapter 5 ](#chapter_5)
* [Chapter 6 ](#chapter_6)
* [Chapter 7 ](#chapter_7)
* [Chapter 8 ](#chapter_8)
* [Chapter 9 ](#chapter_9)
* [Chapter 10 ](#chapter_10)
* [Chapter 11 ](#chapter_11)
* [Chapter 12](#chapter_12)
* [Chapter 13](#chapter_13)
* [Chapter 14](#chapter_14)
* [Chapter 15](#chapter_15)
* [Chapter 16](#chapter_16)


Chapter 2
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

> Initialization is not Define plus Assign. direct-initialization(`int ival(1024);`) and copy-initialization(`int ival = 1024;`)

> variables in stack and class are not initialized automatically.

Definition and Declaration
--------------------------

Definition malloc memory and initialize variables while Declaration indicate type and name of variables.

Const
--------

`const` and `static` are file local while `extern` are program local.
header file: Never define `int a = 1;` which leads to define global variable twice. On the other hand, const variable is file local. As for function, inline and Macro will be substitute in compiling which will never conflict. 

enum
-------

1. enum should use constant expression to initialize.
2. enum variable can only be assigned and defined by enum variable or enum selection.

struct and class
----------------

The only difference between them is the default visit level.

Header File
----------------

use `#ifdef #define #endif` to avoid load header file more than once.


Chapter 3
=========

two library will conflict if they define the same varibles and the file include two namespaces.

As shown in `ex3_1namespace.cpp`

string::size\_type
------------------

use `size_type` to avoid overflow which is not included in std namespace.

vector
---------

Vector is a class template used to make class definition or function definition. When compiling the program, the program make some class definition.

const\_iterator and const iterator
----------------------------------

const\_iterator: iterator to const data.
const iterator: const iterator to data.

**iter1 - iter2**: The "-" of iterator is operation override function.
return difference\_type

**In General**:

Use size\_t, difference\_size, string::size\_type, size\_t and so on.
Use container more.
Use Iterator and typedef more.


Chapter 4
==========

vector/iterator vs array/pointer
--------------------------------

Use vector more. **Is iterator better than pointer?**

1. Size. Size of array is unknown. Array must use const expression to define dimension because the size of array is decided in compiling time.
2. Security. Intialize pointer to NULL, then you will find the problem when use it without assigning.

const pointer
-------------

```cpp
typedef string *pstring;
const pstring cstr;
```

equals:
`string \*const cstr`. 

const pointer to a string. Because pstring is string pointer.

`const int \*ptr` is legal while `int \*const ptr` is not legal which is not initialized.

string and c-style string
--------------------------

```cpp
string str = "123";
const char \*cstr = str.c\_str();
```
the change of str make influence on cstr.

mutil-array
------------

It is just a long array.
```cpp
int [3][4] ia = { {0}, {1}, {2} };
typedef int int_array[4];
int_array *ip = ia;
```

**In General**: Take care of edge when using Array and Pointer. Use typedef more. 


Chapter 5
==========

Type Conversion
---------------

static\_cast, dynamic\_cast, const\_cast, reinterpret\_cast

Chapter 6
==========

try and catch
--------------
Exception will be throw upward oppsite with the backtrace.

debug
-----------

**NDEBUG**
`$ gcc -DNDEBUG main.c`

**assert** will excute expression if NDEBUG not defined.

**SOURCE FILE INFO**
```__FILE__, __LINE__, __TIME__, __DATA__```


Chapter 7
==========

const argument
----------------

Be able to store const and non-const variable.

Function Overload
------------------

`void fun(int array[10])` and `void fun (int (&array)[10])` is different, the latter can only accept an array with length of 10.

Take care of ambigous when using default argument.

**Overload Resolution**: Do not convert type, Do not convert down type. `const` is not allowed to act as a differnet fuction variable. Do not use overload only if it is really more convenient.

When It comes to reference and pointer, `const` can be used as different overload function.

Lifetime and Scope
------------------
The initialization expression of static variable will be excuted once.

`inline function` is static file scope.

Default Constructor
--------------------

Only initialize class type variable.

Chapter 8
==========

Header File
-------------

fstream and sstream is inheritanted form iostream.
ostream and istream is two base stream for reading and writing.

stream can not be copied for some reason.

IO state
-----------

```while (cin >> s)``` will just stop the reader if encounting bad, fail or eof situation.

```cpp
int ival;

while (cin >> ival, !cin.eof()) {
	if (cin.bad())
		throw runtime_error("IO stream corrupted");

	if (cin.fail()) {
		cerr << "bad data, try again." << endl;
		cin.clear(iostream::failbit);
		continue;	
	}

	//ok to process ival
}
```

Buffer
----------

**When to flush buffer**: 

1. program finished.
2. endl.
3. invoke stream function flush. ```cout << "first" << flush << "second << flush;``` or ```cout << unitbuf << "first" << "second" << nounitbuf;```
4. using read and write stream (cin and cout are tied together and share one buffer in order to ensure that any output is earlier than input)
5. buffer is full.

```cpp
cout.tie(&cout);    //flush
ostream& old_tie = cin.tie(&out);
cin.tie(0);
```

**Pay Attention**: endl will flush but '\n' do not.

fstream
-----------

The operation of fstream is similar with iostream which is its parent.

reopen
-----------

We should `close` and `clear` a stream before we reopen it.


Chapter 9
==========

Elements in container must be able to copy and assign, therefore ostream and reference is not allowed.

```vector<Foo> bad(10); vector<Foo> ok(10,1);``` will call the constructor. 

Deque and Vector support Relation Operation other than `!=` and `==`.

We should use `!=` to travesal container, because container other than deque and vector do not support ```>``` and so on.

`eraze` and `push` will make iterator fail.

use `value\_type`, `reference`, `const\_reference` to indicate type, then we need not know the type of container value.

Front Back `[]` at()
--------------------

Return: All function return reference.

front(), back(), `[]` will not throw error, but at() will throw out_of_range error.

Vector Growth
--------------

Vector try its best to avoid resize too frequently.

Container Adapter
-----------------

stack ~= vector, list, deque

queue ~= list, deque (push\_front)

priority\_queue ~= vector, deque (random-acess)


Chapter 10
============

use set to record words.

Add Element in Map
-------------------

```map["hello"]++;``` is useful in counting words.

Chapter 11
==========

The more STL you use, the more time you save.

Back\_inserter
--------------

Avoid insert data outside of Container. 

Container Conversion Automatically
-----------------------------------

double will be converted to int automatically.

```cpp
vector<double> vec(2, 2.2);
double sum = accumulate(vec.begin(), vec.end(), 0);
```

Const Iterator
--------------

```const vector<int> vec;``` vec.begin() is a const iterator.

Why the iterator of list is bi-direction.

Use structure of algorithm to remember its function. (argument, name and iterator)

Chapter 12
==========

> C++ class is able to control initialization, copying, assigning and destorying.

> C++ class allow you to make your class be the same with other built-in class.


Class
-------

Definition of Class
-------------------

> The definition of class and built-in type is defferent, which compiler do not malloc memory for it. (The definition of class and creation of object is equal to declaration and definition of built-in type)

Class Definition is actually a declaring which do not malloc memory, so we should not give class member a definition in class.

**Why is not allowed to define a class object in the same class?**

```cpp
class Link;
class LinkScreen;
class LinkScreen {
   Link* linkScreen1;
   LinkScreen linkScreen2; 
};

class Link {}; 
```

It leads to recursive forever. [reference](http://stackoverflow.com/questions/22368353/why-is-it-not-allowed-to-define-a-class-object-in-the-same-class)

**Why shouldn't we implentation every function in definition?**

1. Function implemented in definition of Class is inline. Class definition is just like the definition of Struction. Function implemention in Class definition is inline function like Macro.
2. Definition and Implementation should better be departed which is useful for uplevel.

this
----------

It is useful when we want reference the object but its members. (return itself)


**Why should we add Class::?**

1. Function in file is __Global__ by default.

**Every object share the same function data, how did the function know which data he should operate on?**

They use pointer __this__ to point data which is very similar with structure. 

**How did C++ protect data?**

1. public\private\protected
2. const function `double avg\_price() const;`


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

> Copy Initialization build a temp object, then call direct-initialization.

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

When Do we need override direct-initialization. When We need to allocate data, make a unique id and so on.

**How to avoid direct-initialization?**

Make a private dirrect initialization function declaration, then friend class\function and object can not use it.


Scope
------------

`const Object&` can not protect the pointer value of object.

We can change the value of object in the same kind of class object.

```cpp
class test {
    public:
        void change(test t) { t.a = 3;}
    private:
        int a = 3;
}
```

Assigning Function
-----------------


Destructor
------------------

while local scope finished(encounter '}'), destructor is invoked.

User-defined destructor is used to free memory in constructor or run-time of object. If we need user-defined destructor, we also need copy initialization and direct initialization.

Dangling Pointers
------------------

Data a pointer points to is deleted. The pointer is now dangling.

Smart Pointers
--------------------

use counter with pointer class member.

Chapter 14
============

It's not allowed to override operator on two built-in type.

> Common override operator: ==, <<, >>, !.

> No `short-cut` on `||` and `&&`

> sort use `<` and find use `==`

`++` and `--` with prefix and postfix which need to save the state before.

Function object
----------------

**Logical-Math-Relational**
In functional header, there are some Function object. object() is euqal to function. 

Chapter 15
============

> Inheriance make us define similar classes, while Dynamic Bind let us ignore differences between similar classes.

> There are static type and dynamic type about Reference and Pointer. They may be different.

> Handler

Chapter 16
============

> Template is a blueprint but function or class.

> compiler infers what template argument(s) to bind to template function. The compiler initialize a function template. binding for class argument is mandatory.

> why should not template class add ```<>```

Non-type template argument can get the length of array automatically.

**Type Conversion**: The arguments should all be converted or not.
