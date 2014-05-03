#include <iostream>
using namespace std;

class X {
    friend ostream& operator<<(ostream &out, X &x);
    friend istream& operator>>(istream &in, X &x);
    friend X operator+(const X &lhs, const X &rhs);
    public:
        X& operator+=(const X &rhs);
        X(): a(0) {}
    private:
        int a; 
};

X& X::operator+=(const X &rhs) {
    a += rhs.a;
    return *this;
}


ostream& operator<<(ostream &out, X &x) {
    cout << x.a;
    return cout;
}

istream& operator>>(istream &in, X &x) {
    cin >> x.a;
    return cin;
}

X operator+(const X &lhs, const X &rhs) {
    X x;
    x.a = lhs.a + rhs.a;
    return x;
}

int main() {
    X x, y;
    cin >> x;
    cin >> y; 
    X z = x + y;
    X r;
    r += z;

    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
    cout << "z:x+y=" << z << endl;
    cout << "r:0+=z" << r << endl;
    return 0;
}
