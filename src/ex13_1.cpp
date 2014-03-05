#include <iostream>
using namespace std;

class Sales_item {
    public:
        Sales_item(int _val, const string &_data): val(_val), data(new string(_data)) {}
        Sales_item(const Sales_item& s);
        int get_val() { return val;}
        string& get_data() { return *data;}
        ~Sales_item() { delete data; }
    private:
        int val;
        string *data;
};

Sales_item::Sales_item(const Sales_item& s): val(s.val), data(new string(*s.data)) {
}


int main() {
    Sales_item *s1 = new Sales_item(1, "123");
    Sales_item s2 = *s1;
    delete s1;
    cout << s2.get_val() << " " << s2.get_data() << endl;
    return 0;
}
