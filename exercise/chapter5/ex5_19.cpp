#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    string a[] = {"12", "23"};
    string *p = &a[0];
    cout << *p++ << endl;
    return 0;
}
