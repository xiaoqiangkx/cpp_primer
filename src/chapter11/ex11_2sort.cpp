#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool is_shorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

bool isGT6(const string& s) {
    return s.size() >= 6;
}

int main(int argc, char* argv[]) {
    vector<string> vec;
    string s;
    while (cin >> s) {
        vec.push_back(s);
    }


    vector<string>::iterator end_unique = unique(vec.begin(), vec.end());
    sort(vec.begin(), end_unique);
    vec.erase(end_unique, vec.end());

    stable_sort(vec.begin(), vec.end(), is_shorter);

    vector<string>::iterator first = find_if(vec.begin(), vec.end(), isGT6);

    while (first != vec.end()) {
        cout << *first << endl;
        first++;
    }

    return 0;
}
