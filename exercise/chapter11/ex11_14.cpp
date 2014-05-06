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
    list<int> ivec1;
    list<int> ivec2;
    list<int> ivec3;

    cout << "正" << endl;
    replace_copy(ivec.begin(), ivec.end(), inserter(ivec1, ivec1.begin()), 1, 3);
    print(ivec1.begin(), ivec1.end());

    cout << "正" << endl;
    replace_copy(ivec.begin(), ivec.end(), back_inserter(ivec2), 1, 3);
    print(ivec2.begin(), ivec2.end());

    cout << "反" << endl;
    replace_copy(ivec.begin(), ivec.end(), front_inserter(ivec3), 1, 3);
    print(ivec3.begin(), ivec3.end());



    return 0;
}
