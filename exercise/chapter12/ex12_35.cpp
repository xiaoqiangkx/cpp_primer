#include <iostream>
using namespace std;

class X {
    friend istream& operator>>(istream &is, X &x);
    public:
        X(int _a): a(_a) {}
        void print() {
            cout << a << endl;
        }

    private:
        int a;
};

istream& operator>>(istream &is, X &x) {
    is >> x.a;
    return is;
}

int main() {
    X a(1);
    cin >> a;
    a.print();
    return 0;
}
