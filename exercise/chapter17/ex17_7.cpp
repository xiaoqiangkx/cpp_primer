#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

void exercise1() {
    vector<int> v(3, 4);
    int *p = new int[v.size()];
    try {
        throw runtime_error("runtime error");
    } catch (exception &e) {
        cout << e.what() << endl;
        if (p) delete [] p;
    }

}

class Handler {
    public:
        Handler(int *p): ptr(p), use(new size_t(1)) {
        }

        ~Handler() {
            if (--*use == 0) {
                cout << "delete data" << endl;
                delete [] ptr;
                delete use;
            }
        }
    private:
        int *ptr;
        size_t *use;

};

void exercise2() {
    vector<int> v(3, 4);
    int *p = new int[3];
    Handler h(p);
    try {
        throw runtime_error("runtime error");
    } catch (exception &e) {
        cout << e.what() << endl;
    }

}
int main() {
    exercise1();
    exercise2();
    return 0;
}
