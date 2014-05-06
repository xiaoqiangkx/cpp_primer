#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
    vector<int> ivec;
    fill_n(back_inserter(ivec), 10, 0);

    for (vector<int>::iterator it=ivec.begin(); it != ivec.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
