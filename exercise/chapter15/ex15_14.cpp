#include <iostream>
using namespace std;

class Item_base {
    public:
        Item_base(const string& _isbn=""): isbn(_isbn) {}
    private:
        string isbn;
};

class Bulk_item: public Item_base {
    public:
        Bulk_item(const string& _isbn=""): Item_base(_isbn) {}

};

int main() {
    Bulk_item bi("hello");
    return 0;
}
