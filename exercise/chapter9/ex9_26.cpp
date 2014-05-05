#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

template <typename T>
void print(T st, T ed) {
    while (st != ed) {
        cout << *st << " ";
        st++;
    }

    cout << endl;
}

struct IS_EVEN {
    bool operator()(int val) {
        return val % 2 == 0;
    }
};

struct IS_ODD {
    bool operator()(int val) {
        return val % 2 != 0;
    }
};

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> ivec(ia, ia + sizeof(ia) / sizeof(int) );
    list<int> ilist(ivec.begin(), ivec.end());

    vector<int>::iterator vit = ivec.begin();

    while (vit != ivec.end()) {
      vit = find_if(vit, ivec.end(), IS_EVEN());
      if (vit != ivec.end())
          vit = ivec.erase(vit);
    }
    
    cout << "no even" << endl;
    print(ivec.begin(), ivec.end());

    list<int>::iterator lit = ilist.begin();
    while (lit != ilist.end()) {
      lit = find_if(lit, ilist.end(), IS_ODD());
      if (lit != ilist.end())
          lit = ilist.erase(lit);
    }

    cout << "no odd" << endl;
    print(ilist.begin(), ilist.end());
    return 0;
}
