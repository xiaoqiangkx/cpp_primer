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
};

int main() {
    try {
        throw new BookStore::out_of_stock("out of stock");
    } catch (const logic_error* e) {    /* must use pointer */
        cout << e->what() << endl;
    }

    return 0;
}
