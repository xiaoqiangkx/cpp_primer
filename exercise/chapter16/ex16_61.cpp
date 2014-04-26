#include <iostream>
using namespace std;

template <typename T> int compare(const T& t1, const T& t2) {
    cout << "tempalte T" << endl;
    return 0;
}

template <class U, class V> int compare(U u1, U u2, V u3) {
    cout << "template U, V" << endl;
    return 0;
}

int compare(const char* c1, const char* c2) {
    cout << "simple compare" << endl;
    return 0;
}

int main() {
    return 0;
}
