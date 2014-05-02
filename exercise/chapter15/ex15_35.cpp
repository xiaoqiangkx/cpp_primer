#include <iostream>
#include <stdexcept>
#include <set>
using namespace std;

class Item_base {
    public:
        Item_base(const string& _isbn="", double _price=0.0)
            : isbn(_isbn), price(_price) {}

        const string& book() const {
            return isbn;
        }

        virtual double net_price(size_t n) const {
            return price * n;
        }

        virtual void debug(ostream &os = cout) const {
            cout << "Item_base: isbn=" << isbn << ",price=" << price << endl;
        }

        virtual Item_base* clone() const {
            return new Item_base(*this);
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

        Bulk_item* clone() const {
            return new Bulk_item(*this);
        }

        virtual void debug(ostream& os = cout) const {
            cout << "Bulk_item: isbn=" << book() << ",price=" << price << endl;
            cout << "dicont=" << discount << ", max_qty" << max_qty << endl;
        }
        
        virtual Bulk_item* clone() {
            return new Bulk_item(*this);
        }
    private:
        double discount;
        size_t max_qty;
};

// 句柄类, 管理Item_base继承簇
class Sales_item {
    public:
        Sales_item(): ptr(NULL), use(new size_t(1)) {}  // NULL considered as source
        // use clone function to avoid pointer in user space
        Sales_item(const Item_base& base)
            : ptr(base.clone()), use(new size_t(1)) {
        }

        Sales_item& operator=(const Sales_item& rhs) {
            ++*use;
            decr_use();
            ptr = rhs.ptr;
            use = rhs.use;
            return *this;
        } 

        Sales_item(const Sales_item& item): ptr(item.ptr), use(item.use) {
            ++*use; 
        }

        ~Sales_item() { decr_use(); }

        const Item_base& operator*() const { 
            if (ptr)
                return *ptr;
            else
                throw new logic_error("unbound Sales_item");
        }

        const Item_base* operator->() const { 
            if (ptr)
                return ptr; 
            else
                throw new logic_error("unbound Sales_item");
        }

    private:
        Item_base* ptr;
        size_t* use;
        void decr_use() {
            if (--*use == 0) {
                delete ptr;
                delete use;
            }
        }
};

inline bool compare(const Sales_item &lhs, const Sales_item &rhs) {
    return lhs->book() < rhs->book();
}

class Basket {
    typedef bool (*Comp)(const Sales_item &lhr, const Sales_item &rhs);
    public:
        typedef multiset<Sales_item, Comp> set_type;
        typedef set_type::size_type size_type;
        typedef set_type::const_iterator const_iter;
        Basket(): items(compare) {}
        size_type size(const Sales_item &i) const {
            return items.count(i);
        }

        void add_item(const Sales_item &item) {
            items.insert(item);
        }

        double total();

    private:
        multiset<Sales_item, Comp> items;
};

double Basket::total() {
    double sum = 0.0;
    for (const_iter iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
        size_t n = size(*iter);
        Sales_item sale_item = *iter;
        sum += sale_item->net_price(n);
    }

    return sum;
}

int main() {

    Bulk_item bulk_item("Dream", 2.2, 0.5, 5);
    Item_base base_item("Hello", 1.0);
    Basket basket;
    for (int i=0; i<12; i++) {
        basket.add_item(bulk_item);
    }

    for (int i=0; i<5; i++) {
        basket.add_item(base_item);
    }

    double sum = basket.total();
    cout << "sum=" << sum << endl;
    return 0;
}
