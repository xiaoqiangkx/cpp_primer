#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream ifs("test.data");
    ifs.open("test2.data");
    cout << "ifs:" << !ifs << endl;
    ifs.open("test3.data");
    cout << "ifs:" << !ifs << endl;
    ifs.close();
    return 0;
}
