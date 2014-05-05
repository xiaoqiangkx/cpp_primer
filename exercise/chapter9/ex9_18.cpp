#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template <typename T>
void print(T st, T ed) {
    while (st != ed) {
        cout << *st << " ";
        st++;
    }

    cout << endl;
}

int main() {
    int array[] = { 3, 2, 3, 1, 4, 5};
    vector<int> temp(array, array + sizeof(array)/sizeof(int));
    list<int> ilist(temp.begin(), temp.end());

    cout << "list" << endl;
    print(ilist.begin(), ilist.end());
    deque<int> dq1, dq2;

    for (list<int>::iterator it = ilist.begin(); it != ilist.end(); it++) {
        if (*it % 2 == 0) {
            dq1.push_back(*it);
        } else {
            dq2.push_back(*it);
        }
    }

    cout << "deque1" << endl;
    print(dq1.begin(), dq1.end());

    cout << "deque2" << endl;
    print(dq2.begin(), dq2.end());

    return 0;
}
