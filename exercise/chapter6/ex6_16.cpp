#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {

    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    vector<int> ivec1(arr1, arr1+3);
    vector<int> ivec2(arr2, arr2+6);

    for (int i=0, j=0; i<ivec1.size() && j<ivec2.size(); i++, j++) {
        if (ivec1[i] != ivec2[j]) break;
        
        if (i == ivec1.size() - 1) cout << "success" << endl;
    }

    return 0;
}
