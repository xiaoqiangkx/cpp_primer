#include <iostream>
using namespace std;

class Sale_item {
    public:
        Sale_item(int _i): i(_i) {}
        
        friend ostream& operator<<(ostream &out, const Sale_item& item) {
            out << item.i;
            return out;
        }

        friend istream& operator>>(istream &in, Sale_item& item) {
            in >> item.i;
            return in;
        }

        friend Sale_item& operator+(const Sale_item& item1, const Sale_item& item2) {
            int sum = item1.i + item2.i; 
            Sale_item *new_item = new Sale_item(sum);
            return *new_item;
        }

        Sale_item& operator=(const Sale_item& item) {
            i = item.i;
            return *this;
        }
    private:
        int i;
};

int main(int argc, char* argv[]) {
    Sale_item s1(1);
    Sale_item s2 = s1;
    cout << s1 << " " << s2 << endl;
    cin >> s2;
    cout << s1 << " " << s2 << endl;
    
    Sale_item s3 = s1 + s2;
    cout << s1 << " " << s2 << " " << s3 << endl;
    return 0;
}
