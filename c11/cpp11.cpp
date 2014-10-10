#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

int auto_fun() {
	return 1;
}

// auto 自动类型推导 
void test_auto() {
	vector<int> ivec(10, 1);
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	auto data = auto_fun();	// 不建议使用，代码可读性会降低 
	cout << data << endl;
}

// 闭包：使用函数的地方定义函数,更简洁私有
// 本质上lambda是将函数转化为函数对象
// ptr_fun(atoi)可以将函数转化为函数对象，但是函数参数只有1个或2个 
void test_lambda() {
	int A[] = {1, 2, 3, 4};
	int sum = 0;
	
	// 1. 单参数 
	for_each(A, A + sizeof(A)/sizeof(int), 
		[&sum] (int num) {
			sum += num;
		});
	cout << "sum=" << sum << endl;
	
	// 2. 多参数
	sum = 0;
	for_each(A, A + sizeof(A)/sizeof(int), 
	[&sum] (int num, int num1 = 1, int num2 = 1) {
		sum += (num + num1 + num2);
	});
	cout << "sum=" << sum << endl;
	
	// 3. 传入多个全局变量
	sum = 0;
	int other = -10;
	for_each(A, A + sizeof(A)/sizeof(int), 
	[&sum, &other] (int num) {
		sum += num;
		other += num;
	});
	cout << "sum=" << sum << endl; 
	cout << "other=" << other << endl;
} 

// 自动化推导：类似于auto 
void test_decltype() {
	const vector<int> vi;
	typedef decltype (vi.begin()) CIT;
	typedef decltype (test_auto) TA;
	typedef decltype (1) INT_TYPE;
	int a; 
	typedef decltype ((a)) REF_TYPE; // 左值，一个表达式，可以放在=左边 
}

void test_initial() {
	struct C {
		int a;
		int b;
	};
	
	C c{1, 1};	// POD标准布局初始化, 有虚函数以后就不同 
	cout << c.a << " " << c.b << endl;
	
	int *a = new int[3] {1, 2, 0}; 
	int *b = new int[3]();
	//int *d = new int[3](2);
	
	vector<string> vs = {"hello", "world"};
	map<string, string> data = { {"hello", "world"}};
	cout << data["hello"]	<< endl;
	
	class D {
		int a = 1;
	};
}

// 防止某些默认函数出现，包括构造函数，类型提升等 
void test_delete() {
	class A {
		public:
			void f(int i) {
			}
			
			void f(double i) = delete;
	};
	
	A a;
	a.f(1);
}

// nullptr指针，不再使用NULL。由于NULL宏在某些平台是0，容易出现问题
void test_nullptr() {
	class A {
		public:
			void f(int i) {
			}
			void f(char *i) {
			}
	};
	
	A a;
	a.f(0);
	a.f(nullptr);
} 

void test_override_final() {
	class Base {
		public:
			virtual void f(int i) {}
	};
	
	class Derived : public Base {
		public:
			virtual void f(int i) override final {
			}
	};
}

// 三类智能指针: unique_ptr, shared_ptr, weak_ptr
// 1. unique_ptr, 不允许共享，可以转让
// 2. shared_ptr, 共享指针
// 3. weak_ptr, 共享内存但是不计数+1，避免依赖循环 
void test_stl() {
	unique_ptr<int> p1(new int(42));
	unique_ptr<int> p2 = move(p1);
	
	if (p1) {
		cout << p1.get() << endl;
	} else {
		cout << *(p2.get()) << endl;
		cout << *p2 << endl;
	}
	
	shared_ptr<int> p3(new int(43));
	shared_ptr<int> p4 = p3;
	if (p3) {
		cout << *p3 << endl;
 	}
 	
 	if (p4) {
 		cout << *(p4.get()) << endl;
 	}
 	
 	
	// 原子操作，不用分词两次内存，不容易出错。
	// foo(shared_ptr<int>(new int(43)), seed()) 会出错
	auto p5 = make_shared<int>(42);
	
	auto p = make_shared<int>(42);
	weak_ptr<int> wp = p;
	
	if (!wp.expired()) {
		shared_ptr<int> sp = wp.lock();
		cout << *sp << endl;	
	}
	
	p.reset();
	if (wp.expired())	{
		cout << "expired" << endl;
	} 
	
	if (wp.lock() == nullptr) {
		cout << "expired" << endl;
	}
}

template <class T>
class A {
	public:
		void f(T a) {
			static_assert (is_integral<T>::value, "not integer");
		}
};

void test_trait() {
	A<int> a;
	//a.f("ab");
}

int main() {
	test_auto();
	test_lambda();
	test_decltype();
	test_initial();
	test_delete();
	test_nullptr();
	test_override_final();
	test_stl();
	test_trait(); 
	return 0;
} 
