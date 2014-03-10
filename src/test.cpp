#include <iostream>
#include <vector>
using namespace std;

int main() {
    int *a = new int[10]();
    cout << a[3] << endl;
    delete [] a;
    return 0;
}
