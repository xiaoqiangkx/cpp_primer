#include <iostream>
#include <vector>
using namespace std;

int main() {
    char carr[] = "abcdef";
    vector<char> cvec(carr, carr + 6);
    string s(cvec.begin(), cvec.end());
    cout << s << endl;
    return 0;
}
