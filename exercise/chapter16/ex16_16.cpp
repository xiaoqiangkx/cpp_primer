#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
void printElem(const T (&array)[N]) {
    for (int i=0; i<N; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    int a[] = {12, 23, 34, 1, 2, 4};
    string b[] = { "hello", "abc", "bc", "d" };

    printElem(a);
    printElem(b);
    return 0;
}
