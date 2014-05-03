#include <iostream>
using namespace std;

class Foo {
    public:
        Foo(int a_=12): a(a_) {}
        int get() const { return a; }
    private:
        int a;
};

class Bar {
    public:
        // const不限制static变量
        int get_f() const {
            cnt++;
            return f.get();
        }

        static int callsFooVal() {
            return cnt;
        }
    private:
        static int cnt;
        static Foo f;
};

int Bar::cnt = 0;
Foo Bar::f;

int main() {
    Bar b;
    cout << Bar::callsFooVal() << endl;
    b.get_f();
    b.get_f();
    b.get_f();
    cout << Bar::callsFooVal() << endl;
    return 0;
}
