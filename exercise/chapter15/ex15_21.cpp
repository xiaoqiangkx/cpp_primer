#include <iostream>
#include <string>
using namespace std;

class Item_base {
    public:
        Item_base(const string &book="",double sales_price = 0.0)
            : isbn(book), price(sales_price) {
            cout << "Item_bas(const string&, double)"
                << endl;
        }

        string book() const {
            return isbn;
        }

        virtual double net_price(size_t n) const {
            return n * price;
        }

        Item_base(const Item_base& ib): isbn(ib.isbn), price(ib.price) {
            cout << "Item_base(const Item_base&)" << endl;
        }
        
        Item_base& operator= (const Item_base& rhs) {
            isbn = rhs.isbn;
            price = rhs.price;

            cout << "Item_Base::operator=()" << endl;

            return *this;
        }

        virtual ~Item_base() {
            cout << "~Item_base()" << endl;
        }

    private:
        string isbn;
    protected:
        double price;
    
};


class Bulk_item: public Item_base {
    public:
        Bulk_item(const string& book = "", double sales_price = 0.0,
                size_t qty = 0, double disc_rate = 0.0)
            : Item_base(book, sales_price), min_qty(qty), discount(disc_rate) {
            cout << "Bulk_item(const string&, double, size_t, double)" << endl;
        }

        double net_price(size_t cnt) const {
            if (cnt >= min_qty) {
                return cnt * (1-discount) *price;
            } else {
                return cnt * price;
            }
        }

        // Item_base(b) 操作可以初始化赋值私有成员
        Bulk_item(const Bulk_item& b):
            Item_base(b), min_qty(b.min_qty), discount(b.discount) {
            cout << "Bulk_item(const Bulk_item&)" << endl;     
        }

        // 通过赋值运算可以改变派生类的基类私有成员, 本质上rhs也是通过构造函数改变的,使用了公共的接口
        Bulk_item& operator= (const Bulk_item& rhs) {
            if (this != &rhs)
                Item_base::operator=(rhs);

            min_qty = rhs.min_qty;
            discount = rhs.discount;

            cout << "Bulk_item::operator=()" << endl;

            return *this;
        }

        virtual ~Bulk_item() {
            cout << "~Bulk_item()" << endl;
        }

    private:
        size_t min_qty;
        double discount;
};

int main() {
    return 0;
}
