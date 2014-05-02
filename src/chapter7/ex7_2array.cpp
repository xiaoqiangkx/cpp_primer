#include <iostream>
using namespace std;

void show(int (&arr)[5]) {
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    int a[5] = {0};
    show(a);
    return 0;
}
