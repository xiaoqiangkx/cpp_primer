#include <iostream>
using namespace std;

/* 返回绝对值 */
template <typename T>
int compare (const T &v1, const T &v2) {
    if (v1 < v2) {
        return -1;
    } else if (v2 < v1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // error: no matching function for call to ‘compare(const char [4], const char [3])’
    // compare("123", "12");
    return 0;
}
