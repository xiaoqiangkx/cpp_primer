#include <iostream>
#include <string>
using namespace std;

struct Base {
    Base() {}
    Base(const string &s): name(s) {}
    Base(const Base& base): name(base.name) {}
    protected:
        string name;
};

struct Derived1: virtual public Base {
    Derived1(): Base("Derived1") {}
    Derived1(const string& name): Base(name) {}
    Derived1(const Derived1& d): Base(d) {}
};

struct Derived2: virtual public Base {
    Derived2(): Base("Derived2") {}
    Derived2(const string& name): Base(name) {}
    Derived2(const Derived2& d): Base(d) {}

};

struct MI: public Derived1, public Derived2 {
    MI(): Base("MI") {}
    MI(const string& name): Base(name) {}
    MI(const MI& m): Base(m), Derived1(m), Derived2(m) {}
};

int main() {
    Base b;
    Derived1 d1;
    Derived2 d2;
    MI m;
    return 0;
}
