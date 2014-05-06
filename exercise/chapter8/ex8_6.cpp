#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

void read_is(istream& is) {
    int a;
    while (is >> a)
        cout << a << endl;
}

int main() {

    ifstream ifs("test.dat");
    read_is(ifs);
    return 0;
}
