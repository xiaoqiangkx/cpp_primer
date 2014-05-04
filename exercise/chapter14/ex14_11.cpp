#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class CheckoutRecord {
    friend istream& operator>>(istream& in, CheckoutRecord & cr);
    private:
        double book_id;
        string title;
        pair<string, string> borrower;
        vector< pair<string, string>* > wait_list;
};

istream& operator>>(istream& in, CheckoutRecord & cr) {
    in >> cr.book_id >> cr.title >> cr.borrower.first >> cr.borrower.second;
    string a, b;

    cr.wait_list.clear();
    while (cin >> a >> b) {
       pair<string, string>* data = new pair<string, string>(a, b); 
       cr.wait_list.push_back(data);
    }

    cout << "eof:" << in.eof() << ";fail:" << in.fail() << "; bad:" << in.bad() << endl;
    if (!in.good() && !in.eof()) {
        cr = CheckoutRecord();
        cout << "wrong" << endl;
    }

    return in;
}

int main() {
    CheckoutRecord cr;
    cin >> cr;
    return 0;
}

