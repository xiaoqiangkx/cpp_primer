#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << " argc is 3 " << endl;
        return -1;
    }

    for (int i=0; i<3; i++) {
        cout << argv[i] << endl;
    }
    return 0;
}
