#include <iostream>
using namespace std;

class X {
    public:
    const static int a = 1;
};

const int X::a;

void test(const int& a) {
    cout << a << endl;
}

int main() {
    X x;
    cout << x.a << endl;
    test(X::a);
    return 0;
}
