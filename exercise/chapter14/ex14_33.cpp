#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
struct GT_cls {
    GT_cls(const T &t): bound(t) {}
    bool operator()(const T& t) {
        return t > bound;
    }
    private:
        T bound;
};

int main() {
    int a[] = { 3, 2, 1, 4 };
    vector<int> vec(a, a+4);
    vector<int>::iterator res = find_if(vec.begin(), vec.end(), GT_cls<int>(3));

    if (res != vec.end()) {
        cout << *res << endl;
    } else {
        cout << "do not find it" << endl;
    }

    return 0;
}
