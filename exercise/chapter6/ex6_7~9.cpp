#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    string s = "ffflfgfi";

    size_t index = 0;
    int cnt = 0;
    while (index < s.size()) {
        if (s[index] == 'f') {
            index++;
            if (index == s.size()) break;
            switch (s[index]) {
                case 'f': case 'l': case 'i':
                    cnt++;
                    break;
                default:
                    continue;
            }
        }

        index++;
    }

    cout << "cnt=" << cnt << endl;
    return 0;
}
