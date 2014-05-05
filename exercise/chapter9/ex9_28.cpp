#include <iostream>
#include <vector>
#include <list>
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
    char* carr[] = { "hello", "in" };
    string sarr[] = { "world", "out" };
    
    vector<string> svec(sarr, sarr+2);
    list<char*> clist;
    clist.push_back(carr[0]);
    clist.push_back(carr[1]);

    svec.assign(clist.begin(), clist.end());
    print(svec.begin(), svec.end());
    print(clist.begin(), clist.end());

    return 0;
}
