#include <iostream>
#include <algorithm>
using namespace std;

struct IS_CAP {
    bool operator()(char c) {
        return c <= 'Z' && c >= 'A';
    }
};

int main() {
    string a = "aDabdE";
    string::iterator it = a.begin();
   
    while (it != a.end()) {
        it = find_if(it, a.end(), IS_CAP());
        if (it != a.end())
            it = a.erase(it);
    }

    cout << a << endl;
    return 0;
}
