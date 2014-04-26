#include <iostream>
using namespace std;

template <int HI, int WI>
class Screen {
    public:
        Screen(): hi(HI), wi(WI) {}
        void print() { cout << hi << " " << wi << endl; }
    private:
        int hi;
        int wi;
};

int main() {
    Screen<20, 40> screen;
    screen.print();
    return 0;
}
