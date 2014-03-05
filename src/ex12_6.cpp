#include <iostream>
using namespace std;

class Sales_item {
    public:
        static int get_a() { a++; return a; };
        Sales_item(int _val): val(_val) {}
    private:
        static int a;
        int val;
};

int Sales_item::a = 1;

int main() {
    Sales_item s1(1), s2(2);
    int a1 = s1.get_a();
    int a2 = s2.get_a();
    cout << a1 << endl << a2 << endl;
    return 0;
}
