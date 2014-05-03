#include <iostream>
using namespace std;

class X {
    public:
        X(): a(1) {
            cout << "X()" << endl;
        }
        
        X(const X& x): a(x.a) {
            cout << "X(const)" << endl;
        }

        X& operator=(const X&x) {
            cout << "X operator=" << endl;
            a = x.a;
        }

    private:
        int a;   
};

int main() {
    X b;
    X c(b);     // X c(b) 与 X a = b是一致的.
    X a = b;
    a = c;
    return 0;
}
