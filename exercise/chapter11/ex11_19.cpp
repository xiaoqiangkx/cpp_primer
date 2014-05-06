#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {

    int iarr[] = {1, 2, 3, 4};
    vector<int> ivec(iarr, iarr + sizeof(iarr)/sizeof(int));

    for (vector<int>::reverse_iterator r_iter = ivec.rbegin(); r_iter != ivec.rend(); r_iter++) {
        cout << *r_iter << endl;
    }
    return 0;
}
