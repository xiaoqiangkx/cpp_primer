#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char* argv[]) {
    vector<pair<int, string> > vec;

    int n;
    string s;
    pair<int, string> p;
    while (cin >> n >> s) {
        p = make_pair(n, s);
        vec.push_back(p);
    }

    for (int i=0; i<vec.size(); i++) {
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    return 0;
}
