#include <iostream>
using namespace std;

class Sales_item {
    friend int add_items(Sales_item& s1, Sales_item& s2) {
        return s1.val + s2.val;
    }
    public:
        Sales_item(int _val): val(_val) {}
    private:
        int val;
};

int main() {
    Sales_item s1(1), s2(2);
    cout << add_items(s1, s2) << endl;
    return 0;
}
