#include <iostream>
using namespace std;

template <typename T>
T maxVal(const T &v1, const T &v2) {
    return v1 < v2 ? v2 : v1;
}

int main() {
    cout << "1, 2=" << maxVal(1, 2) << endl;
    cout << "1.1, 2.2=" << maxVal(1.1, 2.2) << endl;
    // error: no matching function for call to ‘maxVal(int, double)’
    // cout << "1, 2.2=" << maxVal(1, 2.2) << endl;
    return 0;
}
