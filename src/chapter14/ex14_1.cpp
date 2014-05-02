#include <iostream>
using namespace std;

class Sales_item {
    friend Sales_item& operator+(Sales_item& s1, Sales_item& s2);
    public:
    Sales_item(int _val): val(_val) {}
    Sales_item& operator-(Sales_item& s2);
    void set_val(int _val) { val = _val;}
    int get_val() { return val; }

    private:
        int val;
};

Sales_item& Sales_item::operator-(Sales_item& s2) {
    Sales_item *s = new Sales_item(0);
    s->val = this->val - s2.val;
    return *s;
}

Sales_item& operator+(Sales_item& s1, Sales_item& s2) {
    Sales_item *s = new Sales_item(0);
    s->val = s1.val + s2.val;
    return *s;
}

int main() {
    Sales_item s1(1), s2(2);
    Sales_item result = s1 + s2;
    cout << result.get_val() << endl;
    result = s1 - s2;
    cout << result.get_val() << endl;
    return 0;
}
