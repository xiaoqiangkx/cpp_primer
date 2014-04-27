#include <iostream>
#include <stdexcept>
#include <typeinfo>
using namespace std;

class A {
    public:
    virtual void print() {
        cout << "A" << endl;
    }
};

class B: public A {
    public:
    virtual void print() {
        cout << "B" << endl;
    }
};

int main() {
    A a1;
    B b1;
    A &a = a1;
    A &b = b1;

    try {
       B &bref = dynamic_cast<B&>(a); 
    } catch(bad_cast &e) {
        cout << "bad_cast" << endl;
    }

    try {
       B &bref = dynamic_cast<B&>(b); 
       b.print();
    } catch(bad_cast &e) {
        cout << "bad_cast" << endl;
    }
    return 0;
}
