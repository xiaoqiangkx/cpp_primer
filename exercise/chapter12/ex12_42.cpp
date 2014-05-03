#include <iostream>
using namespace std;

class X {
    public:
    const static int a = 1;
};

// const int X::a;

int main() {
    X x;
    cout << x.a << endl;
    return 0;
}
