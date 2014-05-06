#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> strCnts;

    string s;
    while (cin >> s) {
        pair<map<string, int>::iterator, bool> ret = strCnts.insert(make_pair(s, 1));

        if (!ret.second) {
            ++ret.first->second;
        }
    }

    for (map<string, int>::iterator it = strCnts.begin(); it != strCnts.end(); it++) {
        cout << it->first << ":\t" << it->second << endl;
    }
            
    return 0;
}
