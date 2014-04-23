#include <iostream>
using namespace std;

/* 返回绝对值 */
template <typename T>
T absVal(T val) {
    return val > 0 ? val : -val;
}

int main() {
    cout << "-1:" << absVal(-1) << endl;
    cout << "-1.2:" << absVal(-1.2) << endl;
    cout << "-1.2:" << absVal(-1.2f) << endl;
    return 0;
}
