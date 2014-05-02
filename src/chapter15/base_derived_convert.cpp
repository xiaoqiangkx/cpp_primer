#include <iostream>
using namespace std;

class A {
    public:
        int a;
};

class B: public A {
};

int main(int argc, char* argv[]) {
    B b;
    A a = b;
    return 0;
}
