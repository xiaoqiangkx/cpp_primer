#include <iostream>
#include <cstdarg>
using namespace std;

void printNum(int n, ...) {
    va_list vl;
    va_start(vl, n);

    for(int i=0; i<n; i++) {
        int val = va_arg(vl, int);
        cout << val << " ";
    }
  
    va_end(vl);
    cout << endl;
}

int main(int argc, char* argv[]) {
    printNum(4,2,3,4,5);
    return 0;
}
