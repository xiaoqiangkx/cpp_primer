#include <iostream>
using namespace std;

class Screen {
    typedef string::size_type index;
    public:
        Screen(): contents("Hello world"), cursor(0), height(10), width(3) {}
        Screen& move(int h, int w) {
            cursor = h * width + w;
            return *this;
        }

        Screen& set(char c) {
            contents[cursor] = c;
            return *this;
        }

        Screen& display(ostream &out=cout) {
            cout << contents << endl;
        }
        
        const Screen& display(ostream &out=cout) const {
            cout << contents << endl;
        }
    private:
        string contents;
        index cursor;
        index height, width;
};

int main() {
    Screen screen;
    screen.move(2, 0).set('#').display();
    return 0;
}
