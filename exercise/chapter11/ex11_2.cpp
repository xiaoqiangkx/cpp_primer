#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {

    int iarr[] = { 1, 3, 4, 2, 4, 2 ,4};
    string sarr[] = { "123", "244", "123" };

    vector<string> svec(sarr, sarr+3);
    list<string> slist(svec.begin(), svec.end());
    cout << "123:" << count(slist.begin(), slist.end(), "123") << endl;
    return 0;
}
