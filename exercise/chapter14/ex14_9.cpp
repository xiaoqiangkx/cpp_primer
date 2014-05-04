#include <iostream>
using namespace std;

class Sales_item {
    public:
        friend istream& operator>>(istream& in, Sales_item &item);
    private:
        string isbn;
        int cnt;
        double price;
};

istream& operator>>(istream& in, Sales_item &item) {
    in >> item.isbn >> item.cnt >> item.price;
    
    if (!in) {
        item = Sales_item();
        cout << "wrong" << endl;
    }
    return in;
}

int main() {
    Sales_item item;
    cin >> item;
    return 0;
}
