#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {

    int iarr[] = { 1, 3, 4, 2, 4, 2 ,4};
    string sarr[] = { "123", "244", "123" };

    vector<int> ivec(iarr, iarr + sizeof(iarr)/sizeof(int));
    cout << "4:" << count(ivec.begin(), ivec.end(), 4) << endl;
    return 0;
}
