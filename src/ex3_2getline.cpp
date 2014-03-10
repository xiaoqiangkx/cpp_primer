#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string s;
    while ( cin >> s) {
        if (s == "quit") break;
        cout << s << endl;
    }

    while (getline(cin, s)) {
        cout << s << endl;
    }
    return 0;
}
