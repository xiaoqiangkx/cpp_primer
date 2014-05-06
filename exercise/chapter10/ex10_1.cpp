#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    vector<pair<string,int> > pvec;
    string s;
    int num;
    while (cin >> s >> num) {
        pvec.push_back(make_pair<string, int>(s, num));
    }
    return 0;
}
