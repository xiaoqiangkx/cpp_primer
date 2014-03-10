#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char* argv[]) {
    bitset<32> bitvec;
    int a[] = {1,2,3,5,8,13,21};

    for (int i=0; i<sizeof(a)/sizeof(int); i++) {
        bitvec.set(a[i]);
    }

    cout << bitvec << endl;
    return 0;
}
