#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void fun2() {
    throw runtime_error("error");
}

void fun1() {
    try {
        fun2();
    } catch(runtime_error err) {
        cout << err.what() << endl;
    }
}

int main() {
    fun1();
    cout << "end" << endl;
    return 0;
}
