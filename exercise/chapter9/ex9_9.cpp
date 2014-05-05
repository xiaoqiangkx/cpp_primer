#include <iostream>
#include <list>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5};
    list<int> ilist(a, a+5);
    for (list<int>::reverse_iterator it = ilist.rbegin(); it != ilist.rend(); it++) {
        cout << *it << endl;
    }
    return 0;
}
