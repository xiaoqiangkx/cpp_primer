#include <iostream>
using namespace std;

class Item_base {
    public:
        Item_base(const string& _book="", int _price = 0.0): 
            book(_book), price(_price) {};
        string get_book() const { return book;}
        virtual double net_price(int n) const = 0;
    private:
        string book; 
    protected:
        double price;
};

class Bulk_Item: public Item_base {
    public:
        Bulk_Item(const string& _book, double price, double _discount):
            Item_base(_book, price), discount(_discount) {}
        double net_price(int n) const;
    private:
        int min_qty;
        double discount;
};

double Bulk_Item::net_price(int n) const {
    if (n >= min_qty) {
        return n * price * (1 - discount);
    } else {
        return n * price;
    }
}

int main() {
    Item_base *item = new Bulk_Item("hello", 12, 0.1);
    cout << item->get_book() << " " << item->net_price(10) << endl;
    delete item;
    return 0;
}
