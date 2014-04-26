#include <iostream>
using namespace std;

template <int HI, int WI>
class Screen;

template <int HI, int WI>
ostream& operator<<(ostream &os, const Screen<HI, WI>&);

template <int HI, int WI>
class Screen {
    friend ostream& operator<< <HI, WI> (ostream &os, const Screen<HI, WI>&);
    public:
        Screen(): hi(HI), wi(WI) {}
        void print() { cout << hi << " " << wi << endl; }
    private:
        int hi;
        int wi;
};

template <int HI, int WI>
ostream& operator<<(ostream &os, const Screen<HI, WI> &screen) {
    os << screen.hi << " " << screen.wi << endl;
}

int main() {
    Screen<20, 40> screen;
    screen.print();
    cout << screen;
    return 0;
}
