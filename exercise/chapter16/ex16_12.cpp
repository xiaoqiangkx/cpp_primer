#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename T>
typename T::value_type findMostFreq(T first, T last) {
    allocator<typename T::value_type> alloc;

    T newFirst = alloc.allocate(last - first);
    T newLast = newFirst + (last - first);

    uninitialized_copy(first, second, newFirst);

    sort(newFirst, newLast);

    size_t maxOccu = 0, occu = 0;
    T preIter = newFirst; maxOccuElem = newFirst;

    while (newFirst != newLast) {
        if (*newFirst != preIter) {
            if (occu > maxOccu) {
                maxOccu = occu;
                maxOccuElem = preIter;
            }

            occu = 0;
        }

        ++occu;
        preIter = newFirst;
        newFirst++;
    }

    if (occu > maxOccu) {
        maxOccu = occu;
        maxOccuElem = preIter;
    }

    return *maxOccuElem;

}

int main() {
    int a[] = {2, 3, 1, 4, 5, 2, 4, 1};

    vector<int> data(a, a+8);
    return 0;
}
