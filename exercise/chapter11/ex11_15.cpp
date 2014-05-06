#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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
    int iarr[] = {1,2,1,4};
    vector<int> ivec(iarr, iarr + sizeof(iarr)/sizeof(int));
    sort(ivec.begin(), ivec.end());
    cout << "raw data" << endl;
    print(ivec.begin(), ivec.end());

    list<int> ilist;
    cout << "new data" << endl;
    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilist));

    print(ilist.begin(), ilist.end());
    return 0;
}
