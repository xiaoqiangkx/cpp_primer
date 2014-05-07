#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    vector<int> ivec(10, 0);
    vector<int> *pvec = &ivec;
    delete pvec;
    return 0;
}
