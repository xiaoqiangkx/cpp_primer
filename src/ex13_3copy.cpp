#include <iostream>
using namespace std;

class Test {
    public:
        Test(int _i, int _j): i(_i), j(_j) {}
        Test& operator=(const Test& t) {
            //i = t.i;
            j = t.j;
        }

    private:
       const int i;
       int j; 
};

int main(int argc, char* argv[]) {
    Test t1(1,2);
    Test t2 = t1;
    return 0;
}
