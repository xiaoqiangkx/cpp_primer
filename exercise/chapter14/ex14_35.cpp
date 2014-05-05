#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct BT_cls {
    BT_cls(size_t st_, size_t ed_): st(st_), ed(ed_) {}
    bool operator()(const string& s) {
        return s.size() >= st && s.size() <= ed;
    }
    private:
        size_t st;
        size_t ed;
};

void display(vector<string> &vec) {
    for (vector<string>::iterator st = vec.begin(); st != vec.end(); st++) {
        cout << *st << " ";
    }
    cout << endl;
}

int main() {
    string a[] = { "hello", "dfasfasdfasdf", "", "a", "b"};
    vector<string> vec(a, a+5);

    display(vec);
    int cnt = count_if(vec.begin(), vec.end(), BT_cls(1, 10));
    cout << "cnt=" << cnt << endl;

    return 0;
}
