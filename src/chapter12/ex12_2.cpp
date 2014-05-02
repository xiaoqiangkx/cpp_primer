#include <iostream>
using namespace std;

class Screen {
    public:
        int len;
        int width;
        Screen(int _len, int _width): len(_len), width(_width) {}
        Screen& move(int num);
        Screen& display(ostream &os);
        const Screen& display(ostream &os) const;
        typedef int intp;
        intp test();
    private:
        void do_display(ostream &os) const {
            os << len <<" " << width << endl;
        }
};

Screen::intp test() {}

Screen& Screen::move(int num) {
    len += num;
    width += num;
    return *this;
}

Screen& Screen::display(ostream &os) {
   move(3);
   do_display(os);
   return *this; 
}

const Screen& Screen::display(ostream &os) const {
   do_display(os);
   return *this; 
}

int main() {
    Screen s(1,1);
    const Screen cs(1,1);
    s.move(1).display(cout);
    cs.display(cout);
    return 0;
}
