#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace BookStore {
    class out_of_stock: public logic_error {
        public:
         out_of_stock(const string &s): logic_error(s), data(s) {   /* must initialize logic_error */
         }

         const char* what() throw () {
             return data.c_str();
         }

         virtual ~out_of_stock() throw() {}
        private:
           const string data; 
    };

    class Sale_Item {
        public:
            friend Sale_Item operator+(const Sale_Item &lhs, const Sale_Item &rhs);
            Sale_Item(const string &s, int _cnt=0)
                :cnt(_cnt), isbn(s) {
            }

        private:
            int cnt;
            string isbn;
    };

    Sale_Item operator+(const Sale_Item &lhs, const Sale_Item &rhs);
   
};

BookStore::Sale_Item BookStore::operator+(const BookStore::Sale_Item &lhs, const BookStore::Sale_Item &rhs) {
    if (lhs.isbn != rhs.isbn)
        throw new BookStore::out_of_stock("differnt isbn");

    BookStore::Sale_Item item(lhs.isbn, lhs.cnt + rhs.cnt);
    return item;
}

int main() {
    try {
        BookStore::Sale_Item item1("hello", 1);
        BookStore::Sale_Item item2("hello", 1);

        BookStore::Sale_Item item = item1 + item2;
        cout << "finish add item1 and item2 " << endl;
        BookStore::Sale_Item item3("hello1", 2);
        item + item3;

    } catch (const logic_error* e) {    /* must use pointer */
        cout << e->what() << endl;
    }

    return 0;
}
