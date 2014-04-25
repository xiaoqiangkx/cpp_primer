#include <iostream>
#include <algorithm>
#include "findMid.h"
using namespace std;

int main() {
    int a[] = { 3, 2, 1, 4, 5};
    vector<int> data(a, a+5);
    cout << *(findMid(data)) << endl;
    return 0;
}
