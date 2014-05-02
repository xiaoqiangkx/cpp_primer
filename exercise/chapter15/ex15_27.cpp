#include <iostream>
using namespace std;

class Disc_item {
    public:
        virtual double net_price(size_t) const = 0;
};

class Disc_bulk: public Disc_item {
    public:
        virtual double net_price(double a) {}
        virtual double net_price(size_t n) const {
            return 1.2;
        }
};

int main() {
//    Disc_item di;
    Disc_bulk db;
    return 0;
}
