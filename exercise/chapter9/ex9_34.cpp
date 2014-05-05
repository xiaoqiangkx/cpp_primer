#include <iostream>
using namespace std;

int main() {
    string a = "aDabdE";
    for (string::iterator it = a.begin(); it != a.end(); it++) {
        if (*it <= 'z' && *it >= 'a')
            *it += ('A' - 'a');
    }

    cout << a << endl;
    return 0;
}
