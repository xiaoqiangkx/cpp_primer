#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int array[] = { 2, 3, 1, 4, 5};
    vector<int> ivec(array, array + 5);
    list<int> ilist(ivec.begin(), ivec.end());

    if (ivec == vector<int>(ilist.begin(), ilist.end())) cout << "equal" << endl;

    ilist.push_back(3);
    if (ivec == vector<int>(ilist.begin(), ilist.end())) cout << "equal" << endl;
    else cout << "not equal" << endl;
    return 0;
}
