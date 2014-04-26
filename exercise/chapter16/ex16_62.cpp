#include <iostream>
using namespace std;

template <typename T> int compare(const T& t1, const T& t2) {
    cout << "tempalte T" << endl;
    return 0;
}

template <class U, class V> int compare(U u1, U u2, V u3) {
    cout << "template U, V" << endl;
    return 0;
}

int compare(const char* c1, const char* c2) {
    cout << "simple compare" << endl;
    return 0;
}

/* 一旦程序做类型转换, */
int main() {
    char ch_arr1[] = "world", ch_arr2[] = "hello";
    const char const_arr1[] = "world", const_arr2[] = "hello";
    compare(ch_arr1, const_arr1);
    compare(ch_arr2, const_arr2);
    compare(0, 0);  /* 模板中int 直接匹配 */
    return 0;
}
