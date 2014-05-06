#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> strCnts;

    string s;
    while (cin >> s) {
        ++strCnts[s];
    }

    for (map<string, int>::iterator it = strCnts.begin(); it != strCnts.end(); it++) {
        cout << it->first << ":\t" << it->second << endl;
    }
            
    return 0;
}
