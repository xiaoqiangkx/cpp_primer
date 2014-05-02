#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

typedef deque<int>::iterator dit;
void show(const string s, dit st, dit ed) {
    cout << s << endl;
    while (st != ed) {
        cout << *st << endl;
        st++;
    }
}

int main(int argc, char* argv[]) {
    vector<int> vec;
    deque<int> dq1;
    deque<int> dq2;

    int n;
    while (cin >> n) {
        vec.push_back(n);
    }

    typedef vector<int>::iterator vit;
    vit st = vec.begin(), ed = vec.end();

    while (st != ed) {
        if (*st % 2 == 0) {
            dq1.push_back(*st);
        } else {
            dq2.push_back(*st);
        } 
        st++;
    }

    show("dque1:", dq1.begin(), dq1.end());
    show("dque2:", dq2.begin(), dq2.end());
    return 0;
}
