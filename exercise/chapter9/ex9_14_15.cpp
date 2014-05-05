#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> svec;
    string s;
    while (cin >> s) {
        svec.push_back(s);
        cout << svec.back() << endl;
    }

    cout << "finished" << endl;
    cin.clear();
    cin >> s;
    // while (1) {}
    return 0;
}
