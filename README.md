C++ Primer 学习札记
============================


> C++和操作系统是密不可分的。

> 尽量使用STL和智能指针，回避数组和普通指针。

目录
========

* [变量和基本类型](#变量和基本类型)
* [标准库类型](#标准库类型)
* [Chapter 4 ](#chapter_4)
* [Chapter 5 ](#chapter_5)
* [Chapter 6 ](#chapter_6)
* [Chapter 7 ](#chapter_7)
* [Chapter 8 Standard IO](#chapter_8)
* [Chapter 9 ](#chapter_9)
* [Chapter 10 ](#chapter_10)
* [Chapter 11 ](#chapter_11)
* [Chapter 12](#chapter_12)
* [Chapter 13](#chapter_13)
* [Chapter 14](#chapter_14)
* [Chapter 15](#chapter_15)
* [Chapter 16](#chapter_16)
* [Chapter 17](#chapter_17)
* [C++ 11](#c++_11)


变量和基本类型
===============

整数类型
-----------------------

- 有符号数和无符号数
	- 在机器存储角度看，有符号和无符号数都是补码bits表示，没有区别。所谓的有符号数和无符号数只是C++程序解析时产生区分而已，例如cout输出时根据类型来确定不同输出代码。[钱智慧的博客](http://www.cnblogs.com/qzhforthelife/archive/2012/10/30/2746918.html)。
	- 数组以及vector等的索引需要使用无符号数。
	- char类型unsigned还是signed是未定义的。
- 表示范围和溢出问题
	- 由于整数表示范围有限，一旦运算出错，那么将会丢失高位，出现精度丢失的情况。
	- 两个正数相加溢出时出现**负数**，两个负数相加结果可能为**正数或者负数**。可以使用`limits.h`来验证.
- 类型转换

**注意：**   
1. **跨平台**: linux开发下使用[`stdint.h`](http://www.nongnu.org/avr-libc/user-manual/stdint_8h_source.html)中封装各类整型。`unitN_t`、`intN_t`、`intptr_t`和`unitptr_t`是较常用的几个类型。

浮点类型
-----------------------
- 精度
	- float类型保证6位有效数字，double类型保证10位有效数字。double相对于float计算代价区别不大。

变量
-----------------------
- 初始化与赋值
	- 初始化在编译时就分配了空间并保存了初始值。而赋值是在程序运行过程中的一个步骤。
	- 全局变量和局部变量由于存在bbs段，所以编译器初始化为0，栈和堆中变量都没有初始化。[程序员的自我修养](http://book.douban.com/subject/3652388/)
- 变量和声明
	- `extern`可以用于声明变量。不分配空间。
- const变量作用域
	- 普通全局变量默认添加`extern`，而const变量正好相反。
- typedef
	- 用于隐藏类型的实现，而突出类型的目的。如`typedef unsigned index`。
	- 用于简化复杂类型， 如`typedef int fun(int, int)`。
	- 允许一种类型用于多个目的。

枚举
-----------------------
- 定义
	- 可以定义初值。默认从0开始，可以自定义。如`enum Form { kShape = 1, kSphere };`
	- 只能通过shape等枚举成员赋值，不同通过数字赋值。
	- 本质上枚举类型即一系列*常量*，但是语法上允许枚举成员转换为整型，反之不允许。

类类型
-----------------------
- struct和class：唯一的区别就是默认访问级别。


标准库类型
=============
> 尝试去实现这些标准库类型。

String
---------
- `string::size_type`: 不要使用int来存储size()的返回值，防止溢出。索引和size都是用`size_type`类型。
- 赋值操作：释放原始字符串占用的空间，分配新字符串所需的空间，将新字符串赋值到相应空间。
- 相加操作：使用s1 += s2无需创建临时string，而s1 = s1 + s2需要。
- `cctype`头文件判断字符类别：数字、字幕、标点、大小写、空白、十六进制。

vector
---------
- 值初始化：调用类的构造函数进行初始化，如果自定义类屏蔽了相应方法，编译将出错。
- 优先使用`!=`而不是`<`来判断循环条件：由于部分类无法比较`<`。
- 循环中倾向于每次循环中测试size的当前值。而且size()往往是内联函数，开销不大。

迭代器
----------
- 迭代器类型：决定了`*`的不同。
- `const_iterator`: 避免修改元素。
- 双向迭代器支持算术操作。

bitset
----------
> 使用unsigned或者string类型来进行初始化“位向量”。可以进行某些位的翻转，统计，重置等。

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

模板: 算法和容器支持不同的类型. 同一个sort,vector支持不同的类型. 当然类型必须满足这些算法和容器的一些要求. 如果你不满足这些要求, 效率低, 报错或者结果错误(参考effective STL).

使用类模板template来重写List, Queue.

**问:为什么模板函数或者类中不允许出现typedef重定义**     
答: 静态编译时等价于写了`typedef xx T`的形式    

模板作用域: 模板之后的函数, 语句段或者语句.

模板类型形参可以作为返回类型或函数形参类型, 函数体内变量声明以及强制类型转换.

引用模板形参类的类型成员时, 必须使用typename, 默认是数据成员.

C++引入数组的引用传递, 必须输入大小N, 无需传递长度.

> Template is a blueprint but function or class.

> compiler infers what template argument(s) to bind to template function. The compiler initialize a function template. binding for class argument is mandatory.

> why should not template class add ```<>```

Non-type template argument can get the length of array automatically.

**Type Conversion**: The arguments should all be converted or not.


Chapter 17
============

Exception
----------

The variable in local scope will be cleared when exception is threw. Therefore, the data in exception should be in global scope.

Namespace
-----------

`::` is global namespace.

MutiInheriance
--------------

virtual base class: avoid to get two base object.


C++ 11
===========


参考资料
==============


注意: ex16_49~51需要重写
注意: ex17_16~17需要重写
注意: ex17_39~42需要重写
注意: ex13_16~19需要重写
注意: ex9_40~43需要重写
注意: ex10_30~33需要重写
