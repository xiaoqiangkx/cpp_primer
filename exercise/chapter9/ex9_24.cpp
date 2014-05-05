#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {
    vector<int> ivec;
    ivec[0];    // undefined
    try {
        ivec.at(0);
    } catch (out_of_range &e) {
        cout << "out_of_range" << endl;
    }
    ivec.front();// undefined 

    *(ivec.begin());// undefined
    return 0;
}
