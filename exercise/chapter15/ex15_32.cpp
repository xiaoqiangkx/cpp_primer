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

        virtual void debug(ostream &os = cout) const {
            cout << "Item_base: isbn=" << isbn << ",price=" << price << endl;
        }
    private:
        string isbn;
    protected:
        double price;

};

class Bulk_item: public Item_base {
    public:
        Bulk_item(const string& _isbn="", double _price=0.0, double _discount=0.0, size_t _max_qty=1)
           : Item_base(_isbn, _price), discount(_discount), max_qty(_max_qty) {}

        virtual double net_price(size_t n) const {
            if (n <= max_qty) {
                return (1 - discount) * n * price;
            } else {
                return (n-max_qty) * price + max_qty * price * (1 - discount);
            }
        }

        Bulk_item* clone() {
            return new Bulk_item(*this);
        }

        virtual void debug(ostream& os = cout) const {
            cout << "Bulk_item: isbn=" << get_isbn() << ",price=" << price << endl;
            cout << "dicont=" << discount << ", max_qty" << max_qty << endl;
        }
    private:
        double discount;
        size_t max_qty;
};

int main() {

    Bulk_item bulk_item("Dream", 2.2, 0.5, 5);

    Item_base * item = &bulk_item;
    item->debug();
    return 0;
}
