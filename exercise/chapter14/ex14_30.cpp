#include <iostream>
#include <stdexcept>
using namespace std;

struct X {
    X(): a(1), b(2) {}
    int a;
    int b;
};

class Y {
    public:
        Y(X *st_, X *ed_): st(st_), ed(ed_), cur(st_) {}
        Y& operator++() {
            if (cur+1 >= ed) {
                throw out_of_range("wrong");
            }

            cur++;
            return *this;
        }
        
        Y& operator--() {
            if (cur-1 < st ) {
                throw out_of_range("wrong");
            }

            cur--;
            return *this;
        }
        
        Y operator++(int) {
            Y ret(*this);
            ++*this;
            return ret;
        }
        
        Y operator--(int) {
            Y ret(*this);    
            --*this;
            return ret;
        }

        X operator*() {
            return *cur;
        }

        X* operator->() {
            return cur;
        }

        const X operator*() const {
            return *cur;
        }

        const X* operator->() const {
            return cur;
        }

    private:
        X *st;
        X *ed;
        X *cur;
};

int main() {
    X xx[4];
    Y y(xx, xx+4);
    ++y;
    y++;
    y++;
    --y;
    y--;
    (*y).a;
    y->a;
    return 0;
}
