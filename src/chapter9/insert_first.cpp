#include  <iostream>
#include <vector>
using namespace std;

int main() {
    int data[] = {3, 4};
    vector<int> ivec(data, data+2);
    vector<int>::iterator it = ivec.begin();

    while (it != ivec.end()) {
        it = ivec.insert(it, 42);
        it += 2;
    }
    return 0;
}
