#include <iostream>
#include <vector>
using namespace std;

template<class InputIterator, class T>
InputIterator find_my(InputIterator st, InputIterator ed, const T& t) {
    while (st != ed) {
        if (*st == t) return st;
        st++;
    }

    return ed;
}

int main(int argc, char* argv[]) {
    char* a[3] = { "123", "234", "456" };
    int b[3] = {3, 4, 5};
    vector<string> v1(a, a+3);
    vector<int> v2(b, b+3);

    cout << *(find_my(v1.begin(), v1.end(), "123")) << endl;
    cout << *(find_my(v2.begin(), v2.end(), 4)) << endl;

    cout << (find_my(v1.begin(), v1.end(), "46") == v1.end()) << endl;
    cout << (find_my(v2.begin(), v2.end(), 6) == v2.end()) << endl;
    
    return 0;
}
