#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
size_t size(const T (&array)[N]) {
    return N;
}

int main() {
    int a[] = {12, 23, 34, 1, 2, 4};
    string b[] = { "hello", "abc", "bc", "d" };

    cout << size(a) << endl;
    cout << size(b) << endl;
    return 0;
}
