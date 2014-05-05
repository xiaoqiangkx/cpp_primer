#include <iostream>
using namespace std;

int main() {
    string digit = "0123456789";
    string letter;
    for (char c='a'; c <= 'z'; c++) {
        letter.push_back(c);
        letter.push_back(c + 'A' - 'a');
    }
    string s = "ab2c3d7R4E6";

    string::size_type pos = 0;
    while ( (pos = s.find_first_of(digit, pos)) != string::npos) {
        cout << s[pos] << endl;
        pos++;
    }

    pos = 0;
    while ( (pos = s.find_first_of(letter, pos)) != string::npos) {
        cout << s[pos] << endl;
        pos++;
    }
    return 0;
}
