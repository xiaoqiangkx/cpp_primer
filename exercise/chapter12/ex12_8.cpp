#include <iostream>
using namespace std;

class Sales_item {
    public:
        Sales_item(): units_sold(0), revenue(0.0) {}
        inline double avg_price() const;
    private:
        string isbn;
        unsigned units_sold;
        double revenue;
};

inline double Sales_item::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

int main() {
    Sales_item item;
    cout << item.avg_price() << endl;
    return 0;
}
