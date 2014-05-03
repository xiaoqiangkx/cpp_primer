#include <iostream>
using namespace std;

class X {
    public:
        X(): book(""), cnt(0), price(new double(0.0)), ifs(cin) {}
        ~X() { if(price) delete price; }
    private:
        string book;
        int cnt;
        double* price;
        istream& ifs;
};

int main() {
    X x;
    return 0;
}
