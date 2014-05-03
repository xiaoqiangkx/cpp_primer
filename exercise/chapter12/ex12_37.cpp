#include <iostream>
using namespace std;

class X {
    public:
        static int a;
        static void set(int val) { a = val; }
        int get() const { return a; }
};

int X::a = 1;
int main() {
    X x;
    cout << X::a << " " << x.a << endl;
    x.set(20);
    X b;
    cout << X::a << " " << b.get() << endl;
    return 0;
}
