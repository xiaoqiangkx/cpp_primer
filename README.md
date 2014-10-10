C++ Primer 学习札记
============================


> C++和操作系统是密不可分的。

> 尽量使用STL和智能指针，回避数组和普通指针。

目录
========

* [变量和基本类型](#变量和基本类型)
* [标准库类型](#标准库类型)
* [数组和指针](#数组和指针)
* [表达式](#表达式)
* [语句](#语句)
* [函数](#函数)
* [标准IO库](#标准IO库)
* [顺序容器](#顺序容器)
* [关联容器](#关联容器)
* [泛型算法](#泛型算法)
* [类](#类)
* [复制控制](#复制控制)
* [重载操作符与转换](#重载操作符与转换)
* [面向对象编程](#面向对象编程)
* [模板与泛型编程](#模板与泛型编程)
* [高级主题](#高级主题)
* [C++ 11/ C++ 13](#c++_11)


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
	- 所有小于int的整数提升为int，其它提升为unsigned int。bool类型false为0，true为1。
	- 显示转换：`static_cast`覆盖隐式转换，`const_cast`可以增删`const`属性，`reinterpret_cast`为位模式提供较低层次的解释。如`int *ip; char *pc = reinterpret_cast<char*>(ip);` 细颗粒地区分了类型转换权限，比旧式强制类型转换安全。

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


数组和指针
============

初始化与赋值
--------------
- 若数组未初始化，仅全局和静态变量的值默认为0或者调用默认构造函数，其它值为未定义。
- 如数组进行初始化，则未初始化的值默认赋予0或者调用默认构造函数。

ptrdiff\_t vs size\_t
-------------------
`prtdiff_t`是signed类型，而`size_t`是unsigned类型。

vector/iterator vs array/pointer
--------------------------------

1. 大小。array大小未知，只有在编译的时候可以通过size来获得大小。
2. 扩展。array无法动态扩展。
3. 速度。array和pointer访问速度更快。iterator和vector需要进行函数调用。而array和pointer的相关操作可以由编译器直接转化或者进行优化。

const pointer
-------------
自以为指向const的指针，指向的内容别人可能修改。

    typedef string *pstring;
    const pstring cstr;

等价于

    string \*const cstr

string转化为c_str
------------------
    string str = "123";
    const char *cstr = str.c_str();

多维数组
------------

> 本质上是一个长array，&ia也是一个指针，只不过+-时，移动整块的空间.

	int ia[3][4]  = { {0}, {1}, {2} };
	typedef int int_array[4];  // 定义int_arry是一个指向int[4]的指针
	int_array *ip = ia;
	int (*ip)[4] = ia;

动态数组
------------
- 初始化：
	- 数组`int *a = new int[10]();`,只能初始化为0。
	- 单个元素`int *b = new int(2);`,可以初始化为各种值。
- 释放delete：
	- `delete[]`释放普通单元素指针时行为是未定义的。

表达式
==========

位操作符
---------------

由于系统不能确保如何处理其操作数的符号位，所以使用**`unsigned`**整型来操作。

static\_cast, dynamic\_cast, const\_cast, reinterpret\_cast

前置操作符
---------------
使用前置操作符无需保存原始值。

函数+操作符
---------------
`f1() * f2()`这种表达式中`f1()`和`f2()`的调用顺序是未知的。

new后面检查bad_alloc异常的返回值
-----------------------------


语句
==========

switch
-----------

`case标号`必须是整数常量表达式，包括枚举。不允许使用浮点数。

宏DEBUG定义
-----------

NDEBUG
-----------
`$ gcc -DNDEBUG main.c`，**assert**将不会执行

编译时文件相关宏
---------------
```__FILE__, __LINE__, __TIME__, __DATA__```


函数
==========

函数重载
------------------

- `void fun(int array[10])` 和 `void fun (int (&array)[10])`是不同的，后者只接受长度为10的array，前者的10没有约束作用.
- `void fun(const int i)`和`void fun(int i)`不能实现重载，为了和C语言兼容。但是`void fun(const Type t)`和`void fun(Type t)`可以重载。

数组形参
------------------

下面三种形式等价，编译器将所有转化为`int*`

    void fun(int*);
    void fun(int[]);
    void fun(int[10]);

而
    void fun(int (&arr)[10]);

不会转化为`int*`，编译时需要同时检查长度和类型。

多维数组除了第一维，其它维度都是元素类型的一部分，必须制定。
    void fun(int (*arr)[10]);

main函数
--------------

`<cstdlib>`中定义了`EXIT_FAILTURE`和`EXIT_SUCCESS`宏返回值。**不提供return的结果时未定义的**。

默认实参
---------------

默认实参只能指定一次，尽量不要使用默认实参，容易混淆而且不能用于虚函数。

实参类型匹配
---------------

**类型提升**(char到int，枚举到int) `>` **标准转换**(char到unsigned char, char到double等) 
`>` 类类型转换

函数指针
---------------

如下所示：

    bool (*fun) (int, int)
	typedef int (*pf)(int, int)


标准IO库
==========

标准IO库应支持各类文件系统的标准输入输出以及数据的格式化输入输出。标准IO（控制台），文件IO（磁盘文件）和String IO（字符串流）。

IO流对象不可复制和赋值
--------------------

出于某种原因，标准库类型不允许复制和赋值，所以不能作为形参参数、返回值和容器内元素使用。

IO state
-----------

```while (cin >> s)```：当`cin.good()`不正确时，类型转换值为false。eofbit表示文件末尾，failbit表示可恢复错误，badbit表示系统级故障，不可恢复错误。


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


缓冲区
----------

**缓存输出的几种条件**: 

1. 程序终止。
2. 输出endl。
3. 开启flush机制。 ```cout << "first" << flush << "second << flush;``` or ```cout << unitbuf << "first" << "second" << nounitbuf;```
4. 标准输入输出共享缓冲区，出现交叉操作时。
5. 缓冲区满。

    cout.tie(&cout);//flush
    ostream& old_tie = cin.tie(&out);
    cin.tie(0);

reopen
-----------

用同一个fstream重新文件时，需要`close` 和`clear`保证fstream可用。否则会打开失败。


顺序容器
==========

> 容器只提供基本的遍历、增删改查操作。大多数额外操作则由算法库提供。

构造函数
---------------
- `vector<int> a(b);`其中a和b的容器类型和元素类型必须相同，因为仅定义了一个函数。若要支持不同的类型间赋值，使用迭代器。如`mid = a.begin() + a.size()/2; `其中`vector(a.begin(), mid)`即前半部分，`vector(mid, a.end())`即后半部分。

容器元素约束
-----------------
- 支持赋值和复制。

迭代器失效
------------------

- 没有机制来检测迭代器是否指针悬挂或者失效，所以尽量使迭代器有效范围变小，严格检查是否有增加和删除语句存在。
- insert函数在指向元素前插入数据，返回新的元素。
- 避免存储end操作返回的迭代器，直接使用`v.end()`。
- 赋值操作使迭代器失效，swap操作则不使迭代器失效。
- assign和`=`一样，将原容器清空。


关联容器
============

区别
-------------
- `erase()`返回`void`类型。不提供`assign()`。
- 容器按照键的顺序存储。
- 存储类型必须满足`<`操作。
- insert后返回`pair`，pair包括键的iterator和bool。

下标操作的副作用
---------------

如果元素不存在，将会插入一个元素，其值为值初始化。

查找multiset和multimap
----------------------
- 使用`find()`和`count()`。
- `lower_bound()`、`upper_bound()`和`equal_range()`（返回pair）。

泛型算法
=============

> 算法会对`==`操作符等有要求。

只读算法
-------------
**初始值:类型转换**

    vector<double> vec(2, 2.2);
    double sum = accumulate(vec.begin(), vec.end(), 0);

写容器元素的算法
---------------
- `fill_n`的算法需要使用插入迭代器适配器`back_inserter`来插入数据。（要求：容器必须有`push_back`方法）
- `copy`方法写入未知个数到某个容器中；
- 算法都有`_copy`和`_if`版本。
- `if`函数使用谓词函数`bool isShorter(const string &s1, const string &s2)`。
- 关联容器的键是`const`对象

类
==========

const function的本质：将this指针编译为指向const数据的指针。

C++类编译
------------

先查看所有声明，再查看定义。

单参数构造函数应该定义为explicit。

static成员变量
----------------

只有在类定义体外定义，const int和int才有地址空间。

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
所以在类内部定义本类的静态对象是ok的。因为静态对象不作为sizeof(类)的一部分

复制控制
===========

智能指针
------------

支持自动析构，支持赋值和复制。


重载操作符与转换
==============

调用操作符()
--------------

将某个对象的`()`操作符重载, 函数对象比函数更加的灵活

    struct BSS {
    	int operator() (int val) {
    		return val < 0 ? -val : val;
    	}
    };

函数对象适配器
-------------

`bind1st`和`bind2nd`以及`not1`和`not2`。

转换与类类型
--------------

`operator bool() { return false; }


面向对象编程
============

> 了解对象内存存储模型, 参考深入理解《C++对象模型》。



模板与泛型编程
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


高级主题
============

异常
----------

**不使用异常的原因：**

- 深度调用时，中间的函数必须小心处理异常；用户可能使用异常不当。[参考](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#Exceptions)


命名空间
-----------

`::` is global namespace.使用未命名的命名空间来定义仅在本文件内使用的函数。




C++ 11
===========


参考资料
==============