#include <iostream>
#include <vector>
using namespace std;

template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
   return t1+t2;
}


/* supported higher than 4.7.2 */

//class B 
//{
//public:
//   virtual void f(int) {cout << "B::f" << endl;}
//};
//
//class D : public B
//{
//public:
//   virtual void f(int) override final {cout << "D::f" << endl;}
//};
//
//class F : public D
//{
////public:
// //  virtual void f(int) override {std::cout << "F::f" << std::endl;}
//};

int main() {
    vector<int> v(10, 0);
    
    /** 1. auto **/
    auto st = v.begin(), ed = v.end();

    while (st != ed) {
        cout << *st << endl;
        st++;
    }

	auto adder = compose(2, 3.14); // v's type is double
	cout << adder << endl;

    /** 2. nullptr **/
    bool f = nullptr;
    int* i = nullptr;

    /** 3. foreach **/
    for (const auto & num : v) {
        cout << num << endl;
    }

    int arr[] = {1, 2, 3, 4, 5};
    for (int& e : arr) {
        e = e*e;
        cout << e << endl;
    }

    /** 4. enum **/
    enum class Options1 { None, One, All};
    enum class Options2 { None, One, All};
    Options1 o = Options1::None;
    //cout << "enum=" << o << endl;
    return 0;
}
