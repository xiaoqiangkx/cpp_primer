#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

template <typename T>
void print(T st, T ed) {
    while (st != ed) {
        cout << *st << " ";
        st++;
    }

    cout << endl;
}

int main() {

    int iarr[] = {1, 2, 3, 4, 1, 5, 2, 3, 4, 5};
    vector<int> ivec(iarr, iarr + sizeof(iarr)/sizeof(int));
    list<int> ilist(ivec.rbegin()+3, ivec.rend()-2);

    print(ivec.begin(), ivec.end());
    print(ilist.begin(), ilist.end());

    return 0;
}
