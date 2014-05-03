#include <iostream>
using namespace std;

class Foo {
    public:
        Foo(int a_): a(a_) {}
        int get() const { return a; }
    private:
        int a;
};

int main() {
    Foo foo(1);
    cout << foo.get() << endl;
    return 0;
}
