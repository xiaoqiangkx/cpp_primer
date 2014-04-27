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

bool test(A *&a) {
    if (typeid(*a) == typeid(B)) {
        B *b = dynamic_cast<B*>(a);
        b->print();
    } else {
        a->print();
    }
    
}

int main() {
    A *a2 = new B();
    A *a1 = new A();
    test(a1);
    test(a2);

    return 0;
}
