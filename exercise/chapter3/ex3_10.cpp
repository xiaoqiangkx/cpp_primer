#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>
using namespace std;

struct NOT_PUNC {
    bool operator() (char c) {
        return !ispunct(c);
    }
}; 
int main() {
    string data("ab,a:dg");
    data.erase(stable_partition(data.begin(), data.end(), NOT_PUNC()), data.end());
    cout << data << endl;
    return 0;
}
