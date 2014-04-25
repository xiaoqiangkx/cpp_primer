#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printElem(const T &container) {
    
    typename T::const_iterator st = container.begin(), ed = container.end();

    while (st != ed) {
        cout << *st << endl;
        st++;
    }

}

int main() {
    vector<int> data(5, 1);
    printElem(data);
    return 0;
}
