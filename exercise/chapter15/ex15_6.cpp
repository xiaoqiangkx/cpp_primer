#include <iostream>
using namespace std;

class Item_base {
    public:
        Item_base(const string& _isbn="", double _price=0.0)
            : isbn(_isbn), price(_price) {}

        const string& get_isbn() const {
            return isbn;
        }

        virtual double net_price(size_t n) const {
            return price * n;
        }
    private:
        string isbn;
    protected:
        double price;

};

class Bulk_item: public Item_base {
    public:
        Bulk_item(const string& _isbn="", double _price=0.0, double _discount=0.0, size_t _min_qty=1)
           : Item_base(_isbn, _price), discount(_discount), min_qty(_min_qty) {}

        virtual double net_price(size_t n) const {
            if (n >= min_qty) {
                return (1 - discount) * n * price;
            } else {
                return n * price;
            }
        }
    private:
        double discount;
        size_t min_qty;
};

int main() {

    Bulk_item bulk_item("Dream", 2.2, 0.5, 10);
    cout << "Buy 10 " << bulk_item.get_isbn() << " is " << bulk_item.net_price(10) << endl;
    cout << "Buy 5 " << bulk_item.get_isbn() << " is " << bulk_item.net_price(5) << endl;

    return 0;
}
