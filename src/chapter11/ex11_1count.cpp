#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> vec;
    int n;
    while (cin >> n) {
        vec.push_back(n);
    }

    int cnt = count(vec.begin(), vec.end(), 1);
    cout << "the num of 1 is " << cnt << endl;
    return 0;
}
