#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int iarr[4] = { 1, 2, 3, 4};
    vector<int> ivec(iarr, iarr + 4);

    int sum = accumulate(ivec.begin(), ivec.end(), 0);
    cout << "sum=" << sum << endl;
    return 0;
}
