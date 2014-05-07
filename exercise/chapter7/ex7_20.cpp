#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {

    int n = 5;
    long long sum = 1;
    while (n > 0) {
        sum *= n;
        n--;
    }

    cout << sum << endl;
    return 0;
}
