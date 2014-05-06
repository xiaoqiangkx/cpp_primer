#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

struct IS_SHORTER {
    bool operator()(const string &lhs, const string& rhs) {
        return lhs.size() < rhs.size();
    }
};

struct IS_LONGER {

    IS_LONGER(int bound_): bound(bound_) {}

    bool operator()(const string &s) {
        return s.size() >= bound;
    }

    private:
        int bound;
};

int main() {
    char* sarr[] = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    cout << sizeof(sarr) << " " << sizeof(char*) << endl;
    vector<string> svec(sarr, sarr + sizeof(sarr)/sizeof(char*));
    vector<string>::iterator end_unique = unique(svec.begin(), svec.end());
    svec.erase(end_unique, svec.end());
    sort(svec.begin(), svec.end(), IS_SHORTER());

    int cnt = count_if(svec.begin(), svec.end(), IS_LONGER(4));
    cout << "cnt: " << cnt << endl;
    return 0;
}
