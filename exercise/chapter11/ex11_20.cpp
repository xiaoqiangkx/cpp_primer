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

    for (vector<int>::iterator iter = ivec.end(); iter != ivec.begin(); iter--) {
        cout << *(iter-1) << endl;
    }
    return 0;
}
