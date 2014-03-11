#include "ex7_6test.h"

inline int maxNum(int a, int b) {
    return a < b ? a : b;
}

int get(int a, int b) {
    return maxNum(a, b);
}
