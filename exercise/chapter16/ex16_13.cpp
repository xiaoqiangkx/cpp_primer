#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printElem(const T &container) {
    
    typename T::size_type len = container.size();
    for (int i=0; i<len; i++) {
        cout << container[i] << endl;
    }

}

int main() {
    vector<int> data(5, 1);
    printElem(data);
    return 0;
}
