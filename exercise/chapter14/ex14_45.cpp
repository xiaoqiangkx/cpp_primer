#include <iostream>
using namespace std;

class X {
    X(double d) {
        cout << "X() " <<endl;
    }
};

void cal(int) { cout << "int" << endl; }
void cal(X) { cout << "X" << endl; }

int main() {
    double d;
    cal(d);
    return 0;
}
