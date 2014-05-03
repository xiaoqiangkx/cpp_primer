#include <iostream>
using namespace std;

class Ref {
public:
    int &rc;
};

int main() {
//    int &a;
    Ref ref;
    int a = 1;
//    ref.rc = a;
//    cout << ref.rc << endl;
    return 0;
}
