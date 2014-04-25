#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printElem(const T &container) {
    
    typename T::const_iterator st;

    for (st = container.begin(); st != container.end(); st++) {
        cout << *st << endl;
    }

}

int main() {
    vector<int> data(5, 1);
    printElem(data);
    return 0;
}
