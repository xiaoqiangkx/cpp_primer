#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename TypeIterator, typename T>
TypeIterator findVal(TypeIterator st, TypeIterator ed, const T &val) {
    while (st != ed) {
        if (*st == val) {
            return st;
        }

        st++;
    }

    return ed;
}


int main() {
    int a_array[] = {3, 4, 5, 1, 3};
    string s_array[] = { "hello", "world", "1", "234", "2"};

    vector<int> vi(a_array, a_array + sizeof(a_array)/sizeof(int) );
    vector<string> vs(s_array, s_array + 5);

    cout << *(findVal(vi.begin(), vi.end(), 5)) << endl;
    cout << *(findVal(vs.begin(), vs.end(), "world")) << endl;
    return 0;
}
