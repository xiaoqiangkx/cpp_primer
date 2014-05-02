#include <list>
#include <iostream>
using namespace std;

int main() {
    int a[4] = {1, 3, 5, 7};
    int b[4] = {2, 4, 6, 8};
    list<int> data(a, a+4);


    list<int>::iterator st = data.begin(), ed = data.end();
    
    int cnt = 0;
    while (st != data.end()) {
        data.insert(++st, b[cnt++]);
    }

//    return 0;
    st = data.begin(), ed = data.end();
    while (st != ed) {
        cout << *st << endl;
        st++;
    }

    return 0;
}
