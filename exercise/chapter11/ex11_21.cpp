#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {

    int iarr[] = {1, 2, 3, 4, 1, 5};
    vector<int> ivec(iarr, iarr + sizeof(iarr)/sizeof(int));
    list<int> ilist(ivec.begin(), ivec.end());

    list<int>::reverse_iterator it = find(ilist.rbegin(), ilist.rend(), 1);

    if (it != ilist.rend())
        cout << *it++ << " ";
        cout << *it << endl;

    return 0;
}
