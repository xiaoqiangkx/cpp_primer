#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    char a[] = "abcde";
    char b[] = "abcd";

    char *pa = a;
    char *pb = b;

    while (*pa != '\0' && *pb != '\0') {
        if (*pa < *pb) {
            cout << "Smaller" << endl;
            break;
        } else if ( *pa > *pb) {
            cout << "Larger" << endl;
            break;
        } else {
            pa++, pb++;
            continue;
        }
    }

    if (*pa == '\0' && *pb == '\0') {
        cout << "Equal" << endl;
    } else if (*pa != '\0') {
        cout << "Larger" << endl;
    } else {
        cout << "Smaller" << endl;
    }
    return 0;
}
