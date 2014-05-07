#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    int a[3][4] = { { 0 }, { 4 }, { 8 } };

    for (int (*p)[4] = a; p != a + 3; p++) {
        for (int *q = *p; q != *p + 4; q++) {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}
