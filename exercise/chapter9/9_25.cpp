#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> a(ia, ia+sizeof(ia)/sizeof(int));
    list<int> b(ia, ia+sizeof(ia)/sizeof(int));

    vector<int>::iterator it = a.begin();
    while (it != a.end()) {
        if (*it % 2 != 0) {
            it++;
            continue;
        } else {
            it++;
            a.erase(it-1);
        }
    }
    
    it = a.begin();
    while (it != a.end()) {
        cout << *it << endl;
        it++;
    }

    cout << endl;

    {
    list<int>::iterator it = b.begin();
    list<int>::iterator temp;
    while (it != b.end()) {
        if (*it % 2 == 0) {
            it++;
            continue;
        } else {
           temp = it;
           it++;
           b.erase(temp); 
        }
    }

    it = b.begin();
    while (it != b.end()) {
        cout << *it << endl;
        it++;
    }
    }
    return 0;
}
