#include <iostream>
using namespace std;

struct X {
    X(const string &str =""): sptr(new string(str)) {}
    X(const X& x): sptr(new string(*(x.sptr))) {}
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

    return 0;
}
