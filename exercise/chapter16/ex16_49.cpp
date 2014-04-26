#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Handler {
    public:
        Handler(T *_ptr = NULL): ptr(_ptr), use(new size_t(1)) {}   /*size_t is user_defined class but typedef for int */
        Handler(const Handler& h): ptr(h.ptr), use(h.use) { ++(*use);}
        Handler& operator=(const Handler& rhs) {    /* right hand side */
            ++*(rhs.use);
            rem_ref();
            use = rhs.use;
            ptr = rhs.ptr;
            return *this;
        }

        ~Handler() {
            rem_ref();
        }

        T& operator*() {
            if (ptr != NULL)    return *ptr;
            throw new runtime_error("dereference of unbound handler");
        }

        const T& operator*() const{
            if (ptr != NULL)    return *ptr;
            throw new runtime_error("dereference of unbound handler");
        }

        T* operator->() {
            if (ptr != NULL)    return ptr;
            throw new runtime_error("access through unbound handler");
        }

        const T* operator->() const{
            if (ptr != NULL)    return ptr;
            throw new runtime_error("access through unbound handler");
        }

    private:
        T *ptr; /* every handler use the same ptr and use */
        size_t *use;
        void rem_ref() {
            if (0 == --*use) {
                delete use; 
                delete ptr;
                cout << "delete data" << endl;
            } else {
                cout << "count --: " << *use << endl;
            }
        }
};

class Item_base {
    public:
        Item_base(const std::string &book="", double sales_price = 0.0):
            isbn(book), price(sales_price) {} 

        double net_price(int num) {
            if (num < 2) {
                return price * num;
            } else {
                return price * num * 0.5;
            }
        }
    private:
        string isbn;
        double price;

};

template <typename T>
class Sale_item {
    public:
        const T& operator*() const { return *h; }
        const T* operator->() const { return h.operator->(); }
    private:
        Handler<T> h;
};

int main() {
    // Item_base *data[] = {new Item_base("123", 2.0), new Item_base("2", 2.0), new Item_base("123", 2.0}};
    Handler<Item_base> h1(new Item_base("123", 2.0));
    Handler<Item_base> h2(new Item_base("2", 2.0));
    Handler<Item_base> h3 = h1;

    vector<Handler<Item_base> > data;
    data.push_back(h1);
    data.push_back(h2);
    data.push_back(h3);

    return 0;
}
