#include <iostream>
using namespace std;

struct X {
    X(const string &str =""): sptr(new string(str)) {}
    X(const X& x): sptr(new string(*(x.sptr))) {}
    X& operator=(const X &x) {
        if (&x == this) return *this;
        delete sptr;
        sptr = new string(*(x.sptr));
        return *this;
    }
    void print() const {
        cout << *(sptr) << endl;
    }

    ~X() { 
        if (sptr) delete sptr;
    } 

    private:
         string* sptr;
};

int main() {
    X x("hello");
    X y = x;

    y.print();
    X z;
    z = y;
    z.print();

    return 0;
}
