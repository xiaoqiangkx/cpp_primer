#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {

    string pred = "", cur;
    int cnt = 0;
    int maxCnt = 0;
    while (cin >> cur) {
        if (pred == "") {
            pred = cur;
            cnt = 1;
            continue;
        } else {
            if (cur == pred) {
                cnt++;
            } else {
                maxCnt = max(maxCnt, cnt);
                pred = cur;
                cnt = 1;
            }
        }
    }

    maxCnt = max(maxCnt, cnt);
    cout << "max=" << maxCnt << endl;
    return 0;
}
