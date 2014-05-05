#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
struct EQ_cls {
    EQ_cls(const T &t): bound(t) {}
    bool operator()(const T& t) {
        return t == bound;
    }
    private:
        T bound;
};

void display(vector<int> &vec) {
    for (vector<int>::iterator st = vec.begin(); st != vec.end(); st++) {
        cout << *st << " ";
    }
    cout << endl;
}

int main() {
    int a[] = { 3, 2, 1, 4, 3};
    vector<int> vec(a, a+5);

    display(vec);
    replace_if(vec.begin(), vec.end(), EQ_cls<int>(3), 2);

    display(vec);
    return 0;
}
