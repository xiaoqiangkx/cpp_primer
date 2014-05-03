#include <iostream>
using namespace std;

class X {
    public:
        X() {}
        explicit X(const X& x) {}
};

int main() {
    X x;
    // X y = x;
    X y(x);
    return 0;
}
