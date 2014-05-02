#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream ofs("test.data");
    cin.tie(&ofs);

    ofs << "hello";
    int num;
    cin >> num;
    return 0;
}
