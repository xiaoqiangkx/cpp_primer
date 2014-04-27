#include <iostream>
#include <string>
using namespace std;

template <typename T>
class QueueItem {
    public:
        void* operator new(size_t) {
            cout << "New" << endl;
        }
        void operator delete(void*, size_t) {
            cout << "Delete" << endl;
        }
    private:
        string isbn;
        T price;
};

int main() {
    return 0;
}
