#include <iostream>
#include "ex7_6test.h"
using namespace std;

inline int maxNum(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char* argv[]) {
    cout << maxNum(1,2) << endl;
    cout << get(1,2) << endl;
    return 0;
}
