#include <iostream>
using namespace std;

class X {
    friend X operator+(const X &lhs, const X &rhs);
    public:
        X(int _a): a(_a) {}
        void print() {
            cout << a << endl;
        }

    private:
        int a;
};

X operator+(const X &lhs, const X &rhs) {
    X x(0);
    x.a = lhs.a + rhs.a;
    return x;
}

int main() {
    X a(1), b(2);
    X c = a + b;
    c.print();
    return 0;
}
