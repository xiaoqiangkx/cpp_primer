#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    vector<string> svec;
    string s;
    while (cin >> s) {
        istringstream iss(s);
        while (iss >> s) {
            svec.push_back(s);
        }
        
    }

    for (vector<string>::iterator it = svec.begin(); it != svec.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
