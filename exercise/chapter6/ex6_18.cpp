#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    string s1, s2;
    char rsp;
    do {
        cout << " input two string (Ex: abc a) " << endl;
        cin >> s1 >> s2;
        if (cin) {
            cout << "compare(" << s1 << "," << s2 << ")=" << (s1 < s2) << endl;
            cout << "continue?(y/n)" << endl;
            cin >> rsp; 
        }
    } while(cin && rsp == 'y');

    return 0;
}
