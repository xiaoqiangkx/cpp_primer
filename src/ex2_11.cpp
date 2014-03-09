#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]) {
    // support reinput number
    cout << "input a base and exponent(Ex. 1 2)" << endl;

    int base = 0, ex = 0;
    int result;
    while (cin >> base >> ex) {
        if (base == 0 && ex == 0) {
            printf("(base=%d, ex=%d) is not legal\n", base, ex);
            printf("input again:");
            continue;
        }

        if (ex < 0) {
            printf("(base=%d, ex=%d) is not legal\n", base, ex);
            printf("input again:");
            continue;
        }

        result = 1;
        for (int i = 0; i < ex; i++) {
            result *= base;   
        }
        break;
    }

    printf("result((%d)^(%d)) is %d\n", base, ex, result);
    return 0;
}
