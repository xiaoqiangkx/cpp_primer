#include <iostream>
using namespace std;

/* 变量名和类型名不允许同名 */

typedef int ABC;
int ABC;

template <class T>
T f2(int &T) {
    return T;
}

int main() {
    int a = f2<int>(2);
    return 0;
}
