#include <iostream>
using namespace std;

class Item_base {
    public:
    virtual double net_price(size_t n, size_t min_pty=10) {
        if (n >= min_pty) {
            return 10 * n * 0.5;
        } else {
            return n * 10;
        }
    }   
};

class Bulk_item: public Item_base {
    public:
    virtual double net_price(size_t n, size_t min_pty=12) {
        if (n >= min_pty) {
            return 10 * n * 0.6;
        } else {
            return n * 10;
        }
    }   
};

int main() {
    Item_base *item_base = new Bulk_item();
    cout << item_base->net_price(10) << endl;
}

