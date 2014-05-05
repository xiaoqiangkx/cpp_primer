#include <iostream>
using namespace std;

struct Test {
    int operator()(bool test, int a, int b) {
        return test ? a : b;
    }
};

int main() {
    Test t;
    cout << t(true, 1, 2) << endl;
    cout << t(false, 1, 2) << endl;
    return 0;
}
