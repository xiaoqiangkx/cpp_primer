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

int main() {
    Item_base item("Love", 2.2);
    cout << "the price of " << item.get_isbn() << " is " << item.net_price(10) << endl;
    return 0;
}
