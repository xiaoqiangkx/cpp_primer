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

// auto �Զ������Ƶ� 
void test_auto() {
	vector<int> ivec(10, 1);
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	
	auto data = auto_fun();	// ������ʹ�ã�����ɶ��Իή�� 
	cout << data << endl;
}

// �հ���ʹ�ú����ĵط����庯��,�����˽��
// ������lambda�ǽ�����ת��Ϊ��������
// ptr_fun(atoi)���Խ�����ת��Ϊ�������󣬵��Ǻ�������ֻ��1����2�� 
void test_lambda() {
	int A[] = {1, 2, 3, 4};
	int sum = 0;
	
	// 1. ������ 
	for_each(A, A + sizeof(A)/sizeof(int), 
		[&sum] (int num) {
			sum += num;
		});
	cout << "sum=" << sum << endl;
	
	// 2. �����
	sum = 0;
	for_each(A, A + sizeof(A)/sizeof(int), 
	[&sum] (int num, int num1 = 1, int num2 = 1) {
		sum += (num + num1 + num2);
	});
	cout << "sum=" << sum << endl;
	
	// 3. ������ȫ�ֱ���
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

// �Զ����Ƶ���������auto 
void test_decltype() {
	const vector<int> vi;
	typedef decltype (vi.begin()) CIT;
	typedef decltype (test_auto) TA;
	typedef decltype (1) INT_TYPE;
	int a; 
	typedef decltype ((a)) REF_TYPE; // ��ֵ��һ�����ʽ�����Է���=��� 
}

void test_initial() {
	struct C {
		int a;
		int b;
	};
	
	C c{1, 1};	// POD��׼���ֳ�ʼ��, ���麯���Ժ�Ͳ�ͬ 
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

// ��ֹĳЩĬ�Ϻ������֣��������캯�������������� 
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

// nullptrָ�룬����ʹ��NULL������NULL����ĳЩƽ̨��0�����׳�������
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

// ��������ָ��: unique_ptr, shared_ptr, weak_ptr
// 1. unique_ptr, ������������ת��
// 2. shared_ptr, ����ָ��
// 3. weak_ptr, �����ڴ浫�ǲ�����+1����������ѭ�� 
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
 	
 	
	// ԭ�Ӳ��������÷ִ������ڴ棬�����׳���
	// foo(shared_ptr<int>(new int(43)), seed()) �����
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
